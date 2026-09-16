#ifndef NOMER2_H
#define NOMER2_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <cctype>
#include <stdexcept>

class WordCounter {
private:
    // autosort words according to alphabet and save positions
    std::map<std::string, std::vector<int>> wordIndex;
    int currentPosition = 0;

    // if the word is raw, clean it
    std::string cleanWord(const std::string& input) {
        std::string result = "";
        for (char symbol : input) {
            if (!std::ispunct(static_cast<unsigned char>(symbol))) {
                result += static_cast<char>(std::tolower(static_cast<unsigned char>(symbol)));
            }
        }
        return result;
    }

public:
    // reading file, making indexing
    void processFile(const std::string& fileName) {
        std::ifstream file(fileName);

        if (!file.is_open()) {
            throw std::runtime_error("error: file wasnt open " + fileName);
        }

        std::string rawWord;
        while (file >> rawWord) {
            std::string cleaned = cleanWord(rawWord);
            
            // if the word is enpty or "-""  or "—", skip it
            if (cleaned.empty() || cleaned == "—" || cleaned == "-") {
                continue; 
            }

            wordIndex[cleaned].push_back(currentPosition);
            currentPosition++;
        }

        file.close();
    }

    void printResults() const {
        std::wcout << "results:\n";
        if (wordIndex.empty()) {
            std::wcout << "file is empty\n";
            return;
        }

        for (const auto& pair : wordIndex) {
            std::cout << "«" << pair.first << " – ";

            for (size_t i = 0; i < pair.second.size(); ++i) {
                std::cout << pair.second[i];
                if (i != pair.second.size() - 1) {
                    std::cout << ", ";
                }
            }
            std::cout << "»\n";
        }
    }
};

#endif

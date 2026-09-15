#ifndef NOMER1_H
#define NOMER1_H

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cctype>
#include <stdexcept>

class WordCounter {
private:
    // autosort words accrording to alphabet
    std::map<std::string, int> wordCounts;

    // if the word is raw, clean it, make lower
    std::string cleanWord(const std::string& rawWord) {
        std::string cleaned;
        for (char c : rawWord) {
            if (isalpha(static_cast<unsigned char>(c))) {
                cleaned += tolower(static_cast<unsigned char>(c));
            }
        }
        return cleaned;
    }

public:
    // reading file, counting words
    void processFile(const std::string& filename) {
        std::ifstream file(filename);
        
        if (!file.is_open()) {
            throw std::runtime_error("error: file wasnt open " + filename);
        }

        std::string rawWord;
        while (file >> rawWord) {
            std::string word = cleanWord(rawWord);
            
            // if the word is empty, make it
            if (!word.empty()) {
                wordCounts[word]++;
            }
        }
        
        file.close();
    }

    void printResults() const {
        std::cout << "results:\n";
        if (wordCounts.empty()) {
            std::cout << "file is empty\n";
            return;
        }

        for (const auto& pair : wordCounts) {
            std::cout << pair.first << " - " << pair.second << "\n";
        }
    }
    
    size_t getUniqueWordsCount() const {
        return wordCounts.size();
    }
};

#endif

#include <iostream>
#include "WordCounter1.h"


// if the word is raw, clean it, make lower
std::string WordCounter1::cleanWord(const std::string& rawWord) {
    std::string cleaned;
    for (char c : rawWord) {
        if (isalpha(static_cast<unsigned char>(c))) {
            cleaned += tolower(static_cast<unsigned char>(c));
        }
    }
    return cleaned;
}

void WordCounter1::processFile(const std::string& filename) {
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

void WordCounter1::printResults() const {
        std::cout << "results:\n";
        if (wordCounts.empty()) {
            std::cout << "file is empty\n";
            return;
        }

        for (const auto& pair : wordCounts) {
            std::cout << pair.first << " - " << pair.second << "\n";
        }
    }
    
size_t WordCounter1::getUniqueWordsCount() const {
    return wordCounts.size();
}


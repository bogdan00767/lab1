#ifndef WORDCOUNTER2_H
#define WORDCOUNTER2_H

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
#include <cctype>
#include <stdexcept>

class WordCounter2 {
private:
    /// @brief word -> list of positions, auto sorted by alphabet
    std::map<std::string, std::vector<int>> wordIndex;

    /// @brief remove punctuation and make the word lower
    /// @param input raw word from file
    /// @return cleaned word
    std::string cleanWord(const std::string& input);

public:
    /// @brief read file and remember where each word appears
    /// @param fileName path to the text file
    /// @throws std::runtime_error if the file cannot be opened
    void processFile(const std::string& fileName);

    /// @brief print each word and its positions
    void printResults() const;
};

#endif
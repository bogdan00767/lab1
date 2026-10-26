#ifndef WORDCOUNTER1_H
#define WORDCOUNTER1_H

#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cctype>
#include <stdexcept>

class WordCounter1 {
private:
    /// @brief word -> count, auto sorted by alphabet
    std::map<std::string, int> wordCounts;

    /// @brief keep only letters and make the word lower
    /// @param rawWord raw word from file (may have punctuation)
    /// @return cleaned word, can be empty
    std::string cleanWord(const std::string& rawWord);

public:
    /// @brief read file and count how many times each word appears
    /// @param filename path to the text file
    /// @throws std::runtime_error if the file cannot be opened
    void processFile(const std::string& filename);

    /// @brief print all words and their counts
    void printResults() const;

    /// @brief how many unique words were found
    /// @return number of unique words
    size_t getUniqueWordsCount() const;

    /// @brief check if nothing was counted
    /// @return true if there are no words
    bool isEmpty() const { return wordCounts.empty(); }
};

#endif
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
    // autosort words accrording to alphabet
    std::map<std::string, int> wordCounts;

    // if the word is raw, clean it, make lower
    std::string cleanWord(const std::string& rawWord);

public:
    void processFile(const std::string& filename);
    void printResults() const;
    size_t getUniqueWordsCount() const;
};

#endif

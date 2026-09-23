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
    // autosort words according to alphabet and save positions
    std::map<std::string, std::vector<int>> wordIndex;

    // if the word is raw, clean it
    std::string cleanWord(const std::string& input);

public:
    void processFile(const std::string& fileName);
    void printResults() const;
};

#endif

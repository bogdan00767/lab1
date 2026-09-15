#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <cctype>
#include <stdexcept>


using namespace std;

class WordCounter {
private:

    // autosort words accrording to alphabet
    map<string, int> wordCounts;

    // if the word is raw, clean it, make lower
    string cleanWord(const string& rawWord) {
        string cleaned;
        for (char c : rawWord) {
            if (isalpha(static_cast<unsigned char>(c))) {
                cleaned += tolower(static_cast<unsigned char>(c));
            }
        }
        return cleaned;
    }

public:
    // reading file, counting words
    void processFile(const string& filename) {
        ifstream file(filename);
        
        if (!file.is_open()) {
            throw runtime_error("error: file wasnt open " + filename);
        }

        string rawWord;
        while (file >> rawWord) {
            string word = cleanWord(rawWord);
            
            // if the word is empty, make it
            if (!word.empty()) {
                wordCounts[word]++;
            }
        }
        
        file.close();
    }

    void printResults() const {
        cout << "results:\n";
        if (wordCounts.empty()) {
            cout << "file is empty\n";
            return;
        }

        for (const auto& pair : wordCounts) {
            cout << pair.first << " - " << pair.second << "\n";
        }
    }
    
    size_t getUniqueWordsCount() const {
        return wordCounts.size();
    }
};

int main() {

    string filename = "/Users/bogdanvinogradov/Desktop/5sem/ptppovs/lab1/warAndPeace.txt"; 

    try {
        WordCounter counter;
        
        counter.processFile(filename);
        counter.printResults();
        
        cout << "\nunique words: " << counter.getUniqueWordsCount() << "\n";
        
    } catch (const std::exception& e) {
        cerr << e.what() << "\n";
        return 1;
    }

    return 0;
}

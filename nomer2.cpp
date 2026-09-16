#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <cctype>

using namespace std;

class WordCounter {
private:
    // autosort words according to alphabet and save positions
    map<string, vector<int>> wordIndex;
    int currentPosition = 0;

    // if the word is raw, clean it
    string cleanWord(const string& input) {
        string result = "";
        for (char symbol : input) {
            if (!ispunct(static_cast<unsigned char>(symbol))) {
                result += static_cast<char>(tolower(static_cast<unsigned char>(symbol)));
            }
        }
        return result;
    }

public:
    // reading file, making indexing
    void processFile(const string& fileName) {
        ifstream file(fileName);

        if (!file.is_open()) {
            throw runtime_error("error: file wasnt open " + fileName);
        }

        string rawWord;
        while (file >> rawWord) {
            string cleaned = cleanWord(rawWord);
            
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
        cout << "results:\n";
        if (wordIndex.empty()) {
            cout << "file is empty\n";
            return;
        }

        for (const auto& pair : wordIndex) {
            cout << "«" << pair.first << " – ";

            for (size_t i = 0; i < pair.second.size(); ++i) {
                cout << pair.second[i];
                if (i != pair.second.size() - 1) {
                    cout << ", ";
                }
            }
            cout << "»\n";
        }
    }
};

int main() {
    setlocale(LC_ALL, "Russian");

    string fileName = "/Users/bogdanvinogradov/Desktop/5sem/ptppovs/lab1/nomer2.txt";

    try {
        WordCounter counter;
        
        counter.processFile(fileName);
        counter.printResults();
        
    } catch (const exception& e) {
        cerr << e.what() << "\n";
        return 1;
    }

    return 0;
}

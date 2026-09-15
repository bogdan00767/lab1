#include <iostream>
#include "nomer1.h"

using namespace std;

int main() {

    string filename = "/Users/bogdanvinogradov/Desktop/5sem/ptppovs/lab1/en_warAndPeace.txt"; 

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
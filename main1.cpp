#include <iostream>
#include <chrono>
#include "WordCounter1.h"

using namespace std;

int main() {

    string filename = "/Users/bogdanvinogradov/Desktop/5sem/ptppovs/lab1/en_warAndPeace.txt"; 

    try {
        auto start = chrono::steady_clock::now();
        WordCounter1 counter;
        
        counter.processFile(filename);
        counter.printResults();
        
        cout << "\nunique words: " << counter.getUniqueWordsCount() << "\n";
        auto stop = chrono::steady_clock::now();
        chrono::duration<double, std::milli> duration = stop - start;
        cout << "time = " << duration.count() << "\n";
    } catch (const std::exception& e) {
        cerr << e.what() << "\n";
        return 1;
    }

    return 0;
}
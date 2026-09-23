#include <iostream>
#include <chrono>
#include "WordCounter2.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");

    string fileName = "/Users/bogdanvinogradov/Desktop/5sem/ptppovs/lab1/nomer2.txt";

    try {
        auto start = chrono::steady_clock::now();
        WordCounter2 counter;
        
        counter.processFile(fileName);
        counter.printResults();
        auto stop = chrono::steady_clock::now();
        chrono::duration<double, std::milli> duration = stop - start;
        cout << "time = " << duration.count() << "\n";

    } catch (const exception& e) {
        cerr << e.what() << "\n";
        return 1;
    }

    return 0;
}

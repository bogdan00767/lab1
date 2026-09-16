#include <iostream>
#include "nomer2.h"

using namespace std;

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

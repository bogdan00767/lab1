#include <iostream>
#include "nomer3.h"

using namespace std;

int main() {
    VectorProcessor processor;

    // nomer 3a
    vector<int> vecA = {2, 3, 4, 5, 6, 7, 8, 9, 11};
    processor.printVector(vecA, "initial vector A");
    
    processor.processPrimes(vecA);
    processor.printVector(vecA, "after proc primes (squares)");
    cout << "\n";

    // nomer 3b
    vector<int> vecB = {4, 7, 2, 9, 1, 8, 6, 3, 5, 10};
    processor.printVector(vecB, "initial vector B");
    
    processor.customSort(vecB);
    processor.printVector(vecB, "after custom sorting (Nechetn from 1 to >>, chetn from >> to 1)");
    cout << "\n";

    // nomer 3c
    vector<int> vecC = {5, 12, 5, 8, 20, 12, 7, 3, 8};
    processor.printVector(vecC, "initial vector C");
    
    int minRange = 5;
    int maxRange = 15;
    cout << "range condition: from " << minRange << " to " << maxRange << "\n";
    
    vector<int> resultC = processor.findUniqueInRange(vecC, minRange, maxRange);
    processor.printVector(resultC, "unique elements in range are ");

    return 0;
}

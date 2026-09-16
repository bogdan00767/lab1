#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// helper func to check if number is prime
bool isPrime(int n) {
    if (n <= 1) return false;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) return false;
    }
    return true;
}

class VectorProcessor {
private:

public:

    // nomer 3a. check for prime numbers and make them square
    void processPrimes(vector<int>& vec) {
        // std::transform modifies every element in range using lambda function
        transform(vec.begin(), vec.end(), vec.begin(), [](int val) {
            if (isPrime(val)) {
                return val * val;
            }
            return val;
        });
    }

    // nomer 3b. sort: first %2 = 0 from the least, then %2! = 0 from the highest
    void customSort(vector<int>& vec) {
        // std::sort with custom comparator logic
        sort(vec.begin(), vec.end(), [](int a, int b) {
            bool aIsNechetn = (a % 2 != 0);
            bool bIsNechetn = (b % 2 != 0);

            if (aIsNechetn != bIsNechetn) {
                return aIsNechetn; 
            }

            if (aIsNechetn) {
                return a < b;
            }

            return a > b;
        });
    }

    // nomer 3c. find numbers in range and make unique array
    vector<int> findUniqueInRange(const vector<int>& vec, int minVal, int maxVal) {
        vector<int> temp;

        // copy elements that match range condition
        copy_if(vec.begin(), vec.end(), back_inserter(temp), [minVal, maxVal](int val) {
            return val >= minVal && val <= maxVal;
        });

        // std::sort and std::unique is the way to remove duplicates
        sort(temp.begin(), temp.end());
        
        // unique moves duplicates to end, erase removes them completely
        auto last = unique(temp.begin(), temp.end());
        temp.erase(last, temp.end());

        return temp;
    }

    // helper to print vector
    void printVector(const vector<int>& vec, const string& message) const {
        cout << message << ": ";
        for (int val : vec) {
            cout << val << " ";
        }
        cout << "\n";
    }
};

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
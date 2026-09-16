#ifndef NOMER3_H
#define NOMER3_H

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// helper func to check if number is prime
inline bool isPrime(int n) {
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
    void processPrimes(std::vector<int>& vec) {
        // std::transform modifies every element in range using lambda function
        std::transform(vec.begin(), vec.end(), vec.begin(), [](int val) {
            if (isPrime(val)) {
                return val * val;
            }
            return val;
        });
    }

    // nomer 3b. sort: first %2 = 0 from the least, then %2! = 0 from the highest
    void customSort(std::vector<int>& vec) {
        // std::sort with custom comparator logic
        std::sort(vec.begin(), vec.end(), [](int a, int b) {
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
    std::vector<int> findUniqueInRange(const std::vector<int>& vec, int minVal, int maxVal) {
        std::vector<int> temp;

        // copy elements that match range condition
        std::copy_if(vec.begin(), vec.end(), std::back_inserter(temp), [minVal, maxVal](int val) {
            return val >= minVal && val <= maxVal;
        });

        // std::sort and std::unique is the way to remove duplicates
        std::sort(temp.begin(), temp.end());
        
        // unique moves duplicates to end, erase removes them completely
        auto last = std::unique(temp.begin(), temp.end());
        temp.erase(last, temp.end());

        return temp;
    }

    // helper to print vector
    void printVector(const std::vector<int>& vec, const std::string& message) const {
        std::cout << message << ": ";
        for (int val : vec) {
            std::cout << val << " ";
        }
        std::cout << "\n";
    }
};

#endif

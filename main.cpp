#include <iostream>
#include <fstream>
#include <chrono>
#include <string>
#include <vector>
#include <exception>

#include "menu.h"
#include "WordCounter1.h"
#include "WordCounter2.h"
#include "nomer3.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "");

    try {
        Menu menu("/Users/bogdanvinogradov/Desktop/5sem/ptppovs/lab1/locales.json");
        menu.chooseLanguage();

        while (true) {
            int switcher = menu.chooseTask();

            if (switcher == 0) {
                cout << menu.tr("bye") << "\n";
                return 0;
            }

            cout << menu.tr("enter_filename");
            string outFile;
            cin >> outFile;

            ofstream fout(outFile, ios::out | ios::trunc);
            if (!fout.is_open()) {
                cerr << menu.tr("file_open_err") << ": " << outFile << "\n\n";
                continue;
            }

            streambuf* oldBuf = cout.rdbuf();
            cout.rdbuf(fout.rdbuf());

            try {
                switch (switcher) {

                    case 1: {
                        string filename = "/Users/bogdanvinogradov/Desktop/5sem/ptppovs/lab1/en_warAndPeace.txt";

                        auto start = chrono::steady_clock::now();
                        WordCounter1 counter;

                        counter.processFile(filename);

                        cout << menu.tr("results") << ":\n";
                        if (counter.isEmpty()) {
                            cout << menu.tr("file_empty") << "\n";
                        } else {
                            counter.printResults();
                        }

                        cout << "\n" << menu.tr("unique_words") << ": "
                             << counter.getUniqueWordsCount() << "\n";

                        auto stop = chrono::steady_clock::now();
                        chrono::duration<double, std::milli> duration = stop - start;
                        cout << menu.tr("time") << " = " << duration.count() << " ms\n";
                        break;
                    }

                    case 2: {
                        string fileName = "/Users/bogdanvinogradov/Desktop/5sem/ptppovs/lab1/nomer2.txt";

                        auto start = chrono::steady_clock::now();
                        WordCounter2 counter;

                        counter.processFile(fileName);
                        counter.printResults();

                        auto stop = chrono::steady_clock::now();
                        chrono::duration<double, std::milli> duration = stop - start;
                        cout << menu.tr("time") << " = " << duration.count() << " ms\n";
                        break;
                    }

                    case 3: {
                        auto start = chrono::steady_clock::now();
                        VectorProcessor processor;

                        vector<int> vecA = {2, 3, 4, 5, 6, 7, 8, 9, 11};
                        processor.printVector(vecA, menu.tr("vec_a_init"));
                        processor.processPrimes(vecA);
                        processor.printVector(vecA, menu.tr("vec_a_after"));
                        cout << "\n";

                        vector<int> vecB = {4, 7, 2, 9, 1, 8, 6, 3, 5, 10};
                        processor.printVector(vecB, menu.tr("vec_b_init"));
                        processor.customSort(vecB);
                        processor.printVector(vecB, menu.tr("vec_b_after"));
                        cout << "\n";

                        vector<int> vecC = {5, 12, 5, 8, 20, 12, 7, 3, 8};
                        processor.printVector(vecC, menu.tr("vec_c_init"));

                        int minRange = 5;
                        int maxRange = 15;
                        cout << menu.tr("range_cond") << ": [" << minRange << ".." << maxRange << "]\n";

                        vector<int> resultC = processor.findUniqueInRange(vecC, minRange, maxRange);
                        processor.printVector(resultC, menu.tr("unique_in_range"));

                        auto stop = chrono::steady_clock::now();
                        chrono::duration<double, std::milli> duration = stop - start;
                        cout << menu.tr("time") << " = " << duration.count() << " ms\n";
                        break;
                    }
                }
            } catch (const exception& e) {
                cout.rdbuf(oldBuf);
                fout.close();
                cerr << menu.tr("err_file") << ": " << e.what() << "\n\n";
                continue;
            }
            cout.rdbuf(oldBuf);
            fout.close();
            cout << menu.tr("saved_to") << ": " << outFile << "\n\n";
        }
    } catch (const exception& e) {
        cerr << "Fatal: " << e.what() << "\n";
        return 1;
    }
}
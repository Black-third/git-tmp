#include <iostream>
#include <sstream>
#include <set>
#include <fstream>
#include <algorithm>
#include <cctype>
#include <iomanip>
#include <vector>
#include <map>
#include <queue>
#include <numeric>
#include <string>
#include <cmath>
#include <climits>
#include <stack>
#include <complex>
#include <cstdlib>
#include <cstring>
#include <array>
#include <unordered_map>
#include <unordered_set>
#include <functional>
#include <bitset>
#include <cassert>
#include <tuple>

using namespace std;
typedef long long ll;
typedef long double ld;
const int mod = 998244353;
//const int mod = 1e9+7;

template <typename T>
class StatisticalCalculation {
private:
    T* data; // Dynamically allocated array for storing data
    int size; // Number of elements in the array

public:
    // Constructor
    StatisticalCalculation(int size) : size(size) {
        data = new T[size];
    }

    // Destructor
    ~StatisticalCalculation() {
        delete[] data;
    }


    void inputData() {
        for (int i = 0; i < size; i++) {
            cout << "Enter element " << (i + 1) << ": ";
            cin >> data[i];
        }
    }


    void sortData() {
        sort(data, data + size);
    }


    T findMedian() {
        sortData();
        if (size % 2 == 0)
            return (data[size / 2 - 1] + data[size / 2]) / 2.0;
        else
            return data[size / 2];
    }


    T findMin() {
        return *min_element(data, data + size);
    }


    T findMax() {
        return *max_element(data, data + size);
    }


    double findMean() {
        double sum = findSummation();
        return sum / size;
    }


    T findSummation() {
        T sum = 0;
        for (int i = 0; i < size; i++)
            sum += data[i];
        return sum;
    }

    void displayArray() {
        sortData();
        cout << "Sorted Data: ";
        for (int i = 0; i < size; i++)
            cout << data[i] << " ";
        cout << endl;
    }

    void statisticsMenu() {
        int choice;
        do {
            cout << "\nSelect a statistical calculation:\n";
            cout << "1. Find Median\n2. Find Minimum\n3. Find Maximum\n4. Find Mean\n5. Find Summation\n6. Exit\n";
            cout << "Enter your choice (1-6): ";
            cin >> choice;

            switch (choice) {
                case 1: cout << "Median: " << findMedian() << endl; break;
                case 2: cout << "Minimum: " << findMin() << endl; break;
                case 3: cout << "Maximum: " << findMax() << endl; break;
                case 4: cout << "Mean: " << findMean() << endl; break;
                case 5: cout << "Summation: " << findSummation() << endl; break;
                case 6: cout << "Exiting..." << endl; break;
                default: cout << "Invalid choice! Please enter a number between 1 and 6." << endl;
            }
        } while (choice != 6);
    }
};

int main() {
    ios_base::sync_with_stdio (false);
    cin.tie (nullptr);
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;
    StatisticalCalculation<int> stat(n);
    stat.inputData();
    stat.statisticsMenu();
    return 0;
}





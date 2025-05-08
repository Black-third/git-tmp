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

const double EPS = 1e-9;

template <typename T>
class Polynomial {
private:
    int order;
    T* coefficients;
    T value;

public:
    Polynomial(int order) : order(order) {
        coefficients = new T[order + 1]();
    }

    ~Polynomial() {
        delete[] coefficients;
    }

    void inputPolynomial() {
        cout << "Enter polynomial coefficients :" << endl;
        cin >> value;
        for (int i = 0; i <= order; i++) {
            cin >> coefficients[i];
        }
    }

    void displayPolynomial() {
        bool first = true;
        for (int i = order; i >= 0; i--) {
            if (abs(coefficients[i]) < EPS) continue;

            if (!first) {
                cout << (coefficients[i] > 0 ? " + " : " - ");
            } else {
                if (coefficients[i] < 0) cout << "-";
                first = false;
            }

            if (i == 0 || abs(coefficients[i]) != 1) cout << abs(coefficients[i]);
            if (i > 0) cout << "x";
            if (i > 1) cout << "^" << i;
        }
        if (first) cout << "0"; // If all coefficients are zero
        cout << " = " << value << endl;
    }

    Polynomial operator+(const Polynomial& other) {
        int maxOrder = max(order, other.order);
        Polynomial result(maxOrder);
        result.value = value + other.value;
        for (int i = 0; i <= maxOrder; i++) {
            T a = (i <= order) ? coefficients[i] : 0;
            T b = (i <= other.order) ? other.coefficients[i] : 0;
            result.coefficients[i] = a + b;
        }
        return result;
    }

    Polynomial operator-(const Polynomial& other) {
        int maxOrder = max(order, other.order);
        Polynomial result(maxOrder);
        result.value = value - other.value;
        for (int i = 0; i <= maxOrder; i++) {
            T a = (i <= order) ? coefficients[i] : 0;
            T b = (i <= other.order) ? other.coefficients[i] : 0;
            result.coefficients[i] = a - b;
        }
        return result;
    }
};


int main() {
    ios_base::sync_with_stdio (false);
    cin.tie (nullptr);
    int order1, order2;
    cout << "Enter order of first polynomial: ";
    cin >> order1;
    Polynomial<int> poly1(order1);
    poly1.inputPolynomial();
    cout << "Enter order of second polynomial: ";
    cin >> order2;
    Polynomial<int> poly2(order2);
    poly2.inputPolynomial();
    cout << "First polynomial: ";
    poly1.displayPolynomial();
    cout << "Second polynomial: ";
    poly2.displayPolynomial();
    Polynomial<int> sum = poly1 + poly2;
    Polynomial<int> diff = poly2 - poly1;
    cout << "Sum of polynomials: ";
    sum.displayPolynomial();
    cout << "Difference of polynomials: ";
    diff.displayPolynomial();
    return 0;
}





#include <iostream>
#include <cmath>
using namespace std;

int log_a_to_base_b(int a, int b) {
    return log(a) / log(b);
}

void masters(int a, int b, int p, int k) {
    int comp;
    int comp1, comp2;
    if (a > pow(b, k)) {
        comp = log_a_to_base_b(a, b);
        cout << "θ(n^" << comp << ")" << endl;
    }
    else if (a == pow(b, k)) {
        if (p >= -1) {
            comp1 = log_a_to_base_b(a, b);
            comp2 = (p + 1);
            cout << "θ(n^" << comp1 << " log" << comp2 << "n" << endl;
        }
        else if (p == -1) {
            comp = log_a_to_base_b(a, b);
            cout << "θ(n^" << comp << " loglog n" << endl;
        }
        else {
            comp = log_a_to_base_b(a, b);
            cout << "θ(n^" << comp << endl;
        }
    }
    else {
        if (p >= 0) {
            cout << "θ(n^" << k << " log^" << p << "n" << endl;
        }
        else {
            cout << "θ(n^" << k << endl;
        }
    }
}

int main() {
    int a, b, p, k;
    cout << "Enter values for a, b, p, and k: ";
    cin >> a >> b >> p >> k;
    masters(a, b, p, k);
    return 0;
}

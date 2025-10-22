#include <iostream>
using namespace std;

int main() {
    int A, B, temp;

    cout << "Masukkan nilai A: ";
    cin >> A;
    cout << "Masukkan nilai B: ";
    cin >> B;

    cout << "Sebelum penukaran: A = " << A << ", B = " << B << endl;

    // Proses penukaran
    temp = A;
    A = B;
    B = temp;

    cout << "Setelah penukaran: A = " << A << ", B = " << B << endl;

    return 0;
}

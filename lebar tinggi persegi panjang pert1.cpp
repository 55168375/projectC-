#include <iostream>
using namespace std;

int main() {
    float lebar, tinggi, luas, keliling;

    cout << "Masukkan lebar persegi panjang: ";
    cin >> lebar;
    cout << "Masukkan tinggi persegi panjang: ";
    cin >> tinggi;

    luas = lebar * tinggi;
    keliling = 2 * (lebar + tinggi);

    cout << "Luas persegi panjang: " << luas << endl;
    cout << "Keliling persegi panjang: " << keliling << endl;

    return 0;
}

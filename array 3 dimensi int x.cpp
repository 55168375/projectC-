
#include <iostream>
using namespace std;

int main() {
    int x[2][3][5];
    // Simulasi: kita tahu &x[1][1][4] = 0x12EF
    long long known_address = 0x12EF;
    // Hitung offset x[1][1][4]
    int i1=1, j1=1, k1=4;
    int offset1 = (i1 * 3 * 5) + (j1 * 5) + k1; // = 24
    // Basis array A = known_address - offset1 * sizeof(int)
    long long base_A = known_address - (offset1 * sizeof(int));

    // Sekarang hitung &x[0][0][3]
    int i2=0, j2=0, k2=3;
    int offset2 = (i2 * 3 * 5) + (j2 * 5) + k2; // = 3
    long long target_address = base_A + (offset2 * sizeof(int));

    cout << "Simulasi &x[1][1][4] = 0x" << hex << known_address << endl;
    cout << "Ditemukan Alamat Dasar Array (A) = 0x" << hex << base_A << endl;
    cout << "Simulasi &x[0][0][3] = 0x" << hex << target_address << endl;

    return 0;
}

#include <iostream>
using namespace std;

int main() {
    // long biasanya 8 byte
    long x[12][14];
    long long base = 0x1000; // Simulasi &x[0][0]
    int baris = 2, kolom = 4;
    int total_kolom = 14;
    long long offset = (baris * total_kolom + kolom) * sizeof(long);
    long long alamat_x24 = base + offset;
    cout << "Simulasi &x[0][0] = 0x" << hex << base << endl;
    cout << "Simulasi &x[2][4] = 0x" << hex << alamat_x24 << endl;
    return 0;
}

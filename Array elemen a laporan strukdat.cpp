//Nama:Farsya Haikal Lesmana
//Nim:2410114014949
//Tugas: array element a

#include <iostream>
using namespace std;

int main() {
    int x[4][3] = {{0,1,2}, {3,4,5}, {6,7,8}, {9,10,11}};

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 3; j++) {
            cout << "Elemen di x[" << i << "][" << j << "]: ";
            cout << x[i][j] << endl;
        }
    }
    return 0;
}

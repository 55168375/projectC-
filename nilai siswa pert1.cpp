#include <iostream>
using namespace std;

int main() {
    int skor;
    cout << "Masukkan skor (0-100): ";
    cin >> skor;

    if (skor == 100) {
        cout << "Skor sempurna!" << endl;
    } else if (skor >= 90) {
        cout << "A" << endl;
    } else if (skor >= 80) {
        cout << "B" << endl;
    } else if (skor >= 70) {
        cout << "C" << endl;
    } else if (skor >= 60) {
        cout << "D" << endl;
    } else {
        cout << "F" << endl;
    }

    return 0;
}

//Nama:Farsya Haikal Lesmana
//Nim:241011401494
//Tugas:pert 2 array element

#include<iostream>
using namespace std;

const int MAX = 10;

void tampilkanArray(int arr[][MAX], int baris, int kolom) {
    cout << "Isi Array:" << endl;
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }
}

void jumlahkanArray(int arr[][MAX], int baris, int kolom) {
    int total = 0;
    for (int i = 0; i < baris; i++) {
        for (int j = 0; j < kolom; j++) {
            total += arr[i][j];
        }
    }
    cout << "Total semua elemen: " << total << endl;
}

int main() {
    int arr[MAX][MAX] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };
    int baris = 3, kolom = 4;
    int pilihan;
    
    do {
        cout << "\n=== MENU OPERASI ARRAY ===" << endl;
        cout << "1. Tampilkan Array" << endl;
        cout << "2. Jumlahkan Semua Elemen" << endl;
        cout << "3. Keluar" << endl;
        cout << "Pilihan: ";
        cin >> pilihan;
        
        switch(pilihan) {
            case 1:
                tampilkanArray(arr, baris, kolom);
                break;
            case 2:
                jumlahkanArray(arr, baris, kolom);
                break;
            case 3:
                cout << "Program selesai." << endl;
                break;
            default:
                cout << "Pilihan tidak valid!" << endl;
        }
    } while (pilihan != 3);
    
    return 0;
}

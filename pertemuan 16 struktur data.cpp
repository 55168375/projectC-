#include <iostream>
#include <vector>
using namespace std;

void searchTwoPointer(const vector<int>& arr, int target) {
    int left = 0;
    int right = arr.size() - 1;
    int attempts = 0;
    int position = -1;
    
    while (left <= right) {
        attempts++;
        
        if (arr[left] == target) {
            position = left;
            break;
        }
        
        if (arr[right] == target) {
            position = right;
            break;
        }
        
        left++;
        right--;
    }
    
    if (position != -1) {
        cout << "SUKSES: Elemen " << target << " ditemukan di indeks " 
             << position << " (percobaan ke-" << attempts << ")" << endl;
    } else {
        cout << "GAGAL: Elemen " << target << " tidak ditemukan setelah " 
             << attempts << " percobaan" << endl;
    }
}

int main() {
    vector<int> data;
    int n, element, searchValue;
    
    cout << "PROGRAM PENCARIAN TWO POINTER" << endl;
    cout << "=============================" << endl;
    
    // Input jumlah elemen
    cout << "Masukkan jumlah elemen array: ";
    cin >> n;
    
    // Input elemen array
    cout << "Masukkan " << n << " elemen array:" << endl;
    for (int i = 0; i < n; i++) {
        cout << "Elemen ke-" << i + 1 << ": ";
        cin >> element;
        data.push_back(element);
    }
    
    // Tampilkan array
    cout << endl << "Array yang dimasukkan: ";
    for (int i = 0; i < data.size(); i++) {
        cout << data[i] << " ";
    }
    cout << endl;
    
    // Input nilai yang dicari
    cout << endl << "Masukkan elemen yang ingin dicari: ";
    cin >> searchValue;
    
    // Proses pencarian
    cout << endl << "Hasil Pencarian:" << endl;
    searchTwoPointer(data, searchValue);
    
    return 0;
}

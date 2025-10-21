//Nama:Farsya Haikal Lesmana
//Kelas:03TPLP023
//Tugas:Pertemuan 2

#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main() {
    string input;
    getline(cin, input);
    stringstream ss(input);
    
    int nilai1;
    char nilai2;
    float nilai3;
    
    ss >> nilai1 >> nilai2 >> nilai3;
    
    cout << nilai1 << endl;
    cout << nilai2 << endl;
    cout << nilai3 << endl;
    
    return 0;
}

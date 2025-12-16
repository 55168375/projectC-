#include <iostream>
#include <string>
#include <windows.h> // Untuk fungsi animasi
#include <conio.h>   // Untuk getch()
using namespace std;

// Struktur data mahasiswa
struct Mahasiswa {
    string nama;
    string nim;
    char gender;
    float nilai;
    Mahasiswa* next;
    Mahasiswa* prev;
};

Mahasiswa* head = NULL;
Mahasiswa* tail = NULL;

// Fungsi untuk membersihkan layar dengan animasi
void clearScreen() {
    system("cls");
}

// Fungsi untuk delay dengan animasi
void delay(int milliseconds) {
    Sleep(milliseconds);
}

// Fungsi untuk menampilkan animasi loading
void loadingAnimation() {
    cout << "\n\t\t";
    for (int i = 0; i < 3; i++) {
        cout << ".";
        delay(300);
    }
    cout << " ";
}

// Fungsi untuk memindahkan kursor
void gotoxy(int x, int y) {
    COORD coord;
    coord.X = x;
    coord.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

// Fungsi untuk menampilkan header dengan animasi
void displayHeader() {
    clearScreen();
    cout << "\n\n";
    cout << "\t¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦\n";
    cout << "\t¦                                                   ¦\n";
    cout << "\t¦        C I R C U L A R   D O U B L Y             ¦\n";
    cout << "\t¦        L I N K E D   L I S T                     ¦\n";
    cout << "\t¦                                                   ¦\n";
    cout << "\t¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦\n";
    cout << "\t¦                                                   ¦\n";
    cout << "\t¦           M A N A J E M E N   D A T A            ¦\n";
    cout << "\t¦           M A H A S I S W A                      ¦\n";
    cout << "\t¦                                                   ¦\n";
    cout << "\t¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦\n\n\n";
}

// Fungsi untuk membuat node baru
Mahasiswa* createNode(string nama, string nim, char gender, float nilai) {
    Mahasiswa* newNode = new Mahasiswa();
    newNode->nama = nama;
    newNode->nim = nim;
    newNode->gender = gender;
    newNode->nilai = nilai;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

// Fungsi untuk mengecek apakah NIM sudah ada
bool isNIMExist(string nim) {
    if (head == NULL) return false;
    
    Mahasiswa* current = head;
    do {
        if (current->nim == nim) {
            return true;
        }
        current = current->next;
    } while (current != head);
    
    return false;
}

// Fungsi untuk menambahkan data dengan animasi
void insertData() {
    clearScreen();
    displayHeader();
    
    string nama, nim;
    char gender;
    float nilai;
    
    cout << "\n\n\t\t    ===== INSERT DATA MAHASISWA =====\n\n";
    
    // Input NIM dengan validasi
    while (true) {
        cout << "\t\tMasukkan NIM      : ";
        cin >> nim;
        
        if (isNIMExist(nim)) {
            cout << "\t\t[!] NIM sudah ada! Silakan masukkan NIM lain.\n";
            loadingAnimation();
        } else {
            break;
        }
    }
    
    cout << "\t\tMasukkan Nama     : ";
    cin.ignore();
    getline(cin, nama);
    
    cout << "\t\tMasukkan Gender (L/P) : ";
    cin >> gender;
    
    cout << "\t\tMasukkan Nilai    : ";
    cin >> nilai;
    
    Mahasiswa* newNode = createNode(nama, nim, gender, nilai);
    
    // Animasi proses insert
    cout << "\n\t\tMemproses data";
    loadingAnimation();
    
    if (head == NULL) {
        // Jika linked list kosong
        head = newNode;
        tail = newNode;
        head->next = head;
        head->prev = head;
        
        // Animasi node pertama
        cout << "\n\n\t\t[?] Data berhasil ditambahkan sebagai node pertama!\n";
    } else {
        // Cari posisi yang tepat (terurut berdasarkan NIM)
        Mahasiswa* current = head;
        bool inserted = false;
        
        do {
            if (nim < current->nim) {
                // Insert sebelum current node
                newNode->next = current;
                newNode->prev = current->prev;
                current->prev->next = newNode;
                current->prev = newNode;
                
                if (current == head) {
                    head = newNode;
                }
                inserted = true;
                break;
            }
            current = current->next;
        } while (current != head);
        
        // Jika NIM terbesar, insert di akhir
        if (!inserted) {
            newNode->next = head;
            newNode->prev = tail;
            tail->next = newNode;
            head->prev = newNode;
            tail = newNode;
        }
        
        // Animasi node terhubung
        cout << "\n\n\t\t[?] Data berhasil ditambahkan!\n";
        cout << "\t\t    Node terhubung secara circular...\n";
    }
    
    delay(1000);
}

// Fungsi untuk menghapus data dengan animasi
void deleteData() {
    clearScreen();
    displayHeader();
    
    if (head == NULL) {
        cout << "\n\n\t\t[!] Linked List kosong!\n";
        cout << "\t\t    Tidak ada data yang bisa dihapus.\n";
        delay(1500);
        return;
    }
    
    cout << "\n\n\t\t    ===== HAPUS DATA MAHASISWA =====\n\n";
    
    string nim;
    cout << "\t\tMasukkan NIM yang akan dihapus : ";
    cin >> nim;
    
    cout << "\n\t\tMencari data";
    loadingAnimation();
    
    Mahasiswa* current = head;
    bool found = false;
    
    do {
        if (current->nim == nim) {
            found = true;
            break;
        }
        current = current->next;
    } while (current != head);
    
    if (!found) {
        cout << "\n\n\t\t[!] Data dengan NIM " << nim << " tidak ditemukan!\n";
        delay(1500);
        return;
    }
    
    // Tampilkan data yang akan dihapus
    cout << "\n\n\t\tData ditemukan:\n";
    cout << "\t\t------------------------------------\n";
    cout << "\t\tNIM    : " << current->nim << endl;
    cout << "\t\tNama   : " << current->nama << endl;
    cout << "\t\tGender : " << current->gender << endl;
    cout << "\t\tNilai  : " << current->nilai << endl;
    cout << "\t\t------------------------------------\n";
    
    cout << "\n\t\tMenghapus data";
    loadingAnimation();
    
    // Proses penghapusan
    if (current == head && current->next == head) {
        // Hanya satu node
        delete current;
        head = NULL;
        tail = NULL;
        cout << "\n\n\t\t[?] Data berhasil dihapus!\n";
        cout << "\t\t    Linked List sekarang kosong.\n";
    } else {
        // Ada lebih dari satu node
        current->prev->next = current->next;
        current->next->prev = current->prev;
        
        if (current == head) {
            head = current->next;
        }
        if (current == tail) {
            tail = current->prev;
        }
        
        delete current;
        
        // Animasi penyesuaian pointer
        cout << "\n\n\t\t[?] Data berhasil dihapus!\n";
        cout << "\t\t    Pointer disesuaikan...\n";
        
        // Tampilkan animasi linked list setelah penghapusan
        cout << "\n\t\t[!] Prev <-> Next pointers telah diperbarui!\n";
    }
    
    delay(1500);
}

// Fungsi untuk mencetak data dengan animasi
void printData() {
    clearScreen();
    displayHeader();
    
    cout << "\n\n\t\t    ===== DATA MAHASISWA =====\n\n";
    
    if (head == NULL) {
        cout << "\t\t[!] Linked List kosong!\n";
        delay(1500);
        return;
    }
    
    cout << "\t\tMemuat data";
    loadingAnimation();
    
    cout << "\n\n";
    cout << "\t\t+---------------------------------------------------+\n";
    cout << "\t\t¦    NIM     ¦        NAMA        ¦ GENDER ¦  NILAI ¦\n";
    cout << "\t\t+------------+--------------------+--------+--------¦\n";
    
    Mahasiswa* current = head;
    int count = 0;
    
    do {
        // Animasi baris per baris
        cout << "\t\t¦ " << current->nim;
        for (int i = current->nim.length(); i < 10; i++) cout << " ";
        cout << " ¦ " << current->nama;
        for (int i = current->nama.length(); i < 18; i++) cout << " ";
        cout << " ¦   " << current->gender << "    ¦ ";
        printf("%6.2f ¦\n", current->nilai);
        
        count++;
        current = current->next;
        
        if (current != head) {
            delay(200); // Animasi delay antar baris
        }
    } while (current != head);
    
    cout << "\t\t+---------------------------------------------------+\n";
    
    // Tampilkan informasi linked list
    cout << "\n\n\t\t[!] Total Data: " << count << " mahasiswa\n";
    cout << "\t\t[!] Linked List: Circular Doubly Linked List\n";
    cout << "\t\t[!] Pointer Head ? " << head->nim << endl;
    cout << "\t\t[!] Pointer Tail ? " << tail->nim << endl;
    
    // Tampilkan hubungan circular
    cout << "\n\t\t[!] Hubungan Circular:\n";
    cout << "\t\t    Tail ? Next ? Head: " << tail->nim << " ? " << tail->next->nim << endl;
    cout << "\t\t    Head ? Prev ? Tail: " << head->nim << " ? " << head->prev->nim << endl;
    
    cout << "\n\n\t\tTekan Enter untuk kembali ke menu...";
    cin.ignore();
    cin.get();
}

// Fungsi untuk menampilkan menu dengan animasi
void displayMenu() {
    clearScreen();
    displayHeader();
    
    cout << "\n\n";
    cout << "\t\t+--------------------------------------------+\n";
    cout << "\t\t¦                 M E N U                    ¦\n";
    cout << "\t\t¦--------------------------------------------¦\n";
    
    // Animasi munculnya menu
    string menuItems[4] = {
        "1. INSERT DATA",
        "2. HAPUS DATA",
        "3. CETAK DATA",
        "4. EXIT"
    };
    
    for (int i = 0; i < 4; i++) {
        delay(150);
        cout << "\t\t¦                                            ¦\n";
        cout << "\t\t¦        " << menuItems[i];
        for (int j = menuItems[i].length(); j < 36; j++) cout << " ";
        cout << "¦\n";
    }
    
    cout << "\t\t¦                                            ¦\n";
    cout << "\t\t+--------------------------------------------+\n\n";
}

// Fungsi utama
int main() {
    // Set console title
    SetConsoleTitle("Circular Doubly Linked List - Management Data Mahasiswa");
    
    int choice;
    
    do {
        displayMenu();
        
        cout << "\n\t\tPilihan (1 - 4) : ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                insertData();
                break;
            case 2:
                deleteData();
                break;
            case 3:
                printData();
                break;
            case 4:
                clearScreen();
                cout << "\n\n\n";
                cout << "\t\t¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦\n";
                cout << "\t\t¦                                                   ¦\n";
                cout << "\t\t¦                 T E R I M A  K A S I H            ¦\n";
                cout << "\t\t¦                                                   ¦\n";
                cout << "\t\t¦          Program Circular Doubly Linked List     ¦\n";
                cout << "\t\t¦                telah selesai digunakan           ¦\n";
                cout << "\t\t¦                                                   ¦\n";
                cout << "\t\t¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦¦\n";
                
                cout << "\n\n\t\tKeluar dari program";
                loadingAnimation();
                cout << "\n\n";
                break;
            default:
                cout << "\n\t\t[!] Pilihan tidak valid! Silakan pilih 1-4.\n";
                delay(1000);
                break;
        }
    } while (choice != 4);
    
    return 0;
}

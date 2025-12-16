#include <iostream>
#include <string>
#include <iomanip>
#include <windows.h>  // Untuk fungsi animasi di Windows
#include <conio.h>    // Untuk getch()
#include <cstdlib>    // Untuk system()
using namespace std;

// Deklarasi warna konsol untuk Windows
#ifdef _WIN32
#define COLOR_RESET   "\033[0m"
#define COLOR_RED     "\033[31m"
#define COLOR_GREEN   "\033[32m"
#define COLOR_YELLOW  "\033[33m"
#define COLOR_BLUE    "\033[34m"
#define COLOR_MAGENTA "\033[35m"
#define COLOR_CYAN    "\033[36m"
#define COLOR_WHITE   "\033[37m"
#else
#define COLOR_RESET   ""
#define COLOR_RED     ""
#define COLOR_GREEN   ""
#define COLOR_YELLOW  ""
#define COLOR_BLUE    ""
#define COLOR_MAGENTA ""
#define COLOR_CYAN    ""
#define COLOR_WHITE   ""
#endif

// Struktur data mahasiswa
struct Mahasiswa {
    string nama;
    string nim;
    char gender;
    float nilai;
    Mahasiswa* next;
};

// Pointer global untuk head dan tail
Mahasiswa* head = NULL;
Mahasiswa* tail = NULL;

// Fungsi untuk membersihkan layar
void clearScreen() {
    system("cls");
}

// Fungsi untuk delay dengan animasi
void delay(int milliseconds) {
    Sleep(milliseconds);
}

// Fungsi untuk animasi loading
void showLoading(string message = "Memproses") {
    cout << "\n\t" << message;
    for (int i = 0; i < 3; i++) {
        cout << ".";
        cout.flush();
        delay(300);
    }
    cout << "\n";
}

// Fungsi untuk menampilkan header
void displayHeader() {
    clearScreen();
    
    cout << COLOR_CYAN;
    cout << "\n\n";
    cout << "\t==============================================================\n";
    cout << "\t                  CIRCULAR LINKED LIST                        \n";
    cout << "\t                   DATA MAHASISWA                             \n";
    cout << "\t==============================================================\n";
    cout << COLOR_RESET;
}

// Fungsi untuk menampilkan menu
void displayMenu() {
    cout << COLOR_MAGENTA;
    cout << "\n\t====================== MENU UTAMA ======================\n";
    cout << COLOR_RESET;
    
    // Menampilkan menu items
    cout << COLOR_YELLOW;
    cout << "\n\t1. INSERT DATA (Tambah Data Mahasiswa)";
    cout << "\n\t2. HAPUS DATA  (Hapus Data berdasarkan NIM)";
    cout << "\n\t3. CETAK DATA  (Tampilkan Semua Data)";
    cout << "\n\t4. EXIT        (Keluar dari Program)";
    cout << COLOR_RESET;
    
    cout << COLOR_MAGENTA;
    cout << "\n\t========================================================\n";
    cout << COLOR_RESET;
}

// Fungsi untuk membuat node baru
Mahasiswa* createNode(string nama, string nim, char gender, float nilai) {
    Mahasiswa* newNode = new Mahasiswa();
    newNode->nama = nama;
    newNode->nim = nim;
    newNode->gender = gender;
    newNode->nilai = nilai;
    newNode->next = NULL;
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

// Fungsi untuk menampilkan animasi insert
void animateInsert(Mahasiswa* newNode, Mahasiswa* prevNode = NULL, Mahasiswa* nextNode = NULL) {
    cout << COLOR_GREEN;
    cout << "\n\t[ANIMASI PENYISIPAN NODE]\n";
    cout << COLOR_RESET;
    
    cout << "\n\tMembuat node baru: ";
    cout << COLOR_CYAN << "[" << newNode->nim << "]" << COLOR_RESET << "\n";
    delay(500);
    
    if (prevNode) {
        cout << "\t" << prevNode->nim << " ? [" << newNode->nim << "]\n";
        delay(500);
    }
    
    if (nextNode) {
        cout << "\t[" << newNode->nim << "] ? " << nextNode->nim << "\n";
        delay(500);
    }
    
    if (newNode->next == head) {
        cout << "\n\t? Membuat hubungan circular: ";
        cout << newNode->nim << " ? " << head->nim << "\n";
        delay(500);
    }
}

// Fungsi untuk menambahkan data (INSERT DATA)
void insertData() {
    displayHeader();
    
    cout << COLOR_BLUE;
    cout << "\n\t================ INSERT DATA MAHASISWA ================\n";
    cout << COLOR_RESET;
    
    string nama, nim;
    char gender;
    float nilai;
    
    cout << COLOR_YELLOW;
    cout << "\n\tMasukkan data mahasiswa:\n";
    cout << "\t--------------------------\n";
    cout << COLOR_RESET;
    
    // Input NIM dengan validasi
    bool nimValid = false;
    while (!nimValid) {
        cout << "\n\tNIM     : ";
        cin >> nim;
        
        if (isNIMExist(nim)) {
            cout << COLOR_RED;
            cout << "\t! NIM sudah terdaftar! Silakan masukkan NIM lain.\n";
            cout << COLOR_RESET;
        } else {
            nimValid = true;
        }
    }
    
    cout << "\tNama    : ";
    cin.ignore();
    getline(cin, nama);
    
    cout << "\tGender (L/P): ";
    cin >> gender;
    gender = toupper(gender);
    
    cout << "\tNilai   : ";
    cin >> nilai;
    
    // Validasi nilai
    while (nilai < 0 || nilai > 100) {
        cout << COLOR_RED;
        cout << "\t! Nilai harus antara 0-100!\n";
        cout << COLOR_RESET;
        cout << "\tNilai   : ";
        cin >> nilai;
    }
    
    // Membuat node baru
    Mahasiswa* newNode = createNode(nama, nim, gender, nilai);
    
    showLoading("\n\tMenyisipkan data");
    
    // Kasus 1: Linked list kosong
    if (head == NULL) {
        head = newNode;
        tail = newNode;
        newNode->next = head;  // Circular link
        
        cout << COLOR_GREEN;
        cout << "\n\t[SUKSES] Data berhasil ditambahkan sebagai node pertama!\n";
        cout << "\tHead = Tail = " << newNode->nim << "\n";
        cout << COLOR_RESET;
        
        delay(500);
        cout << "\n\t? Membuat hubungan circular...\n";
        delay(500);
        cout << "\t" << newNode->nim << " ? " << newNode->next->nim << "\n";
    }
    // Kasus 2: Insert di awal (NIM lebih kecil dari head)
    else if (nim < head->nim) {
        newNode->next = head;
        head = newNode;
        tail->next = head;  // Update circular link
        
        cout << COLOR_GREEN;
        cout << "\n\t[SUKSES] Data berhasil ditambahkan di awal list!\n";
        cout << COLOR_RESET;
        
        animateInsert(newNode, NULL, head->next);
    }
    // Kasus 3: Insert di akhir (NIM lebih besar dari tail)
    else if (nim > tail->nim) {
        tail->next = newNode;
        newNode->next = head;
        tail = newNode;
        
        cout << COLOR_GREEN;
        cout << "\n\t[SUKSES] Data berhasil ditambahkan di akhir list!\n";
        cout << COLOR_RESET;
        
        animateInsert(newNode, tail, head);
    }
    // Kasus 4: Insert di tengah
    else {
        Mahasiswa* current = head;
        Mahasiswa* prev = tail;  // Karena circular, prev dari head adalah tail
        
        do {
            if (nim < current->nim) {
                break;
            }
            prev = current;
            current = current->next;
        } while (current != head);
        
        // Insert setelah prev dan sebelum current
        newNode->next = current;
        prev->next = newNode;
        
        cout << COLOR_GREEN;
        cout << "\n\t[SUKSES] Data berhasil ditambahkan di posisi tengah!\n";
        cout << COLOR_RESET;
        
        animateInsert(newNode, prev, current);
    }
    
    delay(1500);
}

// Fungsi untuk menampilkan animasi delete
void animateDelete(Mahasiswa* nodeToDelete, Mahasiswa* prevNode, Mahasiswa* nextNode) {
    cout << COLOR_MAGENTA;
    cout << "\n\t[ANIMASI PENGHAPUSAN NODE]\n";
    cout << COLOR_RESET;
    
    cout << "\n\tNode yang dihapus: ";
    cout << COLOR_RED << "[" << nodeToDelete->nim << "]" << COLOR_RESET << "\n";
    delay(500);
    
    if (prevNode) {
        cout << "\tSebelum: " << prevNode->nim << " ? [" << nodeToDelete->nim << "]\n";
        delay(500);
        cout << "\tSesudah: " << prevNode->nim << " ? " << nextNode->nim << "\n";
        delay(500);
    }
    
    if (nextNode) {
        cout << "\tMenyesuaikan pointer next...\n";
        delay(500);
    }
}

// Fungsi untuk menghapus data (HAPUS DATA)
void deleteData() {
    displayHeader();
    
    cout << COLOR_BLUE;
    cout << "\n\t================ HAPUS DATA MAHASISWA ================\n";
    cout << COLOR_RESET;
    
    if (head == NULL) {
        cout << COLOR_RED;
        cout << "\n\t[ERROR] Linked List kosong! Tidak ada data yang bisa dihapus.\n";
        cout << COLOR_RESET;
        delay(1500);
        return;
    }
    
    string nim;
    cout << COLOR_YELLOW;
    cout << "\n\tMasukkan NIM yang akan dihapus: ";
    cout << COLOR_RESET;
    cin >> nim;
    
    showLoading("\n\tMencari data");
    
    Mahasiswa* current = head;
    Mahasiswa* prev = tail;  // Karena circular
    bool found = false;
    
    // Cari node yang akan dihapus
    do {
        if (current->nim == nim) {
            found = true;
            break;
        }
        prev = current;
        current = current->next;
    } while (current != head);
    
    if (!found) {
        cout << COLOR_RED;
        cout << "\n\t[ERROR] Data dengan NIM " << nim << " tidak ditemukan!\n";
        cout << COLOR_RESET;
        delay(1500);
        return;
    }
    
    // Tampilkan data yang akan dihapus
    cout << COLOR_CYAN;
    cout << "\n\tData yang akan dihapus:\n";
    cout << "\t-----------------------\n";
    cout << "\tNIM    : " << current->nim << "\n";
    cout << "\tNama   : " << current->nama << "\n";
    cout << "\tGender : " << current->gender << "\n";
    cout << "\tNilai  : " << current->nilai << "\n";
    cout << COLOR_RESET;
    
    // Konfirmasi penghapusan
    char confirm;
    cout << COLOR_YELLOW;
    cout << "\n\tApakah yakin ingin menghapus? (Y/N): ";
    cout << COLOR_RESET;
    cin >> confirm;
    confirm = toupper(confirm);
    
    if (confirm != 'Y') {
        cout << COLOR_BLUE;
        cout << "\n\tPenghapusan dibatalkan.\n";
        cout << COLOR_RESET;
        delay(1000);
        return;
    }
    
    showLoading("\n\tMenghapus data");
    
    // Animasi penghapusan
    animateDelete(current, prev, current->next);
    
    // Proses penghapusan
    // Kasus 1: Hanya satu node
    if (current == head && current->next == head) {
        delete current;
        head = NULL;
        tail = NULL;
        
        cout << COLOR_GREEN;
        cout << "\n\t[SUKSES] Data berhasil dihapus! Linked List sekarang kosong.\n";
        cout << COLOR_RESET;
    }
    // Kasus 2: Node adalah head (bukan satu-satunya)
    else if (current == head) {
        head = head->next;
        tail->next = head;  // Update circular link
        delete current;
        
        cout << COLOR_GREEN;
        cout << "\n\t[SUKSES] Data di awal list berhasil dihapus!\n";
        cout << "\tHead baru: " << head->nim << "\n";
        cout << COLOR_RESET;
    }
    // Kasus 3: Node adalah tail (bukan satu-satunya)
    else if (current == tail) {
        tail = prev;
        tail->next = head;  // Update circular link
        delete current;
        
        cout << COLOR_GREEN;
        cout << "\n\t[SUKSES] Data di akhir list berhasil dihapus!\n";
        cout << "\tTail baru: " << tail->nim << "\n";
        cout << COLOR_RESET;
    }
    // Kasus 4: Node di tengah
    else {
        prev->next = current->next;
        delete current;
        
        cout << COLOR_GREEN;
        cout << "\n\t[SUKSES] Data di tengah list berhasil dihapus!\n";
        cout << COLOR_RESET;
    }
    
    delay(1500);
}

// Fungsi untuk visualisasi linked list
void visualizeLinkedList() {
    if (head == NULL) return;
    
    cout << COLOR_CYAN;
    cout << "\n\tVISUALISASI LINKED LIST:\n";
    cout << "\t";
    
    Mahasiswa* current = head;
    int count = 0;
    
    do {
        cout << "[" << current->nim << "]";
        if (current->next != head) {
            cout << " -> ";
        }
        current = current->next;
        count++;
        
        // Batasi tampilan untuk mencegah overflow
        if (count >= 5 && current != head) {
            cout << " ... -> [" << tail->nim << "]";
            break;
        }
    } while (current != head);
    
    cout << " -> [HEAD]\n";
    cout << COLOR_RESET;
}

// Fungsi untuk mencetak data (CETAK DATA)
void printData() {
    displayHeader();
    
    cout << COLOR_BLUE;
    cout << "\n\t================ CETAK DATA MAHASISWA ================\n";
    cout << COLOR_RESET;
    
    if (head == NULL) {
        cout << COLOR_RED;
        cout << "\n\t[ERROR] Linked List kosong! Tidak ada data untuk ditampilkan.\n";
        cout << COLOR_RESET;
        delay(1500);
        return;
    }
    
    showLoading("\n\tMemuat data");
    
    // Tampilkan header tabel
    cout << COLOR_CYAN;
    cout << "\n\t+------------+--------------------+--------+--------+-----------------+\n";
    cout << "\t|    NIM     |        NAMA        | GENDER |  NILAI |      NEXT       |\n";
    cout << "\t+------------+--------------------+--------+--------+-----------------+\n";
    cout << COLOR_RESET;
    
    Mahasiswa* current = head;
    int count = 0;
    float totalNilai = 0;
    
    // Traverse dan tampilkan semua node
    do {
        // Tampilkan data dengan animasi per baris
        cout << "\t| " << COLOR_YELLOW << setw(10) << left << current->nim << COLOR_RESET << " | ";
        cout << COLOR_GREEN << setw(18) << left;
        if (current->nama.length() > 18) {
            cout << current->nama.substr(0, 15) << "...";
        } else {
            cout << current->nama;
        }
        cout << COLOR_RESET << " |   ";
        
        // Tampilkan gender dengan warna
        if (current->gender == 'L' || current->gender == 'l') {
            cout << COLOR_BLUE << "L" << COLOR_RESET;
        } else {
            cout << COLOR_MAGENTA << "P" << COLOR_RESET;
        }
        cout << "    | ";
        
        // Warna nilai berdasarkan range
        if (current->nilai >= 85) {
            cout << COLOR_GREEN;
        } else if (current->nilai >= 70) {
            cout << COLOR_YELLOW;
        } else if (current->nilai >= 60) {
            cout << COLOR_MAGENTA;
        } else {
            cout << COLOR_RED;
        }
        cout << setw(6) << fixed << setprecision(2) << current->nilai << COLOR_RESET << " | ";
        
        // Tampilkan pointer next
        cout << COLOR_CYAN << "-> " << current->next->nim;
        for (int i = current->next->nim.length(); i < 13; i++) cout << " ";
        cout << COLOR_RESET << "|\n";
        
        totalNilai += current->nilai;
        count++;
        current = current->next;
        
        // Delay untuk efek animasi
        if (current != head) {
            delay(150);
        }
        
    } while (current != head);
    
    cout << COLOR_CYAN;
    cout << "\t+------------+--------------------+--------+--------+-----------------+\n";
    cout << COLOR_RESET;
    
    // Tampilkan statistik
    cout << COLOR_MAGENTA;
    cout << "\n\t==================== STATISTIK DATA ====================\n";
    cout << COLOR_RESET;
    
    cout << "\n\t" << COLOR_GREEN << "> Total Data      : " << count << " mahasiswa\n" << COLOR_RESET;
    cout << "\t" << COLOR_YELLOW << "> Rata-rata Nilai : " << fixed << setprecision(2) 
         << (count > 0 ? totalNilai / count : 0) << "\n" << COLOR_RESET;
    
    if (head != NULL) {
        cout << "\t" << COLOR_BLUE << "> Head (Awal)     : " << head->nim << " - " 
             << (head->nama.length() > 15 ? head->nama.substr(0, 15) + "..." : head->nama) 
             << "\n" << COLOR_RESET;
        cout << "\t" << COLOR_MAGENTA << "> Tail (Akhir)    : " << tail->nim << " - " 
             << (tail->nama.length() > 15 ? tail->nama.substr(0, 15) + "..." : tail->nama) 
             << "\n" << COLOR_RESET;
    }
    
    // Visualisasi linked list
    visualizeLinkedList();
    
    // Tampilkan hubungan circular
    cout << COLOR_CYAN;
    cout << "\n\t============ HUBUNGAN CIRCULAR LINKED LIST ============\n";
    cout << COLOR_RESET;
    
    if (head != NULL && tail != NULL) {
        cout << "\n\t" << COLOR_YELLOW << "Next dari Tail -> Head: " << tail->nim 
             << " -> " << tail->next->nim << "\n" << COLOR_RESET;
        
        // Verifikasi circular
        cout << "\n\t" << COLOR_GREEN << "? Verifikasi Circular: " << COLOR_RESET;
        Mahasiswa* temp = head;
        int steps = 0;
        do {
            temp = temp->next;
            steps++;
        } while (temp != head && steps <= count * 2);
        
        if (temp == head && steps == count) {
            cout << COLOR_GREEN << "Berhasil kembali ke head setelah " << steps << " langkah\n" << COLOR_RESET;
        } else if (temp == head) {
            cout << COLOR_GREEN << "Circular terverifikasi\n" << COLOR_RESET;
        } else {
            cout << COLOR_RED << "Gagal verifikasi circular\n" << COLOR_RESET;
        }
    }
    
    cout << COLOR_GREEN;
    cout << "\n\tTekan Enter untuk kembali ke menu...";
    cout << COLOR_RESET;
    cin.ignore();
    cin.get();
}

// Fungsi utama
int main() {
    // Set judul konsol untuk Windows
    SetConsoleTitle("Circular Linked List - Manajemen Data Mahasiswa");
    
    int choice;
    
    do {
        displayHeader();
        displayMenu();
        
        cout << COLOR_YELLOW;
        cout << "\n\tPilihan (1 - 4) : ";
        cout << COLOR_RESET;
        
        // Validasi input
        if (!(cin >> choice)) {
            cin.clear();
            cin.ignore(1000, '\n');
            cout << COLOR_RED;
            cout << "\n\t[ERROR] Input tidak valid! Harap masukkan angka 1-4.\n";
            cout << COLOR_RESET;
            delay(1500);
            continue;
        }
        
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
                displayHeader();
                
                cout << COLOR_GREEN;
                cout << "\n\n\t==============================================================\n";
                cout << "\t                    TERIMA KASIH                             \n";
                cout << "\t           Telah menggunakan program ini                     \n";
                cout << "\t==============================================================\n\n";
                cout << COLOR_RESET;
                
                showLoading("\n\tKeluar dari program");
                
                cout << "\n\n";
                break;
            default:
                cout << COLOR_RED;
                cout << "\n\t[ERROR] Pilihan tidak valid! Harap masukkan angka 1-4.\n";
                cout << COLOR_RESET;
                delay(1500);
                break;
        }
        
    } while (choice != 4);
    
    return 0;
}

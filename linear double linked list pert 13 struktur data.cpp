#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// Struktur data mahasiswa
typedef struct Mahasiswa {
    char nama[50];
    char nim[15];
    char gender;
    float nilai;
    struct Mahasiswa *prev;
    struct Mahasiswa *next;
} Mahasiswa;

Mahasiswa *head = NULL;
Mahasiswa *tail = NULL;

// Fungsi untuk membersihkan layar (cross-platform)
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

// Fungsi untuk delay (animasi)
void delay(int milliseconds) {
    usleep(milliseconds * 1000);
}

// Fungsi untuk membuat node baru
Mahasiswa* createNode(char nama[], char nim[], char gender, float nilai) {
    Mahasiswa *newNode = (Mahasiswa*)malloc(sizeof(Mahasiswa));
    strcpy(newNode->nama, nama);
    strcpy(newNode->nim, nim);
    newNode->gender = gender;
    newNode->nilai = nilai;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Fungsi untuk menampilkan animasi loading
void showLoading(char *message) {
    printf("\n%s", message);
    fflush(stdout);
    for(int i = 0; i < 3; i++) {
        printf(".");
        fflush(stdout);
        delay(500);
    }
    printf("\n");
}

// Fungsi untuk insert data dengan animasi
void insertData() {
    char nama[50], nim[15], gender;
    float nilai;
    
    clearScreen();
    printf("+--------------------------------------+\n");
    printf("¦           INSERT DATA MAHASISWA     ¦\n");
    printf("+--------------------------------------+\n\n");
    
    printf("Masukkan NAMA    : ");
    scanf(" %[^\n]", nama);
    printf("Masukkan NIM     : ");
    scanf(" %s", nim);
    printf("Masukkan GENDER (L/P): ");
    scanf(" %c", &gender);
    printf("Masukkan NILAI   : ");
    scanf("%f", &nilai);
    
    showLoading("Memproses data");
    
    Mahasiswa *newNode = createNode(nama, nim, gender, nilai);
    
    // Jika linked list kosong
    if (head == NULL) {
        head = tail = newNode;
        printf("? Data berhasil ditambahkan sebagai elemen pertama!\n");
    } 
    // Insert di awal jika NIM lebih kecil dari head
    else if (strcmp(nim, head->nim) < 0) {
        showLoading("Menambahkan di awal list");
        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        printf("? Data berhasil ditambahkan di awal list!\n");
    }
    // Insert di akhir jika NIM lebih besar dari tail
    else if (strcmp(nim, tail->nim) > 0) {
        showLoading("Menambahkan di akhir list");
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        printf("? Data berhasil ditambahkan di akhir list!\n");
    }
    // Insert di tengah
    else {
        showLoading("Mencari posisi yang tepat");
        Mahasiswa *current = head;
        
        while (current != NULL && strcmp(nim, current->nim) > 0) {
            current = current->next;
        }
        
        if (current != NULL && strcmp(nim, current->nim) == 0) {
            printf("? Error: NIM sudah ada dalam database!\n");
            free(newNode);
            return;
        }
        
        // Insert sebelum current
        newNode->next = current;
        newNode->prev = current->prev;
        current->prev->next = newNode;
        current->prev = newNode;
        
        printf("? Data berhasil ditambahkan di tengah list!\n");
    }
    
    delay(1000);
}

// Fungsi untuk menghapus data berdasarkan NIM dengan animasi
void deleteData() {
    char nim[15];
    
    clearScreen();
    printf("+--------------------------------------+\n");
    printf("¦           HAPUS DATA MAHASISWA      ¦\n");
    printf("+--------------------------------------+\n\n");
    
    if (head == NULL) {
        printf("? Linked list kosong! Tidak ada data untuk dihapus.\n");
        delay(1500);
        return;
    }
    
    printf("Masukkan NIM yang akan dihapus: ");
    scanf(" %s", nim);
    
    showLoading("Mencari data");
    
    Mahasiswa *current = head;
    
    // Cari data berdasarkan NIM
    while (current != NULL) {
        if (strcmp(current->nim, nim) == 0) {
            break;
        }
        current = current->next;
    }
    
    if (current == NULL) {
        printf("? Data dengan NIM %s tidak ditemukan!\n", nim);
        delay(1500);
        return;
    }
    
    showLoading("Menghapus data");
    
    // Kasus 1: Hanya satu elemen
    if (head == tail) {
        free(head);
        head = tail = NULL;
    }
    // Kasus 2: Hapus elemen pertama
    else if (current == head) {
        head = head->next;
        head->prev = NULL;
        free(current);
    }
    // Kasus 3: Hapus elemen terakhir
    else if (current == tail) {
        tail = tail->prev;
        tail->next = NULL;
        free(current);
    }
    // Kasus 4: Hapus elemen di tengah
    else {
        current->prev->next = current->next;
        current->next->prev = current->prev;
        free(current);
    }
    
    printf("? Data dengan NIM %s berhasil dihapus!\n", nim);
    delay(1000);
}

// Fungsi untuk mencetak data dengan animasi
void printData() {
    clearScreen();
    printf("+----------------------------------------------------------------------+\n");
    printf("¦                        CETAK DATA MAHASISWA                         ¦\n");
    printf("+----------------------------------------------------------------------+\n\n");
    
    if (head == NULL) {
        printf("? Linked list kosong! Tidak ada data untuk ditampilkan.\n");
        delay(1500);
        return;
    }
    
    showLoading("Memuat data");
    
    printf("+----------------------------------------------------+\n");
    printf("¦     NIM      ¦       NAMA        ¦ GENDER ¦  NILAI ¦\n");
    printf("+--------------+-------------------+--------+--------¦\n");
    
    Mahasiswa *current = head;
    int count = 0;
    
    while (current != NULL) {
        printf("¦ %-12s ¦ %-17s ¦   %c    ¦ %6.2f ¦\n", 
               current->nim, current->nama, current->gender, current->nilai);
        
        // Animasi untuk setiap baris data
        delay(200);
        
        current = current->next;
        count++;
    }
    
    printf("+----------------------------------------------------+\n");
    printf("\nTotal data: %d mahasiswa\n", count);
    
    printf("\nTekan Enter untuk kembali ke menu...");
    getchar(); // Clear buffer
    getchar(); // Wait for Enter
}

// Fungsi untuk menampilkan menu
void displayMenu() {
    clearScreen();
    printf("+--------------------------------------+\n");
    printf("¦     PROGRAM DOUBLY LINKED LIST      ¦\n");
    printf("¦         DATA MAHASISWA              ¦\n");
    printf("¦--------------------------------------¦\n");
    printf("¦ 1. INSERT DATA                      ¦\n");
    printf("¦ 2. HAPUS DATA                       ¦\n");
    printf("¦ 3. CETAK DATA                       ¦\n");
    printf("¦ 4. EXIT                             ¦\n");
    printf("+--------------------------------------+\n");
    printf("Pilih menu [1-4]: ");
}

// Fungsi untuk free semua memory
void freeMemory() {
    Mahasiswa *current = head;
    Mahasiswa *next;
    
    while (current != NULL) {
        next = current->next;
        free(current);
        current = next;
    }
    
    head = tail = NULL;
}

int main() {
    int choice;
    
    do {
        displayMenu();
        scanf("%d", &choice);
        
        switch(choice) {
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
                showLoading("Keluar dari program");
                printf("Terima kasih telah menggunakan program ini!\n");
                break;
            default:
                printf("Pilihan tidak valid! Silakan pilih 1-4.\n");
                delay(1500);
                break;
        }
    } while(choice != 4);
    
    freeMemory();
    return 0;
}

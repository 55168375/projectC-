#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>  // Untuk Sleep() di Windows

// Untuk sistem non-Windows, gunakan:
// #include <unistd.h>  // Untuk usleep()

void print_array(int arr[], int n, int highlight1, int highlight2, int swapped) {
    for(int i = 0; i < n; i++) {
        if(i == highlight1 || i == highlight2) {
            if(swapped) {
                printf("\033[1;32m[%d]\033[0m ", arr[i]);  // Hijau untuk yang ditukar
            } else {
                printf("\033[1;33m[%d]\033[0m ", arr[i]);  // Kuning untuk sedang dibandingkan
            }
        } else {
            printf("%d ", arr[i]);
        }
    }
}

void print_pass_header(int pass, int iteration, int total_passes) {
    printf("\n+---------------------------------------------+\n");
    printf("¦ PASS %d/%d - Iterasi %d                      ¦\n", 
           pass, total_passes, iteration);
    printf("+---------------------------------------------+\n");
}

void print_comparison(int a, int b, int should_swap) {
    printf("  Membandingkan: \033[1;33m%d\033[0m dan \033[1;33m%d\033[0m ? ", a, b);
    if(should_swap) {
        printf("\033[1;32m%d > %d ? TUKAR\033[0m\n", a, b);
    } else {
        printf("\033[1;34m%d = %d ? TETAP\033[0m\n", a, b);
    }
}

void bubble_sort_animation(int data[], int n) {
    int i, j, temp;
    int swapped;
    int total_passes = n - 1;
    int total_iterations = 0;
    
    system("cls");  // Clear screen (Windows)
    // system("clear");  // Untuk Linux/Mac
    
    printf("\n----------------------------------------------------------------\n");
    printf("                     ANIMASI BUBBLE SORT                       \n");
    printf("----------------------------------------------------------------\n");
    
    printf("\n?? DATA AWAL: ");
    print_array(data, n, -1, -1, 0);
    printf("\n");
    
    for(i = 0; i < n-1; i++) {
        swapped = 0;
        printf("\n----------------------------------------------------------------\n");
        printf("                     PASS %d dimulai                           \n", i+1);
        printf("----------------------------------------------------------------\n");
        
        for(j = 0; j < n-1-i; j++) {
            total_iterations++;
            
            print_pass_header(i+1, j+1, total_passes);
            
            // Tampilkan array sebelum perbandingan
            printf("\n?? Array sebelum: ");
            print_array(data, n, j, j+1, 0);
            printf("\n");
            
            // Tampilkan perbandingan
            print_comparison(data[j], data[j+1], data[j] > data[j+1]);
            
            if(data[j] > data[j+1]) {
                // Proses pertukaran
                printf("\n?? Proses pertukaran:\n");
                printf("   %d ? %d\n", data[j], data[j+1]);
                
                // Tukar elemen
                temp = data[j];
                data[j] = data[j+1];
                data[j+1] = temp;
                swapped = 1;
                
                // Tampilkan array setelah pertukaran
                printf("\n? Array setelah: ");
                print_array(data, n, j, j+1, 1);
                printf("\n");
            } else {
                printf("\n? Array tetap:   ");
                print_array(data, n, j, j+1, 0);
                printf("\n");
            }
            
            // Delay untuk animasi (1 detik)
            Sleep(1000);  // Windows
            // usleep(1000000);  // Linux/Mac (1 detik)
            
            printf("\n");
        }
        
        // Tampilkan hasil setelah satu pass selesai
        printf("----------------------------------------------------------------\n");
        printf("? HASIL SETELAH PASS %d: ", i+1);
        print_array(data, n, -1, -1, 0);
        printf("\n");
        
        // Jika tidak ada pertukaran, sorting selesai
        if(!swapped) {
            printf("\n?? Tidak ada pertukaran pada pass ini. Sorting selesai!\n");
            break;
        }
        
        // Tampilkan elemen yang sudah diurutkan
        printf("\n?? Elemen yang sudah diurutkan: ");
        for(int k = n-1-i; k < n; k++) {
            printf("\033[1;32m%d\033[0m ", data[k]);
        }
        printf("\n");
        
        Sleep(1500);  // Delay sebelum pass berikutnya
    }
    
    // Tampilkan hasil akhir
    printf("\n----------------------------------------------------------------\n");
    printf("                        HASIL AKHIR                           \n");
    printf("----------------------------------------------------------------\n");
    
    printf("\n?? DATA TERURUT: ");
    print_array(data, n, -1, -1, 0);
    
    printf("\n\n?? STATISTIK SORTING:");
    printf("\n   • Total passes: %d", i+1);
    printf("\n   • Total iterasi: %d", total_iterations);
    printf("\n   • Kompleksitas waktu: O(n²)");
    printf("\n   • Status: \033[1;32mSELESAI\033[0m\n");
    
    printf("\n----------------------------------------------------------------\n");
}

void generate_random_array(int arr[], int n) {
    printf("Mengenerate %d angka acak...\n", n);
    for(int i = 0; i < n; i++) {
        arr[i] = rand() % 100 + 1;  // Angka 1-100
    }
}

void display_step_by_step() {
    printf("\n+-------------------------------------------------------------+\n");
    printf("¦                  PROSES BUBBLE SORT                         ¦\n");
    printf("+-------------------------------------------------------------¦\n");
    printf("¦ 1. Bandingkan dua elemen yang berdekatan                    ¦\n");
    printf("¦ 2. Jika elemen kiri > elemen kanan, tukar posisi            ¦\n");
    printf("¦ 3. Geser satu posisi ke kanan, ulangi langkah 1-2           ¦\n");
    printf("¦ 4. Setelah satu pass, elemen terbesar akan di posisi akhir  ¦\n");
    printf("¦ 5. Ulangi untuk sisa array (kecuali elemen yang terurut)    ¦\n");
    printf("+-------------------------------------------------------------+\n");
}

void soal1_improved() {
    srand(time(NULL));
    int n = 10;
    int data[10];
    
    printf("\n");
    printf("+--------------------------------------------------------------+\n");
    printf("¦                    1. BUBBLE SORT ANIMATION                  ¦\n");
    printf("+--------------------------------------------------------------+\n");
    
    // Tampilkan penjelasan proses
    display_step_by_step();
    
    // Generate data random
    generate_random_array(data, n);
    
    // Tampilkan data asli
    printf("\n?? DATA ASLI: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", data[i]);
    }
    printf("\n");
    
    // Tunggu sebelum mulai animasi
    printf("\nTekan Enter untuk memulai animasi...");
    getchar();
    
    // Buat salinan data untuk sorting
    int data_copy[10];
    for(int i = 0; i < n; i++) {
        data_copy[i] = data[i];
    }
    
    // Jalankan animasi bubble sort
    bubble_sort_animation(data_copy, n);
    
    // Tampilkan perbandingan sebelum dan sesudah
    printf("\n+--------------------------------------------------------------+\n");
    printf("¦                    PERBANDINGAN HASIL                       ¦\n");
    printf("¦--------------------------------------------------------------¦\n");
    printf("¦ SEBELUM: ", data[0]);
    for(int i = 0; i < n; i++) printf("%d ", data[i]);
    printf("\n¦ SESUDAH: ");
    for(int i = 0; i < n; i++) printf("%d ", data_copy[i]);
    printf("\n+--------------------------------------------------------------+\n");
}

int main() {
    soal1_improved();
    return 0;
}

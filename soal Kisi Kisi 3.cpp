#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>

void print_array_highlight(int arr[], int n, int left, int right, int mid) {
    printf("\nIndeks:   ");
    for(int i = 0; i < n; i++) {
        if(i == left) printf(" L ");
        else if(i == right) printf(" R ");
        else if(i == mid) printf(" M ");
        else printf("   ");
        printf("  ");
    }
    
    printf("\n          ");
    for(int i = 0; i < n; i++) {
        printf("[%2d] ", i);
    }
    
    printf("\nArray:    ");
    for(int i = 0; i < n; i++) {
        if(i == mid) printf("\033[1;32m");  // Hijau untuk mid
        else if(i >= left && i <= right) printf("\033[1;33m");  // Kuning untuk range
        else printf("\033[0m");
        
        printf("%3d  ", arr[i]);
        printf("\033[0m");
    }
    printf("\n");
}

void binary_search_animation(int arr[], int n, int target) {
    int left = 0, right = n - 1;
    int iterations = 0;
    int found = -1;
    
    system("cls");
    printf("\n-------------------------------------------------------\n");
    printf("                BINARY SEARCH ANIMATION                \n");
    printf("-------------------------------------------------------\n");
    
    printf("\n?? Data terurut: ");
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n?? Target pencarian: %d\n", target);
    printf("?? Jumlah data: %d\n", n);
    
    printf("\nLEGENDA: L=Left, R=Right, M=Mid\n");
    printf("-------------------------------------------------------\n");
    
    while(left <= right) {
        iterations++;
        int mid = left + (right - left) / 2;
        
        printf("\n+-----------------------------------------------------+\n");
        printf("¦                ITERASI %2d                         ¦\n", iterations);
        printf("+-----------------------------------------------------¦\n");
        
        printf("¦ Range pencarian: indeks [%d..%d]                    ¦\n", left, right);
        printf("¦ Nilai range: [%d..%d]                              ¦\n", arr[left], arr[right]);
        printf("¦ Mid = %d + (%d - %d) / 2 = %d                      ¦\n", left, right, left, mid);
        printf("¦ Nilai mid = arr[%d] = %d                          ¦\n", mid, arr[mid]);
        printf("+-----------------------------------------------------+\n");
        
        print_array_highlight(arr, n, left, right, mid);
        
        printf("\n?? Membandingkan: arr[%d] = %d dengan target = %d\n", mid, arr[mid], target);
        
        Sleep(1500);
        
        if(arr[mid] == target) {
            printf("\n?? ? arr[%d] == %d ? DATA DITEMUKAN!\n", mid, target);
            found = mid;
            break;
        } else if(arr[mid] < target) {
            printf("\n?? %d < %d ? target ada di SEBELAH KANAN\n", arr[mid], target);
            printf("   Left = mid + 1 = %d + 1 = %d\n", mid, mid + 1);
            left = mid + 1;
        } else {
            printf("\n?? %d > %d ? target ada di SEBELAH KIRI\n", arr[mid], target);
            printf("   Right = mid - 1 = %d - 1 = %d\n", mid, mid - 1);
            right = mid - 1;
        }
        
        printf("\nTekan Enter untuk iterasi berikutnya...");
        getchar();
        getchar();
    }
    
    printf("\n-------------------------------------------------------\n");
    printf("                    HASIL PENCARIAN                   \n");
    printf("-------------------------------------------------------\n");
    
    if(found != -1) {
        printf("\n? SUKSES: Data %d ditemukan!\n", target);
        printf("   • Posisi: indeks %d\n", found);
        printf("   • Nilai: %d\n", arr[found]);
    } else {
        printf("\n? GAGAL: Data %d tidak ditemukan!\n", target);
        printf("   • Data tidak ada dalam array\n");
    }
    
    printf("\n?? STATISTIK:\n");
    printf("   • Total iterasi: %d\n", iterations);
    printf("   • Kompleksitas: O(log n)\n");
    printf("   • Worst case: %d iterasi\n", (int)(log(n)/log(2)) + 1);
    
    printf("\nTekan Enter untuk melanjutkan...");
    getchar();
}

void bubble_sort(int arr[], int n) {
    for(int i = 0; i < n-1; i++) {
        for(int j = 0; j < n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void generate_random_array(int arr[], int n) {
    printf("\n?? Generating %d random numbers (10-99)...\n", n);
    for(int i = 0; i < n; i++) {
        arr[i] = rand() % 90 + 10;
    }
    
    printf("Data sebelum sorting: ");
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    
    bubble_sort(arr, n);
    
    printf("\nData setelah sorting: ");
    for(int i = 0; i < n; i++) printf("%d ", arr[i]);
    printf("\n");
}

void manual_input_array(int arr[], int n) {
    printf("\n?? Masukkan %d data (harus terurut ascending):\n", n);
    for(int i = 0; i < n; i++) {
        printf("Data[%d]: ", i);
        scanf("%d", &arr[i]);
    }
    
    // Cek apakah data sudah terurut
    int sorted = 1;
    for(int i = 1; i < n; i++) {
        if(arr[i] < arr[i-1]) {
            sorted = 0;
            break;
        }
    }
    
    if(!sorted) {
        printf("\n? Data belum terurut, melakukan sorting...\n");
        bubble_sort(arr, n);
        printf("Data setelah sorting: ");
        for(int i = 0; i < n; i++) printf("%d ", arr[i]);
        printf("\n");
    }
}

void soal3() {
    srand(time(NULL));
    int choice, n = 15;
    int data[15];
    int target;
    
    system("cls");
    printf("\n-------------------------------------------------------\n");
    printf("              BINARY SEARCH IMPLEMENTATION            \n");
    printf("-------------------------------------------------------\n");
    
    printf("\nPilih metode input data:\n");
    printf("1. Random data (otomatis)\n");
    printf("2. Manual input\n");
    printf("Pilihan: ");
    scanf("%d", &choice);
    
    if(choice == 1) {
        generate_random_array(data, n);
        target = data[rand() % n];  // Pilih target yang pasti ada
        printf("\n?? Target pencarian (dipilih random dari data): %d\n", target);
    } else {
        manual_input_array(data, n);
        printf("\nMasukkan target pencarian: ");
        scanf("%d", &target);
    }
    
    printf("\nTekan Enter untuk memulai animasi binary search...");
    getchar();
    getchar();
    
    binary_search_animation(data, n, target);
}

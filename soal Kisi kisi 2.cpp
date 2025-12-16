#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

typedef struct {
    Node* head;
    Node* tail;
    int size;
} CircularList;

// Prototipe fungsi
CircularList* create_list();
void insert(CircularList* list, int data, int position);
void delete(CircularList* list, int data);
void search(CircularList* list, int data);
void traverse(CircularList* list);
void free_list(CircularList* list);
void display_menu();
void animate_insert();
void animate_delete();

CircularList* create_list() {
    CircularList* list = (CircularList*)malloc(sizeof(CircularList));
    list->head = NULL;
    list->tail = NULL;
    list->size = 0;
    return list;
}

void print_node_address(Node* node) {
    if(node) printf("%p", (void*)node);
    else printf("NULL");
}

void traverse(CircularList* list) {
    printf("\n+---------------------------------------------------------+\n");
    printf("¦                    TRAVERSE LIST                       ¦\n");
    printf("+---------------------------------------------------------¦\n");
    
    if(list->head == NULL) {
        printf("¦  List: [KOSONG]                                         ¦\n");
        printf("¦  Head: NULL, Tail: NULL, Size: 0                       ¦\n");
    } else {
        Node* current = list->head;
        printf("¦  List: [");
        
        do {
            printf("%d", current->data);
            current = current->next;
            if(current != list->head) printf(" ? ");
        } while(current != list->head);
        
        printf("] (Circular)\n");
        
        printf("¦  Head: %d (addr: ", list->head->data);
        print_node_address(list->head);
        printf(")\n");
        
        printf("¦  Tail: %d (addr: ", list->tail->data);
        print_node_address(list->tail);
        printf(")\n");
        
        printf("¦  Tail?next: %d (addr: ", list->tail->next->data);
        print_node_address(list->tail->next);
        printf(")\n");
        
        printf("¦  Size: %d                                              ¦\n", list->size);
    }
    printf("+---------------------------------------------------------+\n\n");
}

void insert(CircularList* list, int data, int position) {
    system("cls");
    printf("\n-------------------------------------------------------\n");
    printf("                    INSERT OPERATION                    \n");
    printf("-------------------------------------------------------\n");
    
    Node* new_node = (Node*)malloc(sizeof(Node));
    new_node->data = data;
    new_node->next = NULL;
    
    printf("\nMembuat node baru:\n");
    printf("  Data: %d\n", data);
    printf("  Address: %p\n", (void*)new_node);
    printf("\nStatus sebelum insert:\n");
    traverse(list);
    
    Sleep(1000);
    
    if(list->head == NULL) {
        printf("\n[KASUS 1: List kosong]\n");
        list->head = new_node;
        list->tail = new_node;
        new_node->next = new_node;
        printf("? Head dan tail menunjuk ke node baru\n");
        printf("? Node->next menunjuk ke diri sendiri (circular)\n");
    } else if(position == 1) {
        printf("\n[KASUS 2: Insert di awal]\n");
        new_node->next = list->head;
        list->head = new_node;
        list->tail->next = new_node;
        printf("? Node baru->next menunjuk ke head lama\n");
        printf("? Tail->next menunjuk ke node baru\n");
        printf("? Head menunjuk ke node baru\n");
    } else if(position == list->size + 1 || position == 0) {
        printf("\n[KASUS 3: Insert di akhir]\n");
        new_node->next = list->head;
        list->tail->next = new_node;
        list->tail = new_node;
        printf("? Node baru->next menunjuk ke head\n");
        printf("? Tail lama->next menunjuk ke node baru\n");
        printf("? Tail menunjuk ke node baru\n");
    } else {
        printf("\n[KASUS 4: Insert di posisi %d]\n", position);
        Node* current = list->head;
        for(int i = 1; i < position - 1; i++) {
            current = current->next;
        }
        new_node->next = current->next;
        current->next = new_node;
        printf("? Node di posisi %d->next menunjuk ke node baru\n", position-1);
        printf("? Node baru->next menunjuk ke node di posisi %d\n", position+1);
    }
    
    list->size++;
    
    Sleep(1000);
    printf("\nStatus setelah insert:\n");
    traverse(list);
    printf("? Insert berhasil! Data %d telah ditambahkan.\n", data);
    Sleep(1500);
}

void delete(CircularList* list, int data) {
    system("cls");
    printf("\n-------------------------------------------------------\n");
    printf("                    DELETE OPERATION                    \n");
    printf("-------------------------------------------------------\n");
    
    printf("\nMencari data %d untuk dihapus...\n", data);
    printf("\nStatus sebelum delete:\n");
    traverse(list);
    
    Sleep(1000);
    
    if(list->head == NULL) {
        printf("\n? DELETE GAGAL: List kosong!\n");
        Sleep(1500);
        return;
    }
    
    Node* current = list->head;
    Node* prev = list->tail;
    int found = 0;
    int position = 1;
    
    do {
        if(current->data == data) {
            found = 1;
            break;
        }
        prev = current;
        current = current->next;
        position++;
    } while(current != list->head);
    
    if(!found) {
        printf("\n? DELETE GAGAL: Data %d tidak ditemukan!\n", data);
        Sleep(1500);
        return;
    }
    
    printf("\nData %d ditemukan di posisi %d\n", data, position);
    printf("Address node: %p\n", (void*)current);
    
    Sleep(1000);
    
    if(current == list->head && list->size == 1) {
        printf("\n[KASUS 1: Hapus satu-satunya node]\n");
        list->head = NULL;
        list->tail = NULL;
        printf("? Head dan tail di-set NULL\n");
    } else if(current == list->head) {
        printf("\n[KASUS 2: Hapus node di awal]\n");
        list->head = current->next;
        list->tail->next = list->head;
        printf("? Head menunjuk ke node berikutnya\n");
        printf("? Tail->next menunjuk ke head baru\n");
    } else if(current == list->tail) {
        printf("\n[KASUS 3: Hapus node di akhir]\n");
        prev->next = list->head;
        list->tail = prev;
        printf("? Node sebelum tail menunjuk ke head\n");
        printf("? Tail menunjuk ke node sebelumnya\n");
    } else {
        printf("\n[KASUS 4: Hapus node di tengah (posisi %d)]\n", position);
        prev->next = current->next;
        printf("? Node sebelumnya menunjuk ke node setelahnya\n");
    }
    
    free(current);
    list->size--;
    
    Sleep(1000);
    printf("\nStatus setelah delete:\n");
    traverse(list);
    printf("? Delete berhasil! Data %d telah dihapus.\n", data);
    Sleep(1500);
}

void search(CircularList* list, int data) {
    system("cls");
    printf("\n-------------------------------------------------------\n");
    printf("                    SEARCH OPERATION                   \n");
    printf("-------------------------------------------------------\n");
    
    printf("\nMencari data %d...\n", data);
    printf("\nStatus list saat ini:\n");
    traverse(list);
    
    if(list->head == NULL) {
        printf("? PENCARIAN GAGAL: List kosong!\n");
        Sleep(1500);
        return;
    }
    
    Node* current = list->head;
    int position = 1;
    int found = 0;
    
    printf("\nProses pencarian:\n");
    printf("+-----------------------------------------------+\n");
    printf("¦ Iterasi ¦  Data   ¦   Address    ¦   Status   ¦\n");
    printf("+---------+---------+--------------+------------¦\n");
    
    do {
        printf("¦   %2d    ¦   %3d   ¦  %p  ", position, current->data, (void*)current);
        
        if(current->data == data) {
            printf("¦  ? DITEMUKAN ¦\n");
            found = 1;
            break;
        } else {
            printf("¦     ?       ¦\n");
        }
        
        current = current->next;
        position++;
    } while(current != list->head);
    
    printf("+-----------------------------------------------+\n");
    
    if(found) {
        printf("\n? DATA DITEMUKAN!\n");
        printf("   • Data: %d\n", data);
        printf("   • Posisi: %d\n", position);
        printf("   • Address: %p\n", (void*)current);
    } else {
        printf("\n? DATA TIDAK DITEMUKAN!\n");
    }
    
    printf("\nTekan Enter untuk melanjutkan...");
    getchar();
    getchar();
}

void display_menu() {
    printf("\n+---------------------------------------------------+\n");
    printf("¦      CIRCULAR SINGLE LINKED LIST OPERATIONS      ¦\n");
    printf("¦---------------------------------------------------¦\n");
    printf("¦  1. Insert di awal                               ¦\n");
    printf("¦  2. Insert di akhir                              ¦\n");
    printf("¦  3. Insert di posisi tertentu                    ¦\n");
    printf("¦  4. Delete data                                  ¦\n");
    printf("¦  5. Search data                                  ¦\n");
    printf("¦  6. Traverse (Tampilkan list)                    ¦\n");
    printf("¦  7. Demo otomatis                                ¦\n");
    printf("¦  0. Keluar                                       ¦\n");
    printf("+---------------------------------------------------+\n");
    printf("Pilihan: ");
}

void demo_otomatis(CircularList* list) {
    system("cls");
    printf("\n-------------------------------------------------------\n");
    printf("                    DEMO OTOMATIS                      \n");
    printf("-------------------------------------------------------\n");
    
    printf("\n?? DEMO 1: Insert 5 data otomatis\n");
    Sleep(1000);
    
    insert(list, 10, 0);  // Insert di akhir
    insert(list, 20, 0);  // Insert di akhir
    insert(list, 5, 1);   // Insert di awal
    insert(list, 15, 3);  // Insert di posisi 3
    insert(list, 25, 0);  // Insert di akhir
    
    printf("\n?? DEMO 2: Delete data\n");
    Sleep(1000);
    delete(list, 15);     // Delete data tengah
    delete(list, 5);      // Delete data awal
    delete(list, 25);     // Delete data akhir
    
    printf("\n?? DEMO 3: Search data\n");
    Sleep(1000);
    search(list, 10);
    search(list, 99);     // Data tidak ada
    
    printf("\n?? DEMO SELESAI!\n");
    Sleep(2000);
}

void soal2() {
    CircularList* list = create_list();
    int choice, data, position;
    
    system("cls");
    printf("\n-------------------------------------------------------\n");
    printf("        CIRCULAR SINGLE LINKED LIST IMPLEMENTATION     \n");
    printf("-------------------------------------------------------\n");
    
    do {
        display_menu();
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Masukkan data: ");
                scanf("%d", &data);
                insert(list, data, 1);
                break;
                
            case 2:
                printf("Masukkan data: ");
                scanf("%d", &data);
                insert(list, data, 0);
                break;
                
            case 3:
                printf("Masukkan data: ");
                scanf("%d", &data);
                printf("Masukkan posisi (1-%d): ", list->size + 1);
                scanf("%d", &position);
                if(position < 1 || position > list->size + 1) {
                    printf("? Posisi tidak valid!\n");
                    Sleep(1000);
                } else {
                    insert(list, data, position);
                }
                break;
                
            case 4:
                if(list->size == 0) {
                    printf("? List kosong, tidak ada data untuk dihapus!\n");
                    Sleep(1000);
                } else {
                    printf("Masukkan data yang akan dihapus: ");
                    scanf("%d", &data);
                    delete(list, data);
                }
                break;
                
            case 5:
                if(list->size == 0) {
                    printf("? List kosong, tidak ada data untuk dicari!\n");
                    Sleep(1000);
                } else {
                    printf("Masukkan data yang dicari: ");
                    scanf("%d", &data);
                    search(list, data);
                }
                break;
                
            case 6:
                system("cls");
                traverse(list);
                printf("Tekan Enter untuk melanjutkan...");
                getchar();
                getchar();
                break;
                
            case 7:
                demo_otomatis(list);
                break;
                
            case 0:
                printf("\nKeluar dari program...\n");
                break;
                
            default:
                printf("? Pilihan tidak valid!\n");
                Sleep(1000);
        }
        
    } while(choice != 0);
    
    free_list(list);
}

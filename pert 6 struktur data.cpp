//Nama: Farsya Haikal Lesmana
//Nim: 241011401494
//Tugas: Linear Queue

#include <iostream>
using namespace std;

#define MAX 5

class Queue {
private:
    int front, rear;
    int ele[MAX];
    
public:
    Queue() {
        front = 0;
        rear = -1;
    }
    
    bool isFull();
    bool isEmpty();
    void enqueue(int item);  
    bool dequeue(int &item); 
    void display();
    int getFront();
    int getRear();
    int getSize();
};

bool Queue::isFull() {
    return (rear == MAX - 1);
}

bool Queue::isEmpty() {
    return (front > rear || rear == -1);
}

void Queue::enqueue(int item) {
    if (isFull()) {
        cout << "? Queue Overflow! Tidak bisa menambah " << item << endl;
        return;
    }
    
    ele[++rear] = item;
    cout << "? Berhasil menambah: " << item << endl;
}

bool Queue::dequeue(int &item) {
    if (isEmpty()) {
        cout << "? Queue Underflow! Queue kosong" << endl;
        return false;
    }
    
    item = ele[front++];
    
    
    if (front > rear) {
        front = 0;
        rear = -1;
    }
    
    return true;
}

void Queue::display() {
    if (isEmpty()) {
        cout << "?? Queue kosong" << endl;
        return;
    }
    
    cout << "?? Isi Queue [";
    for (int i = front; i <= rear; i++) {
        cout << ele[i];
        if (i < rear) cout << ", ";
    }
    cout << "]" << endl;
}

int Queue::getFront() {
    if (isEmpty()) {
        return -1;
    }
    return ele[front];
}

int Queue::getRear() {
    if (isEmpty()) {
        return -1;
    }
    return ele[rear];
}

int Queue::getSize() {
    if (isEmpty()) return 0;
    return (rear - front + 1);
}

int main() {
    Queue q;
    int item;
    
    cout << "?? PROGRAM QUEUE IMPLEMENTASI ARRAY" << endl;
    cout << "===================================" << endl;
    
    cout << "\n1. TEST PENAMBAHAN ELEMEN:" << endl;
    cout << "--------------------------" << endl;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60); 
    
    q.display();
    cout << "Front: " << q.getFront() << ", Rear: " << q.getRear() 
         << ", Size: " << q.getSize() << endl;
    
    cout << "\n2. TEST PENGHAPUSAN ELEMEN:" << endl;
    cout << "---------------------------" << endl;
    
    if (q.dequeue(item)) {
        cout << "? Berhasil menghapus: " << item << endl;
    }
    
    if (q.dequeue(item)) {
        cout << "? Berhasil menghapus: " << item << endl;
    }
    
    q.display();
    cout << "Front: " << q.getFront() << ", Rear: " << q.getRear() 
         << ", Size: " << q.getSize() << endl;
    
    cout << "\n3. TEST PENAMBAHAN SETELAH PENGHAPUSAN:" << endl;
    cout << "--------------------------------------" << endl;
    q.enqueue(60);
    q.enqueue(70); 
    
    q.display();
    
    cout << "\n4. TEST MENGHAPUS SEMUA ELEMEN:" << endl;
    cout << "------------------------------" << endl;
    int count = 0;
    while (q.dequeue(item)) {
        cout << "Hapus " << ++count << ": " << item << endl;
    }
    
    q.display();
    
    cout << "\n5. TEST OPERASI PADA QUEUE KOSONG:" << endl;
    cout << "---------------------------------" << endl;
    q.dequeue(item); 
    cout << "Front: " << q.getFront() << " (harusnya -1)" << endl;
    cout << "Size: " << q.getSize() << " (harusnya 0)" << endl;
    
    return 0;
}

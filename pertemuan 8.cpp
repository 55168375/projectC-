//Nama:Farsya Haikal lesmana
//Nim:241011401494
//Pertemuan 8 DOUBLE ENDED QUEUE

#include <iostream> 
using namespace std; 
#define MAX 5 
  
class DQueue 
{ 
    private: 
        int front   ; 
        int rear    ; 
        int count   ; 
        int ele[MAX];  
		public: 
        DQueue(); 
        int  isFull(); 
        int  isEmpty(); 
        void insertDQueueAtRear(int item); 
        int  deleteDQueueAtFont(int *item); 
        void insertDQueueAtFront(int item); 
        int  deleteDQueueAtRear(int *item); 
}; 
  
DQueue:: DQueue() 
{ 
    front =  0; 
    rear  = -1; 
    count =  0;  
} 
  
int DQueue:: isFull() 
{ 
    int full=0; 
  
    if( count == MAX ) 
        full = 1; 
  
    return full;     
} 
  
int DQueue:: isEmpty() 
{ 
    int empty=0; 
  
    if( count == 0 ) 
        empty = 1; 
  
    return empty;    
} 
  
void DQueue:: insertDQueueAtRear(int item) 
{ 
    if( isFull() ) 
  { 
        cout<<"\nQueue Overflow"; 
        return; 
    } 
  
    rear= (rear+1) % MAX; 
  
    ele[rear] = item; 
    count++; 
      
    cout<<"\nDimasukkan di Belakang FRONT : "<< front<<", REAR : "<< rear; 
    cout<<"\nItem dimasukkan : "<< item << endl; 
} 
   
int DQueue:: deleteDQueueAtFont(int *item) 
{ 
    if( isEmpty() ) 
    { 
        cout<<"\nQueue Underflow"; 
        return -1; 
    } 
    *item = ele[front]; 
    front = (front+1) % MAX; 
      
    cout<<"\nSetelah Hapus Di Depan FRONT : "<< front<<", REAR : "<< rear; 
    count--; 
    return 0; 
} 
  
void DQueue:: insertDQueueAtFront(int item) 
{ 
    if( isFull() ) 
    { 
        cout<<"\nQueue Overflow"; 
        return; 
    } 
      
    if ( front == 0) 
        front = MAX - 1; 
    else 
        front = front - 1;
		ele[front] = item; 
		 count++; 
    cout<<"\nSetelah Sisipkan Di Depan FRONT :"<< front<<", REAR : "<< rear; 
    cout<<"\nItem yang disisipkan : "<< item<< endl; 
} 
  
int DQueue:: deleteDQueueAtRear(int *item) 
{ 
    if( isEmpty() ) 
    { 
        cout<<"\nQueue Underflow"; 
        return -1; 
    } 
  
    *item = ele[rear]; 
  
    if(rear == 0) 
        rear = MAX - 1; 
    else 
        rear = rear - 1; 
  
    cout<<"\nSetelah Hapus Dibelakang FRONT : "<< front<<", REAR : "<< rear; 
    count--;     
    return 0; 
} 
  
int main() 
{ 
    int  item; 
    DQueue q = DQueue(); 
  
    q.insertDQueueAtRear(10); 
    q.insertDQueueAtRear(20); 
    q.insertDQueueAtRear(30); 
    q.insertDQueueAtFront(40); 
    q.insertDQueueAtFront(50); 
    q.insertDQueueAtFront(60); 
  
    if( q.deleteDQueueAtFont(&item) == 0 ) 
    { 
        cout<<"\nItem dihapus:"<< item<< endl; 
    } 
  
    if( q.deleteDQueueAtFont(&item) == 0 ) 
    {
	 cout<<"\nItem dihapus:"<< item<< endl; 
    } 
  
    if( q.deleteDQueueAtFont(&item) == 0 ) 
    { 
        cout<<"\nItem dihapus:"<< item<< endl; 
    } 
  
    if( q.deleteDQueueAtRear(&item) == 0 ) 
    { 
        cout<<"\nItem dihapus:"<< item<< endl; 
    } 
  
    if( q.deleteDQueueAtRear(&item) == 0 ) 
    { 
        cout<<"\nItem dihapus:"<< item<< endl; 
    } 
      
    if( q.deleteDQueueAtRear(&item) == 0 ) 
    { 
        cout<<"\nItem dihapus:"<< item<< endl; 
    } 
    cout<<"\n"; 
    return 0; 
};

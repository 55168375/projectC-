//Nama:Farsya Haikal Lesmana
//Kelas:03TPLP023
//Tugas:Latihan pert 4

#include <iostream>
using namespace std;

#define MAX 1000

class Stack {
	int top;
	
public:
	int a[MAX];
	
	Stack(){
		top = -1;
	}
	
	bool push(int x);
	int pop();
	int peek();
	bool isEmpty();
};

bool Stack::push(int x){
	if (top >=(MAX - 1)){
		cout<<"Stack Overflow";
		return false;
	}else{
		a[++top]=x;
		cout<<x<<"disorong ke dalam tumpukan\n";
		return true;
	}
}

int Stack::pop(){
	if (top<0){
		cout<<"Stack Underflow";
		return 0;
	}
}

int Stack::peek(){
	if (top<0){
		cout<<"Tumpukan Kosong";
		return 0;
	}else{
		int x = a[top];
		return x;
	}
}

bool Stack::isEmpty(){
	return(top<0);
}

int main(){
	Stack s;
	s.push(10);
	s.push(20);
	s.push(30);
	cout<<s.pop()<<"Dikeluarkan dari tumpukan\n";
	
	cout<<"Elemen teratas:"<<s.peek()<<endl;
	
	if(s.isEmpty()){
		cout<<"Stack kosong"<<endl;
	}else{
		cout<<"Stack tidak kosong"<<endl;
	}
	
	return 0;
}

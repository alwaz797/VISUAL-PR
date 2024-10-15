#include<iostream>
using namespace std;

int main(){
	
	int a;
	
	cout<<"enter the value of pointer ";
	cin>>a;
	
	int *b;
	
    b = &a ;
    
	cout<<"the value is = "<<*b<<endl;
	
	cout<<"address of pointer is "<<&b;
	
}



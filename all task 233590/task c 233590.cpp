#include<iostream>
using namespace std;

int main(){
	
	int a;
	int b;
	
	cout<<"enter the value of pointer 1"<<endl;
	cin>>a;
	
	cout<<"enter the value of pointer 2"<<endl;
	cin>>b;
	
	
	int *ptrx;
	int *ptry;
	
    ptrx = &a ;
    ptry = &b ;
    
	cout<<"the value of ptr x  = "<<*ptrx<<endl;
    cout<<"value of ptr y = "<<*ptry<<endl;


}

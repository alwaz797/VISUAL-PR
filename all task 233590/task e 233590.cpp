#include<iostream>
using namespace std;
int main(){
	int size=7;
	 
	int *array;
	array =new int [size];
	for(int i=0;i<7;i++){
		cout<<"enter value at index  "<<i+1<<" : ";
		cin>>array[i];
		
	}
	cout<<endl<<endl<<endl;
		for(int i=0;i<7;i++){
		cout<<" value at index  "<<i+1<<" is "<<array[i]<<endl;
	
}
}


#include <iostream>
using namespace std;


int main(){
	
	int num1;
	int num2;
	int sum;
	
	cout<<"enter value num 1: "<<endl;
	cin>>num1;
	cout<<"enter value of num 2: "<<endl;
	cin>>num2;
	
	int *ptr1;
	int *ptr2;
	
	ptr1=&num1;
	ptr2=&num2;
    sum = (*ptr1)+(*ptr2);
	
	cout<<"sum of two numbers is = "<<endl<<sum;
	
}



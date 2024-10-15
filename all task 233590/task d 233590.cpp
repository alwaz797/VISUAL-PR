#include <iostream>

using namespace std;

void findMinMax(int* a, int* b, int* c, int** min, int** max) {
   
    *min = a;
    *max = a;

 
    if (*b < **min) {
        *min = b;
    }
    if (*c < **min) {
        *min = c;
    }
   if (*b > **max) {
        *max = b;
    }
    if (*c > **max) {
        *max = c;
    }
}

int main() {
    int num1, num2, num3;
    int* minPtr;
    int* maxPtr;

    cout << "Enter three numbers: ";
    cin >> num1 >> num2 >> num3;


    findMinMax(&num1, &num2, &num3, &minPtr, &maxPtr);

    cout << "The smallest number is: " << *minPtr << endl;
    cout << "The greatest number is: " << *maxPtr << endl;

    return 0;
}


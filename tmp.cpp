#include <iostream>
#include <cmath>
using namespace std;

bool * int_to_binary(int n) {
    bool *a = new bool [16];
    for (int i = 15; i>=0; i--) {
        int bit = n >> i;
        if (bit & 1) a[15-i] = 1;
        else a[15-i] = 0;
    }
    return a;
}


bool *int_to_binary1(int n) {
    bool *a = new bool [32];
    for (int i = 31; i>= 0; i--) {
       int bit = n >> i;
       if (bit & 1) a[31-i] = 1;
       else a[31-i] = 0;
    }
    return a;
}

int binary_to_int (bool *a, int size) {
    int num = 0, k = 0;
    for (int i = size; i>=1; i--) {
        num = num + a[i]*pow(2, k);
        k++;
    }
    if (a[0] == 0) return num;
    else if (a[0] == 1) return num - pow(2, size);
}

bool * float_to_binary(float n) {
    int *p = (int*) &n;
    bool *kq;
    kq = int_to_binary1(*p);
    return kq;
}

float binary_to_float(bool *a) {
    int x = 0;
    x = binary_to_int(a, 31);
    float *p = (float *) &x;
    return *p;
}

void printBina (bool *a) {
    for (int i = 0; i<16; i++) cout << a[i];
    cout << endl;
}

void printBina1(bool *a) {
    for (int i = 0; i<32; i++) cout << a[i];
    cout << endl;
}

int main() {
    bool *arr;
    int n;
    cout << "integer: ";
    cin >> n;
    arr = int_to_binary(n);
    cout << "binary: ";
    printBina(arr);
    cout << endl;
    cout << "binary to int: " << binary_to_int(arr, 15);
    cout << endl;
    delete []arr;


    bool *a;
    float x;
    cout << "float: ";
    cin >> x;
    a = float_to_binary(x);
    cout << "binary: ";
    printBina1(a);
    cout << endl;
    cout << "binary to float: " << binary_to_float(a);
    cout << endl;
    delete []a;
    return 0;

}
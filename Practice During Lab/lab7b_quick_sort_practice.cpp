#include <bits/stdc++.h>
using namespace std;

int partition(int arr[], int low, int high) {
    int piv = arr[high];
    // cout << piv << endl;
    int i = low;

    for (int j=low; j<high; j++) { 
        if (arr[j] <= piv) { 
            swap(arr[i], arr[j]); 
            i++; 
        }
    }
    swap(arr[i], arr[high]);

    return i-1;
}


void quick_sort(int arr[], int low, int high) {
    if (low < high) { 
        int mid = partition(arr, low, high); 
        quick_sort(arr, low, mid-1); 
        quick_sort(arr, mid+1, high); 
    } 
} 


int main() {
    int arr[] = {8, 7, 6, 1, 0, 9, 2};
    int len = sizeof(arr)/sizeof(int);

    quick_sort(arr, 0, len-1); 
    
    for (int i=0; i<len; i++) {
        cout << arr[i] << endl;
    }

    return 0;
}


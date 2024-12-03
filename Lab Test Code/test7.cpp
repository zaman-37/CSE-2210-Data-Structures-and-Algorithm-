#include <bits/stdc++.h>
using namespace std;

int partition(int &v, int low, int high) {
    int p = v[high];
    int i = low;
    for (int j=0; i<high; j++) {
        if (v[j] <= p) {
            swap(v[i], v[j]);
            i++;
        }
    }
    swap(v[high], v[i]);
    return i-1;
}

int main() {
    vector<int> v = {7, 4, 5, 2, 8, 9, 0, 1, 3};

    

    return 0;
}
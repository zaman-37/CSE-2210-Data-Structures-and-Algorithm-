#include <bits/stdc++.h>
using namespace std;


class Quick_sort{
    private: 
    int partition(vector<string> &bk, int low, int high) {
        string pivot = bk[high];
        int i = low;
        for (int j=low; j<=high-1; j++) {
            if (bk[j] <= pivot) {
                swap(bk[i], bk[j]);
                i++;
            }
        }
        swap(bk[i], bk[high]);
        return i;
    }

    public: 
    void sort(vector<string> &b, int low, int high) {
        if (low > high) {
            return;
        }
        int p = partition(b, low, high);
        sort(b, low, p-1);
        sort(b, p+1, high);
    } 
};


int main() {
    vector<string>s;
    for (int i=0; i<5; i++) {
        string str;
        cin >> str;
        s.push_back(str);
    }

    Quick_sort qs;
    qs.sort(s, 0, s.size()-1);
    for (auto u: s) {
        cout <<  u << endl;
    }
    

    return 0;
}
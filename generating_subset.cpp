#include <bits/stdc++.h>
using namespace std;

vector<int> v;

void search(int k, int n){
    if (k == n){
        for(int i: v) cout << i << " ";
        cout << endl;
        return;
    }
    search(k+1, n);
    v.push_back(k);
    search(k+1, n);
    v.pop_back();
}

int main(void){
    int n;
    cin >> n;
    search(1, n);
}
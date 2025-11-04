#include <bits/stdc++.h>
using namespace std;

int main(void){
    // vector<string> v = {"hello", "world", "hello hello"};

    // vector<string>::iterator it;

    // for(auto it = v.begin(); it != v.end();it++){
    //     cout << *it << endl;
    // }

    vector<int> a = {1, 2, 3, 4, 5};

    auto it = max_element(a.begin(), a.end());
    auto b = min_element(a.begin(), a.end());
    cout << *it << " " << *b << endl;
}
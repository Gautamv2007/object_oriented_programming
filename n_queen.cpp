#include <bits/stdc++.h>
using namespace std;

int n;                  // board size
int countSolutions = 0; // number of valid solutions
vector<int> column, diag1, diag2;

void search(int y) {
    if (y == n) {
        countSolutions++;  // found one valid arrangement
        return;
    }
    for (int x = 0; x < n; x++) {
        if (column[x] || diag1[x+y] || diag2[x-y+n-1]) continue;
        // place queen
        column[x] = diag1[x+y] = diag2[x-y+n-1] = 1;
        search(y+1);
        // backtrack
        column[x] = diag1[x+y] = diag2[x-y+n-1] = 0;
    }
}

int main() {
    cin >> n;
    column.assign(n, 0);
    diag1.assign(2*n - 1, 0);
    diag2.assign(2*n - 1, 0);

    search(0);
    cout << "Number of solutions for " << n << "-Queens: " 
         << countSolutions << endl;

    return 0;
}

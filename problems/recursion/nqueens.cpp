#include <iostream>
using namespace std;

int n;
bool* col;
bool* fdiag;
bool* bdiag;
int count = 0;

void dfs(int r) {
    if (r == n) {
        ++count;
        return;
    }

    for (int c = 0; c < n; ++c) {
        if (col[c] || fdiag[r + c] || bdiag[r - c + n - 1]) { continue; }
        col[c] = fdiag[r + c] = bdiag[r - c + n - 1] = true;
        dfs(r + 1);
        col[c] = fdiag[r + c] = bdiag[r - c + n - 1] = false;
    }
}

int main(int argc, char* argv[]) {
    n = atoi(argv[1]);
    col = new bool[n]{false};
    fdiag = new bool[2 * n - 1]{false};
    bdiag = new bool[2 * n - 1]{false};

    dfs(0);
    cout << count << endl;

    delete[] col;
    delete[] fdiag;
    delete[] bdiag;
}

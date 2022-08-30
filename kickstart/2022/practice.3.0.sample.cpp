#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        int n, m, c = 0;
        cin >> n >> m;
        while (n--) {
            int ci;
            cin >> ci;
            c += ci;
        }
        cout << "Case #" << i << ": " << c % m << endl;
    }
}

#include <iostream>
using namespace std;

int main() {
        int t, n, x, c, d;
        cin >> t;
        while (t--) {
                cin >> n;
                if (n == 1) {
                        cin >> x;
                        cout << 0 << endl;
                        continue;
                }
                c = d = 0;
                while (n--) {
                        cin >> x;
                        ++d;
                        if (!x and !c)
                            c = d;
                        if (x)
                            c = 0;
                }
                cout << (x ? d - 1 : c - 2) << endl;
        }
}

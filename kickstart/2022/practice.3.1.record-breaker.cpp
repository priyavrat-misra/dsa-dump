#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        int n, ans = 0;
        cin >> n;
        int* a = new int[n];
        for (int v = 0; v < n; ++v)
            cin >> a[v];
        
        int max_so_far = -1;
        for (int v = 0; v < n; ++v) {
            if (max_so_far < a[v]) {
                max_so_far = a[v];
                if (v + 1 == n || a[v] > a[v+1])
                    ++ans;
            }
        }
        delete[] a;
        cout << "Case #" << i << ": " << ans << endl;
    }
}

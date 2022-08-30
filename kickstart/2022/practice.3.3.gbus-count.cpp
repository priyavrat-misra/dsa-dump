#include <iostream>
using namespace std;

int main() {
    int t;
    cin >> t;
    for (int i = 1; i <= t; ++i) {
        int cities[5001]{0};
        int n;
        cin >> n;
        while (n--) {
            int a, b;
            cin >> a >> b;
            ++cities[a-1];
            --cities[b];
        }
        for (int j = 1; j < 5000; ++j)
            cities[j] += cities[j-1];
        
        int p;
        cin >> p;
        cout << "Case #" << i << ":";
        while (p--) {
            int c;
            cin >> c;
            cout << " " << cities[c-1];
        }
        cout << endl;
    }
}

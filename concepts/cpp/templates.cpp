#include <iostream>

using namespace std;

template<class T>
T triple(T x) {
    return x + x + x;
}

int main(int argc, char* argv[]) {
    cout << triple(1) << '\n';
    cout << triple(2.3) << '\n';
    cout << triple(true) << '\n';
    cout << triple(string{"abc"}) << '\n';
}

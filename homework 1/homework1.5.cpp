#include <iostream>
using namespace std;
int main() {
    double a[5];
    cin >> a[0] >> a[1] >> a[2] >> a[3] >> a[4];
    sort(a, a+5);
    cout << a[0] + a[4];
}

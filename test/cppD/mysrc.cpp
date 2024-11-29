#include <bits/stdc++.h>
using namespace std;
/**
 * @Name 
 */
const int INF = 0x7f7f7f7f;
typedef long long lint;
typedef __int128 ll;
int extendedGCD(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    int x1, y1;
    int gcd = extendedGCD(b, a % b, x1, y1);
    x = y1;
    y = x1 - (a / b) * y1;
    return gcd;
}
int modularInverse(int a, int b) {
    int x, y;
    int gcd = extendedGCD(a, b, x, y);
    if (gcd != 1) {
        return -1;
    }
    x = (x % b + b) % b;
    return x;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int a, b;
    cin >> a >> b;
    int result = modularInverse(a, b);
    cout << result << endl;
    return 0;
}
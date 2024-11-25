#include <bits/stdc++.h>
using namespace std;
/**
 * @Name 扩展的欧几里得算法，使用递归计算最大公约数GCD
 * @Input 两个任意非负整数(lint a, lint b)
 * @Output 三个参数 d, x, y
 * @Math d = gcd(a,b) = a*x + b*y;
 * @Warning 在描述中为 a mod b 取模，但因为只有正数，实际使用 %(rem)
 *  取余操作，有负数时需要更改这个函数。
 *  -5 rem 3 = -2; -5 mod 3 = 1
 */
typedef long long lint;
void euclid(lint a, lint b, lint& d, lint& x, lint& y) {
    if(b == 0){
        d = a; x = 1; y = 0;
    }else{
        lint d1, x1, y1;
        euclid(b, a % b, d1, x1, y1);
        d = d1;
        x = y1;
        y = x1 - floor(a/b)*y1;
    }
}
// 单元测试
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    lint a, b;
    lint d,x,y;
    cin >> a >> b;
    euclid(a, b, d,x,y);
    cout << d <<","<< x<<","<< y<< endl;
    return 0; 
}
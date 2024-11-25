#include <bits/stdc++.h>
using namespace std;
/**
 * @Name 欧几里得算法，使用递归计算最大公约数GCD
 * @Input 两个任意非负整数(loa,b)
 * @Output 整数
 * @Warning 在描述中为 a mod b 取模，但因为只有正数，实际使用 %(rem)
 *  取余操作，有负数时需要更改这个函数。
 *  -5 rem 3 = -2; -5 mod 3 = 1
 */
typedef long long lint;
lint gcd(lint a, lint b) {
    if(b == 0){
        return a;
    }else{
        return gcd(b, a % b);
    }
}
// 单元测试
int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    lint a, b;
    cin >> a >> b;
    lint c = gcd(a, b);
    cout << c << endl;
    return 0; 
}
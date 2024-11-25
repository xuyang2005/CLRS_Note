#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
const int INF = 0x7f7f7f7f;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
    vector<lint> bp;
    vector<bool> b;
    cin >> n;
    for(int i = 0; i <= n; i++){
        bp.push_back(0);
        b.push_back(false);
    }
    int m;
    cin >> m;
    int l,r;
    cin >> l >> r;
    for(int i = 0; i < m; i++){
        int temp;
        cin >> temp;
        b[temp] = true;
    }

    bp[0] = 1;
    b[0] = true;
    b[n] = true;
    for(int i = 0; i < n; i++){
        int il = i + l;
        int ir = i + r;
        if(ir>n){
            ir = n;
        }
        for(int j = il; j <= ir; j++){
            if(b[j]){
                bp[j] += bp[i];
                if(bp[j] > 998244353){
                bp[j] %= 998244353;
                }
                //cout << "bp[" << j << "]=" << bp[j] << endl; 
            }
        }
    }
    int result = bp[n] % 998244353;
    cout << result << endl;
    return 0;}
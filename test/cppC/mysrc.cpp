/* 
 Author: 徐洋
 Result: TLE	Submission_id: 7023671
 Created at: Tue Nov 26 2024 10:50:28 GMT+0800 (China Standard Time)
 Problem_id: 8806	Time: 1120	Memory: 3844
*/

/* 
 Author: 徐洋
 Result: TLE	Submission_id: 7023364
 Created at: Tue Nov 26 2024 01:22:11 GMT+0800 (China Standard Time)
 Problem_id: 8806	Time: 1144	Memory: 4120
*/

#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
const int INF = 0x7f7f7f7f;

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n;
   
    cin >> n;
    vector<lint> bp(n+1,0);
    vector<bool> b(n+1,0);
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
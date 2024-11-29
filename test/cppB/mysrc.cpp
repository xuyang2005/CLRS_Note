#include <bits/stdc++.h>
using namespace std;
/**
 * @Name 
 */
const int INF = 0x7f7f7f7f;
typedef long long lint;
typedef __int128 ll;

vector<int> bitReverse(vector<int>& arr) {
    int n = arr.size();
    int logN = log2(n);
    vector<int> result(n);
    for (int i = 0; i < n; ++i) {
        int reversedIndex = 0;
        for (int j = 0; j < logN; ++j) {
            if (i & (1 << j)) {
                reversedIndex |= (1 << (logN - 1 - j));
            }
        }
        result[reversedIndex] = arr[i];
    }
    return result;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    vector<int> a;
    int n;
    cin >> n;
    for(int i = 0; i < n; i++){
        int temp;
        cin >> temp;
        a.push_back(temp);
    }
    vector<int> r = bitReverse(a);
    for(auto& ele : r){
        cout << ele << " ";
    }
    cout << endl;
return 0;}
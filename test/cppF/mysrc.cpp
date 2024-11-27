#include <bits/stdc++.h>
using namespace std;
typedef pair<__int128,__int128> point;
typedef __int128 lint;
void f(){
    vector<point> ss;
    long long n1;
    cin >> n1;
    lint n = n1;
    long long x1, y1;
    cin >> x1 >> y1;
    lint x = x1;
    lint y = y1;
    point findP{x,y};
    point zeroP{0,0};
    ss.push_back(zeroP);
    for(lint i = 0; i < n; i++){
        char temp;
        cin >> temp;
        if(temp == 'U') {
            zeroP.second += 1;
            
        ss.push_back(zeroP);
        } else if(temp == 'D') {
            zeroP.second -= 1;
            
        ss.push_back(zeroP);
        } else if(temp == 'L') {
            zeroP.first -= 1;
            
        ss.push_back(zeroP);
        } else if(temp == 'R') {
            zeroP.first += 1;
            
        ss.push_back(zeroP);
        } else {
            i--;
        }
    }

    lint result = -1;
    lint h = -1;
    lint hc = -1;

    point finalPos = ss[n];

    for(long long i = 0; i < n; i++){
        long long rx = finalPos.first;
        long long ry = finalPos.second;

        if(rx == 0 && ry == 0){
            if(ss[i] == findP){
                h = 0;
                hc = i;
                break;
            }
        } else if(rx == 0){
            if(x == ss[i].first && (y - ss[i].second) % ry == 0
            && ((y - ss[i].second) / ry)>0){
                lint hg = (y - ss[i].second) / ry;
                if(hg<0){
                    hg *= -1;
                }
                if(h == -1 || hg * n + i < h * n + hc){
                    h = hg;
                    hc = i;
                }
            }
        } else if(ry == 0){
            if(y == ss[i].second && (x - ss[i].first) % rx == 0
            && ((x - ss[i].first) / rx)>0){
                lint hg = (x - ss[i].first) / rx;
                if(hg<0){
                    hg *= -1;
                }
                if(h == -1 || hg * n + i < h * n + hc){
                    h = hg;
                    hc = i;
                }
            }
        } else{
            if((y - ss[i].second) % ry == 0 && (x - ss[i].first) % rx == 0){
                lint h1 = (y - ss[i].second) / ry;
                lint h2 = (x - ss[i].first) / rx;
                if(h1 == h2){
                    lint hg = h1;
                    if(hg<0){
                        hg *= -1;
                    }
                    if(h == -1 || hg * n + i < h * n + hc){
                        h = hg;
                        hc = i;
                    }
                }
            }
        }
    }

    if(h != -1){
        long long result = h * n + hc;
        cout << result << endl;
    } else {
        cout << "-1" << endl;
    }
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int T; cin >> T; 
    while (T--) {
        f();
    }
    return 0;
}
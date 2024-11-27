#include <bits/stdc++.h>
using namespace std;

const int INF = 0x7f7f7f7f;
typedef long long lint;
typedef pair<long long,long long> point;

void f(){
    //主函数
    vector<point> ss;
    lint n;
    cin >> n;
    lint x, y;
    cin >> x >> y;
    point findP{x,y};
    point zeroP{0,0};
    ss.push_back(zeroP);
    for(lint i = 0; i < n; i++){
        char temp;
        cin >> temp;
        if(temp=='U'){
            zeroP.second += 1;
        ss.push_back(zeroP);
        }else if(temp=='D'){
            zeroP.second -= 1;
        ss.push_back(zeroP);
        }else if(temp=='L'){
            zeroP.first -= 1;
        ss.push_back(zeroP);
        }else if(temp=='R'){
            zeroP.first += 1;
        ss.push_back(zeroP);
        }else{
            i--;
        }
    }
    lint rx = ss[n].first;
    lint ry = ss[n].second;
    // for(auto& ele : ss){
    //     cout << ele.first << "," << ele.second << endl;
    // }
    lint result = -1;
    lint h = -1;
    lint hc = -1;
    for(lint i = 0; i < n; i++){
        // cout << "rx=" << rx << " " << "ry=" << ry << endl;
        // cout << "ss[i].first=" << ss[i].first << endl;
        // cout << "ss[i].second=" << ss[i].second << endl;
        // cout << "x=" << x << " " << "y=" << y << endl;
        if(rx==0&&ry==0){
            if(ss[i]==findP){
                h = 0;
                hc = i;
                break;
            }
        }else if(rx==0){
            if(x==ss[i].first && (y - ss[i].second)%ry==0){
                lint hg = abs((y - ss[i].second)/ry);
                lint hcg = i;
                if(h==-1){
                    h = hg;
                    hc = hcg;
                }else if((hg*n+hcg)<(h*n+hc)){
                    h = hg;
                    hc = hcg;
                }
            }
        }else if(ry==0){
            if(y==ss[i].second && (x - ss[i].first)%rx==0){
                lint hg = abs((x - ss[i].first)/rx);
                lint hcg = i;
                if(h==-1){
                    h = hg;
                    hc = hcg;
                }else if((hg*n+hcg)<(h*n+hc)){
                    h = hg;
                    hc = hcg;
                }
            }
        }else{
            if((y - ss[i].second)%ry==0){
                if((x - ss[i].first)%rx==0){
                    lint h1 = (y - ss[i].second)/ry;
                    lint h2 = (x - ss[i].first)/rx;
                    // cout << "h1=" << h1 << endl;
                    // cout << "h2=" << h2 << endl;
                    if(h1==h2){
                        lint hg = abs((x - ss[i].first)/rx);
                        // cout << "hg=" << hg << endl;
                        lint hcg = i;
                        // cout << "hcg=" << hcg << endl;
                        if(h==-1){
                            h = hg;
                            hc = hcg;
                        }else if((hg*n+hcg)<(h*n+hc)){
                            h = hg;
                            hc = hcg;
                        }
                    }
                }
            }
        }
    }
    if(h!=-1){
        lint result = h * n + hc;
        cout << result << endl;
    }else{
        cout << "-1" << endl;
    }
}

int main() {
    //ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int T;cin >> T;for (int ii = 0; ii < T; ii++) {
        f();
    }
return 0;}

/**
 * 11/25/23:04
 * 
 */

#include <bits/stdc++.h>
using namespace std;
typedef long long lint;
const int INF = 0x7f7f7f7f;
vector<int> m1;
vector<int> m2;
vector<vector<int>> adjMatrix(lint vN, lint eN){
        //带权图填充INF
        vector<vector<int>> adm(vN, vector<int>(vN, INF));
        //主对角线设置为0
        for (lint i = 0; i < vN; ++i) {
            adm[i][i] = 0;
        }
        //每行读入三个数
        //无向则双重填充
            for (lint i = 0; i < eN; ++i) {
                lint a, b, c;
                cin >> a >> b >> c;
                m1.push_back(a);
                m2.push_back(b);
                if(adm[a-1][b-1]>c){
                    adm[a-1][b-1] = c;
                    adm[b-1][a-1] = c;
                }
                // adm[a-1][b-1] += c;
                // adm[b-1][a-1] += c;
            }
        return adm;
}

// 使用邻接矩阵实现Floyd-Warshall算法
vector<vector<int>> floydWarshallMatrix(const vector<vector<int>>& graph) {
    // 准备好初始化
    int V = graph.size();
    vector<vector<int>> dist = graph;
    // 算法主体
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    return dist;
}

int main() {
    ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    int vN,eN;
    int qN;
    cin >> vN >> eN >> qN;
    vector<vector<int>> matrix =  adjMatrix(vN,eN);
    //主函数
    vector<vector<int>> dir =  floydWarshallMatrix(matrix);
    // for(auto& row : dir){
    //     for(auto& ele : row){
    //         cout << ele << ", ";
    //     }
    //     cout << "\n";
    // }
    // for(auto & ele : m1){
    //     cout << ele << ", ";
    // }
    // cout << "\n";
    // for(auto & ele : m2){
    //     cout << ele << ", ";
    // }
    for(int i = 0; i < qN; i++){
        int s, t, k;
        cin >> s >> t >> k;
        s--;
        t--;
        k--;
        if((dir[s][m1[k]-1] + dir[m1[k]-1][m2[k]-1] + dir[m2[k]-1][t])==dir[s][t]){
            cout << "Yes" << "\n";
        }else if(((dir[s][m2[k]-1]+dir[m1[k]-1][m2[k]-1]+dir[m1[k]-1][t])==dir[s][t])){
            cout << "Yes" << "\n";
        }else{
            cout << "No" << "\n";
        }
    }
    cout << flush;
return 0;}
#include <bits/stdc++.h>
/**
 * @Date 2024/11/27 19:00
 */
using namespace std;
const int INF = 0x7f7f7f7f;
typedef long long lint;
typedef __int128 ll;

vector<vector<int>> adjMatrix(lint vN, lint eN, 
bool isQuan, bool isDirect){
    if(isQuan){
        //带权图填充INF
        vector<vector<int>> adm(vN, vector<int>(vN, INF));
        //主对角线设置为0
        for (lint i = 0; i < vN; ++i) {
            adm[i][i] = 0;
        }
        //每行读入三个数
        if(isDirect){
            for (lint i = 0; i < eN; ++i) {
                lint a, b, c;
                cin >> a >> b >> c;
                if(adm[a-1][b-1]==INF){
                    adm[a-1][b-1] = 0;
                }
                adm[a-1][b-1] += c;
            }
        }else{//无向则双重填充
            for (lint i = 0; i < eN; ++i) {
                lint a, b, c;
                cin >> a >> b >> c;
                if(adm[a-1][b-1]==INF){
                    adm[a-1][b-1] = 0;
                }
                if(adm[b-1][a-1]==INF){
                    adm[b-1][a-1] = 0;
                }
                adm[a-1][b-1] += c;
                adm[b-1][a-1] += c;
            }
        }
        return adm;
    }else{
        //无权图填充0
        vector<vector<int>> adm(vN, vector<int>(vN, 0));
        //每行读入两个数
        if(isDirect){
            for (lint i = 0; i < eN; ++i) {
                lint a, b;
                cin >> a >> b;
                adm[a-1][b-1] += 1;
            }
        }else{//无向则双重填充
            for (lint i = 0; i < eN; ++i) {
                lint a, b;
                cin >> a >> b;
                adm[a-1][b-1] += 1;
                adm[b-1][a-1] += 1;
            }
        }
        return adm;
    }
}

long long Prim(vector<vector<int>> graph, lint V) {
    int parent[V]; // 存储生成树
    int key[V];    // 用于选择最小边
    bool mstSet[V]; // 为每个顶点标记是否在最小生成树中
    for (int i = 0; i < V; i++) {
        key[i] = INF; // 初始化所有键值为无穷大
        mstSet[i] = false; // 初始化所有顶点未被包含在最小生成树中
    }
    key[0] = 0; // 从第一个顶点开始
    parent[0] = -1; // 第一个顶点是根
    for (int count = 0; count < V - 1; count++) {
        int minKey = INF, minIndex;
        for (int v = 0; v < V; v++) {
            if (!mstSet[v] && key[v] < minKey)
                minKey = key[v], minIndex = v;
        }
        mstSet[minIndex] = true;
        for (int v = 0; v < V; v++) {
            if (graph[minIndex][v] && !mstSet[v] && graph[minIndex][v] < key[v]) {
                parent[v] = minIndex;
                key[v] = graph[minIndex][v];
            }
        }
    }
    lint result = 0;
    for (int i = 1; i < V; i++)
        result +=graph[i][parent[i]];
    return result;
}

int main() {
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int>>matrix = adjMatrix(n, m, true, true);
    lint result = Prim(matrix, n);
    cout << result << endl;
    return 0;
}
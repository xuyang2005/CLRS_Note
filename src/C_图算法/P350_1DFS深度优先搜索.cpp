/**
 * @Author Regulus
 * @Date 2024/11/23
 * @Dis DFS深度优先搜索
 * @Param (const vector<vector<int>>& matrix, 
            vector<bool>& visited,
            int node)
 * @Return vector<vN, vector<vN, int>>的一个邻接矩阵
 * @Hint 由于邻接矩阵的性质，其能存储自环，但不能存储重边，此处遇到重边会+=
 *       即无权图可以显示条数，带权图会扩宽这条边/弧
 */
#include <bits/stdc++.h>
typedef long long lint;
using namespace std;
const int INF = 0x7f7f7f7f;

// 用于邻接矩阵的深度优先搜索
vector<int> result;
// 用于无权的有向/无向图，相当于每条路权都为1
void dfsMatrix(const vector<vector<int>>& matrix, 
vector<bool>& visited,vector<int>& result, int node) {
    visited[node] = true; // 标记当前节点为已访问
    // 把遍历结果存入结果中
    result.push_back(node);
    // 遍历所有相邻节点
    for (int i = 0; i < matrix.size(); ++i) {
        if (matrix[node][i] == 1 && !visited[i]) {// 深度访问
            dfsMatrix(matrix, visited, result, i); // 递归访问
        }
    }
}

// 用于邻接链表的深度优先搜索
vector<int> dfsList(const vector<list<int>>& adjList,
 vector<bool>& visited, int node) {
    visited[node] = true; // 标记当前节点为已访问
    result.push_back(node);
    for (int neighbor : adjList[node]) {
        if (!visited[neighbor]) {
            dfsList(adjList, visited, neighbor); // 递归访问
        }
    }
    return result;
    result.clear();
}

int main() {
    // 示例：使用邻接矩阵
    vector<vector<int>> matrix = {
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {0, 1, 1, 0}
    };

    int vertices = matrix.size();
    vector<bool> visited(vertices, false); // 访问状态初始化
    vector<int> result;
    cout << "DFS using adjacency matrix:" << endl;
    dfsMatrix(matrix, visited, result, 0); // 从节点 0 开始
    for(auto& _ : result){
        cout << _ <<",";
    }
    cout << endl;

    // 重置访问状态
    fill(visited.begin(), visited.end(), false);

    // 示例：使用邻接链表
    vector<list<int>> adjList = {
        {1, 2},   // 节点 0
        {0, 3},   // 节点 1
        {0, 3},   // 节点 2
        {1, 2}    // 节点 3
    };

    cout << "DFS using adjacency list:" << endl;
    vector<int> r2 =dfsList(adjList, visited, 0); // 从节点 0 开始
    for(auto& _ : r2){
        cout << _ <<",";
    }
    cout << endl;

    return 0;
}
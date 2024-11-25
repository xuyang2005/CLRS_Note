/**
 * @Name Floyd(弗洛伊德)-Warshall算法，用于解决所有结点对最短路径问题
 * @Dis 使用D-1和Path-1两张表，依次寻找中间点减小结果长度。
 */
#include <bits/stdc++.h>
typedef long long lint;
using namespace std;
const int INF = 0x7f7f7f7f;
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


struct Edge {
    int dest;
    int weight;
};

// 使用邻接链表实现Floyd-Warshall算法
vector<vector<int>> floydWarshallList(int V, const vector<list<Edge>>& graph) {
    vector<vector<int>> dist(V, vector<int>(V, INF));

    // 初始化距离矩阵
    for (int i = 0; i < V; i++) {
        dist[i][i] = 0; // 自己到自己的距离为0
        for (const auto& edge : graph[i]) {
            dist[i][edge.dest] = edge.weight; // 从邻接链表更新边的权重
        }
    }

    // Floyd-Warshall算法
    for (int k = 0; k < V; k++) {
        for (int i = 0; i < V; i++) {
            for (int j = 0; j < V; j++) {
                if (dist[i][k] != INF && dist[k][j] != INF) {
                    dist[i][j] = std::min(dist[i][j], dist[i][k] + dist[k][j]);
                }
            }
        }
    }
    return dist;
}


// 单元测试
int main() {
    // 示例图的邻接矩阵
    std::vector<std::vector<int>> graph = {
        {0, 3, INF, INF},
        {INF, 0, 1, INF},
        {INF, INF, 0, 7},
        {2, INF, INF, 0}
    };

    floydWarshallMatrix(graph);

    // 示例图的邻接链表
    int V = 4;
    std::vector<std::list<Edge>> graph1(V);

    // 添加边
    graph1[0].push_back({1, 3});
    graph1[1].push_back({2, 1});
    graph1[2].push_back({3, 7});
    graph1[3].push_back({0, 2});

    floydWarshallList(V, graph1);
    return 0;
}


#include <vector>
#include <queue>
#include <iostream>

void bfsMatrix(const std::vector<std::vector<int>>& matrix, std::vector<bool>& visited, std::vector<int>& result, int node) {
    std::queue<int> q;
    q.push(node);
    visited[node] = true;

    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();
        result.push_back(currentNode);

        for (size_t i = 0; i < matrix[currentNode].size(); i++) {
            if (matrix[currentNode][i] == 1 && !visited[i]) {
                q.push(i);
                visited[i] = true;
            }
        }
    }
}

#include <vector>
#include <list>
#include <queue>
#include <iostream>

std::vector<int> bfsList(const std::vector<std::list<int>>& adjList, std::vector<bool>& visited, int node) {
    std::vector<int> result;
    std::queue<int> q;
    q.push(node);
    visited[node] = true;

    while (!q.empty()) {
        int currentNode = q.front();
        q.pop();
        result.push_back(currentNode);

        for (auto& neighbor : adjList[currentNode]) {
            if (!visited[neighbor]) {
                q.push(neighbor);
                visited[neighbor] = true;
            }
        }
    }

    return result;
    
}

int main() {
    // 使用邻接矩阵
    std::vector<std::vector<int>> matrix = {
        {0, 1, 1, 0},
        {1, 0, 0, 1},
        {1, 0, 0, 1},
        {0, 1, 1, 0}
    };

    std::vector<bool> visitedMatrix(matrix.size(), false);
    std::vector<int> resultMatrix;
    bfsMatrix(matrix, visitedMatrix, resultMatrix, 0);

    std::cout << "BFS using matrix: ";
    for (int node : resultMatrix) {
        std::cout << node << " ";
    }
    std::cout << std::endl;

    // 使用邻接表
    std::vector<std::list<int>> adjList = {
        {1, 2},
        {0, 3},
        {0, 3},
        {1, 2}
    };

    std::vector<bool> visitedList(adjList.size(), false);
    std::vector<int> resultList = bfsList(adjList, visitedList, 0);

    std::cout << "BFS using adjacency list: ";
    for (int node : resultList) {
        std::cout << node << " ";
    }
    std::cout << std::endl;

    return 0;
}
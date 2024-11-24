/**
 * @Author Regulus
 * @Date 2024/11/23
 * @Dis 存储图的邻接链表
 * @Param (lint vN 点数默认从1开始,
 *         lint eN 边数/数据组数,
 *         bool isQuan 是否带权，若"无权"则不接受第三个参数,
 *         bool isDirect 是否有向，若"无向"则会同时填充另一个结点)
 * @Return
 * @Hint
 */
#include <bits/stdc++.h>
typedef long long lint;
using namespace std;
const int INF = 0x7f7f7f7f;

vector<list<int>> adjList(lint vN, lint eN, 
bool isQuan, bool isDirect){
    //有向无权图
    vector<list<int>> adjl(vN);
    for(int i = 0; i < eN; i++){
        int a,b;
        cin >> a >> b;
        adjl[a].push_back(b);
    }
    return adjl;
}
/*给定一个二维的矩阵，包含 'X' 和 'O'（字母 O）。
找到所有被 'X' 围绕的区域，并将这些区域里所有的 'O' 用 'X' 填充。

示例:
X X X X
X O O X
X X O X
X O X X
运行你的函数后，矩阵变为：
X X X X
X X X X
X X X X
X O X X
解释:
被围绕的区间不会存在于边界上，换句话说，任何边界上的 'O' 都不会被填充为 'X'。 
任何不在边界上，或不与边界上的 'O' 相连的 'O' 最终都会被填充为 'X'。
如果两个元素在水平或垂直方向相邻，则称它们是“相连”的。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/surrounded-regions
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

xiaobin9652@163.com;
Xiaobin Tian;
解题思路：
解法一：
使用图的深度遍历或者广度遍历。再此我们举例图的广度遍历解法。
可以进入下面网址查看广度遍历的详解
https://leetcode-cn.com/problems/surrounded-regions/solution/bfsdi-gui-dfsfei-di-gui-dfsbing-cha-ji-by-ac_pipe/
解法二：
使用并查集。将所有与边上‘O’相连的‘O’连接到一个并查集dummynode中。
遍历每个元素，若与并查集dummynode相连不改变值，否则变换成‘X’。
*/

/*
*************************************************************************************
解法一
*/
#include<vector>
#include<queue>
using namespace::std;

struct point
{
    int i;
    int j;
    point(int x, int y): i(x), j(y){};
};

void bfs(vector<vector<char>> &board, int i, int j){
    queue<point> myqueue;
    point pos(i, j);
    myqueue.push(pos);
    board[i][j] = '#';
    while(!myqueue.empty()){
        point cur = myqueue.front();
        myqueue.pop();
        if(cur.i > 0 && board[cur.i-1][cur.j] == 'O'){
            myqueue.push(point(cur.i-1,cur.j));
            board[cur.i-1][cur.j] = '#';
        }
        if(cur.i < board.size()-1 && board[cur.i+1][cur.j] == 'O'){
            myqueue.push(point(cur.i+1,cur.j));
            board[cur.i+1][cur.j] = '#';
        }
        if(cur.j > 0 && board[cur.i][cur.j-1] == 'O'){
            myqueue.push(point(cur.i,cur.j-1));
            board[cur.i][cur.j-1] = '#';
        }
        if(cur.j < board[0].size()-1 && board[cur.i][cur.j+1] == 'O'){
            myqueue.push(point(cur.i,cur.j+1));
            board[cur.i][cur.j+1] = '#';
        }
    }
}

void solve(vector<vector<char>> &board){
    if(board.size() == 0 || board[0].size() == 0)
        return;
    int row = board.size(), col = board[0].size();
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            if(i == 0 || i == row-1 || j == 0 || j == col-1)
                if(board[i][j] == 'O')
                    bfs(board, i, j);
        }
    }
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            if(board[i][j] == 'O')
                board[i][j] = 'X';
            else if(board[i][j] == '#')
                board[i][j] = 'O'; 
        }
    }
}

/*
*************************************************************************************
解法二
*/
class UnionFing{
private:
    vector<int> parents;
public:
    UnionFing(int totalnumber){
        for(int i = 0; i < totalnumber; ++i)
            parents.push_back(i);
    };

    void Union(int node1, int node2){
        int root1 = find(node1);
        int root2 = find(node2);
        if(root1 != root2){
            parents[root2] = root1;
        }
    }

    int find(int node){
        while(parents[node] != node){
            parents[node] = parents[parents[node]];
            node = parents[node];
        }
        return node;
    }

    bool isConnected(int node1, int node2){
        return find(node1) == find(node2);
    }
};


inline int node(int i, int j, int col){
        return i * col + j;
}
void solve(vector<vector<char>>& board){
    if(board.size() < 1  || board[0].size() < 1)
        return;
    int row = board.size(), col = board[0].size();
    UnionFing uf(row*col+1);
    int dummynode = row*col;
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            if(board[i][j] == 'O'){
                if(i==0 || i==row-1 || j==0 || j==col-1){
                    uf.Union(node(i,j,col), dummynode);
                }
                else{
                    if(i > 0 && board[i-1][j] == 'O')
                        uf.Union(node(i, j, col), node(i-1, j, col));
                    if(i < row-1 && board[i+1][j] == 'O')
                        uf.Union(node(i, j, col), node(i+1, j, col));
                    if(j > 0 && board[i][j-1] == 'O')
                        uf.Union(node(i, j, col), node(i, j-1, col));
                    if(j < col-1 && board[i][j+1] == 'O')
                        uf.Union(node(i, j, col), node(i, j+1, col));
                }
            }
        }
    }
    for(int i = 0; i < row; ++i){
        for(int j = 0; j < col; ++j){
            if(!uf.isConnected(node(i,j, col), dummynode)){
                board[i][j] = 'X';
            }
        }
    }
}
/*给定无向连通图中一个节点的引用，返回该图的深拷贝（克隆）。图中的每个节点都包含它的值 val（Int） 和其邻居的列表（list[Node]）。

示例：
输入：
{"$id":"1","neighbors":[{"$id":"2","neighbors":[{"$ref":"1"},
{"$id":"3","neighbors":[{"$ref":"2"},{"$id":"4",
"neighbors":[{"$ref":"3"},{"$ref":"1"}],"val":4}],
"val":3}],"val":2},{"$ref":"4"}],"val":1}

解释：
节点 1 的值是 1，它有两个邻居：节点 2 和 4 。
节点 2 的值是 2，它有两个邻居：节点 1 和 3 。
节点 3 的值是 3，它有两个邻居：节点 2 和 4 。
节点 4 的值是 4，它有两个邻居：节点 1 和 3 。
 

提示：

节点数介于 1 到 100 之间。
无向图是一个简单图，这意味着图中没有重复的边，也没有自环。
由于图是无向的，如果节点 p 是节点 q 的邻居，那么节点 q 也必须是节点 p 的邻居。
必须将给定节点的拷贝作为对克隆图的引用返回。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/clone-graph
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

xiaobin9652@163.com;
Xiaobin Tian;
解题思路：
图的遍历，可以使用深度遍历和广度遍历。
*/

#include<vector>
#include<queue>
#include<unordered_map>
using namespace::std;
class Node {
public:
    int val;
    vector<Node*> neighbors;

    Node() {}

    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
Node* cloneGraph(Node* node) {
    queue<Node*> myqueue;
    unordered_map<Node*, Node*> mymap;
    myqueue.push(node);
    Node *newnode = new Node();
    newnode->val = node->val;
    mymap.insert({node, newnode});
    while(!myqueue.empty()){
        auto p = myqueue.front();
        myqueue.pop();
        vector<Node*> temp;
        for(int i = 0; i < p->neighbors.size(); ++i){
            if(mymap.find(p->neighbors[i]) != mymap.end()){
                Node *q = new Node();
                q->val = p->val;
                mymap.insert({p->neighbors[i], q});
            }
            temp.push_back(mymap.find(p->neighbors[i])->second);
            myqueue.push(p->neighbors[i]);
        }
        mymap.find(p)->second->neighbors = temp;
    }
    return newnode;
}
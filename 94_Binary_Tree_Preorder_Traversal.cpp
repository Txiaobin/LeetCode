/*
给定一个二叉树，返回它的中序 遍历。

示例:
输入: [1,null,2,3]
   1
    \
     2
    /
   3
输出: [1,3,2]

进阶: 递归算法很简单，你可以通过迭代算法完成吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-inorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

xiaobin9652@163.com;
Xiaobin Tian;
解题思路：
二叉树的前序遍历有递归和非递归的方法。本代码使用非递归的方法实现。
利用栈来代替递归，因为需要先遍历左子树，所以将所有由左孩子的节点入栈。没有左孩子的节点，遍历，并将该节点的右孩子入栈进行遍历。
 */

#include<vector>
#include<stack>
using namespace::std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

vector<int> inorderTraversal(TreeNode* root){
    vector<int> traver;
    if(!root){
        return traver;
    }
    TreeNode* p = root;
    stack<TreeNode*> mystack;
    while(p || !mystack.empty()){
        while(p != nullptr){
            mystack.push(p);
            p = p->left;
        }
        if(!mystack.empty()){
            p = mystack.top();
            mystack.pop();
            traver.push_back(p->val);
            p = p->right;
        }
    }
    return traver;
}
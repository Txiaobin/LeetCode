/*
给定一个二叉树，返回它的 前序 遍历。

示例:
输入: [1,null,2,3]  
   1
    \
     2
    /
   3 
输出: [1,2,3]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-preorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 */
#include<vector>
#include<stack>
using namespace::std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
vector<int> preorderTraversal(TreeNode* root) {
    vector<int> traver;
    if(!root){
        return traver;
    }
    TreeNode *p = NULL;
    stack<TreeNode*> mystack;
    mystack.push(root);
    while(!mystack.empty()){
        p = mystack.top();
        traver.push_back(p->val);
        mystack.pop();
        if(p->right)
            mystack.push(p->right);
        if(p->left)
            mystack.push(p->left);
    }
    return traver;
}
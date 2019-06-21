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

xiaobin9652@163.com;
Xiaobin Tian;
解题思路：
二叉树的前序遍历有递归和非递归的方法。本代码使用非递归的方法实现。
利用栈来代替递归，先遍历当前节点，然后右孩子和左孩子分别入栈，即分别遍历左子树和右子树。（注意描述中的左右顺序，先进栈的后遍历）
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
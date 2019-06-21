/*
给定一个二叉树，返回它的 后序 遍历。

示例:
输入: [1,null,2,3]  
   1
    \
     2
    /
   3 
输出: [3,2,1]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/binary-tree-postorder-traversal
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。
 
xiaobin9652@163.com;
Xiaobin Tian;
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
vector<int> postorderTraversal(TreeNode* root) {
    vector<int>  traver;
    if(!root){
        return traver;
    }
    TreeNode dummyRoot(0);
    TreeNode *cur=&dummyRoot, *pre=NULL;
    stack<TreeNode*> mystack;
    mystack.push(root);
    while(!mystack.empty()){
        pre = cur;
        cur = mystack.top();
        if((!cur->left && !cur->right) || (cur->left == pre || cur->right == pre)){
            traver.push_back(cur->val);
            mystack.pop();
        }
        else{
            if(cur->right)
                mystack.push(cur->right);
            if(cur->left)
                mystack.push(cur->left);
        }
    }
    return traver;
}
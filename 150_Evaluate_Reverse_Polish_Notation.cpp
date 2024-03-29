/*
根据逆波兰表示法，求表达式的值。
有效的运算符包括 +, -, *, / 。每个运算对象可以是整数，也可以是另一个逆波兰表达式。

说明：
整数除法只保留整数部分。
给定逆波兰表达式总是有效的。换句话说，表达式总会得出有效数值且不存在除数为 0 的情况。

示例 1：
输入: ["2", "1", "+", "3", "*"]
输出: 9
解释: ((2 + 1) * 3) = 9

示例 2：
输入: ["4", "13", "5", "/", "+"]
输出: 6
解释: (4 + (13 / 5)) = 6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/evaluate-reverse-polish-notation
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

xiaobin9652@163.com;
Xiaobin Tian;
解题思路：
简单的栈的使用，数据结构基本习题。
 */

#include<vector>
#include<string>
#include<stack>
using namespace::std;
int evalRPN(vector<string>& tokens) {
    stack<int> num;
    for(auto c:tokens){
        if(c=="+"||c=="*"||c=="-"||c=="/"){
            int x = num.top();
            num.pop();
            int y = num.top();
            num.pop();
            switch(c.front()){
                case '+':
                    num.push(x+y);
                    break;
                case '-':
                    num.push(y-x);
                    break;
                case '*':
                    num.push(x*y);
                    break;
                case '/':
                    num.push(y/x);
                    break; 
            }
        }
        else{
            num.push(stoi(c));
        }
    }
    return num.top();
}
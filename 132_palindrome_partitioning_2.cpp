/*给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。
返回符合要求的最少分割次数。

示例:
输入: "aab"
输出: 1
解释: 进行一次分割就可将 s 分割成 ["aa","b"] 这样两个回文子串。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/palindrome-partitioning-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

xiaobin9652@163.com;
Xiaobin Tian;
解题思路：动态规划法求解。
初始化数组为 [-1,0,1,....n]。字符串从前到后遍历一遍，以s[i]为中心寻找回文字符串，并设置dp[end+1]=min(dp[start]+1, dp[end+1])。
即如果从start到end为回文字符串，则需要前start-1个字符的划分次数加一。
*/

#include<vector>
#include<string>
using namespace::std;

int minCut(string s){
    vector<int> dp;
    for(int i = 0; i < s.size()+1; ++i)
        dp.push_back(i-1);
    for(int i = 0; i < s.size(); ++i){
        int start = i, end = i;
        while(s[start] == s[end]){
            dp[end+1] = min(dp[start] + 1, dp[end+1]);
            if(start == 0 || end == s.size() - 1)
                break;
            --start;
            ++end;
        }
        start = i; end = i + 1;
        while(s[start] == s[end]){
            dp[end+1] = min(dp[start] + 1, dp[end+1]);
            if(start == 0 || end == s.size() - 1)
                break;
            --start;
            ++end;
        }
        if(dp[s.size()] == 0)
            return 0;
    }
    return dp[s.size()];
}
/*给定一个字符串 s，将 s 分割成一些子串，使每个子串都是回文串。
返回 s 所有可能的分割方案。

示例:
输入: "aab"
输出:
[
  ["aa","b"],
  ["a","a","b"]
]


来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/clone-graph
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

xiaobin9652@163.com;
Xiaobin Tian;
解题思路：使用动态规划找到任意 i 和 j 之间子串是否为回文字符串。在使用递归算法找到所有可能的组合。
*/

#include<vector>
#include<string>
using namespace::std;

vector<vector<string>> printpartition(string s, int begin, vector<vector<int>> dp){
    vector<vector<string>> result;
    if(begin == s.size()){
        vector<string> temp;
        result.push_back(temp);
    }
    else{
        for(int i = begin; i < s.size(); ++i){
            if(dp[begin][i]){
                string substring = s.substr(begin, i - begin + 1);
                auto temp = printpartition(s, i+1, dp);
                for(auto p : temp){
                    p.insert(p.begin(), substring);
                    result.push_back(p);
                }
            }
        }
    }
    return result;
}

vector<vector<string>> partition(string s){
    vector<vector<int>> dp(s.size(), vector<int>(s.size(),0));
    for(int len = 1; len <= s.size(); ++len){
        for(int i = 0; i <= s.size() - len; ++i){
            int j = i + len -1;
            if(s[i] == s[j] && (len < 3 || dp[i+1][j-1] == 1)){
                dp[i][j] = 1;
            }
        }
    }
    vector<vector<string>> result = printpartition(s, 0, dp);
    return result;
}
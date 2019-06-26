/*
给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，在字符串中增加空格来构建一个句子，使得句子中所有的单词都在词典中。返回所有这些可能的句子。
说明：
分隔时可以重复使用字典中的单词。
你可以假设字典中没有重复的单词。

示例 1：
输入:
s = "catsanddog"
wordDict = ["cat", "cats", "and", "sand", "dog"]
输出:
[
  "cats and dog",
  "cat sand dog"
]

示例 2：
输入:
s = "pineapplepenapple"
wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
输出:
[
  "pine apple pen apple",
  "pineapple pen apple",
  "pine applepen apple"
]
解释: 注意你可以重复使用字典中的单词。

示例 3：
输入:
s = "catsandog"
wordDict = ["cats", "dog", "sand", "and", "cat"]
输出:
[]

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-break-ii
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

xiaobin9652@163.com;
Xiaobin Tian;
解题思路：
解法一：暴力搜索的方法进行求解，但是在测试过程中会出现超出时间限制的情况。
"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"
["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]

解法二：动态规划算法
使用 n+1 大小的数组 dp 来保存求解的过程，其中 n 是给定字符串的长度。
在求解dp时，使用 2 个下标指针 i 和 j ，其中 i 指向当前字符串（s′）的末尾，j 是当前子字符串（s′）的拆分位置，拆分成 s′(0,j) 和 s'(j+1,i)。
为了求出dp 数组，我们初始化dp都为空串 。
我们用下标 i 来考虑所有从当前字符串开始的可能的子字符串。对于每一个子字符串，我们通过下标 j 将它拆分成s1′和s2′（注意 i 现在指向s2′的结尾）。
为了将 dp[i] 数组求出来，我们依次检查所有dp[j]包含的非空字符串 ，也就是子字符串 s1′是否满足题目要求。
如果满足，我们接下来检查s2′是否在字典中。如果两个字符串都满足要求，我们将新形成的句子保存进dp[i]。
最后可通过dp[s.length()]的值来判断问题的解。
 */

#include<vector>
#include<string>
#include<unordered_set>
using namespace::std;
/*
解法一的输出一直有错误，但是并未发现问题。
 */
vector<string> wordfind_1(string s, unordered_set<string> myset, int start){
    vector<string> res;
    if(start == s.size())
        return res;
    for(int i = start+1; i <= s.size(); i++){
        if(myset.find(s.substr(start,i-start)) != myset.end()){
            vector<string> list = wordfind_1(s, myset, i);
            for(string e : list){
                res.push_back(s.substr(start,i-start) + (e.empty() ? "":" ") + e);
            }
        }  
    }
    return res;
}
vector<string> wordBreak_1(string s, vector<string> &wordDict){
    unordered_set<string> myset;
    for(int i = 0; i < wordDict.size(); i++){
        myset.insert(wordDict[i]);
    }
    return wordfind_1(s,myset,0);
}


vector<string> wordBreak_2(string s, vector<string> &wordDict){
    unordered_set<string> myset;
    for(int i = 0; i < wordDict.size(); i++){
        myset.insert(wordDict[i]);
    }
    vector<string> dp[s.length()+1];
    vector<string> init;
    init.push_back("");
    dp[0] = init;
    for(int i = 1; i <= s.length(); ++i){
        vector<string> list;
        for(int j = 0; j < i; ++j){
            if(dp[j].size() > 0 && myset.find(s.substr(j,i-j)) != myset.end()){
                for(auto e:dp[j]){
                    list.push_back(e + (e.empty() ? "":" ") + s.substr(j,i-j));
                }
            }
        }
        dp[i] = list;
    }
    return dp[s.length()];
}
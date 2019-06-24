/*
给定一个非空字符串 s 和一个包含非空单词列表的字典 wordDict，判定 s 是否可以被空格拆分为一个或多个在字典中出现的单词。

说明：
1.拆分时可以重复使用字典中的单词。
2.你可以假设字典中没有重复的单词。

示例 1：
输入: s = "leetcode", wordDict = ["leet", "code"]
输出: true
解释: 返回 true 因为 "leetcode" 可以被拆分成 "leet code"。

示例 2：
输入: s = "applepenapple", wordDict = ["apple", "pen"]
输出: true
解释: 返回 true 因为 "applepenapple" 可以被拆分成 "apple pen apple"。
     注意你可以重复使用字典中的单词。

示例 3：
输入: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-break
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

xiaobin9652@163.com;
Xiaobin Tian;
解题思路：

解法一：暴力搜索的方法进行求解，但是在测试过程中会出现超出时间限制的情况。
"aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaab"
["a","aa","aaa","aaaa","aaaaa","aaaaaa","aaaaaaa","aaaaaaaa","aaaaaaaaa","aaaaaaaaaa"]

解法二：在解法一种，函数在求解时会对相同的字符串调用多次求解。我们可以保存下每个子问题的求解，在下次遇到相同子问题时直接使用不再计算。
但此方法也会出现超出时间限制的情况。

解法三：动态规划算法
使用 n+1 大小的数组 dp 来保存求解的过程，其中 n 是给定字符串的长度。
在求解dp时，使用 2 个下标指针 i 和 j ，其中 i 指向当前字符串（s′）的末尾，j 是当前子字符串（s′）的拆分位置，拆分成 s′(0,j) 和 s'(j+1,i)。
为了求出dp 数组，我们初始化dp[0] 为true ，这是因为空字符串总是字典的一部分。数组dp剩余的元素都初始化为false。
我们用下标 i 来考虑所有从当前字符串开始的可能的子字符串。对于每一个子字符串，我们通过下标 j 将它拆分成s1′和s2′（注意 i 现在指向s2′的结尾）。
为了将 dp[i] 数组求出来，我们依次检查每个 dp[j] 是否为 true ，也就是子字符串 s1′是否满足题目要求。
如果满足，我们接下来检查s2′是否在字典中。如果两个字符串都满足要求，我们让dp[i] 为true ，否则令其为false 。
最后可通过dp[s.length()]的值来判断问题的解。
 */

#include<vector>
#include<string>
#include<unordered_set>
using namespace::std;
bool wordfind_1(string s, unordered_set<string> myset, int start){
    if(start == s.size())
        return true;
    for(int i = 1; start+i <= s.size(); i++){
        if((myset.find(s.substr(start,i)) != myset.end()) && wordfind_1(s, myset, start + i)){
            return true;
        }  
    }
    return false;
}
bool wordBreak_1(string s, vector<string> &wordDict){
    unordered_set<string> myset;
    for(int i = 0; i < wordDict.size(); i++){
        myset.insert(wordDict[i]);
    }
    return wordfind_1(s,myset,0);
}


bool wordfind_2(string s, unordered_set<string> myset, int start, vector<bool> &boolean){
    if(start == s.size())
        return true;
    if(boolean[start] != false){
        return true;
    }
    for(int i = 1; start+i <= s.size(); i++){
        if((myset.find(s.substr(start,i)) != myset.end()) && wordfind_2(s, myset, start+i, boolean)){
            return boolean[start]  = true;
        }  
    }
    return boolean[start] = false;
}
bool wordBreak_2(string s, vector<string> &wordDict){
    unordered_set<string> myset;
    for(int i = 0; i < wordDict.size(); i++){
        myset.insert(wordDict[i]);
    }
    vector<bool> boolean(s.length(), false);
    return wordfind_2(s,myset,0,boolean);
}


bool wordBreak_3(string s, vector<string> &wordDict){
    unordered_set<string> myset;
    for(int i = 0; i < wordDict.size(); i++){
        myset.insert(wordDict[i]);
    }
    vector<bool> dp(s.length()+1, false);
    dp[0] = true;
    for(int i = 1; i <= s.length(); ++i){
        for(int j = 0; j < i; ++j){
            if(dp[j] && myset.find(s.substr(j,i-j)) != myset.end()){
                dp[i] = true;
                break;
            }
        }
    }
    return dp[s.length()];
}
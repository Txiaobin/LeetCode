/*
给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。

示例 1:
输入: "abcabcbb"
输出: 3 
解释: 因为无重复字符的最长子串是 "abc"，所以其长度为 3。

示例 2:
输入: "bbbbb"
输出: 1
解释: 因为无重复字符的最长子串是 "b"，所以其长度为 1。

示例 3:
输入: "pwwkew"
输出: 3
解释: 因为无重复字符的最长子串是 "wke"，所以其长度为 3。
     请注意，你的答案必须是 子串 的长度，"pwke" 是一个子序列，不是子串。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/sort-list
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

xiaobin9652@163.com;
Xiaobin Tian;
解题思路：
优化的滑动窗口：
当我们找到重复的字符时，我们可以立即跳过该窗口。
也就是说，如果 s[j]s[j] 在 [i, j)范围内有与 j' 重复的字符，我们不需要逐渐增加i。我们可以直接跳过 [i，j']范围内的所有元素，并将 i 变为 j' + 1
 */
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace::std;
int lengthOfLongestSubstring(string s) {
    int i = 0;
    int len = 0;
    std::unordered_map<char, int> mymap;
    for(int j = 0; j < s.size(); j++){
        if(mymap.find(s[j]) != mymap.end()){
            i = max(mymap.find(s[j])->second, i);
        }
        len = max(len, j-i+1);
        mymap[s[j]] = j+1;
    }
    return len;
}
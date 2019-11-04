/*给定两个单词（beginWord 和 endWord）和一个字典，找到从 beginWord 到 endWord 的最短转换序列的长度。转换需遵循如下规则：
每次转换只能改变一个字母；转换过程中的中间单词必须是字典中的单词。
说明:
如果不存在这样的转换序列，返回 0。
所有单词具有相同的长度。
所有单词只由小写字母组成。
字典中不存在重复的单词。
你可以假设 beginWord 和 endWord 是非空的，且二者不相同。

示例 1:
输入:
beginWord = "hit",
endWord = "cog",
wordList = ["hot","dot","dog","lot","log","cog"]
输出: 5
解释: 一个最短转换序列是 "hit" -> "hot" -> "dot" -> "dog" -> "cog",
     返回它的长度 5。

示例 2:
输入:
beginWord = "hit"
endWord = "cog"
wordList = ["hot","dot","dog","lot","log"]
输出: 0
解释: endWord "cog" 不在字典中，所以无法进行转换。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/word-ladder
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

xiaobin9652@163.com;
Xiaobin Tian;
解题思路：

*/

#include<vector>
#include<string>
#include<unordered_map>
#include<unordered_set>
#include<queue>
using namespace::std;

int ladderLength(string beginWord, string endWord, vector<string>& wordList){
    unordered_map<string, vector<string>> allTranDict;
    for(auto str : wordList){
        for(int i = 0; i < str.size(); ++i){
            auto newword = str.substr(0,i) + '*' + str.substr(i + 1);
            if(allTranDict.find(newword) == allTranDict.end()){
                vector<string> temp;
                temp.push_back(str);
                allTranDict.insert({newword, temp});
            }
            else{
                allTranDict.find(newword)->second.push_back(str);
            }
        }
    }

    queue<pair<string, int>> myqueue;
    myqueue.push(pair(beginWord, 1));
    unordered_set<string> visited;
    visited.insert(beginWord);

    while(!myqueue.empty()){
        auto str = myqueue.front().first;
        auto val = myqueue.front().second;
        myqueue.pop();
        for(int i = 0; i < str.size(); ++i){
            auto newword = str.substr(0,i) + '*' + str.substr(i + 1);
            for(auto temp : allTranDict.find(newword)->second){
                if(temp == endWord)
                    return val+1;
                if(visited.find(temp) == visited.end()){
                    visited.insert(temp);
                    myqueue.push(pair(temp, val+1));
                }
            }
        }
    }
    return 0;
}
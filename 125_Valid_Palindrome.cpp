/*给定一个字符串，验证它是否是回文串，只考虑字母和数字字符，可以忽略字母的大小写。

说明：本题中，我们将空字符串定义为有效的回文串。

示例 1:

输入: "A man, a plan, a canal: Panama"
输出: true
示例 2:

输入: "race a car"
输出: false

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/valid-palindrome
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

xiaobin9652@163.com;
Xiaobin Tian;
解题思路：

*/

#include<string>
#include<iostream>
using namespace::std;

bool isPalindrome(string s){
    if(s.size() == 0)
        return true;
    auto p = s.begin();
    while(p < s.end()){
        *p = toupper(*p);
        if(!(isdigit(*p)||isalpha(*p))){
            p = s.erase(p);
        }
        else{
            ++p;
        }
    }
    auto begin = s.begin();
    auto end = s.end()-1;
    while(begin <= end){
        if(*begin != *end)
            return false;
        ++begin;
        --end;
    }
    return true;
}

int main(){
    string s = "A man, a plan, a canal:Panama";
    auto result = isPalindrome(s);
    return 0;
}
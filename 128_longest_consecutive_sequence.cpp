/*给定一个未排序的整数数组，找出最长连续序列的长度。
要求算法的时间复杂度为 O(n)。

示例:
输入: [100, 4, 200, 1, 3, 2]
输出: 4
解释: 最长连续序列是 [1, 2, 3, 4]。它的长度为 4。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/longest-consecutive-sequence
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

xiaobin9652@163.com;
Xiaobin Tian;
解题思路：
讲所有数字都存放在哈希集合中，这样每个数字的查找时间可以降低到 O（1）。
对数组进行遍历，若当前数字 n 减去 1 不在数组中，那么当前数组可以输连续序列的起始。
从 n 开始进行查找后续元素，并找到序列长度，更新当前最长长度。
*/

#include<vector>
#include<unordered_set>
using namespace::std;

int longestConsecutive(vector<int>& num) {
    unordered_set<int> myset;
    for(int i : num){
        if(myset.find(i) == myset.end())
            myset.insert(i);
    }
    int length = 0;
    for(auto i : num){
        if(myset.find(i-1) == myset.end()){
            int temp = i, curlength = 1;
            while(myset.find(temp+1) != myset.end()){
                ++temp;
                ++curlength;
            }
            length = max(length, curlength);
        }
    }
    return length;
}
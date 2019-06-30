/*
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现两次。找出那个只出现了一次的元素。
说明：
你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

示例 1:
输入: [2,2,1]
输出: 1

示例 2:
输入: [4,1,2,1,2]
输出: 4

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/single-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

xiaobin9652@163.com;
Xiaobin Tian;
解题思路：
本题要求不使用额外的空间来进行计算，并且具有线性时间复杂度。即只能在数组中从前到后遍历一遍。
下面介绍使用异或运算来解答本题。
异或运算为一种二进制位逻辑运算符，非二进制位的异或运算会将两个运算表达式转化成二进制数的集合进行异或运算。
异或运算有如下规则：
a ^ 0 = a;
a ^ a = 0;
异或运算满足交换律和结合律，所以a ^ b ^ a = a ^ a ^ b = 0 ^ b = b;
可以利用异或运算的性质来对数组进行一遍遍历得到唯一的数字
 */

#include<vector>
using namespace::std;
int singleNumber(vector<int>& nums) {
    int temp = 0;
    for (int i = 0; i < nums.size(); i++){
        temp ^= nums[i];
    }
    return temp;
}
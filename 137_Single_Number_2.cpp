/*
给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现三次。找出那个只出现了一次的元素。
说明：
你的算法应该具有线性时间复杂度。 你可以不使用额外空间来实现吗？

示例 1:
输入: [2,2,3,2]
输出: 3

示例 2:
输入: [0,1,0,1,0,1,99]
输出: 99

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/single-number
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

xiaobin9652@163.com;
Xiaobin Tian;
解题思路：
本题要求不使用额外的空间来进行计算，并且具有线性时间复杂度。即只能在数组中从前到后遍历一遍。
下面介绍使用二进制模拟三进制来解答本题。
设定如下规则：假设a，b为两位二进制数，若数 num 出现一次，a=num，b=0；若数 num 出现两次，a=0，b=num；若 num 出现三次，a=0，b=0。
a = (a ^ num) & ~b;
b = (b ^ num) & ~a;
其中 a ^ num 和 b ^ num 判断是否num出现一次还是两次；若出现两次时，b=1 ，屏蔽 a ^ num 的次数增加，保持 a=0 的状态。
 */

#include<vector>
using namespace::std;
int singleNumber(vector<int>& nums) {
    int a = 0, b = 0;
    for (int i = 0; i < nums.size(); i++){
        a = (a ^ nums[i]) & ~b;
        b = (b ^ nums[i]) & ~a;
    }
    return a;
}
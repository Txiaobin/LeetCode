/*
老师想给孩子们分发糖果，有 N 个孩子站成了一条直线，老师会根据每个孩子的表现，预先给他们评分。
你需要按照以下要求，帮助老师给这些孩子分发糖果：
每个孩子至少分配到 1 个糖果。
相邻的孩子中，评分高的孩子必须获得更多的糖果。
那么这样下来，老师至少需要准备多少颗糖果呢？

示例 1:
输入: [1,0,2]
输出: 5
解释: 你可以分别给这三个孩子分发 2、1、2 颗糖果。

示例 2:
输入: [1,2,2]
输出: 4
解释: 你可以分别给这三个孩子分发 1、2、1 颗糖果。
     第三个孩子只得到 1 颗糖果，这已满足上述两个条件。

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/candy
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

xiaobin9652@163.com;
Xiaobin Tian;
解题思路：
首先初始化每个学生都获得一个糖果，然后从左到右开始遍历，找到所有比自己左边分高的学生并将他们的糖果数增加一；
下一步从右到左遍历，找到所有比自己右边分高的学生，这一步不直接增加糖果数，需要判断下，他们当前的糖果数是否本身就大于自己右边的糖果数，如果不大于右边的糖果数，再将他们的糖果数加一；
最后将所有学生的糖果数求和。
 */

#include<stack>
#include<vector>
#include<math.h>
using namespace::std;
int candy(vector<int>& ratings){
     vector<int> num(ratings.size(), 1);
     for(int i = 1; i < ratings.size(); ++i){
          if(ratings[i] > ratings[i-1]){
               num[i] = num[i-1]+1;
          }
     }
     int sum = num[ratings.size()-1];
     for(int i = ratings.size() -2; i >= 0; --i){
          if(ratings[i] > ratings[i+1]){
               num[i] = max(num[i], num[i+1] +1);
          }
          sum += num[i];
     }
     return sum;
}
/*
给定一个二维平面，平面上有 n 个点，求最多有多少个点在同一条直线上。

示例 1:
输入: [[1,1],[2,2],[3,3]]
输出: 3
解释:
^
|
|        o
|     o
|  o  
+------------->
0  1  2  3  4

示例 2:
输入: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
输出: 4
解释:
^
|
|  o
|     o        o
|        o
|  o        o
+------------------->
0  1  2  3  4  5  6

来源：力扣（LeetCode）
链接：https://leetcode-cn.com/problems/max-points-on-a-line
著作权归领扣网络所有。商业转载请联系官方授权，非商业转载请注明出处。

xiaobin9652@163.com;
Xiaobin Tian;
解题思路：
根据两点确定一条直线原理，我们可以选取两个点确定一条直线，再看看其他的点有多少位于这条直线上，这题主要思路就这么简单，之所以是个困难题，因为有很多特殊情况要考虑。
第一，斜率的计算，如果用除法计算斜率，会有斜率为无穷大的问题；
另外除法的结果是浮点数，可能会有不精确的问题，所以我们使用乘法来进行斜率的比较，但int的乘法结果可能会超出上限，要用long来保存乘法结果。
第二，重复点的问题，如果一开始选取用来确定一条直线的两个点是重复点就会造成问题，应该跳过这种情况
 */
#include<vector>
#include<algorithm>
using namespace::std;
int maxPoints(vector<vector<int>>& points) {
	int len = 2;
	if(points.size() <= 2)
		return points.size();
	for(int i= 0; i < points.size(); i++){
		int same = 1;
		for(int j=i+1; j < points.size(); j++){
			int cnt = 0;
			if(points[i][0]==points[j][0] && points[i][1]==points[j][1])
				same++;
			else{
                cnt++;
				long kx = points[i][0] - points[j][0];
				long ky = points[i][1] - points[j][1];
				for(int k = j+1; k < points.size(); k++){
					if(kx * (points[j][1]-points[k][1]) == ky * (points[j][0]-points[k][0]))
						cnt++;
				}
			}
			len = max(len, same+cnt);
		}
	}
	return len;
}
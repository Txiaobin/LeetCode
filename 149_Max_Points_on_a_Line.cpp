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
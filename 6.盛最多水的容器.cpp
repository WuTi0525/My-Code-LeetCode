//2023.12.27
//author: wuti
//难度：中等
//https://leetcode.cn/problems/container-with-most-water/description/

#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>
//给定一个长度为 n 的整数数组 height 。有 n 条垂线，第 i 条线的两个端点是(i, 0) 和(i, height[i]) 。
//找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
//返回容器可以储存的最大水量。
//本题可以使用双指针求解
//left表示左边界指针，right表示右边界的指针
//核心就是如何确定这两个指针的移动规则，我们确定的规则就是优先移动高度更低的指针
//时间复杂度：O(n)
//空间复杂度：O(1)


class Solution {
public:
	int maxArea(vector<int>& height) {
		int left = 0;
		int right = height.size() - 1;
		int maxArea = 0;
		while (left < right) {
			maxArea = max(maxArea, (right - left) * min(height[left], height[right]));
			if (height[left] <= height[right]) {
				++left;
			}
			else {
				--right;
			}
		}
		return maxArea;
	}
};

int main06() {
	vector<int> height{1, 8, 6, 2, 5, 4, 8, 3, 7};
	Solution so;
	int ret = so.maxArea(height);
	cout << "容器所盛的最大水量为：" << ret << endl;
	system("pause");
	return 0;
}
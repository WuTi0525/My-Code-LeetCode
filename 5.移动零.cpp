//2023.12.26
//author: wuti
//难度：中等
//https://leetcode.cn/problems/move-zeroes/description/
#include<iostream>
#include<vector>

using namespace std;

//解题思路就是使用非零值按顺序覆盖，后面补零即可
//这里的j可以看成一个慢指针，i可以看出快指针，j只有遇到非零数字才移动，j停下的位置就是补0的位置，也就是说这个方法可以被称为双指针法
//官方题解不建议看
class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int j = 0;//记录从哪个位置开始补0
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i]!=0) {//非零进行赋值
				nums[j++] = nums[i];
			}
		}
		for (; j < nums.size(); ++j) {//补0
			nums[j] = 0;
		}
	}
};

//题目要求：
//给定一个数组 nums，编写一个函数将所有 0 移动到数组的末尾，同时保持非零元素的相对顺序。
//请注意 ，必须在不复制数组的情况下原地对数组进行操作。

int main() {
	vector<int> nums{1, 0, 3, 4, 0, 6, 7, 8, 0, 0, 16, -1};
	cout << "移动零前数组元素为：" << endl;
	for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
		cout << *it << " ";
	}
	cout<<endl;
	Solution so;
	so.moveZeroes(nums);
	cout << "移动零后数组元素为：" << endl;
	for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
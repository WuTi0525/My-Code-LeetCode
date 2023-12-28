//2023.12.28
//author: wuti
//难度：中等
 
//题目描述：
//给定一个整数数组 nums，将数组中的元素向右轮转 k 个位置，其中 k 是非负数
#include<iostream>
#include<vector>
using namespace std;

//使用翻转数组最容易理解
//整体翻转：[1,2,3,4,5,6,7]->[7,6,5,4,3,2,1]
//在位置k处分开数组：[7,6,5,4,3,2,1]=[7,6,5]+[4,3,2,1]
//各段翻转：[7,6,5]->[5,6,7],[4,3,2,1]->[1,2,3,4]
//拼起来就行：[5,6,7]+[1,2,3,4]=[5,6,7,1,2,3,4]
//时间复杂度：O(n)
//空间复杂度：O(1)

class Solution {
public:
	void reverse(vector<int>& nums, int start, int end) {
		while (start < end) {
			swap(nums[start], nums[end]);
			start++;
			end--;
		}
	}
	void rotate(vector<int>& nums, int k) {
		k %= nums.size();
		reverse(nums, 0, nums.size() - 1);
		reverse(nums, 0, k - 1);
		reverse(nums, k, nums.size() - 1);

	}
};
int main() {
	Solution so;
	vector<int> nums{1, 2, 3, 4, 5, 6, 7};
	cout << "原数组为：" << endl;
	for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	so.rotate(nums, 3);
	cout << "轮转数组为：" << endl;
	for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
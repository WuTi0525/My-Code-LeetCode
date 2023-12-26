//2023.12.26
//author: wuti
//难度：中等
//https://leetcode.cn/problems/longest-consecutive-sequence/description/
#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

//题目描述：
//给定一个未排序的整数数组 nums ，找出数字连续的最长序列（不要求序列元素在原数组中连续）的长度。
//请你设计并实现时间复杂度为 O(n) 的算法解决此问题。


//本题也是hash求解
//首先我们将数组存放进unordered_set完成自动去重(这个去重并非必要的，但是却能够大大提高程序的运行效率)并便于后续元素的查找（这个是必须的）,
//然后，我们遍历set容器，查找x-1是否在set中，若不在，从x开始计算连续序列的长度，最后将各段的连续子序列的最大长度返回即可
//不建议直接使用leetcode官方题解求解，比较冗杂难记忆
class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		unordered_set<int> hash_set;
		int res = 0;//最终结果（长度）初始化
		for (int num : nums) {
			hash_set.insert(num);
		}
		for (int x : hash_set) {//也可以是for(int x:nums)但程序效率会降低，因为没有降重
			if(!hash_set.count(x - 1)) {//如果x-1不存在，从x开始重新计算序列长度
				int y = x;
				while (hash_set.count(y + 1))y++;//有x+1,序列长度+1
				res= max(res,y - x + 1);//得到各段连续序列的最大长度，遍历结束后返回即可
			}
		}
		return res;
	}

};

int main() {
	Solution so;
	vector<int> nums{100, 4, 200, 1, 3, 2,1,1};
	int length = so.longestConsecutive(nums);
	cout << "连续序列最长长度为：" << length << endl;
	system("pause");
	return 0;
}
//2023.12.26
//author: wuti
//难度：简单
//https://leetcode.cn/problems/two-sum/description/?envType=study-plan-v2&envId=top-100-liked


#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;


//这道题让我们求解在数组nums中两数之和等于target的下标
//为了将数组中的元素本身与下标对应起来，我们使用unordered_map，可以认为是哈希表
//unordered_map的key为数值本身，value为其在数组中的下标
//对于搜索两个数字，我们使用target-nums[i]在map容器中寻找符合要求的元素
//时间复杂度：O(N)，其中 N 是数组中的元素数量。对于每一个元素 x，我们可以 O(1) 地寻找 target - x。
//空间复杂度：O(N)，其中 N 是数组中的元素数量。主要为哈希表的开销。
class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {	
		unordered_map<int,int> mp;
		for (int i = 0; i < nums.size(); ++i) {
			auto iter = mp.find(target - nums[i]);
			mp.insert(make_pair(nums[i], i));
			if (iter != mp.end()) {
				return { iter->second,i };
			}
		}
		return {};
	}
};

int main() {
	Solution so;
	vector<int> nums{2, 7, 11, 15};
	vector<int> ret=so.twoSum(nums, 9);
	for (int i = 0; i < ret.size(); ++i) {
		cout << ret[i] << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}

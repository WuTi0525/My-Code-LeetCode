//2023.12.26
//author: wuti
//难度：中等
//https://leetcode.cn/problems/3sum/


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//本题要求在nums中找出三个不重复（数值可以相等，但不能是同一位置的数字）的数字之和为0
//返回所有满足条件的数组
//因此函数的返回类型为二元数组vector<vector<int>> 

//本题使用双指针求解比较方便
//我们在遍历数组时，我们相当于固定了其中的一个数，即nums[i],然后使用left和right指针进行移动搜索结果
//本题难点在于如何去重，包含i，left,right的去重

//时间复杂度: O(n^2)
//空间复杂度: O(1)

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;//存放结果
		sort(nums.begin(), nums.end());//对数组进行排序，以便我们进行后续的去重
		//注意我们每次寻找的数字都是从nums[i]以后的数字进行搜索
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] > 0) {//排序后三个数字中最小的数字nums[i]>0，那么一定搜索不到结果，直接返回结果
				return result;
			}
			if (i > 0 && nums[i] == nums[i - 1]) {//对i进行去重，注意去重使用i和i-1去重，这个去重代码经常会被使用
				continue;
			}
			int left = i + 1;//left从i+1开始，表示搜索从nums[i]以后的数字开始
			int right = nums.size() - 1;//右指针最开始为数组的最后一位元素的下标
			while (left < right) {//保证左指针小于右指针进入循环，避免重复选取
				if (nums[i] + nums[left] + nums[right] < 0) {//如果三数之和小于0，说明left太小，往右移动
					left++;
				}
				else if (nums[i] + nums[left] + nums[right] > 0) {//如果三数之和大于0，说明right太大，往左移动
					right--;
				}
				else {//如果三数之和等于0，将结果存入结果集中
					result.push_back(vector<int>{nums[i], nums[left], nums[right]});
					//left去重，由于对left和right有去重的偏移操作，因此需要保证left<right
					while (left < right && nums[left] == nums[left+1])left++;
					while (left < right && nums[right] == nums[right - 1])right--;//right去重
					//等于0则左右指针同时移动
					left++;
					right--;
				}
			}

		}
		return result;

	}
};

int main() {
	Solution so;
	vector<int>nums{-1, 0, 1, 2, -1, -4};
	vector<vector<int>> ret=so.threeSum(nums);
	for (int i = 0; i < ret.size(); ++i) {
		for (int j = 0; j < ret[0].size(); ++j) {
			cout << ret[i][j] << " ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}
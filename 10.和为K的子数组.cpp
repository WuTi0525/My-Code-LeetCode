//2023.12.28
//author: wuti
//难度：中等
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

//题目描述：
//给你一个整数数组 nums 和一个整数 k ，请你统计并返回 该数组中和为 k 的子数组的个数 。
//子数组是数组中元素的连续非空序列。
//时间复杂度：O(n)
//空间复杂度：O(n)
//我们使用前缀和+哈希的方式解决此题
//pre[i]表示数组前i个数字之和，假设j~i的子数组的和为k，那么k=pre[i]-pre[j-1]
//如果要求数组中和为k的子数组的个数，那么可以遍历数组，在遍历的过程中计算前缀和，根据pre[j-1]=pre[i]-k,
//计算到底有多少个这样的pre[j-1]满足其等于pre[i]-k。这里j<=i，因此使用从前到后的遍历，使用map容器，key为
//前缀和，value为前缀和出现的次数(一般数组中有0出现时，前缀和的次数会大于1)，使用map的查询可以降低时间复杂度。


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int pre = 0;
        int count = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;//map数组初始化，用于解决pre-k=0时的次数增加
        for (auto& x : nums) {
            pre += x;
            if (mp.find(pre - k)!=mp.end()) {
                count += mp[pre - k];
            }
            mp[pre]++;
        }
        return count;

    }
};


int main10() {
    vector<int> nums{1, 2, 3};
    Solution so;
    int count = so.subarraySum(nums, 3);
    cout << count << endl;

    system("pause");
    return 0;
}


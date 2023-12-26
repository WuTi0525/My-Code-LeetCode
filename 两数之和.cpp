//2023.12.26
//author: wuti
//�Ѷȣ���
//https://leetcode.cn/problems/two-sum/description/?envType=study-plan-v2&envId=top-100-liked


#include<iostream>
#include<vector>
#include<unordered_map>

using namespace std;


//��������������������nums������֮�͵���target���±�
//Ϊ�˽������е�Ԫ�ر������±��Ӧ����������ʹ��unordered_map��������Ϊ�ǹ�ϣ��
//unordered_map��keyΪ��ֵ����valueΪ���������е��±�
//���������������֣�����ʹ��target-nums[i]��map������Ѱ�ҷ���Ҫ���Ԫ��
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

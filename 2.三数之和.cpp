//2023.12.26
//author: wuti
//�Ѷȣ��е�
//https://leetcode.cn/problems/3sum/


#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

//����Ҫ����nums���ҳ��������ظ�����ֵ������ȣ���������ͬһλ�õ����֣�������֮��Ϊ0
//����������������������
//��˺����ķ�������Ϊ��Ԫ����vector<vector<int>> 

//����ʹ��˫ָ�����ȽϷ���
//�����ڱ�������ʱ�������൱�ڹ̶������е�һ��������nums[i],Ȼ��ʹ��left��rightָ������ƶ��������
//�����ѵ��������ȥ�أ�����i��left,right��ȥ��

//ʱ�临�Ӷ�: O(n^2)
//�ռ临�Ӷ�: O(1)

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>> result;//��Ž��
		sort(nums.begin(), nums.end());//��������������Ա����ǽ��к�����ȥ��
		//ע������ÿ��Ѱ�ҵ����ֶ��Ǵ�nums[i]�Ժ�����ֽ�������
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i] > 0) {//�����������������С������nums[i]>0����ôһ���������������ֱ�ӷ��ؽ��
				return result;
			}
			if (i > 0 && nums[i] == nums[i - 1]) {//��i����ȥ�أ�ע��ȥ��ʹ��i��i-1ȥ�أ����ȥ�ش��뾭���ᱻʹ��
				continue;
			}
			int left = i + 1;//left��i+1��ʼ����ʾ������nums[i]�Ժ�����ֿ�ʼ
			int right = nums.size() - 1;//��ָ���ʼΪ��������һλԪ�ص��±�
			while (left < right) {//��֤��ָ��С����ָ�����ѭ���������ظ�ѡȡ
				if (nums[i] + nums[left] + nums[right] < 0) {//�������֮��С��0��˵��left̫С�������ƶ�
					left++;
				}
				else if (nums[i] + nums[left] + nums[right] > 0) {//�������֮�ʹ���0��˵��right̫�������ƶ�
					right--;
				}
				else {//�������֮�͵���0�����������������
					result.push_back(vector<int>{nums[i], nums[left], nums[right]});
					//leftȥ�أ����ڶ�left��right��ȥ�ص�ƫ�Ʋ����������Ҫ��֤left<right
					while (left < right && nums[left] == nums[left+1])left++;
					while (left < right && nums[right] == nums[right - 1])right--;//rightȥ��
					//����0������ָ��ͬʱ�ƶ�
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
//2023.12.26
//author: wuti
//�Ѷȣ��е�
//https://leetcode.cn/problems/longest-consecutive-sequence/description/
#include<iostream>
#include<vector>
#include<unordered_set>

using namespace std;

//��Ŀ������
//����һ��δ������������� nums ���ҳ���������������У���Ҫ������Ԫ����ԭ�������������ĳ��ȡ�
//������Ʋ�ʵ��ʱ�临�Ӷ�Ϊ O(n) ���㷨��������⡣


//����Ҳ��hash���
//�������ǽ������Ž�unordered_set����Զ�ȥ��(���ȥ�ز��Ǳ�Ҫ�ģ�����ȴ�ܹ������߳��������Ч��)�����ں���Ԫ�صĲ��ң�����Ǳ���ģ�,
//Ȼ�����Ǳ���set����������x-1�Ƿ���set�У������ڣ���x��ʼ�����������еĳ��ȣ���󽫸��ε����������е���󳤶ȷ��ؼ���
//������ֱ��ʹ��leetcode�ٷ������⣬�Ƚ������Ѽ���
class Solution {
public:
	int longestConsecutive(vector<int>& nums) {
		unordered_set<int> hash_set;
		int res = 0;//���ս�������ȣ���ʼ��
		for (int num : nums) {
			hash_set.insert(num);
		}
		for (int x : hash_set) {//Ҳ������for(int x:nums)������Ч�ʻή�ͣ���Ϊû�н���
			if(!hash_set.count(x - 1)) {//���x-1�����ڣ���x��ʼ���¼������г���
				int y = x;
				while (hash_set.count(y + 1))y++;//��x+1,���г���+1
				res= max(res,y - x + 1);//�õ������������е���󳤶ȣ����������󷵻ؼ���
			}
		}
		return res;
	}

};

int main() {
	Solution so;
	vector<int> nums{100, 4, 200, 1, 3, 2,1,1};
	int length = so.longestConsecutive(nums);
	cout << "�������������Ϊ��" << length << endl;
	system("pause");
	return 0;
}
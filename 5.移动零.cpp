//2023.12.26
//author: wuti
//�Ѷȣ��е�
//https://leetcode.cn/problems/move-zeroes/description/
#include<iostream>
#include<vector>

using namespace std;

//����˼·����ʹ�÷���ֵ��˳�򸲸ǣ����油�㼴��
//�����j���Կ���һ����ָ�룬i���Կ�����ָ�룬jֻ�������������ֲ��ƶ���jͣ�µ�λ�þ��ǲ�0��λ�ã�Ҳ����˵����������Ա���Ϊ˫ָ�뷨
//�ٷ���ⲻ���鿴
class Solution {
public:
	void moveZeroes(vector<int>& nums) {
		int j = 0;//��¼���ĸ�λ�ÿ�ʼ��0
		for (int i = 0; i < nums.size(); ++i) {
			if (nums[i]!=0) {//������и�ֵ
				nums[j++] = nums[i];
			}
		}
		for (; j < nums.size(); ++j) {//��0
			nums[j] = 0;
		}
	}
};

//��ĿҪ��
//����һ������ nums����дһ������������ 0 �ƶ��������ĩβ��ͬʱ���ַ���Ԫ�ص����˳��
//��ע�� �������ڲ���������������ԭ�ض�������в�����

int main() {
	vector<int> nums{1, 0, 3, 4, 0, 6, 7, 8, 0, 0, 16, -1};
	cout << "�ƶ���ǰ����Ԫ��Ϊ��" << endl;
	for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
		cout << *it << " ";
	}
	cout<<endl;
	Solution so;
	so.moveZeroes(nums);
	cout << "�ƶ��������Ԫ��Ϊ��" << endl;
	for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
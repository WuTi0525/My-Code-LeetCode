//2023.12.28
//author: wuti
//�Ѷȣ��е�
 
//��Ŀ������
//����һ���������� nums���������е�Ԫ��������ת k ��λ�ã����� k �ǷǸ���
#include<iostream>
#include<vector>
using namespace std;

//ʹ�÷�ת�������������
//���巭ת��[1,2,3,4,5,6,7]->[7,6,5,4,3,2,1]
//��λ��k���ֿ����飺[7,6,5,4,3,2,1]=[7,6,5]+[4,3,2,1]
//���η�ת��[7,6,5]->[5,6,7],[4,3,2,1]->[1,2,3,4]
//ƴ�������У�[5,6,7]+[1,2,3,4]=[5,6,7,1,2,3,4]
//ʱ�临�Ӷȣ�O(n)
//�ռ临�Ӷȣ�O(1)

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
	cout << "ԭ����Ϊ��" << endl;
	for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	so.rotate(nums, 3);
	cout << "��ת����Ϊ��" << endl;
	for (vector<int>::iterator it = nums.begin(); it != nums.end(); it++) {
		cout << *it << " ";
	}
	cout << endl;
	system("pause");
	return 0;
}
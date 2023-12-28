//2023.12.27
//author: wuti
//�Ѷȣ��е�
//https://leetcode.cn/problems/container-with-most-water/description/

#include <iostream>
#include <vector>
using namespace std;
#include <algorithm>
//����һ������Ϊ n ���������� height ���� n �����ߣ��� i ���ߵ������˵���(i, 0) ��(i, height[i]) ��
//�ҳ����е������ߣ�ʹ�������� x �Ṳͬ���ɵ�����������������ˮ��
//�����������Դ�������ˮ����
//�������ʹ��˫ָ�����
//left��ʾ��߽�ָ�룬right��ʾ�ұ߽��ָ��
//���ľ������ȷ��������ָ����ƶ���������ȷ���Ĺ�����������ƶ��߶ȸ��͵�ָ��
//ʱ�临�Ӷȣ�O(n)
//�ռ临�Ӷȣ�O(1)


class Solution {
public:
	int maxArea(vector<int>& height) {
		int left = 0;
		int right = height.size() - 1;
		int maxArea = 0;
		while (left < right) {
			maxArea = max(maxArea, (right - left) * min(height[left], height[right]));
			if (height[left] <= height[right]) {
				++left;
			}
			else {
				--right;
			}
		}
		return maxArea;
	}
};

int main06() {
	vector<int> height{1, 8, 6, 2, 5, 4, 8, 3, 7};
	Solution so;
	int ret = so.maxArea(height);
	cout << "������ʢ�����ˮ��Ϊ��" << ret << endl;
	system("pause");
	return 0;
}
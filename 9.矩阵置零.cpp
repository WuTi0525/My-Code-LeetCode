//2023.12.28
//author: wuti
//�Ѷȣ��е�
//��Ŀ������
//����һ�� m x n �ľ������һ��Ԫ��Ϊ 0 �����������к��е�����Ԫ�ض���Ϊ 0 ����ʹ�� ԭ�� �㷨��
#include<iostream>
#include<vector>
using namespace std;
//����ʹ�ñ������ķ��������׼�������
//ʱ�临�Ӷȣ�O(mn)
//�ռ临�Ӷȣ�O(m+n)
class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int m = matrix.size();
		int n = matrix[0].size();
		vector<bool> row(m), col(n);
		//ʹ�ñ�������¼Ϊ0���к���
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (matrix[i][j] == 0) {
					row[i] = true;
				    col[j] = true;
				}
				
			}
		}
		//����
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (row[i] || col[j]) {
					matrix[i][j] = 0;
				}
			}
		}

	}
};

int main09() {
	vector<vector<int>> matrix{ {0, 1, 2, 0}, { 3, 4, 5, 2 }, { 1, 3, 1, 5 }};
	Solution so;
	int m = matrix.size();
	int n = matrix[0].size();
	cout << "δ����ǰ�ľ������£�" << endl;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	so.setZeroes(matrix);
	cout << "�����ľ������£�" << endl;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
//2023.12.28
//author: wuti
//难度：中等
//题目描述：
//给定一个 m x n 的矩阵，如果一个元素为 0 ，则将其所在行和列的所有元素都设为 0 。请使用 原地 算法。
#include<iostream>
#include<vector>
using namespace std;
//本题使用标记数组的方法最容易记忆和理解
//时间复杂度：O(mn)
//空间复杂度：O(m+n)
class Solution {
public:
	void setZeroes(vector<vector<int>>& matrix) {
		int m = matrix.size();
		int n = matrix[0].size();
		vector<bool> row(m), col(n);
		//使用标记数组记录为0的行和列
		for (int i = 0; i < m; ++i) {
			for (int j = 0; j < n; ++j) {
				if (matrix[i][j] == 0) {
					row[i] = true;
				    col[j] = true;
				}
				
			}
		}
		//置零
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
	cout << "未置零前的矩阵如下：" << endl;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	so.setZeroes(matrix);
	cout << "置零后的矩阵如下：" << endl;
	for (int i = 0; i < m; ++i) {
		for (int j = 0; j < n; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	system("pause");
	return 0;
}
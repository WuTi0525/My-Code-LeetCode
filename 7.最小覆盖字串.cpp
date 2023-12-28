//2023.12.27
//author: wuti
//�Ѷȣ�����
//��Ŀ������
//����һ���ַ��� s ��һ���ַ��� t ������ s �к��� t �����ַ�����С�Ӵ���
//��� s �в����ں��� t �����ַ����Ӵ����򷵻ؿ��ַ��� "" ��

#include<iostream>
#include<algorithm>
#include<unordered_map>
#include<vector>

using namespace std;

class Solution {
public:
	string minWindow(string s, string t) {
		unordered_map<char, int> hs, ht;
		for (auto c : t)ht[c]++;
		int cnt = 0;
		string res;
		int minLength = INT_MAX;

		for (int i = 0, j = 0; i < s.size(); ++i) {
			hs[s[i]]++;
			if (hs[s[i]] <= ht[s[i]]) {
				cnt++;
			}
			if (cnt == t.size()) {
				while (hs[s[j]] > ht[s[j]]) {
					hs[s[j]]--;
					j++;
				}
				if (i - j + 1 < minLength) {
					res = s.substr(j, i - j + 1);
					minLength = i - j + 1;
				}

			}
		}
		return res;

	}
};

int main07() {
	string s = "ADOBECODEBANC",t= "ABC";
	Solution so;
	string ret = so.minWindow(s,t);
	cout << ret << endl;
	system("pause");
	return 0;
}

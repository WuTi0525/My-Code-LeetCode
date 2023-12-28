//2023.12.27
//author: wuti
//难度：困难
//题目描述：
//给你一个字符串 s 、一个字符串 t 。返回 s 中涵盖 t 所有字符的最小子串。
//如果 s 中不存在涵盖 t 所有字符的子串，则返回空字符串 "" 。

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

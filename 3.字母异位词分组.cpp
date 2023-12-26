//2023.12.26
//author: wuti
//难度：中等
//https://leetcode.cn/problems/group-anagrams/description/


//题目要求：
//给你一个字符串数组，请你将 字母异位词 组合在一起。可以按任意顺序返回结果列表。
//字母异位词 是由重新排列源单词的所有字母得到的一个新单词。

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;


//如何对字母异位词进行分组，一个典型的方法就是使用哈希的方法
//我们使用map容器，key等于字母异位词排序后的唯一结果，value为所有字母异位词
//这样，就能够完成字母异位词的分组，然后遍历map容器，把结果存入结果集中即可
class Solution {
public:
	unordered_map<string, vector<string>> mp;//注意value是字符串数组
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		for (string& str:strs) {
			string key = str;
			sort(key.begin(), key.end());//对key进行排序
			mp[key].push_back(str);//使用push_back进行尾部追加
		}

		vector<vector<string>> ans;//存放结果的集合
		//遍历map容器，存入结果集
		for (auto it = mp.begin(); it != mp.end(); it++) {
			ans.push_back(it->second);
		}
		return ans;

	}
};



int main() {
	Solution so;
	vector<string> strs{"eat", "tea", "tan", "ate", "nat", "bat"};
	vector<vector<string>> ret=so.groupAnagrams(strs);
	for (int i = 0; i < ret.size(); ++i) {
		for (int j = 0; j < ret[i].size(); ++j) {
			cout << ret[i][j] << " ";
		}
		cout << endl;
	}

	system("pause");
	return 0;
}

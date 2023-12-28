//2023.12.27
//author: wuti
//难度：中等

//题目描述：
//给定一个字符串 s ，请你找出其中不含有重复字符的 最长子串 的长度。
//去重自然而然想到set容器
#include<iostream>
#include<unordered_set>
using namespace std;


class Solution {
public:
	int lengthoflongestSubstr(string s) {
		unordered_set<char> hash_set;//使用set容器进行去重操作
		int ans = 0, end = -1;//初始化返回结果，end表示子串的右边界
		for (int i = 0; i < s.size(); ++i) {
			if (i != 0) {//i表示子串左边界，遍历左边界，每次遍历时移除前一边界处的字母
				hash_set.erase(s[i - 1]);
			}
			while (end+1<s.size()&&!hash_set.count(s[end+1])) {//end+1表示右边界的下一位置，即最新的右边界，如果最新的右边界处的字母在之前未出现过，则插入set容器中
				hash_set.insert(s[end+1]);//在进行set容器插入操作时完成了去重操作
				++end;
			}
			ans = max(ans, end - i + 1);//返回子串的最长长度
		}
		return ans;
	}
	
	
};

int main08() {
	Solution so;
	int ret=so.lengthoflongestSubstr("pwwkew");
	cout << ret << endl;
	system("pause");
	return 0;
}
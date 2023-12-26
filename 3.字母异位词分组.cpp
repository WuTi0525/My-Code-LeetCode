//2023.12.26
//author: wuti
//�Ѷȣ��е�
//https://leetcode.cn/problems/group-anagrams/description/


//��ĿҪ��
//����һ���ַ������飬���㽫 ��ĸ��λ�� �����һ�𡣿��԰�����˳�򷵻ؽ���б�
//��ĸ��λ�� ������������Դ���ʵ�������ĸ�õ���һ���µ��ʡ�

#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>

using namespace std;


//��ζ���ĸ��λ�ʽ��з��飬һ�����͵ķ�������ʹ�ù�ϣ�ķ���
//����ʹ��map������key������ĸ��λ��������Ψһ�����valueΪ������ĸ��λ��
//���������ܹ������ĸ��λ�ʵķ��飬Ȼ�����map�������ѽ�����������м���
class Solution {
public:
	unordered_map<string, vector<string>> mp;//ע��value���ַ�������
	vector<vector<string>> groupAnagrams(vector<string>& strs) {
		for (string& str:strs) {
			string key = str;
			sort(key.begin(), key.end());//��key��������
			mp[key].push_back(str);//ʹ��push_back����β��׷��
		}

		vector<vector<string>> ans;//��Ž���ļ���
		//����map��������������
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

//2023.12.27
//author: wuti
//�Ѷȣ��е�

//��Ŀ������
//����һ���ַ��� s �������ҳ����в������ظ��ַ��� ��Ӵ� �ĳ��ȡ�
//ȥ����Ȼ��Ȼ�뵽set����
#include<iostream>
#include<unordered_set>
using namespace std;


class Solution {
public:
	int lengthoflongestSubstr(string s) {
		unordered_set<char> hash_set;//ʹ��set��������ȥ�ز���
		int ans = 0, end = -1;//��ʼ�����ؽ����end��ʾ�Ӵ����ұ߽�
		for (int i = 0; i < s.size(); ++i) {
			if (i != 0) {//i��ʾ�Ӵ���߽磬������߽磬ÿ�α���ʱ�Ƴ�ǰһ�߽紦����ĸ
				hash_set.erase(s[i - 1]);
			}
			while (end+1<s.size()&&!hash_set.count(s[end+1])) {//end+1��ʾ�ұ߽����һλ�ã������µ��ұ߽磬������µ��ұ߽紦����ĸ��֮ǰδ���ֹ��������set������
				hash_set.insert(s[end+1]);//�ڽ���set�����������ʱ�����ȥ�ز���
				++end;
			}
			ans = max(ans, end - i + 1);//�����Ӵ��������
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
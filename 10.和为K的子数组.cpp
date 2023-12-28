//2023.12.28
//author: wuti
//�Ѷȣ��е�
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

//��Ŀ������
//����һ���������� nums ��һ������ k ������ͳ�Ʋ����� �������к�Ϊ k ��������ĸ��� ��
//��������������Ԫ�ص������ǿ����С�
//ʱ�临�Ӷȣ�O(n)
//�ռ临�Ӷȣ�O(n)
//����ʹ��ǰ׺��+��ϣ�ķ�ʽ�������
//pre[i]��ʾ����ǰi������֮�ͣ�����j~i��������ĺ�Ϊk����ôk=pre[i]-pre[j-1]
//���Ҫ�������к�Ϊk��������ĸ�������ô���Ա������飬�ڱ����Ĺ����м���ǰ׺�ͣ�����pre[j-1]=pre[i]-k,
//���㵽���ж��ٸ�������pre[j-1]���������pre[i]-k������j<=i�����ʹ�ô�ǰ����ı�����ʹ��map������keyΪ
//ǰ׺�ͣ�valueΪǰ׺�ͳ��ֵĴ���(һ����������0����ʱ��ǰ׺�͵Ĵ��������1)��ʹ��map�Ĳ�ѯ���Խ���ʱ�临�Ӷȡ�


class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int pre = 0;
        int count = 0;
        unordered_map<int, int> mp;
        mp[0] = 1;//map�����ʼ�������ڽ��pre-k=0ʱ�Ĵ�������
        for (auto& x : nums) {
            pre += x;
            if (mp.find(pre - k)!=mp.end()) {
                count += mp[pre - k];
            }
            mp[pre]++;
        }
        return count;

    }
};


int main10() {
    vector<int> nums{1, 2, 3};
    Solution so;
    int count = so.subarraySum(nums, 3);
    cout << count << endl;

    system("pause");
    return 0;
}


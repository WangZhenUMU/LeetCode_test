class Solution {
public:
    string reverseStr(string s, int k) 
    {
        int n=s.size()-1;
        int left = 0,right = left+k;
        while(left<=n)
        {
            if(right<=n)// ��ʣ��Ԫ�ع�k��ʱ��������ת��
                reverse(s.begin()+left,s.begin()+right);
            else// ��ʣ��Ԫ�ز���k��ʱ��תʣ��ȫ��Ԫ�ء�
                reverse(s.begin()+left,s.end());
            left+=2*k;
            right+=2*k;
        }
        return s;
    }
};
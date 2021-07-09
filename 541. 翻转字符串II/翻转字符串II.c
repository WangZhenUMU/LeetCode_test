class Solution {
public:
    string reverseStr(string s, int k) 
    {
        int n=s.size()-1;
        int left = 0,right = left+k;
        while(left<=n)
        {
            if(right<=n)// 当剩余元素够k个时，正常翻转。
                reverse(s.begin()+left,s.begin()+right);
            else// 当剩余元素不够k个时翻转剩余全部元素。
                reverse(s.begin()+left,s.end());
            left+=2*k;
            right+=2*k;
        }
        return s;
    }
};
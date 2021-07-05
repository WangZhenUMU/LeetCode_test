class Solution 
{
public:
    string multiply(string num1, string num2) 
    {
        //�ų���������
        if(num1=="0" || num2=="0")  return "0";
        if(num1=="1")               return num2;
        if(num2=="1")               return num1;
        //�����С���˴�����ת���ɴ�����С��Ч�ʸ���
         if(num1.length() < num2.length())
            swap(num1,num2);
        int m = num1.length(), n = num2.length();
        //����һ��string�����ڴ洢�˷������Ľ��
        string res(m+n,'0');  
        for(int i = n-1; i>=0; --i)
        {
            //����0*�κ���������0����������0ֱ������
            if(num2[i]=='0') continue;
            int c_in = 0; //��λ
            for(int j = m-1; j>=0; --j)
            {
                int new_num = (num1[j]-'0')*(num2[i]-'0') + (res[i+j+1]-'0') + c_in;  
                c_in = new_num / 10; //���½�λֵ
                new_num = new_num % 10; //�������һλ��ֵ������ֵ��¼��string�����res��
                res[i+j+1] = char(new_num + '0');
            }
            if(c_in > 0) res[i] = char(c_in + '0');
        }
        // ȥ���������
        int i = 0;
        while(res[i] == '0') i++;
        return res.substr(i,m+n-i);  
    }
};
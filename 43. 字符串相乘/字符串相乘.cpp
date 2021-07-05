class Solution 
{
public:
    string multiply(string num1, string num2) 
    {
        //排除非正常项
        if(num1=="0" || num2=="0")  return "0";
        if(num1=="1")               return num2;
        if(num2=="1")               return num1;
        //如果是小数乘大数，转换成大数乘小数效率更高
         if(num1.length() < num2.length())
            swap(num1,num2);
        int m = num1.length(), n = num2.length();
        //定义一个string类用于存储乘法得来的结果
        string res(m+n,'0');  
        for(int i = n-1; i>=0; --i)
        {
            //由于0*任何数都等于0，所以遇到0直接跳过
            if(num2[i]=='0') continue;
            int c_in = 0; //进位
            for(int j = m-1; j>=0; --j)
            {
                int new_num = (num1[j]-'0')*(num2[i]-'0') + (res[i+j+1]-'0') + c_in;  
                c_in = new_num / 10; //更新进位值
                new_num = new_num % 10; //计算最后一位的值，并将值记录入string类对象res中
                res[i+j+1] = char(new_num + '0');
            }
            if(c_in > 0) res[i] = char(c_in + '0');
        }
        // 去掉多余的零
        int i = 0;
        while(res[i] == '0') i++;
        return res.substr(i,m+n-i);  
    }
};
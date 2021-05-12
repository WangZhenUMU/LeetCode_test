void rotate(int* nums, int numsSize, int k)
{
    k%=numsSize;
    int count=0;//记录交换次数
    int t=nums[0];//存储下次出发点元素
    int start=0;//记录出发点的位置；
    int sub=k;//记录跳跃点的位置
    while(count++ <numsSize)
    {
        if(sub<numsSize)//判断跳跃之后是否超过数组的长度
        {
            int temp=nums[sub];
            nums[sub]=t;
            t=temp;//记录下次出发点的元素
            sub+=k;//记录跳跃点的位置
        }
        else//跳跃之后超过数组的长度
        {
            int temp=nums[sub-numsSize];
            nums[sub-numsSize]=t;
            t=temp;
            if(sub-numsSize==start)//当跳跃点与出发点重合时，将记录出发点的start后移，同时跳跃点后移一位
            {
                sub=sub-numsSize+1;
                start++;
                t=nums[sub];
                sub+=k;
            }
            else
            {
                sub=sub-numsSize+k;
            }
        }
    }
}
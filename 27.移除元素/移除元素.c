int removeElement(int* nums, int numsSize, int val){
    int count=0;
    int ret=numsSize;
   for(int i=0;i<numsSize;++i)
    {
        if(nums[i]==val)
        {
            count++;
            ret--;
        }
        else
        {
            nums[i-count]=nums[i];
        }
    }
    return ret;
}
int removeDuplicates(int* nums, int numsSize){
    int count=0;
    if(numsSize<2);
    else
        for(int i=1;i<numsSize;i++)
         {
            (nums[i-1]==nums[i])?(count++):(nums[i-count]=nums[i]);
         }
    return numsSize-count;
}
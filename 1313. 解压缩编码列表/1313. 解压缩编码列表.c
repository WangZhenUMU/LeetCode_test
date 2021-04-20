int* decompressRLElist(int* nums, int numsSize, int* returnSize){
    int i,j,n=0;
    *returnSize=0;
    for(i=0;i<numsSize;i+=2)
    {
        *returnSize+=nums[i];
    }
    int *ret=(int*)malloc((*returnSize)*sizeof(int));
    for(i=0;i<numsSize;i+=2)
    {
        for(j=0;j<nums[i];j++)
        {
            ret[n++]=nums[i+1];
            }
    }
    return ret;
}
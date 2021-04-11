int* runningSum(int* nums, int numsSize, int* returnSize) {
	*returnSize = numsSize;
	int i = 1;
	while (i < numsSize)
	{
		nums[i] += nums[i - 1];
		i++;
	}
	return nums;
}
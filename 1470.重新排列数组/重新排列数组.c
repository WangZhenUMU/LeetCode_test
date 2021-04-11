/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* shuffle(int* nums, int numsSize, int n, int* returnSize) {
	int* pro = (int*)malloc(numsSize * sizeof(int));
	*returnSize = numsSize;
	for (int i = 0; i < n; i++)
	{
		pro[2 * i] = nums[i];
		pro[2 * i + 1] = nums[i + n];
	}
	return pro;
}
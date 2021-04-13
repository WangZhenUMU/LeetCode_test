/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* createTargetArray(int* nums, int numsSize, int* index, int indexSize, int* returnSize) {
	int*target = malloc(numsSize * sizeof(int));
	*returnSize = numsSize;
	for (int i = 0; i < indexSize; i++)
	{
		for (int j = numsSize - 1; j > index[i]; j--)
		{
			target[j] = target[j - 1];
		}
		target[index[i]] = nums[i];
	}
	return target;
}
#include<stdio.h>
int missingNumber(int* nums, int numsSize) {
	int n = 0;
	for (int i = 0; i < numsSize; i++)
	{
		n ^= (i + 1) ^ nums[i];
	}
	return n;
}
int main()
{
	int a[8] = { 0,1,8,2,7,3,6,4 };
	printf("%d", missingNumber(a, 8));
	return 0;
}
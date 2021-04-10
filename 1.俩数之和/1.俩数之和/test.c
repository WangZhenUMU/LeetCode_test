//给定一个整数数组 nums 和一个整数目标值 target，请你在该数组中找出 和为目标值 的那 两个 整数，并返回它们的数组下标。
//你可以假设每种输入只会对应一个答案。但是，数组中同一个元素在答案里不能重复出现。
//你可以按任意顺序返回答案
#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
//暴力法：先找一个数与他之后的每个数进行求和，如果和与target相等，返回下标。
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
	int *a = (int*)malloc(sizeof(int) * 2);
	for (int i = 0; i < numsSize - 1; i++) {
		for (int j = i + 1; j < numsSize; j++) {
			if (nums[i] + nums[j] == target) {
				a[0] = i;
				a[1] = j;
			}
		}
	}
	*returnSize = 2;
	return a;
}
int main() {
	int x = 0;
	int *p = &x;
	int nums[4] = { 2,7,11,15 };
	int *a = twoSum(nums, sizeof(nums) / sizeof(nums[0]), 9, p);
	printf("[%d,%d]", a[0], a[1]);
	return 0;
}
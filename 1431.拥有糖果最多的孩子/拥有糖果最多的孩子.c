/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool* kidsWithCandies(int* candies, int candiesSize, int extraCandies, int* returnSize) {
	*returnSize = candiesSize;
	bool *p = (bool*)malloc(candiesSize * sizeof(bool));
	for (int i = 0; i < candiesSize; i++)
	{
		for (int j = 0; j < candiesSize; j++)
		{
			if (candies[i] + extraCandies < candies[j])
			{
				p[i] = false;
				break;
			}
			if (j == candiesSize - 1)
			{
				p[i] = true;
			}
		}
	}
	return p;
}
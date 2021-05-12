/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* addToArrayForm(int* num, int numSize, int k, int* returnSize)
{
	*returnSize = (numSize > 5 ? numSize + 1 : 6);//确定相加后新数组得最大可能大小
	int n = numSize;
	int s = *returnSize;
	int* array = (int*)malloc(sizeof(int)*(*returnSize));//在堆区开辟新的空间用来存储相加后的数组内容
	//从数组的高位开始，
	//由高向低依次将num数组中的数与k相加。
	//将k值取余存入array数组的高位
	//然后将k值取整
	//最后当num数组中的数全取完后跳出循环
	while (n)    //判断num中得数是否加完
	{
		k += num[n - 1];
		array[s - 1] = k % 10;//取余
		k /= 10;//取整
		n--; s--;
	}
	//判断k值是否全部存入array中，如果没有，将k值按位存入
	if (k != 0)
		while (k)
		{
			array[s - 1] = k % 10;
			k /= 10;
			s--;
		}
	//判断实际存入的内容是否与新建数组array大小相等，如果不等，将array数组的指针移位
	if (s != 0)
	{
		array = array + s;
		*returnSize -= s;
	}
	return array;
}
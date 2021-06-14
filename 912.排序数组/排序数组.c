/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #define SIZE 16
// 交换俩数
void Swap(int* left, int* right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}

// 插入排序
// 时间复杂度: O(N^2)		空间复杂度: O(1)		稳定性: 稳定
// 应用场景: 数据量少 || 数据接近有序(小的数据尽量靠前，大的数据尽量靠后，不大不小的数据放在中间)
void InsertSort(int array[], int size)
{
	// 当只有一个数据或者没有数据的时候不需要排序
	if (size <= 1)
		return;
	else
	{
		// 取第i个位置的元素，将第i个位置的元素插入第i个元素之前适当的位置
		for (int i = 1; i < size; i++)
		{
			int end = i - 1;
			int key = array[i];
			// 找出待插入数据的位置
			while (end >= 0 && array[end] > key)
			{
				array[end + 1] = array[end];
				end--;
			}
			// 插入数据
			array[end+1] = key;
		}
	}
}

// 希尔排序 
// 希尔排序是插入排序的优化
// 当gap > 1时都是预排序，目的是让数组更接近于有序。当gap == 1时，数组已经接近有序的了，这样就会很快。
// 时间复杂度; O(N^1.3—N^2）		空间复杂度: O(1)		稳定性: 不稳定
void ShellSort(int array[], int size)
{
	int gap = size;
	while (gap > 1)
	{
		gap = gap / 3 + 1;
		for (int i = gap; i < size; i++)
		{
			int end = i - gap;
			int key = array[i];
			while (end >= 0 && key < array[end])
			{
				array[end+gap] = array[end];
				end = end - gap;
			}
			array[end+gap] = key;
		}
	}
}
// 选择排序
//时间复杂度:O(N^2)		 空间复杂度:O(1)		稳定性: 不稳定 
void SelectSort(int array[], int size)
{
	// 当只有一个数据或者没有数据的时候不需要排序
	if (size > 1)
	{
		// 循环依次找出最大的值的位置，并将其与第size-i-1个元素的位置进行交换
		for (int i = 0 ; i < size-1; i++)
		{
			// 记录最大值的下标
			int MAXPos = 0;
			for (int j = 1; j < size-i; j++)
			{
				if (array[j] > array[MAXPos])
					MAXPos = j;
			}
			//将最大值与第size-i-1个元素的位置进行交换
			if (MAXPos != size - i - 1)
				Swap(&array[MAXPos], &array[size - i - 1]);
		}
	}
}
// 选择排序 优化 同时找出最大最小值，将最大值放最后，最小值放最前
void SelectSortOP(int array[], int size)
{
	if (size > 1)
	{
		int begin = 0;
		int end = size - 1;
		while (begin < end)
		{
			int MAXpos = begin;
			int MINpos = begin;
			int index = begin + 1;
			// 将数组遍历一遍找出数组中的最小值和最大值的下标
			while (index < end)
			{
				if (array[MAXpos] < array[index])
					MAXpos = index;
				if (array[MINpos] > array[index])
					MINpos = index;
				index++;
			}
			// 将最大值与end交换位置
			if (MAXpos != end)
				Swap(&array[MAXpos], &array[end]);
			// 如果最小值恰巧在end位置，则改变MINpos的指向
			if (MINpos == end)
				MINpos = MAXpos;
			// 将最小值与begin交换位置
			if (MINpos != begin)
				Swap(&array[MINpos], &array[begin]);
			begin++;
			end--;
		}
	}
}

// 堆排序
// 排升序建大堆，排降序建小堆
// 时间复杂度: O(NlogN)		空间复杂度: O(1)		稳定性: 不稳定
// 向下调整
void AdjustDown(int array[], int size, int parent)
{
	// 标记双亲结点的左孩子
	int child = parent * 2 + 1;
	while (child < size)
	{
		// 判断双亲结点是否有又孩子，如果有右孩子，将右孩子与左孩子比较，确定可能要与双亲结点交换位置的孩子
		if (child+1 < size && array[child] < array[child + 1])
		{
			child++;
		}
		// 满足条件，进行交换。并更新根结点和孩子结点
		if (array[parent] < array[child])
		{
			Swap(&array[parent], &array[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
		{
			return;
		}
	}
}
void HeapSort(int array[], int size)
{
	// 建堆
	// 从倒数第一个非叶子结点开始一直到根的位置向下调整
	// 升序->大堆  降序->小堆
	for (int i = (size - 2) / 2; i >= 0; i--)
	{
		AdjustDown(array, size, i);
	}
	int Dsize = size - 1;
	//将根结点与最后一个叶子结点交换，然后从根结点开始向下调整------->堆删除的思想
	while (Dsize)
	{
		Swap(&array[0], &array[Dsize]);
		AdjustDown(array, Dsize, 0);
		Dsize--;
	}
}

// 冒泡排序
// 时间复杂度: O(N^2)		空间复杂度: O(1)		稳定性: 稳定
void BubbleSort(int array[], int size)
{
	if (size > 1)
	{
		for (int i = 0; i < size - 1; i++)
		{
			//定义一个标记，默认标记为0，如果进行交换则标记自加；
			//每次遍历完后判断flog是否等于0，如果等于0，则证明数组有序，跳出循环
			int flog = 0;
			for (int j = 0; j < size - i - 1; j++)
			{
				if (array[j] > array[j + 1])
				{
					Swap(&array[j], &array[j + 1]);
					flog++;
				}
			}
			if (0 == flog)
				break;
		}
	}
}

// 快速排序

// 前中后各取一个值，将三个值按照从小到达排序，并返回中间值的下标
int GetMid(int array[], int left,int right)
{
	int mid = left + (right - left) / 2;
	if (array[left] < array[right - 1])
	{
		if (array[mid] < array[left])
			return left;
		else
		{
			if (array[mid] < array[right - 1])
				return mid;
			else
				return right - 1;
		}
	}
	else
	{
		if (array[mid] < array[right - 1])
			return right - 1;
		else
		{
			if (array[mid] < array[left])
				return mid;
			else
				return left;
		}
	}
}
// 快排->左右指针法
void QuickSort1(int array[], int left, int right)
{
	// 如果数据量过少，则采用插入排序，用时更少
	if (right - left <= SIZE)
		InsertSort(array + left, right - left);
	else
	{
		// 从前中后各取一个值，取三个值的中间值与begin的值进行交换
		int begin = left;
		int end = right;
		int mid = GetMid(array, left, right);
		if (begin != mid)
			Swap(&array[left], &array[mid]);
		// 定义key存储基准值
		int key = array[begin++];
		while (begin < end)
		{
			// begin从前向后找遇到比基准值大的值停下
			while (begin < end && array[begin] <= key)
				begin++;
			// 然后end从后向前找，遇到比基准值小的值停下
			while (begin < end && array[end] >= key)
				end++;
			//交换bgin和end的值
			if (begin < end)
				Swap(&array[begin], &array[end]);
		}
		//将基准值放在他应该在的位置。
		if (begin != left)
			Swap(&array[left], &array[begin]);
		// 通过递归对数组进行排序
		QuickSort1(array, left, begin);
		QuickSort1(array, begin, left);
	}
}
// 快排->挖坑法
void QuickSort2(int array[], int left,int right)
{
	if (right - left <= SIZE)
		InsertSort(array + left, right - left);
	else
	{
		// 从前中后各取一个值，取三个值的中间值与end的值进行交换
		int begin = left;
		int end = right - 1;
		int mid = GetMid(array, begin, end);
		if (mid != right - 1);
			Swap(&array[mid], &array[right - 1]);
		// 定义key存储基准值
		int key = array[end];
		while (begin < end)
		{
			// begin先从前往后找一个比基准值大的值
			while (begin < end && array[begin] < key)
				begin++;
			// 如果找到，将找到的这个比基准值大的值填入坑中
			if (begin < end)
				array[end--] = array[begin];
			// end从后向前遍历寻找一个比基准值小的值
			while (begin < end && array[end] > key)
				end--;
			// 如果找到，将找到的这个值填入begin坑中
			if (begin < end)
				array[begin++] = array[end];
		}
		// 将基准值放在他应该存在的位置。
		array[begin] = key;
		QuickSort2(array, left, begin);
		QuickSort2(array, begin, right);
	}
}
// 快排->前后指针法
void QuickSort3(int array[], int left,int right)
{
	if (right - left <= SIZE)
		InsertSort(array + left, right - left);
	else
	{
		int cur = left;
		int prev = cur - 1;
		int mid = GetMid(array, left, right);
		if (mid != right - 1)
			Swap(&array[mid], &array[right - 1]);
		while (cur < right)
		{
			// cur先走，当array[cur]小于基准值时,prev后移，判断是否有一个大于基准值的值被prev标记。
			// 如果有，交换俩值，如果没有，cur继续后移
			if (array[cur] < array[right - 1] && ++prev != cur)
				Swap(&array[cur], &array[prev]);
			cur++;
		}
		// 将基准值放在他应该存在的地方
		if (++prev != right - 1)
		{
			Swap(&array[prev], &array[right - 1]);
		}
		QuickSort3(array, left, prev);
		QuickSort3(array, prev, right);
	}
}

// 归并数据
void MergeData(int array[], int left, int mid, int right, int temp[])
{
	int index = left;
	int beginA = left, endA = mid;
	int beginB = mid, endB = right;
	// 将数组array分为俩段，有序将俩段数组中得数据插入temp中
	while (beginA < endA && beginB < endB)
	{
		if (array[beginA] < array[beginB])
			temp[index++] = array[beginA++];
		else
			temp[index++] = array[beginB++];
	}
	while (beginA < endA)
		temp[index++] = array[beginA++];
	while (beginB < endB)
		temp[index++] = array[beginB++];
}
// 归并排序
void _MergeSort(int array[], int left, int right, int temp[])
{
	//如果数据过少，采用插入排序更好
	if (right - left <= SIZE)
		InsertSort(array + left, right - left);
	else
	{
		int mid = left + (right - left) / 2;
		_MergeSort(array, left, mid, temp);
		_MergeSort(array, mid, right, temp);
		MergeData(array, left, mid, right, temp);
		memcpy(array+left, temp+left, sizeof(array[0])*(right - left));
	}
}
void MergeSort(int array[], int size)
{
	int* temp = (int*)malloc(sizeof(int)*size);
	if (NULL == temp)
		return;
	_MergeSort(array, 0, size, temp);
	free(temp);
	temp = NULL;
}

// 计数排序
void CountSort(int array[], int size)
{
	if (size <= 1)
		return;
	else
	{
	// 先找出数组中的最大数和最小数
		int max, min;
		max = min = array[0];
		for (int i = 1; i < size; i++)
		{
			if (array[i] > max)
				max = array[i];
			if (array[i] < min)
				min = array[i];
		}
		int* count = (int*)calloc(max - min + 1, sizeof(int));
		// 检查是否申请成功
		if (NULL == count)
			return;
		//统计每个数的数量；
		for (int i = 0; i < size; i++)
			count[array[i] - min]++;
		for (int i = 0,j = 0; i < max - min + 1; i++)
		{
			while(count[i]--)
				array[j++] = i + min;
		}
		free(count);
		count = NULL;
	}
}
int* sortArray(int* nums, int numsSize, int* returnSize){
    ShellSort(nums,numsSize);
    //MergeSort(nums,numsSize);
    //HeapSort(nums,numsSize);
    //InsertSort(nums,numsSize);
    *returnSize=numsSize;
    return nums;
}
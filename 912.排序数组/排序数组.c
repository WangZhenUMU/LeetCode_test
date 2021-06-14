/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
 #define SIZE 16
// ��������
void Swap(int* left, int* right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}

// ��������
// ʱ�临�Ӷ�: O(N^2)		�ռ临�Ӷ�: O(1)		�ȶ���: �ȶ�
// Ӧ�ó���: �������� || ���ݽӽ�����(С�����ݾ�����ǰ��������ݾ������󣬲���С�����ݷ����м�)
void InsertSort(int array[], int size)
{
	// ��ֻ��һ�����ݻ���û�����ݵ�ʱ����Ҫ����
	if (size <= 1)
		return;
	else
	{
		// ȡ��i��λ�õ�Ԫ�أ�����i��λ�õ�Ԫ�ز����i��Ԫ��֮ǰ�ʵ���λ��
		for (int i = 1; i < size; i++)
		{
			int end = i - 1;
			int key = array[i];
			// �ҳ����������ݵ�λ��
			while (end >= 0 && array[end] > key)
			{
				array[end + 1] = array[end];
				end--;
			}
			// ��������
			array[end+1] = key;
		}
	}
}

// ϣ������ 
// ϣ�������ǲ���������Ż�
// ��gap > 1ʱ����Ԥ����Ŀ������������ӽ������򡣵�gap == 1ʱ�������Ѿ��ӽ�������ˣ������ͻ�ܿ졣
// ʱ�临�Ӷ�; O(N^1.3��N^2��		�ռ临�Ӷ�: O(1)		�ȶ���: ���ȶ�
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
// ѡ������
//ʱ�临�Ӷ�:O(N^2)		 �ռ临�Ӷ�:O(1)		�ȶ���: ���ȶ� 
void SelectSort(int array[], int size)
{
	// ��ֻ��һ�����ݻ���û�����ݵ�ʱ����Ҫ����
	if (size > 1)
	{
		// ѭ�������ҳ�����ֵ��λ�ã����������size-i-1��Ԫ�ص�λ�ý��н���
		for (int i = 0 ; i < size-1; i++)
		{
			// ��¼���ֵ���±�
			int MAXPos = 0;
			for (int j = 1; j < size-i; j++)
			{
				if (array[j] > array[MAXPos])
					MAXPos = j;
			}
			//�����ֵ���size-i-1��Ԫ�ص�λ�ý��н���
			if (MAXPos != size - i - 1)
				Swap(&array[MAXPos], &array[size - i - 1]);
		}
	}
}
// ѡ������ �Ż� ͬʱ�ҳ������Сֵ�������ֵ�������Сֵ����ǰ
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
			// ���������һ���ҳ������е���Сֵ�����ֵ���±�
			while (index < end)
			{
				if (array[MAXpos] < array[index])
					MAXpos = index;
				if (array[MINpos] > array[index])
					MINpos = index;
				index++;
			}
			// �����ֵ��end����λ��
			if (MAXpos != end)
				Swap(&array[MAXpos], &array[end]);
			// �����Сֵǡ����endλ�ã���ı�MINpos��ָ��
			if (MINpos == end)
				MINpos = MAXpos;
			// ����Сֵ��begin����λ��
			if (MINpos != begin)
				Swap(&array[MINpos], &array[begin]);
			begin++;
			end--;
		}
	}
}

// ������
// �����򽨴�ѣ��Ž���С��
// ʱ�临�Ӷ�: O(NlogN)		�ռ临�Ӷ�: O(1)		�ȶ���: ���ȶ�
// ���µ���
void AdjustDown(int array[], int size, int parent)
{
	// ���˫�׽�������
	int child = parent * 2 + 1;
	while (child < size)
	{
		// �ж�˫�׽���Ƿ����ֺ��ӣ�������Һ��ӣ����Һ��������ӱȽϣ�ȷ������Ҫ��˫�׽�㽻��λ�õĺ���
		if (child+1 < size && array[child] < array[child + 1])
		{
			child++;
		}
		// �������������н����������¸����ͺ��ӽ��
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
	// ����
	// �ӵ�����һ����Ҷ�ӽ�㿪ʼһֱ������λ�����µ���
	// ����->���  ����->С��
	for (int i = (size - 2) / 2; i >= 0; i--)
	{
		AdjustDown(array, size, i);
	}
	int Dsize = size - 1;
	//������������һ��Ҷ�ӽ�㽻����Ȼ��Ӹ���㿪ʼ���µ���------->��ɾ����˼��
	while (Dsize)
	{
		Swap(&array[0], &array[Dsize]);
		AdjustDown(array, Dsize, 0);
		Dsize--;
	}
}

// ð������
// ʱ�临�Ӷ�: O(N^2)		�ռ临�Ӷ�: O(1)		�ȶ���: �ȶ�
void BubbleSort(int array[], int size)
{
	if (size > 1)
	{
		for (int i = 0; i < size - 1; i++)
		{
			//����һ����ǣ�Ĭ�ϱ��Ϊ0��������н��������Լӣ�
			//ÿ�α�������ж�flog�Ƿ����0���������0����֤��������������ѭ��
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

// ��������

// ǰ�к��ȡһ��ֵ��������ֵ���մ�С�������򣬲������м�ֵ���±�
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
// ����->����ָ�뷨
void QuickSort1(int array[], int left, int right)
{
	// ������������٣�����ò���������ʱ����
	if (right - left <= SIZE)
		InsertSort(array + left, right - left);
	else
	{
		// ��ǰ�к��ȡһ��ֵ��ȡ����ֵ���м�ֵ��begin��ֵ���н���
		int begin = left;
		int end = right;
		int mid = GetMid(array, left, right);
		if (begin != mid)
			Swap(&array[left], &array[mid]);
		// ����key�洢��׼ֵ
		int key = array[begin++];
		while (begin < end)
		{
			// begin��ǰ����������Ȼ�׼ֵ���ֵͣ��
			while (begin < end && array[begin] <= key)
				begin++;
			// Ȼ��end�Ӻ���ǰ�ң������Ȼ�׼ֵС��ֵͣ��
			while (begin < end && array[end] >= key)
				end++;
			//����bgin��end��ֵ
			if (begin < end)
				Swap(&array[begin], &array[end]);
		}
		//����׼ֵ������Ӧ���ڵ�λ�á�
		if (begin != left)
			Swap(&array[left], &array[begin]);
		// ͨ���ݹ�������������
		QuickSort1(array, left, begin);
		QuickSort1(array, begin, left);
	}
}
// ����->�ڿӷ�
void QuickSort2(int array[], int left,int right)
{
	if (right - left <= SIZE)
		InsertSort(array + left, right - left);
	else
	{
		// ��ǰ�к��ȡһ��ֵ��ȡ����ֵ���м�ֵ��end��ֵ���н���
		int begin = left;
		int end = right - 1;
		int mid = GetMid(array, begin, end);
		if (mid != right - 1);
			Swap(&array[mid], &array[right - 1]);
		// ����key�洢��׼ֵ
		int key = array[end];
		while (begin < end)
		{
			// begin�ȴ�ǰ������һ���Ȼ�׼ֵ���ֵ
			while (begin < end && array[begin] < key)
				begin++;
			// ����ҵ������ҵ�������Ȼ�׼ֵ���ֵ�������
			if (begin < end)
				array[end--] = array[begin];
			// end�Ӻ���ǰ����Ѱ��һ���Ȼ�׼ֵС��ֵ
			while (begin < end && array[end] > key)
				end--;
			// ����ҵ������ҵ������ֵ����begin����
			if (begin < end)
				array[begin++] = array[end];
		}
		// ����׼ֵ������Ӧ�ô��ڵ�λ�á�
		array[begin] = key;
		QuickSort2(array, left, begin);
		QuickSort2(array, begin, right);
	}
}
// ����->ǰ��ָ�뷨
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
			// cur���ߣ���array[cur]С�ڻ�׼ֵʱ,prev���ƣ��ж��Ƿ���һ�����ڻ�׼ֵ��ֵ��prev��ǡ�
			// ����У�������ֵ�����û�У�cur��������
			if (array[cur] < array[right - 1] && ++prev != cur)
				Swap(&array[cur], &array[prev]);
			cur++;
		}
		// ����׼ֵ������Ӧ�ô��ڵĵط�
		if (++prev != right - 1)
		{
			Swap(&array[prev], &array[right - 1]);
		}
		QuickSort3(array, left, prev);
		QuickSort3(array, prev, right);
	}
}

// �鲢����
void MergeData(int array[], int left, int mid, int right, int temp[])
{
	int index = left;
	int beginA = left, endA = mid;
	int beginB = mid, endB = right;
	// ������array��Ϊ���Σ��������������е����ݲ���temp��
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
// �鲢����
void _MergeSort(int array[], int left, int right, int temp[])
{
	//������ݹ��٣����ò����������
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

// ��������
void CountSort(int array[], int size)
{
	if (size <= 1)
		return;
	else
	{
	// ���ҳ������е����������С��
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
		// ����Ƿ�����ɹ�
		if (NULL == count)
			return;
		//ͳ��ÿ������������
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
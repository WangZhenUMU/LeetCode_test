/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* addToArrayForm(int* num, int numSize, int k, int* returnSize)
{
	*returnSize = (numSize > 5 ? numSize + 1 : 6);//ȷ����Ӻ�������������ܴ�С
	int n = numSize;
	int s = *returnSize;
	int* array = (int*)malloc(sizeof(int)*(*returnSize));//�ڶ��������µĿռ������洢��Ӻ����������
	//������ĸ�λ��ʼ��
	//�ɸ�������ν�num�����е�����k��ӡ�
	//��kֵȡ�����array����ĸ�λ
	//Ȼ��kֵȡ��
	//���num�����е���ȫȡ�������ѭ��
	while (n)    //�ж�num�е����Ƿ����
	{
		k += num[n - 1];
		array[s - 1] = k % 10;//ȡ��
		k /= 10;//ȡ��
		n--; s--;
	}
	//�ж�kֵ�Ƿ�ȫ������array�У����û�У���kֵ��λ����
	if (k != 0)
		while (k)
		{
			array[s - 1] = k % 10;
			k /= 10;
			s--;
		}
	//�ж�ʵ�ʴ���������Ƿ����½�����array��С��ȣ�������ȣ���array�����ָ����λ
	if (s != 0)
	{
		array = array + s;
		*returnSize -= s;
	}
	return array;
}
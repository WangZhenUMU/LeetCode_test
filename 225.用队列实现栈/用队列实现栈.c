typedef int QDataType;
typedef struct QListNode
{
	struct QListNode* next;
	QDataType data;
}QNode;
// 队列的结构 
typedef struct Queue
{
	QNode* front;
	QNode* rear;
}Queue;
void QueueInit(Queue* q);// 初始化队列 
void QueuePush(Queue* q, QDataType data);// 队尾入队列 
QDataType QueuePop(Queue* q);// 队头出队列 
QDataType QueueFront(Queue* q);// 获取队列头部元素
QDataType QueueBack(Queue* q);// 获取队列尾部元素
int QueueSize(Queue* q);// 获取队列中有效元素个数 
int QueueEmpty(Queue* q);// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
void QueueDestroy(Queue* q);// 销毁队列 
QNode* BuyQueueNode(QDataType data)
{
	QNode* node = (QNode*)malloc(sizeof(QNode));
	if (NULL == node)
	{
		assert(0);
		return NULL;
	}
	node->data = data;
	node->next = NULL;
	return node;
}
// 初始化队列 
void QueueInit(Queue* q)
{
	assert(q);
	q->front = q->rear = BuyQueueNode(0);
}
// 队尾入队列 
void QueuePush(Queue* q, QDataType data)
{
	assert(q);
	q->rear->next = BuyQueueNode(data);
	q->rear = q->rear->next;
}
// 队头出队列 
QDataType QueuePop(Queue* q)
{
	assert(q);
	if (QueueEmpty(q)) //如果为空直接跳出函数
		return NULL;
	QNode* DelNode = q->front->next;
    QDataType temp=DelNode->data;
	q->front->next = DelNode->next;
    if(q->front->next==NULL)
    {
        q->rear=q->front;
    }
    free(DelNode);
    return temp;
}
// 获取队列头部元素 
QDataType QueueFront(Queue* q)
{
	assert(q);
    if(QueueEmpty(q))
        return NULL;
	return q->front->next->data;
}
// 获取队列尾部元素 
QDataType QueueBack(Queue* q)
{
    assert(q);
	if (QueueEmpty(q))
		return NULL;
	return q->rear->data;
}
// 获取队列中有效元素个数 
int QueueSize(Queue* q)
{
	assert(q);
	int count=0;
	QNode* pcurrent = q->front->next;
	while (pcurrent)
	{
		count++;
		pcurrent = pcurrent->next;
	}
	return count;
}
// 检测队列是否为空，如果为空返回非零结果，如果非空返回0 
int QueueEmpty(Queue* q)
{
	assert(q);
	return NULL==q->front->next;
}
// 销毁队列 
void QueueDestroy(Queue* q)
{
	assert(q);
	QNode* pcurrent = q->front;
	while (pcurrent)
	{
		q->front = pcurrent->next;
		free(pcurrent);
		pcurrent = q->front;
	}
	q->rear = NULL;
    free(q);
    q=NULL;
}
//-----------------------------------------------------------------
typedef struct {
    Queue* queue1;
    Queue* queue2;
} MyStack;
/** Initialize your data structure here. */
MyStack* myStackCreate() {
    MyStack *ps=(MyStack*)malloc(sizeof(MyStack));
    ps->queue1=(Queue*)malloc(sizeof(Queue));
    ps->queue2=(Queue*)malloc(sizeof(Queue));
    QueueInit(ps->queue1);
    QueueInit(ps->queue2);    
    return ps;
}
/** Push element x onto stack. */
void myStackPush(MyStack* obj, int x) {
    assert(obj);
    if(!QueueEmpty(obj->queue1))
        QueuePush(obj->queue1,x);
    else
        QueuePush(obj->queue2,x);
}
/** Removes the element on top of the stack and returns that element. */
int myStackPop(MyStack* obj) {
    assert(obj);
    if(!QueueEmpty(obj->queue1))
    {
        while(QueueSize(obj->queue1)>1)
            QueuePush(obj->queue2,QueuePop(obj->queue1));
        return QueuePop(obj->queue1);
    }
    else
    {
        while(QueueSize(obj->queue2)>1)
            QueuePush(obj->queue1,QueuePop(obj->queue2));
        return QueuePop(obj->queue2);
    }
}
/** Get the top element. */
int myStackTop(MyStack* obj) {
    assert(obj);
    int temp;
    if(!QueueEmpty(obj->queue1))
        return QueueBack(obj->queue1);
    else
        return QueueBack(obj->queue2);
}
/** Returns whether the stack is empty. */
bool myStackEmpty(MyStack* obj) {
    assert(obj);
    if(QueueEmpty(obj->queue1)&&QueueEmpty(obj->queue2))
        return true;
    return false;
}

void myStackFree(MyStack* obj) {
    QueueDestroy(obj->queue1);
    QueueDestroy(obj->queue2);
     free(obj);
     obj=NULL;
}

/**
 * Your MyStack struct will be instantiated and called as such:
 * MyStack* obj = myStackCreate();
 * myStackPush(obj, x);
 
 * int param_2 = myStackPop(obj);
 
 * int param_3 = myStackTop(obj);
 
 * bool param_4 = myStackEmpty(obj);
 
 * myStackFree(obj);
*/
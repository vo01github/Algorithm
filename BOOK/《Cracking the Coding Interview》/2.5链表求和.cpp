

// 8.2 链表


// __________________________ 2.5 __________________________
/*
	给定两个用链表表示的整数，每个结点包含一个数位。这些数位是反向存放的，也就是个位排在链表首部。
	编写函数对这两个整数求和，并用链表形式返回结果。

示例
	输入：（7->1->6） + (5->9->2), 即是 617 + 295 = 912
	输出：2->1->9 

进阶：假设这些数位是正向存放的。
	输入：1->2->3->4  ；5->6->7
	输出：既 1234 + 567 。此时 5 应该与 2 对应起来相加。


*/

// __________________________ 解决思路 __________________________
/*
	太简单了，不想写思路了。
	就是练手的题目。
*/

// __________________________ 实现细节 __________________________ 
// 
typedef struct NODE
{
	int				value;
	struct NODE *	next;
}Node,*LinkHead;		// LinkHead 是头指针，*LinkHead 是头结点


/*
下面的代码有点问题：
	1-假设了1>2链表，不应该做这种假设。
	待改进，可以对谁长谁短都不影响。
*/ 
Node* add( Node* numNode1, Node* numNode2 )
{
	// 容错处理
	if( numNode1 == NULL && numNode2 == NULL)

	int sum;
	int oldSum = 0;
	int num1 = 0, num2 = 0;

	
	for(; numNode1!= NULL || numNode2!= NULL; 
		numNode1 = numNode1->next,numNode2 = numNode2->next,num1 = 0;num2 = 0; )
	{
		if(numNode1!= NULL) num1 = numNode1->value;
		if(numNode2!= NULL) num2 = numNode2->value;

		sum = num1 + num2 + oldSum;
		oldSum = sum/10;
		numNode1->value = sum%10;		// 这里是 假设 numNode1 的结点个数 > numNode2
	}
	
	if( oldSum > 0 )
	{
		Node* lastNode = new Node;
		numNode1->next = lastNode;
		lastNode->next = NULL;
		lastNode->value = oldSum;
	}

	return numNode1;

}


// 进阶题目： __________________________ 

// 思路1，先求出 两个链表 的长度，然后对短链表进行补位，全都补0
// 思路2，逆转2个链表。

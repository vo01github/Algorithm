

// 8.2 链表


// __________________________ 2.3 __________________________
/*
	实现一个算法，删除单向链表中间的某个结点，假定你只能访问该结点。
示例
	输入：单向链表 a->b->c->d->e 中的结点c
	结果：不返回任何数据，但该链表变为：a->b->d->e
*/


// __________________________ 解决思路 __________________________
/*	
“节点覆盖”技巧：
	01-访问该节点，
	02-然后 复制 next 节点的值到该节点。
	03-然后 指向 下一个节点，重复 02 步骤 直到走到尾结点时。
	04-删除尾节点。
*/

// __________________________ 实现细节 __________________________
typedef struct NODE
{
	int				value;
	struct NODE *	next;
}Node,*LinkHead;		// LinkHead 是头指针，*LinkHead 是头结点


void freeNode( Node* deleNode)		// free node 
{

	Node* thisNode = deleNode;
	Node* nextNode = thisNode->next;

	thisNode->value = nextNode->value;	// 如果 nextNode == NULL ，那么此题无解，要提出来。
	thisNode->next = nextNode->next;

	// 释放结点内存。
	free(nextNode);
}



// __________________________ 下面是错误的代码，因为我们不知道 LinkHead __________________________
void deleteMidNode( Node* midNode, Node* LinkHead)
{
	Node* thisNode = LinkHead->next ;
	Node* foreNode = thisNode;
	while( thisNode && thisNode != midNode)
	{
		foreNode = thisNode;
		thisNode = thisNode->next;
	}

	if( thisNode == midNode )	// find it 
	{
		foreNode->next = thisNode->next;
		freeNode(thisNode);
	}
}

// 
// 

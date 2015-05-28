

// 8.2 链表


// __________________________ 2.3 __________________________
/*
	实现一个算法，删除单向链表中间的某个结点，假定你只能访问该结点。
*/


typedef struct NODE
{
	int				value;
	struct NODE *	next;
}Node,*LinkHead;		// LinkHead 是头指针，*LinkHead 是头结点


void freeNode( Node* deleNode)		// free node 
{

}


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

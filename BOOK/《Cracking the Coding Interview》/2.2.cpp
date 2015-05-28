

// 8.2 链表


// __________________________ 2.2 __________________________
/*
	实现一个算法，找出单向链表中倒数第k个结点。
*/
typedef struct NODE
{
	int				value;
	struct NODE *	next;
}Node,*LinkHead;		// LinkHead 是头指针，*LinkHead 是头结点

// 链表 头结点+头指针 初始化
LinkHead = (Node *)malloc(sizeof(Node));
assert(LinkHead != NULL,"内存分配失败");
LinkHead->next = NULL;
LinkHead->value = NULL;



Node* findBackNode(int k,Node* LinkHead)
{
	Node* node = LinkHead->next;
	if(!node)return NULL;

	Node* num_k_node = NULL;
	int len = 0;	// 统计经历过 多少个 节点。
	while( node)
	{
		node = node->next;
		++len;
		if (len == k)
		{
			num_k_node = node;
		}else if( len > k){
			num_k_node = num_k_node->next;
		}
	}

	return num_k_node;
}
// 
// 

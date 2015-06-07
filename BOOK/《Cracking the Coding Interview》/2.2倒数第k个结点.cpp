

// 8.2 链表


// __________________________ 2.2 __________________________
/*
	实现一个算法，找出单向链表中倒数第k个结点。
*/

// __________________________ 解决思路 __________________________
/*
思路1：	使用“双指针”技巧：
	01-A指针先走，B指针不动，
	02-等A指针往前走了k步后，B指针指向第1个结点。
	03-B指针和A指针 一起每次移动一步，直到B指针走到尾节点，A指针指向的结点 就是倒数第K个结点。


// 书上居然 先讲了3个比较笨的方法，才讲双指针法。	
*/




// __________________________ 实现细节 __________________________

//思路1：	使用“双指针”技巧 __________________________
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

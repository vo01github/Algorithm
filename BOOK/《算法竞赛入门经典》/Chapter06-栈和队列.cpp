

//#include "Chapter06.h"


// 第06章 栈和队列
/*
	线性结构看似简单，却是重要的算法和数据结构的基础。例如，环状结构也经常转化为线性结构————只需要从某个元素处把环切断，就变成了链。
*/

// __________________________6.1 栈和队列__________________________
// 6.1.1 卡片游戏
/*
	桌上有一叠牌，从第一张牌开始从上往下依次编号为 1~n.当至少还剩两张牌时进行以下操作：
	把第一张牌扔掉，然后把新的第一张放到整叠牌的最后。
	输入n,输出每次扔掉的牌，以及最后剩下的牌。
	样例输入：7 
	样例输出：1 3 5 7 4 2 6
*/

/*
	这些牌像不像是在排队？每次从排头拿到两个，其中第二个再次排到尾部。我们把这种数据结构称为队列（queue）.
	或者说得更加学术一点：FIFO表。其中FIFO表示先进先出（First In,First Out）,符合我们在日常生活中的排队。
	用一个数组 queue 来实现这个队列，再设两个指针 front 和 rear .
*/

const int MAXN = 50;
int queue[MAXN];

int max_num;

cin>>max_num;

for (int i = 0; i<max_num;i++) queue[i] = i+1;	// 初始化卡牌

int front	= 0;
int end		= max_num;

while ( front<end  )
{
	printf( "%d ",queue[front++] );
	queue[end++] = queue[front++];
}

printf( "/n " );
printf( "%d ",end );

/* 尽管运行没错,但是这个程序其实是有BUG的：如果在最后把 end 的值 打印出来，你会发现 end 的值可能比 MAXN 大
	换句话说，在程序运行的后期， 读写了非法内存。读写非法内存不一定会引起程序崩溃，但肯定不行的啦。
	我们要么把数组空间开大些，要么采取一种称为 循环队列的技术，重用 已出对元素占用的空间。
	C++提供了一种更加简单的处理方式——STL 队列
#include<queue>
using namespace std;	
*/

queue<int> q;

int max_num;
cin>>max_num;

for (int i = 0; i<max_num;i++) q.push(i+1);	// 初始化卡牌

while (!q.empty())
{
	printf("%d ",q.front());				// 打印队首元素
	q.pop();								// 抛弃队首元素
	
	if ( q.empty() )break;

	q.push(q.front());						// 把队首元素加入队尾
	q.pop();								// 抛弃队首元素
}

/*
	程序并没有简洁很多，但可读性大大增强了。首先，不需要事先知道n的大小；其次，可以少用2个变量。
*/

// 6.1.2 铁轨 [P106/241]
/*	
	某城市有一个火车站，铁轨铺设如下图所示。有n节车厢从A方向驶入车站，按进站顺序编号为1~n.
	你的任务是让它们按照某种特定顺序进入B方向的铁轨并驶出车站。
	换句话说，在任意时刻，只有两种选择：A->C 和 C->B	
*/

/*
	分析：在中转站C中，车厢符合后进先出的原则，称为LIFO表。其中 LIFO代表 Last In First Out
	它还有一个更常用的名称————栈。由于只有一端生长，实现栈时只需要一个数组stack和栈顶指针（始终指向栈顶元素）。

	没看懂这到题的样例输出，好奇怪。反正能理解 栈 就可以了。
*/




// __________________________6.2 链表__________________________
/*
	在多数情况下，线性表都可以用数组轻松实现，但事情并不总是这么简单。本节介绍链表，并用它和数组进行比较。
*/ 


// 6.2.1 初步分析
/*
	例题：6-1 移动小球	【P109/241】
	你有一些小球，从左到右依次编号为1,2,3,...,n, 如下图所示

	然后题主 用 数组实现了一遍 这到题的大概，最后得出结论，如果是数组的话，
	把元素从最左边移动到最右边，则中间的所有元素都会全部移动一下，非常浪费时间。
*/


// 6.2.2 链式结构
/*
	第2种方法是强调小球之间的相对顺序，而非绝对顺序。我们用left[i]和right[i]分别表示
	编号为 i 的小球左边和右边的小球编号（如果是0，表示不存在）。则移动过程可以分成两个步骤：
	把X移出序列；把X重新插入序列。
*/



// 6.2.3 对比测试
/*
	如何进行对比测试呢？首先需要数据，而且是大量数据。为此，需要编写数据生成器。
*/

#include<stdlib.h>	// rand()和srand()需要	
#include<time.h>	// time()需要
srand(time(NULL));	// 初始化随机数种子，只初始化一次

int random = rand()%2;
/*
	核心函数是 stdlib.h 中的 rand()，它生成一个闭区间[0,RAND_MAX]的均匀随机整数
	（均匀的含义是：该区间内每个整数被产生的概率相同）
*/


// 6.2.4 随机数发生器
/*
	
*/	

// __________________________6.3 二叉树__________________________	
/*
	二叉树 的递归定义如下：二叉树要么为空，要么由根结点(root),左子树(left subtree) 和 右子树(right subtree)组成，
	而左子树和右子树分别是一棵二叉树。
	注意，在计算机中，树一般是“倒置”的————根在上，叶子在下。
*/

// 6.3.1 小球下落[P114/241]
/*
	有一棵二叉树，最大深度为D，且所有叶子的深度都相同。所有结点从上到下从左到右编号为1,2,3。。。
	在结点1处放一个小球，它会往下落，每个内结点上都有一个开关，初始全部关闭，当每次有小球落到一个开关时，它的状态都会改变。
	当小球到达一个内结点时，如果该结点上的开关关闭，则往左走，否则往右走，直到走到叶子结点。

	一些小球从结点1处依次开始下落，最后一个小球将会落到哪里呢？输入叶子深度D和小球个数I,输出第I个小球最后所在的叶子编号。
	假设I不超过整棵树的叶子个数。
	D<=20;
	I<=20^2-1;
*/	

/*
	分析，不难发现：对于一个结点k,它的左儿子，右儿子的编号分别是2k和2k+1。

	题中题-01：证明上面这个论点： 对于一个结点k,它的左儿子，右儿子的编号分别是2k和2k+1。
	提示-01 先证明出最左边的那个节点，这样这个节点的右边所有节点都可以不用证明了，显而易见的规律。
	提示-02 观察最左边的节点的规律，可以发现这个现象：最左节点的编号都是 当前行 节点的个数。
	提示-03 我们现在需要证明的是：最左节点的编号都是 当前行 节点的个数。
	提示-04 最左边节点的编号 = 前面 所有节点数总和 + 1
	提示-05	 2^2 = 2^(1) +  2^(0) + 1;
			 2^3 = 2^2 + 2^(1) +  2^(0) + 1;
			 2^n = 2^(n-1) + 2^(n-2) + 2^(n-3) + ... +  2^(0) + 1;
	提示-06 然后上面这个等式 很容易 证明的吧。
*/

int max_num,deph;

const long MAXN = 6000;
int tree[MAXN];

enum{
	close,
	open
};

int whcihNode,nextNode;

while (true)
{
	cin>>deph;
	cin>>max_num;

	// 初始化小球开关
	for ( int i = 0; i<MAXN; i++) tree[i] = close;

	for (int num = 0; num<max_num; num++)
	{
		nextNode = 1;
		for (int i = 0;i<deph;i++ )
		{
			whcihNode = nextNode;
			if ( tree[whcihNode] == close)
			{
				tree[whcihNode] = open;
				nextNode = whcihNode*2;
			}else if ( tree[whcihNode] == open )
			{
				tree[whcihNode] = close;
				nextNode = whcihNode*2 + 1;
			}
		}
	}

	printf("%d ", whcihNode );	
	printf( "/n " );
}

/*
	分析：上面运算量太大。看如何改进在算法层面。

	采用分流分析法来做：
	比如节点1，总共会经过 max_num 次小球。那么第 max_num 个小球经过时，开关状态为 (max_num-1)%2
	这时就会来到节点2，节点2总共会经过多少小球呢？  max_num/2 + max_num%2
	这样依次可以推理到 最底层树的 节点。
*/


int max_num,deph;

enum{
	close,
	open
};

int lastMaxNum;		// 上次经历过过多少小球
int lastStage;		// 上次开关最后的状态
int nowNode,nextNode;


while (true)
{
	cin>>deph;
	cin>>max_num;

	lastMaxNum	= max_num - 1;
	lastStage	= close;
	nextNode	= 1;
	for (int i = 0;i<deph;i++ )
	{
		nowNode = nextNode;
		lastStage = (lastMaxNum)%2;
		if ( lastStage == close )
		{
			nextNode = nowNode*2;
			lastMaxNum = lastMaxNum/2 + lastMaxNum%2;
		}else if ( lastStage == open )
		{
			nextNode = nowNode*2 + 1;
			lastMaxNum = lastMaxNum/2;
		}
		
	}

	printf("%d\n", nowNode);
}


// 6.3.2 层次遍历[p101(116/241)]
/*	
	输入一棵二叉树，你的任务是按从上到下，从左到右的顺序输出各个结点的值。每个结点都按照从根结点到它的移动序列给出(L表示左，R表示右)。
	在输入中，每个结点的左括号和右括号之间没有空格，相邻结点之间用一个空格隔开。每棵树的输入用一对空括号()结束
	注意，如果从根到某个叶结点的路径上有的结点没有在输入中给出，或者给出了超过一次，应当输出为-1.结点个数不超过256.

样例输入：(11,LL)(7,LLL)(8,R)(5,)(4,L)(13,RL)(2,LLR)(1,RRR)(4,RR)()
		  (3,L)(4,R)()
样例输出：5 4 8 11 13 4 7 2 1
		 -1	
*/	

// 下面的代码，没有实际运行过，因为这个输入函数太麻烦了。
typedef struct Tnode
{
	int have_value;			// 是否赋过值
	int v;					// 节点存储的值
	struct Tnode *left;
	struct Tnode *left;

}Node;

Node *root;					// 二叉树的 根节点

// 把申请新节点的操作封装到 newnode 函数中：
Node* newnode()
{
	Node* u = (Node *) malloc(sizeof(Node));
	if (u != NULL)
	{
		u->have_value = 0;
		u->left = u->right = NULL;
	}
	return u;
};

// 在 read_input 中调用的 addnode 函数。它按照移动序列行走，目标不存在时调用 newnode 来创建新节点。
void addnode(int v,char* s)
{
	int n = strlen(s);
	Node* u = root;
	for (int i = 0;i<n;i++)
	{
		if ( s[i] == 'L' )
		{
			if (u->left == NULL)u->left = newnode();	// 节点不存在，建立新节点
			u = u->left;
		}else if ( s[i] == 'R' )
		{
			if (u->left == NULL)u->right = newnode();	// 节点不存在，建立新节点
			u = u->right;
		}
	}
	if (u->have_value)FAILED = 1;
	u->v = v;
	u->have_value = 1;
}

// 按照层次顺序遍历这棵树。我们使用一个序列来完成这个任务，初始时只有一个根节点，然后每次取出一个节点，就把它的左右儿子(如果有)放进队列。
int n = 0,ans[MAXN];
queue<Node*> q;
int bfs()
{
	q.push(root)
	while ( !q.empty() )
	{
		Node* u = q.front();
		if (!u->have_value)return 0;
		
		ans[n++] = u->v;
		if(u->left != NULL)q.push(u->left);
		if(u->right!= NULL)q.push(u->right);
		q.pop();
	}
	return 1;
}
/*
	这样遍历二叉树的方法称为宽度优先遍历(Breadth-First Search,BFS)。
	后面我们将看到，BFS在显示图和隐式图算法中扮演着重要的角色。
*/

// 释放一棵二叉树的代码，以免内存泄露。
void remove_tree(Node* u)
{
	if ( u == NULL )return;
	remove_tree(u->left);
	remove_tree(u->right);
	free(u);
}



// 6.3.3 二叉树重建[p105(120/241)]
/*
	对于二叉树T，可以递归定义它的前序遍历，中序遍历 和 后序遍历 如下：

	首先，我们看看 前序，中序，后序遍历的特性：
前序遍历：
	1.访问根节点
	2.前序遍历左子树
	3.前序遍历右子树
中序遍历：
	1.中序遍历左子树
	2.访问根节点
	3.中序遍历右子树
后序遍历：
	1.后序遍历左子树
	2.后序遍历右子树
	3.访问根节点
*/

/*
	输入一棵二叉树的前序遍历和中序遍历序列，输出它的后序遍历序列
样例输入：
	DBACEGF ABCDEFG
	BCAD CBAD
样例输出：
	ACBFGED
	CDAB	
*/

/*
	分析：前序遍历第1个访问的就是根节点，因此只需在中序遍历中找到它，就知道左右子树的前序遍历和后序遍历了。
	这样，可以编写一个递归程序：
	它的作用是根据一个长度为 n 的前序序列 s1 和中序序列 s2,构造一个长度为n的后序序列。
*/

void build(int n,char* s1,char* s2,char* s)
{
	if(n<=0)return;
	int p = strchr(s2,s1[0]) - s2;
	build(p,s1+1,s2,s);
	build(n-p-1,s1+p+1,s2+p+1,s+p);
	s[n-1] = s1[0];
}	

while( scanf("%s%s",s1,s2) == 2 )
{
	int n = strlen(s1);
	build(n,s1,s2,ans);
	ans[n]='\0';
	printf("%s\n",ans);
}


// __________________________6.4 图__________________________

// 6.4.1 黑白图像[p107(122/241)]
/*
	输入一个n*n的黑白图像(1表示黑色，0表示白色)，任务是统计其中八连块的个数。
	如果两个黑格子有公共边或者公共顶点，就说它们属于同一个八连块。
	如图6-11所示的图形有3个八连块。

分析：  用递归求解：从每个黑格子除非，递归访问它所有的相邻黑格。
		类似 扫雷 那个游戏。以后有空再来自己敲代码，很类似的。
*/
int mat[MAXN][MAXN],vis[MAXN][MAXN];
void dfs(int x,int y)
{
	if(!mat[x][y] || vis[x][y])return;

	vis[x][y] = 1;
	for(int i = -1;i<2;i++)		// 递归访问周围8个格子+自己。
	{
		for(int j = -1;j<2;j++)
		{
			dfs(x+i,y+j);
		}
	}
}

// 这个程序在哪里判断出界的？在输入之前，在迷宫的外面加上一圈虚拟的白格子
memset(mat,0,sizeof(mat));		// 所有格子都初始化为白色，包括周围一圈的虚拟格子
memset(vis,0,sizeof(vis));		// 所有格子都没有访问过

for(int i = 0; i<n; i++)
{
	scanf("%s",s);
	for(int j = 0; j<n; j++)
	{
		mat[i+1][j+1] = s[j] - '0';		// 把图像往中间移动一点，空出一圈白格子
	}	// 上面这行，没看懂，如何空出一圈白格子。
}

// 接下来只需要不断找黑格，然后调用dfs，从它出发寻找八连块：
int count = 0;
for(int i = 1; i<=n; i++)
{
	for(int j = 1; j<=n; j++)
	{
		if(!vis[i][j] && mat[i][j])
		{
			count++;
			dfs(i,j);
		}
	}
}
printf("%d\n",count);

/*
	为什么函数名为 dfs 呢？可能读者已经猜到了：它是宽度优先遍历(BFS)的孪生兄弟——深度优先遍历(DFS).
	DFS 和 BFS 一样，都是从一个结点出发，按照某种特定的次序访问图中的其他结点。不同的是，BFS使用队列来存放待扩展结点，
	而DFS使用的是栈。等一等！好像上面的程序没有栈啊？尽管没有用STL栈，也没有stack数组和top指针，但递归调用时会把局部变量(当前结点编号)
	存入栈帧中。这也提醒我们：如果图像太大，递归方式的DFS有栈溢出的危险！为了保险起见，
	可以用显式栈来代替递归调用，程序留给读者编写（提示：可以把BFS程序中的队列直接改成栈）。

	仔细参考下面这几篇文章：
	《如何利用循环代替递归以防止栈溢出》
	《该如何将任意形式的递归化解为栈处理》
	递归的效率有时候比较低，这样就可以用栈或循环来代替递归了。
*/

// 下面是我自己写的
void bfs(int x,int y)
{
	if(!mat[x][y] || vis[x][y])return;

	typedef struct Tnode
	{
		int x,y;				// 节点所代表的坐标
	}Node;

	Node root;
	root.x = x;
	root.x = y;	
	vis[x][y] = 1;

	queue<Node> q;
	q.push(root)

	while ( !q.empty() )
	{
		Node  now = q.front();
		for(int i = -1;i<2;i++)		// 循环访问周围8个格子+自己。
		{
			for(int j = -1;j<2;j++)
			{
				int newx = now.x+i;
				int newy = now.y+j;
				if( mat[newx][newy] && (!vis[newx][newy]) )
				{
					Node round;
					round.x = newy;
					round.x = newy;
					q.push(round);
				}
			}
		}
		vis[now.x][now.y] = 1;
		q.pop();
	}
}

// 6.4.2 走迷宫【P108(123/241)】
/*
	一个网格迷宫由n行m列的单元格组成，每个单元格要么是空地(用1来表示)，要么是障碍物(用0来表示)。
	你的任务是找一条从起点到终点的最短移动序列，其中UDLR分别表示往上，下，左，右移动到相邻单元格。
	任何时候都不能在障碍格中，也不能走到迷宫之外。起点和终点保证是空地。n,m<=100。

分析：	还记得二叉树的BFS吗？结点的访问顺序恰好是他们到根结点距离从小到大的顺序。
	类似地，也可以用BFS来按照到起点的距离顺序遍历迷宫图。
	举个例子：假定起点在左上角，我们就从左上角开始用BFS遍历迷宫图，逐步计算出它到每个结点的最短路距离(图6-12（a）)，
	以及这些最短路径上每个结点的“前一个结点”(图6-12（b）)。

注意，如果把图 (图6-12（b）) 中的箭头理解成“指向父亲的指针”，那么迷宫中的格子就变成了一棵树————除了起点之外，
每个结点恰好有一个父亲。

图的BFS几乎与二叉树的BFS一样，但需要避免重复访问一个结点。下面的代码用标记vis[x][y]记录格子(x,y)是否被走过，和DFS一样。
*/

// 这下面写的啥？？？！
int q[MAXN*MAXN];
void bfs(int x,int y)
{
	int front = 0;rear= 0, d, u;
	u = x*m+y;

}

// 6.4.3 拓(tuo)扑(pu)序列【P111(126/241)】
/*
	假设有n个变量，还有m个二元组(u,v),分别表示 变量u小于v.那么，所有变量从小到大排列起来应该是什么样子的呢？
	例如有4个变量a,b,c,d,若已知a<b,c<b,d<c,则这4个变量的排序可能是a<d<c<b。尽管还有其他可能（如d<a<c<b），
	你只需找出其中一个即可。
分析：
	把每个变量看成一个点，“小于”关系看成有向边，则我们得到了一个有向图。这样，我们的任务实际上是把一个图的所有结点排序，
	使得每一条有向边(u,v)对应的u都排在v的前面。在图论中，这个问题称为拓扑排序（topological sort）.
	不难发现：如果图中存在有向环，则不存在拓扑排序，反之则存在。我们把不包含有向环的有向图称为有向无环图。
	可以借助dfs函数完成拓扑排序：在访问完一个结点之后把它加到当前拓扑排序的首部（想一想，为什么不是尾部）。

	【下面的代码写的啥，跟狗屎似的，是给人看的么。】
*/

int c[MAXN];
int topo[MAXN],t;

bool dfs(int u)
{
	c[u] = -1;
	for(int v = 0; v<n; v++)
	{
		if(G[u][v])
		{
			if(c[v]<0)
			{
				return false;		// 存在有向环，失败退出
			}else if(!c[v] && !dfs(v)) {
				return false;
			}
		}	
	}
	c[u] = 1; topo[--t] = u;
	return true;
}	

bool toposort()
{
	t = n;
	memset(c,0,sizeof(c));
	for(int u = 0; u<n; u++)
	{
		if(!c[u])
		{
			if(!dfs(u))return false;	// dfs()返回 false 说明	1-存在有向环，或者2- 	失败退出
		}
	}	
	return true;
}

/*
	这里用到了一个c数组，c[u]=0表示从来没有访问过（从来没有调用过dfs(u)）;
	c[u] = 1 表示已经访问过，并且还递归访问过它的所有子孙（即dfs(u)曾被调用过，并已返回）;
	c[u]=-1 表示正在访问（即递归调用dfs(u) 正在栈帧中，尚未返回）。
*/


// 6.4.4 欧拉回路【P112(127/241)】
/*
	有一条名为 Pregel 的河流经过 Konigsberg 城。城中有7座桥，把河中的两个岛屿河岸连接起来。当地居民热衷于一个难题：
	是否存在一条线路，可以不重复地走遍7座桥。这就是著名的七桥问题。它由大数学家欧拉首先提出，并给出了完美的解答，如下图所示。

	把七桥问题用图论的语言改写成图，则问题变成了：能否从无向图中的一个结点出发走出一条道路，每条边恰好经过一次。这样的路线称为
	欧拉道路，也可以形象地称为“一笔画”。

	可以得知：在欧拉道路中，每经过一个结点，则就会走过连接到该结点的2条道路，一条进，一条出。则除了起点和终点外，
	其他点的连接到道路的个数应该是偶数。

	在七桥问题中，所有4个点的度数均是奇数(这样的点也称【奇点】)，因此不可能存在欧拉道路。

	在一个无向图连通图中，如果只有2个奇点，则必须从一个奇点出发，另一个奇点终止；
	如果奇点不存在，则可以从任意点出发，最终一点会回到该点（称为欧拉回路）
*/
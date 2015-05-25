

//#include "Chapter03.h"


// 第03章 数组和字符串


// __________________________3.1 数组__________________________

/*
	提示3-3：比较大的数组应尽量声明在main函数外。
	放在外面时，数组是静态的，才可以开得很大，如果内存放不下，甚至编译的时候就编译不通过【嵌入式系统】；
	放在main函数内时，数组是存放在堆/栈中的？数组稍大就会异常退出。
*/

// 如果要从数组a复制k个元素到数组b,可以这样做：
#include "string.h"	
memcpy(b,a,sizeof(int)*k);

// 如果需要把数组a全部复制到数组b中，可以写得简单一些:
memcpy(b,a,sizeof(a));

/*
	例题：3-1 开灯问题
	有n盏灯，编号为1~n.第1个人把所有灯打开，第2个人按下所有编号为2的倍数的开关(这些灯将被关掉)，
	第3个人按下所有编号为3的倍数的开关(其中关掉的灯将被打开，开着的灯将被关闭)，依次类推。
	一共有k个人，问最后有哪些灯开着？输入：n和k,输出开着的灯编号。k<=n<=1000
	样例输入：7 3
	样例输出：1 5 6 7
*/
// 程序3-2 开灯问题
#define max 1000
#define LightOn		1
#define LightOff	0

	int light[max];

	int n,k;

	for ( ;1;)		// 可以循环玩这道题目输出了。
	{
		cin>>n;
		cin>>k;

		// 待加 输入范围检测处理   1<k<=n<=max

		//作用是把数组 light清0，
		memset(light,LightOff,sizeof(light));	

		for ( int man = 1; man<=k; man++ )
		{
			for ( int i = 1; i*man<=n; i++)
			{
				int which = i*man;
				light[which] = !light[which];
			}
		}

		// 输出结果
		for ( int i = 1;i<=n;i++ )
		{
			if ( light[i] == LightOn )printf("%d ",i);
		}
		printf("\n");

	}
	//样例输入：100 100
	//样例输出：1 4 9 16 25 36 49 63 81	100	
	//【当输入值为 n,n时，约数个数为奇数的就会被点亮了，或者说是某个数的2次方就会被点亮了】




/*
	例题：3-2 蛇形填数
	在 n*n 方阵里填入1,2,...,n*n,要求填成蛇形。
	下面的方阵中，多余的空格只是为了便于观察规律，不必严格输出。n<=8.	 
	样例输入：4
	样例输出：
	10  11 	12 	1
	9	16	13	2
	8 	15	14	3
	7	6 	5	4
*/


enum DIRECTION_COL{
	COL_UP		= -1,		// 蛇头向上走
	COL_STAY	= 0,		// 蛇头竖直方向不动
	COL_DOWN	= 1,		// 蛇头向下走
};

enum DIRECTION_ROW{
	ROW_LEFT	= -1,		// 蛇头向左走
	ROW_STAY	= 0,		// 蛇头水平方向不动
	ROW_RIGHT	= 1,		// 蛇头向右走	
};
	
	
#define max 12
	int crawl[max][max];
	

while(1)
{
	memset(crawl,0,sizeof(crawl));		// 初始化数组，为0

	int max_line = 0;
	cin>>max_line;
	int col = 0,row = max_line - 1;							// 设置填入的 sneak 的第一个位置
	int colChange = COL_DOWN ,rowChange = ROW_STAY ;		// 设置的 sneak 的初始前进方向

	for (int i =1; i<=max_line*max_line; i++)
	{
		crawl[col][row] = i;
		int colNext = col + colChange ;
		int rowNext = row + rowChange ;

		if ( !((colNext == max_line)||(rowNext == max_line)||(colNext == -1)||(rowNext == -1)) )	//数组没有越界
		{
			if ( crawl[colNext][rowNext] == 0 )		// 没有已经赋值。
			{
				col = colNext;
				row = rowNext;
				continue;	//不执行换方向的动作
			}
		}

		// 执行换方向的动作。
		if ( colChange == COL_DOWN )
		{
			colChange = COL_STAY;
			rowChange = ROW_LEFT;
		}else if ( colChange == COL_UP )
		{
			colChange = COL_STAY;
			rowChange = ROW_RIGHT;
		}else if ( rowChange == ROW_LEFT )
		{
			colChange = COL_UP;
			rowChange = ROW_STAY;
		}else if ( rowChange == ROW_RIGHT )
		{
			colChange = COL_DOWN;
			rowChange = ROW_STAY;
		}

		col += colChange ;
		row += rowChange ;
	}

	// 打印 sneak matrix
	for ( int i = 0; i<max_line; i++ )
	{
		for ( int j = 0; j<max_line; j++ )
		{
			int m = crawl[i][j];
			printf("%d ",m);
			if(m<10)printf(" ");	//个位数，比10位数，都补一个空格。
		}
		printf("\n");
	}
	printf("\n");
}




// __________________________3.2 字符数组__________________________

/*
	例题 3-3 竖式问题
	这道题目，我完全看不懂在说什么，是我语文水平太烂了么
*/ 


// __________________________3.3 最长回文子串__________________________
/*
	例题 3-4 回文串
	输入一个字符串，求出其中最长的回文串。子串的含义是：在原串中连续出现的字符串片段。
	回文的含义是：正着看和倒着相同，如 abba 和 yyxyy。在判断时，应该忽略所有标点符号和空格，且忽略大小写，
	但输出应保持原样(在回文串的首部和尾部不要输出多余字符)。输入字符串长度不超过5000，且占据单独的一行。应该输出最长的回文串，
	如果有多个，输出起始位置最靠左的。
*/ 

// 程序3-5 最长回文子串


#define MAXN 5000
char buf[MAXN],s[MAXN];

int n,m = 0,max = 0;
int i,j,k;

fgets(buf,sizeof(s),stdin);
n = strlen(buf);

// isalpha()	用于判断字符是否为大写字母或小写字母
// toupper(c)	返回c的大写形式。  
for ( i = 0; i<n; i++)
{
	if(isalpha(buf[i])) s[m++] = toupper(buf[i]);
}

for ( i = 0; i<m; i++)
{
	for ( j = i; j<m; j++)
	{
		int ok = 1;
		for ( k = i;k<=j; k++ )
		{
			if( s[k] != s[i+j-k]) ok = 0;
		}
		if ( ok && j-i+1 > max) max = j-i+1;

	}
}

printf("max = %d\n",max);

/*
	还有第2种修改版来显示。这个写的可读性 也太差了吧。
	P45(60/241)
*/


// __________________________3.4 小结与习题__________________________

// 3.4.1 必要的存储量


// 3.4.3 补码表示法


// 3.4.4 重新实现库函数


// 3.4.5 字符串处理的常见问题


// 3.4.6 关于输入输出


// 3.4.7 I/O的效率

// 3.4.8 小结
	





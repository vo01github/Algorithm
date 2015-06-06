

// 数组与字符串


// __________________________ 1.4 __________________________
/*
	编写一个方法，将字符串中的空格全部替换为“%20”。假定该字符串尾部有足够的空间存放新增字符，并且知道字符串的“真实”长度
*/


// __________________________ 解决思路 __________________________
/*
解法01：	用队列来实现，
	01-遇到空格后，就往队列里压入 3个元素，%20。
	02-队列非空时，把当前字符压入队列，然后从队首弹出一个元素，写入当前位置字符处。
	03-最后在末尾加入
	复杂度：1个for循环，用到一个额外的数据结构 队列	

解法02：	从后往前遍历	
	01-先遍历一遍算出有多少个空格
	02-再从后往前遍历写原来的字符串
	复杂度：2个for循环，不用额外开辟内存。

对比：一个速度快，但占用空间可能会多一点。
	  一个速度慢点，但是不占用额外的任何空间。

解法03：使用 string 的 replace 

现实中实际用处：
	就是URL 中的空格需要替换成 %20
*/



// __________________________ 实现细节 __________________________	

// 解法01：用队列__________________________	
#include<queue>

char * insertString( char * str )
{
	// 容错处理
	if( str == NULL )return NULL;
	int len = strlen(str);
	if( len == 0 )return NULL;

	queue<char> q_insert;

	int num_gap = 0;
	for(int i = 0; i<len || ( !q_insert.empty() ); ++i)
	{
		if( str[i] == ' ')
		{
			q_insert.push('%');
			q_insert.push('2');
			q_insert.push('0');
		}

		if ( !q_insert.empty() )
		{
			q_insert.push(str[i]);
			str[i] = q_insert.front();
			q_insert.pop();
			++num_gap;
		}
	}

	str[len + 2*num_gap] = '\0';		// 加入末元素
	return str;
}


// 解法02：从后往前遍历 替换__________________________	
char * repalceString( char * str )
{
	// 容错处理
	if( str == NULL )return NULL;
	int len = strlen(str);
	if( len == 0 )return NULL;

	int gap = 0;
	for(int i = 0; i < len; ++i)
	{
		if( str[i] == ' ') ++gap;
	}

	if( 0 == gap)return str;

	int newlen = len + 2*gap;
	str[newlen] = '\0';
	for(int i = len-1; i>0; --i)
	{
		if(str[i] == ' ')
		{
			str[--newlen] = '0';
			str[--newlen] = '2';
			str[--newlen] = '%';
		}else{
			str[--newlen] = str[i];
		}
	}

	return str;
}

// 解法03：使用 string.replace()__________________________	
void repalce_space( string& str,string& insert )
{
	int pos;
	while( (pos = str.find(' '))  != -1)
	{
		str.replace(pos, 1, insert);
	}

}

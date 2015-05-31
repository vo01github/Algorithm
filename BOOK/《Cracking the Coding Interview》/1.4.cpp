

// 数组与字符串


// __________________________ 1.4 __________________________
/*
	编写一个方法，将字符串中的空格全部替换为“%20”。假定该字符串尾部有足够的空间存放新增字符，并且知道字符串的“真实”长度
*/


// __________________________ 解决思路 __________________________
/*
	用队列来实现，
	01-遇到空格后，就往队列里压入 3个元素，%20。
	02-队列非空时，把当前字符压入队列，然后从队首弹出一个元素，写入当前位置字符处。
	03-最后在末尾加入
*/



// __________________________ 实现细节 __________________________	
#include<queue>

void insertString(char * str，int len)
{
	queue<char> q_insert;

	// int len = strlen(str); // 不能用这个求长度，因为“该字符串尾部有足够的空间存放新增字符”
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

	str[len + 3*num_gap] = '\0';		// 加入末元素
}
// 
// 

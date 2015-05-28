

// 数组与字符串


// __________________________ 1.2 __________________________
/*
	用C或C++ 实现 void reverse(char* str)函数，既反转一个null结尾的字符串。
*/

void swap( char &a, char &b)
{
	char c = a;
	a = b;
	b = c;
}

// 计算字符串长度的版本
void reverse1( char* str )
{
	int len = strlen(str);
 	for(int i = 0; i < len/2 ; ++i)
 	{
 		swap( str[i],str[len-1-i] );
 	}
}

// 不计算字符串长度的版本
void reverse2( char* str)
{
	char *p = str,*q = str;
	while(*p)
	{
		++p;
	}
	--p;

	while( q < p )
	{
		swap(*q++,*p--);
	}
}

// 
// 

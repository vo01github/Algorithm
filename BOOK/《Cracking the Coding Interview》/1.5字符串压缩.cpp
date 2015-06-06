

// 数组与字符串


// __________________________ 1.5 __________________________
/*
	利用字符串重复出现的次数，编写一个方法，实现基本的字符串压缩功能。
	比如，字符串“aabcccaaa” 会变为 “a2b1c3a3”.若压缩后的字符串没有变短，
	则返回原先的字符串。
*/

// __________________________ 解决思路 __________________________
/*
	思路01：创建一个新的 string ，像队列一样对它进行操作，不停的从尾部 压入就好了。
	改进：要加 一个 能预先判断 是否要压缩的函数 就好了。
*/ 


// __________________________ 实现细节 __________________________	
/*

*/ 
// 第1种方案：使用 string __________________________
// 总感觉下面的代码写的 好丑啊！
string compress( string & str )	
{
	if(str.length() < 2)return str;

	string q_insert = "";
	int repeatNum = 1;

	for( int i = 1; i<str.length(); ++i )
	{
		if(str[i] == str[i-1])
		{
			++repeatNum;
		}else{
			q_insert.push(str[i-1]);		// 压入old元素

			// 数字 转 字符串
			char num[10];
			sprintf(num,"%d",repeatNum);

			int j = 0;
			while(num[j] != '\0')		// 或者写成 while(num[j++] != 0 )	
			{
				q_insert.push(num[j++]);
			}

			repeatNum = 1;
		}
	}

	// 要把最后一个 元素压入
	q_insert.push(str[str.length()-1]);
	// 数字 转 字符串
	char num[10];
	sprintf(num,"%d",repeatNum);
	int j = 0;
	while(num[j] != '\0')		// 或者写成 while(num[j++] != 0 )	
	{
		q_insert.push(num[j++]);
	}

	// 最后进行对比
	if( str.length() <= q_insert.size() )
	{
		return str;
	}else{
		return q_insert;
	}
}
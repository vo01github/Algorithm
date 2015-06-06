

// 数组与字符串


// __________________________ 1.1 __________________________
/*
	实现一个算法，确定一个字符串的所有字符是否全都不同。
	假使不允许使用额外的数据结构，又该如何处理？
*/



// __________________________ 解决思路 __________________________
/*
01 假定是 ASCII 编码，而不是UTF-8编码
	用bool数组[256]协助判断	

02 可以将字符串中的 每一个字符 与 其余字符进行比较。
	时间复杂度O(n^2), 空间复杂度：O(1)

03 如果允许修改字符串的话，对字符串先进行排序【时间花费大概是 O(n*log(n)) 】，
	然后在线性检查相邻字符串中是否有完全相同的字符。
*/ 



// __________________________ 实现细节 __________________________	

// 第1种方案：用额外数组__________________________
bool confirm1(const std::string & strOrc)
{
	if( strOrc.length()>256 )return false;	// 大于 Anscii 编码 最大数量了

	bool strHas[256];	
	memset(strHas, 0, sizeof(strHas));		

	for (int i = 0; i < strOrc.length() ; ++i)
	{
		int j = (int)strOrc[i];
		if( strHas[j] )return false;
		strHas[j] = true;
	}

	return true;
} 

/*
	时间复杂度：O(n)
	空间复杂度：O(1)
*/



// 第3种方案：用排序__________________________
bool confirm3( std::string & strOrc )
{
	// 容错处理
	if( strOrc.length() < 2 )return true;	

	if( strOrc.length()>256 )return false;	// 大于 Anscii 编码 最大数量了

	std::string str = strOrc;				// 如果允许对原字符串排序，就不用这个了。
	sort(str,str + str.length());

	for(int i = 1; i<str.length() ;++i)		// 从第2个元素开始
	{
		if (str[i] == str[i-1])		
		{
			return false;
		}
	}

	return true;
}


// 数组与字符串


// __________________________ 1.1 __________________________
/*
	实现一个算法，确定一个字符串的所有字符是否全都不同。假使不允许使用额外的数据结构，又该如何处理？
*/


// 假定是 Anscii 编码，而不是UTF-8编码


// 第1种方案-用255个bool值数组协助判断	
// 待 上机输入 验证 
bool confirm(std::string & strOrc)
{
	int length = strOrc.strlen()
	if(length>255)
	{
		return false;	// 大于 Anscii 编码 最大数量了
	}

	bool strHas[255];	// 统计 bool 值的
	char strdd[255];

	sprintf(strdd,%s,strOrc.c_str())
	for (int i = 0; i < length; ++i)
	{
		int j = (int )strdd[i];
		if( strHas[j] == true  )
		{
			return false;
		}
	}

	return true;
} 

/*
	时间复杂度：O(n)
	空间复杂度：O(n)
*/
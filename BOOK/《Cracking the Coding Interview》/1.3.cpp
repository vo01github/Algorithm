

// 


// __________________________ 1.3 __________________________
/*
	给定两个字符串，请编写程序，确定其中一个字符串的字符重新排列后，能否变成另一个字符串。
*/

// if is ANSI-code

int a[255],b[255];

// 统计每个字符串中字符出现的次数
void statistics(char *str,int *orc)
{
	int len = strlen(str);
	for(int i = 0;i<len;++i)
	{
		int j = (int )str[i];
		++orc[j];
	}
}

// 比较两个数组 是否相同
bool compare()
{
	bool equal = true;
	for(int i = 0;i<255;i++)
	{
		if( a[i] != b[i])
		{
			equal = false;
			break;
		}
	}

	return equal;
}


// 
// 



// 数组与字符串


// __________________________ 1.7 __________________________
/*
	编写一个算法，若 M*N 矩阵中 某个元素为0，则将其所在的行与列清零。
*/


// __________________________ 解决思路 __________________________
/*
思路1：
遍历第1遍矩阵，记录下哪些元素为0.等所有值为0 的元素 全部统计完成后。用栈记录？
然后再对0所在的行与列 清零

思路2：
遍历第1遍矩阵，把同行同列的都置为 true.
遍历第2遍矩阵，把值为 true 的全部设置为 0。
*/ 


// __________________________ 实现细节 __________________________		
// 

// 思路1实现，不好。__________________________		
stack<int> stk; 

void recordZero(int matrix[n][n])
{


	for( int j = 0;j<M-1; ++j )
	{
		for( int i = 0; i<N-1; ++i )
		{
			if( matrix[i][j] == 0 )
			{

			}
		}
	}
}


// M行，N列。
void clearZero(int x, int y,int M,int N)
{
	for( int i = 0; i<M-1; ++i )	// 竖着的一列清0
	{
		matrix[x][i] = 0;
	}

	for( int j = 0; j<N-1; ++j )	// 横着的一行清0
	{
		matrix[j][y] = 0;
	}
}


// 思路2实现 代码来自网上 __________________________		
void zero(int **a, int m, int n)
{
	bool row[m], col[n];
	memset( row,false,sizeof(row) );
	memset( col,false,sizeof(col) );

	for(int i = 0; i<m; ++i)
	{
		for(int j = 0; j<n; ++j)
		{
			if(a[i][j] == 0){
				row[i] = true;
				col[j] = true;
			}
		}
	}


	for(int i=0; i<m; ++i)
	{
		for(int j = 0;j<n; ++j)
		{
			if( row[i] || col[j] )
				a[i][j] = 0;
		}
	}
}

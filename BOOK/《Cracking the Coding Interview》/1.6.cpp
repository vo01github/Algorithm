

// 数组与字符串


// __________________________ 1.6 __________________________
/*
	给定一副由N*N矩阵表示的图像，其中每个像素的大小为4字节，
	编写一个方法，将图像旋转90度。不占用额外内存空间能否做到？
*/


// __________________________ 解决思路 __________________________
/*
	每个像素的大小为4字节。那就是32位真彩色。
	实际的用途就是图像处理软件中的，旋转图像90度后，重新保存图像吧。

e.g. 参考 bmp 图像存放格式：像素点按照从左往右，再从上往下的方式存放在数组中。

思路1：	从外层到里层，一层层循环。
		每层进行：上边移动到右边，右边移动到下边，下边移动到左边，左边移动到上边。

时间复杂度为O(N^2)，这已是最优的做法，因为任何算法都需要访问所有N^2个元素。		

*/ 


// __________________________ 实现细节 __________________________		
// 
struct rgb{
	float r;
	float g;
	float b;
};

void rotate(rgb matrix[n][n],int n)
{
	for( int layer = 0; layer < n/2; ++layer )
	{
		int first = layer;
		int last = n - 1 - layer;
		for(int i = first; i < last + 1; ++i)		// 原书代码里居然少了 +1，写成 i < last 了
		{
			int offset = i - first;

			// 存储上边
			rgb top = matrix[first][i];

			// 左到上
			matrix[first][i] = matrix[last-offset][first];

			// 下到左
			matrix[last-offset][first] = matrix[last][last-offset];

			// 右到下
			matrix[last][last-offset] = matrix[i][last];

			// 从上到右
			matrix[i][last] = top;
		}
	}
}
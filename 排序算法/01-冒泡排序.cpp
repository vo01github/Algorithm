

// 01-冒泡排序
/*
	冒泡排序(Bubble Sort)是一种交换排序，它的基本思想是：两两比较相邻记录的关键字，如果反序则交换，直到没有反序的记录为止。
    冒泡的实现在细节上可以有很多种变化。下面我们将实现3种不同的冒泡实现代码，来讲解冒泡排序的思想。这里，我们就先来看看比较容易理解的一段。
*/

// __________________________0 基础函数 __________________________
// 【交换函数】-C语言版:利用指针来交换值。
void swip(int * i, int * j) 
{
    int temp = *i;
    *i = *j;
    *j = tmep;
}
swap(&a,&b);

// 【交换函数】-C++ 版：利用引用来交换值。优点：效率高，代码易读。
void swip(int &i, int &j) 
{
    int temp = i;
    i = j;
    j = tmep;
}
swap(a,b);

// 【交换函数】-C++ 版-模板：可以针对不同类型,不局限于 int 类型。
template <typename type>  
void swip(type &a, type &b)  
{  
    type temp = i;
    i = j;
    j = tmep; 
}  





// 判断函数-用来决定是否需要交换的【比较函数】
enum COMPARE{
    COMPARE_E_BIG_TO_SMALL  = 0,        //  把数组按从大到小排列
    COMPARE_E_SMALL_TO_BIG  = 1,         //  把数组按从小到大排列
}
int compare(const int &v1, const int &v2)    // 比较函数，不需要修改值，所以加上 const
{
    if(v1>v2) return COMPARE_E_SMALL_TO_BIG;
    if(v1<v2) return COMPARE_E_BIG_TO_SMALL;
    return 0;                               // 相等时，不需要调用 swap(a,b)函数
}

// __________________________1 冒泡排序-初级版-不带哨兵 __________________________
/*  
时间复杂度： 
    n + (n-1) + (n-2) + ... + 2 + 1 = n*(n+1)/2 = n^2 + n = n^2
    而且这个时间复杂度，不受输入值的原始排序影响而变化，始终都是这个值。

算法效率：
    它应该算是最最容易写出的排序代码了，不过这个简单易懂的代码，却是有缺陷的。观察后发现，在排序好1和2的位置后，
    对其余关键字的排序没有什么帮助。也就是说，这个算法的效率是非常低的。
*/
void BubbleSort0(int array[], int length)   // length 为数组的长度。
{
    int i,j;
    for(i = 0;i<length;i++)
    {
        for(j=i+1;j<length;j++)
        {
            if( compare(array[i], array[j]) )
            {
                swap(array[i],array[j]);
            }
        }
    }
}


// __________________________1 冒泡排序 __________________________
/*
	这已经成为了教科书式的排序算法了。很容易实现，且对部分已经排好序的数据进行排序时，具有比较好的效率。它的最坏情形是O(N2)。
	算法思路：以从小到大排序为例，每次从数组最后一个元素开始，比较相邻的两个元素，如果array[j]<array[j-1]，即后面的元素小于前面的元素，
	那么交换两者的顺序，然后j--，再比较j和j-1位置上的元素，直到最后，这样最小的元素就移动到了数组的前面。

	好比是将数组中的元素看成是不同重量的气泡，放在水中它们会自动在重力作用下，轻的上漂，重的下沉。这也是冒泡排序的原理。
	直接上代码：
*/

void BubbleSort(int array[], int nsize)
 {
     int i,j;
     bool bok=false;
     /***i指向冒泡的顶端***/
     /***如果哨兵为true,表明i位置以后的元素都已经排好序，直接退出***/
     for(i=0; (i<nsize-1)&&(bok!=true); i++)
     {
         bok = true;//重置哨兵
         /***j指向底端***/
         for(j=nsize-1; j>i; j--)
         {
             /***满足条件，交换元素***/
            if(array[j]<array[j-1])
            {
                swap(&array[j], &array[j-1]);
                bok = false;//设置哨兵为false，表明存在可以交换的元素
            }
         }
     }
 }	

 /*
以数组array={2,4,6,3,5,9,11}为例说明排序过程：

i=0:	2 3 4 6 5 9 11

i=1:	2 3 4 5 6 9 11

i=2:	bok=true,直接退出。

可以看看这个动画演示会更清楚：http://student.zjzk.cn/course_ware/data_structure/web/flashhtml/maopaopaixu.htm
 */


// __________________________2 插入排序 __________________________
/*

*/

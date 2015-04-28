

// 01-冒泡排序
/*
	冒泡排序(Bubble Sort)是一种【交换排序】，它的基本思想是：两两比较相邻记录的关键字，如果反序则交换，直到没有反序的记录为止。
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
    type temp = a;
    a = b;
    b = tmep; 
}  
swap(a,b);




// 判断函数-用来决定是否需要交换的【比较函数】
enum COMPARE{
    COMPARE_E_BIG_TO_SMALL  = 0,        //  把数组按从大到小排列
    COMPARE_E_SMALL_TO_BIG  = 1,        //  把数组按从小到大排列
}

template <typename type>  
int compare(const type &v1, const type &v2)    // 比较函数，不需要修改值，所以加上 const
{
    if(v1>v2) return COMPARE_E_SMALL_TO_BIG;
    if(v1<v2) return COMPARE_E_BIG_TO_SMALL;
    return 0;                               // 相等时，不需要调用 swap(a,b)函数
}

// __________________________1 交换排序-初级版 __________________________
/*  
时间复杂度： 
     (n-1) + (n-2) + ... + 2 + 1 = n*(n-1)/2 = n^2
    而且这个时间复杂度，不受输入值的原始排序影响而变化，始终都是这个值。
    比如已经拍好序的数组输入，它还是要计算 n^2 次。

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

// __________________________2 冒泡排序-初级版-不带哨兵 __________________________
/*
    在不断循环的过程中，除了将关键字1放到第一的位置，我们还将关键字2从其他位置 放到了 更加靠前的位置。
    显然这一算法比前面的要有进步，在上十万条数据的排序过程中，这种差异会体现出来。
    较小的数字如同气泡般慢慢浮到上面，因此就将此算法命名为冒泡算法。
*/
void BubbleSort1(int array[], int length)   // length 为数组的长度。
{
    int i,j;
    for(i = 0;i<length;i++)
    {
        for(j=length-1;j>i;j--)     /* 注意j是从后往前循环 */
        {
            if( array[j]<array[j-1] )
            {
                swap(array[j],array[j-1]);
            }
        }
    }
}



// __________________________3 冒泡排序-带哨兵 __________________________
/*
	这已经成为了教科书式的排序算法了。很容易实现，且对部分已经排好序的数据进行排序时，具有比较好的效率。它的最坏情形是O(N^2)。
	算法思路：以从小到大排序为例，每次从数组最后一个元素开始，比较相邻的两个元素，如果array[j]<array[j-1]，即后面的元素小于前面的元素，
	那么交换两者的顺序，然后j--，再比较j和j-1位置上的元素，直到最后，这样最小的元素就移动到了数组的前面。

	好比是将数组中的元素看成是不同重量的气泡，放在水中它们会自动在重力作用下，轻的上漂，重的下沉。这也是冒泡排序的原理。
	
    时间复杂度分析：
    当最好的情况，也就是要排序的表本身就是有序的，那么我们比较次数，根据最后改进的代码，可以推断出就是n次的比较，没有数据交换，时间复杂度为O(n)。
    当最坏的情况，即待排序表是逆序的况，此时需要比较 n*(n-1)/2 次，并作等数量级的记录移动。因此，总的时间复杂度为O(n2)。

    但是在最坏的情况时，只要颠倒数组，再开始进行排序，时间复杂度就是 O(n) 了，但是我自己如何在排序前 得知需不需要 对数组进行颠倒呢。
*/
void BubbleSort2(int array[], int length)
 {
     int i,j;
     bool bok=false;
     /***i指向冒泡的顶端***/
     /***如果哨兵为true,表明i位置以后的元素都已经排好序，直接退出***/
     for(i=0; (i<length-1)&&(bok!=true); i++)
     {
         bok = true;//重置哨兵
         /***j指向底端***/
         for(j=length-1; j>i; j--)
         {
             /***满足条件，交换元素***/
            if(array[j]<array[j-1])
            {
                swap(array[j], array[j-1]);
                bok = false;//设置哨兵为false，表明存在可以交换的元素
            }
         }
     }
 }	

/*  BubbleSort2 相比于 BubbleSort1 的进步：
        代码改动的关键就是在i变量的for循环中，增加了对flag是否为true的判断。经过这样的改进，冒泡排序在性能上就有了一些提升，
        可以避免因已经有序的情况下的无意义循环判断。
*/

 /*
以数组array={2,4,6,3,5,9,11}为例说明排序过程：

i=0:	2 3 4 6 5 9 11

i=1:	2 3 4 5 6 9 11

i=2:	bok=true,直接退出。

可以看看这个动画演示会更清楚：http://student.zjzk.cn/course_ware/data_structure/web/flashhtml/maopaopaixu.htm
 */


// __________________________ 鸡尾酒排序 __________________________
/*
    就是把 BubbleSort0 和 BubbleSort1 结合起来.
    不对，理解错了。不是结合起来。

    这样结合起来写太麻烦了，还是拆成两个并列的 大for 循环好一点
*/
// 下面这个代码不对啊， 关键在于条件：  j < length 每次的 length 是变化的，
void cocktail_sort0(int array[], int length)
 {
     int i,j;
     bool bok = false;
     bool bottom = false;
     /***i指向冒泡的顶端***/
     /***如果哨兵为true,表明i位置以后的元素都已经排好序，直接退出***/
     for(i=0; (i<length-1)&&(bok!=true); i++)
     {
         bok = true;//重置哨兵
         
         int add;
         if ( bottom == true )
         {
             j = length-1;
             add = -1;
         }else{
            j = i + 1;
            add = 1;
         }

         for(; j > i && j < length; j += add)
         {
             /***满足条件，交换元素***/
            if(array[j]<array[j-1])
            {
                swap(array[j], array[j-1]);
                bok = false;//设置哨兵为false，表明存在可以交换的元素
            }
         }

         bottom = bottom * (-1);
     }
 }  


/*
   最终正确版的 鸡尾酒 排序

   鸡尾酒排序，也就是定向冒泡排序，鸡尾酒搅拌排序，搅拌排序（也可以视作选择排序的一种变形），涟漪排序，来回排序or 快乐小时排序，
   是冒泡排序的一种变形。此算法与冒泡排序的不同处在于排序时是以双向在序列中进行排序。
    
   动态GIF图片： 
   http://zh.wikipedia.org/wiki/%E9%B8%A1%E5%B0%BE%E9%85%92%E6%8E%92%E5%BA%8F
*/
 void cocktail_sort1(int array[], int length)
 {
    int left = 0,right = length - 1;
    int i,j;
    while( left < right)
    {
        for (i = left; i < right; ++i )
        {
            if(array[i+1]<array[i])
            {
                swap(array[i+1], array[i]);
            }
        }
        --right;

        for (j = right; j > left; --j )
        {
            if(array[j-1] > array[j])
            {
                swap(array[j-1], array[j]);
            }
        }
        ++left;
    }
 }


 // __________________________ 奇偶排序 __________________________
/*
    12
*/
# 排序算法

1、按照待排得记录是否全部被放置到内存中，可以分为内排序与外排序；

2、按照是否需要辅助空间，可以分为原址排序与非原址排序

3、按照两个相等的数排序后相对位置是否发生变化，可以分为稳定排序和不稳定排序

4、按照是否有比较的排序，可以分为基于比较的排序与非基于比较的排序，其中基于比较的排序又可以分为：

（1）交换排序：冒泡排序、快速排序

（2）插入排序：直接插入排序、希尔排序

（3）选择排序：简单选择排序、堆排序

（4）归并排序

基于比较的时间复杂度最好是O(nlogn)

非基于比较的排序：桶排序、计数排序、基数排序

当然，这些都还只是基础，相关变形太多了，
topK问题，
链表进行排序，
多路归并排序等。

掌握其中几种确实够应付大多数问题了，但要每种算法都实现过一遍，相关问题上理解就会深刻很多


## 交换排序
* 冒泡排序【 + 鸡尾酒排序 + 奇偶排序】
* 快速排序

## 插入排序
* 直接插入排序
* 希尔排序

## 选择排序
* 简单选择排序
* 堆排序

## 归并排序
* 归并排序

## 分配排序
* 桶排序



* 计数排序
* 基数排序

* bitmap排序






##  **动画演示**

冒泡排序
http://student.zjzk.cn/course_ware/data_structure/web/flashhtml/maopaopaixu.htm

桶排序
http://www.cs.usfca.edu/~galles/visualization/BucketSort.html


## 排序算法-参考文章：
http://www.cnblogs.com/wb-DarkHorse/category/430640.html
这篇介绍的排序算法有：1) 冒泡排序，2) 插入排序。

九大排序算法再总结
http://blog.csdn.net/xiazdong/article/details/8462393


八大排序算法
http://blog.csdn.net/hguisu/article/details/7776068


大话数据结构-排序的那篇章节
http://www.cnblogs.com/cj723/category/282222.html


漫谈经典排序算法:一、从简单选择排序到堆排序的深度解析
http://blog.csdn.net/touch_2011/article/details/6767673


快速排序算法
http://blog.csdn.net/v_july_v/article/details/6116297


怎样让快速排序更快？
http://blog.sina.com.cn/s/blog_4dff8712010136jh.html


数学之美番外篇：快排为什么那样快【思想高度篇的文章————信息论的知识】
http://mindhacks.cn/2008/06/13/why-is-quicksort-so-quick/


为什么说任何基于比较的算法将5个元素排序都需要7次？【信息论的角度】
http://justjavac.com/other/2013/04/10/why-any-sort-algorithm-based-on-the-comparison-of-the-five-elements-are-needed-7-times.html





可视化对比十多种排序算法（C#版）
http://blog.jobbole.com/72850/
双向冒泡排序
冒泡排序
桶排序
梳排序
循环排序
地精排序
堆排序
插入排序
归并排序
奇偶排序
鸽笼排序
快速排序
使用冒泡的快排
选择排序
希尔排序



// 99-排序练习


// __________________________ __________________________  自我练习 __________________________ __________________________
/// 自己练习 多敲打几遍。



// __________________________1 冒泡排序-带哨兵 __________________________
//  默写练习次数：1
void bubbleSort(int array[],int length)
{
    int i,j;
    bool fuck = false;

    for(i = 0;(i<length-1)&&(fuck != true);i++)
    {
        fuck = true;
        for(j=length-1;j>i;j--)
        {
            if(array[j]<array[j-1])
            {
                swap(array[j],array[j-1]);
                fuck = false;
            }
        }
    }
}

// __________________________2 简单选择排序 __________________________
//  默写练习次数：1

void selectSort(int array[],int length)
{
    int i,j,min;
    for(i=0;i<length-1;i++)
    {
        min = i;
        for(j=i+1;j<length;j++)
        {
            if(array[j]<array[min])
            {
                min = j;
            }
        }

        if(min!=i)
        {
             swap(array[i],array[min])
        } 
    }
}


// __________________________3 直接插入排序 __________________________
//  默写练习次数：1

void insertSort(int array[],int length)
{
    int i,j,ntemp;
    for(i=1;i<length;i++)
    {
        ntemp = array[i];
        for(j=i;(j>=1)&&(array[j-1]>ntemp);j-=1)
        {
            array[j] = array[j-1];
        }
        array[j] = ntemp;
    }
}


// __________________________4 希尔排序 __________________________
//  默写练习次数：1
// 就是把上面的 1全部替换成一个 变量 ngap 

void shellSort(int array[],int length)
{
    int i,j,ntemp,ngap;
    for(ngap = length/3 + 1;ngap>0;ngap=ngap/3+1)
    {
        for(i = ngap;i<length;i++)
        {
            ntemp = array[i];
            for(j=i;j>=ngap&&array[j-ngap]>ntemp;j-=ngap)
            {
                array[j] = array[j-ngap];
            }
            array[j] = ntemp;
        }
    }
}



// __________________________5 堆排序 __________________________
//  默写练习次数：
void heapSort(int array[],int length)
{
    int i;
    for(i = length/2-1;i>=0;i--)
    {
        percolatedown(array[],length,i);
    }

    for(i = length;i>0;i--)
    {
        swap(array[0],array[i-1]);
        percolatedown(array[],i-1,0);
    }
}

void percolatedown(int arr[],int length,int index)
{
    int ntemp;
    int nchild;
    for(ntemp = array[index];2*index+1<=length-1;index =nchild)
    {
        nchild = 2*index+1;
        if( nchild != length-1 && array[nchild]<array[nchild+1])
        {
            nchild++;
        }
        if(ntemp < array[nchild])
        {
            array[index] = array[nchild];
        }else
            break;
    }
    array[index] = ntemp;
}

// __________________________6 归并排序 __________________________
void mergeSort()
{
    mSort(arr[],arr[],1,length);
}

/* 将SR[id0..end1]归并排序为TR1[id0..end1] */
void MSort(int SR[],int TR1[],int id0, int end1)
{
    int end0;
    int TR2[end0AXSIZE+1];
    if(id0==end1)
    {
        TR1[id0]=SR[id0];
    }
    else
    {
      end0=(id0+end1)/2;   /* 将SR[id0..end1]平分为SR[id0..end0]和SR[end0+1..end1] */
      MSort(SR,TR2,id0,end0); /* 递归地将SR[id0..end0]归并为有序的TR2[id0..end0] */
      MSort(SR,TR2,end0+1,end1); /* 递归地将SR[end0+1..end1]归并为有序TR2[end0+1..end1] */
      Merge(TR2,TR1,id0,end0,end1); /* 将TR2[id0..end0]和TR2[end0+1..end1]归并到TR1[id0..end1] */
    }
}

/* 将有序的SR[id0..end0]和SR[end0+1..end1]归并为有序的TR[id0..end1] */
void Merge(int SR[],int TR[],int id0,int end0,int end1)
{
    int id1,id2,l;
    for(id1 = end0+1,id2=id0; id0<=end0 && id1<=end1; id2++)
    {
        if(SR[id0]<SR[id1])
            TR[id2] = SR[id0++];
        else
            TR[id2] = SR[id1++];
    }

    if(id0 <= end0)
    {
        for(l=0;l<=end0-id0;l++)
            TR[id2+l]=SR[id0+l];  /* 将剩余的SR[id0..end0]复制到TR */
   }
   if(id1<=end1)
   {
        for(l=0;l<=end1-id1;l++)
            TR[id2+l]=SR[id1+l];  /* 将剩余的SR[id1..end1]复制到TR */
   }
}

// __________________________7 快速排序 __________________________




 


// 03替代过程的几个简单例子
/*
[英文原文]http://www.codeproject.com/Articles/418776/How-to-replace-recursive-functions-using-stack-and
[译文]http://www.cnblogs.com/wb-DarkHorse/archive/2013/11/15/3284228.html
5 替代过程的几个简单例子

以下几个例子均在vs2008环境下开发，主要包含了：
*/

// __________________________（1）线性递归 Linear Recursion Example  __________________________
#ifndef __LINEAR_RECURSION_H__
#define __LINEAR_RECURSION_H__

#include <stack>
using namespace std;

/**
* \brief 求n的阶乘
* \para 
* \return 
* \note result = n! 递归实现
*/
int Fact(long n)
{
    if(0>n)
        return -1;
    if(0 == n)
        return 1;
    else
    {
        return ( n* Fact(n-1));
    }
} 

/**
* \brief 求n的阶乘
* \para 
* \return 
* \note result = n! 循环实现
*/
int FactLoop(long n)
{
    // (步骤1)
    struct SnapShotStruct // 快照结构体局部声明 
    {
        long inputN;      // 会改变的参数
                          // 没有局部变量
        int stage;        // 阶段变量用于快照跟踪
    } ;

    // (步骤2)
    int returnVal;        // 用于保存当前调用返回值  

    // (步骤3)
    stack<SnapShotStruct> snapshotStack;

    // (步骤4)
    SnapShotStruct currentSnapshot;
    currentSnapshot.inputN=n;
    currentSnapshot.stage=0; // 阶段变量初始化

    snapshotStack.push(currentSnapshot);  

    // (步骤5)
    while(!snapshotStack.empty())  
    {     
        currentSnapshot=snapshotStack.top();         
        snapshotStack.pop();       

        // (步骤6)
        switch(currentSnapshot.stage)
        {
            // (步骤7)
        case 0:
            if(0>currentSnapshot.inputN)
            {
                // (步骤8 & 步骤9)
                returnVal = -1;
                continue;
            }
            if(0 == currentSnapshot.inputN)
            {
                // (步骤8 & 步骤9)
                returnVal = 1;     
                continue;
            }
            else
            {
                // (步骤10)

                // 返回 ( n* Fact(n-1)); 分为2步： 
                // (第一步调用自身，第二步用返回值乘以当前n值)
                // 这里我们拍下快照.
                currentSnapshot.stage=1; // 当前的快照表示正在被处理，并等待自身调用结果返回，所以赋值为1 

                snapshotStack.push(currentSnapshot);

                // 创建一个新的快照，用于调用自身
                SnapShotStruct newSnapshot;
                newSnapshot.inputN= currentSnapshot.inputN -1 ; // 初始化参数 
                                                                 
                newSnapshot.stage = 0 ;                         // 从头开始执行自身，所以赋值stage==0 
                                                                
                snapshotStack.push(newSnapshot);
                continue;

            }
            break;
            // (步骤7)
        case 1:

            // (步骤8)

            returnVal = currentSnapshot.inputN * returnVal;

            // (步骤9)
            continue;
            break;
        }
    }
    
    // (步骤2)
    return returnVal;
}   
#endif //__LINEAR_RECURSION_H__



// __________________________（2）二分递归  Binary Recursion Example__________________________
#ifndef __BINARY_RECURSION_H__
#define __BINARY_RECURSION_H__

#include <stack>
using namespace std;

/**
* \function FibNum
* \brief 求斐波纳契数列
* \para 
* \return 
* \note 递归实现
*/
int FibNum(int n)
{
    if (n < 1)
        return -1;
    if (1 == n || 2 == n)
        return 1;

    // 这里可以看成是
    //int addVal = FibNum( n - 1);
    // addVal += FibNum(n - 2);
    // return addVal;
    return FibNum(n - 1) + FibNum(n - 2);                             
} 
/**
* \function FibNumLoop
* \brief 求斐波纳契数列
* \para 
* \return 
* \note 循环实现
*/
int FibNumLoop(int n)
{
    // (步骤1)
    struct SnapShotStruct // 快照结构体局部声明 
    {
        int inputN;       // 会改变的参数
        int addVal;       // 局部变量
        int stage;        // 阶段变量用于快照跟踪

    };

    // (步骤2)
    int returnVal;        // 用于保存当前调用返回值

    // (步骤3)
    stack<SnapShotStruct> snapshotStack;

    // (步骤4)
    SnapShotStruct currentSnapshot;
    currentSnapshot.inputN=n;
    currentSnapshot.stage=0; // 阶段变量初始化

    snapshotStack.push(currentSnapshot);

    // (步骤5)
    while(!snapshotStack.empty())
    {
        currentSnapshot=snapshotStack.top();
        snapshotStack.pop();

        // (步骤6)
        switch(currentSnapshot.stage)
        {
            // (步骤7)
        case 0:
            if(currentSnapshot.inputN<1)
            {
                // (步骤8 & 步骤9)
                returnVal = -1;
                continue;
            }
            if(currentSnapshot.inputN == 1 || currentSnapshot.inputN == 2 )
            {
                // (步骤8 & 步骤9)
                returnVal = 1;
                continue;
            }
            else
            {
                // (步骤10)

                // 返回 ( FibNum(n - 1) + FibNum(n - 2)); 相当于两步
                // (第一次调用参数是 n-1, 第二次调用参数 n-2)
                // 这里我们拍下快照，分成2个阶段
                currentSnapshot.stage=1;                        // 当前的快照表示正在被处理，并等待自身调用结果返回，所以赋值为1 

                snapshotStack.push(currentSnapshot);

                // 创建一个新的快照，用于调用自身
                SnapShotStruct newSnapshot;
                newSnapshot.inputN= currentSnapshot.inputN -1 ; //初始化参数 FibNum(n - 1)

                newSnapshot.stage = 0 ;                         
                snapshotStack.push(newSnapshot);
                continue;

            }
            break;
            // (步骤7)
        case 1:

            // (步骤10)

            currentSnapshot.addVal = returnVal;
            currentSnapshot.stage=2;                         // 当前的快照正在被处理，并等待的自身调用结果，所以阶段变量变成2

            snapshotStack.push(currentSnapshot);

            // 创建一个新的快照，用于调用自身
            SnapShotStruct newSnapshot;
            newSnapshot.inputN= currentSnapshot.inputN - 2 ; // 初始化参数 FibNum(n - 2)
            newSnapshot.stage = 0 ;                          // 从头开始执行，阶段变量赋值为0 
                                                             
            snapshotStack.push(newSnapshot);
            continue;
            break;
        case 2:
            // (步骤8)
            returnVal = currentSnapshot.addVal + returnVal;  // actual addition of ( FibNum(n - 1) + FibNum(n - 2) )

            // (步骤9)
            continue;
            break;
        }
    }  

    // (步骤2)
    return returnVal;
}
  

#endif //__BINARY_RECURSION_H__




// __________________________（3）尾递归 Tail Recursion Example __________________________
#ifndef __TAIL_RECURSION_H__
#define __TAIL_RECURSION_H__

#include <stack>
using namespace std;

/**
* \function FibNum2
* \brief 2阶裴波那契序列
* \para
* \return
* \note 递归实现  f0 = x, f1 = y, fn=fn-1+fn-2,   n=k,k+1,...
*/ 
int FibNum2(int n, int x, int y)
{   
    if (1 == n)    
    {
        return y;
    }
    else    
    {
        return FibNum2(n-1, y, x+y);
    }
}
/**
* \function FibNum2Loop
* \brief 2阶裴波那契序列
* \para
* \return
* \note 循环实现 在尾递归中, 递归调用后除了返回没有任何其它的操作, 所以在变为循环时，不需要stage变量
*/ 
int FibNum2Loop(int n, int x, int y)
{
    // (步骤1)
    struct SnapShotStruct 
    {
        int inputN;    // 会改变的参数
        int inputX;    // 会改变的参数
        int inputY;    // 会改变的参数
                       // 没有局部变量
    };

    // (步骤2)
    int returnVal;

    // (步骤3)
    stack<SnapShotStruct> snapshotStack;

    // (步骤4)
    SnapShotStruct currentSnapshot;
    currentSnapshot.inputN = n;
    currentSnapshot.inputX = x;
    currentSnapshot.inputY = y;

    snapshotStack.push(currentSnapshot);

    // (步骤5)
    while(!snapshotStack.empty())
    {
        currentSnapshot=snapshotStack.top();
        snapshotStack.pop();

        if(currentSnapshot.inputN == 1)
        {
            // (步骤8 & 步骤9)
            returnVal = currentSnapshot.inputY;
            continue;
        }
        else
        {
            // (步骤10)

            // 创建新快照
            SnapShotStruct newSnapshot;
            newSnapshot.inputN= currentSnapshot.inputN -1 ; // 初始化，调用( FibNum(n-1, y, x+y) )
            newSnapshot.inputX= currentSnapshot.inputY;
            newSnapshot.inputY= currentSnapshot.inputX + currentSnapshot.inputY;
            snapshotStack.push(newSnapshot);
            continue;
        }
    }
    // (步骤2)
    return returnVal;
} 

#endif //__TAIL_RECURSION_H__




// __________________________（4）互递归 Mutual Recursion Example __________________________

#ifndef __MUTUAL_RECURSION_H__
#define __MUTUAL_RECURSION_H__
#include <stack>
using namespace std;

bool IsEvenNumber(int n);//判断是否是偶数
bool IsOddNumber(int n);//判断是否是奇数
bool isOddOrEven(int n, int stage);//判断是否是奇数或偶数

/****************************************************/
//互相调用的递归实现
bool IsOddNumber(int n)
{
    // 终止条件
    if (0 == n)
        return false;
    else
        // 互相调用函数的递归调用
        return IsEvenNumber(n - 1);
}

bool IsEvenNumber(int n)
{
    // 终止条件
    if (0 == n)
        return true;
    else
        // 互相调用函数的递归调用
        return IsOddNumber(n - 1);
} 


/*************************************************/
//互相调用的循环实现
bool IsOddNumberLoop(int n)
{
    return isOddOrEven(n , 0);
}

bool IsEvenNumberLoop(int n)
{
    return isOddOrEven(n , 1);
}

bool isOddOrEven(int n, int stage)
{
    // (步骤1)
    struct SnapShotStruct
    {
        int inputN;       // 会改变的参数
        int stage;
                          // 没有局部变量
    };

    // (步骤2)
    bool returnVal;       

    // (步骤3)
    stack<SnapShotStruct> snapshotStack;

    // (步骤4)
    SnapShotStruct currentSnapshot;
    currentSnapshot.inputN = n;
    currentSnapshot.stage = stage;

    snapshotStack.push(currentSnapshot);

    // (步骤5)
    while(!snapshotStack.empty())
    {
        currentSnapshot=snapshotStack.top();
        snapshotStack.pop();

        // (步骤6)
        switch(currentSnapshot.stage)
        {
            // (步骤7)
            // bool IsOddNumber(int n)
        case 0:
            // 终止条件
            if (0 == currentSnapshot.inputN)
            {
                // (步骤8 & 步骤9)
                returnVal = false;
                continue;
            }
            else
            {
                // (步骤10)

                // 模拟互调用的递归调用

                // 创建新的快照
                SnapShotStruct newSnapshot;
                newSnapshot.inputN= currentSnapshot.inputN - 1; // 初始化参数 
                // 调用 ( IsEvenNumber(n - 1) )
                newSnapshot.stage= 1;
                snapshotStack.push(newSnapshot);
                continue;
            }

            break;
            // (步骤7)
            // bool IsEvenNumber(int n)
        case 1:
            // 终止条件
            if (0 == currentSnapshot.inputN)
            {
                // (步骤8 & 步骤9)
                returnVal = true;
                continue;
            }
            else
            {
                // (步骤10)

                // 模拟互调用的递归调用

                // 创建新的快照
                SnapShotStruct newSnapshot;
                newSnapshot.inputN= currentSnapshot.inputN - 1; // 
                // calling itself ( IsEvenNumber(n - 1) )
                newSnapshot.stage= 0;
                snapshotStack.push(newSnapshot);
                continue;
            }
            break;
        }

    }
    // (步骤2)
    return returnVal;
}  

#endif //__MUTUAL_RECURSION_H__




// __________________________（5）嵌套递归 Nested Recursion Example __________________________
#ifndef __NESTED_RECURSION_H__
#define __NESTED_RECURSION_H__
#include <stack>
using namespace std;

int Ackermann(int x, int y)
{
    // 终止条件
    if (0 == x)
    {
        return y + 1;
    }   
    // 错误处理条件
    if (x < 0  ||  y < 0)
    {
        return -1;
    }  
    // 线性方法的递归调用 
    else if (x > 0 && 0 == y) 
    {
        return Ackermann(x-1, 1);
    }
    // 嵌套方法的递归调用
    else
    {
        //可以看成是：
        // int midVal = Ackermann(x, y-1);
        // return Ackermann(x-1, midVal);
        return Ackermann(x-1, Ackermann(x, y-1));
    }
}



int AckermannLoop(int x, int y)
{
    // (步骤1)
    struct SnapShotStruct 
    {
        int inputX;       // 会改变的参数
        int inputY;       // 会改变的参数
        int stage;
                          // 没有局部变量
    };

    // (步骤2)
    int returnVal;        

    // (步骤3)
    stack<SnapShotStruct> snapshotStack;

    // (步骤4)
    SnapShotStruct currentSnapshot;
    currentSnapshot.inputX = x;
    currentSnapshot.inputY = y;
    currentSnapshot.stage = 0;

    snapshotStack.push(currentSnapshot);

    // (步骤5)
    while(!snapshotStack.empty())
    {
        currentSnapshot=snapshotStack.top();
        snapshotStack.pop();

        // (步骤6)
        switch(currentSnapshot.stage)
        {
            // (步骤7)
        case 0:
            // 终止条件
            if(currentSnapshot.inputX == 0)
            {
                // (步骤8 & 步骤9)
                returnVal = currentSnapshot.inputY + 1;
                continue;             // 这里必须返回
            }
            // 错误处理条件        
            if (currentSnapshot.inputX < 0  ||  currentSnapshot.inputY < 0)
            {
                // (步骤8 & 步骤9)
                returnVal = -1;
                continue;             // 这里必须返回
            }  
            // 线性方法的递归调用 
            else if (currentSnapshot.inputX > 0 && 0 == currentSnapshot.inputY) 
            {
                // (步骤10)

                // 创建新快照
                SnapShotStruct newSnapshot;
                newSnapshot.inputX= currentSnapshot.inputX - 1; // 参数设定 calling itself ( Ackermann(x-1, 1) )
                newSnapshot.inputY= 1;                          // 参数设定 calling itself ( Ackermann(x-1, 1) )
                newSnapshot.stage= 0;
                snapshotStack.push(newSnapshot);
                continue;
            }
            // Recursive call by Nested method
            else
            {
                // (步骤10)

                currentSnapshot.stage=1;                       
                snapshotStack.push(currentSnapshot);

                // 创建新快照
                SnapShotStruct newSnapshot;
                newSnapshot.inputX= currentSnapshot.inputX;        //参数设定calling itself ( Ackermann(x, y-1) )
                newSnapshot.inputY= currentSnapshot.inputY - 1; //参数设定calling itself ( Ackermann(x, y-1) )
                newSnapshot.stage = 0;
                snapshotStack.push(newSnapshot);
                continue;
            }
            break;
        case 1:
            // (步骤10)

            // 创建新快照
            SnapShotStruct newSnapshot;
            newSnapshot.inputX= currentSnapshot.inputX - 1;   // 设定参数calling itself ( Ackermann(x-1,  Ackermann(x, y-1)) )
            newSnapshot.inputY= returnVal;                    // 设定参数calling itself ( Ackermann(x-1,  Ackermann(x, y-1)) )
            newSnapshot.stage = 0;
            snapshotStack.push(newSnapshot);
            continue;
            break;
        }
    }
    // (步骤2)
    return returnVal;
}     
#endif //__NESTED_RECURSION_H__




// __________________________测试代码：__________________________
#include <tchar.h>
#include "BinaryRecursion.h"
#include "LinearRecursion.h"
#include "MutualRecursion.h"
#include "NestedRecursion.h"
#include "TailRecursion.h"


int _tmain(int argc,_TCHAR argv[] )
{
    // Binary Recursion
    int result = FibNum(10);
    int result2 = FibNumLoop(10);

    printf("FibNum(10) = %d\n",result);
    printf("FibNumLoop(10) = %d\n",result2);


    // Linear Recursion
    result = Fact(10);
    result2 = FactLoop(10);

    printf("Fact(10) = %d\n",result);
    printf("FactLoop(10) = %d\n",result2);


    // Tail Recursion
    result = FibNum2(10,5,4);
    result2 = FibNum2Loop(10,5,4);

    printf("FibNum2(10,5,4) = %d\n",result);
    printf("FibNumLoop2(10,5,4) = %d\n",result2);


    // Mutual Recursion
    bool bResult = IsOddNumber(10);
    bool bResult2 = IsOddNumberLoop(10);

    bool bResult3 = IsEvenNumber(10);
    bool bResult4 = IsEvenNumberLoop(10);

    printf("IsOddNumber(10) = %d\n",(int)bResult);
    printf("IsOddNumberLoop(10) = %d\n",(int)bResult2);
    printf("IsEvenNumber(10) = %d\n",(int)bResult3);
    printf("IsEvenNumberLoop(10) = %d\n",(int)bResult4);


    // Nested Recursion
    result = Ackermann(3,2);
    result2 = AckermannLoop(3,2);

    printf("Ackermann(3,2) = %d\n",result);
    printf("AckermannLoop(3,2) = %d\n",result2);

    while(1){}
    return 0;
}


// __________________________6 更多的例子__________________________
/*
	作者给的github网址失效了。
	还好只是换了下路径.还是搜索到了。
	https://github.com/haih/EpWinService/blob/2e30a7e71c48d925b0812127316ae71eb9853603/EpWinServiceAPILibrary/EpWinServiceAPILibrary/EpLibraryHeaders/epQuickSort.h
*/


/*7 结论

我的结论就是在c/c++或者Java代码中，尽量避免用递归。但是正如你看到的，递归容易理解，但是容易导致栈溢出。
虽然循环版本的函数不会增加代码可读性和提升性能，但是它能有效的避免冲突或未定义行为。
正如我开头所说，我的做法通常是在代码中写两份代码，一份递归，一份循环的。前者用于理解代码，后者用于实际的运行和测试用。
如果你对于自己代码中使用这两种代码的利弊很清楚，你可以选择你自己的方式。
*/
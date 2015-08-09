

// 02-如何利用循环代替递归以防止栈溢出
/*
	【原文地址】http://www.cnblogs.com/wb-DarkHorse/archive/2013/11/15/3284228.html
	摘要：我们经常会用到递归函数，但是如果递归深度太大时，往往导致栈溢出。而递归深度往往不太容易把握，所以比较安全一点的做法就是：用循环代替递归。
	文章最后的原文里面讲了如何用10步实现这个过程，相当精彩。本文翻译了这篇文章，并加了自己的一点注释和理解。

目录
	简介
	模拟函数的目的
	递归和模拟函数的优缺点
	用栈和循环代替递归的10个步骤
	替代过程的几个简单例子
	更多的例子
	结论
	参考
	协议
*/


// __________________________1 简介__________________________
/*
	一般我们在进行排序(比如归并排序)或者树操作时会用到递归函数。但是如果递归深度达到一定程度以后，就会出现意想不到的结果比如堆栈溢出。
虽然有很多有经验的开发者都知道了如何用循环函数或者栈加while循环来代替递归函数，以防止栈溢出，但我还是想分享一下这些方法，
这或许会对初学者有很大的帮助。
*/


// __________________________2 模拟函数的目的__________________________
/*
	如果你正在使用递归函数，并且没有控制递归调用，而栈资源又比较有限，调用层次过深的时候就可能导致栈溢出/堆冲突。
模拟函数的目的就是在堆中开辟区域来模拟栈的行为，这样你就能控制内存分配和流处理，从而避免栈溢出。如果能用循环函数来代替效果会更好，
这是一个比较需要时间和经验来处理的事情，出于这些原因，这篇文章为初学者提供了一个简单的参考，
怎样使用循环函数来替代递归函数，以防止栈溢出？
*/


// __________________________3 递归函数和模拟函数的优缺点__________________________
/*
递归函数：

　　优点：算法比较直观。可以参考文章后面的例子

　　缺点：可能导致栈溢出或者堆冲突

　　你可以试试执行下面两个函数(后面的一个例子)，IsEvenNumber(递归实现)和IsEvenNumber(模拟实现)，
	他们在头文件"MutualRecursion.h"中声明。你可以将传入参数设定为10000，像下面这样：	
*/
#include "MutualRecursion.h" 

bool result = IsEvenNumberLoop(10000); // 成功返回

bool result2 = IsEvenNumber(10000);     // 会发生堆栈溢出

/*
 	有些人可能会问：如果我增加栈的容量不就可以避免栈溢出吗？好吧，这只是暂时的解决问题的办法，如果调用层次越来越深，
 	很有可能会再次发生溢出。

 模拟函数：

　　优点：能避免栈溢出或者堆冲突错误，能对过程和内存进行更好的控制

　　缺点：算法不是太直观，代码难以维护
*/


// __________________________4 用栈和循环代替递归的10个步骤__________________________
/*	第一步
1 定义一个新的结构体Snapshot，用于保存递归结构中的一些数据和状态信息

2 在Snapshot内部需要包含的变量有以下几种：

　　A 一般当递归函数调用自身时，函数参数会发生变化。所以你需要包含变化的参数，引用除外。
	比如下面的例子中，参数n应该包含在结构体中，而retVal不需要。

	B 阶段性变量"stage"(通常是一个用来转换到另一个处理分支的整形变量)，详见第六条规则

　　C 函数调用返回以后还需要继续使用的局部变量(一般在二分递归和嵌套递归中很常见)
*/

void SomeFunc(int n, int &retVal);

// Recursive Function "First rule" example	-递归函数
int SomeFunc(int n, int &retIdx)
{
   ...
   if(n>0)
   {
      int test = SomeFunc(n-1, retIdx);
      test--;
      ...
      return test;
   }
   ...
   return 0;
}


// Conversion to Iterative function 		-转化为迭代函数
int SomeFuncLoop(int n, int &retIdx)
{
    // (First rule)
    struct SnapShotStruct {
       int n;        // - parameter input
       int test;     // - local variable that will be used 
                     //     after returning from the function call
                     // - retIdx can be ignored since it is a reference.
       int stage;    // - Since there is process needed to be done 
                     //     after recursive call. (Sixth rule)
    };
    ...
}

/*第二步
1 在函数的开头创建一个局部变量，这个值扮演了递归函数的返回函数角色。它相当于为每次递归调用保存一个临时值，因为C++函数只能有一种返回类型，
如果递归函数的返回类型是void，你可以忽略这个局部变量。如果有缺省的返回值，就应该用缺省值初始化这个局部变量。
*/

// Recursive Function "Second rule" example
int SomeFunc(int n, int &retIdx)
{
   ...
   if(n>0)
   {
      int test = SomeFunc(n-1, retIdx);
      test--;
      ...
      return test;
   }
   ...
   return 0;
}

// Conversion to Iterative Function
int SomeFuncLoop(int n, int &retIdx)
{
     // (First rule)
    struct SnapShotStruct {
       int n;        // - parameter input
       int test;     // - local variable that will be used 
                     //     after returning from the function call
                     // - retIdx can be ignored since it is a reference.
       int stage;    // - Since there is process needed to be done 
                     //     after recursive call. (Sixth rule)
    };

    // (Second rule)
    int retVal = 0;  // initialize with default returning value

    ...
    // (Second rule)
    return retVal;
}

/*第三步
创建一个栈用于保存“Snapshot”结构体类型变量
*/
// Recursive Function "Third rule" example

// Conversion to Iterative Function
int SomeFuncLoop(int n, int &retIdx)
{
     // (First rule)
    struct SnapShotStruct {
       int n;        // - parameter input
       int test;     // - local variable that will be used 
                     //     after returning from the function call
                     // - retIdx can be ignored since it is a reference.
       int stage;    // - Since there is process needed to be done 
                     //     after recursive call. (Sixth rule)
    };

    // (Second rule)
    int retVal = 0;  // initialize with default returning value

    // (Third rule)
    stack<SnapShotStruct> snapshotStack;
    ...
    // (Second rule)
    return retVal;
}

/*第四步
创建一个新的”Snapshot”实例，然后将其中的参数等初始化，并将“Snapshot”实例压入栈
*/
// Recursive Function "Fourth rule" example

// Conversion to Iterative Function
int SomeFuncLoop(int n, int &retIdx)
{
     // (First rule)
    struct SnapShotStruct {
       int n;        // - parameter input
       int test;     // - local variable that will be used 
                     //     after returning from the function call
                     // - retIdx can be ignored since it is a reference.
       int stage;    // - Since there is process needed to be done 
                     //     after recursive call. (Sixth rule)
    };

    // (Second rule)
    int retVal = 0;  // initialize with default returning value

    // (Third rule)
    stack<SnapShotStruct> snapshotStack;

    // (Fourth rule)
    SnapShotStruct currentSnapshot;
    currentSnapshot.n= n;          // set the value as parameter value
    currentSnapshot.test=0;        // set the value as default value
    currentSnapshot.stage=0;       // set the value as initial stage

    snapshotStack.push(currentSnapshot);

    ...
    // (Second rule)
    return retVal;
}


/* 第五步
写一个while循环，使其不断执行直到栈为空。在while循环的每一次迭代过程中，弹出”Snapshot“对象。
*/
// Recursive Function "Fifth rule" example

// Conversion to Iterative Function
int SomeFuncLoop(int n, int &retIdx)
{
     // (First rule)
    struct SnapShotStruct {
       int n;        // - parameter input
       int test;     // - local variable that will be used 
                     //     after returning from the function call
                     // - retIdx can be ignored since it is a reference.
       int stage;    // - Since there is process needed to be done 
                     //     after recursive call. (Sixth rule)
    };
    // (Second rule)
    int retVal = 0;  // initialize with default returning value
    // (Third rule)
    stack<SnapShotStruct> snapshotStack;
    // (Fourth rule)
    SnapShotStruct currentSnapshot;
    currentSnapshot.n= n;          // set the value as parameter value
    currentSnapshot.test=0;        // set the value as default value
    currentSnapshot.stage=0;       // set the value as initial stage
    snapshotStack.push(currentSnapshot);
    // (Fifth rule)
    while(!snapshotStack.empty())
    {
       currentSnapshot=snapshotStack.top();
       snapshotStack.pop();
       ...
    }
    // (Second rule)
    return retVal;
}

/*第六步
将当前阶段一分为二(针对当前只有单一递归调用的情形)。第一个阶段代表了下一次递归调用之前的情况，
第二阶段代表了下一次递归调用完成并返回之后的情况(返回值已经被保存，并在此之前被累加)。
如果当前阶段有两次递归调用，就必须分为3个阶段。
	阶段1：第一次调用返回之前，
	阶段2：阶段1执行的调用过程。
	阶段3：第二次调用返回之前。
如果当前阶段有三次递归调用，就必须至少分为4个阶段。
依次类推。
*/
// Conversion to Iterative Function
int SomeFuncLoop(int n, int &retIdx)
{
     // (First rule)
    struct SnapShotStruct {
       int n;        // - parameter input
       int test;     // - local variable that will be used 
                     //     after returning from the function call
                     // - retIdx can be ignored since it is a reference.
       int stage;    // - Since there is process needed to be done 
                     //     after recursive call. (Sixth rule)
    };
    // (Second rule)
    int retVal = 0;  // initialize with default returning value
    // (Third rule)
    stack<SnapShotStruct> snapshotStack;
    // (Fourth rule)
    SnapShotStruct currentSnapshot;
    currentSnapshot.n= n;          // set the value as parameter value
    currentSnapshot.test=0;        // set the value as default value
    currentSnapshot.stage=0;       // set the value as initial stage
    snapshotStack.push(currentSnapshot);
    // (Fifth rule)
    while(!snapshotStack.empty())
    {
       currentSnapshot=snapshotStack.top();
       snapshotStack.pop();
       // (Sixth rule)
       switch( currentSnapshot.stage)
       {
       case 0:
          ...      // before ( SomeFunc(n-1, retIdx); )
          break; 
       case 1: 
          ...      // after ( SomeFunc(n-1, retIdx); )
          break;
       }
    }
    // (Second rule)
    return retVal;
}


/*第七步
根据阶段变量stage的值切换到相应的处理流程并处理相关过程。
*/
// Conversion to Iterative Function
int SomeFuncLoop(int n, int &retIdx)
{
     // (First rule)
    struct SnapShotStruct {
       int n;        // - parameter input
       int test;     // - local variable that will be used 
                     //     after returning from the function call
                     // - retIdx can be ignored since it is a reference.
       int stage;    // - Since there is process needed to be done 
                     //     after recursive call. (Sixth rule)
    };

    // (Second rule)
    int retVal = 0;  // initialize with default returning value

    // (Third rule)
    stack<SnapShotStruct> snapshotStack;

    // (Fourth rule)
    SnapShotStruct currentSnapshot;
    currentSnapshot.n= n;          // set the value as parameter value
    currentSnapshot.test=0;        // set the value as default value
    currentSnapshot.stage=0;       // set the value as initial stage

    snapshotStack.push(currentSnapshot);

    // (Fifth rule)
    while(!snapshotStack.empty())
    {
       currentSnapshot=snapshotStack.top();
       snapshotStack.pop();

       // (Sixth rule)
       switch( currentSnapshot.stage)
       {
       case 0:
          // (Seventh rule)
          if( currentSnapshot.n>0 )
          {
             ...
          }
          ...
          break; 
       case 1: 
          // (Seventh rule)
          currentSnapshot.test = retVal;
          currentSnapshot.test--;
          ...
          break;
       }
    }
    // (Second rule)
    return retVal;
}


/*第八步
如果递归有返回值，将这个值保存下来放在临时变量里面，比如retVal。当循环结束时，这个临时变量的值就是整个递归处理的结果。
*/
// Conversion to Iterative Function
int SomeFuncLoop(int n, int &retIdx)
{
     // (First rule)
    struct SnapShotStruct {
       int n;        // - parameter input
       int test;     // - local variable that will be used 
                     //     after returning from the function call
                     // - retIdx can be ignored since it is a reference.
       int stage;    // - Since there is process needed to be done 
                     //     after recursive call. (Sixth rule)
    };
    // (Second rule)
    int retVal = 0;  // initialize with default returning value
    // (Third rule)
    stack<SnapShotStruct> snapshotStack;
    // (Fourth rule)
    SnapShotStruct currentSnapshot;
    currentSnapshot.n= n;          // set the value as parameter value
    currentSnapshot.test=0;        // set the value as default value
    currentSnapshot.stage=0;       // set the value as initial stage
    snapshotStack.push(currentSnapshot);
    // (Fifth rule)
    while(!snapshotStack.empty())
    {
       currentSnapshot=snapshotStack.top();
       snapshotStack.pop();
       // (Sixth rule)
       switch( currentSnapshot.stage)
       {
       case 0:
          // (Seventh rule)
          if( currentSnapshot.n>0 )
          {
             ...
          }
          ...
          // (Eighth rule)
          retVal = 0 ;
          ...
          break; 
       case 1: 
          // (Seventh rule)
          currentSnapshot.test = retVal;
          currentSnapshot.test--;
          ...
          // (Eighth rule)
          retVal = currentSnapshot.test;
          ...
          break;
       }
    }
    // (Second rule)
    return retVal;
}


/*
 第九步
如果递归函数有“return”关键字，你应该在while循环里面用“continue”代替。如果return了一个返回值，你应该在循环里面保存下来(步骤8)，
然后continue。大部分情况下，步骤九是可选的，但是它能帮助你避免逻辑错误。
*/
// Conversion to Iterative Function
int SomeFuncLoop(int n, int &retIdx)
{
     // (First rule)
    struct SnapShotStruct {
       int n;        // - parameter input
       int test;     // - local variable that will be used 
                     //     after returning from the function call
                     // - retIdx can be ignored since it is a reference.
       int stage;    // - Since there is process needed to be done 
                     //     after recursive call. (Sixth rule)
    };
    // (Second rule)
    int retVal = 0;  // initialize with default returning value
    // (Third rule)
    stack<SnapShotStruct> snapshotStack;
    // (Fourth rule)
    SnapShotStruct currentSnapshot;
    currentSnapshot.n= n;          // set the value as parameter value
    currentSnapshot.test=0;        // set the value as default value
    currentSnapshot.stage=0;       // set the value as initial stage
    snapshotStack.push(currentSnapshot);
    // (Fifth rule)
    while(!snapshotStack.empty())
    {
       currentSnapshot=snapshotStack.top();
       snapshotStack.pop();
       // (Sixth rule)
       switch( currentSnapshot.stage)
       {
       case 0:
          // (Seventh rule)
          if( currentSnapshot.n>0 )
          {
             ...
          }
          ...
          // (Eighth rule)
          retVal = 0 ;
          
          // (Ninth rule)
          continue;
          break; 
       case 1: 
          // (Seventh rule)
          currentSnapshot.test = retVal;
          currentSnapshot.test--;
          ...
          // (Eighth rule)
          retVal = currentSnapshot.test;

          // (Ninth rule)
          continue;
          break;
       }
    }
    // (Second rule)
    return retVal;
}


/* 第十步
为了模拟下一次递归函数的调用，你必须在当前循环函数里面再生成一个新的“Snapshot”结构体作为下一次调用的快照，初始化其参数以后压入栈，并“continue”。
如果当前调用在执行完成后还有一些事情需要处理，那么更改它的阶段状态“stage”到相应的过程，并在new Snapshot压入之前，把本次的“Snapshot”压入。
*/

// Recursive Function "Tenth rule" example
int SomeFunc(int n, int &retIdx)
{
   ...
   if(n>0)
   {
      int test = SomeFunc(n-1, retIdx);
      test--;
      ...
      return test;
   }
   ...
   return 0;
}

// Conversion to Iterative Function
int SomeFuncLoop(int n, int &retIdx)
{
     // (First rule)
    struct SnapShotStruct {
       int n;        // - parameter input
       int test;     // - local variable that will be used 
                     //     after returning from the function call
                     // - retIdx can be ignored since it is a reference.
       int stage;    // - Since there is process needed to be done 
                     //     after recursive call. (Sixth rule)
    };
    // (Second rule)
    int retVal = 0;  // initialize with default returning value
    // (Third rule)
    stack<SnapShotStruct> snapshotStack;
    // (Fourth rule)
    SnapShotStruct currentSnapshot;
    currentSnapshot.n= n;          // set the value as parameter value
    currentSnapshot.test=0;        // set the value as default value
    currentSnapshot.stage=0;       // set the value as initial stage
    snapshotStack.push(currentSnapshot);
    // (Fifth rule)
    while(!snapshotStack.empty())
    {
       currentSnapshot=snapshotStack.top();
       snapshotStack.pop();
       // (Sixth rule)
       switch( currentSnapshot.stage)
       {
       case 0:
          // (Seventh rule)
          if( currentSnapshot.n>0 )
          {
             // (Tenth rule)
             currentSnapshot.stage = 1;            // - current snapshot need to process after
                                                   //     returning from the recursive call
             snapshotStack.push(currentSnapshot);  // - this MUST pushed into stack before 
                                                   //     new snapshot!
             // Create a new snapshot for calling itself
             SnapShotStruct newSnapshot;
             newSnapshot.n= currentSnapshot.n-1;   // - give parameter as parameter given
                                                   //     when calling itself
                                                   //     ( SomeFunc(n-1, retIdx) )
             newSnapshot.test=0;                   // - set the value as initial value
             newSnapshot.stage=0;                  // - since it will start from the 
                                                   //     beginning of the function, 
                                                   //     give the initial stage
             snapshotStack.push(newSnapshot);
             continue;
          }
          ...
          // (Eighth rule)
          retVal = 0 ;
          
          // (Ninth rule)
          continue;
          break; 
       case 1: 
          // (Seventh rule)
          currentSnapshot.test = retVal;
          currentSnapshot.test--;
          ...
          // (Eighth rule)
          retVal = currentSnapshot.test;
          // (Ninth rule)
          continue;
          break;
       }
    }
    // (Second rule)
    return retVal;
}
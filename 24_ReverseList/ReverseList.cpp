/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// 《剑指Offer——名企面试官精讲典型编程题》代码
// 作者：何海涛
//==================================================================

// 面试题24：反转链表
// 题目：定义一个函数，输入一个链表的头结点，反转该链表并输出反转后链表的
// 头结点。

#include "../Utilities/List.h"
#include <cstdio>

ListNode *ReverseList(ListNode *pHead)
{
    if (!pHead)
        return nullptr;

    ListNode *pPre = nullptr;
    ListNode *pNode = pHead;
    while (pNode)
    {
        ListNode *pMid = pNode;
        pNode = pNode->m_pNext;
        pMid->m_pNext = pPre;
        pPre = pMid;
    }
    return pPre;
}

// ====================测试代码====================
ListNode *Test(ListNode *pHead)
{
    printf("The original list is: \n");
    PrintList(pHead);

    ListNode *pReversedHead = ReverseList(pHead);

    printf("The reversed list is: \n");
    PrintList(pReversedHead);

    return pReversedHead;
}

// 输入的链表有多个结点
void Test1()
{
    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode2 = CreateListNode(2);
    ListNode *pNode3 = CreateListNode(3);
    ListNode *pNode4 = CreateListNode(4);
    ListNode *pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);

    ListNode *pReversedHead = Test(pNode1);

    DestroyList(pReversedHead);
}

// 输入的链表只有一个结点
void Test2()
{
    ListNode *pNode1 = CreateListNode(1);

    ListNode *pReversedHead = Test(pNode1);

    DestroyList(pReversedHead);
}

// 输入空链表
void Test3()
{
    Test(nullptr);
}

int main(int argc, char *argv[])
{
    Test1();
    Test2();
    Test3();

    return 0;
}

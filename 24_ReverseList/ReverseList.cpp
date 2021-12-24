/*******************************************************************
Copyright(c) 2016, Harry He
All rights reserved.

Distributed under the BSD license.
(See accompanying file LICENSE.txt at
https://github.com/zhedahht/CodingInterviewChinese2/blob/master/LICENSE.txt)
*******************************************************************/

//==================================================================
// ����ָOffer�����������Թپ������ͱ���⡷����
// ���ߣ��κ���
//==================================================================

// ������24����ת����
// ��Ŀ������һ������������һ�������ͷ��㣬��ת�����������ת�������
// ͷ��㡣

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

// ====================���Դ���====================
ListNode *Test(ListNode *pHead)
{
    printf("The original list is: \n");
    PrintList(pHead);

    ListNode *pReversedHead = ReverseList(pHead);

    printf("The reversed list is: \n");
    PrintList(pReversedHead);

    return pReversedHead;
}

// ����������ж�����
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

// ���������ֻ��һ�����
void Test2()
{
    ListNode *pNode1 = CreateListNode(1);

    ListNode *pReversedHead = Test(pNode1);

    DestroyList(pReversedHead);
}

// ���������
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

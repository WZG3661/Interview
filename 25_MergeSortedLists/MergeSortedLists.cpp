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

// ������25���ϲ��������������
// ��Ŀ������������������������ϲ�����������ʹ�������еĽ����Ȼ�ǰ�
// �յ�������ġ���������ͼ3.11�е�����1������2����ϲ�֮���������������
// ��3��ʾ��

#include "../Utilities/List.h"
#include <cstdio>
#include <vector>

// ����������㣬�ֱ�ָ����������
// ���p1 > p2����p2->next=p1; p2++;
ListNode *Merge(ListNode *pHead1, ListNode *pHead2)
{
    if (!pHead1)
        return pHead2;
    if (!pHead2)
        return pHead1;

    ListNode *mergeHead = nullptr;
    if (pHead1->m_nValue < pHead2->m_nValue)
    {
        mergeHead = pHead1;
        mergeHead->m_pNext = Merge(pHead1->m_pNext, pHead2);
    }
    else
    {
        mergeHead = pHead2;
        mergeHead->m_pNext = Merge(pHead1, pHead2->m_pNext);
    }
    return mergeHead;
}

// // �ĸ����С�ʹ浽������
// ListNode *Merge(ListNode *pHead1, ListNode *pHead2)
// {
//     if (!pHead1)
//         return pHead2;
//     if (!pHead2)
//         return pHead1;

//     std::vector<ListNode *> vec;
//     ListNode *p1 = pHead1;
//     ListNode *p2 = pHead2;
//     while (p1 || p2)
//     {
//         if (!p2 || (p1 && p1->m_nValue <= p2->m_nValue))
//         {
//             vec.push_back(p1);
//             p1 = p1->m_pNext;
//         }
//         else if (!p1 || (p2 && p1->m_nValue > p2->m_nValue))
//         {
//             vec.push_back(p2);
//             p2 = p2->m_pNext;
//         }
//     }

//     if (vec.size())
//     {
//         for (int i = 0; i < vec.size() - 1; ++i)
//         {
//             vec[i]->m_pNext = vec[i + 1];
//         }
//         return vec[0];
//     }
//     else
//         return nullptr;
// }
// ====================���Դ���====================
ListNode *Test(char *testName, ListNode *pHead1, ListNode *pHead2)
{
    if (testName != nullptr)
        printf("%s begins:\n", testName);

    printf("The first list is:\n");
    PrintList(pHead1);

    printf("The second list is:\n");
    PrintList(pHead2);

    printf("The merged list is:\n");
    ListNode *pMergedHead = Merge(pHead1, pHead2);
    PrintList(pMergedHead);

    printf("\n\n");

    return pMergedHead;
}

// list1: 1->3->5
// list2: 2->4->6
void Test1()
{
    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode3 = CreateListNode(3);
    ListNode *pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode3);
    ConnectListNodes(pNode3, pNode5);

    ListNode *pNode2 = CreateListNode(2);
    ListNode *pNode4 = CreateListNode(4);
    ListNode *pNode6 = CreateListNode(6);

    ConnectListNodes(pNode2, pNode4);
    ConnectListNodes(pNode4, pNode6);

    ListNode *pMergedHead = Test("Test1", pNode1, pNode2);

    DestroyList(pMergedHead);
}

// �������������ظ�������
// list1: 1->3->5
// list2: 1->3->5
void Test2()
{
    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode3 = CreateListNode(3);
    ListNode *pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode3);
    ConnectListNodes(pNode3, pNode5);

    ListNode *pNode2 = CreateListNode(1);
    ListNode *pNode4 = CreateListNode(3);
    ListNode *pNode6 = CreateListNode(5);

    ConnectListNodes(pNode2, pNode4);
    ConnectListNodes(pNode4, pNode6);

    ListNode *pMergedHead = Test("Test2", pNode1, pNode2);

    DestroyList(pMergedHead);
}

// ��������ֻ��һ������
// list1: 1
// list2: 2
void Test3()
{
    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode2 = CreateListNode(2);

    ListNode *pMergedHead = Test("Test3", pNode1, pNode2);

    DestroyList(pMergedHead);
}

// һ������Ϊ������
// list1: 1->3->5
// list2: ������
void Test4()
{
    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode3 = CreateListNode(3);
    ListNode *pNode5 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode3);
    ConnectListNodes(pNode3, pNode5);

    ListNode *pMergedHead = Test("Test4", pNode1, nullptr);

    DestroyList(pMergedHead);
}

// ��������Ϊ������
// list1: ������
// list2: ������
void Test5()
{
    ListNode *pMergedHead = Test("Test5", nullptr, nullptr);
}

int main(int argc, char *argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();

    return 0;
}

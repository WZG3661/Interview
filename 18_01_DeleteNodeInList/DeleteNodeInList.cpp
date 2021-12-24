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

// ������18��һ������O(1)ʱ��ɾ��������
// ��Ŀ���������������ͷָ���һ�����ָ�룬����һ��������O(1)ʱ��ɾ����
// ��㡣

#include "../Utilities/List.h"
#include <cstdio>

// ���Ҫɾ������β��㣬���ͷ����ɾ��֮
// ���Ҫɾ������ͷ��㣬
// ���Ҫɾ���Ĳ���β��㣬������һ���ڵ��ֵ���Ƹ���ɾ���ڵ㣬��ɾ����һ���ڵ�
void DeleteNode(ListNode **pListHead, ListNode *pToBeDeleted)
{
    if (!pListHead || !pToBeDeleted)
        return;
    // Ҫɾ������β��㣬�Ҳ���ͷ��㣬���������ж�����
    if (!pToBeDeleted->m_pNext && *pListHead != pToBeDeleted)
    {
        ListNode *node = *pListHead;
        while (node->m_pNext != pToBeDeleted)
        {
            node = node->m_pNext;
        }
        node->m_pNext = nullptr;
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
    }
    // Ҫɾ������ͷ���
    else if (*pListHead == pToBeDeleted)
    {
        delete pToBeDeleted;
        pToBeDeleted = nullptr;
        *pListHead = nullptr;
    }
    // Ҫɾ���Ĳ���β���
    else
    {
        pToBeDeleted->m_nValue = pToBeDeleted->m_pNext->m_nValue;
        ListNode *del_node = pToBeDeleted->m_pNext;
        pToBeDeleted->m_pNext = del_node->m_pNext;
        delete del_node;
        del_node = nullptr;
    }
    return;
}

// ====================���Դ���====================
void Test(ListNode *pListHead, ListNode *pNode)
{
    printf("The original list is: \n");
    PrintList(pListHead);

    printf("The node to be deleted is: \n");
    PrintListNode(pNode);

    DeleteNode(&pListHead, pNode);

    printf("The result list is: \n");
    PrintList(pListHead);
}

// �������ж����㣬ɾ���м�Ľ��
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

    Test(pNode1, pNode3);

    DestroyList(pNode1);
}

// �������ж����㣬ɾ��β���
void Test2()
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

    Test(pNode1, pNode5);

    DestroyList(pNode1);
}

// �������ж����㣬ɾ��ͷ���
void Test3()
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

    Test(pNode1, pNode1);

    DestroyList(pNode1);
}

// ������ֻ��һ����㣬ɾ��ͷ���
void Test4()
{
    ListNode *pNode1 = CreateListNode(1);

    Test(pNode1, pNode1);
}

// ����Ϊ��
void Test5()
{
    Test(nullptr, nullptr);
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

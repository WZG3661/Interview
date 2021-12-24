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

// ������18��������ɾ���������ظ��Ľ��
// ��Ŀ����һ������������У����ɾ���ظ��Ľ�㣿���磬��ͼ3.4��a�����ظ�
// ��㱻ɾ��֮��������ͼ3.4��b����ʾ��

#include "../Utilities/List.h"
#include <cstdio>
#include <iostream>

// ���ñ���delVal��Ҫɾ���Ľ���ֵ
// ֻҪ��ǰ����ֵ������һ�ڵ��ֵ���͸���delVal
// ���ϱ�����ֱ����ǰ����ֵ������delVal
void DeleteDuplication(ListNode **pHead)
{
    if (!pHead)
        return;

    ListNode *pNode1 = nullptr;
    ListNode *pNode2 = *pHead; // ��ͷ��ʼ������ͷ����ظ�
    while (pNode2)
    {
        bool needDelete = false;
        while (pNode2->m_pNext && pNode2->m_nValue == pNode2->m_pNext->m_nValue)
        {
            needDelete = true;
            int delVal = pNode2->m_nValue;
            while (pNode2 && pNode2->m_nValue == delVal)
            {
                ListNode *delNode = pNode2;
                pNode2 = pNode2->m_pNext;
                delete delNode;
                delNode = nullptr;
            }
            if (!pNode2)
                break;
        }

        // pNode2��ɾ�������ظ��������һ����㣬������nullptr
        if (needDelete)
        {
            if (!pNode1)
                *pHead = pNode2;
            else
                pNode1->m_pNext = pNode2;
        }

        pNode1 = pNode2;
        if (pNode2)
            pNode2 = pNode2->m_pNext;
    }
}

// ====================���Դ���====================
void Test(char *testName, ListNode **pHead, int *expectedValues, int expectedLength)
{
    if (testName != nullptr)
        printf("%s begins: ", testName);

    DeleteDuplication(pHead);

    int index = 0;
    ListNode *pNode = *pHead;
    while (pNode != nullptr && index < expectedLength)
    {
        if (pNode->m_nValue != expectedValues[index])
            break;

        pNode = pNode->m_pNext;
        index++;
    }

    if (pNode == nullptr && index == expectedLength)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

// ĳЩ������ظ���
void Test1()
{
    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode2 = CreateListNode(2);
    ListNode *pNode3 = CreateListNode(3);
    ListNode *pNode4 = CreateListNode(3);
    ListNode *pNode5 = CreateListNode(4);
    ListNode *pNode6 = CreateListNode(4);
    ListNode *pNode7 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    ListNode *pHead = pNode1;

    int expectedValues[] = {1, 2, 5};
    Test("Test1", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

    DestroyList(pHead);
}

// û���ظ��Ľ��
void Test2()
{
    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode2 = CreateListNode(2);
    ListNode *pNode3 = CreateListNode(3);
    ListNode *pNode4 = CreateListNode(4);
    ListNode *pNode5 = CreateListNode(5);
    ListNode *pNode6 = CreateListNode(6);
    ListNode *pNode7 = CreateListNode(7);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    ListNode *pHead = pNode1;

    int expectedValues[] = {1, 2, 3, 4, 5, 6, 7};
    Test("Test2", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

    DestroyList(pHead);
}

// ����һ�����֮���������н���ֵ����ͬ
void Test3()
{
    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode2 = CreateListNode(1);
    ListNode *pNode3 = CreateListNode(1);
    ListNode *pNode4 = CreateListNode(1);
    ListNode *pNode5 = CreateListNode(1);
    ListNode *pNode6 = CreateListNode(1);
    ListNode *pNode7 = CreateListNode(2);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    ListNode *pHead = pNode1;

    int expectedValues[] = {2};
    Test("Test3", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

    DestroyList(pHead);
}

// ���н���ֵ����ͬ
void Test4()
{
    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode2 = CreateListNode(1);
    ListNode *pNode3 = CreateListNode(1);
    ListNode *pNode4 = CreateListNode(1);
    ListNode *pNode5 = CreateListNode(1);
    ListNode *pNode6 = CreateListNode(1);
    ListNode *pNode7 = CreateListNode(1);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);

    ListNode *pHead = pNode1;

    Test("Test4", &pHead, nullptr, 0);

    DestroyList(pHead);
}

// ���н�㶼�ɶԳ���
void Test5()
{
    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode2 = CreateListNode(1);
    ListNode *pNode3 = CreateListNode(2);
    ListNode *pNode4 = CreateListNode(2);
    ListNode *pNode5 = CreateListNode(3);
    ListNode *pNode6 = CreateListNode(3);
    ListNode *pNode7 = CreateListNode(4);
    ListNode *pNode8 = CreateListNode(4);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);
    ConnectListNodes(pNode7, pNode8);

    ListNode *pHead = pNode1;

    Test("Test5", &pHead, nullptr, 0);

    DestroyList(pHead);
}

// �����������֮��������㶼�ɶԳ���
void Test6()
{
    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode2 = CreateListNode(1);
    ListNode *pNode3 = CreateListNode(2);
    ListNode *pNode4 = CreateListNode(3);
    ListNode *pNode5 = CreateListNode(3);
    ListNode *pNode6 = CreateListNode(4);
    ListNode *pNode7 = CreateListNode(5);
    ListNode *pNode8 = CreateListNode(5);

    ConnectListNodes(pNode1, pNode2);
    ConnectListNodes(pNode2, pNode3);
    ConnectListNodes(pNode3, pNode4);
    ConnectListNodes(pNode4, pNode5);
    ConnectListNodes(pNode5, pNode6);
    ConnectListNodes(pNode6, pNode7);
    ConnectListNodes(pNode7, pNode8);

    ListNode *pHead = pNode1;

    int expectedValues[] = {2, 4};
    Test("Test6", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

    DestroyList(pHead);
}

// ������ֻ���������ظ��Ľ��
void Test7()
{
    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode2 = CreateListNode(2);

    ConnectListNodes(pNode1, pNode2);

    ListNode *pHead = pNode1;

    int expectedValues[] = {1, 2};
    Test("Test7", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

    DestroyList(pHead);
}

// �����ֻ��һ�����
void Test8()
{
    ListNode *pNode1 = CreateListNode(1);

    ConnectListNodes(pNode1, nullptr);

    ListNode *pHead = pNode1;

    int expectedValues[] = {1};
    Test("Test8", &pHead, expectedValues, sizeof(expectedValues) / sizeof(int));

    DestroyList(pHead);
}

// �����ֻ�������ظ��Ľ��
void Test9()
{
    ListNode *pNode1 = CreateListNode(1);
    ListNode *pNode2 = CreateListNode(1);

    ConnectListNodes(pNode1, pNode2);

    ListNode *pHead = pNode1;

    Test("Test9", &pHead, nullptr, 0);

    DestroyList(pHead);
}

// ������
void Test10()
{
    ListNode *pHead = nullptr;

    Test("Test10", &pHead, nullptr, 0);
}

int main(int argc, char *argv[])
{
    Test1();
    Test2();
    Test3();
    Test4();
    Test5();
    Test6();
    Test7();
    Test8();
    Test9();
    Test10();

    return 0;
}

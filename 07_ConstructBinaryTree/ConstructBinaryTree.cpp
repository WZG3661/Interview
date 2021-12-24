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

// ������7���ؽ�������
// ��Ŀ������ĳ��������ǰ���������������Ľ�������ؽ����ö�������������
// ���ǰ���������������Ľ���ж������ظ������֡���������ǰ���������{1,
// 2, 4, 7, 3, 5, 6, 8}�������������{4, 7, 2, 1, 5, 3, 8, 6}�����ؽ���
// ͼ2.6��ʾ�Ķ��������������ͷ��㡣

#include "../Utilities/BinaryTree.h"
#include <cassert>
#include <cstdio>
#include <exception>
#include <iostream>

// ������ǰ������ĵ�һ�����Ǹ��ڵ㣬������������ҵ���Ӧ��λ�ã�����ǰ��ľ������������ұߵ����������������ϵݹ�
BinaryTreeNode *ConstructCore(int *preorder, int *inorder, int pre_start, int pre_end, int in_start, int in_end);
BinaryTreeNode *Construct(int *preorder, int *inorder, int length)
{
    if (!preorder || !inorder || length <= 0)
        return nullptr;

    return ConstructCore(preorder, inorder, 0, length - 1, 0, length - 1);
}
BinaryTreeNode *ConstructCore(int *preorder, int *inorder, int pre_start, int pre_end, int in_start, int in_end)
{
    std::cout << pre_start << "  " << pre_end << "  " << in_start << "  " << in_end << std::endl;
    if (pre_start > pre_end)
        return nullptr;

    int root = preorder[pre_start];
    BinaryTreeNode *pRoot = CreateBinaryTreeNode(root);
    pRoot->m_pLeft = nullptr;
    pRoot->m_pRight = nullptr;
    if (pre_start == pre_end)
    {
        assert(in_start == in_end);
        assert(preorder[pre_start] == inorder[in_start]);
        return pRoot;
    }
    else
    {
        // ����inorder���ҵ����ڵ�
        for (int i = in_start; i <= in_end; ++i)
        {
            if (inorder[i] == root)
            {
                pRoot->m_pLeft = ConstructCore(preorder, inorder, pre_start + 1, pre_start + i - in_start, in_start, i - 1);
                pRoot->m_pRight = ConstructCore(preorder, inorder, pre_start + i - in_start + 1, pre_end, i + 1, in_end);
            }
        }
    }
    return pRoot;
}

// ====================���Դ���====================
void Test(char *testName, int *preorder, int *inorder, int length)
{
    if (testName != nullptr)
        printf("%s begins:\n", testName);

    printf("The preorder sequence is: ");
    for (int i = 0; i < length; ++i)
        printf("%d ", preorder[i]);
    printf("\n");

    printf("The inorder sequence is: ");
    for (int i = 0; i < length; ++i)
        printf("%d ", inorder[i]);
    printf("\n");

    try
    {
        BinaryTreeNode *root = Construct(preorder, inorder, length);
        PrintTree(root);

        DestroyTree(root);
    }
    catch (std::exception &exception)
    {
        printf("Invalid Input.\n");
    }
}

// ��ͨ������
//              1
//           /     \
//          2       3
//         /       / \
//        4       5   6
//         \         /
//          7       8
void Test1()
{
    const int length = 8;
    int preorder[length] = {1, 2, 4, 7, 3, 5, 6, 8};
    int inorder[length] = {4, 7, 2, 1, 5, 3, 8, 6};

    Test("Test1", preorder, inorder, length);
}

// ���н�㶼û�����ӽ��
//            1
//           /
//          2
//         /
//        3
//       /
//      4
//     /
//    5
void Test2()
{
    const int length = 5;
    int preorder[length] = {1, 2, 3, 4, 5};
    int inorder[length] = {5, 4, 3, 2, 1};

    Test("Test2", preorder, inorder, length);
}

// ���н�㶼û�����ӽ��
//            1
//             \ 
//              2
//               \ 
//                3
//                 \
//                  4
//                   \
//                    5
void Test3()
{
    const int length = 5;
    int preorder[length] = {1, 2, 3, 4, 5};
    int inorder[length] = {1, 2, 3, 4, 5};

    Test("Test3", preorder, inorder, length);
}

// ����ֻ��һ�����
void Test4()
{
    const int length = 1;
    int preorder[length] = {1};
    int inorder[length] = {1};

    Test("Test4", preorder, inorder, length);
}

// ��ȫ������
//              1
//           /     \
//          2       3
//         / \     / \
//        4   5   6   7
void Test5()
{
    const int length = 7;
    int preorder[length] = {1, 2, 4, 5, 3, 6, 7};
    int inorder[length] = {4, 2, 5, 1, 6, 3, 7};

    Test("Test5", preorder, inorder, length);
}

// �����ָ��
void Test6()
{
    Test("Test6", nullptr, nullptr, 0);
}

// ������������в�ƥ��
void Test7()
{
    const int length = 7;
    int preorder[length] = {1, 2, 4, 5, 3, 6, 7};
    int inorder[length] = {4, 2, 8, 1, 6, 3, 7};

    Test("Test7: for unmatched input", preorder, inorder, length);
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

    return 0;
}

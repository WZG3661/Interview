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

// 面试题7：重建二叉树
// 题目：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输
// 入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,
// 2, 4, 7, 3, 5, 6, 8}和中序遍历序列{4, 7, 2, 1, 5, 3, 8, 6}，则重建出
// 图2.6所示的二叉树并输出它的头结点。

#include "../Utilities/BinaryTree.h"
#include <cassert>
#include <cstdio>
#include <exception>
#include <iostream>

// 方法：前序遍历的第一个数是根节点，在中序遍历中找到对应的位置，则其前面的就是左子树，右边的则是右子树，不断递归
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
        // 遍历inorder，找到根节点
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

// ====================测试代码====================
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

// 普通二叉树
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

// 所有结点都没有右子结点
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

// 所有结点都没有左子结点
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

// 树中只有一个结点
void Test4()
{
    const int length = 1;
    int preorder[length] = {1};
    int inorder[length] = {1};

    Test("Test4", preorder, inorder, length);
}

// 完全二叉树
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

// 输入空指针
void Test6()
{
    Test("Test6", nullptr, nullptr, 0);
}

// 输入的两个序列不匹配
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

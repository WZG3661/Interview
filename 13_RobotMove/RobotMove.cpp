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

// 面试题13：机器人的运动范围
// 题目：地上有一个m行n列的方格。一个机器人从坐标(0, 0)的格子开始移动，它
// 每一次可以向左、右、上、下移动一格，但不能进入行坐标和列坐标的数位之和
// 大于k的格子。例如，当k为18时，机器人能够进入方格(35, 37)，因为3+5+3+7=18。
// 但它不能进入方格(35, 38)，因为3+5+3+8=19。请问该机器人能够到达多少个格子？

#include <cstdio>
#include <iostream>
#include <string.h>

// 从起点开始深度优先遍历
void movingCountCore(int threshold, int rows, int cols, int pos_i, int pos_j, int &count, bool *visited);
bool DigitSum(int threshold, int pos_i, int pos_j);

int movingCount(int threshold, int rows, int cols)
{
    if (threshold < 0 || rows <= 0 || cols <= 0)
        return 0;
    bool *visited = new bool[rows * cols];
    memset(visited, false, rows * cols);

    int count = 1;
    visited[0] = true;
    movingCountCore(threshold, rows, cols, 0, 0, count, visited);

    return count;
}

int next_move_i[4] = {-1, 1, 0, 0};
int next_move_j[4] = {0, 0, -1, 1};
void movingCountCore(int threshold, int rows, int cols, int pos_i, int pos_j, int &count, bool *visited)
{
    for (int k = 0; k < 4; ++k)
    {
        int next_i = pos_i + next_move_i[k];
        int next_j = pos_j + next_move_j[k];
        if (next_i < 0 || next_i >= rows || next_j < 0 || next_j >= cols)
            continue;
        if (!visited[next_i * rows + next_j] && DigitSum(threshold, next_i, next_j))
        {
            visited[next_i * rows + next_j] = true;
            movingCountCore(threshold, rows, cols, next_i, next_j, ++count, visited);
        }
    }
}

bool DigitSum(int threshold, int pos_i, int pos_j)
{
    int sum = 0;
    while (pos_i)
    {
        sum += pos_i % 10;
        pos_i /= 10;
    }
    while (pos_j)
    {
        sum += pos_j % 10;
        pos_j /= 10;
    }
    if (sum > threshold)
        return false;
    return true;
}
// ====================测试代码====================
void test(char *testName, int threshold, int rows, int cols, int expected)
{
    if (testName != nullptr)
        printf("%s begins: ", testName);

    if (movingCount(threshold, rows, cols) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

// 方格多行多列
void test1()
{
    test("Test1", 5, 10, 10, 21);
}

// 方格多行多列
void test2()
{
    test("Test2", 15, 20, 20, 359);
}

// 方格只有一行，机器人只能到达部分方格
void test3()
{
    test("Test3", 10, 1, 100, 29);
}

// 方格只有一行，机器人能到达所有方格
void test4()
{
    test("Test4", 10, 1, 10, 10);
}

// 方格只有一列，机器人只能到达部分方格
void test5()
{
    test("Test5", 15, 100, 1, 79);
}

// 方格只有一列，机器人能到达所有方格
void test6()
{
    test("Test6", 15, 10, 1, 10);
}

// 方格只有一行一列
void test7()
{
    test("Test7", 15, 1, 1, 1);
}

// 方格只有一行一列
void test8()
{
    test("Test8", 0, 1, 1, 1);
}

// 机器人不能进入任意一个方格
void test9()
{
    test("Test9", -10, 10, 10, 0);
}

int main(int agrc, char *argv[])
{
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    test7();
    test8();
    test9();

    return 0;
}

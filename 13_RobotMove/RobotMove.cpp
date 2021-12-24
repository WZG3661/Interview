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

// ������13�������˵��˶���Χ
// ��Ŀ��������һ��m��n�еķ���һ�������˴�����(0, 0)�ĸ��ӿ�ʼ�ƶ�����
// ÿһ�ο��������ҡ��ϡ����ƶ�һ�񣬵����ܽ�������������������λ֮��
// ����k�ĸ��ӡ����磬��kΪ18ʱ���������ܹ����뷽��(35, 37)����Ϊ3+5+3+7=18��
// �������ܽ��뷽��(35, 38)����Ϊ3+5+3+8=19�����ʸû������ܹ�������ٸ����ӣ�

#include <cstdio>
#include <iostream>
#include <string.h>

// ����㿪ʼ������ȱ���
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
// ====================���Դ���====================
void test(char *testName, int threshold, int rows, int cols, int expected)
{
    if (testName != nullptr)
        printf("%s begins: ", testName);

    if (movingCount(threshold, rows, cols) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

// ������ж���
void test1()
{
    test("Test1", 5, 10, 10, 21);
}

// ������ж���
void test2()
{
    test("Test2", 15, 20, 20, 359);
}

// ����ֻ��һ�У�������ֻ�ܵ��ﲿ�ַ���
void test3()
{
    test("Test3", 10, 1, 100, 29);
}

// ����ֻ��һ�У��������ܵ������з���
void test4()
{
    test("Test4", 10, 1, 10, 10);
}

// ����ֻ��һ�У�������ֻ�ܵ��ﲿ�ַ���
void test5()
{
    test("Test5", 15, 100, 1, 79);
}

// ����ֻ��һ�У��������ܵ������з���
void test6()
{
    test("Test6", 15, 10, 1, 10);
}

// ����ֻ��һ��һ��
void test7()
{
    test("Test7", 15, 1, 1, 1);
}

// ����ֻ��һ��һ��
void test8()
{
    test("Test8", 0, 1, 1, 1);
}

// �����˲��ܽ�������һ������
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

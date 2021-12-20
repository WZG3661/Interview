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

// ������4����ά�����еĲ���
// ��Ŀ����һ����ά�����У�ÿһ�ж����մ����ҵ�����˳������ÿһ�ж���
// �մ��ϵ��µ�����˳�����������һ������������������һ����ά�����һ��
// �������ж��������Ƿ��и�������

#include <cstdio>

// �����Ͻ�[0,c-1]��ʼ����
// if number > [0, c-1], cmp(number, [1, c-1]); elif number < [0, c-1], cmp(number, [0, c-2])
// until c < 0 || r >= rows
bool Find(int *matrix, int rows, int columns, int number)
{
    if (matrix == nullptr || rows <= 0 || columns <= 0)
        return false;
    int r = 0, c = columns - 1;
    while (r < rows && c >= 0)
    {
        if (matrix[r * columns + c] == number)
            return true;
        else if (matrix[r * columns + c] > number)
            c--;
        else
            r++;
    }
    return false;
}

// ====================���Դ���====================
void Test(char *testName, int *matrix, int rows, int columns, int number, bool expected)
{
    if (testName != nullptr)
        printf("%s begins: ", testName);

    bool result = Find(matrix, rows, columns, number);
    if (result == expected)
        printf("Passed.\n");
    else
        printf("Failed.\n");
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ�����������
void Test1()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test1", (int *)matrix, 4, 4, 7, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ�������������
void Test2()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test2", (int *)matrix, 4, 4, 5, false);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ�������������С������
void Test3()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test3", (int *)matrix, 4, 4, 1, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ�������������������
void Test4()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test4", (int *)matrix, 4, 4, 15, true);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ�������������С�����ֻ�С
void Test5()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test5", (int *)matrix, 4, 4, 0, false);
}

//  1   2   8   9
//  2   4   9   12
//  4   7   10  13
//  6   8   11  15
// Ҫ���ҵ������������������ֻ���
void Test6()
{
    int matrix[][4] = {{1, 2, 8, 9}, {2, 4, 9, 12}, {4, 7, 10, 13}, {6, 8, 11, 15}};
    Test("Test6", (int *)matrix, 4, 4, 16, false);
}

// ³���Բ��ԣ������ָ��
void Test7()
{
    Test("Test7", nullptr, 0, 0, 16, false);
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

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

// ������14��������
// ��Ŀ������һ������Ϊn���ӣ�������Ӽ���m�Σ�m��n����������n>1����m��1����
// ÿ�ε����ӵĳ��ȼ�Ϊk[0]��k[1]��������k[m]��k[0]*k[1]*��*k[m]���ܵ�����
// ���Ƕ��٣����統���ӵĳ�����8ʱ�����ǰ������ɳ��ȷֱ�Ϊ2��3��3�����Σ���
// ʱ�õ����ĳ˻�18��

#include <cmath>
#include <iostream>

// ====================��̬�滮====================
// int maxProductAfterCutting_solution1(int length)
// {
//     if (length == 1)
//         return 0;
//     if (length == 2)
//         return 1;
//     if (length == 3)
//         return 2;

//     int max = 0;
//     for (int i = 1; i < length; ++i)
//     {
//         int len1 = maxProductAfterCutting_solution1(i);
//         int len2 = maxProductAfterCutting_solution1(length - i);
//         if (i > len1)
//             len1 = i;
//         if (length - i > len2)
//             len2 = length - i;
//         int len = len1 * len2;
//         if (len > max)
//             max = len;
//     }
//     return max;
// }
int maxProductAfterCutting_solution1(int length)
{
    if (length == 1)
        return 0;
    if (length == 2)
        return 1;
    if (length == 3)
        return 2;

    int *storage = new int[length + 1];
    storage[0] = 0;
    storage[1] = 0;
    storage[2] = 1;
    storage[3] = 2;
    for (int i = 4; i <= length; ++i)
    {
        int max = 0;
        for (int j = 1; j <= i / 2; ++j)
        {
            int len1, len2;
            if (j > storage[j])
                len1 = j;
            if (i - j > storage[i - j])
                len2 = i - j;
            int len = len1 * len2;
            if (len > max)
                max = len;
        }
        storage[i] = max;
    }
    
    delete[] storage;
    return storage[length];
}

// ====================̰���㷨====================
int maxProductAfterCutting_solution2(int length)
{
    if (length < 2)
        return 0;
    if (length == 2)
        return 1;
    if (length == 3)
        return 2;

    // �����ܶ�ؼ�ȥ����Ϊ3�����Ӷ�
    int timesOf3 = length / 3;

    // ���������ʣ�µĳ���Ϊ4��ʱ�򣬲����ټ�ȥ����Ϊ3�����ӶΡ�
    // ��ʱ���õķ����ǰ����Ӽ��ɳ���Ϊ2�����Σ���Ϊ2*2 > 3*1��
    if (length - timesOf3 * 3 == 1)
        timesOf3 -= 1;

    int timesOf2 = (length - timesOf3 * 3) / 2;

    return (int)(pow(3, timesOf3)) * (int)(pow(2, timesOf2));
}

// ====================���Դ���====================
void test(const char *testName, int length, int expected)
{
    int result1 = maxProductAfterCutting_solution1(length);
    if (result1 == expected)
        std::cout << "Solution1 for " << testName << " passed." << std::endl;
    else
        std::cout << "Solution1 for " << testName << " FAILED." << std::endl;

    int result2 = maxProductAfterCutting_solution2(length);
    if (result2 == expected)
        std::cout << "Solution2 for " << testName << " passed." << std::endl;
    else
        std::cout << "Solution2 for " << testName << " FAILED." << std::endl;
}

void test1()
{
    int length = 1;
    int expected = 0;
    test("test1", length, expected);
}

void test2()
{
    int length = 2;
    int expected = 1;
    test("test2", length, expected);
}

void test3()
{
    int length = 3;
    int expected = 2;
    test("test3", length, expected);
}

void test4()
{
    int length = 4;
    int expected = 4;
    test("test4", length, expected);
}

void test5()
{
    int length = 5;
    int expected = 6;
    test("test5", length, expected);
}

void test6()
{
    int length = 6;
    int expected = 9;
    test("test6", length, expected);
}

void test7()
{
    int length = 7;
    int expected = 12;
    test("test7", length, expected);
}

void test8()
{
    int length = 8;
    int expected = 18;
    test("test8", length, expected);
}

void test9()
{
    int length = 9;
    int expected = 27;
    test("test9", length, expected);
}

void test10()
{
    int length = 10;
    int expected = 36;
    test("test10", length, expected);
}

void test11()
{
    int length = 50;
    int expected = 86093442;
    test("test11", length, expected);
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
    test10();
    test11();

    return 0;
}

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

// ������3�����������޸������ҳ��ظ�������
// ��Ŀ����һ������Ϊn+1����������������ֶ���1��n�ķ�Χ�ڣ�������������
// ����һ���������ظ��ġ����ҳ�����������һ���ظ������֣��������޸������
// ���顣���磬������볤��Ϊ8������{2, 3, 5, 4, 3, 2, 6, 7}����ô��Ӧ��
// ������ظ�������2����3��

#include <iostream>

// ����:
//        numbers:     һ����������
//        length:      ����ĳ���
// ����ֵ:
//        ����  - ������Ч�����������д����ظ������֣�����ֵΪ�ظ�������
//        ����  - ������Ч������������û���ظ�������
// ����1����¼ֵΪ[1,n/2]��Χ��Ԫ�ظ�����������ڸ÷�Χ����˵���ظ�Ԫ���ڸ÷�Χ�У��������÷�Χ���֣�����ȡ[n/2+1,n]�ķ�Χ��ֱ����ΧΪ1������count��Ϊ1
int countRange(const int *numbers, int length, int start, int end)
{
    int num = 0;
    for (int i = 0; i < length; ++i)
    {
        if (numbers[i] >= start && numbers[i] <= end)
            num++;
    }
    return num;
}
int getDuplication(const int *numbers, int length)
{
    if (numbers == nullptr || length < 0)
        return -1;
    for (int i = 0; i < length; ++i)
    {
        if (numbers[i] < 1 || numbers[i] >= length)
            return -1;
    }
    int start = 1;
    int end = length - 1;
    while (start <= end)
    {
        int middle = (start + end) >> 1;
        int num = countRange(numbers, length, start, middle);
        if (start == end)
        {
            if (num > 1)
                return start;
            else
                break;
        }
        if (num <= (middle - start + 1))
        {
            start = middle + 1;
        }
        else
            end = middle;
    }
    return -1;
}

// ====================���Դ���====================
void test(const char *testName, int *numbers, int length, int *duplications, int dupLength)
{
    int result = getDuplication(numbers, length);
    for (int i = 0; i < dupLength; ++i)
    {
        if (result == duplications[i])
        {
            std::cout << testName << " passed." << std::endl;
            return;
        }
    }
    std::cout << testName << " FAILED." << std::endl;
}

// ����ظ�������
void test1()
{
    int numbers[] = {2, 3, 5, 4, 3, 2, 6, 7};
    int duplications[] = {2, 3};
    test("test1", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// һ���ظ�������
void test2()
{
    int numbers[] = {3, 2, 1, 4, 4, 5, 6, 7};
    int duplications[] = {4};
    test("test2", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// �ظ�����������������С������
void test3()
{
    int numbers[] = {1, 2, 3, 4, 5, 6, 7, 1, 8};
    int duplications[] = {1};
    test("test3", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// �ظ�����������������������
void test4()
{
    int numbers[] = {1, 7, 3, 4, 5, 6, 8, 2, 8};
    int duplications[] = {8};
    test("test4", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// ������ֻ����������
void test5()
{
    int numbers[] = {1, 1};
    int duplications[] = {1};
    test("test5", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// �ظ�������λ�����鵱��
void test6()
{
    int numbers[] = {3, 2, 1, 3, 4, 5, 6, 7};
    int duplications[] = {3};
    test("test6", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// ����ظ�������
void test7()
{
    int numbers[] = {1, 2, 2, 6, 4, 5, 6};
    int duplications[] = {2, 6};
    test("test7", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// һ�������ظ�����
void test8()
{
    int numbers[] = {1, 2, 2, 6, 4, 5, 2};
    int duplications[] = {2};
    test("test8", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// û���ظ�������
void test9()
{
    int numbers[] = {1, 2, 6, 4, 5, 3};
    int duplications[] = {-1};
    test("test9", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// ��Ч������
void test10()
{
    int *numbers = nullptr;
    int duplications[] = {-1};
    test("test10", numbers, 0, duplications, sizeof(duplications) / sizeof(int));
}

int main()
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
    return 0;
}
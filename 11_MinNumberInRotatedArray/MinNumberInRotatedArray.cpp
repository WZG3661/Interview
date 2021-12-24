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

// 面试题11：旋转数组的最小数字
// 题目：把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。
// 输入一个递增排序的数组的一个旋转，输出旋转数组的最小元素。例如数组
// {3, 4, 5, 1, 2}为{1, 2, 3, 4, 5}的一个旋转，该数组的最小值为1。

#include <cstdio>
#include <exception>

// 比较第一个元素和最后一个元素， 如果第一个元素 < 最后一个元素，返回第一个元素
//                           如果第一个元素 > 最后一个元素，比较中间元素和最后一个元素
//                                                     如果中间元素 < 最后一个元素，继续取左边中间元素
//                                                     如果中间元素 > 最后一个元素，继续取右边中间元素
//                           如果第一个元素 = 最后一个元素，遍历整个数组
int FindMin(int *numbers, int start, int end)
{
    int min = numbers[start];
    for (int i = start; i <= end; ++i)
    {
        if (numbers[i] < min)
            min = numbers[i];
    }
    return min;
}
int Min(int *numbers, int length)
{
    if (!numbers || length <= 0)
        return 0;

    if (numbers[0] < numbers[length - 1]) // 第一个元素 < 最后一个元素
        return numbers[0];
    else if (numbers[0] == numbers[length - 1]) // 第一个元素 == 最后一个元素
    {
        return FindMin(numbers, 0, length - 1);
    }
    else // 第一个元素 > 最后一个元素
    {
        int start = 0;
        int end = length - 1;
        while (start < end)
        {
            int mid = (start + end) >> 1;
            if (numbers[mid] < numbers[end])
                end = mid;
            else if (numbers[mid] > numbers[end])
                start = mid + 1;
            else
            {
                return FindMin(numbers, start, end);
            }
        }
        return numbers[start];
    }
}

// ====================测试代码====================
void Test(int *numbers, int length, int expected)
{
    int result = 0;
    try
    {
        result = Min(numbers, length);

        for (int i = 0; i < length; ++i)
            printf("%d ", numbers[i]);

        if (result == expected)
            printf("\tpassed\n");
        else
            printf("\tfailed\n");
    }
    catch (...)
    {
        if (numbers == nullptr)
            printf("Test passed.\n");
        else
            printf("Test failed.\n");
    }
}

int main(int argc, char *argv[])
{
    // 典型输入，单调升序的数组的一个旋转
    int array1[] = {3, 4, 5, 1, 2};
    Test(array1, sizeof(array1) / sizeof(int), 1);

    // 有重复数字，并且重复的数字刚好的最小的数字
    int array2[] = {3, 4, 5, 1, 1, 2};
    Test(array2, sizeof(array2) / sizeof(int), 1);

    // 有重复数字，但重复的数字不是第一个数字和最后一个数字
    int array3[] = {3, 4, 5, 1, 2, 2};
    Test(array3, sizeof(array3) / sizeof(int), 1);

    // 有重复的数字，并且重复的数字刚好是第一个数字和最后一个数字
    int array4[] = {1, 0, 1, 1, 1};
    Test(array4, sizeof(array4) / sizeof(int), 0);

    // 单调升序数组，旋转0个元素，也就是单调升序数组本身
    int array5[] = {1, 2, 3, 4, 5};
    Test(array5, sizeof(array5) / sizeof(int), 1);

    // 数组中只有一个数字
    int array6[] = {2};
    Test(array6, sizeof(array6) / sizeof(int), 2);

    // 输入nullptr
    Test(nullptr, 0, 0);

    return 0;
}

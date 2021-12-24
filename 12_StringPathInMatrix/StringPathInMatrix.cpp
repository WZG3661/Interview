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

// ������12�������е�·��
// ��Ŀ�������һ�������������ж���һ���������Ƿ����һ������ĳ�ַ�������
// �ַ���·����·�����ԴӾ���������һ��ʼ��ÿһ�������ھ����������ҡ�
// �ϡ����ƶ�һ�����һ��·�������˾����ĳһ����ô��·�������ٴν���
// �ø��ӡ������������3��4�ľ����а���һ���ַ�����bfce����·����·���е���
// ĸ���»��߱�������������в������ַ�����abfb����·������Ϊ�ַ����ĵ�һ��
// �ַ�bռ���˾����еĵ�һ�еڶ�������֮��·�������ٴν���������ӡ�
// A B T G
// C F C S
// J D E H

#include <cstdio>
#include <iostream>
#include <stack>
#include <string.h>
#include <string>

using namespace std;

// ����ÿ��Ԫ�أ���Ϊ�ַ�������㣬Ȼ�󲻶�����·��
// ʹ��ͬ����С�ľ����¼��������λ��
bool FindPath(const char *matrix, int rows, int cols, int pos_i, int pos_j, const char *str, int str_count, bool *mark);

bool hasPath(const char *matrix, int rows, int cols, const char *str)
{
    if (!matrix || rows <= 0 || cols <= 0 || !str)
        return false;

    bool *mark = new bool[rows * cols];
    memset(mark, false, rows * cols);

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (matrix[i * cols + j] == str[0])
            {
                mark[i * cols + j] = true;
                if (FindPath(matrix, rows, cols, i, j, str, 1, mark))
                    return true;
                else
                    mark[i * cols + j] = false;
            }
        }
    }
    return false;
}

int next_pos_i[4] = {-1, 1, 0, 0};
int next_pos_j[4] = {0, 0, -1, 1};
bool FindPath(const char *matrix, int rows, int cols, int pos_i, int pos_j, const char *str, int str_count, bool *mark)
{
    if (str[str_count] == '\0')
        return true;

    for (int k = 0; k < 4; ++k)
    {
        int next_i = pos_i + next_pos_i[k];
        int next_j = pos_j + next_pos_j[k];
        if (next_i < 0 || next_i >= rows || next_j < 0 || next_j >= cols)
            continue;

        if (!mark[next_i * cols + next_j] && matrix[next_i * cols + next_j] == str[str_count])
        {
            mark[next_i * cols + next_j] = true;
            if (FindPath(matrix, rows, cols, next_i, next_j, str, str_count + 1, mark))
                return true;
            else
                mark[next_i * cols + next_j] = false;
        }
    }
    return false;
}
// ====================���Դ���====================
void Test(const char *testName, const char *matrix, int rows, int cols, const char *str, bool expected)
{
    if (testName != nullptr)
        printf("%s begins: ", testName);

    if (hasPath(matrix, rows, cols, str) == expected)
        printf("Passed.\n");
    else
        printf("FAILED.\n");
}

// ABTG
// CFCS
// JDEH

// BFCE
void Test1()
{
    const char *matrix = "ABTGCFCSJDEH";
    const char *str = "BFCE";

    Test("Test1", (const char *)matrix, 3, 4, str, true);
}

// ABCE
// SFCS
// ADEE

// SEE
void Test2()
{
    const char *matrix = "ABCESFCSADEE";
    const char *str = "SEE";

    Test("Test2", (const char *)matrix, 3, 4, str, true);
}

// ABTG
// CFCS
// JDEH

// ABFB
void Test3()
{
    const char *matrix = "ABTGCFCSJDEH";
    const char *str = "ABFB";

    Test("Test3", (const char *)matrix, 3, 4, str, false);
}

// ABCEHJIG
// SFCSLOPQ
// ADEEMNOE
// ADIDEJFM
// VCEIFGGS

// SLHECCEIDEJFGGFIE
void Test4()
{
    const char *matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char *str = "SLHECCEIDEJFGGFIE";

    Test("Test4", (const char *)matrix, 5, 8, str, true);
}

// ABCEHJIG
// SFCSLOPQ
// ADEEMNOE
// ADIDEJFM
// VCEIFGGS

// SGGFIECVAASABCEHJIGQEM
void Test5()
{
    const char *matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char *str = "SGGFIECVAASABCEHJIGQEM";

    Test("Test5", (const char *)matrix, 5, 8, str, true);
}

// ABCEHJIG
// SFCSLOPQ
// ADEEMNOE
// ADIDEJFM
// VCEIFGGS

// SGGFIECVAASABCEEJIGOEM
void Test6()
{
    const char *matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char *str = "SGGFIECVAASABCEEJIGOEM";

    Test("Test6", (const char *)matrix, 5, 8, str, false);
}

// ABCEHJIG
// SFCSLOPQ
// ADEEMNOE
// ADIDEJFM
// VCEIFGGS

// SGGFIECVAASABCEHJIGQEMS
void Test7()
{
    const char *matrix = "ABCEHJIGSFCSLOPQADEEMNOEADIDEJFMVCEIFGGS";
    const char *str = "SGGFIECVAASABCEHJIGQEMS";

    Test("Test7", (const char *)matrix, 5, 8, str, false);
}

// AAAA
// AAAA
// AAAA

// AAAAAAAAAAAA
void Test8()
{
    const char *matrix = "AAAAAAAAAAAA";
    const char *str = "AAAAAAAAAAAA";

    Test("Test8", (const char *)matrix, 3, 4, str, true);
}

// AAAA
// AAAA
// AAAA

// AAAAAAAAAAAAA
void Test9()
{
    const char *matrix = "AAAAAAAAAAAA";
    const char *str = "AAAAAAAAAAAAA";

    Test("Test9", (const char *)matrix, 3, 4, str, false);
}

// A

// A
void Test10()
{
    const char *matrix = "A";
    const char *str = "A";

    Test("Test10", (const char *)matrix, 1, 1, str, true);
}

// A

// B
void Test11()
{
    const char *matrix = "A";
    const char *str = "B";

    Test("Test11", (const char *)matrix, 1, 1, str, false);
}

void Test12()
{
    Test("Test12", nullptr, 0, 0, nullptr, false);
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
    Test11();
    Test12();

    return 0;
}

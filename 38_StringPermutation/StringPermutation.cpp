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

// ������38���ַ���������
// ��Ŀ������һ���ַ�������ӡ�����ַ������ַ����������С����������ַ���abc��
// ���ӡ�����ַ�a��b��c�������г����������ַ���abc��acb��bac��bca��cab��cba��

#include <cstdio>
#include <iostream>
#include <string.h>
#include <string>
#include <vector>
//===================================����һ
//��visited��¼�Ƿ������
void PermutationCore(char *pStr, std::string &part, int str_len, int visit_num, bool *visited,
                     std::vector<std::string> &permutations);
void Permutation(char *pStr)
{
    if (!pStr)
        return;

    int str_len = 0;
    for (int i = 0; pStr[i] != '\0'; i++)
        str_len++;
    bool *visited = new bool[str_len];
    memset(visited, false, str_len);

    std::vector<std::string> permutations;
    std::string part;
    PermutationCore(pStr, part, str_len, 0, visited, permutations);
    return;
}
void PermutationCore(char *pStr, std::string &part, int str_len, int visit_num, bool *visited,
                     std::vector<std::string> &permutations)
{
    if (visit_num == str_len)
    {
        // std::cout << "\n";
        permutations.push_back(part);
        return;
    }

    for (int i = 0; pStr[i] != '\0'; ++i)
    {
        if (visited[i])
            continue;

        // std::cout << pStr[i];
        part.push_back(pStr[i]);
        visited[i] = true;
        visit_num++;
        PermutationCore(pStr, part, str_len, visit_num, visited, permutations);
        part.pop_back();
        visited[i] = false;
        visit_num--;
    }
}
//================================������
// ����λ��
// void Permutation(char *pStr, char *pBegin);
// void Permutation(char *pStr)
// {
//     if (pStr == nullptr)
//         return;

//     Permutation(pStr, pStr);
// }

// void Permutation(char *pStr, char *pBegin)
// {
//     if (*pBegin == '\0')
//     {
//         printf("%s\n", pStr);
//     }
//     else
//     {
//         for (char *pCh = pBegin; *pCh != '\0'; ++pCh)
//         {
//             char temp = *pCh;
//             *pCh = *pBegin;
//             *pBegin = temp;

//             Permutation(pStr, pBegin + 1);

//             temp = *pCh;
//             *pCh = *pBegin;
//             *pBegin = temp;
//         }
//     }
// }
// ====================���Դ���====================
void Test(char *pStr)
{
    if (pStr == nullptr)
        printf("Test for nullptr begins:\n");
    else
        printf("Test for %s begins:\n", pStr);

    Permutation(pStr);

    printf("\n");
}

int main(int argc, char *argv[])
{
    Test(nullptr);

    char string1[] = "";
    Test(string1);

    char string2[] = "a";
    Test(string2);

    char string3[] = "ab";
    Test(string3);

    char string4[] = "abc";
    Test(string4);

    char string5[] = "abcd";
    Test(string5);

    return 0;
}

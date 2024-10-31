#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct node
{
    char* pStr;
    struct node* pNext;
}LNode;

void listInit(LNode** pHead)
{
    (*pHead) = (LNode*)malloc(sizeof(LNode));
    (*pHead)->pNext = NULL;
    (*pHead)->pStr = NULL;
}

void listInsert(LNode* pHead, char* pStrNeeded)
{
    int length = strlen(pStrNeeded);
    LNode* pNode = (LNode*)malloc(sizeof(LNode));
    pNode->pStr = (char*)malloc(sizeof(char) * 21);//每个单词最长20个字母
    strcpy(pNode->pStr, pStrNeeded);
    pNode->pNext = pHead->pNext;//将节点插入链首
    pHead->pNext = pNode;
}

void listShow(LNode* pHead)
{
    /*对字符串中的所有单词进行倒排,新插入的
    节点总在前端，所以从链首开始输出，则为
    倒排。*/
    LNode* pNode = NULL;
    pNode = pHead->pNext;
    while (pNode)
    {
        printf("%s", pNode->pStr);
        if (pNode->pNext)//如果是最后一个单词，则不输出空格。
        {
            printf(" ");
        }
        else
            printf("\n");
        pNode = pNode->pNext;
    }
}

void listFree(LNode** pHead)
{
    LNode* pNode = (*pHead)->pNext;
    LNode* pNodeTemp = NULL;
    while (pNode)//释放链表的所有节点空间，包括申请的字符串空间
    {
        pNodeTemp = pNode;
        pNode = pNode->pNext;
        free(pNodeTemp->pStr);
        free(pNodeTemp);
    }
    free((*pHead));//节点全部释放之后，回收首节点空间
}

int main()
{
    LNode* pHead = NULL;
    int length = 0;
    int idx = 0, idy = 0;
    char str[5000] = { '\0' };
    char strTemp[21] = { '\0' };
    while (gets(str))
    {
        idx = 0;
        listInit(&pHead);//初始化一个链表头
        length = strlen(str);
        for (; idx < length;)
        {
            while (isalpha(str[idx]))
            {
                strTemp[idy++] = str[idx++];
            }
            strTemp[idy] = '\0';
            if(idy != 0)
                listInsert(pHead, strTemp);
            memset(strTemp, 0, sizeof(char) * 21);
            idy = 0;
            idx++;//跳过空格
        }
        listShow(pHead);
        listFree(&pHead);
    }
    return 0;
}
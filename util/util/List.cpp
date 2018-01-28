//
//  List.cpp
//  util
//
//  Created by Bass小森 on 2018/1/28.
//  Copyright © 2018年 Bass小森. All rights reserved.
//

#include "List.h"
#include <stdio.h>
#include <stdlib.h>

//创建一个节点
ListNode* CreateListNode(int value){
    ListNode* pNode = new ListNode();
    pNode->m_nValue = value;
    pNode->m_pNext = nullptr;
    return pNode;
}

//链接节点
void ConnectListNode(ListNode* pCurrent,ListNode* pNext){
    if(pCurrent == nullptr){
        printf("error connect\n");
        exit(1);
    }
    pCurrent->m_pNext=pNext;//赋值地址
}

//打印节点的值
void PrintListNode(ListNode* pNode){
    if(pNode==nullptr){
        printf("The node is null\n");
    }else{
        printf("The value in node is %d.\n",pNode->m_nValue);
    }
}

//打印链表 通过头指针索引
void PrintList(ListNode* pHead){
    printf("\n PrintList is start.\n");
    
    ListNode* pNode = pHead;
    while (pNode != nullptr) {
        printf("%d\t",pNode->m_nValue);
        pNode=pNode->m_pNext;
    }
    
    printf("\nPrintList ends.\n");
}

//销毁链表
void DestroyList(ListNode* pHead){
    ListNode* pNode = pHead;
    while(pNode != NULL)
    {
        pHead = pHead->m_pNext;
        delete pNode;
        pNode = pHead;
    }
}

//向单向链表末尾添加节点
void AddToTail(ListNode** pHead,int value){
    //先创建准备添加的节点
    ListNode* pNew = new ListNode();
    pNew->m_nValue = value;
    pNew->m_pNext = nullptr;
    
    //如果是空链表
    if (pHead==nullptr) {
        *pHead = pNew;
    }else{//非空,找到最后的节点
        ListNode* pNode = *pHead;
        while (pNode!=nullptr) {
            pNode=pNode->m_pNext;
        }
        pNode->m_pNext=pNew;
    }
}

//在链表中找到第一个含有某值的结点并删除该结点
void RemoveNode(ListNode** pHead, int value)
{
    //空链表
    if(pHead == nullptr || *pHead == nullptr)
        return;
    
    ListNode* pToBeDeleted = nullptr;
    //如果要删除的结点为首结点
    if((*pHead)->m_nValue == value)
    {
        pToBeDeleted = *pHead;
        *pHead = (*pHead)->m_pNext;
    }
    else
    {
        ListNode* pNode = *pHead;
        //退出while循环的条件是（1）到达尾结点
        //（2) 找到与value匹配的结点
        //pNode指向将被删结点的前一个结点
        while(pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue != value)
            pNode = pNode->m_pNext;
        
        //注意if条件内容
        if(pNode->m_pNext != nullptr && pNode->m_pNext->m_nValue == value)
        {
            pToBeDeleted = pNode->m_pNext;//先断开，后删除
            pNode->m_pNext = pNode->m_pNext->m_pNext;
        }
        
        //确定存在与valude值匹配的将要删除的结点
        if(pToBeDeleted!= nullptr)
        {
            delete pToBeDeleted;
            pToBeDeleted = nullptr;
        }
    }
}

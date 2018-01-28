//
//  List.h
//  util
//
//  Created by Bass小森 on 2018/1/28.
//  Copyright © 2018年 Bass小森. All rights reserved.
//

#ifndef List_h
#define List_h

struct ListNode{
    int m_nValue;
    ListNode* m_pNext;
};
 ListNode* CreateListNode(int value);
 void ConnectListNodes(ListNode* pCurrent,ListNode* pNext);
 void PrintListNode(ListNode* pNode);
 void PrintList(ListNode* pHead);
 void DestroyList(ListNode* pHead);
 void AddToTail(ListNode** pHead, int value);
 void RemoveNode(ListNode** pHead, int value);

#endif /* List_h */


//
//  main.cpp
//  SwordForOffer04
//
//  Created by Bass小森 on 2018/1/27.
//  Copyright © 2018年 Bass小森. All rights reserved.
//

#include <iostream>
#include <stack>
using namespace std;

struct ListNode {
    int key;
    ListNode* next;
};
//非递归实现
void PrintList(ListNode* pHead){
    stack<ListNode*> nodes;
    
    ListNode*pNode=pHead;
    while (pNode!=nullptr) {
        nodes.push(pNode);
        pNode=pNode->next;
    }
    
    while(!nodes.empty()){
        pNode=nodes.top();
        printf("%d\t",pNode->key);
        nodes.pop();
    }
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

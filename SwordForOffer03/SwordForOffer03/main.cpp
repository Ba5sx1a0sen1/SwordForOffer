//
//  main.cpp
//  SwordForOffer03
//
//  Created by Bass小森 on 2018/1/23.
//  Copyright © 2018年 Bass小森. All rights reserved.
//

#include <iostream>

class Solution {
public:
    void replaceSpace(char *str,int length) {
        if(str == nullptr||length<=0){
            return;
        }
        
        //定义实际长度
        int originalLength = 0;
        int numberOfBlank = 0;
        int i = 0;
        while(str[i]!='\0'){
            ++originalLength;
            if(str[i]==' '){
                ++numberOfBlank;
            }
            ++i;
        }
        //替换
        int newLength = originalLength + numberOfBlank*2;
        if(newLength > length)
            return;
        
        int indexOfOriginal = originalLength;
        int indexOfNew = newLength;
        while(indexOfOriginal >=0 && indexOfNew > indexOfOriginal)
        {
            if(str[indexOfOriginal]==' '){
                str[indexOfNew--]='0';
                str[indexOfNew--]='2';
                str[indexOfNew--]='%';
                
            }else{
                str[indexOfNew--]=str[indexOfOriginal];
            }
            --indexOfOriginal;
        }
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

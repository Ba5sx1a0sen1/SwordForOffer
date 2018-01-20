//
//  main.cpp
//  SwordForOffer01
//
//  Created by Bass小森 on 2018/1/20.
//  Copyright © 2018年 Bass小森. All rights reserved.
//

#include <iostream>

//在一个长度为n的数组里的所有数字都在0~n-1的范围内。统计其中的重复数字。
bool duplicate(int numbers[],int length,int* duplication){
    if(numbers==nullptr||length<=0){
        return false;
    }
    for (int i=0; i<length; i++) {
        if (numbers[i]<0||numbers[i]>length-1) {
            //遍历数组，若出现不满足条件的数字（小于0，大于数组最大下标），则跳出循环
            return false;
        }
    }
    for (int i=0; i<length; i++) {
        while (numbers[i]!=i) {
            if(numbers[i]==numbers[numbers[i]]){
                *duplication=numbers[i];
                return true;
            }
            //交换数字,让数字等于其下标数字
            int temp = numbers[i];
            numbers[i]=numbers[temp];
            numbers[temp]=temp;
        }
    }
    return false;
}


int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

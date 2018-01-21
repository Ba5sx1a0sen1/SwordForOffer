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

// ====================测试代码====================
bool contains(int array[], int length, int number)
{
    for(int i = 0; i < length; ++i)
    {
        if(array[i] == number)
            return true;
    }
    
    return false;
}

void test(char* testName, int numbers[], int lengthNumbers, int expected[], int expectedExpected, bool validArgument)
{
    printf("%s begins: ", testName);
    
    int duplication;
    bool validInput = duplicate(numbers, lengthNumbers, &duplication);
    
    if(validArgument == validInput)
    {
        if(validArgument)
        {
            if(contains(expected, expectedExpected, duplication))
                printf("Passed.\n");
            else
                printf("FAILED.\n");
        }
        else
            printf("Passed.\n");
    }
    else
        printf("FAILED.\n");
}

// 重复的数字是数组中最小的数字
void test1()
{
    int numbers[] = { 2, 1, 3, 1, 4 };
    int duplications[] = { 1 };
    test("Test1", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// 重复的数字是数组中最大的数字
void test2()
{
    int numbers[] = { 2, 4, 3, 1, 4 };
    int duplications[] = { 4 };
    test("Test2", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// 数组中存在多个重复的数字
void test3()
{
    int numbers[] = { 2, 4, 2, 1, 4 };
    int duplications[] = { 2, 4 };
    test("Test3", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), true);
}

// 没有重复的数字
void test4()
{
    int numbers[] = { 2, 1, 3, 0, 4 };
    int duplications[] = { -1 }; // not in use in the test function
    test("Test4", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

// 没有重复的数字
void test5()
{
    int numbers[] = { 2, 1, 3, 5, 4 };
    int duplications[] = { -1 }; // not in use in the test function
    test("Test5", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int), false);
}

// 无效的输入
void test6()
{
    int* numbers = nullptr;
    int duplications[] = { -1 }; // not in use in the test function
    test("Test6", numbers, 0, duplications, sizeof(duplications) / sizeof(int), false);
}

int main(int argc, const char * argv[]) {
    // insert code here...
    //进行测试用例;
    test1();
    test2();
    test3();
    test4();
    test5();
    test6();
    return 0;
}

//
//  main.cpp
//  SwordForOffer02
//
//  Created by Bass小森 on 2018/1/21.
//  Copyright © 2018年 Bass小森. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;
//从右上角扫描方法
bool Find(int* matrix,int rows,int columns,int number)
{
    bool found = false;
    if(matrix!=nullptr&&rows>0&&columns>0){
        int row=0;//从第0行开始扫描
        int column = columns - 1;//定义最后一列的索引
        while (row<rows&&column>=0) {
            if(matrix[row * columns+column]==number){
                found=true;
                break;
            }
            else if(matrix[row * columns + column]>number){
                --column;//剔除本列
            }
            else
                ++row;//扫描下一行
        }
    }
    return found;
}
//从左下角扫描方法
bool Find2(int* matrix,int rows,int columns,int number)
{
    bool found = false;
    if(matrix!=nullptr&&rows>0&&columns>0){
        int row=rows-1;//从最后的行开始扫描
        int column = 0;//定义第一列的索引
        while (row<rows&&column>=0) {
            if(matrix[row * columns+column]==number){
                found=true;
                break;
            }
            else if(matrix[row * columns + column]>number){
                row--;//剔除本行
            }
            else
                column++;//扫描下一列
        }
    }
    return found;
}

bool Find(int target, vector< vector<int> > array) {
    bool found = false;
    
    return found;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

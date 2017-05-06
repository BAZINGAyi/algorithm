#include <iostream>
using namespace std;
/**
    注意判断最后一圈的状况
 1. 以圈的形式打印 需要确定圈数 通过规律发现最后一圈的起点的 x 坐标不大于 2 * 行数 或 y 坐标不大于 2 * 列数
 2. 判断最后一圈的状况 ，肯能不是完整的一圈
 **/


void PrintMatrixInCircle(int (*numbers)[3], int columns, int rows, int start){
    int starty = start;
    int endy = rows-1-start; // 结束的纵坐标
    int startx = start;
    int endx = columns-1-start ;// 结束的横坐标
    
    // 打印上面的行
    for(int i = startx; i <= endx; i++){
        cout<<numbers[startx][i]<<endl;
    }
    
    // 打印右面的一列 每一行的个数不为一
    if(starty < endy){
        for(int i = starty + 1; i <= endy; i++){
            cout<<numbers[i][endx]<<endl;
        }
    }
    
    // 打印下面的行 每一行的个数不为1 每一列的个数不为一
    if(startx < endx && startx < endy){
        for(int i = endx-1; i >= startx; i--){
            cout<<numbers[endy][i]<<endl;
        }
    }
    
    // 打印左面的一列 一行中列的个数至少为 2
    if(startx < endx && starty < endy -1){
        for(int i = endy-1; i >= starty +1; i--){
            cout<<numbers[i][starty]<<endl;
        }
    }
}


void PrintMatrixClockwisely(int (*numbers)[3], int columns, int rows){
    
    if(numbers == NULL || columns <= 0 || rows <=0)
        return;
    
    int start = 0;
    
    while (columns > start * 2 && rows > start * 2) {
        PrintMatrixInCircle(numbers,columns,rows,start);
        ++start;
    }
}

int main(int argc, const char * argv[]) {
    
    int a[1][3]={1,2,3};

    PrintMatrixInCircle(a, 3, 1, 0);
    
    return 0;
}

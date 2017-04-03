#include <iostream>

using namespace std;

#include <memory>

#include<string.h>

void PrintNumber(char* number);

bool Increment(char* number);

void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index);

// 正常解法

void Print1ToMaxOfNDigits_1(int n){
    
    if(n <= 0)
        
        return;
    
    char *number = new char[n + 1]; //注意申请的 n+1 包含‘\0’ 另外 news 和 delete 搭配 申请的是堆内存
    
    memset(number, '0', n);
    
    number[n] = '\0';
    
    while(Increment(number)){
    
        PrintNumber(number);
        
    }
    
}

bool Increment(char* number){
    
    int takeOver = 0; //进位
    
    int overFlow = true; //溢出
    
    int length = strlen(number);
    
    for (int i = length - 1; i >= 0; i--) {
        
        int sum = number[i] - '0' + takeOver;
        
        if(i == length - 1) //只有第一次进来才加一
            
            sum++;
        
        if(sum >= 10){
            
            if(i == 0)
            
                overFlow = false;
            
            else{
                
                sum = sum - 10;
                
                takeOver = 1;
                
                number[i] = sum + '0';  // 到 10 后归零
                
            }
            
        }else{
            
            number[i] = '0' + sum;
            
            break;
        }
        
    }
    
    return overFlow;

}

void PrintNumber(char* number ){
    
    int length = strlen(number);
    
    int control = true;
    
    for(int i = 0; i <= length - 1; i++){
    
        // 只有遇到第一个非0字符才打印
        if(control == true && number[i] != '0')
            
            control = false;
        
        if(!control)
            
            cout<<number[i];
        
    }
    
    cout<<" ";
    
}


// 快速解法 1-9 的全排列
// 从第一位开始依次确定从 0 到 9，然后第二位，第三位
void Print1ToMaxOfNDigits_2(int n){
    
    if(n <= 0)
        
        return;
    
    char * number = new char[n+1];
    
    number[n] = '\0';
    
    for(int i = 0; i<10; i++){
    
        number[0] = i + '0';
        
        Print1ToMaxOfNDigitsRecursively(number, n, 0);
        
    }

}

void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index){

    if(index == length - 1){
        
        PrintNumber(number);
        
        return ;
    }
    
    for (int i = 0; i < 10; i++) {
        
        number[index + 1]= i + '0';
        
        Print1ToMaxOfNDigitsRecursively(number, length, index + 1);
    }
}

int main(int argc, const char * argv[]) {
    
    int n = 3;
    
    Print1ToMaxOfNDigits_1(n);
    
    Print1ToMaxOfNDigits_2(n);
    
    return 0;
}

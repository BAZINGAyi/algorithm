// 大数相加问题
#include <iostream>

using namespace  std;

#include <string.h>

#include <stdio.h>

// 100 位的两个数相加最大为 101位 还需要一位 ‘\0’
#define MAXSIZE 20

#define AINDEX 0    // a 数组有符号出现

#define BINDEX 1    // b 数组没有符号出现

void bigNumberAdd(char a [] , char b [], char sum[]){
    
    int takeOver = 0; // 进位

    char m[MAXSIZE] = {0};  // 数组初始化为 0
    
    char n[MAXSIZE] = {0};
    
    memset(sum, 0, MAXSIZE * sizeof(char));
    
     // 1. 字符串反转并变成数字
    
    int i;
    
    int lenA = strlen(a);
    
    int lenB = strlen(b);
    
    for (i = 0; i < lenA; i++)
            
        m[i] = a[lenA - 1 - i] - '0';
    
    
    for (i = 0; i < lenB; i++)
        
        n[i] = b[lenB - 1 - i] - '0';
    
    // 2.  进行位运算
    for(i = 0; i < lenA || i < lenB; i++){
    
        sum[i] = (m[i] + n[i] + takeOver) % 10 + '0';
        
        takeOver = (m[i] + n[i] + takeOver) / 10; // 得到进位
    
    }
    
    // 如果有进位的情况
    if ( takeOver != 0)
    {
        sum[i] = 1 + '0';
    }
    

}

void printfNUmber(char sum[]){

    for (int i = strlen(sum) - 1; i >= 0; i--)
        
        cout<<sum[i];
}

void sub(char max [] , char min [], char sum[], int index){
    
    
    int maxLength = strlen(max);
    
    int minLength = strlen(min);
    
    int borrow = 0;
    
    while (minLength > 0) {
        
        int d1 = min[minLength - 1] - '0';
        
        int d2 = max[maxLength - 1] - '0';
        
        if(borrow) d2--;
        
        borrow = d2 >= d1 ? 0 : 1;
        
        d2 += d2 >= d1 ? 0 : 10;
        
        sum[maxLength] = (d2 - d1) + '0'; // 注意这不需要减 1
        
        maxLength--;
        
        minLength--;
        
    }
    

    
    
    while(maxLength){ // a 的长度大于 b
        
        int d1 = max[maxLength - 1] - '0';
        
        if(borrow) d1--;
        
        borrow = d1 >=0 ? 0 : 1;
        
        d1 += d1 >=0 ? 0 : 10;
        
        sum[maxLength] = d1 + '0';
        
        maxLength--;
    }
    
    if(borrow > 0)
        
        sum[0] = '1';
    
    else
       
        sum[0] = '0';
    
    
    cout<<sum;
//    if(AINDEX == index){
//        
//     //   cout<<"-";
//    
//        printfNUmber(sum);
//    
//    }else if(BINDEX == index)
//
//        printfNUmber(sum);
}



void dosubtraction(char a [] , char b [], char sum[], int index){
    
    memset(sum, 0, MAXSIZE * sizeof(char)); // 不要忘记这句话
    
    if(strlen(a) > strlen(b))
        
        sub(a, b, sum, index);
    
    else if(strlen(a) < strlen(b))
        
        sub(b, a, sum, index);
    
    else{
        
        int res = strcmp(a, b);
        
        if(res == 0)
            
            cout<<"0"<<endl;
        
        else if(res > 0)
            
            sub(a, b, sum, index);
        
        else
    
            sub(b, a, sum, index);
    
    }
        
    

}
int main(int argc, const char * argv[]) {
    
    int n = 3;
    
    char a[MAXSIZE] = {0};
    
    char b[MAXSIZE] = {0};
    
    char sum[MAXSIZE] ={0} ;
    
    gets(a);
    
    gets(b);
    
//    dec(a,b,sum);
    
    sub(a,b,sum,AINDEX);

    
  
    

    
//    if(a[0] == '-' && b[0] != '-'){ // 去掉 a 负号
//        
//        char a1[MAXSIZE] = {0};
//        
//        for (int i = 1; i < strlen(a); i++)
//            
//            a1[i-1] = a[i];
//        
//        dosubtraction(a1,b,sum,AINDEX);
//        
//    }else if(a[0] != '-' && b[0] == '-'){ // 去掉 b 负号
//        
//        char b1[MAXSIZE] = {0};
//        
//        for (int i = 1; i < strlen(b); i++)
//            
//            b1[i-1] = b[i];
//        
//        dosubtraction(b1,a,sum,BINDEX);
//        
//    }else if(a[0] == '-' && b[0] == '-'){
//        
//        char a1[MAXSIZE] = {0};
//        
//        char b1[MAXSIZE] = {0};
//        
//        for (int i = 1; i < strlen(a); i++)
//            
//            a1[i-1] = a[i];
//        
//        for (int i = 1; i < strlen(b); i++)
//            
//            b1[i-1] = b[i];
//        
//        cout<<'-';
//        
//        bigNumberAdd(a1, b1, sum);
//        
//        printfNUmber(sum);
//        
//    }else {
//        
//        bigNumberAdd(a, b, sum);
//        
//        printfNUmber(sum);
//        
//    }

    return 0;
}

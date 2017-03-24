#include <iostream>

using namespace std;

int NumberOf1(int n){

    int count = 0;
    
    unsigned int flag = 1;
    
    while(flag){
        
        if( n & flag)
            
            count++;
        
        flag = flag << 1;
    }
    
    return count;

}
// 思想：
// 一个数减去 1 后，与原数相与，得到的是原数最右边少一个 1 的结果。
// 例如原数为：1100 减一后：1011 相与后得到：1000
// 也就说明原数能减几次 1 就证明含有几个 1
int NUmberOf1_method2(int n){
    
    int count = 0;
    
    while(n){
    
        n = n & (n - 1);
        
        count++;
        
    }
    
    return count;
}

// 问题：用一条语句判断一个整数是不是 2 的整数次方。
// 思路：一个整数如果是 2 的整数次方，那么她的二进制表示中有切只能有 1 位是 1 其它位都是 0 。

bool judge_IntegerPowerOf2(int n){
    
    return (n = n & (n-1)) == 0 ? true : false;
}

// 问题：输入两个整数 m，n，计算需要改变 m 的二进制表示中的多少位才能得到 n 。
// 思路：两个数进行异或运算，然后统计结果中 1 的个数。

int get1(int m, int n){
    
    int p = m ^ n;
    
    return NUmberOf1_method2(p);
}

int main(int argc, const char * argv[]) {
    
    int count = NumberOf1(0x80000000);
    
    int count1 = NUmberOf1_method2(0x80000000);
    
    cout<<"1 的个数位："<<count<<" "<<count1<<endl;
    
    cout<<"是否是 2 的整数次方( 1 代表是，0 代表不是)："<<judge_IntegerPowerOf2(0x80000000)<<endl;
    
    cout<<"把 m 变成 n 需要改变的个数为："<<get1(10, 13)<<endl;;
    
    return 0;
}

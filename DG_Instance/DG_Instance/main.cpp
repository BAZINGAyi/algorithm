
#include <iostream>
using namespace  std;

// 问题1：求1+2+3+4+～+n

int Add(int n){
    
    return n == 1 ? 1 : n + Add(n-1);

}

// 问题2: 求斐波那契数列的和 不是好的解法 因为会求已经求过的值

long long Fibonacci(unsigned int n){
    
    if(n == 0)
        
        return 0;
    
    if(n == 1)
        
        return 1;
    
    return Fibonacci(n-1) + Fibonacci(n-2);
        
}

long long Fibonacci1(unsigned int n){
    
    int reslut[2] = {0,1};
    
    if(n < 2)

        return reslut[n];
    
    long long fibNMinusOne = 0;
    
    long long fibNMinusTwo = 1;
        
    long long fibN = 0;
    
    for(unsigned int i = 2 ; i <= n; i++){
        
        fibN = fibNMinusOne + fibNMinusTwo;
        
        fibNMinusOne = fibNMinusTwo;
        
        fibNMinusTwo = fibN;
    }
    
    return fibN;
}

// 问题3 青蛙跳台阶问题 一只青蛙一次可以跳1节台阶，也可以跳2节台阶，问到第n节台阶有几种跳法
// 第一种是第一次跳一次台阶，有 f（n-1）种 第二种是第一次跳两次台阶，有 f（n-2）种

int Jump(int n){
    
    if(n == 1) return 1;
    
    if(n == 2) return 2;
    
    return Jump(n-1) + Jump(n-2);
}


// 问题4 用 8 个 2*1 的小矩形无重叠的覆盖一个 2*8 的大矩形 共有几种方法
// 考虑：把 2*8 的覆盖方法记为 f（8），首先如果竖着放，则还有 f(7) 摆法。 如果横着放，下方必须放一个横着的，所有有 f（6）

long long RectangleNumber(unsigned int n){
    
    int reslut[2] = {0,1};
    
    if(n < 2)
        
        return reslut[n];
    
    long long fibNMinusOne = 0;
    
    long long fibNMinusTwo = 1;
    
    long long fibN = 0;
    
    for(unsigned int i = 2 ; i <= n; i++){
        
        fibN = fibNMinusOne + fibNMinusTwo;
        
        fibNMinusOne = fibNMinusTwo;
        
        fibNMinusTwo = fibN;
    }
    
    return fibN;
}


int main(int argc, const char * argv[]) {
    
    int sum = Add(100);
    
    cout<<"1到100的和为"<<sum<<endl;
    
    long long Fn1 = Fibonacci(6);
    
    cout<<"Fn1="<<Fn1<<endl;
    
    long long Fn2 = Fibonacci1(6);
    
    cout<<"Fn2="<<Fn2<<endl;
    
    long long number = Jump(4);
    
    cout<<"Number="<<number<<endl;
    
    return 0;
}

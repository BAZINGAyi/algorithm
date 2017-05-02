#include <iostream>

using namespace std;

#include "vector"


/* 麻烦的方法：1. 首先确定奇数的个数
             2. 然后开始从第一个位置扫描如果遇到偶数，则从这个位置开始后的所有数向前移动一个位置，如果遇到奇数则跳过
             3. 循环的结束条件为从头开始指向的指针移动的位置数目等于奇数的个数*/
 
void doShuzu(vector<int> & a){
    
    
    int i = 0;
    
    int length = a.size() - 1;
    
    int jishu = 0;
    
    
    while (i <= length) {
        
        if((a[i] & 0x1) == 1)
            
            jishu++;
        
        i++;
    }
    
    i = 0;
    
    while(i != jishu){
        
        if((a[i]& 0x1) == 0){
            
            int temp = a[i];
            
            for(int j = i; j < length; j++){
                
                a[j] = a[j + 1];
            }
            
            a[length] = temp;
            
        }else
            
            i++;
        
    }
    
}

/* 简单的方法：1. 使用两个指针，第一个指针指向数组的第一个位置，第二个指针指向数组的结尾，只向前移动。
             2. 在两个指针相遇之前，第一个指针永远在第二个指针的前面，如果第一个指针指向的是偶数，第二个指针指向的是奇数，则交换两个数组
             */
void ReorderOddEven(int *pData,unsigned int length){

    if(pData == NULL || length == 0)
        
        return;
    
    int *pBegin = pData;
    
    int *pEnd = pData + length - 1;
    
    while (pBegin < pEnd) {
        
        while ((*pBegin & 0x1) == 1 && pBegin < pEnd) {
            pBegin++;
        }
        
        while ((*pEnd & 0x1) == 0 && pBegin < pEnd) {
            pEnd--;
        }
        
        if(pBegin < pEnd){
            
            *pBegin = *pBegin + *pEnd;
            
             *pEnd =   *pBegin - *pEnd;
        
            *pBegin = *pBegin - *pEnd;
        
        
        }
    }

}

/* 抽象：1. ORder 根据 func 的标准把数组 pData 分成两部分
        2. isEven 则是一个具体的标准，即判断一个数是不是偶数。
 */


bool isEven(int n){
    
    return (n & 1) == 0;
}

void Reorder(int *pData,unsigned int length, bool (*func) (int)){
    
    if(pData == NULL || length == 0)
        
        return;
    
    int *pBegin = pData;
    
    int *pEnd = pData + length - 1;
    
    while (pBegin < pEnd) {
        
        while ((*pBegin & 0x1) == 1 && !func(*pBegin)) {
            pBegin++;
        }
        
        while ((*pEnd & 0x1) == 0 && func(*pEnd)) {
            pEnd--;
        }
        
        if(pBegin < pEnd){
            
            *pBegin = *pBegin + *pEnd;
            
            *pEnd =   *pBegin - *pEnd;
            
            *pBegin = *pBegin - *pEnd;
            
            
        }
    }
    
}


int main(int argc, const char * argv[]) {
    // insert code here...
    
    vector<int> a ;
    
    a.push_back(1);
    a.push_back(2);
    a.push_back(3);
    a.push_back(4);
    a.push_back(5);
    a.push_back(6);
    a.push_back(7);
    
    int a1[6] = {1,2,3,4,5,6};
    
    //doShuzu(a);
    
    //ReorderOddEven(a1, 6);
    
    Reorder(a1, 6, isEven);
    
    for (int i =0 ; i < 6; i++) {
        cout<<a1[i]<<endl;
    }
    return 0;
}

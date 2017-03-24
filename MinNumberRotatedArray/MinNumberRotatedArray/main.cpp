#include <iostream>

using namespace std;

#define Error -1;

int OrderFind(int a[],int length){
    
    int mixValue = a[0];
    
    for (int i = 1; i < length ; i++) {
        
        if (a[i] < mixValue)
            
            mixValue = a[i];
        
    }
    
    return mixValue;
}

int FindMinNumberInRotatedArray(int* a, int length){
    
    if (a == NULL || length <= 0)
        
        return Error;
    
    int i = 0;
    
    int j = length - 1;
    
    int mid = i; //赋值为i的情况是可能旋转的0个元素即是原数组
    
    while(a[i] >= a[j]){
        
        if(j - i == 1)
            
            break;
        
        mid = (i + j) / 2;
    
        if (a[mid] == a[i] && a[i] == a[j])
            
            return OrderFind(a, length);
        
        if(a[mid] >= a[i])
            
            i = mid;
        
        else if(a[mid] <= a[j])
            
            j = mid;
    
    }
    
    return a[j];
}

int main(int argc, const char * argv[]) {
    
    int a[] =  {2,3,4,0,2,2};
    
    // 注 a1【】 a2【】 这两种情况，我们无法判断中间数字的1是属于第一个递增子数组还是第二个递增子数组，
    // 所以当首，中，尾三值相等的时候我们只能采用顺序查找的方法
    
    int a1[] = {1,0,1,1,1};
    
    int a2[] = {1,1,1,0,1};
    
    int minValue = FindMinNumberInRotatedArray(a1,5);
    
    cout<<"最小的元素是"<<minValue<<endl;
    
    return 0;
}

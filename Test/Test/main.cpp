//
//  main.cpp
//  Test
//
//  Created by Bazinga on 2017/3/15.
//  Copyright © 2017年 Bazinga. All rights reserved.
//

#include <iostream>
#include <stack>
#include <exception>
#include <queue>
using namespace std;

template<typename T> class CQueue{
    
public:
    
    CQueue(void);
    
    ~CQueue(void);
    
    void appendTail(const T& node);
    
    T deleteHead();
    
private:
    stack<T> stack1;
    stack<T> stack2;

};


template <typename T> CQueue<T>::CQueue(void){}

template <typename T> CQueue<T>::~CQueue(void){}

template<typename T> void CQueue<T>::appendTail(const T & node){
    
    stack1.push(node);

}

template<typename T> T CQueue<T>::deleteHead(){

    
    if (stack2.size()<=0) {
        
        while(stack1.size()>0){
            
            int data = stack1.top();
            
            stack2.push(data);
            
            stack1.pop();
            
        }
    }
    
    if(stack2.size() == 0){
        
        throw string("queue is empty");
        
    }
    
    T head = stack2.top();
    
    stack2.pop();
    
    return head;

}

int main(){

    CQueue<int > list ;
    
    list.appendTail(1);
    
    list.appendTail(2);
    
    int value =  list.deleteHead();
    
    cout<<value<<endl;



}

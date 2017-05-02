#include <iostream>
#include <string.h>
using namespace std;

/**
 分析：合并链表过程实际上是比较两个指针的过程
 存在问题：两个链表微为空的情况
 **/

typedef struct ListNode{
    int value;
    struct ListNode * next;
}ListNode;

typedef ListNode* LinkList;

int a[6] = {1,2,6,8,10,40};

int b[6] = {2,4,10,12,50,60};

void initLinkNode(LinkList * p , int type){
    
    *p = (LinkList)malloc(sizeof(ListNode));
    
    (*p)->value = 0;
    
    (*p)->next  = NULL;
    
    int count = 0;
    
    LinkList head = *p;
    
    while (count < 6) {
        
        LinkList q = (LinkList)malloc(sizeof(ListNode));
        
        if(type == 1)
            q->value = a[count];
        else
            q->value = b[count];
        q->next = NULL;
        
        head->next = q;
        
        head = q;
        
        count++;
    }
}

LinkList sortList(LinkList p ,LinkList q){
    
    LinkList merageList;
    
    if(p == NULL && q == NULL)
        return NULL;
    
    if(p == NULL)
        return q;
    
    
    if(q == NULL)
        return p;
        
    if(p->value > q->value) {
        merageList = q;
        merageList->next = sortList(p, q->next);
    }else{
        merageList = p;
        merageList->next = sortList(p->next, q);
    }
        
    return merageList;
}

int main(int argc, const char * argv[]) {
    LinkList p ;
    LinkList q ;
    initLinkNode(&p,1);
    initLinkNode(&q,2);
    
    LinkList result = sortList(p->next,q->next);
    
    while (result != NULL) {
        cout<<result->value<<endl;
        result=result->next;
    }

    return 0;
}

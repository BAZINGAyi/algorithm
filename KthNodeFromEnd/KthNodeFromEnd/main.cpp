#include <iostream>
using namespace std;


typedef struct ListNode{
    
    int m_nValue;
    
    ListNode * m_pnext;
    
}ListNode;

typedef ListNode * LinkList;

void createNode(LinkList * p){
    
    * p = (LinkList) malloc(sizeof(ListNode));
    
    if( (*p) ==  NULL)
        
        return;
    
    LinkList temp = *p;
    
    LinkList q;
    
    for(int i = 0; i < 10; i++){
        
        q = (LinkList)malloc(sizeof(ListNode));
        
        q->m_pnext = NULL;
        
        q ->m_nValue = i;
        
        temp->m_pnext = q;
        
        temp = q;
    }

}

int length(LinkList p){
    
    LinkList q = p->m_pnext;
    
    int count = 0;
    
    while(q != NULL){
        
        count ++ ;
        
        q = q -> m_pnext;
    }
    
    return count;

}

void kthNodeFromENd(LinkList p, unsigned k){
    
    if(p == NULL || k == 0 || k > length(p) ){
        return ;
    }
    
    LinkList first = p->m_pnext;
    
    LinkList sec = p ->m_pnext;
    
    for(int i =0; i < k-1; i++){
        first = first->m_pnext;
    }
    
    while (first ->m_pnext != NULL) {
        first = first->m_pnext;;
        sec = sec->m_pnext;
    }
    
    cout<<sec->m_nValue<<endl;

}


void printfNode(LinkList p){
    
    LinkList q = p ->m_pnext;
    
    while(q != NULL){
        cout<<q->m_nValue<<endl;
        q = q->m_pnext;
    }
    
}

int main(int argc, const char * argv[]) {
    
    
    LinkList head;
    
    createNode(&head);
    
    printfNode(head);
    
    kthNodeFromENd(head,10);
    
    return 0;
}

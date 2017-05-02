#include <iostream>

using namespace std;

typedef struct NodeList{
    
    int data ;
    
    NodeList * next;
    
}NodeList;

typedef NodeList *  LinkList;

void initNode(LinkList * head){
    
    * head = (LinkList)malloc(sizeof(NodeList));
    
    (* head)->data = 0;
    
    (* head)->next = NULL;

}

void insertNode(LinkList  head, int data){

    if(head == NULL)
    
        return;
    
    LinkList p = (LinkList)malloc(sizeof(NodeList));
    
    p->data = data;
    
    p->next = NULL;
    
    LinkList f = head;
    
    while (f->next != NULL) {
        
        f = f->next;
    }
    
    f->next = p;
    
}

void printfList(LinkList head){
    
    LinkList p = head->next;
    
    while(p != NULL){
        
        cout<<p->data;
        
        p = p->next;
        
    }
}

void destoryNode(LinkList head){

    LinkList p,q;
    
    p = head->next;
    
    while(p != NULL){
        
        q = p->next;
        
        free(p);
        
        p = q;
    }
    
    head->next = NULL;
    
}


void deleteNode(LinkList* head, LinkList pToBeDeleted){
    
    if((*head) == NULL ||  pToBeDeleted == NULL)
    
        return;
    
    //删除的结点不是尾节点
    if(pToBeDeleted->next != NULL){
        
        LinkList next = pToBeDeleted->next;
        
        pToBeDeleted->next = next->next;
        
        pToBeDeleted->data = next->data;
        
        free(next);
        
        next = NULL;
    }else if((*head)->next == pToBeDeleted){
        // 只有一个结点
        
        free(pToBeDeleted);
        
        (*head)->next = NULL;
        
        pToBeDeleted = NULL;
    }else{
        // 如果删除的是尾节点
        LinkList p = (*head)->next;
        
        while(p->next != pToBeDeleted){
        
            p = p->next;
        }
        
        p->next = NULL;
        
        free(pToBeDeleted);
        
        pToBeDeleted = NULL;
    }
    
}

int main(int argc, const char * argv[]) {
    
    LinkList head ;
    
    initNode(&head);
    
    insertNode(head, 1);
    
    deleteNode(&head, head->next);
    
    printfList(head);
   
    return 0;
}


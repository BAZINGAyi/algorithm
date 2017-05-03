#include <iostream>
using namespace std;
/**
 描述：判断树 B 是否属于树 A 相当于，对树进行遍历的比较，当比较到树 B 的叶子为空时结束
 注意：判断 树 A 和 树 B 是否为空的情况
 
 注意这里生成树的规则是按照二叉树的前序遍历生成的，所以比较也要按照这个规则
 **/

typedef struct BiNode{
    int value;
    struct BiNode * rightChildNode;
    struct BiNode * leftChildNode;
}BiNode;

typedef BiNode * BiLink;

int Nil = 0;

int nodeValue1[100]={1,2,4,0,6,0,0,5,0,7,0,0,3};

int nodePoint1 = 0;

int nodeValue2[100]={1,0,3};

int nodePoint2 = 0;

void initBiTree(BiLink * head,int type){
    
    int value;
    
    if(type == 1)
        value = nodeValue1[nodePoint1++];
    else
        value = nodeValue2[nodePoint2++];
    
    if(value == 0)
        *head = NULL;
    else{
        
        *head = (BiLink)malloc(sizeof(BiNode));
        
        (*head)->value = value;
        
        if(type == 1){
            initBiTree(&(*head)->leftChildNode,1);
            initBiTree(&(*head)->rightChildNode,1);
        }else{
            initBiTree(&(*head)->leftChildNode,2);
            initBiTree(&(*head)->rightChildNode,2);
        }
          
    }
    
}

// 遍历比较 树 A 和 树 B 的结点
bool DoesTree1HaveTree2(BiLink T1 , BiLink T2){
    // T2 为空证明遍历完毕
    if(T2 == NULL)
        return true;
    if(T1 == NULL)
        return false;
    if(T1->value != T2->value)
       return false;
    return DoesTree1HaveTree2(T1->leftChildNode, T2->leftChildNode)&&
        DoesTree1HaveTree2(T1->rightChildNode, T2->rightChildNode);
}

// 判断树 A 和 树 B 关系的函数
bool HasSubTree(BiLink T1 , BiLink T2){
    
    bool result = false;
    
    if(T1 != NULL && T2 !=NULL){
        if(T1->value == T2->value)
            result = DoesTree1HaveTree2(T1,T2);
        if(!result)
            result = HasSubTree(T1->leftChildNode, T2);
        if(!result)
            result = HasSubTree(T1->rightChildNode, T2);
    }
    return result;
}

void PreOrderTraverse(BiLink T){
    
    if(T == NULL)
        
        return;
    
    cout<<T->value<<" "<<endl;
    
    PreOrderTraverse(T->leftChildNode);
    
    PreOrderTraverse(T->rightChildNode);
    
}

int main(int argc, const char * argv[]) {
    BiLink T1 = NULL;
    BiLink T2 = NULL;
    initBiTree(&T1, 1);
    initBiTree(&T2, 2);
    cout<<HasSubTree(T1, T2)<<endl;
    return 0;
}

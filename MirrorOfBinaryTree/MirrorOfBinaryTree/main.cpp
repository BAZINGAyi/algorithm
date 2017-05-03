#include <iostream>
using namespace std;

/**
分析：利用画图求镜像二叉树，过程为首先判断二叉树的根节点是否存在，
     如果存在则判断二叉树是否只有一个树根节点如果不是的话，则依次调换
     根节点的左右子树，使用前序遍历整个树根
     这里以先序遍历生成二叉树
 **/

#define Nil 0

typedef struct BiTree {
    int value ;
    struct BiTree * leftChild;
    struct BiTree * rightChild;
}BiTree;

typedef BiTree * BiLink;

int a[100]={1,2,0,4,5,0,0,0,3,6};

int length = 0;



void createBiTree(BiLink * T){
    
    int value = 0;
    
    value = a[length++];
    
    if(value == Nil){
        *T = NULL;
    }else {
        
        *T = (BiLink)malloc(sizeof(BiTree));
        
        (*T)->value = value;
        
        createBiTree(&(*T)->leftChild);
        
        createBiTree(&(*T)->rightChild);
    }
}

void PreInorder(BiLink T){
    
    if(T == NULL)
        return ;
    cout<<T->value<<endl;
    PreInorder(T->leftChild);
    PreInorder(T->rightChild);
}

void getMirrorTree(BiLink * T){
    
    BiLink Head = * T;
    
    if(Head == NULL)
        return ;
    
    if(Head->leftChild == NULL && Head->rightChild == NULL)
        return ;
    
    BiLink temp = Head->rightChild;
    
    Head->rightChild = Head->leftChild;
    
    Head->leftChild = temp;
    
    if(Head->leftChild){
        
        getMirrorTree(&Head->leftChild);
    }
    
    if(Head->rightChild){
        
        getMirrorTree(&Head->rightChild);
        
    }
}
#define DIV(x,y) (x/y)

int main(int argc, const char * argv[]) {

    BiLink T;
    
    createBiTree(&T);
    
    getMirrorTree(&T);
    
    PreInorder(T);
    return 0;
}

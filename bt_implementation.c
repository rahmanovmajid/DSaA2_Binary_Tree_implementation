#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>



struct SNode {
    char *value;
    struct SNode* pLeftChild;
    struct SNode* pRightChild;
    int isFull;


};

struct SBinaryTree {

    struct SNode* pHead;
    
};


struct SNode *Node_new(char *value) {
    struct SNode* pNode=(struct SNode *)malloc(sizeof(struct SNode));
    pNode->value=value;
    pNode->pLeftChild=NULL;
    pNode->pRightChild=NULL;
    if(*value>=48 && *value<=57) pNode->isFull=1;
    else  pNode->isFull=0;
    return pNode;
}

struct SBinaryTree* BT_new(struct SNode* pNode) {
    struct SBinaryTree* pTree=(struct SBinaryTree*)malloc(sizeof(struct SBinaryTree));
    pTree->pHead=pNode;
    
    return pTree;
}

void BT_add(struct SNode* pCurrent,struct SNode* pNode) {

    
    printf("%s\n",pNode->value);


        while(1) {
            if(pCurrent->pLeftChild!=NULL) {
                if(pCurrent->pLeftChild->pLeftChild!=NULL && pCurrent->pLeftChild->pRightChild!=NULL) {
                    if (pCurrent->pLeftChild->pLeftChild->isFull==1 && pCurrent->pLeftChild->pRightChild->isFull==1) 
                    pCurrent->pLeftChild->isFull=1;
                 }
            }
            if(pCurrent->pRightChild!=NULL) {
                if(pCurrent->pRightChild->pLeftChild!=NULL && pCurrent->pRightChild->pRightChild!=NULL) {
                    if (pCurrent->pRightChild->pLeftChild->isFull==1 && pCurrent->pRightChild->pRightChild->isFull==1) 
                    pCurrent->pLeftChild->isFull=1;
                }
            }
        
          
            
          



          if(pCurrent->pLeftChild!=NULL){
              if(pCurrent->pLeftChild->isFull==0) { 
                pCurrent=pCurrent->pLeftChild;
              }
              else if(pCurrent->pRightChild!=NULL) {
                if(pCurrent->pRightChild->isFull==0) {
                    pCurrent=pCurrent->pRightChild;
                }
                else { 
                    break; }
              }
              else {
                  break;}
          }
          else  {
          break; }
            
        } 
        

        
            if(pCurrent->pLeftChild==NULL) {
            pCurrent->pLeftChild=pNode;
            if(strcmp(pCurrent->value,"sqrt")==0 ||strcmp(pCurrent->value,"sin")==0 || strcmp(pCurrent->value,"cos")==0 || strcmp(pCurrent->value,"tan")==0 ) {
                pCurrent->isFull=1; }
            }
            else
            {
                pCurrent->pRightChild=pNode;
            }
            
        if(pCurrent->pLeftChild!=NULL && pCurrent->pRightChild!=NULL) {
        if(pCurrent->pLeftChild->isFull==1 && pCurrent->pRightChild->isFull==1)  pCurrent->isFull=1;
        }
        
}

struct SBinaryTree* BT_from_prefix(char* array) {
    char *token;
    token=strtok(array," ");
    struct SBinaryTree* pTree= BT_new(Node_new(token));
    struct SNode* pCurrent=pTree->pHead;
    token=strtok(NULL," ");
    while(token!=NULL) {
        struct SNode* pNode=Node_new(token);
        BT_add(pCurrent,pNode);
        token=strtok(NULL," ");
    }
    return pTree;
}
        

void BT_PrePrint(struct SNode* pNode) { 
    printf("%s ",pNode->value);
    if(pNode->pLeftChild) BT_PrePrint(pNode->pLeftChild);
    if(pNode->pRightChild) BT_PrePrint(pNode->pRightChild);
}

void BT_PostPrint(struct SNode* pNode) {
    if(pNode->pLeftChild) BT_PostPrint(pNode->pLeftChild);
    if(pNode->pRightChild) BT_PostPrint(pNode->pRightChild);
    printf("%s ",pNode->value);
}

void BT_InPrint(struct SNode* pNode) {
    if(pNode->pLeftChild) {
        BT_InPrint(pNode->pLeftChild);
    }
    printf("%s ",pNode->value);
    if(pNode->pRightChild)  {
        BT_InPrint(pNode->pRightChild); 
    }
}


int BT_answer(struct SNode *pNode) {
    if(*pNode->value==48) return 0;
    else if(*pNode->value==49) return 1;
    else if(*pNode->value==50) return 2;
    else if(*pNode->value==51) return 3;
    else if(*pNode->value==52) return 4;
    else if(*pNode->value==53) return 5;
    else if(*pNode->value==54) return 6;
    else if(*pNode->value==55) return 7;
    else if(*pNode->value==56) return 8;
    else if(*pNode->value==57) return 9;
    else if(*pNode->value==42) return BT_answer(pNode->pLeftChild)*BT_answer(pNode->pRightChild);
    else if(*pNode->value==43) return BT_answer(pNode->pLeftChild)+BT_answer(pNode->pRightChild);
    else if(*pNode->value==45) return BT_answer(pNode->pLeftChild)-BT_answer(pNode->pRightChild);
    else if(*pNode->value==47) return BT_answer(pNode->pLeftChild)/BT_answer(pNode->pRightChild);
    else if(strcmp(pNode->value,"sqrt")==0) return sqrt(BT_answer(pNode->pLeftChild));
    else if(strcmp(pNode->value,"sin")==0) return sin(BT_answer(pNode->pLeftChild));
    else if(strcmp(pNode->value,"cos")==0) return cos(BT_answer(pNode->pLeftChild));
    else if(strcmp(pNode->value,"tan")==0) return tan(BT_answer(pNode->pLeftChild));
}
    



int main () {
    // firstly i create the char array corresponding to my example (expression)
    char expression[100]="* - + 6 1 - 5 2 7";

    // now creating tree from given expression
    struct SBinaryTree* pTree=BT_from_prefix(expression);

    //binary tree printed in prefix,postfix and infix
    BT_PrePrint(pTree->pHead);
    printf("\n");
    BT_PostPrint(pTree->pHead);
    printf("\n");
    BT_InPrint(pTree->pHead);
    printf("\n\n");
    printf("The answer of mathematical expression = %d\n",BT_answer(pTree->pHead));
    return 0;
} 

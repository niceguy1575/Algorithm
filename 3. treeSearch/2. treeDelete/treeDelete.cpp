#include<stdio.h> 
#include<stdlib.h> 

typedef struct treeNode {
	int key;
	struct treeNode* left;
	struct treeNode* right;
} treeNode;

treeNode* insertNode(treeNode *p, int x){
 	  treeNode *newNode;
	  if (p == NULL){ 
        	newNode = (treeNode*)malloc(sizeof(treeNode)); 
		newNode->key = x; 
		newNode->left = NULL; 
		newNode->right = NULL; 
		return newNode; 
	  } 
	  else if (x < p->key)  p->left = insertNode(p->left, x);        
	  else if (x > p->key)  p->right = insertNode(p->right, x); 

	  return p;
} 

void deleteNode(treeNode *root, int key){
	
    treeNode *parent, *p, *succ, *succ_parent; 
    treeNode *child; 
   
    parent=NULL; 
    p=root; 
    while((p != NULL) && (p->key != key)){
        parent=p; 
        if(key < p->key) p=p->left; 
        else p=p->right; 
    }
        
    // 자식 0개 
    if((p->left == NULL) && (p->right == NULL)){ 
        if(parent != NULL){ 
            if(parent->left == p) parent->left=NULL; 
            else parent->right=NULL; 
        } 
        else root=NULL; 
    } 
   
   // 자식 1개 
    else if((p->left == NULL) || (p->right == NULL)){ 
        if(p->left != NULL) child=p->left; 
        else child=p->right; 
   
        if(parent != NULL){
            if(parent->left == p) parent->left=child; 
            else parent->right=child; 
        }
        else root=child; 
    } 
   
    // 자식 2개 
    else{ 
        succ_parent=p; 
        succ=p-> right; 
        while(succ->left  != NULL){ 
            succ_parent=succ; 
            succ=succ-> left; 
        } 
        if(succ_parent->right == succ)  succ_parent->right=succ-> right;
        else succ_parent->left=succ-> right; 
        p->key=succ->key; 
        p=succ; 
    }  
    free(p); 
} 

void preorder(treeNode* root){
    if(root!=NULL){
       printf("%d ", root->key); 
       preorder(root->left); 
       preorder(root->right); 
    }
} 
   
void inorder(treeNode* root){ 
    if(root!=NULL){  
       inorder(root->left); 
       printf("%d ", root->key); 
       inorder(root->right); 
    } 
} 
   
void postorder(treeNode* root){ 
    if(root!=NULL){ 
       postorder(root->left); 
       postorder(root->right); 
       printf("%d ", root->key); 
    } 
}

int main() 
{	 
	treeNode* root = NULL;	  
	treeNode* foundedNode = NULL; 
	
	// tree 구성 
	int size, i, delNum, x, p;
    scanf("%d", &size);
    
    int *inputArr = (int*)malloc(sizeof (int) * size);
    for (i = 0; i < size; i++) {
        scanf("%d",&inputArr[i]);
        if(i==0) {
        	root = root=insertNode(root, inputArr[i]);
		}
        else {
        	insertNode(root, inputArr[i]);	
		}
	}
	
	// tree 삭제
	scanf("%d", &delNum);
	
	for(i = 0 ; i < delNum; i ++){
		
	    scanf("%d", &p);
	    scanf("%d", &x);
	    
	    deleteNode(root, x);
	    
	    if(p==0) {
	    	preorder(root);
	    	printf("\n");
		}
	    else if(p==1){
	    	inorder(root);
	    	printf("\n");
		}
		else if(p==2){
			postorder(root);
			printf("\n");
		}
		else{
			;
		}
	}
	
	return 0;
}


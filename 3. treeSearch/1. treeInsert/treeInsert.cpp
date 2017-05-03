#include<stdio.h> 
#include<stdlib.h> 

int cnt = 0;

typedef struct treeNode {
	int key;
	struct treeNode* left;
	struct treeNode* right;
} treeNode;

treeNode* insertNode(treeNode *p, int x){
	cnt++;
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

int main() 
{	 
	treeNode* root = NULL;	  
	treeNode* foundedNode = NULL; 
	
	int size;
    scanf("%d", &size);
    
    int *inputArr = (int*)malloc(sizeof (int) * size);
    for (int i = 0; i < size; i++) {
        scanf("%d",&inputArr[i]);
        if(i==0) {
        	root = root=insertNode(root, inputArr[i]);
		}
        else {
        	insertNode(root, inputArr[i]);	
		}
	}
	
	printf("%d", cnt);
	return 0;
}


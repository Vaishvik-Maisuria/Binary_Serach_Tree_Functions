#include<stdio.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include <ctype.h>
#define N 10


int * myFunction(char* str, int n);
/* A binary tree node has data, left and right child*/
struct node{
    int data;
    struct node* left;
    struct node* right;
};

// A function to create a new node
struct node *newNode(int item)
{
    struct node *temp =  (struct node *)malloc(sizeof(struct node));
    temp->data = item;
    temp->left = temp->right = NULL;
    return temp;
}

/* A function to insert a new node with key in tree*/
struct node* insert_key(struct node* node, int key){
    /* If the tree is empty, return a new node */
    if (node == NULL){
        return newNode(key);
    }
    /* Otherwise, recur down the tree */
    if (key < node->data)
        node->left  = insert_key(node->left, key);
    else if (key > node->data)
        node->right = insert_key(node->right, key);
    
    /* return the (unchanged) node pointer */
    return node;
}
 
/* Compute the "maxDepth"/ "height" of a tree -- the number of
    nodes along the longest path from the root node 
    down to the farthest leaf node.*/
int Max_Height(struct node* node)
{
   if (node==NULL) 
       return 0;
   else
   {
       /* compute the depth of each subtree */
       int lheight = Max_Height(node->left);
       int rheight = Max_Height(node->right);
 
       /* use the larger one */
       if (lheight > rheight)
           return(lheight+1);
       else return(rheight+1);
   }
} 

/* Prints the permutation of the list
 insert the values of the list into a binary tree
 and prints the height of the binary tree */
void print(int *num, int n)
{
    int i;
    struct node *root = NULL;
    for ( i = 0 ; i < n ; i++){
        printf("%d ", num[i]);
        
        if ( i ==0){
            root = insert_key(root, num[i]);
        }else{
            insert_key(root, num[i]);
        }
        
    }
    printf("Height of tree is %d", Max_Height(root));
    printf("\n");
    
}

/* Function to swap values at two pointers */
void swap(char *x, char *y)
{
    char temp;
    temp = *x;
    *x = *y;
    *y = temp;
}

/* Function to permutations of string
 This function takes three parameters:
 1. String
 2. Starting index of the string
 3. Ending index of the string. */
void permute(char *a, int l, int r){
    int i;
    
    if (l == r){
        //printf("%s\n", a);
        int* values2 = (int*) malloc (sizeof (int) * 4) ;
        values2 = myFunction(a, r +1);
        print(values2,r+1);
    }else{
        for (i = l; i <= r; i++)
        {
            swap((a+l), (a+i));
            permute(a, l+1, r);
            swap((a+l), (a+i)); //backtrack
        }
    }
}

int * myFunction(char* str, int n) {
    int i , j;

    char tmp [2] = {'\0', '\0'} ;
    int* values = (int*) malloc (sizeof (int) * n) ;
    
    for ( i = 0, j = 0; i < n; ++i)
    {
        if (isdigit(str[i]))
        {
            tmp [0] = str[i] ;
            values [j++] = atoi (tmp) ;
        }
    }
   
    
    return values;
}
int main(){
    
    int* values2 = (int*) malloc (sizeof (int) * 4) ;
    
    
    
    char str[100];
    
    printf("Enter your String to permutate: ");
    scanf("%s", str);
    
    int n = strlen(str);
    
    values2 = myFunction(str, n);
    
    permute(str, 0, n-1);
    
    return 0;
}

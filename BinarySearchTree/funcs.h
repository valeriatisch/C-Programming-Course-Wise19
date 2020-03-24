#ifndef BINARYSEARCHTREEFUNCS_H
#define BINARYSEARCHTREE_FUNCS_H

#include "structs.h"

//a macro function:
#define MAX(A, B) (A > B ? A : B)

void insert_node(char*, _node**); //insert string into the binary search tree.
_node* createNode(char*); //create a node to insert into the binary search tree.
void printTree(_node*); //Print the tree using depth-first search prefering left branches.
int height(_node*, int); //Compute the height of a binary search tree.
int numberLeaves(_node*, int); //Compute the number of leaves in a binary search tree.
void stringCount(_node*, int*); //Count the number of strings (nodes) in this binary tree.
void free_memory(_node* root);
void print2DUtil(_node *root, int space);

#endif //BINARYSEARCHTREE_FUNCS_H

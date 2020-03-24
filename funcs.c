#include "funcs.h"

//Implement all functions declared in the header funcs.h

//Function to create a new node.
_node* createNode(char* buffy) {

    _node* node = (_node*) malloc(sizeof(_node));
    if (node == NULL) {
        fprintf(stderr, "Could not allocate space for new BST node!");
        exit(EXIT_FAILURE);
    }

    node->left = NULL;
    node->right = NULL;
    strcpy(node->value, buffy);

    return node;
}

//What does strcmp return? https://stackoverflow.com/questions/34824838/what-does-strcmp-exactly-return-in-c/34825545
//Recursively build up the tree from the input string
void insert_node(char* buffy, _node** probe) {

    if(*probe == NULL) {
        *probe = createNode(buffy);
        return;
    } else {
        if(strcmp(buffy, (*probe)->value) > 0) {
            probe = &(*probe)->right; //"->" bindet staerker als der Adressoperator "&", alternativ: &((*probe)->right)
            insert_node(buffy, probe);
        } else {
            probe = &(*probe)->left;
            insert_node(buffy, probe);
        }
    }

    return;
}

//Depth first search for nodes to print them
//Nodes to be visited are implicitly stored on the stack
void printTree(_node* probe) {

    if(probe == NULL) {
        return;
    } else {
        printf("NODE: %s\n", probe->value);
        if(probe->left != NULL)
            printTree(probe->left);

        if(probe->right != NULL)
            printTree(probe->right);

        return;
    }
}

//Recursively find the height of the tree.
int height(_node* probe, int treeHeight) {

    if((probe != NULL) && (probe->left == NULL) && (probe->right == NULL))
        return 0;

    if(probe != NULL)
        treeHeight = 1 + (MAX(height(probe->left,treeHeight), height(probe->right,treeHeight)));


    return treeHeight;
}

//Find the number of leaves in the tree
int numberLeaves(_node* probe, int cLeaves) {

    if(probe != NULL) {
        if((probe->left == NULL) && (probe->right == NULL)) {
            return 1;
        }
    }
    if(probe != NULL)
        cLeaves += (numberLeaves(probe->right, cLeaves) + numberLeaves(probe->left, cLeaves));
    return cLeaves;
}

/*Count the number of strings in the tree */
void stringCount(_node* probe, int *strings) {

    if(probe == NULL) {
        return;
    } else {

        (*strings)++;
        if(probe->left != NULL)
            stringCount(probe->left, strings);
        if(probe->right != NULL)
            stringCount(probe->right, strings);
    }
    return;
}

void free_memory(_node* root){
    if(root == NULL) {
        return;
    }
    else {
        if(root->left != NULL)
            free_memory(root->left);
        if(root->right != NULL)
            free_memory(root->right);
        free(root);
        return;
    }
}

void print2DUtil(_node *root, int space){
    // Base case
    if (root == NULL)
        return;

    // Increase distance between levels
    space += 20;

    // Process right child first
    print2DUtil(root->right, space);

    // Print current node after space
    // count
    printf("\n");
    for (int i = 20; i < space; i++)
        printf(" ");
    printf("%s\n", root->value);

    // Process left child
    print2DUtil(root->left, space);
}


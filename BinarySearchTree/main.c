#include "funcs.h"

int main(int argc, char* argv[]) {

    //File pointers for the input and output files.
    FILE* in;
    FILE* out;

    //root of the tree
    _node* root = NULL;

    //Buffer for reading the string from the file.
    char buffy[MAX_STR_LEN];

    //Counters for information about the tree
    int numberStrings = 0,
        treeHeight = 0,
        leaves = 0,
        leftStrings =0,
        rightStrings =0;

    //Needs infile and outfile for proper usage
    if(argc != CMD_ARGC) {
        fprintf(stderr, "Wrong input. Try: %s %s\n", argv[0], USAGE_STRING);
        exit(EXIT_FAILURE);
    }

    //Open the infile for reading ("r"), exit if cannot be opened
    if((in = fopen(argv[INFILE], "r")) == NULL) {
        perror("Input file could not be opened for reading.\n");
        exit(EXIT_FAILURE);
    }

    //Open the outfile for writting
    if ((out = fopen(argv[OUTFILE], "w")) == NULL) {
        perror("Output file could not be opened for writing.\n");
        exit(EXIT_FAILURE);
    }

    //Read the strings from the input file
    while(fscanf(in,"%s", buffy) != EOF) {
        insert_node(buffy, &root); //insert every string as a node into the bst
        numberStrings++;
    }

    //Print the strings out in a depth first search
    printTree(root);

    treeHeight = height(root, 0);
    leaves = numberLeaves(root, 0);
    stringCount(root->left, &leftStrings);
    stringCount(root->right, &rightStrings);

    //Write information about the tree into the output file
    fprintf(out, "Number of strings: %d\n", numberStrings);
    fprintf(out, "Height of the tree: %d\n", treeHeight);
    fprintf(out, "Number of leaves in the tree: %d\n", leaves);
    fprintf(out,"No. strings right sub-tree = %d\n", rightStrings);
    fprintf(out,"No. strings left sub-tree = %d\n", leftStrings);

    print2DUtil(root, 0);

    free_memory(root);

    return 0;
}


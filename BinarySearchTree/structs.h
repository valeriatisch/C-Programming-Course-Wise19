//
// Created by valeria on 03.12.19.
//

#ifndef BINARYSEARCHTREE_STRUCTS_H
#define BINARYSEARCHTREE_STRUCTS_H

#include "includes.h"

typedef struct _node _node;

struct _node{
    char value[MAX_STR_LEN];
    struct _node *left, *right;
};

#endif //BINARYSEARCHTREE_STRUCTS_H

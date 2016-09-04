#ifndef _BST_H__
#define _BST_H__

#include <stdio.h>
#include <stdbool.h>

#define KEYWORD_SIZE 100

/* structure representing a node of the binary search tree */
struct tree_node_t
{
    char  data[KEYWORD_SIZE];
    struct tree_node_t *left;
    struct tree_node_t *right;
};

typedef struct tree_node_t tree_node;

/* function to insert a node in the binary search tree */
bool insert(char * val);

/* function to find a node in the binary search tree */
bool find(char * val);

#endif

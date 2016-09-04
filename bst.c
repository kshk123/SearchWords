#include <stdlib.h>
#include <string.h>
#include "bst.h"


tree_node * root = NULL;

/* Function to insert a node in the Binary Search Tree
   For the first insert it sets the root
   The function will return false if it fails to insert a new node, 
   else returns true */
bool insert(char * val)
{
	if(NULL == val)
		return false;

    tree_node* newNode = (tree_node *)malloc(sizeof(tree_node));
	if(NULL == newNode)
		return false;

    strcpy(newNode->data, val);
    newNode->left = NULL;
    newNode->right = NULL;

    if(NULL == root)
    {
        root = newNode;
    }
    else
    {
        tree_node* ptr = root;
        tree_node* parent = root;
        while(NULL != ptr)
        {
            parent = ptr;
            if(strcmp(ptr->data, val) > 0)
                ptr = ptr->left;
            else
                ptr = ptr->right;
        }

        if(strcmp(parent->data, val) > 0)
            parent->left = newNode;
        else
            parent->right = newNode;
    }

    return true;
}

/* Function to find a value in the Binary Search Tree
   The function will return false if it fails to find the value, 
   else returns true */
bool find(char * val)
{
	if((NULL == root) || (NULL == val))
		return false;

	tree_node* ptr = root;

	while(NULL != ptr)
	{
		if(!strcmp(ptr->data, val))
			return true;

		if(strcmp(ptr->data , val) > 0)
			ptr = ptr->left;
		else
			ptr = ptr->right;
	}

	return false;
}


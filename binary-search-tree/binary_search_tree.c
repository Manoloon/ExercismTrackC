#include "binary_search_tree.h"
#include <stdlib.h>

node_t *build_tree(int *tree_data, size_t tree_data_len)
{
    if(tree_data == NULL || tree_data_len == 0) return NULL;

    node_t* root = NULL;

    for(size_t i = 0; i < tree_data_len;++i)
    {
        root = insert(root,tree_data[i]);
    }
    return root;
}

void free_tree(node_t *tree)
{
    if(tree == NULL) return;
    free_tree(tree->left);
    free_tree(tree->right);
    free(tree);
}

int *sorted_data(node_t *tree)
{
    if(tree == NULL) return NULL;
    
    return &tree->data;
}

node_t* insert(node_t *root, int tree_data)
{
    if(root == NULL)
    {
        node_t* new_node = malloc(sizeof(node_t));
        if(new_node == NULL) return NULL;
        new_node->data = tree_data;
        new_node->left = NULL;
        new_node->right = NULL;
        return new_node;
    }

    // insert left
    if(tree_data <= root->data)
    {
        root->left = insert(root->left,tree_data);
    }
    else
    {
        root->right = insert(root->right,tree_data);
    }
    return root;
}

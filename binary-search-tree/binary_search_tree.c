#include "binary_search_tree.h"
#include <stdlib.h>

node_t *build_tree(int *tree_data, size_t tree_data_len)
{
    if(tree_data == NULL) return NULL;
    node_t* result = malloc(sizeof(node_t)*tree_data_len);
    result->data = *tree_data;
    result->left = NULL;
    result->right = NULL;
    return result;
}

void free_tree(node_t *tree)
{
    free(tree);
}

int *sorted_data(node_t *tree)
{
    if(tree == NULL) return NULL;
    return &tree->data;
}

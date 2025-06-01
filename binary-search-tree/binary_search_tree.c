#include "binary_search_tree.h"
#include <stdlib.h>
#include <stdio.h>
node_t *build_tree(int *tree_data, size_t tree_data_len)
{
    if(tree_data == NULL) return NULL;
    node_t* result = malloc(sizeof(node_t));
    if(result == NULL) return NULL;
    printf("len %lld\n",tree_data_len);
    if(tree_data_len < 2)
    {
        result->data = *tree_data;
        result->left = NULL;
        result->right = NULL;
        return result;
    }
    for(size_t i = 0; i < tree_data_len;++i)
    {
        printf("data at %lld  = %d\n",i,tree_data[i]);
            // left
            if(tree_data[i] < tree_data[0])
            {
                result->left->data = tree_data[i];
                result->right = NULL;
            }
            else
            {
                result->right->data = tree_data[i];
                result->left = NULL;
            }
    }
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

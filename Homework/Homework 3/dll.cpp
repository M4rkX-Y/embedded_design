#include <iostream>

struct DLL
{               // A Doubly Linked List (has forward and backward links)
    DLL *left;  // The node to my left (nullptr if first element)
    DLL *right; // The node to my right (nullptr if last element)
    int val;    // my value
};
/**
 * Inserts val as the idx element of list (counting from 0).
 * Returns a pointer to the beginning of the list.
 */
DLL *insert(DLL *list, int val, unsigned int idx)
{
    if (!list)
    {
        return nullptr;
    }
    DLL *tmp = list;
    if (!idx)
    {
        DLL *new_node = new DLL();
        new_node->val = val;
        new_node->left = nullptr;
        new_node->right = tmp;
        tmp->left = new_node;
        return new_node;
    }
    while (idx > 1 && tmp->right)
    {
        tmp = tmp->right;
        idx--;
    }
    if (idx > 1)
    {
        std::cerr << "Error! Index was too big" << std::endl;
        return list;
    }
    DLL *new_node = new DLL();
    new_node->val = val;
    new_node->left = tmp;
    new_node->right = tmp->right;
    if (tmp->right)
    {
        tmp->left = new_node;
    };
    tmp->right = new_node;
    return list;
}
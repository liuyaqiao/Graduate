//
// Created by Yaqiao on 2018/2/21.
//


#include <iostream>
#include "Tree.h"

Tree::Tree()
{
    root = NULL;
}

Tree::Node *Tree::MinAux(Node *node)
{
    while (node && node->left)
        node = node->left;
    return node;
}
void Tree::PrintAux(Node *node)
{
    if (!node)
        return;
    PrintAux(node->left);
    std::cout << '\n';
    std::cout << "Key: ";
    node->key->Print();
    node->data->Print();
    PrintAux(node->right);
}

Tree::Node *Tree::SearchAux(Object *key)
{
    Node *node = root;
    while (node)
    {
        if (node->key->Compare(key))
            node = node->right;
        else if (key->Compare(node->key))
            node = node->left;
        else
            return node;
    }
    return NULL;
}
void Tree::Print()
{
    PrintAux(root);
    std::cout << '\n';
}

void Tree::Insert(Object *key, Object *data)
{
    Node *node;
    Node *x, *y;
/* Create new node */
    node = new Node;
    node->key = key;
    node->data = data;
    y = NULL;
    x = root;
    while (x)
    {
        y = x;
        if (key->Compare(x->key))
            x = x->left;
        else
            x = x->right;
    }
    node->parent = y;
    if (!y)
        root = node;
    else if (key->Compare(y->key))
        y->left = node;
    else
        y->right = node;
}

void Tree::Transplant(Node *u, Node *v)
{
    if (!u->parent)
        root = v;
    else if (u == u->parent->left)
        u->parent->left = v;
    else
        u->parent->right = v;
    if (v)
        v->parent = u->parent;
}
Object *Tree::Min()
{
    Node *node = MinAux(root);
    return node ? node->data : NULL;
}

Object *Tree::Search(Object *key)
{
    Node *node = SearchAux(key);
    return node ? node->data : NULL;
}
Object *Tree::Delete(Object *key)
{
    Object *data;
    Node *node;
    Node *succ;
/* Search element */
    node = SearchAux(key);
    if (!node)
        return NULL;
    if (!node->left)
        Transplant(node, node->right);
    else if (!node->right)
        Transplant(node, node->left);
    else
    {
        succ = MinAux(node->right);
        if (succ == node->right)
        {
            Transplant(node, succ);
            succ->left = node->left;
            succ->left->parent = succ;
        }
        else
        {
            Transplant(succ, succ->right);
            Transplant(node, succ);
            succ->left = node->left;
            succ->left->parent = succ;
            succ->right = node->right;
            succ->right->parent = succ;
        }
    }
// Return
    data = node->data;
    delete node;
    return data;
}

int Tree::getHeightAux(Node *node)
{
  //  if(node->left == 0 && node ->right ==0)
  //      return 0;
    if(node == 0)
	return -1;   
 
    int LeftHeight = getHeightAux(node->left);
    int RightHeight = getHeightAux(node->right);
    return (LeftHeight>RightHeight)?(LeftHeight+1):(RightHeight+1);
}

int Tree::getHeight()
{
    std::cout<<"\nThe height of this tree is  "<<getHeightAux(root)<<"\n";
}








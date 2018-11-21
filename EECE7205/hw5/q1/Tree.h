//
// Created by Yaqiao on 2018/2/21.
//

#ifndef BINARYTREE_TREE_H
#define BINARYTREE_TREE_H

#include "Object.h"

class Tree {
    struct Node
    {
        Node *left,*right,*parent;
        Object *key,*data;
    };

    Node *root;

    Node *MinAux(Node *node);
    Node *SearchAux(Object *key);
    void PrintAux(Node *node);
    void Transplant(Node *u, Node *v);
    int getHeightAux(Node *node);
public:
    Tree();

    void Print();
    void Insert(Object *key, Object *data);

    Object* Min();
    Object* Search(Object *key);
    Object* Delete(Object *key);
    int getHeight();
};


#endif //BINARYTREE_TREE_H

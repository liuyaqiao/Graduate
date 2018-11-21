//
// Created by Yaqiao on 2018/3/10.
//

#include "HashTable.h"
#include <iostream>
#include <cstdlib>
#include "String.h"

const float HashTable::max_load_factor = 0.7;

HashTable::HashTable(int size)
{
    this->size = size;
    length = 0;
    nodes = new Node* [size] ();
}

HashTable::~HashTable()
{
    delete[] nodes;
}

void HashTable::Grow()
{
    int old_size;
    int index;
    int i;

    Node **old_nodes;
    Node *node;

    old_size = size;
    old_nodes = nodes;

    size = old_size * 2;
    nodes = new Node* [size]();

    for (int i = 0; i < old_size; i++)
    {
        while ((node = old_nodes[i]))
        {
            old_nodes[i] = node->next;
            index = node->key->Hash() % size;
            node->next = nodes[index];
            nodes[index] = node;
        }
    }
    delete [] old_nodes;
}

Object *HashTable::Search(Object *key)
{
    unsigned int index;
    Node *node;
    index = key->Hash() % size;
    for (node = nodes[index]; node; node = node->next)
    {
        if (key->Equals(node->key))
            break;
    }
    return node ? node->data : NULL;
}

void HashTable::Print()
{
    for (int i = 0; i < size; i++)
    {
        for (Node *node = nodes[i]; node; node = node->next)
        {
            std::cout << '\n';
            std::cout << "Key: ";
            node->key->Print();
            node->data->Print();
        }
    }
}

void HashTable::Insert(Object *key, Object *data)
{
    if (length > size * max_load_factor)
        Grow();
    if (Search(key))
        throw "Element must not exist";

    Node *node = new Node;
    node->data = data;
    node->key = key;

    unsigned int index = key->Hash() % size;
    node->next = nodes[index];
    nodes[index] = node;
    length++;
}

Object *HashTable::Delete(Object *key)
{
// Calculate hash index
    unsigned int index = key->Hash() % size;
// Find element
    Node *prev = NULL;
    Node *node = nodes[index];
    while (node && !key->Equals(node->key))
    {
        prev = node;
        node = node->next;
    }
// Not found
    if (!node)
        throw "Element not found";
// Delete it
    if (prev)
        prev->next = node->next;
    else
        nodes[index] = node->next;
// Free element
    Object *data = node->data;
    delete node;
// Return the data
    return data;
}

Object *HashTable::Succ(Object *key)
{
    if (Search(key) == NULL) {
        return NULL;
    }
    Node *gapNode = new Node;
    String *strMAX = new String("ZZZZZZ");
    gapNode->key = strMAX;
    for (int i = 0; i < size; i++)
    {
        for (Node *node = nodes[i]; node; node = node->next)
        {
            Node *tempNode = new Node;
            if (! node->key->Compare(key)) {
                tempNode = node;
                if (tempNode->key->Compare(gapNode->key) && key->Compare(tempNode->key)) {
                    gapNode = tempNode;
                }
            }
        }
    }
    if (gapNode->key->Equals(strMAX))
        return NULL;
    return gapNode->key;
}
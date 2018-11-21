//
// Created by Yaqiao on 2018/3/15.
//

#include "Hashtable.h"
#include <iostream>
#include <cstdlib>
#include "String.h"

//const float Hashtable::max_load_factor = 0.9;

Hashtable::Hashtable(int size)
{
    this->size = size;
    length = 0;
    nodes = new Node* [size] ();
    for (int i = 0; i < size; ++i) {
        nodes[i] = new Node();
    }
}

Hashtable::~Hashtable()
{
    for (int i = 0; i < size; ++i) {
        delete nodes[i];
    }
    delete[] nodes;
}

void Hashtable::Print()
{
    for (int i = 0; i < size; i++) {
        if (nodes[i]->key) {
            std::cout << '\n';
            std::cout << "Key: ";
            nodes[i]->key->Print();
            nodes[i]->data->Print();
        }
    }
}

Object* Hashtable::Search(Object *key)
{
    for (int i = 0; i < size - 1; i++) {
        int index = (key->Hash(i)) % size;
        if (nodes[index]->key->Equals(key)) {
            return nodes[index]->key;
        }
        if (nodes[index]->key == NULL && nodes[index]->removed == false) {
            return NULL;
        }
    }
    return NULL;
}

void Hashtable::Insert(Object *key, Object *data)
{
    for (int i = 0; i < size; ++i) {
        int index = (key->Hash(i)) % size;
        if (nodes[index]->key == NULL) {
            nodes[index]->key = key;
            nodes[index]->data = data;
            nodes[index]->removed = false;
            length++;
            return;
        }
    }
    std::cerr<<"Full Table";
}

Object* Hashtable::Delete(Object *key)
{
    for (int i = 0; i < size; ++i) {
        int index = (key->Hash(i)) % size;
        if (nodes[index]->key == key) {
            Node *node = new Node();
            node = nodes[index];
            nodes[index]->key = NULL;
            nodes[index]->data = NULL;
            nodes[index]->removed = true;
            length--;
            return node->data;
        }
        if (nodes[index]->key == NULL && nodes[index]->removed == false) {
            std::cerr<<"Not Found\n";
        }
    }

    std::cerr<<"Not Found\n";
}
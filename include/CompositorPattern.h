#ifndef COMPOSITOR_PATTERN_H
#define COMPOSITOR_PATTERN_H

#include <vector>

struct Node{
    int data;
    std::vector<Node*> children;

    Node(int d);
    ~Node();

    Node* add(int data);
    void process();

    //Like.... count the price of every component

    int sum() const;
};


int CompositorPattern();

#endif
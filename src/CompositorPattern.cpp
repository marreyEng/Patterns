#include <CompositorPattern.h>
#include <TestTitle.h>

#include <iostream>

Node::Node(int d)
: data{d}
{}
Node::~Node(){
    for(auto& c : children){
        delete c;
    }
}

Node* Node::add(int data){
    auto ptr = new Node(data);
    children.push_back(ptr);
    return ptr;
}

void Node::process(){
    std::cout << data;
    for(Node* c : children){
        c->process();
    }
}

int Node::sum() const {
    auto sum = data;
    
    for(const auto c : children){
        sum += c->sum();
    }

    return sum;
}


int CompositorPattern(){
    Title t{__func__};

    Node* root = new Node(0);
    Node* a = root->add(1);
        Node* aa = a->add(3);
        Node* ab = a->add(4);
    
    Node* b = root->add(2);
        Node* ba = b->add(5);
        Node* bb = b->add(6);
            Node* bba = bb->add(7);
            Node* bbb = bb->add(8);
            Node* bbc = bb->add(9);

    std::cout << root->sum();

    delete root;

    return -42;
}
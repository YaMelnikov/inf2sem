#include <iostream>

struct Node
{
    int key=0;
    Node *next=nullptr;
};
void push_front(Node*& head_ref, int new_key){
    if (head_ref == nullptr){
        head_ref=new Node;
        head_ref->key=new_key;
        return;
    }
    Node *new_node=new Node;
    new_node->next=head_ref;
    new_node->key=new_key;
    head_ref=new_node;
    return;
}
void push_back(Node*& head_ref, int new_data){
    if (head_ref==nullptr){
        head_ref=new Node;
        head_ref->key=new_data;
        return;
    }
    Node *now=head_ref;
    while (now->next!=nullptr)
        now=now->next;
    Node *new_node=new Node;
    now->next=new_node;
    new_node->next=nullptr;
    new_node->key=new_data;
    return;
}
void insert_after(Node*& prev_ref, int new_key){
    if (prev_ref==nullptr)
        return;
    Node *now=prev_ref->next;
    prev_ref->next=new Node;
    prev_ref->next->key=new_key;
    prev_ref->next->next=now;
}
void destroy_list(Node*& head_ptr){
    if (head_ptr==nullptr)
        return;
    while (head_ptr->next!=nullptr){
        Node *now=head_ptr->next->next;
        delete head_ptr->next;
        head_ptr->next=now;
    }
    delete head_ptr->next;
    head_ptr=nullptr;
}
void print_list(Node* head_ref){
    if (head_ref==nullptr){
        cout<<endl;
        return;
    }
    Node *now=head_ref;
    if (head_ref->next==nullptr){
        cout<<head_ref->key<<' '<<head_ref->next->key<<endl;
        return;
    }
    while (now->next!=nullptr){
        cout<<now->key<<' ';
        now=now->next;
    }
    cout<<now->key<<endl;
}
Node* find(Node* head_ref, int key){
    Node *now=head_ref;
    while (now!=nullptr){
        if (now->key==key)
            return now;
        now=now->next;
    }
    return nullptr;
}
void remove_key(Node*& head_ptr, int key){
    if (head_ptr==nullptr)
        return;
    if (head_ptr->key==key){
        Node *mem=head_ptr->next;
        delete head_ptr;
        head_ptr=mem;
        return;
    }
    Node *now=head_ptr;
    while (now->next!=nullptr){
        if (now->next->key==key)
            break;
        now=now->next;
    }
    if (now->next==nullptr)
        return;
    else {Node *mem=now->next->next;
        delete now->next;
        now->next=mem;
        return;
    }
}

using std::cout;
using std::endl;

int main() {
}
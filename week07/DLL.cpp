#include <iostream>

struct Node{
    int key = 0;
    Node* next = nullptr;
    Node* prev = nullptr;
};

struct List{
    Node* HEAD = nullptr;
    Node* TAIL = nullptr;
    Node* NIL = nullptr;
    size_t size = 0;
};

List* create_empty_list(){
    List *list=new List;
    list->NIL=new Node;
    list->HEAD=list->NIL;
    list->TAIL=list->NIL;
    return list;
}
List* push_back(List* list_ptr, int new_key){
    if (list_ptr==nullptr)
        return list_ptr;
    Node *new_node=new Node;
    new_node->next=list_ptr->NIL;
    list_ptr->NIL->prev=new_node;
    new_node->key=new_key;
    if (list_ptr->TAIL==list_ptr->NIL){
        new_node->prev=list_ptr->NIL;
        list_ptr->NIL->next=new_node;
        list_ptr->HEAD=new_node;
    }
    else {new_node->prev=list_ptr->TAIL;
    list_ptr->TAIL->next=new_node;
    }
    list_ptr->TAIL=new_node;
    list_ptr->size++;
    return list_ptr;
}
List* push_front(List* list_ptr, int new_key){
    if (list_ptr==nullptr)
        return list_ptr;
    Node *new_node=new Node;
    new_node->prev=list_ptr->NIL;
    list_ptr->NIL->next=new_node;
    new_node->key=new_key;
    if (list_ptr->HEAD==list_ptr->NIL){
        new_node->next=list_ptr->NIL;
        list_ptr->NIL->prev=new_node;
        list_ptr->TAIL=new_node;
    }
    else {new_node->next=list_ptr->HEAD;
    list_ptr->HEAD->prev=new_node;
    }
    list_ptr->HEAD=new_node;
    list_ptr->size++;
    return list_ptr;
}
List* insert_after(List* list_ptr, Node* prev_ptr, int new_key){
    if (list_ptr==nullptr or prev_ptr==nullptr)
        return list_ptr;
    Node *new_node= new Node;
    new_node->prev=prev_ptr;
    new_node->key=new_key;
    if (new_node->prev->next==list_ptr->NIL){
        list_ptr->TAIL=new_node;
        list_ptr->NIL->prev=new_node;
        new_node->next=list_ptr->NIL;
        if (new_node->prev==list_ptr->NIL){
            list_ptr->HEAD=new_node;
            list_ptr->NIL->next=new_node;
        }
        else new_node->prev->next=new_node;
        list_ptr->size++;
        return list_ptr;
    }
    else if (new_node->prev==list_ptr->NIL){
        new_node->next=list_ptr->HEAD;
        list_ptr->HEAD->prev=new_node;
        list_ptr->HEAD=new_node;
        list_ptr->NIL->next=new_node;
        list_ptr->size++;
        return list_ptr;
    }
    else {new_node->prev->next->prev=new_node;
        new_node->next=new_node->prev->next;
        new_node->prev->next=new_node;
        list_ptr->size++;
        return list_ptr;
    }
}
void print_list(const List* list_ptr){
    if ((list_ptr==nullptr) or (list_ptr->HEAD==list_ptr->NIL)){
        cout<<endl;
        return;
    }
    Node *move=list_ptr->HEAD;
    while (move != list_ptr->NIL){
        cout << move->key;
        move = move->next;
        if (move != list_ptr->NIL){
            cout << ' ';
        }
    }
    cout << endl;
}
void clear_list(List* list_ptr){
    if ((list_ptr==nullptr) or (list_ptr->HEAD==list_ptr->NIL))
        return;
    Node *mem=list_ptr->HEAD;
    while (mem!=list_ptr->NIL){
        mem=mem->next;
        delete mem->prev;
    }
    list_ptr->size=0;
    list_ptr->HEAD=list_ptr->NIL;
    list_ptr->TAIL=list_ptr->NIL;
}
void destroy_list(List* list_ptr){
    if (list_ptr==nullptr)
        return;
    if (list_ptr->HEAD == list_ptr->NIL) {
        delete list_ptr->NIL;
        delete list_ptr;
        return;
    }
    Node *mem=list_ptr->HEAD;
    while(mem->next!=list_ptr->NIL){
        mem=mem->next;
        delete mem->prev;
    }
    delete mem;
    delete list_ptr->NIL;
    delete list_ptr;
}
Node* find_key(List* list_ptr, int key){
    if (list_ptr==nullptr)
        return nullptr;
    Node *mem=list_ptr->HEAD;
    while(mem!=list_ptr->NIL){
        if (mem->key==key)
            break;
        mem=mem->next;
    }
    return mem;
}
void remove_key(List* list_ptr, int key){
    if ((list_ptr==nullptr) or (list_ptr->HEAD=list_ptr->NIL))
        return;
    Node *mem=list_ptr->HEAD;
    while ((mem->key != key) and (mem->next != list_ptr->NIL)){
        mem = mem->next;
    }
    if (mem->key == key){
        mem->prev->next = mem->next;
        mem->next->prev = mem->prev;
        if (mem->prev == list_ptr->NIL){
            list_ptr->HEAD = mem->next;
        }
        if (mem->next == list_ptr->NIL){
            list_ptr->TAIL = mem->prev;
        }
        list_ptr->size--;
        delete mem;
    }
}


using std::cout;
using std::endl;

int main() {
  List* list = create_empty_list();
  push_back(list, 0);
  push_back(list, 1);
  push_back(list, 2);
  remove_key(list, 2);
  if (list->TAIL->key == 1) {
    cout << "OK" << endl;
  }
  return 0;
}
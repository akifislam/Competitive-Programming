#include<bits/stdc++.h>

using namespace std;


typedef struct node *Node;

struct node {
    int data;
    struct node *next;
};

Node first = NULL;
Node last = NULL;

int calculateSize(Node start){
    Node ptr = start;
    int size = 0;

    while(ptr!=NULL){
        size++;
        ptr = ptr->next;
    }
    cout<<"Size : "<<size<<endl;
    return size;
}



Node getnode() {
    Node p;
    p = (Node) malloc(sizeof(struct node));
    return p;
}



void addFirst(int value){
    Node new_node = getnode();
    new_node->data = value;
    new_node->next = first;
    first = new_node;
}

void addLast(int value){
    Node new_node;
    new_node = getnode();
    new_node->data = value;

    if(first == NULL){
        first = last  = new_node;
//        cout<<"Got First Node"<<endl;

    }
    else {
        last->next = new_node;
        last = new_node;
        cout<<"Inserted : "<<value<<endl;
    }
}


void addatPosition(int pos, int value){
    int size = calculateSize(first);
    if(pos == 1){
        addFirst(value);
        return;
    }
    if(pos==size+1){
        addLast(value);
        return;
    }
    if(pos>size+1){
        cout<<"Invalid Position"<<endl;
        return;
    }
    Node new_node = getnode();
    new_node->data = value;

    int cur_pos = 1;
    Node ptr = first;

    while(cur_pos < pos -1){
        cur_pos++;
        ptr = ptr->next;
    }
    new_node->next = ptr->next;
    ptr->next = new_node;
}

void removeAtFirst(){

}
void traverse(Node start) {
    cout<<"---------"<<endl;
    Node ptr = start;
    while (ptr != NULL) {
        cout << ptr->data << " ";
        ptr = ptr->next;
    }
    cout<<endl;
    cout<<"---------"<<endl;
}



int main() {
    addLast(1);
    addLast(2);
    addLast(3);
    addLast(4);
    addLast(5);
    addLast(6);
    addLast(7);
    addLast(8);
    addatPosition(9,9);
    addatPosition(1,-1);
    traverse(first);
}
#include<iostream>

using namespace std;

struct node{
    int data;
    struct node *next;
};

typedef struct node *Node;

Node getnode(void);
Node insertnode(Node ptr, int value);
void traverse(Node ptr);
void insert_to_pos(Node start,int pos, int data);
 
int main()
{
    int i, n, value;
    Node start, ptr;
    ptr = start;

    do
    {
        cin>>n;
        if(n>=0) ptr = insertnode(ptr, n);
    } while (n>=0);
    ptr->next = NULL;
    // start = start->next;
    
    
    insert_to_pos(start, 1, 400);
    traverse(start);

    return 0;
}

Node getnode(void)
{
    Node p;
    p = (Node) malloc(sizeof(struct node));
    return p;
}

Node insertnode(Node ptr, int value)
{
    Node q;
    q = getnode();
    q->data = value;
    ptr->next = q;
    return q;
}

void traverse(Node start)
{
    Node ptr = start;
    while(ptr != NULL)
    {
        ptr = ptr->next;
        cout<<ptr->data<<" ";      
    }
}

void insert_to_pos(Node start,int pos, int data)
{
    Node ptr = start;
    Node q = getnode();
    q->data = data;
    
    if(pos <1)
    {
        return;
    }

    if(pos == 1)
    {
        q->next = ptr->next;
        ptr->next = q;
    }

    else
    {
        for (int i = 2; i <= pos; i++)
        {
            if(ptr->next == NULL)
                break;

            ptr = ptr->next;
        }
        q->next = ptr->next;
        ptr->next = q;   
    }   
}
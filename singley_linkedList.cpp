#include<iostream>

using namespace std;

class Node
{
    public:
        int data;
        Node* next;
};

// GLOBAL HEAD 
Node* head = NULL;


// GIVES THE LENGTH OF THE LINKED LIST ---- > O(n)
int len(Node* node){
    Node* temp1=NULL;
    temp1 = node;

    int count=0;
    while (temp1!=NULL)
    {
        count+=1;
        temp1 = temp1->next;
    }
    return count;
}



// ADDS A NODE IN Nth POSITION ----> O(n)
Node* add_node(Node* node, int data, int pos=len(head)){
    
    if((pos>len(head)+1) or (pos<0)){
       throw std::invalid_argument( "received invalid position" );
    }

    if(pos==0){
        Node* pointer = NULL;
        pointer = new Node();
        pointer->data = data;
        pointer->next = head;
        head = pointer;

        return head;
    }

    if(pos>0 and pos<len(head)){
        Node* temp2 = head;
        Node* pointer = NULL;
        pointer = new Node();
        pointer->data = data;

        for (int i = 0; i < pos-2; i++)
        {
            temp2 = temp2->next;
        }

        pointer->next = temp2->next;
        temp2->next = pointer;

        return head;
    }

    // cout<<len(head)<<" ";
    else{

        Node* pointer = NULL;
        pointer = new Node();
        pointer->data = data;
        pointer->next = NULL;

        Node* temp1 = head;
        while (temp1->next != NULL)
        {
            temp1 = temp1 ->next; 
        }
        
        temp1->next = pointer;
        

        // cout<<len(head)<<endl;

        return head;
    }
}

// Delete the Node at nth position O(n)
Node* delete_node(Node* node, int pos=len(head)){
    if((pos>len(head)) or (pos<0)){
       throw std::invalid_argument( "received invalid position" );
    }

    if(pos==0){
        Node* temp = head;
        head = temp->next;
        delete(temp);
        return head;

    }

    if(pos>0 and pos<len(head)){

        Node* temp1 = head;
        for (int i = 0; i < pos-2; i++)
        {
            temp1 = temp1->next;
        }
        Node* temp2 = temp1->next;
        temp1->next = temp2->next;
        delete(temp2);
        return head;
    }

    else{
        
        Node* temp1=NULL;
        temp1 = node;
        
        while (temp1->next->next!=NULL)
        {
            temp1 = temp1->next;
        }
        delete(temp1->next);
        temp1->next = NULL;
    }
}

// Recuursion Method to Delete
void delete_val(int val){
    Node* temp1 = head;
    for (int i = 0; i < len(head); i++)
        {   
            if(temp1->data==val){
                delete_node(head, i+1);
                return;
            }
            temp1 = temp1->next;
        }
        throw std::invalid_argument( "received invalid value" );
}

// Reverese 
void reverse()
{
    Node *current, *prev, *next;
    current = head;
    prev = NULL;

    while(current!=NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    head = prev;
}

// Printing the Linked List
void Print(Node* n){
    if(n==NULL){
        return;
    }
    cout<<n->data<<" -> ";
    Print(n->next);
}

// Recuursion Print
void ReversePrint(Node* n){
    if(n==NULL){
        return;
    }
    ReversePrint(n->next);
    cout<<n->data<<" -> ";
}

// Reverse the Linked List Using Recurrsion
void ReverseRecur(Node* n){
    if(n==NULL){
        head = n;
        return;
    }
    ReverseRecur(n->next);
    Node* q=n->next;
    q->next = n;
    n->next = NULL;
    // Instead of above lines
    // n->next->next = n;

}



int main(){

    head = NULL;

    add_node(head, 3);
    add_node(head, 1);
    add_node(head, 7,2);
    add_node(head, 9,0);
    add_node(head, 5);
    add_node(head, 8);

    Print(head);
    
    cout<<"NULL"<<endl;

    ReverseRecur(head);
    Print(head);
    cout<<"NULL"<<endl;


    return 0;
}

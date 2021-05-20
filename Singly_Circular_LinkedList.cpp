#include<iostream>

using namespace std;

// Singly Circular Linked List
class Node{
    public:
        int data;
        Node* next;
};

Node* head;

int len(Node* node){
    int count=0;
    while (node->next!=head)
    {
        node = node->next;
        count++;
    }
    return count+1;
}

Node* GetNode(int x){
    Node* newNode = new Node;
    newNode->data = x;
    newNode->next = NULL;
    return newNode;
}

void addNode_start(int x){
    Node* newNode = GetNode(x);
    if(head == NULL){
        head = newNode;
        head->next = head;
        return;
    }
    Node* temp = head;
    newNode->next = temp;
    while (temp->next!=head)
    {
        temp = temp->next;
    }

    
    temp->next = newNode;
    head = newNode;
    
}

// ADD NODE At position p ---> O(n)
void addNode_at_n(int x, int pos){
    Node* newNode = GetNode(x);
    if(abs(pos)!=pos){
         throw std::invalid_argument( "received invalid position" );
    }
    else if (pos<1)
    {
         throw std::invalid_argument( "received invalid position" );
    }
    else if(pos>len(head)+1)
    {
        throw std::invalid_argument( "received invalid position" );
    }
    
    else if(head == NULL){
        head = newNode;
        head->next = head;
        return;
    }
    else if(pos==1){
        addNode_start(x);
    }
    else
    {
        Node* temp = head;
        for(int i=0; i<pos-2; i++)
        {
            temp = temp->next;
        }  
        newNode->next = temp->next;
        temp->next = newNode;
    }
    
}

void deleteNode_at_n(int pos){

    if(abs(pos)!=pos){
         throw std::invalid_argument( "received invalid position" );
    }
    else if (pos<1)
    {
         throw std::invalid_argument( "received invalid position" );
    }
    else if(pos>len(head)+1)
    {
        throw std::invalid_argument( "received invalid position" );
    }
    else if(head == NULL){
        throw std::invalid_argument( "No position to delete at empty List" );
        return;
    }
    else if(pos==1){
        try
        {
            Node*temp = head;

            while (temp->next!=head)
            {
                temp = temp->next;
            }
            temp->next = temp->next->next;
            head = temp->next;
            
        }
        catch(const std::exception& e)
        {
            head = NULL;
        }
    }
    else
    {
        Node* temp = head;
        for(int i=0; i<pos-2; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
    }
    
}


void Print(){
    Node* temp = head;
    while (temp->next!=head)
    {
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    cout<<temp->data<<" -> ";
    cout<<"NULL"<<endl;
    
}

int main(){

    addNode_start(3);
    addNode_start(10);
    addNode_start(4);
    addNode_at_n(100,1);
    addNode_start(5);
    addNode_start(7);
    deleteNode_at_n(1);
    Print();

    return 0;
}

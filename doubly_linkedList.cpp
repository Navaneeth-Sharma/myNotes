#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node* prev;
};


Node* head;

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



Node* GetNewNode(int x){
    Node* newNode = new Node;
    newNode->data = x;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

void InsertAtHead(int x){
    Node* newNode = GetNewNode(x);
    if(head==NULL){
        head = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

void InsertAtTail(int x){
    Node* newNode = GetNewNode(x);
    if(head==NULL){
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next!=NULL)
    {
        temp = temp->next;
    }
    
    temp->next = newNode;
    newNode->prev = temp;
    // head = newNode;
}

void delete_node(int position){
    /*
    deletes at position 
    */
   Node* temp = head;
   if(position<1){
        throw std::invalid_argument( "received invalid position" );
    }
   if(position==1){
        head = temp->next;
        temp->next->prev = NULL;
        return;
   }
   else
   if(position>1 and position<len(head)){
       for (int i = 0; i < position-1; i++)
       {
           temp = temp->next;
       }
       temp->next = temp->next->next;
       temp->next->prev = temp;
   }
   else{
       while (temp->next!=NULL)
       {
           temp = temp->next;
       }

       
   }
}


void Print(){
    Node* temp=head;
    cout<<"Forward: ";
    while(temp->next!=NULL){
        cout<<temp->data<<" -> ";
        temp = temp->next;
    }
    cout<<temp->data<<" -> ";
    cout<<"NULL"<<endl;

    cout<<"Reverse: ";
    while(temp!=NULL){
        cout<<temp->data<<" -> ";
        temp = temp->prev;
    }
    cout<<"NULL"<<endl;
}



int main(){

    head = NULL;
    InsertAtHead(3);
    // InsertAtHead(5);
    InsertAtTail(5);
    InsertAtTail(10);
    InsertAtTail(50);

    Print();
    cout<<endl;

    delete_node(1);


    Print();

    return 0;
}

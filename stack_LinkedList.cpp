#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* next;
};


class Stack{
    private:
        Node* top = NULL;
    public:
        
        
        void push(int x){
            Node* temp = new Node;
            temp->data = x;
            temp->next = top;
            top = temp;
        }

        void pop(){
            if(top==NULL) return;

            Node* temp = top;
            top = top->next;
            delete(temp);
            
        }

        int Top(){
            if (top==NULL) return -1;
            return top->data;
        }

        bool IsEmpty(){
            if(top==NULL) return false;
            return true;
        }

        void Print(){
            Node* temp = top;

            while (temp!=NULL)
            {
                cout<<temp->data<<" ";
                temp = temp->next;
            }
            cout<<endl;
        }
};





int main(){

    Stack s1;

    cout<<s1.IsEmpty()<<endl;

    s1.push(3);
    s1.push(4);
    s1.push(10);
    s1.push(7);

    s1.Print();

    cout<<s1.IsEmpty()<<endl;
    cout<<s1.Top()<<endl;

    s1.pop();
    s1.pop();

    s1.Print();


    return 0;
}

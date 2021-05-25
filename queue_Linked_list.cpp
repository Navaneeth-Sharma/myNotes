#include<iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* next;
};

class queue{
        Node* front = NULL;
        Node* rear = NULL;
    public:
        void enqueue(int x){
            Node* temp = new Node;
            temp->data = x;
            temp->next = NULL;

            if(front==NULL and rear==NULL){
                front = rear = temp;
            }
            rear->next = temp;
            rear = temp;
        }

        void dequeue(){
            Node* temp = front;
            if(front == NULL) return;
            if(front==rear){
                front = rear = NULL;
            }
            else{
                front = front->next;
            }
            delete(temp);
        }

        bool isEmpty(){
            if(rear==NULL){
                return true;
            }
            return false;
        }

        int Front(){
            return rear->data;
        }

        void print(){
            
            Node* temp = front;
            cout<<"Queue: ";
            while (temp!=NULL)
            {
                cout<<temp->data<<" ";
                temp = temp->next;
            }
        }
};



int main(){

    queue Q;
    Q.enqueue(3);
    Q.enqueue(5);
    Q.enqueue(10);
    Q.dequeue();
    cout<<"The Front element is : "<<Q.Front()<<endl;
    cout<<Q.isEmpty()<<endl;
    Q.print();

    return 0;
}

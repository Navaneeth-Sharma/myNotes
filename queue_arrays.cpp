#include<iostream>

using namespace std;

class queue{
    private:
        int arr[100];
        int front=-1,rear=-1;
    public:

        bool isEmpty(){
            if ((front==-1) and (rear==-1)){
                return true;
            }
            else{
                return false;
            }
        }

        bool IsFull(){
            if (rear==99){
                return true;
            }
            return false;
        }

        void enqueue(int x){
            if(IsFull()) return;
            if(isEmpty())
                {
                    front=0;
                    rear=0;
                }
            else{
                rear = rear + 1;
            }
            arr[rear] = x;
        }

        void dequeue(){
            if(IsFull()) return;
            if(isEmpty()) return;
            else
            {
                front = front + 1;
            }
            
        }

        void print(){
            cout<<"Queue: ";
            for (int i = front; i <= rear; i++)
            {
                cout<<arr[i]<<" ";
            }  
            cout<<endl;
        }

};

int main(){

    queue Q;
    Q.enqueue(3);
    Q.enqueue(5);
    Q.enqueue(10);
    Q.print();

    Q.dequeue();
    Q.print();

    cout<<"Is Full ?:  "<<Q.IsFull()<<endl;
    cout<<"Is Empty: "<<Q.isEmpty()<<endl;


    return 0;
}

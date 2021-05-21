#include<iostream>

using namespace std;

class stack{

    private:
        int A[100];
        int top=-1;
    public:
        void push(int x){
        if(top == 99){
            cout<<"Not possible";
            return;
            }
            A[++top] = x;
        }

        void pop(){
            top--;
        }

        int Top(){
            return A[top];
        }

        void IsEmpty(){
            if(top==-1) return;
            else true;
        }

        void Print(){
            for (int i = 0; i <= top; i++)
            {
                cout<<A[i]<<" ";
            }
            cout<<endl;   
        }

};

int main(){

    stack s;
    s.push(5);s.Print();
    s.push(7);s.Print();
    s.push(23);s.Print();
    s.pop();s.Print();
    cout<<"The Top Element is "<<s.Top();

    return 0;
}

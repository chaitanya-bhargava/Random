#include <iostream> 
using namespace std;

class Queue{
    public:
    int arr[10];
    int front,rear;
    bool isEmpty(){
        if((front==-1)||(front==(rear-1))){
            return true;
        }
        else{
            return false;
        }
    }
    bool isFull(){
        if((front-rear)==9){
            return true;
        }
        else{
            return false;
        }
    }
    void enqueue(int a){
        if(isFull()){
            cout<<"Queue is full\n";
        }else{
        front++;
        arr[front]=a;
        }
    }
    int dequeue(){
        if(isEmpty()){
            cout<<"Queue is empty\n";
            return 0;
        }else{
        int temp=arr[rear];
        rear++;
        return temp;
        }
    }
    void display(){
        for(int i=rear;i<front+1;i++){
            cout<<arr[i]<<"\n";
        }
    }
    Queue(){
        front=-1;
        rear=0;
        for(int i=0;i<10;i++){
            arr[i]=0;
        }
    }
};

class Stack{
    public:
        Queue q1;
        void push(int n){
            q1.enqueue(n);
        }
        int pop(){
            for(int i=0;i<q1.front-q1.rear;i++){
                int x=q1.dequeue();
                q1.enqueue(x);
            }

            return q1.dequeue();
        }
};

int main(){
    Stack S1;
    S1.push(5);
    S1.push(6);
    S1.push(7);
    S1.push(8);
    int x = S1.pop();
    cout<<x;
    return 0;
}
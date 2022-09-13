#include <iostream> 
using namespace std;

class Queue{
    private:
    int arr[10];
    int front,rear;
    public:
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
    void dequeue(){
        if(isEmpty()){
            cout<<"Queue is empty\n";
        }else{
        rear++;
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



int main(){
    Queue q1;
    q1.dequeue();
    q1.enqueue(1);
    q1.enqueue(2);
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);
    q1.enqueue(6);
    q1.enqueue(7);
    q1.enqueue(8);
    q1.enqueue(9);
    q1.enqueue(10);
    q1.enqueue(11);
    q1.enqueue(12);
    q1.display();
    q1.dequeue();
    q1.dequeue();
    q1.display();
    return 0;
}
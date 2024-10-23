#include <iostream>
using namespace std;
template <class T>
class Queue
{
private:
    T *data;
    int front;
    int rear;
    const int MAX_SIZE;
public:
    // Constructor
    Queue(const int MAX_SIZE = 5):MAX_SIZE(MAX_SIZE){
        data = new T[MAX_SIZE];
        front=-1;
        rear=-1;
    }
    // Default MAX_SIZE set to 10
    // Destructor
    ~Queue(){
        delete[] data;
    }
    // Queue manipulation operations
    void enQueue(const T newItem){
        if(!isFull()){
            if(front==-1){
                front++;
            }
            rear=(rear+1)%MAX_SIZE;
            data[rear]=newItem;
        }else{
            cout<<"que full hai"<<endl;
        }
    }
    // Enqueue a new item onto the queue
    void deQueue(){
        if(!isEmpty()){
            if(front<rear){
            front=(front+1)%MAX_SIZE;
            }
        }
    }
    // Dequeue an item from the queue
    void clear(){
        if(!isEmpty()){
        rear=-1;
        front=-1;
        }
    }
    // clear the queue
    // Queue accessors
    T getFront() const{
        if(!isEmpty()){
        return data[front];
        }
    }
    // Return item at the front of the queue
    T getRear() const{
        if(!isEmpty()){
        return data[rear];
        }
    };
    // Return item at the rear of the queue
    // Queue status operations
    bool isEmpty() const{
        if(front==-1 && rear==-1){
            return true;
        }else{
            return false;
        }
    }
    // Check if the queue is empty
    bool isFull() const{
        if(((rear+1) % MAX_SIZE)==front){
            return true;
        }else{
            return false;
        }
    }
    void showStructure() const{
        cout<<"front :"<<front<<endl;
        cout<<"rear :"<<rear<<endl;
        if(!isEmpty()){
            for(int i=front;i<=rear;i++){
                cout<<data[i]<<endl;
            }
        }
    }


};
int main()
{
    Queue<int> obj(5);
    obj.enQueue(3);
    obj.enQueue(6);
    obj.enQueue(9);
    obj.enQueue(5);
    obj.enQueue(10);
    obj.deQueue();
    obj.enQueue(11);
    obj.enQueue(5);
    obj.showStructure();
    cout << "hello" << endl;
}
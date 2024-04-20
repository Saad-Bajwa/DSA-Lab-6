#include <iostream>
using namespace std;
class Node
{
private:
    int data;
    Node *next;

public:
    Node();
    int GetData();
    Node *GetNext();
    void SetData(int val);
    void SetNext(Node *adr);
};
Node::Node()
{
    next = nullptr;
}
void Node::SetData(int val)
{
    data = val;
}
void Node::SetNext(Node *adr)
{
    next = adr;
}
int Node::GetData()
{
    return data;
}
Node *Node::GetNext()
{
    return next;
}
class LinkedList
{
private:
    Node *head;
    Node *tail;

public:
    LinkedList();
    void Insert(int data);
    void Delete();
    void Print();
    bool IsEmpty();
    int GetFirst();
    ~LinkedList();
};

LinkedList::LinkedList()
{
    head = nullptr;
    tail = nullptr;
}
LinkedList::~LinkedList()
{
    Node *current = head;
    while (current != nullptr)
    {
        Node *temp = current->GetNext();
        delete current;
        current = temp;
    }
}
bool LinkedList::IsEmpty(){
    if(tail==nullptr){
        return true;
    }
    return false;
}
void LinkedList::Insert(int data)
{
    Node *newNode = new Node;
    newNode->SetData(data);
    if (head == nullptr)
    {
        head = newNode;
        tail = newNode;
    }
    else
    {
        tail->SetNext(newNode);
        tail = newNode;
    }
}
void LinkedList::Delete()
{
    Node *temp = head->GetNext();
    delete head;
    head = temp;
}
void LinkedList::Print()
{
    Node *temp = head;
    while (temp != nullptr)
    {
        cout << temp->GetData() << " ";
        temp = temp->GetNext();
    }
    cout << endl;
}
int LinkedList::GetFirst(){
    if(!IsEmpty()){
        return head->GetData();
    }
    return -1;
}
class LinkedListQueue
{
private:
    LinkedList list;

public:
    LinkedListQueue();
    void Enqueue(int);
    void Dequeue();
    void PrintQueue();
    bool IsEmpty();
    int GetFront();
};
LinkedListQueue::LinkedListQueue(){
    //There is nothing there because i have implemented already a linked list class above
}
void LinkedListQueue::Enqueue(int data){
    list.Insert(data);
}
void LinkedListQueue::Dequeue(){
    if(!list.IsEmpty()){
        list.Delete();
    }
    else{
        cout << "List is empty.Can't delete data"<< endl;
    }
}
void LinkedListQueue::PrintQueue(){
    list.Print();
}
bool LinkedListQueue::IsEmpty(){
    if(list.IsEmpty()){
        return true;
    }
    return false;
}
int LinkedListQueue:: GetFront(){
    return list.GetFirst();
}
class ArrayQueue{
    private:
        int* array;
        int capacity;
        int size;
        int rear;
        int front;
    public:
        ArrayQueue(int capacity);
        void Enqueue(int data);
        void Dequeue();
        void PrintQueue();
        bool IsEmpty();
        bool IsFull();
        int GetFront();
        ~ArrayQueue();
};
ArrayQueue::ArrayQueue(int capacity){
    this->capacity = capacity;
    array = new int[capacity];
    size = 0;
    front = 0;
    rear = -1;
}
ArrayQueue::~ArrayQueue(){
    delete[] array;
}
bool ArrayQueue::IsFull(){
    return size == capacity;
}
bool ArrayQueue::IsEmpty(){
    return size == 0;
}
void ArrayQueue::Enqueue(int data){
    if(IsFull()){
        cout << "Can't insert the data queue is full" << endl;
        return;
    }
    rear = (rear+1)%5;
    array[rear] = data;
    size++;
}
void ArrayQueue::Dequeue(){
    if(IsEmpty()){
        cout << "Queue is empty!!!" << endl;
        return;
    }
    front = (front+1)%capacity;
    size--;
}
void ArrayQueue::PrintQueue(){
    if (IsEmpty()) {
        cout << "Queue is empty.\n";
        return;
    }
    int i = front;
    while (i != rear) {
        cout << array[i] << " ";
        i = (i + 1) % capacity;
    }
    cout << array[rear] << endl;
}
int ArrayQueue::GetFront() {
    if (IsEmpty()) {
        cout << "Queue is empty.\n";
        return -1;
    }
    return array[front];
}
int main()
{
    //LinkedList Queue
    LinkedListQueue que;
    que.Enqueue(1);
    que.Enqueue(1);
    que.Enqueue(1);
    que.Enqueue(1);
    que.Enqueue(1);
    que.Enqueue(1);
    que.Enqueue(1);
    que.Enqueue(1);
    que.Dequeue();
    que.Dequeue();
    que.Dequeue();
    que.Dequeue();
    cout << "The front of the queue is " << que.GetFront() << endl;
    que.PrintQueue();

    //Array Queue

    ArrayQueue queue(5); 

    queue.Enqueue(1);
    queue.Enqueue(2);
    queue.Enqueue(3);
    queue.Enqueue(4);
    queue.Enqueue(5);

    cout << "Queue elements: ";
    queue.PrintQueue();

    cout << "Front element: " << queue.GetFront() << endl;

    queue.Dequeue();
    queue.Dequeue();

    cout << "After dequeueing two elements:\n";
    cout << "Queue elements: ";
    queue.PrintQueue();
    queue.Dequeue();
    queue.PrintQueue();
}
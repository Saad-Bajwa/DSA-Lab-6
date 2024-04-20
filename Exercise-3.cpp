#include <iostream>
using namespace std;
class Node
{
private:
    int data;
    Node *next;

public:
    Node();
    void SetData(int val);
    void SetNext(Node *adr);
    int GetData();
    Node *GetNext();
};
Node::Node()
{
    next = nullptr;
}
int Node::GetData()
{
    return data;
}
Node *Node::GetNext()
{
    return next;
}
void Node::SetData(int val)
{
    data = val;
}
void Node::SetNext(Node *adr)
{
    next = adr;
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
    int GetFront();
    bool IsEmpty();
    void Print();
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
bool LinkedList::IsEmpty()
{
    return tail == nullptr;
}
int LinkedList::GetFront()
{
    if (!IsEmpty())
    {
        return tail->GetData();
    }
    return -1;
}
void LinkedList::Delete()
{
    if (IsEmpty())
    {
        cout << "The list is empty can't delete";
        return;
    }
    Node *temp = head->GetNext();
    delete head;
    head = temp;
}
void LinkedList::Print(){
    Node* temp =head;
    while(temp != nullptr){
        cout << temp->GetData() << " " ;
        temp = temp->GetNext();
    }
    cout << endl;
}
class ListQueue
{
private:
    LinkedList lst;

public:
    ListQueue();
    void Enqueue(int val);
    void Dequeue();
    void PrintQueue();
};
ListQueue::ListQueue()
{
    // Nothing to initialize in the queue
}
void ListQueue::Enqueue(int val)
{
    lst.Insert(val);
}
void ListQueue::Dequeue()
{
    lst.Delete();
}
void ListQueue::PrintQueue()
{
    lst.Print();
}
int main()
{
    int choice;
    ListQueue que;
    cout << "<------------------------Enter your choice<------------------------>\n";
    while (choice != 4)
    {
        cout << "1.Insert in the queue\n2.Delete from the queue\n3.Print the queue\n4.Exit from the program\n\n";
        cout << "\t\t\t----Your choice : ";
        cin >> choice;
        switch (choice)
        {
        case 1:
            int val;
            cout << "Enter the value to insert in the que : ";
            cin >> val;
            que.Enqueue(val);
            break;
        case 2:
            que.Dequeue();
            break;
        case 3:
            que.PrintQueue();
            break;
        case 4:
            break;
        default:
            cout << "Invalid choice!!!" << endl;
        }
    }
    return 0;
}
#include <iostream>
#include <assert.h>>

using namespace std;

struct Node
{
    const char* element;
    Node* next;
    Node* pre;

    Node(const char* e = "", Node* n = NULL, Node* m = NULL)
    {
        element = e;
        next = n;
        pre = m;
    }
};

struct DLinkedList
{
    Node* head;
    Node* tail;
    long size;

    DLinkedList() {
        head = new Node;
        tail = new Node;
        head->next = tail;
        tail->pre = head;
        head->pre = NULL;
        tail->next = NULL;
        size = 2;
    }

    void addFirst(const char* s)
    {
        Node* newNode = new Node;
        newNode->element = s;
        newNode->pre = NULL;
        newNode->next = head;
        head->pre = newNode;
        head = newNode;
        size++;
    }
    void addLast(const char* s)
    {
        Node* newNode = new Node;
        newNode->element = s;
        newNode->next = NULL;
        newNode->pre = tail;
        tail->next = newNode;
        tail = newNode;
        size++;
    }
    void print()
    {   
        assert(head != NULL);
        for (Node* p = head; p != NULL; p = p->next) {

            cout << p->element << " ";
        }
        cout << endl;
    }
    void removeFirst()
    {
        assert(head != NULL || tail != NULL);
        Node* tmp;
        tmp = head;
        head = head->next;
        head->pre = NULL;
        delete tmp;
        size--;
    }
    void destructor()
    {
        assert(head != NULL||tail!=NULL);
        long tmp = size;
        for (int i = 0; i < tmp; i++)
        {
            this->removeFirst();
        }

    }
    void removeLast()
    {
        assert(head != NULL || tail != NULL);
        Node* temp = new Node;
        temp = tail;
        tail = tail->pre;
        tail->next = NULL;
        delete temp;
        size--;
    }
    void insertAfter(Node* p, const char* s)
    {   
        assert(p != NULL && s != NULL);
        size++;
        Node* newNode = new Node;
        newNode->element = s;
        newNode->next = p->next;
        newNode->pre = p;
        p->next = newNode;
        newNode->next->pre = newNode;
    }
    const char* remove(Node* p)
    {   
        assert(p != NULL);
        const char* ch = p->element;
        if (p == head)
        {
            head = head->next;
            delete p;
            return ch;
        }
        Node* newNode = new Node;
        newNode = head;
        while (newNode->next != p)
        {
            newNode = newNode->next;
        }
        newNode->next = p->next;
        newNode->next->pre = newNode;
        delete p;
        return ch;
    }
};

void testA1(DLinkedList& L)
{
    cout << "A1:" << endl;
    L.addFirst("first");
    L.print();
    L.addLast("last");
    L.print();
    L.addFirst("newFrist");
    L.print();
}

void testA2(DLinkedList& L)
{
    cout << "A2:" << endl;
    L.removeFirst();
    L.print();
}


void testA3(DLinkedList& L)
{
    cout << "A3" << endl;
    L.destructor();
    L.print();
}

void testA4(DLinkedList& L)
{
    cout << "A4" << endl;
    L.removeLast();
    L.print();
}

void testA5(DLinkedList& L)
{
    cout << "A5" << endl;
    L.insertAfter(L.head, "afterFirst");
    L.print();
}

void testA6(DLinkedList& L)
{
    cout << "A6" << endl;
    cout << L.remove(L.head) << endl;
    L.print();
}
int main()
{
    DLinkedList L;
    testA1(L);
    testA2(L);
    testA4(L);
    testA5(L);
    testA6(L);

    return 0;
}
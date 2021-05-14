#include <iostream>
#include <assert.h>>

using namespace std;

struct Node
{
    const char* element;
    Node* next;

    Node(const char* e = NULL, Node* n = NULL)
    {
        element = e;
        next = n;
    }
};

struct SLinkedList
{
    Node* head;
    long size;

    SLinkedList() {
        head = NULL;
        size = 0;
    }

    void addFirst(const char* s)
    {
        Node* newNode = new Node;
        newNode->element = s;
        newNode->next = head;
        head = newNode;
        size++;
    }
    void addLast(const char* s)
    {
        Node* newNode = new Node;
        newNode->element = s;
        newNode->next = NULL;

        if (head == NULL)
        {
            head = newNode;
        }
        Node* temp = new Node;
        temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
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
        assert(head != NULL);
        Node* tmp;
        tmp = head;
        head = head->next;
        delete tmp;
        size--;
    }
    void destructor()
    {
        long tmp = size;
        for (int i = 0; i < tmp; i++)
        {
            this->removeFirst();
        }
    }
    void removeLast()
    {
        assert(head != NULL);
        Node* tail = new Node;
        Node* neartail = new Node;
        tail = head;

        while (tail->next != NULL)
        {
            neartail = tail;
            tail = tail->next;
        }
        neartail->next = NULL;
        delete tail;
    }
    void insertAfter(Node* p, const char* s)
    {
        assert(p != NULL && s != NULL);
        Node* newNode = new Node;
        newNode->element = s;
        newNode->next = p->next;
        p->next = newNode;
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
        delete p;
        return ch;
    }
};

void testA1(SLinkedList& L)
{
    cout << "A1:" << endl;
    L.addFirst("first");
    L.print();
    L.addLast("last");
    L.print();
    L.addFirst("newFrist");
    L.print();
}

void testA2(SLinkedList& L)
{
    cout << "A2:" << endl;
    L.removeFirst();
    L.print();
}


void testA3(SLinkedList& L)
{
    cout << "A3" << endl;
    L.destructor();
    L.print();
}

void testA4(SLinkedList& L)
{
    cout << "A4" << endl;
    L.removeLast();
    L.print();
}

void testA5(SLinkedList& L)
{
    cout << "A5" << endl;
    L.insertAfter(L.head, "afterFirst");
    L.print();
}

void testA6(SLinkedList& L)
{
    cout << "A6" << endl;
    cout << L.remove(L.head) << endl;
    L.print();
}
int main()
{
    SLinkedList L;

    testA1(L);
    testA2(L);
    testA4(L);
    testA5(L);
    testA6(L);
    return 0;
}
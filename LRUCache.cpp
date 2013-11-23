#include <iostream>
#include <map>

using namespace std;

struct Node
{
    int key;
    int value;
    Node *previous;
    Node *next;
    Node(int val): key(0), value(val), previous(NULL), next(NULL) {}
};

class DoublyLinkedList
{
public:
    Node *m_head, *m_tail;
    int m_size;
    DoublyLinkedList(): m_head(NULL), m_tail(NULL), m_size(0)
    {
        m_head = m_tail;
    }

    void PushFront(Node *pnode)
    {
        if (m_size == 0)
        {
            m_head = pnode;
            m_tail = pnode;
            pnode->next = NULL;
            pnode->previous = NULL;
        }
        else
        {
            pnode->next = m_head;
            pnode->previous = NULL;
            m_head->previous = pnode;
            m_head = pnode;
        }
        ++m_size;
    }

    void PushBack(Node *pnode)
    {
        if (m_size == 0)
        {
            m_head = pnode;
            m_tail = pnode;
            pnode->next = NULL;
            pnode->previous = NULL;
        }
        else
        {
            pnode->next = NULL;
            pnode->previous = m_tail;
            m_tail->next = pnode;
            m_tail = pnode;
        }
        ++m_size;
    }

    int PopFront()
    {
        int result = 0;
        if (m_size < 1)
        {
            cout<<"PopFront() failed!"<<endl;
            return -1;
        }
        else if (m_size == 1)
        {
            result = m_head->value;
            delete m_head;
            --m_size;
            m_head = NULL;
            m_tail = NULL;
            return result;
        }
        result = m_head->value;
        Node *pnode = m_head;
        m_head->next->previous = NULL;
        m_head = m_head->next;
        --m_size;
        delete pnode;
        return result;
    }

    int PopBack()
    {
        int result = 0;
        if (m_size < 1)
        {
            cout<<"PopBack() failed!"<<endl;
            return -1;
        }
        else if (m_size == 1)
        {
            result = m_head->value;
            delete m_head;
            --m_size;
            m_head = NULL;
            m_tail = NULL;
            return result;
        }
        result = m_tail->value;
        Node *pnode = m_tail;
        m_tail->previous->next = NULL;
        m_tail = m_tail->previous;
        --m_size;
        delete pnode;
        return result;
    }

    void MoveHead(Node *pnode)
    {
        Node *orinext = pnode->next, *oriprevious = pnode->previous;
        if (oriprevious != NULL) oriprevious->next = orinext;
        else return; //pnode is head
        if (orinext != NULL) orinext->previous = oriprevious;
        else //pnode is tail
        {
            m_tail = oriprevious;
        }
        pnode->next = m_head;
        m_head->previous = pnode;
        pnode->previous = NULL;
        m_head = pnode;
    }

    void PrintList()
    {
        cout<<"Positive Order:"<<endl;
        Node *iter = m_head;
        while(iter != NULL)
        {
            cout <<iter->value;
            if (iter->next !=NULL) cout<<",";
            else cout<<endl;
            iter = iter->next;
        }

        cout<<"Negative Order:"<<endl;
        iter = m_tail;
        while(iter != NULL)
        {
            cout <<iter->value;
            if (iter->previous !=NULL) cout<<",";
            else cout<<endl;
            iter = iter->previous;
        }
    }

    void Clear()
    {
        Node *iter = m_head, *temp;
        int size = 0;
        while(iter != NULL)
        {
            temp = iter->next;
            delete iter;
            ++size;
            iter = temp;
        }
        if (size != m_size) cout<<"List size inconsistent!"<<endl;
        m_size = 0;
    }
};

class LRUCache{
public:
    int m_capacity;
    DoublyLinkedList m_dll;
    map<int, Node *> m_existmap;
public:
    LRUCache(int capacity): m_capacity(capacity) {
        m_dll.Clear();
        m_existmap.clear();
    }

    int get(int key) {
        map<int, Node *>::iterator it;
        it = m_existmap.find(key);
        if (it != m_existmap.end())
        {
            m_dll.MoveHead(it->second);
            return it->second->value;
        }
        else return -1;
    }

    void set(int key, int value) {
        map<int, Node *>::iterator it, ittail;
        it = m_existmap.find(key);
        if (it == m_existmap.end())
        {
            if (m_existmap.size() < m_capacity)
            {
                Node *pnode = new Node(value);
                pnode->key = key;
                m_existmap.insert(make_pair(key, pnode));
                m_dll.PushFront(pnode);
            }
            else
            {
                ittail = m_existmap.find(m_dll.m_tail->key);
                m_existmap.erase(ittail);

                m_dll.m_tail->key = key;
                m_dll.m_tail->value = value;
                m_existmap.insert(make_pair(key, m_dll.m_tail));
                m_dll.MoveHead(m_dll.m_tail);
            }
        }
        else
        {
            it->second->value = value;
            m_dll.MoveHead(it->second);
        }
    }
};

int main()
{
    LRUCache lru(5);
    for (int i = 0; i < 10; ++i)
    {
        lru.set(i, i * 10);
    }
    cout<<lru.get(3)<<endl;
    cout<<lru.get(7)<<endl;
    lru.m_dll.PrintList();
    
//     // DoublyLinkedList Test
//     DoublyLinkedList dll;
//     Node *pnode = new Node(3), *t;
//     dll.PushFront(pnode);
//     pnode = new Node(4);
//     dll.PushFront(pnode);
//     pnode = new Node(5);
//     dll.PushFront(pnode);
//     pnode = new Node(6);
//     dll.PushFront(pnode);
//     pnode = new Node(2);
//     dll.PushBack(pnode);
//     pnode = new Node(1);
//     t = pnode;
//     dll.PushBack(pnode);
//     dll.PrintList();
//     dll.PopFront();
//     dll.PopFront();
//     dll.PopFront();
//     dll.MoveHead(t);
//     dll.PrintList();
//     cout<<dll.PopFront()<<endl;
//     dll.PrintList();
//     cout<<dll.PopBack()<<endl;
//     dll.PrintList();
//
//     dll.Clear();
//     pnode = new Node(2);
//     dll.PushBack(pnode);
//     dll.PrintList();
//     cout<<dll.PopFront()<<endl;
//     cout<<dll.PopBack()<<endl;
//     dll.PrintList();
//     dll.Clear();
    return 0;
}

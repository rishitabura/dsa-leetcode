#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *next;

    node(int val)
    {
        data = val;
        next = NULL;
    }
};

class Stack
{
    node* top;

public:
    Stack()
    {
        top = nullptr;
    }

    void push(int x)
    {
        node* newNode = new node(x);

        if (newNode ==nullptr)
        {
            cout << "Stack overflow";
            return;

        }
        newNode->data = x;
        newNode->next = top;
        top = newNode;

    }
    void pop()
    {
        if (top == nullptr)
        {
            cout << "Stack empty";
            return ;
        }
        node* temp;
        temp = top;
        top = top->next;
        delete(temp);

    }

    int Top()
    {
        if (top == nullptr)
        {
            cout << "Stack empty";
            return -1;
        }
        node* temp;
        temp = top;
        return temp->data;

    }
    bool empty()
    {
        if (top == nullptr)
        {
            return true;
        }
        return false;
    }

    void display()
    {
        node* temp;
        if (top == nullptr)
        {
            cout << "Empty";
            return;
        }
        else
        {
            temp = top;
            while (temp!=nullptr)
            {
                cout << temp->data << " ";
                temp = temp->next;
            }
            cout << endl;
            
        }
    }

    int getSize()
    {
        int count = 0;
        node* temp;
        if (top == nullptr)
        {
            return 0;
        }
        else
        {
            temp = top;
            while (temp!=nullptr)
            {
                count++;
                temp = temp->next;
            }
            return count;
        }

    }
};


int main()
{
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.pop();
    st.pop();
    st.display();
    cout << st.getSize();

    return 0;
}
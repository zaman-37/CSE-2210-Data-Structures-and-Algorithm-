// counting frequency of all the element of a linked list using another linked list...instead of using map or hashing.
// complexity is O(n^2)

#include <bits/stdc++.h>
using namespace std;

class Node1
{
public:
    int info;
    Node1 *link;
};
class Node2
{
public:
    int info;
    int freq;
    Node2 *link;
};

Node1 *head1 = NULL, *tem1;
Node2 *head2 = NULL, *tem2;

void allocate1(int a)
{
    Node1 *ptr = new Node1();
    ptr->info = a;
    ptr->link = NULL;

    if (head1 == NULL)
    {
        head1 = ptr;
    }
    else
    {
        tem1->link = ptr;
    }
    tem1 = ptr;
}

void allocate2(int a)
{
    Node2 *ptr = new Node2();
    ptr->info = a;
    ptr->freq = 1;
    ptr->link = NULL;

    if (head2 == NULL)
    {
        head2 = ptr;
    }
    else
    {
        tem2->link = ptr;
    }
    tem2 = ptr;
}

void traverse1()
{
    Node1 *ptr = head1;
    while (ptr != NULL)
    {
        cout << ptr->info << " ";
        ptr = ptr->link;
    }
    cout << endl;
}

void traverse2()
{
    Node2 *ptr = head2;
    while (ptr != NULL)
    {
        cout << ptr->info << " " << ptr->freq << endl;
        
        ptr = ptr->link;
    }
    cout << endl;
}

void count_freq()
{
    Node1 *ptr1 = head1;
    while (ptr1 != NULL) {
        Node2 *ptr2 = head2;
        bool fl = false;

        while (ptr2 != NULL) {
            if (ptr1->info == ptr2->info) {
                ptr2->freq = ptr2->freq + 1;
                fl = true;
                break;
            }
            ptr2 = ptr2->link;
        }
        if (fl == false) {
            allocate2(ptr1->info);
        }

        ptr1 = ptr1->link;
    }
}

int main()
{

    allocate1(1);
    allocate1(2);
    allocate1(3);
    allocate1(4);
    allocate1(4);
    allocate1(4);
    allocate1(5);
    allocate1(5);
    allocate1(5);
    allocate1(6);
    traverse1(); 

    count_freq();
    traverse2();

    return 0;
}
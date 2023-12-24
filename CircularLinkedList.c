#include "CircularLinkedList.h"

void Add_To_Head(int data)
{
    Node *Current = (Node*)malloc(sizeof(Node));
    Current->data = data;
    //Check if the List is Empty
    if(Head == NULL)
    {
        Head = Current;
        Head->next = NULL;
        Tail = Current;
        Tail->next = NULL;
    }
    else
    {
        //Addting to head
        Current->next = Head;
        Head = Current;
        Tail->next = Head;
    }
}

void Add_To_Tail(int data)
{
    Node *Current = (Node*)malloc(sizeof(Node));
    Current->data = data;
    //Check if the List is Empty
    if(Head == NULL)
    {
        Head = Current;
        Head->next = NULL;
        Tail = Current;
        Tail->next = NULL;
    }
    else
    {
        //Addting to tail
        Tail->next = Current;
        Tail = Current;
        Tail->next = Head;
    }
}

void Remove_From_Head(void)
{
    Node *myHead = Head;
    Head = Head->next;
    free(myHead);
    Tail->next = Head;
}

void Remove_From_Tail(void)
{
    if (Head == NULL) {
        // List is empty
        return;
    }

    Node *myTail = Tail;
    Node *temp = Head;

    while (temp->next != Tail)
    {
        temp = temp->next;
    }

    if (Tail == Head) {
        // Only one node in the list
        free(Tail);
        Head = Tail = NULL;
    } else {
        // More than one node in the list
        Tail = temp;
        free(myTail);
        Tail->next = Head;
    }
}

void Remove_From_Middle(int data)
{
    if (Head == NULL) {
        // List is empty
        return;
    }

    Node *temp = Head->next;
    Node *temp_prev = Head;

    while (temp != Head && temp->data != data)
    {
        temp_prev = temp;
        temp = temp->next;
    }

    if (temp == Head) {
        // Node with the specified data not found
        return;
    }

    temp_prev->next = temp->next;

    if (temp == Tail) {
        // Update Tail if the removed node was the Tail
        Tail = temp_prev;
    }

    free(temp);
}

void Print_CircularLinkedList(void)
{
    Node *temp;
    temp = Head;
    int i = 1;
    do {
        printf("Node%d: %d\n",i,temp->data);
        temp = temp->next;
        i++;
    } while (temp != Head);
}

int main()
{
    Add_To_Head(10);
    Add_To_Tail(20);
    Add_To_Head(5);
    Remove_From_Middle(10);
    Print_CircularLinkedList();
    return 0;
}
// remove nth node from end

#include <stdio.h>
#include <stdlib.h>
struct node
{
    int data;
    struct node *next;
    int flag;
};

struct node *removeNthFromEnd(struct node *head, int n)
{

    struct node *current, *prev, *next;
    current = head;
    prev = NULL;
    while (current != NULL)
    {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    // head = prev;

    struct node *p = prev;
    struct node *q = prev->next;

    for (int i = 1; i < n ; i++)
    {
        p = p->next;
        q = q->next;
    }

    p->next = q->next;
    free(q);
    head = prev;

    return head;
}

void linkedListTraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Elements : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main(int argc, char const *argv[])
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));
    struct node *third = (struct node *)malloc(sizeof(struct node));
    struct node *fourth = (struct node *)malloc(sizeof(struct node));

    head->data = 10;
    second->data = 23;
    third->data = 34;
    fourth->data = 67;

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = NULL;

    linkedListTraversal(head);
    head  =  removeNthFromEnd(head, 2);
    printf("After :\n");
    linkedListTraversal(head);

    return 0;
}

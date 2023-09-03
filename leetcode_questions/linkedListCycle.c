#include<stdio.h>
#include<stdlib.h>
struct node
{
    int data;
    struct node *next;
    int flag;
};

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
    fourth->next = second;

    struct node *ptr = head;
    ptr->flag = 0;

    while (ptr!= NULL)
    {
        ptr->flag = 1;
        printf("%d ",ptr->data);
        ptr = ptr->next;
        if (ptr->flag == 1)
        {
            return 0;
        }
        
    }

    // alternative
//    bool hasCycle(struct ListNode *head) {
//     struct ListNode *ptr = head;     // slow
//     struct ListNode *ptr2 = head;    // fast
    
//     while(ptr2!= NULL && ptr2->next != NULL)
//     {
//         ptr2 = ptr2->next->next;
//         ptr = ptr->next;

//         if(ptr == ptr2)
//         {
//             return true;
//         }
//     }

//     return false;
    


    return 0;
}

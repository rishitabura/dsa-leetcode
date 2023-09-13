// #include <stdio.h>
// #include <stdlib.h>
// struct node
// {
//     int data;
//     struct node *next;
// };

// struct node* deleteDuplicates(struct node *head)
// {

//     struct node *prev = head;
//     struct node *currentN = prev->next;
    
//     while (prev!=NULL &&currentN!=NULL && currentN->next != NULL)
//     {
//         if (currentN->data == currentN->next->data)
//         {
//             struct node *nextNode= currentN->next;
//             prev->next = currentN->next->next;
//             free(currentN);
//             free(nextNode);
        
//         }
//         else
//         {
//             prev = prev->next;
//             currentN = currentN->next;
//         }

//     }
//     return head;
   
// }

// void linkedListTraversal(struct node *ptr)
// {
//     while (ptr != NULL)
//     {
//         printf("Elements : %d\n", ptr->data);
//         ptr = ptr->next;
//     }
// }

// int main()
// {
//     struct node *head = (struct node *)malloc(sizeof(struct node));
//     struct node *second = (struct node *)malloc(sizeof(struct node));
//     struct node *third = (struct node *)malloc(sizeof(struct node));
//     struct node *fourth = (struct node *)malloc(sizeof(struct node));

//     head->data = 10;
//     second->data = 23;
//     third->data = 23;
//     fourth->data = 67;

//     head->next = second;
//     second->next = third;
//     third->next = fourth;
//     fourth->next = NULL;

//     head = deleteDuplicates(head);
//     linkedListTraversal(head);

//     return 0;
// }
#include <stdio.h>
#include <stdlib.h>

struct node
{
    int data;
    struct node *next;
};

void removeDuplicates(struct node *head)
{
    struct node *current = head;
    
    while (current != NULL)
    {
        struct node *runner = current;
        
        while (runner->next != NULL)
        {
            if (runner->next->data == current->data)
            {
                struct node *temp = runner->next;
                runner->next = runner->next->next;
                free(temp);
            }
            else
            {
                runner = runner->next;
            }
        }
        
        current = current->next;
    }
}

void linkedListTraversal(struct node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element: %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    struct node *head = (struct node *)malloc(sizeof(struct node));
    struct node *second = (struct node *)malloc(sizeof(struct node));
    struct node *third = (struct node *)malloc(sizeof(struct node));
    struct node *fourth = (struct node *)malloc(sizeof(struct node));
    struct node *fifth = (struct node *)malloc(sizeof(struct node));

    head->data = 10;
    second->data = 23;
    third->data = 23;
    fourth->data = 67;
    fifth->data = 67;

    head->next = second;
    second->next = third;
    third->next = fourth;
    fourth->next = fifth;
    fifth->next = NULL;

    removeDuplicates(head);
    linkedListTraversal(head);

    return 0;
}

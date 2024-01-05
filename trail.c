// #include<stdio.h>

// int main()
// {
//     int age;
//     printf("enter age : ");
//     scanf("%d", &age);

//     if (age > 18){ 
//         printf("adult \n");
//         printf(" they can vote \n");
//         printf(" they can drive \n");
        
//     }

//     else {
//         printf(" not adult \n");
//         printf(" they can't vote and drive \n");

//     }
//     return 0;
// }

#include<stdio.h>

int main()
{
    int age;
    printf("Enter age : ");
    scanf("%d", &age);
    
    if (age > 18)
    {
        printf("Can vote and can drive \n");

        printf("Can vote and can drive \n");
    }
    else
    {
        printf("Cannot vote and drive");
    }
    
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>
#include <conio.h>

struct node
{
    char *name[100];
    int age;
    char *address[100];
    int phone;
    int account_number;
    int priority;
    struct node *next;
};
struct node *start = NULL;
struct node *insert(struct node *);
struct node *delete (struct node *);
int main()
{

    int option;
    do
    {
        // system("COLOR 46");
        printf("\t\t\t-------------------------------\n");
        printf("\t\t\t\t\t\t\t\t\t\t\t\n");
        printf("\t\t\t\t\t\t\t\t\t\t\n");
        printf("\t\t\t WELCOME TO SR BANK!\n");
        printf("\t\t\t\t\t\t\t\t\t\t\n");
        printf("\t\t\t\t\t\t\t\t\t\t\n");
        printf("\t\t\t-------------------------------\n");
        printf("\t\t\t1.ADD AN ACCOUNT\n");
        printf("\t\t\t2.DELETE AN ACCOUNT\n");
        printf("\t\t\t3.DISPLAY ALL ACCOUNTS\n");
        printf("\t\t\t4.EXIT\n");
        printf("\t\t\tEnter your choice:");
        scanf("%d", &option);
        switch (option)
        {
        case 1:
            start = insert(start);
            getchar();
            system("cls");
            break;
        case 2:
            start = delete (start);
            getchar();
            system("cls");
            break;
        case 3:
            display(start);
            getchar();
            system("cls");
            break;
        case 4:
            exit(0);
            break;
        }
    } while (option != 4);
}
struct node *insert(struct node *start)
{
    int val2, val4, val6, pri;
    char val1, val3, val5;
    struct node *ptr, *p;
    char *name[100];
    char *address[100];
    ptr = (struct node *)malloc(sizeof(struct node));
    printf("Enter ACCOUNT HOLDER Name:");
    scanf(" %s", ptr->name);
    printf("Enter the ACCOUNT HOLDER age:");
    scanf("%d", &val2);
    printf("Enter your home address:");
    scanf(" %s", ptr->address);
    printf("Enter your phone number:");
    scanf("%d", &val4);
    printf("Enter the ACCOUNT NUMBER:");
    scanf("%d",&val6);
    printf("Account created successfully\n");
    // ptr->name=name;
    ptr->age = val2;
    // ptr->address=address;
    ptr->phone = val4;
    ptr->account_number = val6;
    ptr->priority = pri;
    if ((start == NULL) || pri < start->priority)
    {
        ptr->next = start;
        start = ptr;
    }
    else
    {
        p = start;
        while (p->next != NULL && p->next->priority <= pri)
            p = p->next;
        ptr->next = p->next;
        p->next = ptr;
    }
    return start;
};
struct node *delete (struct node *start)
{
    struct node *ptr;
    if (start == NULL)
    {
        printf("\n NO ACCOUNT RECORD TO DELETE");
        return;
    }
    else
    {
        ptr = start;
        printf("\n Deleted Record is : %d", ptr->account_number);
        start = start->next;
        free(ptr);
    }
    return start;
};
void display(struct node *start)
{
    struct node *ptr;
    ptr = start;
    if (start == NULL)
        printf("\nTHERE ARE NO ACCOUNTS");
    else
    {
        printf("\nACCOUNTS are:");
        while (ptr != NULL)
        {
            printf("The name of ACCOUNT HOLDER is:%s\n", ptr->name);
            printf("The age of ACCOUNT HOLDER is:%d\n", ptr->age);
            printf("The address of ACCOUNT HOLDER is : %s\n", ptr->address);
            printf("Phone Number:%d\n", ptr->phone);
            printf("Account number:%d\n",ptr->account_number);
            printf("---------------------------------------------------\n");
            ptr = ptr->next;
        }
    }
    getchar();
}

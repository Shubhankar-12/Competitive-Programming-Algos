#include<stdio.h>  
#include<stdlib.h>  
struct node  
{  
    struct node *prev;//previous pointer  
    struct node *next;// next pointer
    int data; //reg_no
    char name[30]; //name
};  
struct node *head;  
void insert_begin();  
void insert_last();  
void insert_pos();  
void delete_begin();  
void delete_last();  
void delete_pos();  
void traverse();  
void find();

int main ()  
{  
int choice =0;  
    while(choice != 9)  
    {  
        printf("\nChoose one option from the following list ...\n");  
        printf("\n1.Insert in begining\n2.Insert at last\n3.Insert at any random position\n4.Delete from Beginning\n");
        printf("5.Delete from last\n6.Delete the node after the given data\n7.Find\n8.Traverse\n9.Exit\n");  
        printf("\nEnter your choice?\n");  
        scanf("\n%d",&choice);  
        switch(choice)  
        {  
            case 1:  
            insert_begin();  
            break;  
            case 2:  
                    insert_last();  
            break;  
            case 3:  
            insert_pos();  
            break;  
            case 4:  
            delete_begin();  
            break;  
            case 5:  
            delete_last();  
            break;  
            case 6:  
            delete_pos();  
            break;  
            case 7:  
            find();  
            break;  
            case 8:  
            traverse();  
            break;  
            case 9:  
            exit(0);  
            break;  
            default:  
            printf("Please enter valid choice..");  
        }  
    }
    return 0;
}  
//inserting at the beginning
void insert_begin()  
{  
   struct node *ptr;   
   int Reg_no;  
   ptr = (struct node *)malloc(sizeof(struct node));  
   if(ptr == NULL)  
   {  
       printf("\nList Full");  
   }  
   else  
   {  
    printf("\nEnter Reg_no: ");  
    scanf("%d",&Reg_no);  
      
   if(head==NULL)  
   {  
       ptr->next = NULL;  
       ptr->prev=NULL;  
       ptr->data=Reg_no;  
       head=ptr;  
   }  
   else   
   {  
       ptr->data=Reg_no;  
       ptr->prev=NULL;  
       ptr->next = head;  
       head->prev=ptr;  
       head=ptr;  
   }  
   printf("\nNode inserted\n");  
}  
     
}  
//inserting at the last
void insert_last()  
{  
   struct node *ptr,*temp;  
   int Reg_no;  
   ptr = (struct node *) malloc(sizeof(struct node));  
   if(ptr == NULL)  
   {  
       printf("\nList Full");  
   }  
   else  
   {  
       printf("\nEnter reg_no: ");  
       scanf("%d",&Reg_no);  
        ptr->data=Reg_no;  
       if(head == NULL)  
       {  
           ptr->next = NULL;  
           ptr->prev = NULL;  
           head = ptr;  
       }  
       else  
       {  
          temp = head;  
          while(temp->next!=NULL)  
          {  
              temp = temp->next;  
          }  
          temp->next = ptr;  
          ptr ->prev=temp;  
          ptr->next = NULL;  
          }  
             
       }  
     printf("\nnode inserted\n");  
    }  

//inserting at the position
void insert_pos()  
{  
   struct node *ptr,*temp;  
   int Reg_no,loc,i;  
   ptr = (struct node *)malloc(sizeof(struct node));  
   if(ptr == NULL)  
   {  
       printf("\n List Full");  
   }  
   else  
   {  
       temp=head;  
       printf("Enter the position");  
       scanf("%d",&loc);  
       for(i=0;i<loc;i++)  
       {  
           temp = temp->next;  
           if(temp == NULL)  
           {  
               printf("\n There are less than %d elements", loc);  
               return;  
           }  
       }  
       printf("Enter reg_no: ");  
       scanf("%d",&Reg_no);  
       ptr->data = Reg_no;  
       ptr->next = temp->next;  
       ptr -> prev = temp;  
       temp->next = ptr;  
       temp->next->prev=ptr;  
       printf("\nnode inserted\n");  
   }  
}  

//Delete from beginning
void delete_begin()  
{  
    struct node *ptr;  
    if(head == NULL)  
    {  
        printf("\n Null list");  
    }  
    else if(head->next == NULL)  
    {  
        head = NULL;   
        free(head);  
        printf("\nnode deleted\n");  
    }  
    else  
    {  
        ptr = head;  
        head = head -> next;  
        head -> prev = NULL;  
        free(ptr);  
        printf("\nnode deleted\n");  
    }  
  
}  

//Delete from last
void delete_last()  
{  
    struct node *ptr;  
    if(head == NULL)  
    {  
        printf("\n Null list");  
    }  
    else if(head->next == NULL)  
    {  
        head = NULL;   
        free(head);   
        printf("\nnode deleted\n");  
    }  
    else   
    {  
        ptr = head;   
        if(ptr->next != NULL)  
        {  
            ptr = ptr -> next;   
        }  
        ptr -> prev -> next = NULL;   
        free(ptr);  
        printf("\nnode deleted\n");  
    }  
}  

////Delete from position
void delete_pos()  
{  
    struct node *ptr, *temp;  
    int val;  
    printf("\n Enter the position after which the node is to be deleted : ");  
    scanf("%d", &val);  
    ptr = head;  
    while(ptr -> data != val)  
    ptr = ptr -> next;  
    if(ptr -> next == NULL)  
    {  
        printf("\nCan't delete\n");  
    }  
    else if(ptr -> next -> next == NULL)  
    {  
        ptr ->next = NULL;  
    }  
    else  
    {   
        temp = ptr -> next;  
        ptr -> next = temp -> next;  
        temp -> next -> prev = ptr;  
        free(temp);  
        printf("\nnode deleted\n");  
    }     
}  

//traversing values
void traverse()  
{  
    struct node *ptr;    
    ptr = head;  
    while(ptr != NULL)  
    {  
        printf("%d ",ptr->data);  
        ptr=ptr->next;  
    }  
}   

// searching values
void find()  
{  
    struct node *ptr;  
    int Reg_no,i=0,flag;  
    ptr = head;   
    if(ptr == NULL)  
    {  
        printf("\nEmpty List\n");  
    }  
    else  
    {   
        printf("\nEnter Reg_no which you want to find?\n");   
        scanf("%d",&Reg_no);  
        while (ptr!=NULL)  
        {  
            if(ptr->data == Reg_no)  
            {  
                printf("\nitem found at position %d ",i+1);  
                flag=0;  
                break;  
            }   
            else  
            {  
                flag=1;  
            }  
            i++;  
            ptr = ptr -> next;  
        }  
        if(flag==1)  
        {  
            printf("\nItem not found\n");  
        }  
    }     
          
}  

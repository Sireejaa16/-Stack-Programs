#include<stdio.h>
#include<stdlib.h>


struct Node
{
        int data;
        struct Node *next;
};
typedef struct Node node;

node *getNode()
{
         int ele;
         node *newnode;
         newnode=(node*)malloc(sizeof(node));
         printf("Enter the data to be stored in the newnode\n");
         scanf("%d",&ele);
         newnode->data=ele;
         newnode->next=NULL;
         return newnode;
}

node *head=NULL;
void DisplayList()
{
        if(head==NULL)
		printf("Empty Stack");
        else{
        	node *temp;
        	temp=head;
        	while(temp!=NULL)
        	{
                	printf("%d \n",temp->data);
                	temp=temp->next;
        	}
        	free (temp);
        }
}
void InsertNodeFront()                                             //Inserting the elements of the stack
{
         node *newnode=getNode();
	 newnode->next=head;
         head=newnode;
}

void DeleteNodeFront()                                              //Popping of elements of stack
{
        if(head==NULL)
        printf("Empty stack\n");
        else{
        node *temp;
        temp=head;
        head=head->next;
        free (temp);
        }
}


int main()
{
     printf("Enter the elements of the  stack and then enter 4\n");
     int choice=0;
     while(choice!=4)
      {
        printf("\nEnter choice\n");
        printf("Enter 1 to push an element to the stack \n");
        printf("Enter 2 to pop an element from the stack \n");
        printf("Enter 3 to display the stack \n");
        printf("Enter 4 to complete entering the stack\n");
  

	 scanf("%d",&choice);
        switch(choice)
        {
                 case 1:
                        {
                                InsertNodeFront();
                                DisplayList();
                                break;
                        }
                 case 2:
                        {
                                DeleteNodeFront();
                                DisplayList();
                                break;
                        }
                 
                 case 3:
                        {
                                DisplayList();
                                break;
                        }
		 case 4:break;	
                
                default:
                        {
                                printf("EXIT");
                                break;
                        }

        }
     }
    return 0;
}




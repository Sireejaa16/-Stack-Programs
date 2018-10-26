#include<stdio.h>
#define STACKSIZE 10
int stack[STACKSIZE];
int top=-1;

void push(int ele)
{
 if(top==STACKSIZE-1)
 {
  printf("Stack overflow");
  return;
 }
 else
 {
 top++;
 stack[top]=ele;
 }
}


int pop()
{
 if(top==-1)
 {
  printf("Stack underflow");
  return ;
 }
 else
 {
 return stack[top--];
 }
}

void display()

{
 for(int i=top;i>=0;i--)
  {
  printf("%d\n",stack[i]);
  }
}

int isEmpty()
{
 if(top==-1)
	 return 1;
 else
	 return 0;
}

int isFull()
{
	if(top==STACKSIZE-1)
                return 1;
	else 
		return 0;

}

int main()
{
   int ch,n;
   while(ch!=6)
  {	   
   printf("Enter 1 for push\n");
   printf("Enter 2 for pop\n");
   printf("Enter 3 for finding if the stack is empty\n");
   printf("Enter 4 for finding if the stack is full\n");
   printf("Enter 5 for displaying all the elements of the stack\n");
   printf("Enter 6 for exit\n");
   scanf("%d",&ch);
   switch(ch)
   {
	   case 1:{
		  printf("Enter the elemet to be pushed into the stack\n");
		  scanf("%d",&n);
		  push(n);
		 break;
		  }
	   case 2:{
		printf("The element popped is %d",pop());
                 break;
                 }
            case 3:{
	           if(isEmpty()==1)
			   printf("The stack is empty\n");
                   else
	                   printf("The stack is not empty\n");
                   break;
                   }
            case 4:{
                   if(isFull()==1)
                           printf("The stack is full\n");                 
                   else
                           printf("The stack is not full\n");             
                   break;
                   }
	   case 5:{
	       display();
                 break;
		  }
           case 6: break;
          default :{ 
	          printf("Invalid choice");
                  break;
		   }
   }
  }   

		   

}


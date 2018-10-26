#include<stdio.h> 
#include<stdlib.h> 
#define bool int 

struct Node 
{ 
char data; 
struct Node *next; 
}; 
typedef struct Node node;
 

/* Returns 1 if character1 and character2 are matching left 
and right Parenthesis */
bool Pair(char character1, char character2) 
{ 
if (character1 == '(' && character2 == ')') 
	return 1; 
else if (character1 == '{' && character2 == '}') 
	return 1; 
else if (character1 == '[' && character2 == ']') 
	return 1; 
else
	return 0; 
} 

/*Return 1 if expression has balanced Parenthesis */
bool check(char exp[]) 
{ 
int i = 0; 

/* Declare an empty character stack */
node *stack = NULL; 

/* Traverse the given expression to check matching parenthesis */
while (exp[i]) 
{ 
	/*If the exp[i] is a starting parenthesis then push it*/
	if (exp[i] == '{' || exp[i] == '(' || exp[i] == '[') 
		push(&stack, exp[i]); 

	/* If exp[i] is an ending parenthesis then pop from stack and 
		check if the popped parenthesis is a matching pair*/
	if (exp[i] == '}' || exp[i] == ')' || exp[i] == ']') 
	{ 
			
		/*If we see an ending parenthesis without a pair then return false*/
		if (stack == NULL) 
		return 0; 

		/* Pop the top element from stack, if it is not a pair 
			parenthesis of character then there is a mismatch. 
			This happens for expressions like {(}) */
		else if (Pair(pop(&stack), exp[i]) ) 
		return 1; 
	} 
	i++; 
} 
	
/* If there is something left in expression then there is a starting 
	parenthesis without a closing parenthesis */
if (stack == NULL) 
	return 1; /*balanced*/
else
	return 0; /*not balanced*/
} 

/* UTILITY FUNCTIONS */
/*driver program to test above functions*/
int main() 
{
        int num;
      	printf("Enter the total number of characters present in the expression\n ");
        scanf("%d",&num);
	char *exp=(char*)calloc(++num,sizeof(char));                                    // just num doesnot take the entire expression ,it inputs 1 character less....why?
	printf("Enter the expression\n");
	for(int i=0;i<num;i++)
	{
	 scanf("%c",(exp+i));
	}
	printf("The entered expression is :\n");
	for(int j=0;j<num;j++)
	{printf("%c",*(exp+j));}
//char exp[100] = "{()}[]("; 
if (check(exp)) 
	printf("Balanced \n"); 
else
	printf("Not Balanced \n"); 
return 0; 
}	 

/* Function to push an item to stack*/
void push(node** top_ref, int new_data) 
{ 
/* allocate node */
node* new_node = ( node*) malloc(sizeof(node)); 
/* put in the data */
new_node->data = new_data; 

/* link the old list off the new node */
new_node->next = (*top_ref); 

/* move the head to point to the new node */
(*top_ref) = new_node; 
} 

/* Function to pop an item from stack*/
int pop(node** top_ref) 
{ 
char res; 
node *top; 

/*If stack is empty then error */
if (*top_ref == NULL) 
{ 
	printf("Stack overflow n"); 
//etchar(); 
//xit(0); 
} 
else
{ 
	top = *top_ref; 
	res = top->data; 
	*top_ref = top->next; 
	free(top); 
	return res; 
} 
} 


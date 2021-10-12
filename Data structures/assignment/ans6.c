#include<stdio.h>
#include <string.h>

char infix[100],postfix[100];

int top,stack[100],pop();

int precedence(char symbol)
{    if(symbol == '(')
     	return 0;
	else if(symbol == '+'|| symbol == '-')
		return 1;
	else if(symbol == '*' || symbol == '/' || symbol == '%')
		return 2;
	else if(symbol == '^')
		return 3;
	else
		return 0;	 
}

int is_Empty()
{if(top == -1)
  return 1;

 return 0;
}

int pop()
{
 return(stack[top--]);  
}

void push(int temp)
{ top=top + 1;
  stack[top] = temp;    
}


int check_space(char symbol)
{ if(symbol == '\t' || symbol == ' ' )
   {
     return 1;
}
 return 0;
}

void infix_to_postfix()
{   int count, temp = 0;
    char next;
	char symbol;

    for(count = 0; count <= (strlen(infix)-1); count++)
	{
	symbol = infix[count];  
	if(!check_space(symbol))
	{
	switch(symbol)
	{
	case '(': push(symbol);
			  break;
    case ')':
			  while((next = pop()) != '(')    
  			  {
    			postfix[temp++] = next;
			  }
			  break;
	case '+':
	case '-':
	case '*':
	case '/':
	case '%':
	case '^':
			   while(!is_Empty() && precedence(stack[top]) >= precedence(symbol))   
                        postfix[temp++] = pop();
               push(symbol);
			   break;
	default:
			   postfix[temp++] = symbol;
			}
		}
	}
while(!is_Empty())
{ postfix[temp++] = pop();
}
postfix[temp] = '\0';
}

int main()
{
int count, length;
char temp;
top = -1;
printf("\nInfix expression: ");
scanf("%s", infix);
infix_to_postfix();
printf("\nPostfix Expression: %s\n", postfix);


    return 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 1000

int CheckPara(char String[N], int len)
{
    char Stack[N] = {0};
    int top = -1;
    for(int i = 0; i < len; i++) {
        
        if(String[i] == '{' || String[i] == '[' || String[i] == '(') {
            Stack[++top] = String[i];
        }
        if(String[i] == ']') {
            if(Stack[top] != '[') {
                return 0;
            }
            top--;
        }
        if(String[i] == '}') {
            if(Stack[top] != '{') {
                return 0;
            }
            top--;
        }
        if(String[i] == ')') {
            if(Stack[top] != '(') {
                return 0;
            }
            top--;
        }
    }
    if(top < 0)
        return 1;
    else
        return 0;
}
int main()
{
    char String[N];
    int result = 0;
    printf("Enter the expression : ");
    scanf(" %s", String);
    result = CheckPara(String, strlen(String));
    if(result) {
        printf("Braces are balanced \n");
    } else {
        printf("Braces are not balanced \n");
    }
}
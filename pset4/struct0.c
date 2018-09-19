#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    int a,*pi;
    printf("s: ");
    char* s=get_string();
    printf("t: ");
    char* t=get_string();
    
    
    pi=&a;
    a=20;
    
    
    if(s != NULL && t != NULL){
        if(strcmp(s,t)==0){
            printf("same\n");
        }
        else{
            printf("different\n");
        }
    }
    
    printf("pi is %p an the value of p is %d\n",pi,*pi);
}
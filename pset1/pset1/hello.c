#include <stdio.h>
#include<string.h>
#include <cs50.h>

int main(void)
{   
    string se = get_string("what is your name :\n");
    printf("hello, %s\n", se);
}
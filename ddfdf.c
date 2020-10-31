#include<stdio.h>
#include<stdlib.h>

int main(int argc, char const *argv[])
{
    /* code */
    int a;
    int *p = (int*) malloc(sizeof(int) * 10);
    *p = 6;
    *(p+1)=4;
    *(p+2)=5;
    


    return 0;
}

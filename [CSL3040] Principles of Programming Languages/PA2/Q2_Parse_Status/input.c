#include<stdio.h>
#include<string.h>

int main() {
    int a;
    int x=1;
    int y=2;
    int z=3;
    int k;
    x=3;
    y=10;
    z=5;

    do
    {
        printf("do while test");
    } while (z--);
    

    while(x--){
        z++;
        printf("While Test");
    }

    switch (z+x<10)
    {
    case 1:
        x++;
        break;
    case 2:
        printf("switch case test");
    default:
        break;
    }
    
    return 1;
}
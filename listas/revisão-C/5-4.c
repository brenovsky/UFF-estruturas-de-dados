#include <stdio.h>
#include <stdlib.h>

int calcula(int x)
{
    int i;
    if ((x=x*2)>5) return(x+3);
    for(i=0;i<10;i++)
    {
        if (i<5) continue;
        if (x>8) break;
        x+=2;
    }
    return(x);
}

void main()
{

    int a,b,c;
    char d;
    a=1;b=2;c=3;d='A';
    a+=b*c;
    d=(a>7)?d-1:d+1;
    b = calcula(b);
    c = calcula(calcula(a));
    a = c++;
    printf("%d - %d - %d - %c\n",a,b,c,d);
}

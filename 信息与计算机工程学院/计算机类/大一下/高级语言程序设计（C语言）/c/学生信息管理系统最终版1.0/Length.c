#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"


int Length (node *phead)
{
    if(phead==NULL) return 0;
    node *p=phead->next;
    int n;
    while(p!=NULL)
    {
        n++;
        p=p->next;
    }
    return n;
}

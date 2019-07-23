#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"



void Output (node *p)
{
    printf("%d ", p->num);
    printf("%s ", p->name);
    printf("%c ", p->sex);
    printf("%lf ", p->math_score);
    printf("%lf ", p->english_score);
    printf("%lf ", p->chinese_score);
    printf("%lf ",p->ave_score);
    printf("%lf ",p->sum_score);
    printf("%d\n", p->rank);
}

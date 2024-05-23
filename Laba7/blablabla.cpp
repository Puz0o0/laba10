// blablabla.cpp: определяет точку входа для консольного приложения.
//


#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "StdAfx.h"
int main() {


    int a, b, c, d, e, y;
    puts("Введите значения для: a, b, c, d, e: ");
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &e);
    //(b<c)or(d<=e)

    __asm {
        push eax;
        push ebx;

        mov eax, b;
        cmp eax, c;
        jl y1; // b < c

        mov eax, d;
        cmp eax, e;
        jle y1; // d<=e

        //y2 = (a + b + c) / d * e

        mov eax, a;
        add eax, b;
        add eax, c;
        cdq;
        idiv d;
        imul eax, e;
        mov y, eax;
        jmp end;

    y1:    //y1=a-b+c/d*e
        mov eax, c;
        cdq;
        idiv d;
        imul eax, e;
        add eax, a;
        sub eax, b;
        mov y, eax;
        jmp end;
    end:
        pop ebx;
        pop eax;
    }
    printf("y = %d", y);
    printf("\nf1 = %d\n", (a - b + c / d * e));
    printf("f2 = %d", ((a + b + c) / d * e)); //Перенесли строку с объевлением перерменной

    return 0;
}


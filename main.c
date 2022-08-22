/**
@file main.c
@author Хоменко К., гр. 515-в
@date 21 серпня 2022р.
@brief Навчальна практика.
*/
#include <stdio.h>

int main()
{
    int num;
    printf("Введіть число: ");
    scanf("%i", &num);

    printf("\nРезультат: %s\n\n", GetNumberName(num));

    return 0;
}

/*
** EPITECH PROJECT, 2020
** InfinAdd
** File description:
** infinite addition
*/
#include <unistd.h>
#include <stdlib.h>
#include "libmy.h"

int my_strlen (char const *str);
int my_putchar(char c);

char *check_string(char *str_one, char *str_two)
{
    int i = 0;
    int j = 0;
    int k = 0;

    if (my_strlen(str_one) < my_strlen(str_two))
        return (str_one);
    else if (my_strlen(str_one) > my_strlen(str_two))
        return (str_two);
    else
        if (str_one[1] > str_two[1])
            return(str_one);
        else if (str_one[1] < str_two[1])
            return(str_two);
}
char *int_to_end(char *str_one, char *str_two)
{
    int i = 0;
    int j = 0;
    int k = 0;

    while (str_one[i] || str_two[j]) {
        k++;
    }
    while (str_one[i]) {
            i++;
    }
    while (str_two[j]) {
            j++;
    }
}

char *calcul(char *str_one, char *str_two)
{
    int i;
    int j;
    int k;
    char *dest = malloc(sizeof(char*) * (my_strlen(check_string(str_one, str_two))) + 1);

    int_to_end(str_one, str_two);
    while (dest[k]) {
        if (str_one[i] >= '5'|| str_two[j] >= '5') {
            dest[k] += (str_one[i] + str_two[j]);
            if (dest[k] > '9') {
                dest[k - 1] += 1;
            }
            dest[k] = - 58;
        }
        else {
            dest[k] = (str_one[i] + str_two[j]);
            if (dest[k] > '9') {
                dest[k - 1] += 1;
            }
            dest[k] = - 48;
        }
        my_putchar(dest[k]);
        i--;
        j--;
        k--;
    }
    return(dest);
}

void my_sub_string_negative(char *str_one, char *str_two)
{
    int i;
    int j;
    int k;
    char *dest;

    if (str_one[1] > str_two[1]) {
        dest[k] += (str_one[i] + str_two[j]);
        if (dest[k] < '0') {
            dest[k - 1] -= 1;
        }
        dest[k] += 48;
    }
    else
        dest[k] += (str_two[j] + str_one[i]);
    if (dest[k] < '0') {
        dest[k - 1] -= 1;
    }
    dest[k] += 48;
}

void my_strings_negative(char *str_one, char *str_two)
{
    int i;
    int j;
    int k;
    char *dest;

    if (my_strlen(str_one) < my_strlen(str_two)) {
        dest[k] += (str_two[j] + str_one[i]);
        if (dest[k] < '0') {
            dest[k - 1] -= 1;
        }
        dest[k] += 48;
    }
    else if (my_strlen(str_one) > my_strlen(str_two)) {
        dest[k] += (str_one[i] + str_two[j]);
        if (dest[k] < '0') {
            dest[k - 1] -= 1;
        }
        dest[k] += 48;
    }
    else {
        my_sub_string_negative(str_one, str_two);
    }
}

void first_string_priority(char *str_one, char *str_two)
{
    int i;
    int j;
    int k;
    char *dest;

    if (str_one[0] == '-' && str_two[0] != '-') {
        dest[k] += (str_two[j] - str_one[i]);
        if (dest[k] < '0') {
            dest[k - 1] -= 1;
        }
        dest[k] += 48;
    }
    else if (str_one[0] != '-' && str_two[0] == '-') {
        dest[k] += (str_one[i] - str_two[j]);
        if (dest[k] < '0') {
            dest[k - 1] -= 1;
        }
        dest[k] += 48;
    }
    else  if (str_one[0] == '-' && str_two[0] == '-') {
        my_strings_negative(str_one, str_two);
    }
}

char *calcul_negative(char *str_one, char *str_two)
{
    int i;
    int j;
    int k;
    char *dest = malloc(sizeof(char*) * (my_strlen(check_string(str_one, str_two))) + 1);

    int_to_end(str_one, str_two);
    while (k >= 0) {
        if (dest[k] < '0') {
            first_string_priority(str_one, str_two);
        }
        else {
            first_string_priority(str_one, str_two);
        }
        my_putchar(dest[k]);
        i--;
        j--;
        k--;
    }
    dest[0] = '-';
    return (dest);
}

char *infinadd(char const *str_one, char const *str_two)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char *dest;

    if (str_one[i] == '-' || str_two[i] == '-') {
        calcul_negative(char *str_one, char *str_two);
        return (dest);
    }
    else {
        calcul(char *str_one, char *str_two);
    }
}

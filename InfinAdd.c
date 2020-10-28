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

char *calcul(char *str_one, char *str_two, char *dest)
{
   int i = my_strlen(str_one);
    int j = my_strlen(str_two);
    int k = my_strlen(check_string(str_one, str_two));
    dest = malloc(sizeof(char*) * (my_strlen(check_string(str_one, str_two))) + 1);

    while (k != 0) {
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
}

void my_sub_string_negative(char *str_one, char *str_two, char *dest)
{
    int i = my_strlen(str_one);
    int j = my_strlen(str_two);
    int k = my_strlen(check_string(str_one, str_two));

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

void my_strings_negative(char *str_one, char *str_two, char *dest)
{
    int i = my_strlen(str_one);
    int j = my_strlen(str_two);
    int k = my_strlen(check_string(str_one, str_two));

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
        my_sub_string_negative(str_one, str_two, dest);
    }
}

void first_string_priority(char *str_one, char *str_two, char *dest)
{
    int i = my_strlen(str_one);
    int j = my_strlen(str_two);
    int k = my_strlen(check_string(str_one, str_two));

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
        my_strings_negative(str_one, str_two, dest);
    }
}

char *calcul_negative(char *str_one, char *str_two, char *dest)
{
    int i = my_strlen(str_one);
    int j = my_strlen(str_two);
    int k = my_strlen(check_string(str_one, str_two));
    dest = malloc(sizeof(char*) * (my_strlen(check_string(str_one, str_two))) + 1);

    while (k >= 0) {
        if (dest[k] < '0') {
            first_string_priority(str_one, str_two, dest);
        }
        else {
            first_string_priority(str_one, str_two, dest);
        }
        my_putchar(dest[k]);
        i--;
        j--;
        k--;
    }
    dest[0] = '-';
}

char *infinadd(char *str_one, char *str_two, char *dest)
{
    int i = 0;
    int j = 0;
    int k = 0;
    dest = malloc(sizeof(char*) * (my_strlen(check_string(str_one, str_two))) + 1);

    if (str_one[i] == '-' || str_two[i] == '-') {
        dest = calcul_negative(str_one, str_two, dest);
    }
    else {
        dest = calcul(str_one, str_two, dest);
    }
    return (dest);
}

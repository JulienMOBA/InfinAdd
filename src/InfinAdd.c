/*
** EPITECH PROJECT, 2020
** InfinAdd
** File description:
** infinite addition
*/

int my_strlen (char const *str);

char calcul(char *str_one, char *str_two)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char *dest malloc(sizeof (char) * (my_strlen(str_one) + my_strlen(str_two)));

    check_string(str_one, str_two);

    while (dest[k]) {
        if (str_one[i] >= '5'|| str_two[j] >= '5') {
            dest[k] += (str_one[i] + str_two[j]) - 58;
        }
        else {
            dest[k] = (str_one[i] + str_two[j]) - 48;
        }
        if (dest[k] > '9') {
            dest[k - 1] += 1;
        }
        i--;
        j--;
        k--;
    }
}

void first_string_priority(char *str_one, char *str_two)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char *dest;

    if (str_one[0] == '-' && str_two[0] != '-') {
        dest[k] += (str_two[j] - str_one[i]) + 48;
    }
    else if (str_one[0] != '-' && str_two[0] == '-') {
        dest[k] += (str_one[i] - str_two[j]) + 48;
    }
    else  if (str_one[0] == '-' && str_two[0] == '-') {
        my_strings_negative(str_one, str_two);
    }
}

void my_strings_negative(char *str_one, char *str_two)
{
    int i;
    int j;
    int k;
    char *dest;

    if (my_strlen(str_one) < my_strlen(str_two)) {
        dest[k] += (str_two[j] + str_one[i]) + 48;
    }
    else if (my_strlen(str_one) > my_strlen(str_two)) {
        dest[k] += (str_one[i] + str_two[j]) + 48;
    }
    else {
        if (str_one[1] > str_two[1])
            dest[k] += (str_one[i] + str_two[j]) + 48;
        else
            dest[k] += (str_two[j] + str_one[i]) + 48;
    }
}

char calcul_negative(char *str_one, char *str_two)
{
    int i;
    int j;
    int k;
    char *dest malloc(sizeof (char) * (my_strlen(str_one) + my_strlen(str_two)));

    check_string(str_one, str_two);
    while (k >= 0) {
        first_string_priority(str_one, str_two);
        if (dest[k] < '0') {
            dest[k - 1] -= 1;
        }
        else {
            first_string_priority(str_one, str_two);
        }
        i--;
        j--;
        k--;
    }
}


void check_string(char *str_one, char *str_two)
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
    if (j > i && str_two[0] == '-'|| i > j && str_one[0] == '-') {
        dest[0] = '-';
    }

}


char *infinadd(char *str_one, char *str_two)
{
    check_string(str_one, str_two);

    if (str_one)
}

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
    
    while (str_one[i] && str_two[j]) {
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
char calcul_negative(char *str_one, char *str_two)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char *dest malloc(sizeof (char) * (my_strlen(str_one) + my_strlen(str_two)));

    check_string(str_one, str_two);

    while (str_one[i] || str_two[j]) {
        dest[k] = (str_one[i] + str_two[j]) - 48;
        if (dest[k] > '9') {
            dest[k] = dest[k] - 58;
            dest[k - 1] += 1;
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

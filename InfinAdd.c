/*
** EPITECH PROJECT, 2020
** InfinAdd
** File description:
** infinite addition
*/

int my_strlen (char const *str);
void integer_count(char *str_one, char const *str_two)
{
    int i;
    int j;

    while (str_one[i] || str_two[j]) {
        k++;
    }
    while (i < my_strlen(str_one) - 1) {
        i++;
    }
    while (j < my_strlen(str_two) - 1) {
        j++;
    }
}

char calcul(char *str_one, char *str_two)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char *dest malloc(sizeof (char) * (my_strlen(str_one) + my_strlen(str_two)));

    integer_count(str_one, str_two);
    
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

void check_string(char *str_one, char *str_two) {
    int h = 0;
    int l = 0;

    while (str_one[h]) {
        if (str_one[0] == '-' || str_one[h] >= '0' && str_one[h] <= '9')
            h++;
    }
    while (str_two[l]) {
        if (str_two[0] == '-' || str_two[l] >= '0' && str_two[l] <= '9')
            l++;
    }
}


char *infinadd(char *str_one, char *str_two)
{
    
}

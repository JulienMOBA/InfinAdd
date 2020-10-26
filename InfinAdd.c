/*
** EPITECH PROJECT, 2020
** InfinAdd
** File description:
** infinite addition
*/

int my_strlen (char const *str)

char *infinadd(char *str_one, char *str_two)
{
    int i = 0;
    int j = 0;
                                        
        while(str_one[i] ||str_two[j]) {
        if (str_one[0] == '-' || str_one[i] >= '0' && str_one[i] <= '9')
            i++;
        if (str_two[0] == '-' || str_two[j] >= '0' && str_two[j] <= '9')
            j++;
        
    }
}

char calcul(char *str_one, char *str_two)
{
    int i = 0;
    int j = 0;
    int k = 0;
    char *dest malloc(sizeof (char) * (my_strlen(str_one) + my_strlen(str_two)));

    while (str_one[i] || str_two[j]) {
        while (str_one[i] != my_strlen(str_one) - 1 && str_two[j] != my_strlen(str_two) - 1) {
            i++;
            j++;
            k++;
        }
        dest = (str_one[i] + str_two[j]) - 48;
        if (dest[k] > '9'){
            dest[k] = dest[k] - 58;
            str_one[i - 1] += 1;
        }
        i--;
        j--;
        k--;
    }
}

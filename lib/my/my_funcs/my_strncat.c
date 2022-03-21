/*
** EPITECH PROJECT, 2021
** my_strncat
** File description:
** my_strncat
*/

int my_strlen(char *str);

char *my_strncat(char *dest, char const *str, int n)
{
    int end_line = my_strlen(dest);

    for (int i = 0; str[i] != '\0' && i < n; i++)
        dest[end_line + i] = str[i];
    end_line = my_strlen(dest) - 1;
    dest[end_line] = '\0';
    return (dest);
}

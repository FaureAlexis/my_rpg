/*
** EPITECH PROJECT, 2021
** return_index
** File description:
** return_index
*/

int return_index(char c, char const *str)
{
    for (int i = 0; str[i] != '\0'; i++) {
        if (c == str[i])
            return i;
    }
    return -1;
}

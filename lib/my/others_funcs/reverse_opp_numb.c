/*
** EPITECH PROJECT, 2021
** reverse_opp_numb*
** File description:
** reverse_opp_numb
*/

void my_swap(int *a, int *b);

void reverse_opp_numb(char *c, char *d)
{
    int e = *c;
    int f = *d;

    my_swap(&e, &f);
    *c = e;
    *d = f;
}

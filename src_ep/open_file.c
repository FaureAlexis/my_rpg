/*
** EPITECH PROJECT, 2021
** open_file
** File description:
** buff
*/

#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <sys/stat.h>

char *open_file(char const *filepath)
{
    struct stat info;
    if (stat(filepath, &info) == -1)
            return NULL;
    int fd = open(filepath, O_RDONLY);
    int size = 0;
    char *buff = NULL;

    size = info.st_size;
    if (size == 0)
        return NULL;
    buff = malloc(sizeof(char) * (size + 1));
    read(fd, buff, size);
    if (!buff)
        return NULL;
    buff[size] = '\0';
    return buff;
}

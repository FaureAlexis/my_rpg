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
    int fd = 0;
    int size = 0;
    char *buff = NULL;

    if (!filepath)
        return NULL;
    fd = open(filepath, O_RDONLY);
    if (fd == -1 || stat(filepath, &info) == -1)
        return NULL;
    size = info.st_size;
    buff = malloc(sizeof(char) * (size + 1));
    if (size == 0 || !buff)
        return NULL;
    read(fd, buff, size);
    if (!buff)
        return NULL;
    buff[size] = '\0';
    close(fd);
    return buff;
}

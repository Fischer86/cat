#include <unistd.h>
#include <fcntl.h>

void    ft_putchar(char c)
{
    write(1, &c, 1);
}

void    ft_putstr(char *str)
{
    int     i = 0;
    while (str[i])
    {
        ft_putchar(str[i]);
        i++;
    }
}

int     main(int argc, char **argv)
{
    int     fd;
    char    buffer[4096];
    ssize_t bytes_read;

    if (argc != 2)
        return(1);

    fd = open(argv[1], O_RDONLY);

    if (fd == -1)
        return(0);

    while ((bytes_read = read(fd, buffer, sizeof(buffer))) > 0)
        write(1, buffer, bytes_read);

    close(fd);
    return(0);
}
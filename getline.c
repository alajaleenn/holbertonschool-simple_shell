#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

#define BUFFER_SIZE 1024

/**
 * _getline - custom getline function that reads from stdin
 * Return: pointer to line read, or NULL on EOF
 */
char *_getline(void)
{
    static char buffer[BUFFER_SIZE];
    static ssize_t buf_len = 0;
    static ssize_t buf_pos = 0;
    char *line = NULL;
    size_t line_size = 0;
    char c;

    while (1)
    {
        if (buf_pos >= buf_len)
        {
            buf_len = read(STDIN_FILENO, buffer, BUFFER_SIZE);
            if (buf_len <= 0)
            {
                if (line_size == 0)
                    return (NULL);
                break;
            }
            buf_pos = 0;
        }

        c = buffer[buf_pos++];

        line = realloc(line, line_size + 2);
        if (!line)
            return (NULL);

        line[line_size++] = c;

        if (c == '\n')
            break;
    }

    line[line_size] = '\0';
    return (line);
}

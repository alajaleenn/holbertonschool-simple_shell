#include "main.h"
#include <unistd.h>
#include <stdlib.h>

#define BUFFER_SIZE 1024

/**
 * _getline - Custom getline function using static buffer
 * Return: pointer to line read, or NULL on EOF
 */
char *_getline(void)
{
    static char buffer[BUFFER_SIZE];
    static ssize_t buf_len = 0, buf_pos = 0;
    char *line = NULL;
    size_t line_size = 0;
    char c;

    while (1)
    {
        if (buf_pos >= buf_len)
        {
            buf_len = read(STDIN_FILENO, buffer, BUFFER_SIZE);
            if (buf_len <= 0)
                return (line_size ? line : NULL);
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

    /* Remove trailing newline if present */
    if (line_size > 0 && line[line_size - 1] == '\n')
        line[line_size - 1] = '\0';
    else
        line[line_size] = '\0';

    return line;
}

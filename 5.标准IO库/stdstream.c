#include <stdio.h>

void pr_stdio(const char *, FILE *);
int is_unbuffered(FILE *);
int is_linebuffered(FILE *);
int buffer_size(FILE *);

int main(int argc, char *argv[])
{
    FILE *fp;

    fputs("enter any character\n", stdout);
    if (getchar() == EOF)
        printf("getchar error\n");
    fputs("one line to standard error\n", stderr);

    pr_stdio("stdin", stdin);
    pr_stdio("stdout", stdout);
    pr_stdio("stderr", stderr);

    if ((fp = fopen("/etc/passwd", "r")) == NULL)
        printf("fopen error\n");
    if (getc(fp) == EOF)
        printf("getc error\n");

    pr_stdio("/etc/passwd", fp);

    return 0;
}


void pr_stdio(const char *name, FILE *fp)
{
    printf("stream = %s ,", name);

    if (is_unbuffered(fp))
        printf("unbuffered ,");
    else if (is_linebuffered(fp))
        printf("linebuffered ,");
    else
        printf("fully buffered ,");

    printf("buffer size = %d\n", buffer_size(fp));
}


/*
 * the following is nonportable
 */

int is_unbuffered(FILE *fp)
{
    return (fp->_flags & _IO_UNBUFFERED);
}

int is_linebuffered(FILE *fp)
{
    return (fp->_flags & _IO_LINE_BUF);
}

int buffer_size(FILE *fp)
{
    return (fp->_IO_buf_end - fp->_IO_buf_base);
}

/*
 * ./a.out < /etc/group > std.out 2> std.err
 */
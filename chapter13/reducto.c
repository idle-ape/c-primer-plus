/* reducto.c – 把文件压缩成原来的1/3! */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LEN 40

int main(int argc, char *argv[])
{
    FILE *in, *out;
    int ch;
    char name[LEN];
    int count = 0;

    if (argc < 2)
    {
        fprintf(stderr, "Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    if ((in = fopen(argv[1], "r")) == NULL)
    {
        fprintf(stderr, "I clouldn't open the file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    strncpy(name, argv[1], LEN - 5);
    name[LEN - 5] = '\0';
    strcat(name, ".red");

    if ((out = fopen(name, "w")) == NULL)
    {
        fprintf(stderr, "Can't create output file.\n");
        exit(EXIT_FAILURE);
    }

    char *head = "Generate by reducto.c!\n";
    fwrite(head, strlen(head), 1, out);

    // copy the data
    while ((ch = getc(in)) != EOF)
        if (count++%3 == 0)
            putc(ch, out);
    
    if (fclose(in) != 0 || fclose(out) != 0)
    {
        fprintf(stderr, "Error in closing files.\n");
        exit(EXIT_FAILURE);
    }

    return 0;
}
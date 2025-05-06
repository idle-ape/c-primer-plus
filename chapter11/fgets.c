#include <stdio.h>

#define STLEN 10

int main(void)
{
    char words[STLEN];
    puts("Enter strings(empty line to quit):");
    /*
        fgets()函数的第2个参数指明了读入字符的最大数量。如果该参数的值是n，那么fgets()将读入n-1个字符，或者读到遇到的第一个换行符为止。
        如果fgets()读到一个换行符，会把它储存在字符串中。这点与gets()不 同，gets()会丢弃换行符。

        fputs()函数返回指向 char 的指针。如果一切进行顺利，该函数返回的地址与传入的第 1 个参数相同。
        但是，如果函数读到文件结尾，它将返回一个特殊的指针:空指针(null pointer)。

        系统使用缓冲的I/O。这意味着用户在按下Return键之前，输入都被储存 在临时存储区(即，缓冲区)中。
        按下Return键就在输入中增加了一个换行 符，并把整行输入发送给fgets()。
        对于输出，fputs()把字符发送给另一个缓冲区，当发送换行符时，缓冲区中的内容被发送至屏幕上。
    */
    while (fgets(words, STLEN, stdin) != NULL && words[0] != '\n')
    {
        int i = 0;
        while (words[i] != '\n' && words[i] != '\0')
        {
            i++;
        }
        if (words[i] == '\n')
        {
            words[i] = '\0';
        }
        else
        {
            // 说明fgets()读取到了STLEN-1长度的字符，如果仍有字符串留在输入行怎么办?一个可行的办法是，
            // 如果目标数组装不下一整行输入，就丢弃那些多出的字符:
            while (getchar() != '\n')
            {
                continue;
            }
        }
        puts(words);
    }
    puts("Done.\n");
    return 0;
}
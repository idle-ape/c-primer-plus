#include <stdio.h>

#define STLEN 81

int main(void)
{
    /*
        chapter11/getsputs.c:9:5: warning: implicit declaration of function ‘gets’; did you mean ‘fgets’? [-Wimplicit-function-declaration]
          9 |     gets(words);
            |     ^~~~
            |     fgets
        /usr/bin/ld: /tmp/ccLMLkIx.o: in function `main':
        getsputs.c:(.text+0x37): warning: the `gets' function is dangerous and should not be used.

        编译会有warning，因为 gets() 函数不安全，它只接收了数组，但并不知道数组的长度，字符串的长度可能会超过数组长度，
        导致访问到尚未使用的内存。
    */
   
    char words[STLEN];
    puts("Enter a string please.");
    gets(words);
    printf("Your string twice:\n");
    printf("%s\n", words);
    puts(words);
    puts("Done.");

    // 如果fgets()读到一个换行符，会把它储存在字符串中。这点与gets()不 同，gets()会丢弃换行符。
    fgets(words, STLEN, stdin);
    puts(words);

    return 0;
}
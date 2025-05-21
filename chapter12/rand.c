/* rand.c -- 使用 ANSI C 可移植算法生成随机数 */

static unsigned long int next = 1; // seed

unsigned int rand(void)
{
    next = next * 1103515245 + 12345;
    return (unsigned int)(next / 65536) % 32768;
}
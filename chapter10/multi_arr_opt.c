#include <stdio.h>

int main(void)
{
    int zippo[4][2] = {
        {2, 4},
        {6, 8},
        {1, 3},
        {5, 7},
    };

    // 打印zippo数组的首个元素的地址，即 {2, 4} 这个元素的地址，zippo + 1 打印的是第二个元素即 {6, 8} 的地址
    // zippo + 1 的地址要比 zippo 的地址多2个int的大小，即8
    printf("zippo = %p, zippo + 1 = %p\n", zippo, zippo + 1); // zippo = 0x7ffc08e56a50, zippo + 1 = 0x7ffc08e56a58
    // 打印的是zippo数组首个元素的起始地址，即 2 这个元素的起始地址，zippo[0] + 1 打印的是 4 这个元素的地址
    // zippo[0] + 1 的地址要比 zippo[0] 的地址多1个int的大小，即4
    printf("zippo[0] = %p, zippo[0] + 1 = %p, zippo[0] = %d, zippo[0] + 1 = %d\n",
           zippo[0], zippo[0] + 1, *zippo[0], *(zippo[0] + 1)); // zippo[0] = 0x7ffc08e56a50, zippo[0] + 1 = 0x7ffc08e56a54, zippo[0] = 2, zippo[0] + 1 = 4
    // 打印的是zipp首个元素的地址，即 {2, 4} 这个元素的地址，以及 4 这个元素的地址。因为 *zippo 还是个指针
    printf("*zippo = %p, *zippo + 1 = %p, *zippo + 1 = %d\n", *zippo, *zippo + 1, *(*zippo + 1)); // *zippo = 0x7ffc08e56a50, *zippo + 1 = 0x7ffc08e56a54, *zippo + 1 = 4
    // zippo[0][0] = 2
    printf("zippo[0][0] = %d\n", zippo[0][0]);
    // *zippo[0] = 2
    printf("*zippo[0] = %d\n", *zippo[0]);
    // **zippo = 2
    printf("**zippo = %d\n", **zippo);
    // zippo[2][1] = 3
    printf("zippo[2][1] = %d\n", zippo[2][1]);

    /*
    zippo               <-二维数组首元素的地址(每个元素都是内含两个int类型元素的一维数组)
    zippo+2             <-二维数组的第3个元素(即一维数组)的地址
    *(zippo+2)          <-二维数组的第 3个元素(即一维数组)的首元素(一个int类型的值)地址
    *(zippo+2)+ 1       <-二维数组的第 3个元素(即一维数组)的第2个元素(也是一个int 类型的值)地址
    *(*(zippo+2)+ 1)    <-二维数组的第 3个一维数组元素的第2个int 类型元素的值，即数组的第3行第 2 列的值(zippo[2][1])
    */
    printf("*(*(zippo+2) + 1) = %d\n", *(*(zippo + 2) + 1)); // *(*(zippo+2) + 1) = 3，与 zippo[2][1]等价

    int (*pz)[2]; // pz指向一个内含两个int类型值的数组
    int *pax[2];  // pax是一个内含两个指针元素的数组，每个元素都指向int的指针，因为[]的优先级要高于*
    pz = zippo;

    return 0;
}
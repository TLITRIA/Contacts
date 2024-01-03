/**
 * name test01.c
 * function 测试简单程序控制 
 * 
 * 
 * 
*/
#include <stdio.h>

#include "common.h"

// printf("\t\t┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃\n");

int printInputMessage(void)
{
    // ┏ ┓ ┛ ┗ ┻ ┳ ━ ┃
    printf("\t┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("\t┃                                ┃\n");
    printf("\t┃      输入数字执行对应操作      ┃\n");
    printf("\t┃      0:结束程序                ┃\n");
    printf("\t┃                                ┃\n");
    printf("\t┃                                ┃\n");
    printf("\t┃                                ┃\n");
    printf("\t┃                                ┃\n");
    printf("\t┃                                ┃\n");
    printf("\t┃                                ┃\n");
    printf("\t┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    return ON_SUCCESS;
}





int main()
{
    
    int inputValue = 0;
    int status = 1;
    while (status > 0)
    {
        printf("输入数字执行对应操作\n");
        printf("0:退出程序\n");
        printf(">>>");
        scanf("%d", &inputValue);
        printf("输入数据：%d\n",inputValue);

        if (inputValue == 0)
        {
            printf("程序退出！\n");
            status = 0;
        }
        else
        {
            printf("非法输入！\n");
        }
    }
    return ON_SUCCESS;
}
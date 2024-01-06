/**
 * name test01.c
 * function 测试简单程序交互
 * 
 * 
 * 
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "common.h"

#define INPUT_SIZE 10
#define DEFAULT_INPUT_SIZE -1
// printf("\t\t┃━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┃\n");

enum COMMAND_CODE // 命令
{
    EXIT = 0,
    PRINT_CONTACTS,
    SEARCH_CONTACT,
    ADD_CONTACT,
    MODIFY_CONTACT,
    DELETE_CONTACT,
};

enum CONTACTS_STATUS_CODE
{
    QUIT = -1,
    NORMAL = 1,
};

int printMenu(void)
{
    // ┏ ┓ ┛ ┗ ┻ ┳ ━ ┃
    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃                                ┃\n");
    printf("┃      输入数字执行对应操作      ┃\n");
    printf("┃      0：结束程序               ┃\n");
    printf("┃      1：打印通讯录             ┃\n");
    printf("┃      2：查询联系人             ┃\n");
    printf("┃      3：增加联系人             ┃\n");
    printf("┃      4：修改信息               ┃\n");
    printf("┃      5：删除联系人             ┃\n");
    printf("┃                                ┃\n");
    // printf("┃                                ┃\n");
    printf("┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n");
    return ON_SUCCESS;
}





int main()
{
    
    int inputValue = 0;     // 获取输入的值
    // char getChar = '\0';    // 获取输入的第一个字节

    char *inputString = (char *)malloc(sizeof(char) * INPUT_SIZE);
    JUDGE_MALLOC(inputString);
    memset(inputString, 0, sizeof(char) * INPUT_SIZE);

    int status = NORMAL;
    while (status > 0)
    {
        /* 1.输出提示 */
        #if 0
        printf("输入数字执行对应操作\n");
        printf("0:退出程序\n");
        #else
        printMenu();
        #endif
        printf(">>>");
        
        /* 2.获取输入信息，需要有健壮性 */
        fgets(inputString, sizeof(inputString), stdin); // https://blog.51cto.com/xiaowange/9105192 
        inputValue = DEFAULT_INPUT_SIZE;
        inputValue = inputString[0] - '0';
        printf(">>>input:%c val:%d\n", inputString[0], inputString[0]);

        /* 3.执行操作，判断逻辑 */
    #if 0
        if (inputValue == 0)
        {
            printf(">>>程序退出！\n");
            status = 0;
        }
        else
        {
            printf(">>>非法输入！\n");
        }
    #else
        switch(inputValue)
        {
            case EXIT:
            {
                printf(">>>程序退出！\n");
                status = QUIT;
                break;
            }
            case PRINT_CONTACTS:
            {
                printf(">>>打印操作\n");
                break;
            }
            case SEARCH_CONTACT:
            {
                printf(">>>查询操作\n");
                break;
            }
            case ADD_CONTACT:
            {
                printf(">>>添加操作\n");
                break;
            }
            case MODIFY_CONTACT:
            {
                printf(">>>修改操作\n");
                break;
            }
            case DELETE_CONTACT:
            {
                printf(">>>删除操作\n");
                break;
            }
            default :
            {
                printf(">>>无效的输入！\n");
                break;
            }
        }

    #endif
    }
    return ON_SUCCESS;
}
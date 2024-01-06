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
#include "balanceBinarySearchTree.h"
#include "test01.h"

#define INPUT_SIZE 30
#define DEFAULT_INPUT_SIZE -1


enum COMMAND_CODE // 命令
{
    DEFAULT_CODE = -1,
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


/* 输出提示信息 */
int printMenu(void)
{
    // ┏ ┓ ┛ ┗ ┻ ┳ ━ ┃
    printf("┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n");
    printf("┃                                ┃\n");
    printf("┃      输入单个数字执行操作      ┃\n");
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
/* 静态函数前置声明 */



/* 静态函数 */


/* 静态函数结束 */


/* 通讯录初始化 */
int contactsInit(Contacts **pContacts, 
                int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2), 
                int (*printFunc)(ELEMENTTYPE val))
{
    balanceBinarySearchTreeInit(pContacts, compareFunc, printFunc);
    return ON_SUCCESS;
}

/* 添加联系人 */
int contactsAdd(Contacts *pContacts, ELEMENTTYPE val)
{
    balanceBinarySearchTreeInsert(pContacts, val);
    return ON_SUCCESS;
}

/* 查询联系人--指定号码--返回结点指针--修改联系人除号码以外的信息需要查询结点 */
Person * contactsSearchAppointNumber(Contacts *pContacts, ELEMENTTYPE compareNode)
{
    Person * travelNode = pContacts->root;
    int cmp = 0;
    while (travelNode != NULL)
    {
        /* 比较大小 */
        cmp = pContacts->compareFunc(compareNode, travelNode->data);
        if (cmp < 0)
        {
            travelNode = travelNode->left;
        }
        else if (cmp > 0)
        {
            travelNode = travelNode->right;
        }
        else
        {
            /* 找到了. */
            return travelNode;
        }
    }
    return NULL;
}

/* 修改联系人--指定号码 */
int contactsModAppointNumber(Contacts *pContacts, ELEMENTTYPE compareNode, ELEMENTTYPE newMessage)
{
    Person * modifyNode = contactsSearchAppointNumber(pContacts, compareNode);
    Message *oldMessage = modifyNode->data;
    modifyNode->data = newMessage;
    FREE(oldMessage);
    return ON_SUCCESS;
}

/* 删除联系人--指定号码 */
int contactsDelAppointNumber(Contacts *pContacts, ELEMENTTYPE compareNode)
{
    balanceBinarySearchTreeDelete(pContacts, compareNode);
    return ON_SUCCESS;
}

/* 打印通讯录 */
int contactsPrintAll(Contacts *pContacts)
{
    balanceBinarySearchTreeInOrderTravel(pContacts);
    return ON_SUCCESS;
}


/* 删除通讯录 */
int contactsPrintDel(Contacts *pContacts)
{
    balanceBinarySearchTreeDestroy(pContacts);
    return ON_SUCCESS;
}





int main()
{
    
    // int inputValue = 0;     // 获取输入的值
    // char getChar = '\0';    // 获取输入的第一个字节

    // char *inputString = (char *)malloc(sizeof(char) * INPUT_SIZE);
    // JUDGE_MALLOC(inputString);
    // memset(inputString, 0, sizeof(char) * INPUT_SIZE);

    

    int status = NORMAL;
    while (status > 0)
    {
        /* 1.输出提示 */
        printMenu();
        printf(">>>");
        
        /* 2.获取输入信息，需要有健壮性 */
    #if 0
        // fgets(inputString, sizeof(inputString), stdin); // https://blog.51cto.com/xiaowange/9105192 
    #else
        char *inputString = (char *)malloc(sizeof(char) * INPUT_SIZE);
        JUDGE_MALLOC(inputString);
        memset(inputString, 0, sizeof(char) * INPUT_SIZE);

        scanf("%s", inputString);
        int len = strlen(inputString);
        int inputValue = DEFAULT_CODE;
        if (len == 1)
        {
            inputValue = inputString[0] - '0';
        }
        // printf("inputString:%s\n", inputString);
        // printf("inputValue:%d\n", inputValue);
        // printf("len:%d\n", len);
    #endif

        /* 3.执行操作，判断逻辑 */
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

    }
    return ON_SUCCESS;
}
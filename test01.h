#ifndef __TEST_01_
#define __TEST_01_


#include "common.h"
#include "balanceBinarySearchTree.h"


#define PHONENUMBER_SIZE 11
#define NUME_SIZE 6

/* 信息结构体 */
typedef struct Message
{
    int phoneNumber;    // 必填项
    char *name;         // 指向姓名所在的地址
    char sex;
} Message;



/* 通讯录结构体 */
typedef BalanceBinarySearchTree Contacts;

/* 联系人结构体 */
typedef AVLTreeNode Person;

/* 输出提示信息 */
int printMenu(void);

/* 通讯录初始化 */
int contactsInit(Contacts **pContacts, 
                int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2), 
                int (*printFunc)(ELEMENTTYPE val));

/* 添加联系人 */
int contactsAdd(Contacts *pContacts, ELEMENTTYPE val);

/* 根据指定的号码获取通讯录的结点 */
Person * contactsSearchAppointNumber(Contacts *pContacts, ELEMENTTYPE compareNode);

/* 删除联系人--指定号码 */
int contactsDelAppointNumber(Contacts *pContacts, ELEMENTTYPE compareNode);

/* 修改联系人--指定号码 */
int contactsModAppointNumber(Contacts *pContacts, ELEMENTTYPE compareNode, ELEMENTTYPE val);

/* 打印通讯录 */
int contactsPrintAll(Contacts *pContacts);

/* 删除通讯录 */
int contactsPrintDel(Contacts *pContacts);

#endif // __TEST_01_
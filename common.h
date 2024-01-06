#ifndef _COMMON_H_
#define _COMMON_H_

#define ELEMENTTYPE void*

enum STATUS_CODEH
{
    NOT_FIND = -1,
    ON_SUCCESS,
    NULL_PTR,
    MALLOC_ERROR,
    INVALID_ACCESS,
};


/* 链表结点取别名*/
typedef struct DoubleLinkNode
{
    ELEMENTTYPE data;
    /* 指向前一个节点的指针*/
    struct DoubleLinkNode *prev;
    /* 指向下一个节点的指针*/
    struct DoubleLinkNode *next;/* 指针类型*/
}DoubleLinkNode;

/* 链表*/
typedef struct DoubleLinkList
{
    DoubleLinkNode * head;/* 链表的虚拟头结点*/
    DoubleLinkNode * tail;/* 尾指针不需要分配空间*/
    int len;/* 链表长度*/
}DoubleLinkList;


/* 宏函数 */

/* 判断malloc是否分配成功 */
#define JUDGE_MALLOC(p)     \
if (NULL == p)              \
    return MALLOC_ERROR;    \

/* 判空 */
#define JUDGE_NULL(p)   \
if (NULL == p)          \
    return NULL_PTR;    \

/* 判空 返回值是NULL，在返回值是指针的函数中使用 */
#define JUDGE_IFNULL_RETURN_NULL(p) \
if (NULL == p)                      \
    return NULL;                    \

/* 释放指针 */
#define FREE(p) \
if (p != NULL)  \
{               \
    free(p);    \
    p = NULL;   \
}               \





#endif //_COMMON_H_


#if 0
/*┏ ┓ ┛ ┗ ┻ ┳ ━ ┃ */

/* ===========报错码============ */
enum ERROR_CODE
{
    NOT_FIND = -4,
    INVALID_ACCESS,
    NULL_PTR,
    MALLOC_ERROR,
    ON_SUCCESS,
};

/* ===========宏定义和宏函数=========== */
#define START_POS 0/* todo */
#define ELEMENTTYPE void*

#define JUDGE_NULL(p)   \
if (NULL == p)          \
    return NULL_PTR;    \

#define JUDGE_MALLOC(p)     \
if (NULL == p)              \
    return MALLOC_ERROR;    \


/* 输出 */
#define PRINT_INT(num) \
//printf("%s:%d\n", #num, num);
#define PRINT //printf("=========\n")
#define PRINT_Message //printf("\n")

/* 释放指针 */
#define FREE(p) \
if (p != NULL)  \
{               \
    free(p);    \
    p = NULL;   \
}               \





/* 双向链表结点 */
typedef struct DoubleLinkNode
{
    ELEMENTTYPE data;
    struct DoubleLinkNode *next;
    struct DoubleLinkNode *prev;
} DoubleLinkNode;

/* 双向链表 */
typedef struct DoubleLinkList
{
    DoubleLinkNode *head;
    DoubleLinkNode *tail;
    int len;
    int (*compareFunc)(ELEMENTTYPE val1, ELEMENTTYPE val2);
    int (*printFunc)(ELEMENTTYPE val);
} DoubleLinkList;

typedef DoubleLinkList DoubleLinkListQueue;
#endif
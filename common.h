#ifndef _COMMON_H_
#define _COMMON_H_

// ┏ ┓ ┛ ┗ ┻ ┳ ━ ┃

/* ===========状态码============ */
enum STATUS_CODE
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

#endif //_COMMON_H_
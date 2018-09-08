#ifndef __EXCEPT_H__
#define __EXCEPT_H__

#include "expr.h"

typedef enum except_type
{
    EXCEPT_UNKNOWN = 0,
    EXCEPT_ALL = 1,
    EXCEPT_ID = 2
} except_type;

typedef enum except_no
{
    EXCEPT_NO_UNKNOWN = 0,
    EXCEPT_NO_DIVISION = 1,
    EXCEPT_NO_ARR_SIZE = 2,
    EXCEPT_NO_INDEX_OOB = 3
} except_no;

typedef struct except
{
    except_type type;
    char * id;
    unsigned int no;
    expr * expr_value;
    unsigned int line_no;
} except;

typedef struct except_list_node
{
    except * value;
    struct except_list_node * prev;
    struct except_list_node * next;
} except_list_node;

typedef struct except_list
{
    unsigned int count;
    except_list_node * head;
    except_list_node * tail;
} except_list;

except * except_new_all(expr_list * seq);
except * except_new_id(char * id, expr_list * seq);

void except_delete(except * value);

except_list_node * except_list_node_new(except * value);
void except_list_node_delete(except_list_node * node);

except_list * except_list_new();
void except_list_delete(except_list * list);

void except_list_add_beg(except_list * list, except * value);
void except_list_add_end(except_list * list, except * value);

#endif /* __EXCEPT_H__ */


/**
 * Copyright 2018 Slawomir Maludzinski
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 *
 * The above copyright notice and this permission notice shall be included
 * in all copies or substantial portions of the Software.
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS
 * OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL
 * THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 * THE SOFTWARE.
 */
#ifndef __TAILREC_H__
#define __TAILREC_H__

#include "never.h"
#include "weakexpr.h"

typedef enum tailrec_op
{
    TAILREC_OP_SKIP = 0,
    TAILREC_OP_ADD = 1
} tailrec_op;

int expr_id_tailrec(unsigned int syn_level, func * func_value,
                    expr * value, tailrec_op op, expr_list_weak * list_weak);
int expr_tailrec(unsigned int syn_level, func * func_value,
                 expr * value, tailrec_op op, expr_list_weak * list_weak);
int expr_list_tailrec(unsigned int syn_level, func * func_value,
                     expr_list * list, tailrec_op op, expr_list_weak * list_weak);
int expr_seq_tailrec(unsigned int syn_level, func * func_value,
                     expr_list * list, tailrec_op op, expr_list_weak * list_weak);
int array_tailrec(unsigned int syn_level, func * func_value,
                  array * value, tailrec_op op, expr_list_weak * list_weak);
int bind_tailrec(unsigned int syn_level, func * func_value,
                 bind * value, tailrec_op op, expr_list_weak * list_weak);
int bind_list_tailrec(unsigned int syn_level, func * func_value,
                      bind_list * list, tailrec_op op, expr_list_weak * list_weak);
int except_tailrec(unsigned int syn_level, func * func_value,
                   except * value, tailrec_op op, expr_list_weak * list_weak);
int except_list_tailrec(unsigned int syn_level, func * func_value,
                        except_list * list, tailrec_op op, expr_list_weak * list_weak);

int last_call_list_tailrec(expr_list_weak * list_weak);
int func_tailrec(unsigned int syn_level, func * value);
int func_list_tailrec(unsigned int syn_level, func_list * list);

int never_tailrec(never * nev);

#endif /* __TAILREC_H__ */

#ifndef  _FSM_TBL_H_
#define _FSM_TBL_H_

#include <stdio.h>
#include <stdlib.h>

#include "stdint.h"

#define STATE_TBL_SIZE(tbl) (sizeof(tbl)/sizeof(tbl[0]))

#define RETURN_IF_FAILED_VAL(expression, val)  do {     \
    if (expression)                                     \
        return val;                                     \
}while(0)

#define RETURN_IF_FAILED(expression)  do {              \
    if (expression)                                     \
        return;                                         \
}while(0)

struct StatusTable;

typedef void (*EventCallback)(struct StatusTable *tbl);

struct StatusTable {
    int16_t status;               //当前状态
    int16_t nextStatus;           //下一个状态
    int16_t event;                //事件
    EventCallback eventCb;        //  事件处理回调函数
};



##endif /* _FSM_TBL_H_ */ 
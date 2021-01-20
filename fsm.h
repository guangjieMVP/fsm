#ifndef __DOGE_FSM_H_
#define __DOGE_FSM_H_

#include "fsm-tbl.h"

/*状态机类 */
struct FSM {
    int16_t fsmCurStatus;             //当前状态
    int16_t curEvent;                 //当前事件
    int16_t tablSize;                 //表的大小
    struct  StatusTable *statusTbl;   //状态表
};

void FSM_Init(struct FSM *f, struct StatusTable *sT, int16_t tblSize, int16_t curStatus, int16_t event);
void FSM_SwitchToNextState(struct FSM *f, int16_t status);
void FSM_TriggerEvent(struct FSM *f, int16_t event);
void FSM_SetCurStatus(struct FSM *f, int16_t status);
void FSM_EventHandleLoop(struct FSM *f);

#endif
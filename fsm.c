#include "fsm.h"

void FSM_Init(struct FSM *f, struct StatusTable *sT, int16_t tblSize, int16_t curStatus, int16_t event)
{
    RETURN_IF_FAILED(f==NULL);

    f->statusTbl = sT;
    f->tablSize  = tblSize;
    f->fsmCurStatus = curStatus;
    f->curEvent = event;
}

void FSM_SwitchToNextState(struct FSM *f, int16_t status)
{
    RETURN_IF_FAILED(f==NULL);

    f->fsmCurStatus = status;
}


void FSM_TriggerEvent(struct FSM *f, int16_t event)
{
    RETURN_IF_FAILED(f==NULL);

    f->curEvent = event;
}


void FSM_SetCurStatus(struct FSM *f, int16_t status)
{
    RETURN_IF_FAILED(f==NULL);

    f->fsmCurStatus = status;
}



void FSM_EventHandleLoop(struct FSM *f)
{
    int index;
    int8_t trigger = 0;

    RETURN_IF_FAILED(f==NULL || f->statusTbl==NULL);

    for (index = 0; index < f->tablSize; index++)
    {
        if (f->curEvent == f->statusTbl[index].event
           && f->fsmCurStatus == f->statusTbl[index].status)
        {
            printf("current status : %d\r\n", f->fsmCurStatus);
            printf("current event : %d\r\n", f->curEvent);
            trigger = 1;
            break;
        }
    }
    if (trigger)
    {
        if (f->statusTbl[index].eventCb)
            f->statusTbl[index].eventCb(&f->statusTbl[index]);         // ×´Ì¬´¦Àíº¯Êý
    }
}
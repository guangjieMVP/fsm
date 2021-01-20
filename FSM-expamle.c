#include "fsm.h"

enum status {
    status1 = 1,
    status2,
    status3,
};

enum {
    EVENT1 = 1,
    EVENT2,
    EVENT3,
};

struct FSM myFsm;           //???????

int a = 0;

void Event1_Cb(struct StatusTable *tbl)
{
    printf("Event 1 %d\r\n", a++);
    if (a > 1000)
    {
        a = 0;
        FSM_TriggerEvent(&myFsm, EVENT2);
        FSM_SwitchToNextState(&myFsm, tbl->nextStatus);
    }
}

int b = 0;
void Event2_Cb(struct StatusTable *tbl)
{
    printf("Event 2 %d\r\n", b++);
    if (b > 10000)
    {
        b = 0;
        FSM_SwitchToNextState(&myFsm, tbl->nextStatus);
    }
}


void Event3_Cb(struct StatusTable *tbl)
{
    printf("Event 3\r\n");
    FSM_SwitchToNextState(&myFsm, tbl->nextStatus);
}



struct StatusTable myStatusTbl[3] = {
    {   .status = status1,
        .nextStatus = status2,
        .event   =  EVENT1,
        .eventCb = Event1_Cb,
    },

   {   .status = status2,
        .nextStatus = status3,
        .event   =  EVENT2,
        .eventCb = Event2_Cb,
    },

   {    .status = status3,
        .nextStatus = status1,
        .event   =  EVENT3,
        .eventCb = Event3_Cb,
    }
};


int main()
{
    int event;

    FSM_Init(&myFsm, myStatusTbl, STATE_TBL_SIZE(myStatusTbl), status1, EVENT1); //

//     printf(" ‰»Îevent:\r\n");
//        scanf("%d", &event);

    while(1)
    {

//        FSM_TriggerEvent(&myFsm, event);
        FSM_EventHandleLoop(&myFsm);
    }

    return 0;
}

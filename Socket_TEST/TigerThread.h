//
//  TigerThread.h
//  SlotMachine
//
//  Created by user on 13-7-25.
//
//

#ifndef __SlotMachine__TigerThread__
#define __SlotMachine__TigerThread__

#include "cocos2d.h"
#include "ODSocket.h"

using namespace cocos2d;
//using namespace extension;

class TigerThread
{
public:
    int threadStart();
    static void* thread_funcation(void *arg);
private:
    pthread_t threadHimi;
};
#endif /* defined(__SlotMachine__TigerThread__) */

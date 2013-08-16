//
//  TigerThread.cpp
//  SlotMachine
//
//  Created by user on 13-7-25.
//
//

#include "TigerThread.h"

int TigerThread::threadStart()
{
    int errCode = 0;
    do{
        
        pthread_attr_t tAttr;
        errCode = pthread_attr_init(&tAttr);
        
        CC_BREAK_IF(errCode!=0);
        
        errCode = pthread_attr_setdetachstate(&tAttr, PTHREAD_CREATE_DETACHED);
        
        if (errCode!=0) {
            pthread_attr_destroy(&tAttr);
            break;
        }
        //若成功则返回0，否则返回出错编号
        errCode = pthread_create(&threadHimi, &tAttr, thread_funcation, this);
        
    }while (0);
    return errCode; 
}

void* TigerThread::thread_funcation(void *arg)
{
    ODSocket *pSocket = ODSocket::sharedODSocket();
    pSocket->Init();
    pSocket->Create(AF_INET, SOCK_STREAM,0);
    
    /*
     /////////////////////////////////////////////
     char ipaddr[20];
     cSocket.DnsParse("www.baidu.com", ipaddr);
     //192.168.22.154
     //aliyun-027.btcsky.com
     /////////////////////////////////////////////--DNS解析 www->ip
     */
    
    if (pSocket->Connect("58.83.190.220", 6621)) {
        char recvBuf[1024] = "\0";
        // std::string testmsg= |login|fan123@sohu.com,e10adc3949ba59abbe56e057f20f883e,68:A8:6D:10:66:DC|$\r\n
        std::string testmsg= pSocket->msg_To_Sever;
        pSocket->Send(testmsg.data(),testmsg.length(),0);
        pSocket->Recv(recvBuf,1024,0);
        std::string rec_msg=std::string(recvBuf);
        printf("%s",rec_msg.c_str());
    }
    else
    {
        CCLog("服务器连接失败");
    }
    pSocket->Close();
    pSocket->Clean();
    return NULL;

}


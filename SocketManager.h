//
// Created by to on 1/2/19.
//

#ifndef GENERICSERVER_SOCKETMANAGER_H
#define GENERICSERVER_SOCKETMANAGER_H


#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>

#include <string.h>
#include <string>

#include <sys/socket.h>


#include <string>
#include "IOManager.h"

#define BUFFER_SIZE 2




class SocketManager : public IOManager {
    int sockfd;
    std::string extra_data;


public:
    SocketManager(int sockfd);

    /**
     * get a massage from the socket
     * @return the massage from the socket
     */
    std::string getMsg() override;

    /**
     * get the first line from a massage from the socket
     * @return the first line from the massage from the socket
     */
    std::string getLine() override;

    /**
     * send a massage throw the socket
     * @param msg - the massage to send
     */
    void sendMsg(std::string &msg) override;

};


#endif //GENERICSERVER_SOCKETMANAGER_H

//
// Created by nikol on 12/26/18.
//

#ifndef GENERICSERVER_MYSERIALSERVER_H
#define GENERICSERVER_MYSERIALSERVER_H

#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>

#include <string.h>
#include <string>

#include <sys/socket.h>
#include "Server.h"
#include "SocketManager.h"
#include <thread>
#include "ServerArguments.h"

using namespace server_side;

class MySerialServer : public Server {
    volatile bool *is_close;
public:
    MySerialServer();

    void open(int port, ClientHandler &client_handler) override;;

    void stop() override;

    virtual ~MySerialServer();
};


#endif //GENERICSERVER_MYSERIALSERVER_H

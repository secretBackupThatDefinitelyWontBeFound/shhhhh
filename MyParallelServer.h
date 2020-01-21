//
// Created by nikol on 12/26/18.
//

#ifndef GENERICSERVER_MYPARALLELSERVER_H
#define GENERICSERVER_MYPARALLELSERVER_H

#include <stdio.h>
#include <stdlib.h>

#include <netdb.h>
#include <unistd.h>
#include <netinet/in.h>

#include <string.h>
#include <string>
#include <thread>
#include <sys/socket.h>
#include <vector>
#include "Server.h"
#include "SocketManager.h"
#include "Server.h"
#include "ServerArguments.h"
#include "ClientArguments.h"


#define MAX_CLIENTS 5

class MyParallelServer : server_side::Server {
    volatile bool *is_close;
    int listen_num;
    thread* new_clients_thread;
    int sockettfed;

public:
    /**
     * defulte constructor
     */
    MyParallelServer();

    MyParallelServer(int listion_num);

    void open(int port, ClientHandler &client_handler) override;

    void stop() override;

    virtual ~MyParallelServer();

private:




};


#endif //GENERICSERVER_MYPARALLELSERVER_H

//
// Created by nikol on 12/26/18.
//

#ifndef GENERICSERVER_SERVER_H
#define GENERICSERVER_SERVER_H

#define BUFFER_SIZE 2
#define SERVER_ERROR "Server Error"
#include "ClientHandler.h"

namespace server_side{
    class Server{
    public:
        virtual void open(int port, ClientHandler &client_handler)=0;
        virtual void stop() = 0;
    };

}

#endif //GENERICSERVER_SERVER_H

//
// Created by to on 1/13/19.
//

#ifndef GENERICSERVER_CLIENTARGUMENTS_H
#define GENERICSERVER_CLIENTARGUMENTS_H

#include "ClientHandler.h"

struct ClientArguments {
    ClientHandler *client_handler;
    int socket_id;

    ClientArguments(ClientHandler *client_handler, int socket_id) : client_handler(client_handler),
                                                                    socket_id(socket_id) {}

};

#endif //GENERICSERVER_CLIENTARGUMENTS_H

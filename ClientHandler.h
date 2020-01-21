//
// Created by nikol on 12/26/18.
//

#ifndef GENERICSERVER_CLIENTHANDLER_H
#define GENERICSERVER_CLIENTHANDLER_H

#include <sstream>
#include "IOManager.h"
using namespace std;

class ClientHandler{
public:
    virtual void handleClient(IOManager* io_manager)=0;
};

#endif //GENERICSERVER_CLIENTHANDLER_H

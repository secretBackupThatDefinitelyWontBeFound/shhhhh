//
// Created by to on 1/3/19.
//

#ifndef GENERICSERVER_IOMANAGER_H
#define GENERICSERVER_IOMANAGER_H

#include <string>

class IOManager {
public:
    /**
     * get a massage from the socket
     * @return the massage from the socket
     */
    virtual std::string getMsg() = 0;

    /**
     * get the first line from a massage from the socket
     * @return the first line from the massage from the socket
     */
    virtual std::string getLine() = 0;

    /**
     * send a massage throw the socket
     * @param msg - the massage to send
     */
    virtual void sendMsg(std::string &msg) = 0;

};

#endif //GENERICSERVER_IOMANAGER_H

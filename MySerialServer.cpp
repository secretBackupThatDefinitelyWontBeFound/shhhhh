//
// Created by nikol on 12/26/18.
//



#include "MySerialServer.h"

void MySerialServer::open(int port, ClientHandler &client_handler) {
    int sockfd, clilen;
    struct sockaddr_in serv_addr, cli_addr;

    /* First call to socket() function */
    sockfd = socket(AF_INET, SOCK_STREAM, 0);

    if (sockfd < 0) {
        throw SERVER_ERROR;
    }

    /* Initialize socket structure */
    bzero((char *) &serv_addr, sizeof(serv_addr));

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_addr.s_addr = INADDR_ANY;
    serv_addr.sin_port = htons(port);

    /* Now bind the host address using bind() call.*/
    if (bind(sockfd, (struct sockaddr *) &serv_addr, sizeof(serv_addr)) < 0) {
        throw SERVER_ERROR;
    }

    /* Now start listening for the clients, here process will
       * go in sleep mode and will wait for the incoming connection
    */

    listen(sockfd, 5);
    ServerArguments *argu = new ServerArguments(sockfd, &client_handler, cli_addr, clilen, is_close);
    /* Accept actual connection from the client */
    //(bool *is_close, int sockfd, struct sockaddr_in cli_addr, int clilen, ClientHandler &client_handler)
    auto f = [](void *argu) {

        struct ServerArguments *arguments = (ServerArguments *) argu;
        int sockfd = arguments->socket_id;
        struct sockaddr_in cli_addr = arguments->cli_addr;
        int clilen = arguments->clilen;
        ClientHandler *client_handler = arguments->client_handler;
        volatile bool *is_close = arguments->is_close;
        delete (arguments);
        std::time_t time = std::time(0);
        while (!(*is_close)) {
            //TODO(noamdwc): add time out
            int newsockfd = accept(sockfd, (struct sockaddr *) &cli_addr, (socklen_t *) &clilen);
            if (newsockfd < 0) {
                throw SERVER_ERROR;
            }
            SocketManager socket_manager(newsockfd);
            client_handler->handleClient(&socket_manager);
        }
        return nullptr;
    };

    //set bool of is_close to false
    (*is_close) = false;
    thread t(f, (void *) argu);
    t.detach();
}

MySerialServer::~MySerialServer() {}


void MySerialServer::stop() {
    (*is_close) = true;
}

MySerialServer::MySerialServer() {
    is_close = new bool;
    (*is_close) = true;
}

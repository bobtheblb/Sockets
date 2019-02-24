#include <stdio.h>

#include <stdlib.h>   

#include <sys/socket.h>

#include <netinet/in.h>

#include <iostream>

#include <string.h>   

#include <arpa/inet.h>

#include <sys/types.h>

#include <unistd.h>

#define MAXBUF 256

int main(int argc, char const *argv[])

{
    int flags;

    bool ReceiveData = true;

    char buffer[MAXBUF];
    buffer[MAXBUF] = {0};
    int my_socket = socket(AF_INET, SOCK_STREAM, 0);

    struct sockaddr_in my_address;

    struct sockaddr_in serv_addr;

    memset(&serv_addr, '0', sizeof(serv_addr));

    my_address.sin_family = AF_INET;

    my_address.sin_addr.s_addr = inet_addr("127.0.0.1");

    my_address.sin_port = htons(5060);

    
    //while(1){
    
        if (my_socket < 0)

        {

            std::cout<<"Failed to Start"<<std::endl;

            return 0;

        }

        else

        {

            std::cout<<"Program Binding and Connecting"<<std::endl;

            //int bind_socket = bind(my_socket, (struct sockaddr *)&my_address, sizeof(my_address));

            std::cout<<"Muddy"<<std::endl;

            int connect_socket = connect(my_socket, (struct sockaddr *)&my_address, sizeof(my_address));

            std::cout<<"Oink"<< connect_socket << std::endl;
            
            if (connect_socket < 0)

            {

                std::cout<<"Could Not Connect"<<std::endl;

                //int reading = read(my_socket, buffer, 265);

            }else{

                std::cout<<"Pig"<<std::endl;
                std::cout<<"This is it gamers, " << connect_socket << std::endl;
                //send(my_socket, string, strlen(string), 0);
                //for(;;)
                //{
                std::cout << "hi" << std::endl;
                
                int reading = recv(my_socket, buffer, MAXBUF, 0);
                std::cout << "um, hello? " << reading << std::endl;
                std::cout << "Its a me - Mario! " << buffer << std::endl;
                
                //}
            }

        }

    //}

}

/*  int location;

    if ((location = socket(AF_INET, SOCK_STREAM, 0)) < 0)

    {

        perror("Socket Can't Be Created");

        return 0;

    }

    std::cout<<"Socket  Location Created"<<std::endl;

    struct sockaddr_in my_address;

    memset((void *)&my_address, 0, sizeof(my_address));

    my_address.sin_family = AF_INET;

    my_address.sin_addr.s_addr = inet_addr("127.0.0.1");

    my_address.sin_port = 5060;

    if (bind(location, (struct sockaddr *)&my_address, sizeof(my_address)) < 0)

    {

        perror("Fail");

    }

    if (connect(location, (struct sockaddr *)&my_address, sizeof(my_address)) < 0)

    {

        perror("Failed to Connect");

    }

    //exit(0);*/
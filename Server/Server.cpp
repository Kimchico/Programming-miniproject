// Server side of networking text program
#define _OE_SOCKETS
#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <thread>
#include <sys/time.h>
#include <mutex>
#include <cstdint>
#include <stdio.h>
#include <cstring>

using namespace std;

// Data container for storing all the data for each client.
struct Data{
    // Char array that stores the message received and send from each client.
    char buffer[1024];
    // The socket of the client.
    int file_d;
    // The name of the client which the user will be prompted to input when executing the Client.cpp.
    string name;
};

// Function used for managing data received from one client and then send it to the other 2.
// Takes 3 arguments first one is the sender and the other 2 is the receivers.
void receive(Data data, Data data_2, Data data_3){
    // Char array that will store the name of the sender.
	char client_name[100];
    // Stores the string variable data.name in the client_name char array declared before.
    // This will make it possible to send that array as a "buffer".
	strcpy(client_name, data.name.c_str());
	
    // Infinite loop that is only stopped if the program is terminated.
    while(true){
        // Function used for receiving data from a particular socket and then storing it in a particular buffer. 
        recv(data.file_d, data.buffer, (sizeof(data.buffer) / sizeof(*data.buffer)), 0);
	
        // If statement that controls whether or not the program should be terminated.
        // If the received char buffer is equal to '#' it will go down into the if statement.
 	    if(*data.buffer == '#'){
            cout << "Program terminated" << endl;
            // The following 3 lines will send the data.buffer to every client, which will make them terminate.
	        send(data.file_d, data.buffer, (sizeof(data.buffer) / sizeof(*data.buffer)), 0);
	        send(data_2.file_d, data.buffer, (sizeof(data.buffer) / sizeof(*data.buffer)), 0);
	        send(data_3.file_d, data.buffer, (sizeof(data.buffer) / sizeof(*data.buffer)), 0);
            //Exits the program.
            exit(1);
        }


	    //Send client name.
	    send(data_2.file_d, client_name, (sizeof(client_name) / sizeof(*client_name)), 0);
	    send(data_3.file_d, client_name, (sizeof(client_name) / sizeof(*client_name)), 0);

	    //send message.
	    send(data_2.file_d, data.buffer, (sizeof(data.buffer) / sizeof(*data.buffer)), 0);
        send(data_3.file_d, data.buffer, (sizeof(data.buffer) / sizeof(*data.buffer)), 0);
        cout << data.name << ": " << data.buffer << endl;
    }
}

int main(){




  return 0;
}

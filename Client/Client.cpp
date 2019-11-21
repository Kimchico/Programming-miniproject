#include <iostream>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <stdlib.h>
#include <unistd.h>
#include <netdb.h>
#include <thread>

using namespace std;    


// Function that receives the data from the Server.
// Takes 2 arguments; a socket and a char buffer[].
void receive(int file_d, char buffer[]){

    // Array where the received message from a client is stored.
	char client_name[100];

    // Infinite loop.
    while(true){

        // Receives the client name and message and stores it in client_name and buffer.
        recv(file_d, client_name, (sizeof(client_name) / sizeof(*client_name)), 0);
        recv(file_d, buffer, 1024, 0);

        // If statement that controls whether or not the message received is a '#
        // If true it will go down into the if statment.
        if(*client_name == '#') {
            cout << "Terminating program now" << endl;

            // Close the file_d socket.
            close(file_d);

            // Exit the program.
            exit(1);
        }

        // Print the message.
	    cout << client_name << " says:";
        cout << " " << buffer << "\n\n";
    }
}

// Main thread
int main(){

    // Variable decleration.
    int client;
    int port = 5000;
    char buffer[1024];
    char buffer_[1024];
    int buff_size = (sizeof(buffer) / sizeof(*buffer));
    struct sockaddr_in server_address;


    // server_address.sin_addr.s_addr is the ip address of the machine which the Server.cpp is running on.
    // Windows: use ipconfig in cmd and set the inet_addr to your IPv4.
    // If needed to connect mulitple computers uncomment the line below and enter the IPv4 where the Server.cpp is running.
    // server_address.sin_addr.s_addr = inet_addr("172.20.10.3");
    server_address.sin_family = AF_INET;
    server_address.sin_port = htons(port);

    // Created the client socket.
    client = socket(AF_INET, SOCK_STREAM, 0);

    // If the client socket is a negative number the program will end.
    if(client < 0){
        cout << "\nError establishing socket" << endl;
        exit(1);
    }

    // Establishes a connection to a specific socket.    
    if (connect(client,(struct sockaddr *)&server_address, sizeof(server_address)) == 0)
        cout << "\nConnection to the server port number: " << port << endl;
}

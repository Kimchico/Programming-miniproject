# Programming-miniproject
C++ miniproject of server and client 


You need to download the CYGWIN emulator since this code does not work on windows.

When you have downloaded Cygwin, you have to download the gcc/g++ compiler.

Now import the folder with the cpp files into the Cygwin/home/user folder.

Now open Cygwin and do the following:

You need to compile with the following sentence:
g++ -std=c++11 fileToCompile.cpp -o a.out

You have to change the fileToCompile.cpp to Server.cpp and run it.
The second time you run it fileToCompile.cpp is changed to Client.ccp and a.out is changed to b.out


Then open 4 windows and write the following in each:

./a.out
./b.out
./b.out
./b.out

Now the program runs, enjoy!




################ How the program works ##############

You have to start up the server first and then the 3 clients afterwards.

The 3 clients have to enter their name and the program will continue.

Then the clients can write freely to each other.

If they want to end the program they have to send the '#' symbol
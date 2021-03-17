/*
*   @Serenki
*   SORRY FOR WRONG C++ CONVENTION
*   I GUESS THAT IS JAVA CONVENTION....
*
* */

#include <iostream>
using namespace std;        //so I don't have to write std::cout every time...


int numberOutsideOfMain = 498;


void bitShiftStuff() {
    cout << "\n\n\nNow let's get to bitshifting...\n";
    cout << "if I actually want to, because I already did some of that in the *.ino files\n";
}

int main()
{

    //getting to know real C++ :D
    cout << "~~~~~~~~The following is first experimenting with C++ outside of the Arduino IDE and library.~~~~~~~~\n";
    cout << "Hello World!\n";
    int number = 0;
    char negativeByte = 0x80;
    unsigned char byteNumber = 0xff;
    cout << "number: " << number << "\n";
    cout << "negativeByte: " << (short) negativeByte << "\n";
    cout << "byteNumber: " << (short) byteNumber << "\n";
    cout << "uhh I am printing a number which was declared outside of this method^^ --> " << numberOutsideOfMain << "\n";
    string testString = "do Strings exist?\n";
    string answer = "seems like they aren't capitalized like in java... so string instead of String...\n";
    cout << testString << answer;
    char whatAbout[] = "What is the difference between String and char-Array?\n";
    cout << whatAbout;




    //ok now let's take a look at pointers I guess :)
    cout << "\n\n\n";
    int* pointer = 0x00;
    //cout << pointer;
    //cout << *pointer;     hihi so I'm not allowed to read 0x00 :D
    pointer = &number;
    cout << "Printing pointer to variable number using our pointer: " << pointer << "\n";
    cout << "Printing the position of the variable number using no newly created pointer: " << &number << "\n";
    cout << "number = " << number << "\n";
    *pointer = number + 1;
    cout << "Now I changed the value my pointer is pointing at. That should also be the value of number then..." << "\n";
    cout << "So let's see: value of pointer: " << *pointer << " -- value of number: " << number << "\n";
    if (*pointer == number) 
        cout << "true"; 
    else 
        cout << "false";
    cout << "\n\n\n";

    //specific testing to understand rfid library for Arduino
    //does it matter where * is for creating a pointer?
    int arduinoInt = 43421;
    int *arduinoPointer = & arduinoInt;
    cout << arduinoInt << "\n";
    //So I guess you can declare a pointer with     type *name;     weird but possible I guess :>   - Spaces don't seem to matter
    cout << "\n\n\n";

    //It still kinda annoys me that * is used to declare a pointer and to get the value of a pointer...

    char character = 'M';
    cout << "Let's try something stupid... :D --> " << *(&character) << "\n";
    //hihi it works 



    //pointers and arrays


    bitShiftStuff();        //really? The method needs to be above main()??? ok...
}




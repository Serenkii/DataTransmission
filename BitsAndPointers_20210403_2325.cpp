/*
*   @Serenki
*   SORRY FOR WRONG C++ CONVENTIONS
*   I GUESS THAT IS JAVA CONVENTION....
*
* */

#include <iostream>
#include <bitset>       //so it's easy to print binaries
using namespace std;        //so I don't have to write std::cout every time...


int numberOutsideOfMain = 498;


void bitStuff() {
    cout << "\n\n\nNow let's get to bitshifting...\n";
    cout << "if I actually want to, because I already did some of that in the *.ino files\n";
    
    unsigned char number = 0b00000001;
    cout << "number = " << bitset<8>(number) << endl;
    number = number << 1;
    cout << "number = " << bitset<8>(number) << endl;
    number << 2;
    cout << "number = " << bitset<8>(number) << endl;
    number = number << 6;
    cout << "number = " << bitset<8>(number) << endl;
    number = number >> 7;
    cout << "number = " << bitset<8>(number) << endl;
    cout << endl;

    char n = 1;
    for (int i = 0; i < 8; i++) {
        cout << "n = " << bitset<8>(n) << endl;
        n = n << 1;
        n++;
    }
    for (int i = 0; i < 8; i++) {
        cout << "n = " << bitset<8>(n) << endl;
        n = n << 1;
    }
    cout << endl;
    for (int j = 0; j < 0/*4*/; j++) {
        for (int i = 0; i < 8; i++) {
            cout << "n = " << bitset<8>(n) << endl;
            n = n << 1;
            n++;
        }
        for (int i = 0; i < 8; i++) {
            cout << "n = " << bitset<8>(n) << endl;
            n = n << 1;
        }
    }
}

void savingFloatBitsIntoInt(float x) {
    cout << "float      x = " << x << "         = " << bitset<32>(x) << endl;
    cout << "I am now trying to copy these bits onto an int because I once saw that in an interesting algorithm in some game\n";
    float* pointerX = &x;
    int z = *pointerX;
    cout << "int        z = " << z << "             = " << bitset<32>(z) << "\n\n";
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
    cout << "\n\npointers and arrays:\n";
    int arr[8] = { 1,2,3,4,255,6,7,8 };
    cout << "An array is a pointer, right, so arr = " << arr << endl;
    cout << "The same should be the pointer to arr[0]... &arr[0] = " << &arr[0] << endl;
    cout << "The pointer to arr[1] should be 1 higher: &arr[1] = " << &arr[1] << endl;
    cout << "oups, nah it actually depends on the size of the datatype^^ - &arr[2] = " << &arr[2] << endl;

    int size = &arr[1] - &arr[0];
    cout << "size = " << size << " byte\nDoesn't seem to work... I don't know why...";

    bitStuff();        //really? The method needs to be above main()??? ok...

    savingFloatBitsIntoInt(13.924);
    savingFloatBitsIntoInt(0.124353245);
    savingFloatBitsIntoInt(93141.213);
    savingFloatBitsIntoInt(-6312.134632);
    cout << "I think they did something differently and I can't quite remember what they had in mind.\nIt was some special "
        << "approximation for a mathematical operation, I think square root (not sure). They used bitshift etc. to be much more efficient.\n"
        << "The method they used had to be very effecient because they used it alot.\n"
        << "(raytracing?, bullets?, reflection?, something to do with angles?, not sure but it was interesting!\n";
    cout << "To use this or learn what they might have done, I need to learn more about floats (and doubles) and how they are stored :)\n";
}




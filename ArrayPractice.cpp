#include "Array.h"
#include <iostream>

using namespace std;

int main() {
    class Array a;

    char gerneralUserInput;
    int tempInput1;
    int tempInput2;
    int functionReturn;
    bool TF = false;

    try {
        a.readTxtFile();
    }
    catch (runtime_error e) {
        cout << e.what() << endl;
    };

    cout << endl;

    cout << "Welcome to the array test" << endl;

    do {
        cout << "Enter F to find an interger in the array" << endl
            << "Enter C to change the value of an interger in the array at a certain index" << endl
            << "Enter A to add an interger to the end of the array" << endl
            << "Enter R to remove an interger in the array" << endl
            << "Or enter Q to quit the program" << endl;
        cin >> gerneralUserInput;
        cin.clear();
        cin.ignore(100, '\n');

        
        gerneralUserInput = toupper(gerneralUserInput);

        if (gerneralUserInput == 'F') {
            cout << endl << "What interger would you like to check for" << endl;
            cin >> tempInput1;
            cin.clear();
            cin.ignore(100, '\n');
            functionReturn = a.arrayCheckInt(tempInput1);
            if (functionReturn == -10)
                cout << endl << "Number does not exist in the array" << endl << endl;
            else
                cout << endl << tempInput1 << " exist at the index " << functionReturn << endl << endl;
        }
       
        if (gerneralUserInput == 'C') {
            do {
                cout << endl << "What is the index of the item you would like to change" << endl;
                cin >> tempInput1;
                cin.clear();
                cin.ignore(100, '\n');
                if (tempInput1 < 0 || tempInput1 > (a.getCurrentArraySize() - 1))
                    cout << endl << "Index is out of bounds" << endl;
                else
                    TF = true;
            } while (!TF); 
            cout << endl << "what is the number you would like to add" << endl;
            cin >> tempInput2;
            cin.clear();
            cin.ignore(100, '\n');
            cout << endl << "The value at " << tempInput1 << " is " << a.getArray(tempInput1) << endl;
            a.setArray(tempInput2, tempInput1);
            cout << endl << "The new value at " << tempInput1 << " is " << a.getArray(tempInput1) << endl << endl;
        }

        if (gerneralUserInput == 'A') {
            cout << endl << "What interger would you like to add to the array" << endl;
            cin >> tempInput1;
            cin.clear();
            cin.ignore(100, '\n');
            try {
                a.arrayAddInt(tempInput1);
                cout << endl << tempInput1 << " was add at index " << a.getCurrentArraySize() - 1 << endl << endl;
            }
            catch (runtime_error e) {
                cerr << endl << e.what() << endl << endl;
            };
            
        }

        if (gerneralUserInput == 'R') {
            do {
                cout << endl << "What is the index of the interger you would like to remove" << endl;
                cin >> tempInput1;
                cin.clear();
                cin.ignore(100, '\n');
                if (tempInput1 < 0 || tempInput1 > a.getCurrentArraySize())
                    cout << endl << "Index is out of bounds" << endl;
                else
                    TF = true;
            } while (!TF);
            cout << endl << a.getArray(tempInput1);
            a.arrayRemoveInt(tempInput1);
            cout << " at the index " << tempInput1 << " was removed" << endl << endl;
        }
        
        TF = false;
    } while (gerneralUserInput != 'Q');

    return 0;
}


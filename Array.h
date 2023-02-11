#ifndef ARRAY_H_
#define ARRAY_H_

const int   MAX_ARRAY_SIZE = 150;

class Array {
private:

    int     currentArraySize = 0;
    int     array[MAX_ARRAY_SIZE];

public:
    //Defaut construsctor (will never have an input)
    Array() {};

    //setArray -> sets a value for the array at a certian index
    //pre takes the number you want to set and the index you want it at
    //post sets the array to the number given at the given index
    void    setArray(int num, int index);

    //getArray -> returns the array at a given index
    //pre takes index
    //post returns the vaule of the array at that index
    int     getArray(int index) const { return array[index]; }
    
    //getArray -> returns the array at the end of the array
    //pre none
    //post returns the value of the array at the end of the array
    int     getArray() const { return array[currentArraySize - 1]; }

    //setCurrentArraySize -> sets the current array size
    //pre inputs a number                                 
    //post changes current array size
    void    setCurrentArraySize(int num);

    //getCurrentArraySize -> gets the current array size
    //pre none
    //post returns the current array size
    int     getCurrentArraySize() { return currentArraySize; }

    //readTxtFile -> reads the given .txt file and turns its data into an array
    //pre existing .txt file
    //post inputs data into a int array
    void    readTxtFile();

    //arrayCheckInt -> Checks array for an int
    //pre a given int
    //post the index of where the int is if found
    int     arrayCheckInt(int num);

    //arrayAddInt -> adds an int the back of the array (spits error if out of bounds)
    //pre an give int
    //post adds int to the end of the array
    void    arrayAddInt(int num);

    //arrayRemoveInt -> removes an int from a given index (main checks the index for out of bounds)
    //pre a given index
    //post turn array[index] to 0
    void    arrayRemoveInt(int index);


};

#endif
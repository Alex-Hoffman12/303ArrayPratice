#include "Array.h"
#include <fstream>
#include <iostream>
#include <stdexcept>


void Array::setArray(int num, int index) {
    array[index] = num;
}

void Array::setCurrentArraySize(int num) {
    currentArraySize = num;
}

void Array::readTxtFile() {
    std::fstream txt;
    int c = 0;
    int num = 0;

    txt.open("Data.txt");
    if (txt.is_open() == false)
        throw std::runtime_error("File can't be open.");
    do {
        if (c == MAX_ARRAY_SIZE) {
            throw std::runtime_error("Array is out of bounds. Please check .txt file for errors.");
        }
        txt >> num;
        setArray(num, c);
        //std::cout << getArray(c) << std::endl; Debug for checking array
        c++;
    } while (!txt.eof());
    currentArraySize = c;
    //std::cout << currentArraySize << std::endl; Debug for currentArraySize
    std::cout << "Data file was read successfully" << std::endl;
}

int Array::arrayCheckInt(int num) {
    for (int i = 0; i < currentArraySize; i++) {
        if (array[i] == num)
            return i;
    }
    return (-10);
}

void Array::arrayAddInt(int num) {
    if (currentArraySize == MAX_ARRAY_SIZE) {
        throw std::runtime_error("Array is to full to contuine.");
    }
    array[currentArraySize] = num;
    currentArraySize++;
}

void Array::arrayRemoveInt(int index) {
    if (index < 0 || index > (currentArraySize)) {
        throw std::runtime_error("Postion is out of bounds.");
    }
    array[index] = 0;
}
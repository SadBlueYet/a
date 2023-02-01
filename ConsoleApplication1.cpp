#include <iostream>
#include <random>
#include <stdlib.h>
void inputArray();
void matrix();
int main() {
   // inputArray();
    matrix();
}
void inputArray() {
    int arrLength;
    std::cin >> arrLength;
    int* array = (int*)malloc(arrLength * sizeof(int));
    bool sub;
    int value;
    for (int i = 0; i < arrLength; i++) {
        std::cin >> array[i];
    }
    do {
        sub = false;
        for (int i = 0; i < arrLength; i++) {
            if (array[i] > array[i + 1]) {
                if (i == arrLength - 1) break;
                value = array[i];
                array[i] = array[i + 1];
                array[i + 1] = value;
                sub = true;
            }else {
                continue;
            } 
        }
    } while (sub == true);
    for (int i = 0; i < arrLength; i++) {
        std::cout << array[i] << '\t';
    }
    free(array);
}
int randomNumber(int min, int max) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(min, max);
    return dist(gen);
}
void matrix() {
    int arrLength;
    std::cin >> arrLength;
    int** arrayLine = (int**)malloc(arrLength * (sizeof(int)));
    
    for (int i = 0; i < arrLength; i++)
        arrayLine[i] = (int*)malloc(arrLength * (sizeof(int)));

    for (int i = 0; i < arrLength; i++) {
        for (int j = 0; j < arrLength; j++) {
            arrayLine[i][j] = randomNumber(0, 99);
        }
    }
    for (int i = 0; i < arrLength; i++) {
        for (int j = 0; j < arrLength; j++) {
            std::cout << arrayLine[i][j] << '\t';
        }
        std::cout << '\n';
    }
    for (int i = 0; i < arrLength; i++)
        free(arrayLine[i]);
    free(arrayLine);
 
}

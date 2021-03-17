#include <iostream>

using namespace std;

#define COMPARISON(firstNum, secondNum) (((firstNum >= 0) && (firstNum < secondNum)) ? "Yes" : "No")

#define arrayAccess(numLine, numColumn) *(*(justArray + numLine) + numColumn)

#define returnSizeArray(localArray, arrayType) (sizeof(localArray)) / (sizeof(arrayType))

int main(int argc, const char** argv) {

    // ex 7.1
    // Описать макрокоманду, проверяющую, входит ли переданное
    // ей число в диапазон от нуля (включительно) до переданного ей второго аргумента (исключительно)

    cout << COMPARISON(5, 10) << endl;

    // ex 7.2
    // Описать макрокоманду, получающую доступ к элементу двумерного
    // массива (организованного динамически) посредством разыменования указателей

    const int lenArray = 3;

    int **justArray = new int *[lenArray];

    for (int i = 0; i < lenArray; i++){

        justArray[i] = new int [lenArray];

    }

    for (int line = 0; line < 3; line++) {
        for (int column = 0; column < 3; column++){
            justArray[line][column] = rand() % 10 + 1;
        }
    }

    cout << arrayAccess(0,0) << endl;

    for (int count = 0; count < 3; count++){  // Вопрос, удалять память лучше в конце кода или сразу?
        delete [] justArray[count];           // В интернете неоднозначные ответы на этот вопрос.
    }

    // ex 7.3
    // Описать макрокоманду, возвращающую количество элементов локального
    // массива, принимающую на вход ссылку на массив и его тип

    int localArray[14];

    cout << returnSizeArray(localArray, int) << endl;

   return 0;
}

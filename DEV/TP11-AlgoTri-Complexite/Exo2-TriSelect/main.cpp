#include <iostream>

void display(int arraySize, std::string array[]){
    for  (int i = 0; i < arraySize; i++){
        std::cout << array[i] << ", ";
    }
    std::cout << std::endl;
}

void swap(std::string &string1, std::string &string2){
    std::string temp = string1;
    string1 = string2;
    string2 = temp;
}

void selectiveSort(int arraySize, std::string array[]){
    for (int i = 0; i < arraySize; i++){
        int mini = i;
        for (int j = i+1; j < arraySize; j++){
            if (array[mini].compare(array[j]) > 0){
                mini = j;
            }
        }
        if (mini != i){
            swap(array[i], array[mini]);
        }
    }
}

int main()
{
    std::string array[10] = {"zerator", "genshin", "Kevin", "Zelda", "Celeste", "1", "1020", "BOTW", "Skyward", "Skyward"};
    display(10, array);
    selectiveSort(10, array);
    display(10, array);
    return 0;
}

#include <iostream>
#include <chrono>
#include <ctime>
#include <random>

int randomIntBetween(int min, int max){
    std::random_device rd;
    std::default_random_engine eng(rd());
    std::uniform_int_distribution<int> distr(min, max);
    return distr(eng);
}

void generateArray(int size, std::string array[]){
    for (int i = 0; i < size; i++){
        int len = randomIntBetween(5, 20);
        std::string word = "";
        for (int j = 0; j < len; j++){
            word += char(randomIntBetween(32, 126));
        }
        array[i] = word;
    }
}

long timeSort(void (*sortFunc)(int, std::string []), int size, std::string array[]){
    std::chrono::system_clock::time_point begin = std::chrono::system_clock::now();
    sortFunc(size, array);
    std::chrono::system_clock::time_point end = std::chrono::system_clock::now();
    std::chrono::duration time = end - begin;
    long ns = std::chrono::duration_cast<std::chrono::nanoseconds> (time).count();
    return ns;
}

void display(int arraySize, std::string array[]){
    for  (int i = 0; i < arraySize; i++){
        std::cout << array[i] << ", " << std::endl;
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
    int arraySize = 1000;
    long long nbTests = 1000;
    long long totalTime = 0;
    std::string array[arraySize];
    for (int i = 0; i < nbTests; i++){
        generateArray(arraySize, array);
        totalTime += timeSort(&selectiveSort, arraySize, array);
    }
    std::cout << totalTime/nbTests << " ns" << std::endl;
    return 0;
}

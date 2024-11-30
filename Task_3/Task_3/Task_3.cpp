#include <iostream>
#include <string>
#include <windows.h>

template<class T>
class Arr_3 {
    T* arr;
    int size;
    int count_3{};
    int count_3_sum{};
public:

    Arr_3(int s, T* initArr) : size(s) {
        arr = new T[size];
        for (int i = 0; i < size; i++) {
            arr[i] = initArr[i];
        }
    }
    ~Arr_3() {
        delete[] arr;
    }

    void operator()() {
        count_3 = 0;
        count_3_sum = 0;
        for (int i = 0; i < size; i++) {
            if (arr[i] % 3 == 0) {  // Проверяем кратность 3
                count_3++;
                count_3_sum += arr[i];
            }
        }
    }

    void get_sum() {
        std::cout << "\n[OUT]: "<<"get_sum() = " << count_3_sum;
    }

    void get_count() {
        std::cout << "\n[OUT]: "<<"get_count() = " << count_3;
    }
};

void print_array(int values[], int size) {
    for (int i = 0; i < size; ++i) {
        std::cout << values[i] << " ";
    }

}

int main(int argc, char* argv[])
{
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    int values[] = { 4, 1, 3, 6, 25, 54 };   
    int size_of_values = sizeof(values) / sizeof(values[0]);
    Arr_3<int> obj(6, values);
    obj();
    std::cout << "[IN]: ";
    print_array(values,size_of_values);      
    obj.get_count();
    obj.get_sum();

}

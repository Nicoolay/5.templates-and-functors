#include <iostream>
#include <windows.h>

template <typename T>
class table {
public:
    // Конструктор, создающий двумерный массив
    table(int rows, int cols)
        : rows(rows), cols(cols) {
        data = new T * [rows]; // Массив указателей на строки

        for (int i = 0; i < rows; ++i) {
            data[i] = new T[cols];
        }
    }

    // Деструктор
    ~table() {
        for (int i = 0; i < rows; ++i) {
            delete[] data[i]; 
        }
        delete[] data; 
    }

    table& operator=(const table&) = delete;
    table(const table&) = delete;

    const T* operator[](int row) const {
        if (row < 0 || row >= rows) {
            std::cout<<"Число должно быть в пределах диапазона";
        }
        return data[row];
    }

    T* operator[](int row) {
        if (row < 0 || row >= rows) {
            std::cout << "Число должно быть в пределах диапазона";
        }
        return data[row];
    }

    // Функция для получения размера таблицы
    int Size() const {
        return { rows* cols };
    }

private:
    int rows; 
    int cols;
    T** data; 
};
int main(int argc, char* argv[]) {
   
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);
    
    table<int> test(2, 3); 
    test[0][0] = 4; 
    std::cout << test[0][0] << std::endl; 
    test[1][2] = 7;
    std::cout << test[1][2] << std::endl; 
    std::cout << "Размер таблицы: "<< test.Size();
    //table<int> t1(2, 3);// запретил копирование и присваивание, код для теста
    //table<int> t2(2, 3);
    //t1 = t2;

    //table<double> t1(2, 3);
    //table<double> t3(t1);
    return 0;
}

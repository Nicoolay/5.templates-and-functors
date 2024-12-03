#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

class Arr_3 {
    int count_3{};
    int count_3_sum{};
public:
    Arr_3():count_3(0),count_3_sum(0){}
   
    void operator()(int num) {
                if (num % 3 == 0) {  // Проверяем кратность 3
                count_3++;
                count_3_sum += num;
            }
       }

    int get_sum() const {
        return count_3_sum;
    }

    int get_count() const {
        return count_3;
    }
};
void print(int x) {
    std::cout << x << " ";
}

int main(int argc, char* argv[])
{
    std::vector<int> numbers = { 4, 1, 3, 6, 25, 54 };
    Arr_3 counter= std::for_each(numbers.begin(), numbers.end(), Arr_3());
    std::cout << "[IN]: ";
    std::for_each(numbers.begin(), numbers.end(), print);
    std::cout << "\n[OUT]: get_sum() = " << counter.get_sum() << std::endl;
    std::cout << "[OUT]: get_count() = " << counter.get_count() << std::endl;
}

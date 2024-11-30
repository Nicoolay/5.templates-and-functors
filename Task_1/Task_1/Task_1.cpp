#include <iostream>
#include <string>
#include <vector>


template <typename B>
B my_square(B a) {
    return a * a;
}
template <typename T>
std::vector<T> my_square( std::vector<T>& vec) {
    std::vector<T> result;
    result.reserve(vec.size()); 
    for ( T& value : vec) {
        value = my_square(value);
    }
    return result;
}

template <typename T>
void print_vector(const std::vector<T>& vec) {
    for (size_t i = 0; i < vec.size(); ++i) {
        std::cout << vec[i];
        if (i != vec.size() - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

int main(int argc, char* argv[])
{
    int num{4};
    std::cout << "[IN]: "<<num;
    std::cout << "\n[OUT]: " << my_square(num)<< std::endl;
    std::vector<int> arr = { -1, 4, 8 };
    std::cout << "[IN]: ";
    print_vector(arr);
    my_square(arr);
    std::cout << "[OUT]: ";
    print_vector(arr);
   


}

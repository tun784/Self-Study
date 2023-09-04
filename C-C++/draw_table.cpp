#include <iostream>
#include <iomanip> // for setw

int main() {
    // Table headers
    std::cout << std::left << std::setw(10) << "Name"
              << std::setw(10) << "Age"
              << std::setw(10) << "City" << std::endl;

    // Table rows
    std::cout << std::left << std::setw(10) << "John"
              << std::setw(10) << "25"
              << std::setw(10) << "New York" << std::endl;

    std::cout << std::left << std::setw(10) << "Alice"
              << std::setw(10) << "30"
              << std::setw(10) << "London" << std::endl;

    std::cout << std::left << std::setw(10) << "Bob"
              << std::setw(10) << "22"
              << std::setw(10) << "Paris" << std::endl;
      system("pause");
    return 0;
}
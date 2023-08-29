#include <iostream>

/*
 * Simple main function: 
 * Read two numbers and write their sum
 */

int main() {

    //Exercise 1.3
    std::cout << "Hello, World" << std::endl; 

    //Exercise 1.4
    int v1 = 0, v2 = 0;
    std::cin >> v1 >> v2;
    std::cout << "The product of " << v1 << " and " << v2 << " is " << v1 * v2 << std::endl; 
    
    //Exercise 1.5
    std::cout << "The sum of ";
    std::cout << v1;
    std::cout << " and ";
    std::cout << v2;
    std::cout << " is ";
    std::cout << v1 + v2;
    std::cout << std::endl;
    
    //Exercise 1.6
    //The program is not legal, since the first statement has ended with a semicolon, The second and third statement cannot receive standard output object to print what stores in the ostream
    std::cout << "The sum of " << v1
              << " and " << v2
              << " is " << v1 + v2 << std::endl;

    //Exercise 1.8
    std::cout << "/*";
    std::cout << "*/";
    std::cout << std::endl;

    //Exercise 1.9
    int sum = 0, val = 50;
    while (val <= 100) {
        sum += val;
        val++;
    }
    std::cout << "Sum of 50 to 100 inclusive is " << sum << std::endl;

    //Exercise 1.10
    int val1 = 10;
    while (val1 >= 0) {
        std::cout << val1 << std::endl;
        val1--;
    }

    //Exercise 1.11
    int x = 0, y = 0;
    std::cin >> x >> y;
    while (y >= x) {
        std::cout << y << std::endl;
        y--;
    }

    //Exercise 1.16
    sum = 0;
    int a = 0;
    while (std::cin >> a) {
        sum += a;
    }
    std::cout << "The sum of numbers is " << sum << std::endl;
    return 0;
}
#include <iostream>
#include "Sales_item.h"

int main() {

    // //Exercise 1.21
    // Sales_item item1, item2;

    // std::cin >> item1 >> item2;
    // if (item1 == item2) {
    //     std::cout << item1 + item2 << std::endl;
    // }
    // else {
    //     std::cout << "they are not the same." << std::endl;
    // }

    // //Exercise 1.22
    // Sales_item total, item;
    // if (std::cin >> total) {
    //     while (std::cin >> item)
    //         total += item;
    //     std::cout << total << std::endl;
    // }

    //Exercise 1.33
    Sales_item currItem, item;

    if (std::cin >> currItem) {
        int cnt = 1;
        while (std::cin >> item) {
            if (currItem.isbn() == item.isbn()) {
                cnt++;
            }
            else {
                std::cout << currItem.isbn() << " " << cnt << std::endl;
                currItem = item;
                cnt = 1;
            }
        }
        std::cout << currItem.isbn() << " " << cnt << std::endl;
    }
    return 0;
}
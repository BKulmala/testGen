#include "Quizlet.hpp"
int main() {
        bool choice;
        std::cout << "Do you want to review a chapter or create a new review?\n" <<
                     "0:Create a new chapter.\n" <<
                     "1:Review a chapter.\n";
    std::cin >> choice;
    if(choice == 0) {
        std::cout << "What is the chapter?\n";
        fileCreate();
    }
    else if(choice == 1){
        std::cout << "What are you reviewing?\n";
        fileList();
    }
    return 0;
}

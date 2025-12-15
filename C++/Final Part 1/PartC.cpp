#include <iostream>
#include <string>
#include "task_methodsPARTC.h"

int main(){
    std::string stringinput = "0";
    int choice;

    int intinput;

    int size = 5;
    TaskManager Manager(size);
    do{

    do{
        displaymenu();  
        std::getline(std::cin, stringinput);
        std::cout << std::endl;
    } while(!(stringinput == "1" || stringinput == "2" || stringinput == "3" || stringinput == "4" || stringinput == "5"));

    choice = stringtoint(stringinput);

    switch(choice){
        case 1:
        std::cout << "Enter the task description: ";
        std::getline(std::cin, stringinput);
        Manager.addTask(stringinput);
        break;

        case 2:
        do{
            std::cout << "Enter the number of which task to delete: ";
            std::getline(std::cin, stringinput);}
        while (stringtoint(stringinput) == 0);
        Manager.removeTask(stringtoint(stringinput));
        break;

        case 3:
        do{
            std::cout << "Enter the number of which task to complete: ";
            std::getline(std::cin, stringinput);}
        while (stringtoint(stringinput) == 0); //only 1-5
        intinput = stringtoint(stringinput);
        Manager.completeTask(intinput);
        break;

        case 4:
            Manager.listTasks();
        break;

        case 5:
            return 0; //auto clears memory
        break;
    }
} while(choice != 5);
return 0;
}

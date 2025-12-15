#include <iostream>
#include <string>
#include "task_methodsPARTB.h"

int main(){
    int size = 0;
    const int capacity = 5; //i did not do the optional part
    int choice = 0;
    std::string input = "";
    int idnumber = 1;
    int helpvar = 0;

    Task* tasks = new Task[capacity]; //an array of tasks with index 0 to capacity - POINTER TO HEAP

do{
    do{
    displaymenu();
    std::getline(std::cin, input);
    std::cout << std::endl;
    }
    while(!(input == "1" || input == "2" || input == "3" || input == "4" || input == "5")); //demorgans law 
    
    choice = stringtoint(input);

    switch(choice){
        case 1:
            std::cout << "Enter a description: ";
            std::getline(std::cin, input);

            helpvar = size;
            addTask(tasks, size, capacity, input); //POINTER ALREADY MADE FROM TASKS
            std::cout << std::endl;
            if(helpvar == size){ //new variable to make sure that i dont affect the functions said in the assignemnt
                break;
            }

            if(size <= capacity){ 
                (tasks + size - 1) -> setId(idnumber); 
            idnumber++;
            }
            break;

        case 2:
            do{
            std::cout << "Enter the number of which task to delete: ";
            std::getline(std::cin, input);}
            while (stringtoint(input) == 0);
            removeTask(tasks, size, stringtoint(input));
            break;

        case 3:
            do{
            std::cout << "Enter the number of which task to complete: ";
            std::getline(std::cin, input);}
            while (stringtoint(input) == 0);
            completeTask(tasks + stringtoint(input) - 1, stringtoint(input)); //different from the part A function
            break;                                     

        case 4:
            listTasks(tasks, size); 
            break;
        
        case 5:
            deletelist(tasks);
            input = "5";
            break;
            
    }
} while (choice != 5);

}

#pragma once
#include <iostream>
#include <string>

class Task {
private:
    int id;
    std::string description;
    bool completed;

public:
    Task() : id(0), description(""), completed(false) {};

    Task(int idinput, const std::string& descinput): id(idinput), description(descinput), completed(false) {};

    //~Task() {std::cout << "task deleted/allocated" << std::endl;}; used to check

    void markCompleted(){
        completed = true;
    };

    bool isCompleted() const {
        return completed;
    }; 

    int getId() const {
        return id;
    };

    std::string getDescription() const{
        return description; 
    }; 

    void setId(int idInput){ //NEW FUNCTION
        id = idInput;
    }
};

void completeTask(Task *t, int position){ 
    if(position == 0){
    std::cout << "There is no task there" << std::endl << std::endl;
    return;
    }
    if(t -> getId() == 0){
        std::cout << "There is no task there" << std::endl << std::endl;
        return;
    }
    t -> markCompleted();
    std::cout << "Completed task " << position << std:: endl << std::endl; 
    
};

//PART B
void addTask(Task* tasks, int &size, int capacity, const std::string& desc){ 
    if (size >= capacity){
        std::cout << "Maximum tasks reached! (" << capacity << ")" << std::endl;
        return;
    }
    *(tasks + size) = Task(0, desc); //i set the id in main later so that i can increment the id past the size
    size++; 
    std::cout << "Added Task " << size << std::endl; 
};

void removeTask(Task* tasks, int& size, int input){
    
    if(input > size || input == 0){
        std::cout << "There is no task there!" << std::endl << std::endl;
        return;
    }

   for(int i = input - 1; i < size - 1; i++){ //shifts all elements to the right of id left
    *(tasks + i) = *(tasks + i + 1); 
   }
    
    *(tasks + size - 1) = Task();
    
    std::cout << "Removed Task " << input << std::endl << std::endl;
    size--;
        return;
};

void listTasks(Task* tasks, int size){
    if(size == 0){
        std::cout << "There is no tasks" << std::endl << std::endl;
        return;
    }

    std::cout << "TASK LIST" << std::endl;
    for(int i = 0 ; i < size ; i++){ 
        std::cout << "Task " << i+1; //list
        std::cout << " (ID " << (tasks + i) -> getId(); //id number
        std::cout << "): " << (tasks + i)-> getDescription(); //description
        
        if((tasks + i) -> isCompleted() == 0){
        std::cout << " (Incomplete)";}

        if((tasks + i) -> isCompleted() == 1){
        std::cout << " (Complete)";}

        std::cout << std::endl;
    }
    std::cout << std::endl;
};

void deletelist(Task*&tasks){
    delete[] tasks;
    tasks = nullptr;
};

void displaymenu(){
    std::cout << "TASK MANAGER" << std::endl;
    std::cout << "Add Task (1)" << std::endl;
    std::cout << "Remove Task (2)" << std::endl;
    std::cout << "Complete Task (3)" << std::endl;
    std::cout << "List Tasks (4)" << std::endl;
    std::cout << "Delete List and Quit (5)" << std::endl;
    std::cout << "Input: ";
};

int stringtoint(std::string input){ //for input validation and such
    if (input == "1") {return 1;}
    else if (input == "2") {return 2;}
    else if(input == "3") {return 3;}
    else if (input == "4") {return 4;}
    else if (input == "5") {return 5;}
    return 0;
};






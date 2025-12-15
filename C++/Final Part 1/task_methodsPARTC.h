#pragma once
#include <iostream>
#include <string>
#include <memory>

class Task {
private:
    int id;
    std::string description;
    bool completed;

public:
    Task() : id(0), description(""), completed(false) {};

    Task(int idinput, const std::string& descinput): id(idinput), description(descinput), completed(false) {};

//    ~Task() {std::cout << "task deleted/allocated" << std::endl;};

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

    void setId(int idInput){ //NEW FUNCTION FOR ADD TASK
        id = idInput;
    }
};

class TaskManager {
private:
    std::unique_ptr<Task[]> tasks;
    int size = 0;
    int capacity = 0;
    int idcounter = 0; //SOOOO MUCH BETTER!!!!

public:
    TaskManager(int initialCapacity){
        tasks = std::make_unique<Task[]>(initialCapacity);
        capacity = initialCapacity;
    };
 
    void addTask(const std::string& desc){ 
    if (size >= capacity){
        std::cout << "Maximum tasks reached! (" << capacity << ")" << std::endl;
        return;
    }
        tasks[size] = Task(idcounter, desc); //i set the id in main later so that i can increment the id past the size
        size++; 
        idcounter++;

        std::cout<< "Added Task " << size << std::endl << std::endl;
    };

    void removeTask(int input){ //input validation
        
    if(input > size || input <= 0){
        std::cout << "There is no task there!" << std::endl << std::endl;
        return;
    }

   for(int i = input - 1; i < size - 1; i++){ //shifts all elements to the right of id left
        tasks[i] = tasks[i + 1]; //Task(i, (tasks + i + 1) -> getDescription()); //THIS is the wroon
   }
    
    //tasks[i] = tasks[i + 1];
    
    std::cout << "Removed Task " << input << std::endl << std::endl;
    size--;
        return;
};

    void completeTask(int position) {
    if (position <= 0 || position > size) {
        std::cout << "Invalid task number!" << std::endl << std::endl;;
        return;
    }

        tasks[position - 1].markCompleted();
        std::cout << "Completed Task " << position << std::endl << std::endl;
    }

    void listTasks(){ //i had to watch a video to learn the syntax
        
        if(size == 0){
            std::cout << "There is no tasks" << std::endl;
            return;
        }
        
        std::cout << "TASK LIST" << std::endl;
        for(int i = 0 ; i < size ; i++){ 
        std::cout << "Task " << i+1; //list
        std::cout << " (ID " << tasks[i].getId() + 1; //id number
        std::cout << "): " << tasks[i].getDescription(); //description
        
        if((tasks[i].isCompleted() == false)){
        std::cout << " (Incomplete)";}

        if(tasks[i].isCompleted() == true){
        std::cout << " (Complete)";}

        std::cout << std::endl;
    }
    std::cout << std::endl;
};

};

int stringtoint(std::string input){ //for input validation and such
    if (input == "1") {return 1;}
    else if (input == "2") {return 2;}
    else if(input == "3") {return 3;}
    else if (input == "4") {return 4;}
    else if (input == "5") {return 5;}
    return 0;
};

void displaymenu(){
    std::cout << "FUNCTION MANAGER" << std::endl;
    std::cout << "Add Task (1)" << std::endl;
    std::cout << "Remove Task (2)" << std::endl;
    std::cout << "Complete Task (3)" << std::endl;
    std::cout << "List Tasks (4)" << std::endl;
    std::cout << "Delete List and Quit (5)" << std::endl;
    std::cout << "Input: ";
};

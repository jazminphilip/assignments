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

    //~Task() {std::cout << "task deleted/allocated" << std::endl;};

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

};
//PART A
void completeTask(Task *t){ //enter an address for object, then it accesses the function associated with the object under the class
    t -> markCompleted();
};

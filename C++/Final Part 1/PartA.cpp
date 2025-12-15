#include <iostream>
#include <string>
#include "task_methodsPARTA.h"
using namespace std;
    
int main() {

    Task t1(1, "Finish project");
    Task t2(2, "Study for exam");

    Task* p1 = &t1;
    Task* p2 = &t2; 

    string task_number = "";
    string response = "";

    do{
    {
        do{
        if(t1.isCompleted() == 1){
            cout << "Task " << t1.getId() << " is completed: ";}
        else { 
            cout <<"Task " << t1.getId() << " is not completed: ";}
            
        std::cout << t1.getDescription() << std::endl;

        if(t2.isCompleted() == 1){
            cout << "Task " << t2.getId() << " is completed: ";}
        else { 
            cout << "Task " << t2.getId() << " is not completed: ";}
            
        std::cout << t2.getDescription() << std::endl << std::endl;

        cout << "You have two tasks, which would you like to select? (1) or (2)" << endl;
        cin  >> task_number;
        cout << endl;}
        while (task_number != "1" && task_number != "2");

        do{
        cout << "do you wish to complete that task? (y) or (n)" << endl;
        cin >> response;
        cout << endl;}
        while (response != "y" && response != "n");
    }
        {
            if (response == "y" && task_number == "1"){
                completeTask(p1);
            }

            else if (response == "y" && task_number == "2"){
                completeTask(p2);
            }
        }
    
        

    } while (t1.isCompleted() == 0 || t2.isCompleted() == 0);
    
    cout << "You finished all your tasks.";
    return 0;
}

# UML Diagrams
```
┌─────────────────────────┐   ┌─────────────────────────────┐   ┌─────────────────────────────┐
│    Part A: Task Class   │   │  Part B: Task + Functions   │   │    Part C: Task + Manager   │
├─────────────────────────┤   ├─────────────────────────────┤   ├─────────────────────────────┤
│ - id: int               │   │ - id: int                   │   │ - id: int                   │
│ - description: string   │   │ - description: string       │   │ - description: string       │
│ - completed: bool       │   │ - completed: bool           │   │ - completed: bool           │
├─────────────────────────┤   ├─────────────────────────────┤   ├─────────────────────────────┤
│ + Task()                │   │ + Task()                    │   │ + Task()                    │
│ + Task(int, string)     │   │ + Task(int, string)         │   │ + Task(int, string)         │
│ + markCompleted(): void │   │ + markCompleted(): void     │   │ + markCompleted(): void     │
│ + isCompleted(): bool   │   │ + isCompleted(): bool       │   │ + isCompleted(): bool       │
│ + getId(): int          │   │ + getId(): int              │   │ + getId(): int              │
│ + getDescription(): str │   │ + getDescription(): str     │   │ + getDescription(): str     │
└─────────────────────────┘   │ + setId(int): void          │   └─────────────────────────────┘
                              ├─────────────────────────────┤   ┌─────────────────────────────┤
                              │ + completeTask(Task*): void │   │      TaskManager Class      │
                              │ + addTask(Task*, int&,      │   ├─────────────────────────────┤
                              │   int, string): void        │   │ - tasks: unique_ptr<Task[]> │
                              │ + removeTask(Task*, int&,   │   │ - size: int                 │
                              │   int): void                │   │ - capacity: int             │
                              │ + listTasks(Task*, int):    │   ├─────────────────────────────┤
                              │   void                      │   │ + TaskManager(int)          │
                              │ + deletelist(Task*&): void  │   │ + addTask(string): void     │
                              │ + displaymenu(): void       │   │ + removeTask(int): void     │
                              │ + stringtoint(string): int  │   │ + completeTask(int): void   │
                              └─────────────────────────────┘   │ + listTasks(): void         │
                                                                └─────────────────────────────┘
```
                                                              
# Part D

Answer the following:

1) Differences between: pointer to stack memory, pointer to heap memory, smart pointer (unique_ptr)

Firstly, pointer to stack memory is a pointer that points to another object or variable in the stack. 

Secondly, pointers to heap memory is a pointer that points to an object on the heap. The difference between this and raw pointers on the stack is that pointers to heap memory are not automatically handled by the compiler. Programmers must use delete and also set heap pointers used to null. 

Thirdly, smart pointers are pointers that point to the heap but automatically delete what is inside of where they are pointing to when their scope ends. What they do is try to be similar to stack pointers in the way that the compiler automatically handles them without having to manually free the memory like in raw heap memory pointers. 
  
2) Where and why delete was used.

Delete was used in Part B because I was using a raw pointer to the heap. Raw pointers to the stack are automatically handled by the compiler and smart pointers have RAII so there is no need to use delete there. 

3) Explanation of ownership in each design.

In part A, raw pointers to the stack are similar to variables. There is no delete function for the pointer just like how there is no delete function for normal primitive data type variables. When the program ends, all variables in the stack are automatically freed for next run, but also the pointers that reside them get cleared as well.

In Part B, where raw pointers to the heap are used, I delete at the end of the main with a function. I only use one pointer that points to an array, so by deleting that pointer, it frees up the memory that is took and also sets the pointer to nullptr. 

In Part C of my code, I use unique pointers so that during the end of my code, the pointer automatically frees the memory from the array of tasks. Here only one unique pointer can exist for the list of task because by going out of scope of the unique variable, the objects are deleted and the address associated with the array is freed. If I were to create an app that had multiple lists of tasks, this would probbaly be wat I would use alongside the vector header file to make the logic for removing a task from the list easier.

4) Which pointer method is safest and why.

The safest pointer method is the smart pointer. This is because it is easy to have a memory leak, have multiple deletes, dangling pointers, or wild pointers when working with raw pointers since there is a need to always be mindful of where to delete a pointer. I would say that raw pointers to the stack are the safest since they are easiest to work with, but smart pointers have more use with how object oriented programming works with classes as a whole.

# Reflection

While doing this assignment, I was worried about ID and position the most. This is because I wanted all tasks to have a separate ID which increments but that their position would shift depending on what was deleted. I very confused on whether or not I was supposed to pass the ID number of what was to be deleted or the position because I did not know if I was to dynamically resize the array.

I thought that this may have not been the case because we learned about the vector header file so I would just use that and because by the time I realized this I would have to rewrite my string to int function that I depended to turn the strings 1 through 5 into integers. I also saw that the dynamic resize option for part B was an optional thing but was worried because in the rubric the input for the remove task function was listed as Id.  

My choose option for maenu implementation and selecting which part of the array to select both depended on the string to int function, so I would have to rewrite a lot more if I were to make dynamic sizing.

I really wanted to implement the resize function, but I was already very much struggling with this assignment and overwhelmed with other classes.

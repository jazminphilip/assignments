# Part D

Answer the following:

Differences between:

pointer to stack memory
pointer to heap memory
smart pointer (unique_ptr)

  Firstly, pointer to stack memory is a pointer that points to another object or variable in the stack. 

  Secondly, pointers to heap memory is a pointer that points to an object on the heap. The difference between this and raw pointers on the stack is that pointers to heap memory are not automatically handled by the compiler. Programmers must use delete and also set heap ointers used to null. 

  Thirdly, smart pointers are pointers that point to the heap but automatically delete what is inside of where they are pointing to when their scope ends. What they do is try to be similar to stack pointers in the way that the compiler automatically handles them without having to manually free the memory like in raw heap memory pointers. 
  
Where and why delete was used.

  Delete was used in Part B beacause I was using raw pointers to the heap. Raw pointers to the stack are automatically handled by the compiler and smart pointers have RAII so there is no need to use delete.

Explanation of ownership in each design.

In part A, raw pointers to the stack are similar to variables. There is no delete function for the pointer just like how there is no delete function for normal primitive data type variables.

In Part B, where this is used, I delete at the end with a function. I only use one pointer that points to an array, so by deleting that pointer, it sets all of the objects in the array to be usable again. The function then sets the pointer to a nullptr.  

In Part C of my code, I use unique pointers so that when at the end of my code the pointer automatically reallocates the memory from the array of tasks. 


Which pointer method is safest and why.

  The safest pointer method is the smart pointer. This is because it is easy to have a memory leak when working with raw pointers and forgetting to 

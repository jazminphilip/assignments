# 🧮 Assignment: Working with Arrays in C++



Code for the assignment:
```cpp

// Name: Philip Jazmin
// Course: CISC 192 - C++ Programming
// Date: 11/2/2025
// Assignment: Non-Duplicated Integer Array Operations

#include <iostream>
#include <array>

using namespace std;
enum class operation_list{ascend = 1, descend = 2, largest = 3}; //used this to organize my operations

int main(){

cout << "Enter an array size: ";
int size; //caused diffuculty later with loops and arrays starting at 0
cin >> size;
cout << endl;
int* array = new int[size]; //i cant just declare size and then declare array[size] so i use pointer instead

    for(int i = 0; i < size; i++){ //loop for entering values
        cout<<"Element " << i + 1 << ": ";
        cin >> array[i];

        for(int j = 0; j < i; j++){ //loop to check if values preceding what was inputted was already in the array
            if(array[j] == array[i]){ //j maximum = i - 1
                do{
                cout << "Non unique entry! Please enter a unique value for Element " << i + 1 << ": ";
                cin >> array[i];
                }
                while(array[j] == array[i]); //post check for condition loop
            }
        }
    }

cout << endl;
cout << "Your array is: ";
    for(int i = 0; i < size; i++){ //just a loop to output what you put in
        cout << array[i] << " ";
    }

cout << endl;
cout << "Sort by ascending (1)" << endl;
cout << "Sort by descending (2)"<< endl;
cout << "Find largest (3)" << endl;
cout << "Enter an operation: ";

int operation;
cin >> operation;

int temp_array[2]; //i use this heavily for swapping values
    
    switch(static_cast<operation_list>(operation)){ //this is where size - 1 comes in, because array[size] is a uninitialized value
        case operation_list::ascend:
            for (int i = 0; i < size - 1; i++) { //reiterate comparison through all values
                for (int j = 0; j < size - 1; j++) {  //if you are comparing two values in a set, then you will compare n-1 times
                    if(array[j] > array[j + 1]) {  //if the left side of comparison is greater, swap it with right side
                        temp_array[0] = array[j]; 
                        temp_array[1] = array[j+1];
                        array[j] = temp_array[1];
                        array[j+1] = temp_array[0];
                    }
                }
            }
    cout << endl << "Your array in ascending order: "; 
        for(int i = 0; i < size; i++){
            cout << array[i] << " ";
        }
        break;

        case operation_list::descend: //also uses size - 1
            for (int i = 0; i < size - 1; i++) { 
                for (int j = 0; j < size-1; j++) {  //stops at j = size - 2 so convenient...
                    if(array[size-1-j] > array[size-2-j]){ //if right side is greater, then swap with value to the left
                        temp_array[1] = array[size-1-j];
                        temp_array[0] = array[size-2-j];
                        array[size-2-j] = temp_array[1];
                        array[size-1-j] = temp_array[0];
                }
            }
        }
    cout << endl << "Your array in decending order: ";
        for(int i=0; i < size; i++){
            cout << array[i] << " ";
        }    
        break;

        case operation_list::largest:
            for (int i = 0; i < size - 1; i++){ //if array[0] is less, then the next value takes it, nested loop not needed
                if(array[0] < array[i+1]){
                    array[0] = array[i+1];
                }
            }
    cout << endl << "The largest number in your array is: " << array[0] << endl;
        break;

        default:
            cerr << "Error with operation or inputting values, ending program" << endl; //i just combined the errors if you didnt input integers
            return 1; //error return value
    }

delete[] array;
//delete[] temp_array;
//i originally had this and it continued to run, but there was a warning from my compiler, so i omitted as a comment to be safe
return 0;
}
```
## 🎯 Objective
Practice working with arrays and basic control structures in C++. You will write a program that:
1. Accepts **unique integers** (no duplicates).  
2. Allows the user to **perform operations** on the array:
   - Sort the array (ascending or descending)  
   - Find the maximum number  

You will **not** use any library other than the ones specified.

---

## 🧠 Instructions

1. Create a C++ program that:
   - Declares a **fixed-size `std::array<int, N>`** (you can choose `N = 5` or any small number).
   - Prompts the user to **enter unique integers** (ensure no duplicates are allowed).
   - Displays a menu asking the user to perform one of the following operations:
     - **(a)** Sort the array in ascending order  
     - **(b)** Sort the array in descending order  
     - **(c)** Find the **maximum number**
   - Uses only **manual sorting logic** (e.g., nested loops).  
   - Displays the results clearly after the operation.

2. **Allowed headers only:**
   ```cpp
   #include <iostream>
   #include <array>
   ```

3. **Not allowed:**
   - `<algorithm>`
   - `<vector>`
   - `<set>` or any STL container other than `std::array`
   - Any other header files

---

## 🧩 Example Output

```
Enter 5 unique integers:
Element 1: 4
Element 2: 9
Element 3: 2
Element 4: 9
Duplicate found! Enter a different number.
Element 4: 6
Element 5: 3

Choose an operation:
1. Sort Ascending
2. Sort Descending
3. Find Maximum
Enter your choice: 1

Array sorted in ascending order:
2 3 4 6 9
```

---

## 💡 Hints
- Use **nested loops** for sorting (like bubble sort).
- Use a **`switch` statement** for menu selection.
- Keep your code modular and readable.

---

## 📦 Submission Requirements
- Submit the code in github in markdown format and share the link. No grading if the file is not formatted and uploaded correctly
- Make sure you add me as a collaborator in your repo. Add me with my email dkhan1010@gmail.com
- File name: `array_operations.md`
- Include your **name**, **course**, and **date** as comments at the top of the file.

```cpp
// Name: Your Full Name
// Course: CISC 192 - C++ Programming
// Date: MM/DD/YYYY
// Assignment: Non-Duplicated Integer Array Operations
```

---

## ✅ Grading Rubric

| Criteria | Points |
| :-- | --: |
| Correct implementation of unique array input | 20 |
| Sorting logic (ascending and descending) | 25 |
| Finding maximum element | 15 |
| Correct use of `<array>` and `<iostream>` only | 20 |
| Code readability and output clarity | 10 |
| Comments and documentation | 10 |
| **Total** | **100** |

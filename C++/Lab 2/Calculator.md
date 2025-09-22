# Lab: Menu-driven calculator 

Practice `if` chains vs. `switch`, input validation, and short-circuiting.

------

## Learning outcomes

By the end, students can:

- **Apply** `if`/`else` and `switch` to implement menu options.
- **Analyze** input to validate numeric values and reject errors.
- **Analyze** edge cases such as division by zero.
- **Apply** `enum class` for type-safe menu choices.
- **Analyze** conditions using short-circuiting and scope control.
- **Create** a complete interactive calculator integrating input, decisions, and arithmetic.

------

## Prerequisite

- Decision and switch statements

## What do you need to complete this exercise?

- Submit your responses in a Markdown file on GitHub, and include a brief reflection on the challenges you encountered during the lab.
- Ensure that all code included in the Markdown file runs without errors. Refer to [Submitting Your Assignment Using GitHub](https://sdccd-edu.zoom.us/rec/share/F4rK6ZABMXlRn4aGlZ9P005e-iRKwq8rr9KuawDoJ77TdkybKU2tpf4l4QSe113g.ut4jpVaqaPY0oI7b?startTime=1725121532000) for detailed instructions.
- Record a video of yourself explaining the code. Use a desktop or laptop to write and demonstrate the code, making sure that both your screen and your image are visible. If you do not have a laptop, you may borrow one from the library for the semester.

### Requirements

1. Show menu: add, subtract, multiply, divide, quit. Use `enum class` and `switch`.
2. Read two `double` operands with validation; reject non-numeric input.
3. For divide: detect division by zero using `if (b == 0)`; keep the program running.

## Challenges

Please describe the challenges you faced during the exercise.

```python
# I initially thought to cast string to number, but couldnt because switches only take numbers,

# so I instead opted to use the ascii values of each operation instead and cast them to integers.

# I had to look at precedence rules for gates when making if statement checking operations since

# I could not just separate the conditions with commas.

```

## Write code here

Copy your working code from an IDE (e.g., Visual Studio or any other you prefer) and enclose it between triple backticks (``` ) when submitting.

**Calculator.cpp**

```cpp
enum class operation_list{add=43,mult=42,sub=45,div=47};

int main()
    {
        double x,y,z{};
        char operation{};

        std::cout << "Calculator \ngive me a number \n"; 

        if (!(std::cin >> x)){
            std::cerr << "please enter a number next time \n";
            return 1;
        }
    
        std::cout << "give me the symbol of an operation (+, -, *, /) that you want to make\nyou can also quit by using 'q' \n";
        std::cin >> operation;

        if(operation == 'q'){
            std::cout << "quitting calculator... \n";
            return 0;
        }

        if(!(operation == '+' || operation == '*' || operation == '-' || operation == '/')){
            std::cerr << "you must enter a valid operation \n";
            return 2;
        }

        std::cout << "give me a number once more \n";
        if (!(std::cin >> y)){
            std::cerr << "please enter a number next time \n";
            return 3;
        }

    switch (static_cast<operation_list>((static_cast<int>(operation)))){
        case operation_list::add:
            z = x + y;
            std::cout << "your equation is: " << x << " + " << y << " = " << z;
            break;

        case operation_list::mult:
            z = x * y;
            std::cout << "your equation is: " << x << " * " << y << " = " << z;
            break;

        case operation_list::sub:
            z = x - y;
            std::cout << "your equation is: " << x << " - " << y << " = " << z;
            break;

        case operation_list::div:
            if (!(y==0))
                {
                    z = x / y;
                    std::cout << "your equation is: " << x << " / " << y << " = " << z; 
                }
            else 
                {
                    std::cerr << "you cannot divide by zero \n";
                    return 4;
                }
            break;

        default:
                std::cerr << "error with processing request\n";
                return 5;
    }

    return 0;
}

```

## Paste video link here

```
https://www.youtube.com/watch?v=6zsCze_XxqI
```

<br>
<br>
<br>
<br>

**End of exercise**

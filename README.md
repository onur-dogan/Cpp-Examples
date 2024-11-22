# Cpp-Examples
C++ Project with examples and notes from C++ How to Program (9th Edition) book. Also, it includes some extra examples, apart from this book.


**Some Quick Notes**
- `endl` manipulator inserts a **newline** and flushes the stream.
- **Header** files shouldn't include namespaces.
- **unsigned** keyword allows the variable to be only a positive. The integer can never be a negative value.
- `default_random_engine` - `srand` functions change the seed(starting point) of the random number generator algorithm.
- [`float (4)`, `long (4)`, `double (8)`, `long double (8)`](https://learn.microsoft.com/en-us/cpp/cpp/fundamental-types-cpp?view=msvc-170#sizes-of-built-in-types)
- Stack: LIFO, Queue: FIFO.
- The ampersand(&) is used in variable declarations to declare reference variable.
- **Overloaded Function**: Function overloading is a feature of OOP where the multiple functions with the same name has different parameter data types.
- **Temporary** is a construct that generates an ordinary type or function at compile time based on arguments the user supplies for the template parameters.
- **Performance Concern**: If the performance is important, then better to avoid using recursion functions. It takes more time and uses more memory. The deeper the recursion, the more memory is used. Because each recursive call requires its own stack frame to store variables and other information.
- `vector.insert()` and `vector.emplace` are used for the same purpose. However;
    - `emplace` constructs an object in place at a specified position, potentially **avoiding a copy operation**.
    - `insert` adds a **copy** of the object at the specified position.
- It is important to set a default value like `nullptr` to the pointers. It might cause critical issues to update a pointer that doesn't have a default value since the value might not point to a valid memory location.
- `lvalue` simply means an object that has an identifiable location in memory.
- `r-value` simply means, an object that has no identifiable location in memory.
- `char` array constants have a static storage duration (they exist throughout the program).
- The `~` operator is used to reverse operation on the bytes so it makes sense to use it for `destructor` function definitions like `~Destroy()`
- When a variable is declared as `static`, space for it gets allocated for the lifetime of the program. The space for the static variable is allocated only once.
- A `static` variable of a class, gets allocated once so it stores one value for each generated same type class. So, it isn't used to store special values for each class. It stores the class specific global variables.
- The `static` variable can't be defined with `const` since `const` keyword means that it can't change the objects in the function/class in which it is defined. However, the `static` variables are independent of the class objects
- Objects are created from the inside out and destroyed from the outside in via `destructor` functions.
- The `friend` class/function can access private and protected members of a class. The parameter object that references the class must be a constant. 
    - `friend` functions in the class have permission to access any property(public/protected/private) of the class which it is defined
    - `friend` class have permission to access public/private/protected members of other classes in which it is declared as a friend 
- Using `this->` is same with `(*this).`. Because the dot(.) operator is prioritized higher than the asterisk(*) operator, it is necessary to use parentheses.
- The operators can be overloaded to customize some functionalities. It is like overloading the `<<` operator to print a text specifically by the class requirements or the `++` operator to update a character in the text instead of increasing the number.
- `struct` keyword allows us to create structures. Structures are a way to group several related variables into one place like an object and can contain different data types:
    ```c++
    struct {
        int num;
        string text;
        ...
    }
    ```
- A memory leak occurs when new memory is allocated dynamically and never deallocated. In `C` programs, new memory is allocated by the `malloc` or `calloc` functions, and deallocated by the `free` function. In C++, new memory is usually allocated by the `new` operator and deallocated by the `delete` or the `delete []` operator. The list variables should be deallocated by the `delete []` since it guarantees to call all of the elements in the list. Similarly, use `delete` to deallocate the memory that is defined as a single element. Using `delete []` to deallocate the single memorized element is undefined. 
- `friend` functions can't be inherited in C++. If the base class has any friend function, this function doesn’t become the friend of the derived class.
- To `override` an inherited function in the derived class, define the same function prototype with `override` keyword. Also, the base class must be declared as a `virtual` function to enable dynamic overriding.
- `virtual` functions cannot be `static` but can be a `friend` function of another class.
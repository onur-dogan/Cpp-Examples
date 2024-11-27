# Cpp-Examples
The C++ Project includes some examples and notes (mostly C++11). It also includes some additional examples/notes from the C++ How to Program (9th Edition) book.


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
    struct str {
        int num;
        string text;
        ...
    }
    ```
- A memory leak occurs when new memory is allocated dynamically and never deallocated. In `C` programs, new memory is allocated by the `malloc` or `calloc` functions, and deallocated by the `free` function. In C++, new memory is usually allocated by the `new` operator and deallocated by the `delete` or the `delete []` operator. The list variables should be deallocated by the `delete []` since it guarantees to call all of the elements in the list. Similarly, use `delete` to deallocate the memory that is defined as a single element. Using `delete []` to deallocate the single memorized element is undefined. 
- `friend` functions can't be inherited in C++. If the base class has any friend function, this function doesn’t become the friend of the derived class.
- `Polymorphism` means having multiple forms. To adapt `polymorphism` in inherited classes, `override` an inherited function in the derived class by defining a function with the same prototype of the overridden function and using `override` keyword. 
- When declaring a function with `override` keyword, the compiler checks whether the base class has the same function that has the same signature(same name, parameters). If it doesn't exist, then the compiler shows error. Also, the base class must be declared as a `virtual` function to enable dynamic overriding.
- `virtual` functions cannot be `static` but can be a `friend` function of another class. Also, the constructors can't be defined as `virtual` cause virtual pointer doesn't define when the constructor of the class is executed.
- About the difference between `virtual` and `abstract` functions, the `virtual` function must have a base functionality(body) so, it provides the derived classes with the option of overriding it. However, this is not mandatory. When it is not overridden, it uses the base function that is defined as default. However, the `abstract` function is defined without any functionality(body) as default so it has to be overridden by the (non-abstract) subclasses. This override process is mandatory unlike the `virtual` functions.
- `final` specifier is used to prevent overriding of a virtual function. 
- If a class that is defined with a `final` specifier, can't be a base class. So, the classes with `final` specifier, don't allow inheritance. 
- For the inherited classes;
    - When an object of the **derived class** is created, the constructor of the **base class** executes first. Then, the constructor of the **derived class** executes. If there is a deeper inheritance hierarchy, then this flow executes in the same order **(cascade)**.
    - In the opposite way, when the **derived class's object** is destroyed, the destructors are called in the **reverse order of the constructors**. So, the destructor function of the derived class executes first, followed by execution of the destructor of the base class.
- One of the advantages of OOP is code reuse. There are two ways we can do code reuse either by the implementation of inheritance (`is-a` relationship), or object composition (`has-a` relationship)
    - A `is-a` relation is based on inheritance. For example, **Car** (derived) class has `is-a` relation with the **Vehicle** (base) class. In short, the **Car** class is a sub-class of **Vehicle** class, so it can be described similarly as `Car class is a (subclass of) Vehicle class`.
    - A `has-a` relation is based on composition. For example, **Car** class has `has-a` relation with the `Wheel` and `Brakes` classes. In short, **Wheel** and **Brakes** are parts of a **Car**, so it can be described similarly as `Car has wheel and brakes`.
- `typeid` operator returns the runtime type information of the parameter like a data type. For a class defined variable, it returns the information of the class (e.g. `typeid(...).name()` returns the class name).
- The `typedef` keyword is used to create customized data types with aliased names. For example;
    - `istream` type definition represents the `basic_istream<char>` template customization. `typedef` keyword is used like `typedef basic_istream<char> istream;`
    - `ostream` type definition represents the `basic_istream<char>` template customization. `typedef` keyword is used like `typedef basic_ostream<char> ostream;`
    - A customized `pointer` definition could be defined like `typedef Person * personPtr;`
    - A customized `vector` definition could be defined like `typedef std::vector<Person> vPerson;`
    - A customized `vector pointer` definition could be defined like `typedef std::vector<Person *> vPersonPtr;`
    - A customized `function` definition could be defined like `typedef void (* personFunctionPtr)(std::char, int);`
- The `string_view` template specialization provides an efficient way to pass a **read-only(constant)**, **exception-safe**, **non-owning handle** to the character data of any string. It is optimized for the constant string operations. For example, when declaring constant(enum) strings that shouldn't be modified anywhere, it is a good choice.
- `constexpr` keyword improves program performance by computing at compile time rather than run time. Unlike `const`, `constexpr` can also be applied to **functions** and **class** constructors.
- `boolalpha` manipulator formats and displays the `boolean` variables in text format (`true` for `1`, and `false` for `0`). Using `noboolalpha` manipulator disables this feature so it displays as `1` or `0` as in normal.
- `showpoint` manipulator is used to show(fill) the zeros of the decimal value. So, the variable could be displayed in a certain length. For example, a float variable with the `2.300` value shows as `2.3` in normal. By setting the `showpoint` manipulator, it shows as `2.30000`. Setting the `precision` function declares how many characters will be displayed in total, so the zeros could be limited. After setting `setprecision(5)`, it shows as `2.3000`. On the other hand, using the `noshowpoint` manipulator disables this feature, so the decimal point is only displayed for numbers whose decimal part is not zero as in normal.
- `scientific` manipulator is used to display the numbers in scientific notations.
- `cin.fail()` method is used to check whether the entered input type is the same as the variable type. If it's not in the same data type, it returns 1. Otherwise, returns 0.
- `#define` **preprocessor** directive is used to define a `macro`(constant). `Macros` are a way to represent a fragment of code or a constant value by giving it a name. When the **preprocessor** encounters the `macro` name in the code, it replaces it with the corresponding code fragment or value that is defined using the #define **preprocessor**.
- `std::ofstream` **(Output File Stream)** is used to write into files. `std::ifstream` **(Input File Stream)** is used to read the data from a file.
- `std::ios::app` writes the new lines to the end of the file. So, the previous data in the file remains.
- `std::ios::out` opens file for writing and deletes the previous data in the file. It writes the new data instead.
- `std::ios::in` opens file for reading and allows inputs from the stream to get the data in the file.
- `std::ios::binary` opens the file in binary mode. 
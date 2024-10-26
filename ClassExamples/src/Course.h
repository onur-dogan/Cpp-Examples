#include <iostream>
// Need to define the used types in the header file to be able to use them in file. 
// This informs the compiler to decide how much memory should be allocated.
// Also, we would hide the class property details from the client code
#include <string>

// ** Header files shouldn't include namespaces. **
class Course
{
private:
    // Define variables that will be private and be able to be used in the class functions only
    std::string courseName;

public:
    // Set course name as default in explicit(constructor)
    // It is mostly good to define a default variable in constructur instead of waiting to set a value to the variables
    explicit Course(std::string);
    // Setter function that changes variables 
    void setCourseName(std::string);
    // Getter function that returns the variables
    std::string getCourseName() const;
    // Displays some outputs according to the definitions in cpp file
    void displayCourseName() const;
};

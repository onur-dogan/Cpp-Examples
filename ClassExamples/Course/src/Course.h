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
    std::string courseInstructor;
    // Limit variable to store a limited string
    int courseNameLimit;

public:
    // Set course name as default in explicit(constructor)
    // It is mostly good to define a default variable in constructur instead of waiting to set a value to the variables
    explicit Course(std::string, std::string, int);
    // *** Setter Functions ***
    // Set course name variable
    void setCourseName(std::string);
    // Set course instructor variable
    void setCourseInstructor(std::string);

    // *** Getter Functions ***
    // Get course name
    std::string getCourseName() const;
    // Get course instructor
    std::string getCourseInstructor() const;
    // Get course name's character length
    int getCourseNameLength() const;

    // Displays some outputs according to the definitions in cpp file
    void displayCourseName() const;
    // Displays course instructor information
    void displayCourseInstructor() const;
};

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
#include <vector>
/**
 * See: https://www.boost.org/doc/libs/1_72_0/libs/range/doc/html/range/reference/adaptors/reference/indexed.html
 * Used {
 *  boost::adaptors::indexed
 * }
 */
#include <boost/range/adaptor/indexed.hpp>

#include "constants.hpp"

// Macros (Constants)
#define DOCS_FOLDER_PATH "docs/"
#define EXTENSION ".txt"

// *** File Processing Examples ***

struct OptionStructure
{
    std::string desc;
    void (*function)();
};
typedef std::vector<OptionStructure> vOption;

struct PersonStructure
{
    std::string name;
    std::string surName;
    int age;
};

// Function definitions
// Main helpers
inline OptionStructure getOptionModel(void (*function)()) noexcept;
inline void displayOptions(vOption &);
vOption getOptions() noexcept;
inline const void clearInputStream();

inline std::string getEnteredFileName();
inline std::string prepareFilePath(std::string);
inline void outputLine(PersonStructure);
inline void outputTitle(std::string[]);

// Main
void writeFile();
void readFile();

// Main function
int main()
{
    std::cout << "Enter the number of the function which you would like to run: "
              << "(Type '" << std::cin.eof() << "' to end the process)"
              << std::endl;

    vOption options = getOptions();

    for (unsigned int i = 0; i < options.size(); i++)
    {
        // Assign the descriptions from the constant texts
        options[i].desc = Constants[i];

        // Display the options
        std::cout << (i + 1) << ". " << options[i].desc << std::endl;
    }

    int selection;
    while (std::cin >> selection && selection != EOF)
    {
        // Don't allow to enter an integer that causes any error
        if (selection < 0 || selection > options.size())
        {
            std::cout << "Unavailable number to run any function. Please make sure you entered an available number:" << std::endl;
            continue;
        }

        // If the user types 0, print the menu again
        if (selection == 0)
        {
            displayOptions(options);
            continue;
        }

        // Show selected option information
        std::cout << "\nSelected option is: "
                  << selection << ". " << options[selection - 1].desc
                  << "\nThe function is running...\n"
                  << std::endl;

        // Run the related function
        options[selection - 1].function();
        // Clear stream
        clearInputStream();

        // After the related function is completed, show the final explanations
        std::cout << "\nRun another function by entering its number. Type '0' to see the menu again. Type '"
                  << EOF
                  << "' to end the process.\n"
                  << std::endl;
    }
    writeFile();
    readFile();
}

inline std::string getEnteredFileName()
{
    std::string fileName;
    std::cout << "Enter the file name you would like to update/create: " << std::endl;
    std::cin >> fileName;

    if (std::cin.fail())
        throw std::invalid_argument("The entered file name must be a string!");

    return fileName;
}

inline std::string prepareFilePath(std::string fileName)
{
    return DOCS_FOLDER_PATH + fileName + EXTENSION;
}

void writeFile()
{
    std::string fileName = getEnteredFileName();
    std::string filePath = prepareFilePath(fileName);
    /**
     * std::ios::app writes the new lines to the end of the file. So, the previous data in the file remains
     * std::ios::out deletes the previous data in the file and writes the new data instead
     * std::ios::in allows inputs from the stream to get the data in the file
     */
    std::ofstream outputFile(filePath, std::ios::app);
    if (!outputFile)
    {
        throw std::invalid_argument("The related file couldn't opened/created! Try again...");
        exit(EXIT_FAILURE);
    }

    std::cout << "Enter name surname and age in a line and same order for each person. (Enter Ctrl+Z or Ctrl+C to end the process)" << "\n?";

    PersonStructure personStr;
    while (std::cin >> personStr.name >> personStr.surName >> personStr.age)
    {
        outputFile << personStr.name << ' ' << personStr.surName << ' ' << personStr.age << std::endl;
        std::cout << '?';
    }

    // The ofstream's destructor already closes the file but it is good to close it manually too as an extra example
    outputFile.close();
}

inline void outputLine(PersonStructure personStr)
{
    std::cout << std::left << std::setw(20) << personStr.name
              << std::setw(20) << personStr.surName
              << std::right << personStr.age
              << std::endl;
}

inline void outputTitle(std::string titles[])
{
    std::cout << std::left << std::setw(20) << titles[0]
              << std::setw(20) << titles[1]
              << std::right << titles[2]
              << std::endl;
}

void readFile()
{
    std::string fileName = getEnteredFileName();
    std::string filePath = prepareFilePath(fileName);

    std::ifstream inputFile(filePath, std::ios::in);
    if (!inputFile)
    {
        throw std::invalid_argument("The related file couldn't opened/created! Try again...");
        exit(EXIT_FAILURE);
    }

    std::cout << "*** The Data in the " << fileName + EXTENSION << " file ***" << std::endl;

    // Print titles
    std::string titles[3]{"Name", "Surname", "Age"};
    outputTitle(titles);

    // Print each line in the file
    PersonStructure personStr;
    while (inputFile >> personStr.name >> personStr.surName >> personStr.age)
        outputLine(personStr);

    // The ofstream's destructor already closes the file but it is good to close it manually too as an extra example
    inputFile.close();
}

inline const void clearInputStream()
{
    // Ignore and clear the input stream to prevent the conflicts situations between this and the below input stream
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.clear();
}

inline OptionStructure getOptionModel(void (*function)()) noexcept
{
    return OptionStructure{
        function : function
    };
}

vOption getOptions() noexcept
{
    std::vector<OptionStructure> options{
        // Write into a file that has been created or create a new file and write into it
        getOptionModel(writeFile),
        // Read data in a file and show the data on the terminal
        getOptionModel(readFile)};

    return options;
}

inline void displayOptions(vOption &options)
{
    for (const auto &option : options | boost::adaptors::indexed(1))
        std::cout << option.index() << ". " << option.value().desc << std::endl;
}
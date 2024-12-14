// Time.h

// It prevents the library's header files to be defined multiple times.
// So, that means if the TIME_H class wasn't defined before, it defines the code between ifndef and endif to the header.
// Otherwise, it does nothing with the duplicated header file since the ifndef condition isn't fulfilled.
#ifndef TIME_H
#define TIME_H

namespace timeClass
{
    class Time
    {
    public:
        // Default constructor. It sets the default values automatically and avoids any issue
        Time();
        Time(int);
        Time(int, int);
        Time(int, int, int);

        // *** Destructor ***
        // The `~` operator is used to reverse operation on the bytes so it makes sense to use it for destructor function definitions
        ~Time();

        /**
         * NOTES:
         *
         * Any one of the functions shouldn't return the reference of the private fields!
         * Otherwise, they would be available to be updated and it causes different problems in the system
         * Only the functions in this class must have availability to update fields that belong to this class
         * And the setter functions take this responsibility
         *  */

        // Setter functions to set private fields
        void setTime(int, int, int);
        void setHour(int);
        void setMinute(int);
        void setSecond(int);

        // Getter functions to set private fields
        unsigned int getHour() const;
        unsigned int getMinute() const;
        unsigned int getSecond() const;

        // Display functions
        void showTime() const;

    private:
        unsigned int hour;
        unsigned int minute;
        unsigned int second;
    };
}

#endif
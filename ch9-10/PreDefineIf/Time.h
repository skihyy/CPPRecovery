// prevent multiple inclusions of header files
#ifndef TIME_H
#define TIME_H

class Time
{
    private:
        int hour; // 0 - 23
        int minute; // 0 - 59
        int second; // 0 - 59

    public:
        Time();
        void setTime(int, int, int);
        void printUniversal();
        void printStandard();
};

#endif

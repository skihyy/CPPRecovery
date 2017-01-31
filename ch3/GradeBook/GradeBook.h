#include<string>
using std::string;

class GradeBook
{
    public:
        GradeBook( string );
        void setCourse( string );
        string getCourse();
        void displayMessage();
    private:
        string course;
};


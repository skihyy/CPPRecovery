#include<string>
using std::string;

class Invoice
{
    private:
        string seriesNo;
        string description;
        int numOfSold;
        int price;
    public:
        Invoice(string, string, int, int);
        int getAmount();
        void setSeriesNo(string);
        string getSeriesNo();
        void setDescription(string);
        string getDescription();
        void setNumOfSold(int);
        int getNumOfSold();
        void setPrice(int);
        int getPrice();
};

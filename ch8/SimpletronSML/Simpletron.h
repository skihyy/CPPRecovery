class Simpletron
{
private:
    static const int rowSize = 100;
    static const int colSize = 3;
    // registers[row][0] -> +/-
    // registers[row][1] -> cmd
    // registers[row][2] -> pos
    int registers[rowSize][colSize];
    int addMachine;

    bool startProgram ( );
    bool takeCmd ( const int, const int );
    bool read ( const int );
    bool write ( const int );
    bool load ( const int );
    bool store ( const int );
    bool add ( const int );
    bool substract ( const int );
    bool devide ( const int );
    bool multiply ( const int );
    bool branch ( const int );
    bool branchNeg ( const int );
    bool branchZero ( const int );
    int getData ( const int );
    void storeOneOrder ( int, const int );

public:
    // IO
    static const int READ = 10; // keyboard -> register
    static const int WRITE = 11; // register -> screen

    // W/R
    static const int LOAD = 20; // register -> add machine
    static const int STORE = 21; // add machine -> register

    // mathematics
    static const int ADD = 30; // add machine + register -> add machine
    static const int SUBSTRACT = 31; // add machine - register -> add machine
    static const int DEVIDE = 32; // add machine / register -> add machine
    static const int MULTIPLY = 33; // add machine * register -> add machine

    // control order
    static const int BRANCH = 40; // move to a pointed position in register
    static const int BRANCHNEG = 41; // if adding machine is negative, move to a pointed position in registe
    static const int BRANCHZERO = 42; // if adding machine is zero, move to a pointed position in registe
    static const int HALT = 43; // stop - program is finished

    Simpletron ( );

    bool takeProgram ( const int *, const int );
    bool debug ( const int, const int );
    void displayDetails ( );
    bool cleanAll ( );
};

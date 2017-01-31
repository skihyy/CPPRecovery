class Account
{
    private:
        float amount;
    public:
        Account( float );
        void debit( float );
        void credit( float );
        float getBalance();
};

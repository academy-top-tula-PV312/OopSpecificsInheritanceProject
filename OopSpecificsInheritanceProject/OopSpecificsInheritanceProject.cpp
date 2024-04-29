#include <iostream>

class Base
{
private:
    int value_private;
protected:
    int value_protected;
public:
    int value_public;
};

class PublicDerived : public Base
{  
private:
    void method()
    {
        value_protected; // prodected
        value_public;    // public
    }
protected:
public:
};

class PrivateDerived : private Base
{
private:
    void method()
    {
        value_protected; // private
        value_public;    // private
    }
protected:
public:
};

class PrivateDerived : protected Base
{
private:
    void method()
    {
        value_protected; // protected
        value_public;    // protected
    }
protected:
public:
};

int main()
{
    
}


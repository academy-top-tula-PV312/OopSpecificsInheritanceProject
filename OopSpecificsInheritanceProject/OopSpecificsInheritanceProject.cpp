#include <iostream>

class Base
{
private:
    int value_private;
protected:
    int value_protected;
public:
    int value_public;
    virtual void Method() { std::cout << "Base\n"; }
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

//class PrivateDerived : protected Base
//{
//private:
//    void method()
//    {
//        value_protected; // protected
//        value_public;    // protected
//    }
//protected:
//public:
//};



class DerivedA : public Base
{
public:
    void Method() { std::cout << "Derived A\n"; }
};

class DerivedB : public DerivedA
{
public:
    //void Method() { std::cout << "Derived B\n"; }
};

class DerivedC : public DerivedB
{
public:
    //void Method() { std::cout << "Derived C\n"; }
};


class Gaget
{
protected:
    std::string name;
public:
    Gaget(std::string name) : name{ name }
    { 
        std::cout << "Gaget " << this << "\n"; 
    }
    virtual void NamePrint()
    {
        std::cout << "Gaget name: " << name << "\n";
    }
};

class Printer : public Gaget
{
public:
    Printer(std::string name) : Gaget(name)
    { 
        std::cout << "Printer " << this << "\n"; 
    }
    void Work() { std::cout << "Print\n"; }
    void NamePrint() override
    {
        std::cout << "Printer name: " << name << "\n";
    }
};

class Scaner : public Gaget
{
public:
    Scaner(std::string name) : Gaget(name)
    { 
        std::cout << "Scaner " << this << "\n"; 
    }
    void Work() { std::cout << "Scan\n"; }
    void NamePrint() override
    {
        std::cout << "Scaner name: " << name << "\n";
    }
};

class Mfu : public Printer, public Scaner
{
public:
    Mfu(std::string namePrinter, std::string nameScaner) 
        : Printer(namePrinter), Scaner(nameScaner)
    { 
        std::cout << "Mfu " << this << "\n"; 
    }
    void NamePrint() override
    {
        std::cout << "Mfu name: " << Scaner::name << "\n";
    }
};


int main()
{
    Base* basePtr = new Base();
    basePtr->Method();

    basePtr = new DerivedA();
    basePtr->Method();

    basePtr = new DerivedC();
    basePtr->Method();

    Mfu mfu;
    mfu.Scaner::Work();
    mfu.Printer::Work();
   
}


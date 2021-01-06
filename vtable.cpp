

using namespace std;

#include <iostream>

class Base
{
public:
    int i, j;

    virtual void fun()
    {
        cout << "Base fun \n";
    }

    void gun()
    {
        cout << "Base gun \n";
    }

    virtual void sun()
    {
        cout << "Base sun\n";
    }
};

class Derived : public Base
{
public:
    int x, y;

    void fun()
    {
        cout << "Derived fun\n";
    }

    virtual void gun()
    {
        cout << "Derived gun\n";
    }

    virtual void run()
    {
        cout << "Derived run\n";
    }
};

int main()

{
    Base bobj;
    Derived dobj;
    cout << sizeof(bobj) << "\n";
    cout << sizeof(dobj) << "\n";

    long int *op = (long int *)(&dobj);

    cout << "Base address of dobj is:" << op << "\n";

    long int *vptr = (long int *)(*op);

    cout << "Address of V-Table is:" << vptr << "\n";

    void (*fp)(); //funtion pointer

    fp = (void (*)())(*vptr);

    fp();

    cout << "Fp is currently pointing to the Address :" << fp << "\n";
    fp = (void (*)())(*(vptr + 1));

    fp();
    cout << "Fp is currently pointing to the Address :" << fp << "\n";

    fp = (void (*)())(*(vptr + 2));

    fp();
    cout << "Fp is currently pointing to the Address :" << fp << "\n";
    return 0;
}
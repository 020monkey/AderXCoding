#include <iostream>

class Base
{
public:

    virtual void f(float x)
    {
        std::cout << "Base::f(float) " << x <<std::endl;
    }

    void g(float x)
    {
        std::cout << "Base::g(float)" <<x <<std::endl;
    }

    void h(float x)
    {
        std::cout << "Base::h(float)" <<x <<std::endl;
    }
};



class Derived : public Base
{

public:

    //  �����麯������, ����Derived::f(float)������Base::f(float)
    virtual void f(float x)
	{
    	std::cout << "Derived::f(float)" <<x <<std::endl;
    }

    // ����Derived::g(int)������Base::g(float)�����������ء�
    void g(int x)
	{
    	std::cout << "Derived::g(int)" <<x <<std::endl;
    }

    // ����Derived::h(float)������Base::h(float)�������Ǹ��ǡ�
    void h(float x)
	{
    	std::cout << "Derived::h(float)" <<x <<std::endl;
    }

};



int main(void)

{
    Derived d;

    Base *pb = &d;

    Derived *pd = &d;

    // Good : behavior depends solely on type of the object

    pb->f(3.14f); // Derived::f(float) 3.14

    pd->f(3.14f); // Derived::f(float) 3.14



    // Bad : behavior depends on type of the pointer

    pb->g(3.14f); // Base::g(float) 3.14

    pd->g(3.14f); // Derived::g(int) 3        (surprise!)



    // Bad : behavior depends on type of the pointer

    pb->h(3.14f); // Base::h(float) 3.14      (surprise!)

    pd->h(3.14f); // Derived::h(float) 3.14

}

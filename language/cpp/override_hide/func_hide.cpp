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

    // function override
    // virtual void Base::f(float)
    // virtual  void Derived::f(float)
    pb->f(3.14);
    d.f(3.14);
    d.Base::f(3.14);

    // function hide
    // virtual void Base::g(float)
    // virtual  void Derived::g(int)
    pb->g(3.14);
    d.g(3.14);
    d.Base::g(3.14);

    pb->g(256);
    d.g(256);
    d.Base::g(256);

    // function hide
    // virtual void Base::h(float)
    // virtual  void Derived::h(float)
    pb->h(3.14);
    d.h(3.14);
    d.Base::h(3.14);

    return 0;
}

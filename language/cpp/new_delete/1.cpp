#include <iostream>

class A
{
public :
    A()
    :m_a(100)
    {

    }
    int m_a;
};


class T
{
public :

    int m_a;

};

int main( )
{
    int a( );           //  ��������
    A aa();             //  ��������������


    //  A�ж�����Ĭ�Ϲ��캯��
    //  ���new A �� new A()
    A *pa1 = new A;
    std::cout <<pa1->m_a <<std::endl;

    A *pa2 = new A();
    std::cout <<pa2->m_a <<std::endl;

    //  T��δ����Ĭ�Ϲ��캯��
    T *pt1 = new T;
    std::cout <<pt1->m_a <<std::endl;   //  ���ֵ

    T *pt2 = new T( );
    std::cout <<pt2->m_a <<std::endl;   //  ���ݱ���ʼ��
    return EXIT_SUCCESS;
}

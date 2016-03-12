#include <iostream>

class Base
{
public :
    Base( )
    {
        //std::cout <<"default constructor..." <<std::endl;
        this->m_data = '\0';
    }

    Base(char data)
    {
        //std::cout <<"simple constructor..." <<std::endl;
        this->m_data = data;
    }

    Base(const Base &base)
    {
        std::cout <<"copy constructor..." <<std::endl;
        this->m_data = base.m_data;
    }

protected :

    char m_data;
};


//  ����ΪBase����
void Func(const Base base)
{
}

//  ����ֵΪbase����
Base Func( )
{
    Base base;

    return base;
}

void Copy()
{
    Base b1;
    Base b2 = b1;

}

int main(void)
{
    Base base(10);

    std::cout  <<std::endl <<"����ΪBase����..." <<std::endl;
    Func(base);     //  �Ż�δ�Ż�����¾�����1�ο������캯��

    std::cout  <<std::endl <<"����ֵΪbase����[�ɱ��Ż�]..." <<std::endl;
    Func();     //  �Ż�����µ���0��, δ�Ż�����µ���1��[��������ʱ����]

    Base b = Func();     //  �Ż�����µ���0��, δ�Ż�����µ���2��[��������ʱ���� + ��ʼ������bʱ����]


    std::cout  <<std::endl <<"��base�����ʼ������һ������..." <<std::endl;
    Copy();     //  �Ż�δ�Ż�����¾�����1�ο������캯��

    return 0;
}

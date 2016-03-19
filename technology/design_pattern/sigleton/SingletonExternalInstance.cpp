#include <iostream>


class Singleton
{
public :
    static Singleton* GetInstancePoint( )           // ��ȡ��������ָ��
    {
        return const_cast<Singleton *>(Singleton::m_singleton);
    }

    static void DestroyInstance( )                  // ���ٵ�������Ŀռ�
    {
        if(Singleton::m_singleton != NULL)
        {
            delete Singleton::m_singleton;
            Singleton::m_singleton = NULL;
        }
    }
private :
    Singleton( )                                // ���캯��[������]
    {
    }

    Singleton(const Singleton &singleton)       // ��ֵ���캯��[������]
    {

    }

    ~Singleton( )                               // ��������
    {

    }

    static Singleton *m_singleton;                // ָ���������ָ��
};




///////////
Singleton* Singleton::m_singleton = new Singleton( );                // ָ���������ָ��
///////////


int main()
{
    Singleton *sp1 = Singleton::GetInstancePoint( );
    Singleton *sp2 = Singleton::GetInstancePoint( );

    std::cout <<(sp1 == sp2) <<std::endl;

    Singleton::DestroyInstance( );

    return 0;
}

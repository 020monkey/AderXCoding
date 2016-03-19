#include <iostream>

class Singleton
{
public :
    static Singleton* GetInstancePoint( )           // ��ȡ��������ָ��
    {
        return const_cast<Singleton *>(Singleton::m_singleton);
    }
private :
    Singleton( )                                // ���캯��[������]
    {
        std::cout <<"default constructor..." <<std::endl;

    }

    Singleton(const Singleton &singleton)       // ��ֵ���캯��[������]
    {
        std::cout <<"copy constructor..." <<std::endl;
    }

    ~Singleton( )
    {
    }


    static Singleton *m_singleton;                // ָ���������ָ��


    class GC
    {
      public :
        ~GC( )
        {
            if (Singleton::m_singleton != NULL)
            {
                std::cout<< "here destroy the m_singleton..." <<std::endl;
                delete m_singleton;
                m_singleton = NULL ;
            }
        }
        static GC gc;
    };
};


Singleton* Singleton::m_singleton = new Singleton( );
Singleton::GC Singleton::GC::gc;

int main()
{
    Singleton *sp1 = Singleton::GetInstancePoint( );
    Singleton *sp2 = Singleton::GetInstancePoint( );

    std::cout <<(sp1 == sp2) <<std::endl;

    return 0;
}

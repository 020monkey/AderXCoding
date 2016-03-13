#include <iostream>


class Singleton
{
public :
    static Singleton* GetInstance( )   // ��ȡ��������ָ��
    {
        if(Singleton::m_singleton == NULL)   // �����������û�д����� ���䴴��
        {
            Singleton::m_singleton = new Singleton( );
        }

        return Singleton::m_singleton;
    }

    static void DestroyInstance( )  // ���ٵ�������Ŀռ�
    {
        if(Singleton::m_singleton != NULL)
        {
            delete Singleton::m_singleton;
            Singleton::m_singleton = NULL;
        }
    }

private :
    Singleton( )// ���캯��[������]
    {
    }

    Singleton(const Singleton &singleton)   // ��ֵ���캯��[������]
    {
    }


    static Singleton *m_singleton;// ָ���������ָ��
};

////////////////////
Singleton* Singleton::m_singleton = NULL;// ָ���������ָ��
////////////////////



int main()
{
Singleton *sp1 = Singleton::GetInstance( );
Singleton *sp2 = Singleton::GetInstance( );

std::cout <<(sp1 == sp2) <<std::endl;   // ��������ĵ�ַ����ͬ��

Singleton::DestroyInstance( );

return 0;
}

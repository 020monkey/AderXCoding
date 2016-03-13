#include <iostream>


class Singleton
{
public :
    static Singleton* GetInstance( )           // ��ȡ��������ָ��
    {
        // �˴�����������m_Instance == NULL���жϣ�
        // �ǽ����Java�ĵ���ģʽʵ��ʱ��
        // ʹ�õ���ν�ġ�˫���������ơ�
        // ��Ϊ����һ�μ����ͽ�������Ҫ������Ӧ�Ĵ��۵ģ�
        // �����������жϣ��Ϳ��Ա����μ��������������
        // ͬʱҲ��֤���̰߳�ȫ
        if(Singleton::m_singleton == NULL)          //
        {
            Lock( );            // �˴����Ե�������������̣߳������Լ�ʵ��һ��
            if(Singleton::m_singleton == NULL)       // �����������û�д����� ���䴴��
            {
                Singleton::m_singleton = new Singleton( );
            }
            Unlock( );      // �˴����Ե�������������̣߳������Լ�ʵ��һ��
        }
        return Singleton::m_singleton;
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

int main()
{
    Singleton *sp1 = Singleton::GetInstance( );
    Singleton *sp2 = Singleton::GetInstance( );

    std::cout <<(sp1 == sp2) <<std::endl;

    Singleton::DestroyInstance( );

    return 0;
}

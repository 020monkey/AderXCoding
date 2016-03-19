#include <iostream>

////////////////////////////////////////////////////////////////////////////////
// ���Ĳ�Ʒ����  -=> ��Ӧ�ڳ����Ʒ��ɫ
class SingCore
{
public :
    virtual ~SingCore( ){ };        // ����������

    virtual void Show( ) = 0;       // ��Ʒ��ʾ����
};


// ���Ĳ�ƷA  -=> ��Ӧ�ھ����Ʒ��ɫ
class SingCoreA : public SingCore
{
public :
    virtual ~SingCoreA( ){ };       // ����������

    void Show( )        // ��Ʒ��ʾ����
    {
        std::cout <<"SingCore A..." <<std::endl;
    }
};

// ���Ĳ�ƷB  -=> ��Ӧ�ھ����Ʒ��ɫ
class SingCoreB : public SingCore
{
public :
    virtual ~SingCoreB( ){ };       // ����������

    void Show( )            // ��Ʒ��ʾ����
    {
        std::cout <<"SingCore B..." <<std::endl;
    }
};
////////////////////////////////////////////////////////////////////////////////
//
//
//
//
////////////////////////////////////////////////////////////////////////////////
// �����Ļ��� -=> ��Ӧ�ڳ��󹤳���ɫ
class Factory
{
public:
    virtual ~Factory( ){ };         // ����������

    virtual SingCore* CreateSingCore( ) = 0;    // ������Ʒ��������

};

// ��������A�Ĺ��� -=> ��Ӧ�ھ����Ʒ��ɫ
class FactoryA : public Factory
{
public :
    virtual ~FactoryA( ){ };            // ����������

    SingCoreA* CreateSingCore( )
    {
        return new SingCoreA( );
    }
};


// ��������B�Ĺ��� -=> ��Ӧ�ھ����Ʒ��ɫ
class FactoryB : public Factory
{
public :
    virtual ~FactoryB( ){ };            // ����������

    SingCoreB* CreateSingCore( )
    {
        return new SingCoreB( );
    }
};

int main( )
{
    Factory *factoryA = new FactoryA( );
    factoryA->CreateSingCore( )->Show( );

    Factory *factoryB = new FactoryB( );
    factoryB->CreateSingCore( )->Show( );

    return 0;
}

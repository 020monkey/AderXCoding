#include <iostream>

//����������
// ��Ӧ�� -=> ���󹹼���Component����ɫ
class Pad
{
public:
    Pad(){ }
    virtual ~Pad(){ }
    virtual void Show( ) = 0;
};


// ���幹����Concrete Component����ɫ
class IPad : public Pad
{
public :
    IPad( ){ }
    virtual ~IPad( ){  };

    void Show( )
    {
        std::cout <<"�µ�Ipad Mini..." <<std::endl;
    }
};


// װ�Σ�Decorator����ɫ��
class Decorator : public Pad

{
public :
    Decorator(Pad *pad)
    {
        m_pad = pad;
    }
    virtual ~Decorator( ){ };

    void Show( )
    {
        this->m_pad->Show( );       // չʾһ���Լ����ֻ�
    }

protected:
    Pad *m_pad;

    virtual void AddDecorator( ) = 0;

};

// ����װ�Σ�Concrete Decorator����ɫ
class CoverDecorator : public Decorator
{
public :
    CoverDecorator(Pad *pad)
    :Decorator(pad)
    {
    }

    virtual ~CoverDecorator( ){ }

    void Show( )
    {
        this->AddDecorator( );
        Decorator::Show( );
    }

protected:
    void AddDecorator( )
    {
        std::cout <<"Ū�˸�������";
    }

};

// ����װ�Σ�Concrete Decorator����ɫ
class FoilDecorator : public Decorator
{
public :
    FoilDecorator(Pad *pad)
    :Decorator(pad)
    {
    }
    virtual ~FoilDecorator( ){ }

    void Show( )
    {
        this->AddDecorator( );
        Decorator::Show( );
    }

protected:
    void AddDecorator( )
    {
        std::cout <<"���˸�����Ĥ...";
    }

};


int main( )
{
    // ����������һ��IpadMini
    Pad *pad = new IPad( );
    pad->Show( );               // �ܳ�ȥ��ɪһ��

    // ���У�����Ҫ�Ӹ�������
    Pad *coveDeco = new CoverDecorator(pad);
    coveDeco->Show( );               // ���ڿ����˰ɣ��ٳ�ȥ��ɫһ��

    // �ðɣ���������Ĥ
    Pad *foilDeco = new FoilDecorator(coveDeco);
    foilDeco->Show( );
}

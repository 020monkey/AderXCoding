#include <iostream>  
  
// ���ɲ�Ʒ���ݱ�ʶ   
typedef enum ClassType  
{  
    SINGCORE_A,  
    SINGCORE_B,   
}ClassType;  
  
  
////////////////////////////////////////////////////////////////////////////////  
// ������Ʒ�� -=> ��Ӧ�ڳ����Ʒ��ɫ  
class SingCore  
{  
public :  
    virtual ~SingCore( ){ };        // ����������   
      
    virtual void Show( ) = 0;       // ��Ʒ����ʾ����   
};  
  
// ���˲�ƷS -=> ��Ӧ�ھ����Ʒ��ɫ  
class SingCoreA : public SingCore  
{  
public :  
    virtual ~SingCoreA( ){ };       // ����������   
      
    void Show( )  
    {  
        std::cout <<"SingCore A..." <<std::endl;   
    }   
};    
  
  
// ���˲�ƷB -=> ��Ӧ�ھ����Ʒ��ɫ  
class SingCoreB : public SingCore  
{  
public :  
    virtual ~SingCoreB( ){ };       // ����������   
      
    void Show( )  
    {  
        std::cout <<"SingCore B..." <<std::endl;   
    }     
};   
////////////////////////////////////////////////////////////////////////////////  
//  
//  
//  
////////////////////////////////////////////////////////////////////////////////  
// ������ -=> ��Ӧ�ڹ�����ɫ  
class Factory  
{  
public :  
    virtual ~Factory( ){ };             // ����������   
  
    SingCore* CreateSingCore(ClassType classType)  
    {   
        switch(classType)  
        {  
            case SINGCORE_A :  
            {  
                return new SingCoreA( );   
            }  
              
            case SINGCORE_B :  
            {  
                return new SingCoreB( );  
            }  
        }  
    }   
};  
////////////////////////////////////////////////////////////////////////////////  
//  
//  
//  
////////////////////////////////////////////////////////////////////////////////  
  
  
int main()  
{  
      
    Factory *factory = new Factory( );  
      
    factory->CreateSingCore(SINGCORE_A)->Show( );   
    factory->CreateSingCore(SINGCORE_B)->Show( );  
          
    delete factory;   
}  
#include <iostream>

//  effective C++ 3rd
//  ����06 : ������ʹ�ñ༭���Զ����ɵĺ���, ��Ӧ����ȷ����
//  ������Boost�ṩ��noncopyable 
class Uncopyable
{

protected :
private   :
	Uncopyable(const Uncopyable &);
	Uncopyable& operator=(const Uncopyable &);
};

/*
ʹ�÷���
class Base : private Uncopyable
{
};
*/
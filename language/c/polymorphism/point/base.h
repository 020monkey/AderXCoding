//���ࣺbase.h
 
#ifndef BASE_H
 
#define BASE_H
 
struct Base
{
	size_t size; //����ռ�ռ�
 
	void * (* ctor) (void * self, va_list * app); //���캯��
 
	void * (* dtor) (void * self); //��������
 
	void (* draw) (const void * self); //��ͼ
};
 
#endif
#include <iostream>
using namespace std;


class a
{
public:
 a()
 {
  cout<<"Constructed a!!!"<<endl;
 }
 ~a()
 {
  cout<<"Destory a!!!!"<<endl;
 }
};
void* get_condesfun_add(int n)
{
 a *pa;
 if (n)  //��0ֵ��ȡ���캯����ַ
 {
__asm
  {
   push eax
   mov eax,confunadd   //���湹�캯������ת��ַ
   mov pa,eax
   pop eax
  }
 }
 else
 {
  __asm
  {
   push eax
   mov eax,desfunadd   //����������������ת��ַ
   mov pa,eax
   pop eax
  }
 }
 return pa;
confunadd:  //�����ų䵱���캯���ķ��ŵ�ַ
 a::a();
 __asm ret    //�ú���ָ��������ִ�к󣬴����ﷵ��
desfunadd:  //�����ų䵱���������ķ��ŵ�ַ
 pa->~a();
 __asm ret //ͬ��
}
int  main()
{
 typedef void(*pf)();
 void*p=get_condesfun_add(0);  //��ȡ����������ַ
 pf desfun=(pf)p;  //ǿ��ת��
 desfun();  //ִ��
 p=get_condesfun_add(1);  //��ȡ���캯����ַ
 pf confun=(pf)p;
 confun();
 return 0;
}

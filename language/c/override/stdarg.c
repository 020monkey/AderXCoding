ANSI C ��׼�У��пɱ�����ĸ������ͨ��һ���ʵ��
 
    va_list arg_ptr:                       ����һ���ɱ�����б�ָ��
    va_start(arg_ptr, argN):        ��arg_ptrָ�����argN
    va_arg(arg_ptr, type):          ��������Ϊtype�Ĳ���ָ��,��ָ����һ������
    va_copy(dest, src):               ���������б�ָ��,src->dest,
    va_end(arg_ptr)��               ��ղ����б����ò���ָ��arg_ptr��Ч��ÿ��va_start()������һ��va_end()��Ӧ
 

 
[c-sharp] view plain copy
#include<stdio.h>  
#include<stdarg.h>  
int getMax(int n, ...)  
{  
        va_list va;  
        va_start(va,n); // init va, pointing to the first argument  
        int tmp,smax=-1;  
        int i;  
        for(i=0;i<n;i++)  
        {  
                tmp=va_arg(va,int); // get the next argument, the type is int  
                if(tmp>smax) smax=tmp;  
        }  
        va_end(va);  
        return smax;  
}  
int main()  
{  
        printf("%d/n",getMax(4,9,5,2,19));  
        printf("%d/n",getMax(6,1,3,4,5,2,0));  
}  
 
 
�������ڴ��Ÿ�ʽ������������ڴ�Ķ�ջ���У���ִ�к�����ʱ�򣬴����һ����ʼ��ջ
��ˣ����趨��һ���ɱ�����ĺ��� void f(int x, ...)�� ͨ��f( x, y, z) ���ã���ô��z����ջ��Ȼ��y�� Ȼ��x�� �������ֻҪ�õ��κ�һ�������ĵ�ַ���Ϳ����ҵ����������ĵ�ַ��
va_start(va, n) ������vaָ��n�ĵ�ַ������������Ϳ��Եõ����в�����ֵ��ǰ���ǣ����Ǳ���֪��ÿ�����������͡��ڱ������У�����int���͡�
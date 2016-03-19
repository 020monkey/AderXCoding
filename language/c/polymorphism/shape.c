//c�����������
#include<stdio.h>
#include<stdarg.h>
#include<stdlib.h>
typedef enum {point,circle} shape_type;//����ͼ������,���Բ
typedef struct
{//����ͼ��
    shape_type type;//ͼ�εı�ʾ���Բ
    void (*destory)(void *);//����ͼ����
    void (*draw)(void *);//����ͼ����
}shape_t;
typedef struct
{//��
    shape_t common;//����
    int x;//������
    int y;//������
}point_t;
typedef struct
{//Բ
    shape_t common;//����
    point_t *center;//������ָ��
    int radius;//Բ�İ뾶��С
}circle_t;
void destoryPoint(point_t *This)
{//���ٵ�
    free(This);
    printf("���ٵ�ͼ��!\n");
}
void drawPoint(point_t *This)
{//���
    printf("P (%d,%d)",This->x,This->y);
}
shape_t* createPoint(va_list *ap)
{//������
    point_t * p_point;//�����ָ��
    if((p_point=(point_t*)malloc(sizeof(point_t)))==NULL)//����ռ�
       return NULL;
    p_point->common.type=point;//ָ������
    p_point->common.destory=(void (__cdecl *)(void *))destoryPoint;//ָ����������
    p_point->common.draw=(void (__cdecl *)(void *))drawPoint;//ָ�����Ƶ㺯��
    p_point->x=va_arg(*ap,int);//����xֵ
    p_point->y=va_arg(*ap,int);//����yֵ
    return (shape_t*)p_point;//ǿ�Ʒ�������
}
void destoryCircle(circle_t* This)
{//����Բ����
    free(This->center);
    free(This);
    printf("����Բ��!\n");
}
void drawCircle(circle_t* This)
{//��Բ����
    printf("C (");
    This->center->common.draw(This->center);//���
    printf(",%d)",This->radius);//ָ���뾶
}
shape_t* createCircle(va_list* ap)
{
    circle_t* p_circle;//����Բ��ָ��
    if((p_circle=(circle_t*)malloc(sizeof(circle_t)))==NULL)//����Բ�οռ�
      return NULL;
    p_circle->common.type=circle;//ָ������
    p_circle->common.destory=(void (__cdecl *)(void *))destoryCircle;//ָ������Բ����
    p_circle->common.draw=(void (__cdecl *)(void *))drawCircle;//ָ������Բ����
    p_circle->center=(point_t*)createPoint(ap);//����һ����
    p_circle->radius=va_arg(*ap,int);//ָ��Բ�İ뾶
    return (shape_t*)p_circle;//ǿ�Ʒ�������
}
shape_t* createShape(shape_type st,...)
{
    va_list ap;//�����ɱ����
    shape_t* p_shape=NULL;//����һ��ͼ��ָ��
    va_start(ap,st);
    //���ݲ�ͬ���ʹ���ͼ��
    if(st==point)
      p_shape=createPoint(&ap);
    if(st==circle)
      p_shape=createCircle(&ap);
    va_end(ap);
    return p_shape;//����ͼ������
}
int main(int argc,char **argv)
{   
    int i;
    shape_t* shape[2];
    shape[0]=createShape(point,2,3);
    shape[1]=createShape(circle,20,40,10);
    for(i=0;i<2;i++)
    {
        shape[i]->draw(shape[i]);
        printf("\n");
    }
    for(i=1;i>=0;i--)
     shape[i]->destory(shape[i]);
    return 0;
}
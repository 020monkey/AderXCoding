//  ������ժ��C/C++����Ա�����ֲ� 6.3��������21
#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    //  array_of_pointers  ָ������
    /*const*/char *pointer_array[] = {"Welcome", "to", "AderStep", "gatieme", "END"};
    //  double_pointer  ����ָ��, һ��ָ��char *ָ���ָ��
    char **double_pointer  = pointer_array;         //  ��ʱpָ����str[1]���ָ��ĵ�ַ
    printf("sizeof(pointer_array) = %d\n", sizeof(pointer_array));  //  5��char *�Ĵ�С


    char rectangular_array[][10] = {"Welcome\0", "to\0", "AderStep\0", "gatieme\0", "END\0"};
    char (*pointer_to_array)[10] = rectangular_array;           //  5��char[10]�Ĵ�С
    printf("sizeof(rectangular_array) = %d\n", sizeof(rectangular_array));

    //  ʹ�÷�ʽ��ͬ, ����Ѱַ��ʽ��ͬ


    //  ѭ��ָ������  -=>  ��άָ��
    for(int row = 0; row < 4; row++)
    {
        //char *point = *(double_pointer + row) = pointer_array[row];
        for(int col = 0; pointer_array[row][col] != '\0'; col++)
        {
            //*(*(double_pointer + row) + col) == pointer_array[row][col];
            //printf("%c", pointer_array[row][col]);
            printf("%c", *(*(double_pointer + row) + col));

        }
        printf("\n");
    }
    pointer_array[row][col] *(*(double_pointer + row) + col)
    //double_pointer[0] = pointer_array[1];       //  �����޸�ָ��������ÿ��ָ���ָ��
    //pointer_array[0][0] = 'a';                  //  �����ַ��������ڳ��������޷��޸�


    //  ѭ����ά����
    for(int row = 0; row < 5; row++)
    {
        for(int col = 0; rectangular_array[row][col] != '\0'; col++)
        {
            printf("%c", *(*(rectangular_array + row) + col));
        }
        printf("\n");
    }
    //rectangular_array[0] = pointer_array[1];       //
    //rectangular_array[0][0] = 'a';                  //

    return EXIT_SUCCESS;
}

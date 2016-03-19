#include <stdio.h>
#include <stdlib.h>

#define DEBUG

#define swap(a, b) (a) ^= (b) ^= (a) ^= (b)

//  �����Ĺ���
void ShiftAdjust(int *array, int low, int high)
{
    // array[low]�ǲ�����ѵ�Ԫ��,Ҳ�ǵ����ĸ��ڵ�
    for(int f = low, i = 2 * low + 1;  //  i ������
        i <= high;
        i = 2 * i + 1)                  //  �ݹ�������
    {
        if(i < high
        && array[i] < array[i + 1])   //  �Ƚ����Ӻ��ɺ���
        {
            i++;        //  �ҵ��ϴ���Ǹ�
        }

        if(array[f] >= array[i])
        {
            break;
        }

        swap(array[f], array[i]);
        f = i;          //  �������±�
    }
}

void Print(int *array, int length)
{
    for(int i = 0; i < length; i++)
    {
        printf("%4d", array[i]);
    }
    printf("\n");

}

void HeadSort(int *array, int length)
{
    int i;
    for(i = (length - 1) / 2; i >= 0; i--)
    {
        ShiftAdjust(array, i, length - 1);
    }

#ifdef DEBUG
    printf("\ninit the heap...\n");
    Print(array, length);
#endif // DEBUG
    for(int i = length - 1; i > 0; i--)
    {
#ifdef DEBUG
        printf("\nafter swap (%d, %d)...\n", array[0], array[i]);
        Print(array, length);
#endif // DEBUG

        swap(array[0], array[i]);

        ShiftAdjust(array, 0, i - 1);

#ifdef DEBUG
        //printf("\nafter shift ...\n", array[0], array[i]);
        Print(array, length);
#endif // DEBUG
    }

}



int main(void)
{
    int array[] = {36, 48, 48, 90, 88, 80, 76, 99};
    HeadSort(array, 8);


    return EXIT_SUCCESS;
}

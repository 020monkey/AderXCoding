#include <iostream>
#include <vector>
#include <algorithm>
//#include <fstream>
#include <iterator>
using namespace std;

#define DEBUG

#ifdef DEBUG

#define debug cout

#else

#define debug 0 && cout

#endif // __tmain


int Partition(vector<int> &numbers, int left, int right)
{
    int i = left, j = right;

    ///  ����ѡ���һ��Ԫ����Ϊ��׼
    ///  ���Ҳ�������ѡ��
    int pivotIndex = left, pivotNum = numbers[pivotIndex];

    debug <<"pivotNum = " <<pivotNum <<endl;

    while(i < j)
    {
        while(i < j && numbers[j] >= pivotNum)
        {
            debug <<"[" <<i <<", " <<j <<"] " <<numbers[j] <<" >= " <<pivotNum <<endl;
            j--;
        }
        debug <<"now we find i = " <<i <<", posJ = " <<j <<", num = " <<numbers[j] <<" < " <<pivotNum <<endl;;
        numbers[i] = numbers[j];        // ���ҵ����Ǹ�������С�����������������I��λ��
        //swap(numbers[i], numbers[j]); // Ҳ����ʹ�ý���, ����û�б�Ҫ, ��Ϊ�����λ�ò�û�����ȷ��

        while(i < j && numbers[i] <= pivotNum)
        {
            debug <<"[" <<i <<", " <<j <<"] " <<numbers[i] <<" <= " <<pivotNum <<endl;
            i++;
        }

        debug <<"now we find j = " <<i <<", posI = " <<j <<", num = " <<numbers[i] <<" > " <<pivotNum <<endl;;
        numbers[j] = numbers[i];        // ���ҵ����Ǹ����������������������Ҳ�J��λ��
        //swap(numbers[i], numbers[j]); // Ҳ����ʹ�ý���, ����û�б�Ҫ, ��Ϊ�����λ�ò�û�����ȷ��
    }

    numbers[i] = pivotNum;              //  ����λ�� i == j ���������λ��

#ifdef DEBUG

    debug <<pivotNum <<" 's post is" <<i <<endl;
    for(int pos = left; pos <= right; pos++)
    {
        debug <<numbers[pos] <<" ";
    }
    debug <<endl;
    //system("PAUSE");

#endif // __tmain

    return i;
}


void QuickSort(vector<int> &numbers, int left, int right)
{
    if(left < right)
    {
        int par = Partition(numbers, left, right);
        QuickSort(numbers, left, par - 1);
        QuickSort(numbers, par + 1, right);
    }
}





int main( )
{
    int arr[] = { 7, 6, 5, 4, 3, 2, 1 };
    vector<int> vec(arr, arr + 7);
    QuickSort(vec, 0, 6);

    copy(vec.begin(), vec.end(), ostream_iterator<int>(cout," "));

    return 0;
}

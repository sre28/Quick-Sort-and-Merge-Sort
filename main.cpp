#include <iostream>
using namespace std;

int quick(int array[], int low, int high) {
    int p_index, i, j;
    p_index = high;
    j = low;
    for (i = low; i < high; i++)
        if (array[p_index] >= array[i])
        {
            int t = array[i];
            array[i] = array[j];
            array[j] = t;
            j++;
        }
        int t = array[j];
        array[j] = array[p_index];
        array[p_index] = t;
        return j;
}
void quick_sort(int array[],int n,int low, int high)
{
    int p_index,i;
    if(low < high)
    {
        p_index = quick(array, low, high);
        quick_sort(array, n , low, p_index - 1);
        quick_sort(array, n , p_index + 1, high);
    }
}

void merge(int array[], int low, int mid, int high) {
    int i;
    int p,q;
    int r = low;
    int new_array[100];
    p=low;
    q=mid+1;
    while(p <= mid && q <= high){
        if (array[p] < array[q])
            new_array[r++] = array[p++];
        else
            new_array[r++] = array[q++];
    }
    while(p<=mid) {
        new_array[r++] = array[p++];
    }
    while(q<=high) {
        new_array[r++] = array[q++];
    }
    for (i=low;i<=high;i++)
        array[i] = new_array[i];
}

void merge_sort(int array[],int n,int low, int high)
{
    int mid;
    if(low < high)
    {
        mid = (low+high)/2;
        merge_sort(array, n , low, mid);
        merge_sort(array, n , mid + 1, high);
        merge(array, low, mid, high);
    }
}

int main() {
    int array[200],i,n;
    std::cout << "Enter size" << std::endl;
    std::cin>>n;

    std::cout << "Enter array" << std::endl;

    for(i=0;i<n;i++)
    std::cin>>array[i];

    merge_sort(array,n,0,n-1);

    for(i=0;i<n;i++)
        std::cout <<array[i]<<" ";

    return 0;
}
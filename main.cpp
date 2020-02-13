#include <iostream>
#include <stdio.h>
#include <memory.h>

using namespace std;

#define SWAP(a, b, type) do { \
    type temp; \
    temp = a;  \
    a = b;     \
    b = temp;  \
} while (0)
#define MAXSIZE 10
#define TYPE int
const int UnsortedArray[MAXSIZE] = {9, 3, 5, 2, 1, 7, 6, 8, 10, 4};

inline void PrintArray(int *Array,int &swaped, string s){
    printf("%s",&s);
    for(int index = 0; index < MAXSIZE; index++)
        printf("%d ",*(Array + index));

    printf("\nSwap Count : %d\n\n",swaped);
}


void BubbleSort_Simulation(){
    int BubblesortedArray[MAXSIZE];
    int cntOfswap = 0;
    memcpy(BubblesortedArray,UnsortedArray,sizeof(BubblesortedArray));
    for(int repeat = 0; repeat < MAXSIZE; repeat++){
        for(int start = 0; start < MAXSIZE-repeat-1; start++){
            if(BubblesortedArray[start] > BubblesortedArray[start+1]) {
                SWAP(BubblesortedArray[start], BubblesortedArray[start + 1],TYPE);
                ++cntOfswap;
            }
        }
    }

    PrintArray(BubblesortedArray, cntOfswap, "BUBBLE SORT\n");
}

void SelectionSort_Simulation(){
    int SelectionsortedArray[MAXSIZE];
    int cntOfswap = 0;
    memcpy(SelectionsortedArray,UnsortedArray,sizeof(SelectionsortedArray));
    for(int start = 0; start < MAXSIZE-1; start++){
        int min_element_index = start;
        for(int find = start+1; find < MAXSIZE; find++){
            if(SelectionsortedArray[min_element_index] > SelectionsortedArray[find]) {
                min_element_index = find;
            }
        }
        if(min_element_index!=start){
            SWAP(SelectionsortedArray[start],SelectionsortedArray[min_element_index],TYPE);
            ++cntOfswap;
        }
    }

    PrintArray(SelectionsortedArray,cntOfswap,"SELECTION SORT\n");
}

void InsertionSort_Simulation(){
    int InsertionsortedArray[MAXSIZE];
    int cntOfswap = 0;
    memcpy(InsertionsortedArray,UnsortedArray,sizeof(InsertionsortedArray));
    for(int start = 1; start < MAXSIZE; start++){
        for(int compare = start-1; compare >= 0; compare--){
            if(InsertionsortedArray[compare] > InsertionsortedArray[compare+1]){
                SWAP(InsertionsortedArray[compare], InsertionsortedArray[compare+1],TYPE);
                ++cntOfswap;
            } else
                break;
        }
    }

    PrintArray(InsertionsortedArray,cntOfswap,"INSERTION SORT\n");
}

inline void Merge(int *Array, int left, int mid, int right, int &cntOfswap){
    int sorted[right-left+1];
    int L = left, R = mid + 1, Index = 0;
    while(L<=mid && R<=right){
        if(Array[L] < Array[R])
            sorted[Index++] = Array[L++];
        else
            sorted[Index++] = Array[R++];
        ++cntOfswap;
    }
    if(L<=mid){
        for(;L<=mid;){
            sorted[Index++] = Array[L++];
            ++cntOfswap;
        }
    }
    else{
        for(;R<=right;){
            sorted[Index++] = Array[R++];
            ++cntOfswap;
        }
    }
    for(Index = left; Index <= right; Index++)
        Array[Index] = sorted[Index - left];
}

void MergeSort(int *Array, int left, int right, int &cntOfswap){
    if(left < right){
        int mid = (left + right)/2;
        MergeSort(Array,left,mid,cntOfswap);
        MergeSort(Array,mid+1,right,cntOfswap);
        Merge(Array, left, mid, right,cntOfswap);
    }
}

void MergeSort_Simulation(){
    int MergesortedArray[MAXSIZE];
    int cntOfswap = 0;
    memcpy(MergesortedArray,UnsortedArray,sizeof(MergesortedArray));
    MergeSort(MergesortedArray, 0, MAXSIZE-1,cntOfswap);
    PrintArray(MergesortedArray,cntOfswap,"MERGE SORT\n");
}

void GnomeSort_Simulation(){
    int GnomesortedArray[MAXSIZE];
    int cntOfswap = 0;
    memcpy(GnomesortedArray,UnsortedArray,sizeof(GnomesortedArray));
    int Index = 0;
    while(Index != (MAXSIZE-1)){
        if(GnomesortedArray[Index]>GnomesortedArray[Index+1]){
            while(Index >= 0 && GnomesortedArray[Index]>GnomesortedArray[Index+1]){
                SWAP(GnomesortedArray[Index], GnomesortedArray[Index+1],TYPE);
                ++cntOfswap; --Index;
            }
            ++Index;
        } else
            ++Index;
    }
    PrintArray(GnomesortedArray,cntOfswap,"GNOME SORT\n");
}

inline void CellSort(int *Array, int &_start, int &Gap, int &cntOfswap){
    for(int start = _start + Gap; start < MAXSIZE; start += Gap){
        int temp = Array[start];
        int compare = start - Gap;
        for(;compare>=_start && Array[compare] > temp; compare -= Gap) {
            Array[compare + Gap] = Array[compare];
            ++cntOfswap;
        }
        Array[compare+Gap] = temp;
    }
}

void CellSort_Simulation(){
    int CellsortedArray[MAXSIZE];
    int cntOfswap = 0;
    memcpy(CellsortedArray,UnsortedArray,sizeof(CellsortedArray));
    int Gap = MAXSIZE>>1;
    while(Gap){
        if(!(Gap&1))
            Gap^=1;
        for(int start = 0; start < Gap; start++)
            CellSort(CellsortedArray,start,Gap,cntOfswap);

        Gap>>=1;
    }
    PrintArray(CellsortedArray,cntOfswap,"CELL SORT\n");
}
inline void Partition(int *Array, int &left, int &right, int &high, int &cntOfswap){
    int low = left;
    int pivot = Array[left];
    do{
        do{
            low++;
        }while(low<=right && Array[low]<pivot);
        do{
            high--;
        }while(high>=left && Array[high]>pivot);
        if(low<high) {
            SWAP(Array[low], Array[high], TYPE);
            ++cntOfswap;
        }

    }while(low<high);
    SWAP(Array[left],Array[high],TYPE);
    ++cntOfswap;
}

void QuickSort(int *Array, int left, int right, int &cntOfswap){
    if(left<right){
        int standard = right+1;
        Partition(Array,left,right,standard,cntOfswap);
        QuickSort(Array,left,standard-1,cntOfswap);
        QuickSort(Array,standard+1,right,cntOfswap);
    }
}

void QuickSort_Simulation(){
    int QuicksortedArray[MAXSIZE];
    int cntOfswap = 0;
    memcpy(QuicksortedArray,UnsortedArray,sizeof(QuicksortedArray));
    QuickSort(QuicksortedArray,0,MAXSIZE-1,cntOfswap);
    PrintArray(QuicksortedArray,cntOfswap,"QUICK SORT\n");
}
int main(int argc, char** argv){
    BubbleSort_Simulation();
    SelectionSort_Simulation();
    InsertionSort_Simulation();
    MergeSort_Simulation();
    GnomeSort_Simulation();
    CellSort_Simulation();
    QuickSort_Simulation();
}
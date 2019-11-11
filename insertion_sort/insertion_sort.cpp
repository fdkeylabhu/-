/*************************************************
Author: Jason Hu
*************************************************/

#include <iostream>
#include <vector>

using namespace std;

//插入排序思想：
//遍历未排序的数组中，并将其插入到已排序的数组中的某个位置
//Tips：在数组中插入元素，其实就是将数组往后移一位，可以通过不断复制得到。
//算法导论P22(2.1-1)： A={31,41,59,26,41,58}
// i = 1; {31 41 59 26 41 58}
// i = 2; {31 41 59 26 41 58}
// i = 3; (key = 26, {31 31 41 59 41 58}, j = -1)   a[j+1] = a[0] = key,  {26 31 41 59 41 58}
// i = 4;  {26 31 41 41 59 58}
// i = 5;  {26 31 41 41 58 59}
void insertion_sort(vector<int> &arr)
{
    int key = 0;
    int j = 0;           //定义一个变量用于索引已排序的数组
    for (int i = 1; i < arr.size(); ++i) {
        j = i - 1;
        key = arr[i];
        while(j >= 0 && arr[j] > key) {    //遍历已排序的数组部分，如果元素值大于key，则将其向后移动一位
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}


int main()
{

    vector<int> arr = {7, 2, 4, 5, 8, 0, 9, 1, 3, 6};

    insertion_sort(arr);

    //print result
    for (int i = 0; i < arr.size(); ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

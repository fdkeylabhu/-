#include <iostream>
#include <vector>

#define DEBUG TRUE



using namespace std;


//维护最大堆性质: 父节点值 > 左右孩子节点值
void heapify(vector<int> &arr, int parent, int length)
{
    if(parent >= length) {
        return;
    }
   
    int l = 2 * parent + 1;    //取得左节点位置
    int r = 2 * parent + 2;    //取得右节点位置
    
    int largest = parent;

    if (l < length && arr[l] > arr[parent]) {     //如果左孩子 > 父节点，则最大值为左孩子
        largest = l;
    }
    if (r < length && arr[r] > arr[largest]) //如果右孩子 > 最大值，则最大值为右孩子
    {
        largest = r;
    }

    if (largest != parent) {
        swap(arr[largest], arr[parent]);
        heapify(arr, largest, length); //由于交换后的arr[largest]值为原父节点，而此时变成了孩子节点，其有可能会违反最大堆性质，因此递归调用
    }
}   


//从无序数组中构造一个最大堆
//这里的技巧就是从非叶子节点开始构造，即从length/2-1位置，对于一个数组A[0,n-1], A[0,n/2]是非叶子节点，A[n/2+1, n-1]是叶子节点
//叶子节点肯定不需要构建，我们只需依次对父节点进行heapify就可以构造出一个最大堆
void build_heap(vector<int> &arr)
{
    int length = arr.size();
    for (int i = length / 2 - 1; i >= 0; i--)
    {
        heapify(arr, i, length);
    }

#ifdef DEBUG

    cout << "初始大顶堆： ";
    for (int i = 0; i < arr.size(); ++i)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
#endif

}



//堆排序：
//1. 构建初始大顶堆
//2. 将堆顶元素交换置数组末尾，再对数组头元素进行heapify的调整操作
//   同时所操作的堆数组的长度递减
void heap_sort(vector<int> &arr)
{
    build_heap(arr);                        //构造大顶堆

    int length = arr.size() - 1;

    for (int i = length; i > 0; --i)        //从后往前计数
    {
        swap(arr[0], arr[i]);               //将堆顶元素移动到数组末尾
        heapify(arr, 0, i);                 //同时heapify数组的长度减1
    }
}

int main()
{

    vector<int> arr = {7,2,4,5,8,0,9,1,3,6};


    heap_sort(arr);

    //print result
    for (int i = 0; i < arr.size(); ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}

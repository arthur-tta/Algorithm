#include <iostream>

using namespace std;
 
// gộp 2 mảng con
void merge(int arr[], int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 =  right - mid;
 
    /* Tạo các mảng tạm */
    int L[n1], R[n2];
 
    /* Copy dữ liệu sang các mảng tạm */
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1+ j];
 
    /* Gộp hai mảng tạm vừa rồi vào mảng arr*/
    int i = 0; // Khởi tạo chỉ số bắt đầu của mảng con đầu tiên
    int j = 0; // Khởi tạo chỉ số bắt đầu của mảng con thứ hai
    int k = left; // Khởi tạo chỉ số bắt đầu của mảng lưu kết quả
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy các phần tử còn lại của mảng L vào arr nếu có */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy các phần tử còn lại của mảng R vào arr nếu có */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
/* l là chỉ số trái và r là chỉ số phải của mảng cần được sắp xếp */
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        // Tương tự (l+r)/2, nhưng cách này tránh tràn số khi l và r lớn
        int mid = left + (right - left) / 2;
 
        // Gọi hàm đệ quy tiếp tục chia đôi từng nửa mảng
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
 
        //gộp 2 mảng con lại
        merge(arr, left, mid, right);
    }
}
 
 
/* Hàm xuất mảng */
void print(int arr[], int n){
    for (int i = 0; i < n; i++)
       cout << arr[i] << " ";
}
 
 
int main(){
    int n = 10;
    int arr[] = {1, 3, 4, 2, 8, 6, 7, 9, 5, 0};
 
    mergeSort(arr, 0, n - 1);
    print(arr, n);
}
 
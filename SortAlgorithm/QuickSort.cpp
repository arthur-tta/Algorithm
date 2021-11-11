#include <iostream>

using namespace std;

void swap(int &a, int &b){
    a = a + b;
    b = a - b;
    a = a - b;
}

//tra ve vi tri chia doi mang
int partition(int arr[], int low, int hight){
    int pivot = arr[hight];     // moc lay la vi tri cuoi cung
    int left = low;
    int right = hight - 1;

    while(true){
        // tim phan tu dau tien ben trai lon hon moc
        while(left <= right && arr[left] < pivot){
            left++;
        }
        // tim vi tri dau tien ben phai nho hon moc
        while(right >= left && arr[right] > pivot){
            right--;
        }
        // neu mang da sap xep thi thoat
        if(left >= right){
            break;
        }else{
            // trao doi 2 phan tu
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
    // trao doi phan tu lon nhat trong doan voi moc
    swap(arr[left], arr[hight]);
    // ra ve vi tri chia doi mang
    return left;
}

void quickSort(int arr[], int low, int hight){
    if(low < hight){
        // pi la vi tri chia doi mang
        int pi = partition(arr, low, hight);

        // de qui sap xep mang trai va mang phai
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, hight);
    }
}


void print(int arr[], int n){
    for(int i = 0; i < n; i++){
        cout << arr[i] << " ";
    }
}

int main(){
    int n = 10;
    int arr[] = {1, 3, 4, 2, 8, 6, 7, 9, 5, 0};

    quickSort(arr, 0, n - 1);
    print(arr, n);

   
}
#include <iostream>
using namespace std;

// membuat fungsi
int binarySearch(int data[], int left, int right, int target){
    if (left > right) {
        return -1;
    }
    
    int mid = left + (right - left) / 2;
    
        if (data[mid] == target) {
            return mid;
        } else if (target < data[mid]) {
            return binarySearch(data, left, mid - 1, target);
        } else {
            return binarySearch(data, mid + 1, right, target);
        }
}
        

int main(){
    int data[] = {1,2,3,4,5,6,7};
    int n = 7;
    int target = 4;

    int hasil = binarySearch(data, 0, n - 1, target);

    if (hasil != -1){
        cout << "Data ditemukan pada indeks: " << hasil << endl;
    }else{
        cout << "Data tidak ditemukan" << endl;
    }

}
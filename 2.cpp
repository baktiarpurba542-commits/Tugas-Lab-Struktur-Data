#include<iostream> //selection sort
using namespace std;

int main (){
    int data []= {5, 2, 4, 1, 3};
    int data = 5;

    for (int i =0; i< n-1; i++){
        int minIndeks = i;

        for (int j =1 +1; j<n; j++){
            if (data[j] < data[minIndeks]){
                minIndeks = j;
            }
        }
        swap(data[i], data[minIndeks]);
    }
    cout << "hasil selection sort : ";
    for (int i = 0; i<n; i++){
        cout <<data[i]<<" "
    }
    return 0;
}
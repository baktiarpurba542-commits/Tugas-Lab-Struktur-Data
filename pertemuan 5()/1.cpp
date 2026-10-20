#include <iostream>//lineaaar search
using namespace std;

//membuat fungsi linear search
int linearSearch (int data[], int n, int target){
    for(int i = 0; i<n; i++){
        if (data[i] == target){
            return i;
        }
    }
    return -1;
}
int main(){
    int data [] = {4, 8, 12, 16, 20, 24, 28};
    int n = 7;
    int target = 20;

    int hasil = linearSearch (data, n, target);

    if (hasil != -1){
        cout<<"Data ditemukan indeks: "<<hasil<<endl;
    } else{
        cout<<"Data tidak ditemukan"<<endl;
    }
    return 0;
}
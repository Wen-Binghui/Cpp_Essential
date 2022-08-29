#include <iostream>
# include "vector"
using namespace std;

void sweep(int& a, int& b){
    int c = a;
    a = b;
    b = c;
}


void bubble_sort(vector<int> &ori_vec){
    int n = ori_vec.size();
    for (int i=0; i<n; i++){
        for (int j=i+1; j<n; j++){
            if (ori_vec[j]<ori_vec[i]){
                sweep(ori_vec[i], ori_vec[j]);
            }
        }
    }


}

int main() {
    // ! 向量与数组
    vector<int> vec(10);
    vec[1] = 1;
    cout<<vec[0]<<vec[1]<<vec[3]<<endl; // 如果是没定义的int，默认为0
    int arr[199];
//    cout<<arr; // 如果是没定义的int，乱码
    // ! 指针
    int *pi = nullptr; //
    cout<<pi<<endl;
    if (pi){
        cout<<"pi is not null.\n";
    }
    vector<int> vec_2sort = {3,1,4,1,5,7};
    bubble_sort(vec_2sort);
    printf("After sorting:");
    for (int i=0; i<vec_2sort.size(); i++){
        printf("%d, ",vec_2sort[i]);
    }


    return 0;
}

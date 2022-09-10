#include <iostream>
# include "vector"
using namespace std;

//! 重载函数
void say_hello(string &addition_msg) {
    printf("\nHello %s\n", addition_msg.c_str()); //? 将C++ string转化成 c string
}
void say_hello() { // 重载函数
    printf("\nHelloooooooooooo!!!\n");
}

//! 模板函数
template<typename elemType>
void display_message(const string &msg, const vector<elemType> &vec) {
    cout << msg << endl;
    for (int i = 0; i < vec.size(); i++) {
        elemType ele = vec[i];
        printf("ele_%04d: %4.2f\n", i, (float)ele);
    }
}

void sweep(int &a, int &b) {
    int c = a;
    a = b;
    b = c;
}

void bubble_sort(vector<int> &ori_vec) {
    unsigned n = ori_vec.size();
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (ori_vec[j] < ori_vec[i]) {
                sweep(ori_vec[i], ori_vec[j]);
            }
        }
    }

}

int main() {
    // ! 向量与数组
    vector<int> vec(10);
    vec[1] = 1;
    cout << vec[0] << vec[1] << vec[3] << endl; // 如果是没定义的int，默认为0
    int arr[199];
//    cout<<arr; // 如果是没定义的int，乱码
    // ! 指针
    int *pi = nullptr; //
    cout << pi << endl;
    if (pi) {
        cout << "pi is not null.\n";
    }
    int b = 3;
    int *a = &b;
    cout << *a << endl;

    //! 排序
    vector<int> vec_2sort = {3, 1, 4, 1, 5, 7};
    vector<float> vec_f = {3, 1, 4, 1, 5, 7};
    bubble_sort(vec_2sort);
    printf("After sorting:");
//    for (int i=0; i<vec_2sort.size(); i++){
    for (int i: vec_2sort) { //! 相当于 i in vec_2sort:
        printf("%d, ", i);
    }
    string msg = "from Me";
    say_hello(msg);
    say_hello();

    display_message(msg, vec_2sort);
    display_message(msg, vec_f);

    return 0;
}

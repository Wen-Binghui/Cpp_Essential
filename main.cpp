#include <iostream>
# include "vector"
using namespace std;

//! 重载函数
void say_hello(string &addition_msg, ostream &os = cout) { // 默认参数
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
        printf("ele_%04d: %4.2f\n", i, (float) ele);
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

// 局部静态对象
vector<int> *fibonacci(int index) {
    const int max_size = 1024;
    if (index > max_size || index < 1) {
        printf("Invalid index.\n");
    }
    static vector<int> fib_vec;
    cout << fib_vec.size() << endl;
    if (fib_vec.size() > index) {
        printf("Already calculated.\n");
        return &fib_vec;
    } else {

        for (unsigned i = fib_vec.size(); i < index; ++i) {
            if (i == 0 || i == 1) fib_vec.push_back(1);
            else fib_vec.push_back(fib_vec[i - 1] + fib_vec[i - 2]);
        }
        return &fib_vec;
    }
}
template<typename elemType>
// 泛化find
elemType *find_(elemType *start_pos, elemType *end_pos, elemType &target) {
    if (!start_pos || !end_pos) return nullptr;
    for (; start_pos != end_pos; start_pos++) {
        if (*start_pos == target) return start_pos;
    }
    return nullptr;
}

int main_chap2() {
    // region 向量与数组
    vector<int> vec(10);
    vec[1] = 1;
    cout << vec[0] << vec[1] << vec[3] << endl; // 如果是没定义的int，默认为0
    int arr[199];
    // endregion
    // region 指针
    int *pi = nullptr; //
    cout << pi << endl;
//    if (pi) {
//        cout << "pi is not null.\n";
//    }
    int b = 3;
    int *a = &b;
    cout << *a << endl;
    // endregion
    // region  排序
    vector<int> vec_2sort = {3, 1, 4, 1, 5, 7};
    vector<float> vec_f = {3, 1, 4, 1, 5, 7};
    bubble_sort(vec_2sort);
    printf("After sorting:");
//    for (int i=0; i<vec_2sort.size(); i++){
    for (int i: vec_2sort) { //! 相当于 i in vec_2sort:
        printf("%d, ", i);
    }
    // endregion
    // region 函数重载
    string msg = "from Me";
    say_hello(msg);
    say_hello();

    display_message(msg, vec_2sort);
    display_message(msg, vec_f);
    // endregion

    vector<int> *fib = fibonacci(3);
    for (int i: *fib) {
        cout << i << endl;
    }

    enum myType { bb, cc, dd = 1 };
    cout << dd << endl;

    return 0;
}

int main() {
//    vector<int> vec_int = {1, 1, 3, 4, 5, 8};
//    int arr_int[] = {1, 1, 3, 4, 5, 8};
//    int tar = 8;
//    int *pos_find_vec = find_(&vec_int[0], &vec_int[vec_int.size()], tar);
//    cout << *pos_find_vec << endl;
//    int *pos_find_arr = find_(&arr_int[0], &arr_int[vec_int.size()], tar);
//    cout << *pos_find_arr << endl;
    vector<string> svec;
    vector<string>::iterator iter = svec.begin();

    return 0;
}





//int main(){
//
//}
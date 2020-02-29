#include <set>
#include <iostream>
#include <string>

template <class T>
int reduce(T ar[], int n){
    std::set<T> set_ar(ar, ar+n);
    return set_ar.size();
}

int main(){
    using std::cout;
    using std::endl;
    long long_ar[10] = {12435, 533, 6452, 533, 9013,
                        531053, 66453523, 235353, 4323, 9013};
    std::string str_ar[10] = {"retste", "ewtewsf", "etwesdg", "rwetwe", "repeat",
                         "ewontwet", "rwetweotnwe", "rewtnowen", "repeat", "re"};
    cout << "after processing: \n";
    cout << "# in long_ar: " << reduce(long_ar, 10) << endl;
    cout << "# in str_ar: " << reduce(str_ar, 10) << endl; 
    return 0;
}

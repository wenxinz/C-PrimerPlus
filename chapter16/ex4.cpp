#include <iostream>
#include <set>

int reduce(long ar[], int n);

int main(){
    long ar[10]={113, 6463, 9135, 6463, 890, 
                 113, 96402, 425, 6463, 890};
    std::cout << reduce(ar,10) << std::endl; 
    return 0;
}

int reduce(long ar[], int n){
    std::set<long> set_ar(ar,ar+n);
    return set_ar.size();
}


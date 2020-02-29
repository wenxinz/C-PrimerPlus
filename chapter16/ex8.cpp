#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <iterator>

int main(){
    using std::cout;
    using std::endl;
    using std::cin;

    std::set<std::string> mat;
    std::set<std::string> pat;
    std::set<std::string> combine;
    std::ostream_iterator<std::string, char> out(cout, " ");
    std::string temp;
     
    cout << "Are you Mat(1) or Pat(2)? (enter 1 or 2, q to quit): \n";
    int choice;
    while(cin >> choice){
        cout << "Please enter names of your friends (enter q to quit): \n";
        while(getline(cin,temp) && temp != "q"){   
            switch(choice){
                case 1: mat.insert(temp); break;
                case 2: pat.insert(temp); break;
            }
        }
        switch(choice){
            case 1: cout << "Mat's friends: \n";
                    copy(mat.begin(), mat.end(), out); break;
            case 2: cout << "Pat's friends: \n";
                    copy(pat.begin(), pat.end(), out); break;
        }
        cout << endl;
        cout << "Are you Mat(1) or Pat(2)? (enter 1 or 2, q to quit):\n";
    }
    std::set_union(mat.begin(), mat.end(), pat.begin(), pat.end(), std::insert_iterator<std::set<std::string> >(combine, combine.begin()));
    cout << "list of friends of both Mat and Pat: \n";
    copy(combine.begin(), combine.end(), out);
    cout << endl;
    
    return 0;
}

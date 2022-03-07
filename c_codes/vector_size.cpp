#include<iostream>
#include <vector>

using namespace std;

int main(){
    vector<unsigned> v;
    cout << sizeof(v) << endl;
    cout << v.size() << endl;
    cout << v.capacity() << endl;
    for(int i=0; i < 9; i++){
        v.push_back(i);
    }

    cout << v.size() << endl;
    cout << v.capacity() << endl;
    cout << sizeof(v) << endl;
    return 0;
}

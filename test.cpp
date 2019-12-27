#include<iostream>
#include<vector>

using namespace std;

int main(){
    vector<int> a;
    a.push_back(24);
    a.push_back(24);
    a.push_back(24);
    a.push_back(24);
    vector<int> b;
    b.push_back(12);
    b.push_back(12);
    b.push_back(12);
    b.push_back(12);

    a.insert(a.end(), b.begin(), b.end());

    vector<int> d = a;

    cout << a.size();


    return 0;
}
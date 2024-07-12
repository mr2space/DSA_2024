#include<iostream>
using namespace std;

int main(){
    std::string t = "Banana Republic";
    std::string s = "nana R";

    std::string::size_type i = t.find(s);

    if (i != std::string::npos)
    t.erase(i, s.length());
    cout << t << endl;
    return 0;
}
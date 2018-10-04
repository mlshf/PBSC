#include <algorithm>
#include <functional>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

template < typename TFunc >
auto Compose( TFunc&& FFunc ) {
    return bind( FFunc, placeholders::_1 );
}

template < typename TFunc1, typename... TFuncs >
auto Compose( TFunc1&& FFunc1, TFuncs... FFuncs ) {
    return bind( FFunc1, Compose( ( FFuncs )... ) );
}

const char* f2(const string& str) {
    return str.c_str();
}
int main() {
    string s[] = {"1.2", "2.343", "3.2"};
    vector<double> d(3);
    auto f1 = atof;
    transform( s,
               s + 3,
               d.begin(),
               Compose( f1, f2 ) );

    for(auto val: d)
        cout << val << endl;
}
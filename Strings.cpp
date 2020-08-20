#include <iostream>
#include <string>
using namespace std;

int main() {
	// Complete the program
    string s,r;
    cin >>s;
    cin >>r;
    cout<<s.size()<<" "<<r.size()<<endl;
    cout<<s<<r<<endl;
    swap( s[0], r[0] );
    cout << s << ' ' <<  r << endl;
    
    
    return 0;
}


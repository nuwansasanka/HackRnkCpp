#include <iostream>
#include <sstream>
#include<string.h>
using namespace std;

/*
Enter code for class Student here.
Read statement for specification.
*/
class Student{
    private:
    int age;
    int standard;
    string first_name;
    string last_name;
    public:
    void set_age(int a){
        age=a;
    }
    int get_age(){
        return age;
    }
     void set_first_name(string l){
        first_name=l;
    }
    string get_first_name(){
        return first_name;
    }
    void set_last_name(string d){
        last_name=d;
    }
    string get_last_name(){
        return last_name;
    }
    void set_standard(int r){
        standard=r;
    }
    int get_standard(){
        return standard;
    }
    string to_string()
    {
        stringstream x;
        char c = ',';
        x << age << c << first_name << c << last_name << c << standard;
        return x.str();
    }
    
 



};

int main() {
    int age, standard;
    string first_name, last_name;
    
    cin >> age >> first_name >> last_name >> standard;
    
    Student st;
    st.set_age(age);
    st.set_standard(standard);
    st.set_first_name(first_name);
    st.set_last_name(last_name);
    
    cout << st.get_age() << "\n";
    cout << st.get_last_name() << ", " << st.get_first_name() << "\n";
    cout << st.get_standard() << "\n";
    cout << "\n";
    cout << st.to_string();
    
    return 0;
}

/*
#include <iostream>
#include <bitset>
#include <string>
using namespace std;

int main()
{
    bitset<4> foo;
    foo[1]=1;
    foo[2]=foo[1];
    foo[3]=foo[2];
    cout << "foo:" <<foo<< endl;
    cout <<foo.count()<<" "<<(foo.size()-foo.count())<<endl;
    cout<<boolalpha;
    for(int i=0;i<foo.size();++i)
        cout<<foo.test(i)<<"\n";

    string mystring=foo.to_string<char,string::traits_type,string::allocator_type>();
    cout<<mystring<<endl;

    return 0;
}
*/


#include<iostream>
#include<deque>

using namespace std;
int main()
{
    deque<int> mydeque;

    for(int i=1;i<=5;i++)
        mydeque.push_back(i);

    cout<<"mydeque contains:";
    deque<int>::iterator it=mydeque.begin();

    while(it!=mydeque.end())
        cout<<" "<<*it++;
    return 0;
}


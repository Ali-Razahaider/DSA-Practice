#include<iostream>
using namespace std;

//Problem Statement: Given an integer N, return the number of digits in N.

int NaiveAppr(long n){
    auto str = to_string(n);
    return str.length();
    //can convert 10 digit numbers
}


int main(){
     long num;
     cin>>num;

     cout<<NaiveAppr(num)<<endl;

}
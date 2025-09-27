#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
string addStrings(const string &a, const string &b){
    string A=a, B=b;
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());
    string result;
    int carry = 0;
    for(int i=0;i<max(A.size(),B.size());i++){
        int digitA=(i<A.size()) ? A[i]-'0': 0;
        int digitB=(i<B.size()) ? B[i]-'0': 0;
        int sum = digitA+ digitB + carry;
        result.push_back((sum%10)+'0');
        carry = sum/10;
    }
    if(carry) result.push_back(carry+'0');
    reverse(result.begin(),result.end());
    return result;
}
string subtractStrings(const string &a, const string &b){
    string A=a, B=b;
    reverse(A.begin(),A.end());
    reverse(B.begin(),B.end());
    string result ;
    int borrow =0;
    for(int i=0;i<A.size();i++){
        int digitA=A[i]-'0';
        int digitB=(i<B.size()) ? B[i]-'0':0;
        int sub = digitA-digitB-borrow;
        if(sub<0){
            sub+=10;
            borrow=1;
        }
        else {
            borrow=0;
        }
        result.push_back(sub+'0');
    }
    while(result.size()>1&&result.back() =='0') result.pop_back();
    reverse(result.begin(), result.end());
    return result;
}
string mulitplySimple(const string &a, const string&b){
    int n1 = a.size();
    int n2=b.size();
    string result(n1+n2,'0');
    for(int i=n1-1;i>=0;i--){
        int carry = 0;
        for(int j=n2-1;j>=0;j--){
            int temp = (result[i+j+1]-'0') + (a[i]-'0')*(b[j]-'0')+carry;
            result[i+j+1]=(temp%10)+'0';
            carry =temp/10;
        }
        result[i]+=carry;
    }
    size_t pos = result.find_first_not_of('0');
    return (pos == string::npos) ? "0" : result.substr(pos);
}
string karatsuba(const string &x , const string &y){
     int n= max(x.size(), y.size());
     if(n<=3)
     return mulitplySimple(x,y);
     int m=(n+1)/2;
     string a= (x.size()>m) ? x.substr(0,x.size()-m) :"0";
     string b=(x.substr(x.size()-m));
     string c=(y.size()>m) ? y.substr(0,y.size()-m):"0";
     string d=y.substr(y.size()-m);
     string ac = karatsuba(a,c);
     string bd = karatsuba(b,d);
     string abcd = karatsuba(addStrings(a,b), addStrings(c,d));
     string adbc = subtractStrings(subtractStrings(abcd, ac), bd);
     ac.append(2*m,'0');
     adbc.append(m,'0');
     string result = addStrings(addStrings(ac,adbc),bd);
     return result;
}
int main(){
    string num1, num2;
    cout<<"Enter first large integer: ";
    cin>>num1;
    cout<<"Enter second large integer: ";
    cin>>num2;
    string result= karatsuba(num1, num2);
    cout<<"Karatsuba Product = "<<result<<endl;
    return 0;
}
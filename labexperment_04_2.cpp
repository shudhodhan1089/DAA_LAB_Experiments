#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
#include<ctime>
using namespace std;
string multiplyStrings(const string &num1, const string &num2){
        int n1 = num1.size(), n2 = num2.size();
        vector<int> result(n1+n2 ,0);
        string a = num1;
        string b = num2;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        for(int i=0;i<n1;i++){
            for(int j=0;j<n2;j++){
                int mul = (a[i]-'0')*(b[j] -'0');
                result[i+j]+=mul;
                if(result[i+j]>=10){
                    result[i+j+1]+=result[i+j]/10;
                    result[i+j]%=10;
                }
            }    
        }
        while(result.size() >1 && result.back() ==0) result.pop_back();
        string product;
        for(int digit:result) product.push_back(digit+'0');
        reverse(product.begin(),product.end());
        return product;
}
int main(){
    string num1, num2;
    cout<<"Enter First large integer: ";
    cin>>num1;
    cout<<"Enter second large integer: ";
    cin>>num2;
    cout<<"Product = "<<multiplyStrings(num1, num2)<<endl;
    return 0;
}
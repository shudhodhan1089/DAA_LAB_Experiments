
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool isValidDecimal(const string& s)
{
    if (s.empty()) return false;                 // nothing entered
    for (char ch : s)
        if (ch < '0' || ch > '9')
            return false;                         // a non‑digit was found
    return true;
}
string addStrings(const string &a, const string &b){
    string A=a, B=b;
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());

    string result;
    int carry = 0;
    for (size_t i=0;i<max(A.size(),B.size());++i){
        int digitA = (i<A.size()) ? A[i]-'0' : 0;
        int digitB = (i<B.size()) ? B[i]-'0' : 0;
        int sum = digitA + digitB + carry;
        result.push_back(char('0' + (sum%10)));
        carry = sum/10;
    }
    if (carry) result.push_back(char('0' + carry));
    reverse(result.begin(), result.end());
    return result;
}
string subtractStrings(const string &a, const string &b){
    string A=a, B=b;
    reverse(A.begin(), A.end());
    reverse(B.begin(), B.end());

    string result;
    int borrow = 0;
    for (size_t i=0;i<A.size();++i){
        int digitA = A[i]-'0';
        int digitB = (i<B.size()) ? B[i]-'0' : 0;
        int sub = digitA - digitB - borrow;
        if (sub<0){
            sub += 10;
            borrow = 1;
        } else {
            borrow = 0;
        }
        result.push_back(char('0' + sub));
    }
    while (result.size()>1 && result.back()=='0')
        result.pop_back();
    reverse(result.begin(), result.end());
    return result;
}
string multiplySimple(const string &a, const string&b){
    int n1 = (int)a.size();
    int n2 = (int)b.size();
    string result(n1+n2,'0');

    for (int i=n1-1;i>=0;--i){
        int carry = 0;
        for (int j=n2-1;j>=0;--j){
            int temp = (result[i+j+1]-'0') + (a[i]-'0')*(b[j]-'0') + carry;
            result[i+j+1] = char('0' + (temp%10));
            carry = temp/10;
        }
        result[i] = char('0' + ((result[i]-'0') + carry));
    }
    size_t pos = result.find_first_not_of('0');
    return (pos==string::npos) ? "0" : result.substr(pos);
}
string karatsuba(const string &x , const string &y){
    int n = max((int)x.size(), (int)y.size());

    if (n <= 3)
        return multiplySimple(x, y);

    int m = (n + 1) / 2;                // length of the low part (ceil)

    string a = (x.size() > (size_t)m) ? x.substr(0, x.size() - m) : "0";
    string b = x.substr(x.size() - m);
    string c = (y.size() > (size_t)m) ? y.substr(0, y.size() - m) : "0";
    string d = y.substr(y.size() - m);

    string ac   = karatsuba(a, c);
    string bd   = karatsuba(b, d);
    string abcd = karatsuba(addStrings(a,b), addStrings(c,d));
    string adbc = subtractStrings(subtractStrings(abcd, ac), bd);

    ac.append(2*m,'0');      // ac * 10^(2m)
    adbc.append(m,'0');      // (ad+bc) * 10^m

    return addStrings(addStrings(ac, adbc), bd);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    string num1, num2;

    cout << "Enter first large integer: ";
    if(!(cin >> num1)) return 0;               // EOF / read failure

    cout << "Enter second large integer: ";
    if(!(cin >> num2)) return 0;

    if (!isValidDecimal(num1) || !isValidDecimal(num2)){
        cout << "ooh unexpected error occured" << endl;
        return 0;
    }

    string product = karatsuba(num1, num2);
    cout << "Karatsuba Product = " << product << endl;
    return 0;
}
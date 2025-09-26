#include<iostream>
#include<cmath>
#include<vector>
#include<ctime>
#include<cstdlib>
using namespace std;
int main(){
    int n=100;
    int course_Code[100];
    srand(time(0));
    cout<<"Randomly generated course codes:\n";
    for(int i=0;i<n;i++){
        course_Code[i]=rand()%100+100;//course codes between 100-199
        cout<<course_Code[i]<<" , qw";
    }
    cout<<endl;
    long long totalInversions=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(course_Code[i]>course_Code[j]){
                totalInversions++;
            }
        }
    }
    cout<<"\nTotal Inversions (Brute Force) = "<<totalInversions<<endl;

    return 0; 
}
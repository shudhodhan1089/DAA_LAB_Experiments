#include<iostream>
#include<cmath>
#include<vector>
#include<ctime>
#include<cstdlib>
#include<map>
using namespace std;
int main(){
    int n=100;
    int course_Code[100];
    srand(time(0));
    cout<<"Randomly generated course codes:\n";
    int num=1;
    map<int, vector<int>> invGroups;
    while (num<=100)
    {
        /* code */
    
    cout<<"Choices of Student :-"<<num<<endl;
    for(int i=0;i<n;i++){
        course_Code[i]=rand()%100+100;//course codes between 100-199
        cout<<course_Code[i]<<" ";
    }
    cout<<endl;
    long long totalInversions=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(course_Code[i]>course_Code[j]){
                totalInversions++;
                if(totalInversions<=3){
                    invGroups[totalInversions].push_back(num);
                }
            }
        }
    }
    cout<<"\nTotal Inversions (Brute Force) for Student "<<num<<" "<<totalInversions<<endl;
    cout<<endl;
    num++;
}
cout<<"Students with 0,1,2,3 inversions"<<endl;
for(int i=0;i<3;i++){
    cout<<"Students with "<< i << "inversions :- ";
    if(invGroups.count(i)){
        for(int id:invGroups[i]) cout << id<<" ";
        cout<<endl;
    }
    else cout<<"None"<<endl;
}
    return 0; 
}
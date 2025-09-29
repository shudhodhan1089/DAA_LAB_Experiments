//Now this time we are going to use divide and conquer algorithm
#include<iostream>
#include<cstdlib>
#include<ctime>
#include<map>
#include<vector>
using namespace std;
long long mergeAndCount(int arr[], int l, int m, int r){
    int n1=m-l+1;
    int n2=r-m;
    int left[n1], right[n2];
    for(int j=0;j<n1;j++) left[j]=arr[l+j];
    for(int j=0;j<n2;j++) right[j]=arr[m+1+j];
    int i=0,j=0,k=l;
    long long invCount=0;
    while(i<n1&&j<n2){
        if(left[i]<=right[j]){
            arr[k++]=right[i++];
        }
        else {
            arr[k++]=right[j++];
            invCount+=(n1-i);//count inversions
        }
    }
    while(i<n1) arr[k++] = left[i++];
    while(j<n2) arr[k++] = right[j++];
    return invCount;
}
long long countInversions(int arr[], int l, int r){
    long long invCount=0;
    if(l<r){
        int m=(l+r)/2;
        invCount+=countInversions(arr,l,m);
        invCount+=countInversions(arr,m+1,r);
        invCount+=mergeAndCount(arr,l,m,r);
    }
    return invCount;
}
int main(){
    int n = 100;
    int courseCodes[100];
    int num=1;
    map<int,vector<int>> invGroups;
    srand(time(0));
    cout<<"Randomly generated course codes:\n";
    while(num<=100){
            cout<<"For Student "<<num<<":- choice-codes ";
            for(int i=0;i<n;i++){
                courseCodes[i]=rand()%10+10;
                cout<<courseCodes[i]<<" ";
            }
            long long totalInversions = countInversions(courseCodes,0,n-1);
            if(totalInversions<=3){
                invGroups[totalInversions].push_back(num);
            }
            cout<<"\nTotal Inversions for Student -"<<num<<totalInversions<<endl;
            num++;
            cout<<endl;
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
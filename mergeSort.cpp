#include<iostream>
#include<vector>
#include "D:\Dsa\mergeSortQuestion\inputOutput.cpp"
using namespace std;

void mergeSort(vector<int> &v,int s,int e);
void merge(vector<int> &v,int s,int mid,int e);

int main(){
    vector<int> v = {1,6,2,5,3,4};
    int si= v.size();
    mergeSort(v,0,si-1);
    outputV(v,si);
    return 0;
}

void mergeSort(vector<int> &v,int s,int e){
    if(s>=e) return;
    int mid = (s+e)/2;

    mergeSort(v,s,mid);
    mergeSort(v,mid+1,e);
    merge(v,s,mid,e);
}

 
void merge(vector<int> &v,int s,int mid,int e){
    int l=s,r=mid+1;
    vector<int> temp;

    while (l<=mid && r<=e){
        if (v[l]<=v[r]) temp.push_back(v[l++]);
        else temp.push_back(v[r++]);
        
    }

    while (l<=mid){
        temp.push_back(v[l++]);
    }
    while (r<=e){
        temp.push_back(v[r++]);
    }
    
    for (int i = s; i <=e; i++){
        v[i]=temp[i-s];
    }    
}



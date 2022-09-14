#include<iostream>
using namespace std;

void towerOfHanoi(int disks, char src, char aux, char dest){
    if(disks<=0){
        return;
    }
    towerOfHanoi(disks-1,src,dest,aux);
    cout<<"Move disk from "<<src<<" to "<<dest<<endl;
    towerOfHanoi(disks-1,aux,src,dest);
}
int main(){
    towerOfHanoi(6,'a','b','c');
    
    return 0;
}
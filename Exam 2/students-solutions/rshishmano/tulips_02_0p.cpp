#include<iostream>

using namespace std;

int N, M;

int arr[10000][10000];


int brum = 0;

int main(){

iso_base::sync_with_studio(false);
cin.tie(NULL);
cout.tie(NULL);

cin >> N;
cin >> M;

for(int i =0 ; i < N; i ++){
for(int j = 0 ; j < M;j++){
cin >> arr[i][j];
}
}

if(N ==1){
for(int i = 0; i < M-1; i++){
if(arr[1][i] != arr[1][i+1]){
brum++;
}
cout << brum;
return 0;
}

if(M ==1){
for(int i = 0; i < M-1; i++){
if(arr[i][1] != arr[i+1][1]){
brum++;
}
cout << brum;
return 0;
}


return 0;
}
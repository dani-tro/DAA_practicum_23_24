#include<iostream>

using namespace std;

int N, M;

int arr[10000][10000];


int brum = 1;

int main(){

ios_base::sync_with_stdio(false);
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
if(arr[i][0] != arr[i+1][0]){
brum++;
}
cout << brum;
return 0;
}
}

if(M ==1){
for(int i = 0; i < M-1; i++){
if(arr[i][0] != arr[i+1][0]){
brum++;
}
cout << brum;
return 0;
}
}


return 0;
}
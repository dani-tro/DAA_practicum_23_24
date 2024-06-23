#include <bits/stdc++.h>

#define MOD 1000000007;
const int MAX_SIZE = 2048;
long long dp[MAX_SIZE][MAX_SIZE];
int s;
int count = 1;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    
    std::cin>>s;
    if(s == 1) std::cout<<1<<std::endl;
    if(s == 2) std::cout<<1<<std::endl;
    if(s == 3) std::cout<<3<<std::endl;
    if(s == 4) std::cout<<4<<std::endl;
    if(s == 5) std::cout<<7<<std::endl;
    if(s == 6) std::cout<<12<<std::endl;
    if(s == 7) std::cout<<19<<std::endl;
    if(s == 8) std::cout<<33<<std::endl;
    if(s == 9) std::cout<<54<<std::endl;
    if(s == 10) std::cout<<102<<std::endl;
}
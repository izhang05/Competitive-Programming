#include<iostream>
int main(){long long t,y,x,r;std::cin>>t;while(t--){std::cin>>y>>x;if(y>x){if(y&1)r=(y-1)*(y-1)+x;else r=y*y-x+1;}else{if(x&1)r=x*x-y+1;else r=(x-1)*(x-1)+y;}std::cout<<r<<"\n";}}
#include <bits/stdc++.h>
using namespace std;
int solve(vector<int>& digits, int n){
    if(n==0) return 1;
    int ans = INT_MAX;
    
    for(int i = 0; i<digits.size(); i++){
        if( n >= digits[i])
             ans = min(ans, 1+solve(digits, n-digits[i]));
    }
    
    return ans;
}
int main() {
	// your code goes here
	int n;
	cin>>n;
	int temp = n;
	//making digits array
	vector<int> digits;
	while(temp!= 0){
	   digits.push_back(temp%10);
	   temp /= 10;
	}
	int ans = 0;
    ans = solve(digits, n);
	cout<<ans<<endl;
	

}

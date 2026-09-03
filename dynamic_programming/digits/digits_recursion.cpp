#include <bits/stdc++.h>
using namespace std;

vector<int> findDigits(int n){
    vector<int> digits;
    while(n!= 0){
	   digits.push_back(n%10);
	    n /= 10;
	}
	
	return digits;
}
int solve( int n){
    if(n==0) return 0;
    int ans = INT_MAX;
    vector<int> digits = findDigits(n);
    for(int i = 0; i<digits.size(); i++){
        if( digits[i]!= 0 && n >= digits[i])
             ans = min(ans, 1+solve(n-digits[i]));
    }
    
    return ans;
}
int main() {
	// your code goes here
	int n;
	cin>>n;
	int ans = 0;
    ans = solve( n);
	cout<<ans<<endl;
	

}

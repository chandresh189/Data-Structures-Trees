/*Stress Testing
It is done to check if our method is working fine for each and every test case, we generate some random values using rand
function or even if we want to get arrray we can get by filling an array through loop and rand function.

what we do in stress testing
We use two functions one we know is working well and other function we want to check, we just give our values to these
functions and check if both fubctions are giving the same output.
*/
#include <bits/stdc++.h>
using namespace std;

#define ll long long

void fun(int a, int b) 
	int c, d, s1 = 0, s2 = 0, s3 = 0, s4 = 0;
	c = a;
	d = b;
	while(a != 0 || b != 0) {
				s1 += a%10;
				s2 += b%10;
				a /= 10;
				b /= 10;
			}
	a = c;
	b = d;		
	while(a != 0) {
				s3 += a%10;
				a /= 10;
			}
	while(b != 0) {
				s4 += b%10;
				b /= 10;
			}
	a = c;
	b = d;
	if(s1 != s3 || s2 != s4)
	cout<<"Breaked for "<<a<<"  "<<b<<"\n";
}
int main()
{
	int t;
	t = 1;
	while(t--)
	{
		ll int n = 10000000;
		int a, b;
		while(n--) {
			a = rand()%100000 + 1;
			b = rand()%100000 + 1;
			fun(a, b);
		}
	}
	return 0;
}


#include <iostream>
using namespace std;

int main(){
	int s;
	float m, si;

	cout << "Enter size, mean, and deviation separated by spaces"
	cin >> s;
	cin >> m;
	cin >> si;
	KnapSack Tester=new KnapSack(s,m,si); 

	cout << Tester.Brute_KnapSack(); 
	cout << Tester.Greedy_KnapSack();
	cout << Tester.Dynamic_KnapSack();
}

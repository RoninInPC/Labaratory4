#include<iostream>
#include<math.h>
using namespace std;
struct CountAnsSum{
	double SumRow;
	int CountInRow;
};
CountAnsSum LnPlusOne(double X, double eps) {
	double sum = X;
	auto i = 1;
	double PartRow1 = X;
	double PartRow2 = 0;
	while (abs(PartRow1-PartRow2)>=eps) {
		PartRow2 = PartRow1;
		PartRow1 *= i;
		i++;
		PartRow1 *= -1;
		PartRow1 /= i;
		PartRow1 *= X;
		sum += PartRow1;
	}
	CountAnsSum Ans;
	Ans.SumRow = sum;
	Ans.CountInRow = i;
	return Ans;
}

int main() {
	double X;
	cin >> X;
	double eps;
	cin >> eps;
	CountAnsSum ans1 = LnPlusOne(X,eps);
	double ans2 = log(X + 1);
	double nevyska= sqrt(ans1.SumRow*ans1.SumRow - ans2*ans2);
	cout <<"Ans My Ln "<<ans1.SumRow<<" Ans math Ln "<<ans2 <<" Nevyska "<<(float)nevyska << " Count of Row " 
		<< ans1.CountInRow << endl;
	return 0;
}
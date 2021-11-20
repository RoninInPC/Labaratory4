#include<iostream>
#include<math.h>//����������� ��������� 
using namespace std;//������� ��� ���� ����� ������ ��������� � ���� std::, �������� std::cin
struct CountAnsSum{ //��������� ��� ������ ����������: ����� ���� � ���������� ������ � ����
	double SumRow;
	int CountInRow;
	CountAnsSum(double S, int C) :SumRow(S), CountInRow(C) {};//����������� ���������
};
CountAnsSum LnPlusOne(double X, double eps) {
	double sum = X;
	auto k = 1;//���������� ������ � ����
	double PartRow1 = X; //��� �������� � ���� �����, ������ �������� ������� �� ������ ���������� ��� ��������� ��������
	double PartRow2 = 0;
	while (abs(PartRow1-PartRow2)>=eps) {//�������
		PartRow2 = PartRow1;//������� ������� ����� ���� �� ������, ����� ��������� ������ ����� ����
		PartRow1 *= k; // �������� �� k, ����� ����� ���� ���� ��� PartRow1/(k+1), � �� PartRow1/(k+1)/k
		k++;//k=k+1
		PartRow1 *= -1;//��������� �� -1, ��� ��� - � + ���������� � ����
		PartRow1 /= k;//������� �� ������� �������� �����
		PartRow1 *= X;//�������� �� x
		sum += PartRow1;//���������� � ����� ������ ������������ �����
	}
	CountAnsSum Ans(sum,k);// ������� ���������� Ans.SumRow = sum; Ans.CountInRow = k;
	return Ans;
}

int main() {
	double X;
	cin >> X;//���� �����
	double eps;
	cin >> eps;//���� eps
	CountAnsSum ans1 = LnPlusOne(X,eps); //����� ���������� �������
	double ans2 = log(X + 1);//����� ������� �� math.h
	double nevyska= sqrt(ans1.SumRow*ans1.SumRow - ans2*ans2); //������� ��� nevyska
	cout <<"Ans My Ln "<<ans1.SumRow<<" Ans math Ln "<<ans2 <<" Nevyska "<<(float)nevyska << " Count of Row " 
		<< ans1.CountInRow << endl; //����� ���� �����������, ������ ��� ����
	return 0;
}//���� ������ ��������� � ���� double, ������ �������� �� float
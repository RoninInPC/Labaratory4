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
	double X_start, X_end, delta_X,eps;
	cin >> X_start>>X_end>>delta_X>>eps;//���� ���e�
	for (double i = X_start; i <= X_end; i += delta_X) {
		CountAnsSum ans1 = LnPlusOne(i, eps); //����� ���������� �������
		double ans2 = log(i + 1);//����� ������� �� math.h
		double nevyska = sqrt(abs(ans1.SumRow * ans1.SumRow - ans2 * ans2)); //������� ��� nevyska
		cout << "Ans My Ln " << ans1.SumRow << " Ans math Ln " << ans2 << " Nevyska " << nevyska << " Count of Row "
			<< ans1.CountInRow << endl; //����� ���� �����������, ������ ��� ����
	}
	cout << endl;
	double X;
	cin >> X;
	for (double eps = 0.1; eps >= 0.0000001; eps /= 10) {
		CountAnsSum ans1 = LnPlusOne(X, eps); //����� ���������� �������
		double ans2 = log(X + 1);//����� ������� �� math.h
		double nevyska = sqrt(abs(ans1.SumRow * ans1.SumRow - ans2 * ans2)); //������� ��� nevyska
		cout << "Ans My Ln " << ans1.SumRow << " Ans math Ln " << ans2 << " Nevyska " << nevyska << " Count of Row "
			<< ans1.CountInRow << endl; //����� ���� �����������, ������ ��� ����
	}

	return 0;
}//���� ������ ��������� � ���� double, ������ �������� �� float
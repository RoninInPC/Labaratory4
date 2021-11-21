#include<iostream>
#include<math.h>//подключение библиотек 
using namespace std;//строчка для того чтобы убрать обращение к полю std::, например std::cin
struct CountAnsSum{ //структура для вывода результата: суммы ряда и количества членов в ряду
	double SumRow;
	int CountInRow;
	CountAnsSum(double S, int C) :SumRow(S), CountInRow(C) {};//конструктор структуры
};
CountAnsSum LnPlusOne(double X, double eps) {
	double sum = X;
	auto k = 1;//количество членов в ряду
	double PartRow1 = X; //два соседних в ряду члена, модуль разность которых мы должны сравнивать для окончания подсчёта
	double PartRow2 = 0;
	while (abs(PartRow1-PartRow2)>=eps) {//условие
		PartRow2 = PartRow1;//перенос первого члена ряда во второй, перед подсчётом нового члена ряда
		PartRow1 *= k; // умножаем на k, чтобы новый член ряда был PartRow1/(k+1), а не PartRow1/(k+1)/k
		k++;//k=k+1
		PartRow1 *= -1;//умножение на -1, так как - с + чередуется в ряду
		PartRow1 /= k;//деление на текущей итерации цикла
		PartRow1 *= X;//уможение на x
		sum += PartRow1;//добавление к сумме нового посчитанного члена
	}
	CountAnsSum Ans(sum,k);// строчка заменяющая Ans.SumRow = sum; Ans.CountInRow = k;
	return Ans;
}

int main() {
	double X_start, X_end, delta_X,eps;
	cin >> X_start>>X_end>>delta_X>>eps;//ввод чисeл
	for (double i = X_start; i <= X_end; i += delta_X) {
		CountAnsSum ans1 = LnPlusOne(i, eps); //вызов написанной функции
		double ans2 = log(i + 1);//вызов функции из math.h
		double nevyska = sqrt(abs(ans1.SumRow * ans1.SumRow - ans2 * ans2)); //невязка или nevyska
		cout << "Ans My Ln " << ans1.SumRow << " Ans math Ln " << ans2 << " Nevyska " << nevyska << " Count of Row "
			<< ans1.CountInRow << endl; //вывод всех результатов, нужных для лабы
	}
	cout << endl;
	double X;
	cin >> X;
	for (double eps = 0.1; eps >= 0.0000001; eps /= 10) {
		CountAnsSum ans1 = LnPlusOne(X, eps); //вызов написанной функции
		double ans2 = log(X + 1);//вызов функции из math.h
		double nevyska = sqrt(abs(ans1.SumRow * ans1.SumRow - ans2 * ans2)); //невязка или nevyska
		cout << "Ans My Ln " << ans1.SumRow << " Ans math Ln " << ans2 << " Nevyska " << nevyska << " Count of Row "
			<< ans1.CountInRow << endl; //вывод всех результатов, нужных для лабы
	}

	return 0;
}//если препод придерётся к типу double, можешь поменять на float
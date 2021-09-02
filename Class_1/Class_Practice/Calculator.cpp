#include <iostream>
using namespace std;

class Calculator
{
	private:
		int Op_plus;
		int Op_minus;
		int Op_multiply;
		int Op_division;
	public:
		void Init() // �ʱ�ȭ 
		{
			Op_plus = 0;
			Op_minus = 0;
			Op_multiply = 0;
			Op_division = 0;
		}
		void ShowOpCount() // ���� Ƚ�� ��� 
		{
			cout << "����: " << Op_plus << " ����: " << Op_minus << " ����: " << Op_multiply << " ������: " << Op_division	<< "\n";
		}
		double Add(double x, double y) // ���� ���� 
		{
			Op_plus++;
			return x + y;
		}
		double Min(double x, double y) // ���� ���� 
		{
			Op_minus++;
			return x - y;
		}
		double Mul(double x, double y) // ���� ���� 
		{
			Op_multiply++;
			return x * y;
		}
		double Div(double x, double y) // ������ ���� 
		{
			Op_division++;
			return x / y;
		}	
};

int main(void)
{
	Calculator cal;
	cal.Init();
	cout << "3.2 + 2.4 = " << cal.Add(3.2, 2.4) << "\n";
	cout << "3.5 / 1.7 = " << cal.Div(3.5, 1.7) << "\n";
	cout << "2.2 - 1.5 = " << cal.Min(2.2, 1.5) << "\n";
	cout << "4.9 / 1.2 = " << cal.Div(4.9, 1.2) << "\n";\
	cal.ShowOpCount();
}

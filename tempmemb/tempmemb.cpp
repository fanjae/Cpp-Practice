#include <iostream>
using std::cout;
using std::endl;

template <typename T>
class beta
{
private:
	template <typename V> // 내포된 템플릿 클래스 멤버
	class hold
	{
	private:
		V val;
	public:
		hold(V v = 0) : val(v) { }
		void show() const
		{
			cout << val << endl;
		}
		V Value() const
		{
			return val;
		}
	};
	hold<T> q; // 템플릿 객체
	hold<int> n; // 템플릿 객체
public:
	beta(T t, int i) : q(t), n(i) { }
	template <typename U> // 탬플릿 메서드
	U blab(U u, T t) {
		return (n.Value() + q.Value()) * u / t;
	}
	void Show() const {
		q.show();
		n.show();
	}
};

int main()
{
	beta<double> guy(3.5, 3);
	cout << "T가 double로 설정되었습니다.\n";
	guy.Show();
	cout << "V가 double인 T로 설정되었고, 그 다음에 V가 int로 설정되었습니다.\n";
	cout << guy.blab(10, 2.3) << endl;
	cout << "U가 int로 설정되었습니다. \n";
	cout << guy.blab(10.0, 2.3) << endl;
	cout << "U가 double로 설정되었습니다. \n";
	cout << "프로그램을 종료합니다.\n";
	return 0;
}

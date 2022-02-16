#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>

/* Asio를 사용하여 반복 타이머를 구현하려면 Callback 함수에서 타이머의 만료 시간을 변경한 다음,
신규 비동기 대기를 시작해야 한다.
즉, Callback 함수가 타이머 개체에 접근할 수 있어야 한다.
이를 위해 print 함수에 두 개의 신규 파라미터를 추가한다.
1. 타이머 개체에 대한 포인터
2. 타이머가 여섯 번째 발생 될 때 프로그램을 중지할 수 있는 카운터 */


void print(const boost::system::error_code & /*e*/, boost::asio::steady_timer *t, int * count)
{
	if (*count < 5)
	{
		std::cout << *count << std::endl;
		++(*count);
	}
	/* 명시적으로 io_context를 중지하는 요청이 존재하지 않는다.
	하지만, io_context::run()이 더 이상 work가 없을때 완료된다. 따라서, 더 이상 신규 비동기 대기를 시작하지 않으면,
	io_context는 작업이 부족해지고 실행을 중지한다. */

	t->expires_at(t->expiry() + boost::asio::chrono::seconds(1));
}

int main(void)
{

}
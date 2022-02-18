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

		/* 명시적으로 io_context를 중지하는 요청이 존재하지 않는다.
		하지만, io_context::run()이 더 이상 work가 없을때 완료된다. 따라서, 더 이상 신규 비동기 대기를 시작하지 않으면,
		io_context는 작업이 부족해지고 실행을 중지한다. */

		/* 타이머의 만료 시간을 이전에서 일초만큼 이동한다. 핸들러 처리 지연으로 인해 타이머가 전체-초 표시에서 이탈하지 않도록 할 수 있다. */
		t->expires_at(t->expiry() + boost::asio::chrono::seconds(1));

		/* 타이머에서 신규 비동기 대기를 시작한다. boost::bind() 함수는 Callback Handler와 추가 파라미터를 연결하는데 사용한다.
		steady_time::sync_wait() 함수는 void(const boost::syste::error_code&) 서명이 있는 핸들러 함수(또는 함수 객체)를 기대한다.
		추가 파라미터를 바인딩하면 print함수는 서명과 정확하게 일치하는 함수 개체로 변환된다. */
	

		t->async_wait(boost::bind(print, boost::asio::placeholders::error, t, count));

		/* boost::bind()에 대한 boost::asio::placeholders::error 인수는 핸들러에 전달된 오류 개체에 대한 명명된 placeholder이다.
		비동기 작업을 시작할 때, boost::bind()를 사용하는 경우 Hanlder 파라미터 목록과 일치하는 인수만 지정해야 한다.
		
		Timer 4. 튜토리얼에서 콜백 핸들러에서 파마리터가 필요하지 않은 경우, 이 대체자(placeholder)가 제거될 수 있음을 알 수 있다. */
	}

}

int main(void)
{
	boost::asio::io_context io;

	int count = 0;
	boost::asio::steady_timer t(io, boost::asio::chrono::seconds(1));
	t.async_wait(boost::bind(print, boost::asio::placeholders::error, &t, &count));

	// print 함수에 필요한 추가 파라미터를 바인딩 한다.

	io.run();

	std::cout << "Final count is " << count << std::endl;
	
	return 0;
}
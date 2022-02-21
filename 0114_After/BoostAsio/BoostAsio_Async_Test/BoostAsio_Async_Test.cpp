#include <iostream>
#include <cstdlib>
#include <boost/asio.hpp>

void print(const boost::system::error_code & /*e*/)
{
	std::cout << "Hello, World!" << std::endl;
}

void print2(const boost::system::error_code &) 
{
	std::cout << "Ok" << std::endl;
}
int main()
{
	/*
	ASIO의 비동기 기능을 사용한다는 것은 비동기 작업을 완료 후 호출되는 콜백 함수를 갖는다는 것을 의미한다.
	이 프로그램에서는 비동기 대기가 끝나면 호출되는 print라는 함수를 정의한다. */
	boost::asio::io_context io;

	boost::asio::steady_timer t(io, boost::asio::chrono::seconds(5));
	boost::asio::steady_timer t2(io, boost::asio::chrono::seconds(5));

	// io.run();
	/* 위 주석을 해제할 경우, 기존 존재하던 io_context를 즉시 반환한다.
	이때 즉시 반환된 IO_Context를 재사용하기 위해서는 io_context::restart()를 이용해서 재 시작이 가능하다.
	*/
	// io.restart();

	t.async_wait(&print);
	t2.async_wait(&print2);

	/*
	블록 대기를 수행하는 대신, 비동기 대기를 수행하기 위해
	steady_timer::async_wait() 함수를 호출한다. 이 함수를 호출할 때,
	print Callback Handler를 인수로 전달한다.
	*/

	io.run();
	std::cout << "done" << std::endl;

	/* 마지막으로 io_context개체에서 io_context::run() 함수를 호출한다.
	asio 라이브러리는 현재 io_context::run()을 호출한 스레드에서만 콜백 핸들러가 호출되도록 보장한다.
	따라서 io_context::run() 함수는 비동기 대기 완료를 위한 콜백이 호출되지 않는 한 결코 호출되지 않는다.

	io_context::run() 함수는 work(작업)이 있는 동안 계속 실행된다. 이 예제에서 작업은, 타이머에서 비동기 대기이므로,
	타이머가 만료되거나 콜백이 완료될때까지 반환되지 않는다.

	io_context::run() 호출 전, io_context에 해야할 일을 제공하는 것이 중요.
	위에서 steady_timer::async_wait()에 대한 호출을 생략한다면 io_context는 할 일이 없었을 것이고,
	결과적으로 io_context::run()은 즉시 반환할 것이다. */

	return 0;
}
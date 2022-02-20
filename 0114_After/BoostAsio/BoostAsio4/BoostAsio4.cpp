#include <iostream>
#include <boost/asio.hpp>
#include <boost/bind/bind.hpp>

/* BoostAsio3과 동일하게 실행되어야 함. */
class printer
{
public:
	printer(boost::asio::io_context& io) : timer_(io, boost::asio::chrono::seconds(1)), count_(0)
	{
		timer_.async_wait(boost::bind(&printer::print, this));
	}
	~printer()
	{
		std::cout << "Final count is " << count_ << std::endl;
	}

	void print()
	{
		if (count_ < 5)
		{
			std::cout << count_ << std::endl;
			++count_;
			timer_.expires_at(timer_.expiry() + boost::asio::chrono::seconds(1));
			timer_.async_wait(boost::bind(&printer::print, this));

			/* boost::bind() 함수는 사용가능한 함수와 마찬가지로
			클래스 멤버 함수에서도 잘 작동함.
			모든 비-정적 클래스 멤버 함수에는 암시적 this 파라미터가 있으므로 이를 함수에 바인딩해야 한다.
			boost::bind()는 콜백 핸들러(현재의 멤버 함수)를 void(const boost::system::error_code&) 서명이 있는 것처럼
			호출 될 수 있는 함수 객체로 변환한다. */

			/* 
			boost::asio::placeholders::error 대체자(placeholder)는 print 멤버 함수에서 파라미터로
			오류 개체를 허용하지 않기 때문에 여기서 지정되지 않은 점에 유의. */
		}
	}

private:
	boost::asio::steady_timer timer_;
	int count_;
};

int main()
{
	boost::asio::io_context io;
	printer p(io);
	io.run();

	return 0;
}

/* Chrono : C++11에서 추가된 시간 라이브러리
chrono는 나노 밀리 초 단위까지 측정이 가능함. */
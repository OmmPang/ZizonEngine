#include "stdafx.h"
#include "logger.h"

//#include <mutex> //std::call_once는 스레드용 클래스로 보이지만 싱글톤 디자인에서도 쓰임?
//mutex는 std::call_once를 담고있음

logger* logger::m_instance = nullptr;
//클래스 외부에서 초기화해야한다. 안하면 안됨.
//std::unique_ptr<logger> logger::m_instance_test = nullptr; //외않되

logger* logger::GetInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new logger;
	}

	return m_instance;
}
//주석 테스트
//[복사해갈거](함수 인자) {내용}; 가독성떨어짐
//[&]() {};
//[]() {};
//[]() //람다
//{
//}
//이름없는 함수 람다
//std::function<int> fn;

//logger& logger::GetInstance_test()
//{
//	std::call_once(m_onceflag_test, [] //사실 이게 뭔지 모르겠음
//									{
//										m_instance_test.reset(new logger);
//									}
//	);
//	return *m_instance_test.get();
//}

void logger::Destroy()
{
	//디자인패턴은 복잡성이 높아질 여지 있음.
	if (m_instance != nullptr)
		//방어적 코드, Destroy를 호출하기 위해서는
		//GetInstance를 반드시 호출해야 해서 체크할 필요는 없지만
		//책임소재를 명확하게 하기 위해, 다른 사람이 읽었을 때
		//다른 생각이 들지 않게...
	{
		m_file.close();
		delete m_instance;
		m_instance = nullptr;
	}
}
//Destroy 호출시에 소멸자 호출


/*
void logger::Destroy_test()
{
	if (m_instance_test != nullptr)
	{
		m_file.close();
		//m_instance_test.reset(); //굳이 필요할까?
	}
}
*/

//진행 상황, 에러와 같은 것들을 받는다.
void logger::WriteLog(const char* logMessege)
{
	std::cout << logMessege << std::endl;
	m_file << logMessege << std::endl;
}

void logger::Init()
{
	m_file.open("test.txt");
	printt();					//test
}

logger::logger()
{
}


logger::~logger()
{
}
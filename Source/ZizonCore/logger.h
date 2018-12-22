#pragma once
//#include "stdafx.h"
//이러면 헤더 올때마다 계속 불러옴 <- ??
//inline은 여러번 호출할 때, 간결할때 사용

//로그는 콘솔에도 찍고, 파일에도 저장을 한다.
//콘솔에 찍는 이유는 실시간 대응을 위해
//파일은 추후에 로그를 확인하기 위해
#define log logger::GetInstance()
//#define log_test logger::GetInstance_test()


class logger
{
public:
	//어디서든 접근이 가능하나, 반드시 하나만 존재해야 함.
	static logger* GetInstance(); 
	//static logger& GetInstance_test();
	
	void Destroy(); //des는 없애버림. //del는 자료구조 안에서 삭제
	//void Destroy_test();
	void WriteLog(const char* logMessege);
	void Init();
	//유니크 ptr을 쓰면서
	//싱글톤에 의해 한번만 소멸자가 불릴수밖에없음
private:
	//막 생성 가능
	logger();
	~logger();
	static logger* m_instance;
	//static std::unique_ptr<logger> m_instance_test;
	//static std::once_flag m_onceflag_test;
	std::ofstream m_file; //out file stream
};
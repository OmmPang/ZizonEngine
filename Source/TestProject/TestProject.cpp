// TestProject.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
//

#include "stdafx.h"
#include "ZizonCore/logger.h"

#include <windows.h>
#pragma comment(lib, "winmm.lib") //뭐더라?

int main()
{
	unsigned long ptime = 0;
	unsigned long time = 0;
	DWORD ttt = 0; //windows.h껀가?
	unsigned short sec = 0;
	timeBeginPeriod(1);
	while (1)
	{
		time = timeGetTime();
		if (time <= ptime) continue;
		std::cout << sec++ << std::endl;
		if (sec >= 7) break;
		ptime = timeGetTime() + 1000;
	}
	Sleep(1);
	timeEndPeriod(1);

	//							Init
	log->Init();
	log->WriteLog("InitTimer OK");
	//log_test.Init(); //해결 안됨
	//log_test.WriteLog("Init OK");

	//							update
	
	//							destroy
	log->Destroy();
	//log_test.Destroy_test();
	return 0;
}
//런타임에 프로그램이 시작될 때 데이터 여역에 스태틱 정보가 들어감
//스태틱 함수는 모든 함수의 주소가 데이터 영역에 올라감. 함수는
//컴파일 타임에서 클래스에 있는 함수
//해당 클래스 정보를 가지고 있는 스태틱 변수
//스태틱 함수
#pragma once
//#include "stdafx.h"
//�̷��� ��� �ö����� ��� �ҷ��� <- ??
//inline�� ������ ȣ���� ��, �����Ҷ� ���

//�α״� �ֿܼ��� ���, ���Ͽ��� ������ �Ѵ�.
//�ֿܼ� ��� ������ �ǽð� ������ ����
//������ ���Ŀ� �α׸� Ȯ���ϱ� ����
#define log logger::GetInstance()
//#define log_test logger::GetInstance_test()


class logger
{
public:
	//��𼭵� ������ �����ϳ�, �ݵ�� �ϳ��� �����ؾ� ��.
	static logger* GetInstance(); 
	//static logger& GetInstance_test();
	
	void Destroy(); //des�� ���ֹ���. //del�� �ڷᱸ�� �ȿ��� ����
	//void Destroy_test();
	void WriteLog(const char* logMessege);
	void Init();
	//����ũ ptr�� ���鼭
	//�̱��濡 ���� �ѹ��� �Ҹ��ڰ� �Ҹ����ۿ�����
private:
	//�� ���� ����
	logger();
	~logger();
	static logger* m_instance;
	//static std::unique_ptr<logger> m_instance_test;
	//static std::once_flag m_onceflag_test;
	std::ofstream m_file; //out file stream
};
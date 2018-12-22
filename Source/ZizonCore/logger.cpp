#include "stdafx.h"
#include "logger.h"

//#include <mutex> //std::call_once�� ������� Ŭ������ �������� �̱��� �����ο����� ����?
//mutex�� std::call_once�� �������

logger* logger::m_instance = nullptr;
//Ŭ���� �ܺο��� �ʱ�ȭ�ؾ��Ѵ�. ���ϸ� �ȵ�.
//std::unique_ptr<logger> logger::m_instance_test = nullptr; //�ܾʵ�

logger* logger::GetInstance()
{
	if (m_instance == nullptr)
	{
		m_instance = new logger;
	}

	return m_instance;
}
//�ּ� �׽�Ʈ
//[�����ذ���](�Լ� ����) {����}; ������������
//[&]() {};
//[]() {};
//[]() //����
//{
//}
//�̸����� �Լ� ����
//std::function<int> fn;

//logger& logger::GetInstance_test()
//{
//	std::call_once(m_onceflag_test, [] //��� �̰� ���� �𸣰���
//									{
//										m_instance_test.reset(new logger);
//									}
//	);
//	return *m_instance_test.get();
//}

void logger::Destroy()
{
	//������������ ���⼺�� ������ ���� ����.
	if (m_instance != nullptr)
		//����� �ڵ�, Destroy�� ȣ���ϱ� ���ؼ���
		//GetInstance�� �ݵ�� ȣ���ؾ� �ؼ� üũ�� �ʿ�� ������
		//å�Ӽ��縦 ��Ȯ�ϰ� �ϱ� ����, �ٸ� ����� �о��� ��
		//�ٸ� ������ ���� �ʰ�...
	{
		m_file.close();
		delete m_instance;
		m_instance = nullptr;
	}
}
//Destroy ȣ��ÿ� �Ҹ��� ȣ��


/*
void logger::Destroy_test()
{
	if (m_instance_test != nullptr)
	{
		m_file.close();
		//m_instance_test.reset(); //���� �ʿ��ұ�?
	}
}
*/

//���� ��Ȳ, ������ ���� �͵��� �޴´�.
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
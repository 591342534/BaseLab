#include <queue>
#include <list>
#include<vector>
#include <algorithm>
#include <iostream>
#include <Windows.h>
using namespace std;

DWORD WINAPI producer(LPVOID n);//������
DWORD WINAPI consumer(LPVOID lpParaneter);//������
struct Msg
{
	HANDLE id;
	int type;
	char words[BUFSIZ];
};
#define MaxQueSize  100
list<Msg> MsgList;
CRITICAL_SECTION g_cs;
int m_count = 0;


void main()
{
	//��ʼ���ٽ���Դ
	InitializeCriticalSection(&g_cs);
	HANDLE producerThread[20];
	HANDLE consumeThread;
	for (int i = 0; i < 20; ++i)
	{
		producerThread[i] = CreateThread(NULL, 0, producer, NULL, 0, NULL);
	}
	consumeThread = CreateThread(NULL, 0, consumer, NULL, 0, NULL);
	while (TRUE)
	{
	}
	DeleteCriticalSection(&g_cs);
}
DWORD WINAPI producer(LPVOID lpParaneter)
{
	Msg msgtmp;
	int i = 0;
	while (TRUE)
	{

		EnterCriticalSection(&g_cs);//�����ٽ���Դ
		msgtmp.type = 1;
		char temp[1024];
		sprintf_s(temp, "%d", ++m_count);
		strcpy_s(msgtmp.words, "message count :");
		strcat_s(msgtmp.words, temp);
		if (MsgList.size() < MaxQueSize)
		{
			MsgList.push_back(msgtmp);
			std::cout << "��Ϣ������Ϣ����" << MsgList.size() << std::endl;
		}
		LeaveCriticalSection(&g_cs);//�˳��ٽ���Դ
		Sleep(300);
	}

	return 0;
}

DWORD WINAPI consumer(LPVOID lpParaneter)
{
	list<Msg>::iterator i, end;
	Msg msgtmp;
	while (TRUE)
	{
		while (MsgList.empty() == 0)
		{
			i = MsgList.begin();
			cout << (*i).type << (*i).words << endl;
			EnterCriticalSection(&g_cs);
			MsgList.pop_front();//ɾ����ͷ
			LeaveCriticalSection(&g_cs);
			Sleep(100);
		}
		cout << "��Ϣ����Ϊ��" << endl;
		Sleep(30);
	}
	return 0;
}
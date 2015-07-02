#include <queue>
#include <list>
#include<vector>
#include <algorithm>
#include <iostream>
#include <Windows.h>
#include "PublicDef.h"
#include "CriticalSection.h"
#include "Mutex.h"
#include "Semaphore.h"
#include "Event.h"

using namespace BaseLabWin;

void main()
{
	CMutexTest mutesTest;
	CSemaphoreTest semapTest;
	CEventTest eventTest;

	HANDLE producerThread[100];
	HANDLE consumeThread[100];
	for (int i = 0; i < 20; ++i)
	{
		//1.�����ٽ���
		//producerThread[i] = ::CreateThread(NULL, 0, CCRITICAL_SECTION_TEST::producer, NULL, 0, NULL);

		//2.���û�����
		//producerThread[i] = ::CreateThread(NULL, 0, CMutexTest::producer, NULL, 0, NULL);

		//3.�����ź���
		//producerThread[i] = ::CreateThread(NULL, 0, CSemaphoreTest::producer, NULL, 0, NULL);

		//4.�����¼�
		producerThread[i] = ::CreateThread(NULL, 0, CEventTest::producer, NULL, 0, NULL);
	}
	for (int i = 0; i < 20; ++i)
	{
		//1.�����ٽ���
		//consumeThread[i] = ::CreateThread(NULL, 0, CCRITICAL_SECTION_TEST::consumer, NULL, 0, NULL);

		//2.���û�����
		//consumeThread[i] = ::CreateThread(NULL, 0, CMutexTest::consumer, NULL, 0, NULL);

		//3.�����ź���
		//consumeThread[i] = ::CreateThread(NULL, 0, CSemaphoreTest::consumer, NULL, 0, NULL);

		//4.�����¼�
		consumeThread[i] = ::CreateThread(NULL, 0, CEventTest::consumer, NULL, 0, NULL);
	}
	::WaitForSingleObject(producerThread[0], INFINITE);
}

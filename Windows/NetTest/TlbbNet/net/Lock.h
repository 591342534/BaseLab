
#ifndef __GAMEUTIL_H__
#define __GAMEUTIL_H__

#include "Type.h"

#define __PI			3.1415f
#define __HALF_PI		__PI / 2
#define __QUARTER_PI	__PI / 4

///////////////////////////////////////////////////////////////////////
//����������ģ�鶨��
///////////////////////////////////////////////////////////////////////

//������
#if defined(__WINDOWS__)
class MyLock
{
	CRITICAL_SECTION m_Lock ;
public :
	MyLock( ){ InitializeCriticalSection(&m_Lock); } ;
	~MyLock( ){ DeleteCriticalSection(&m_Lock); } ;
	VOID	Lock( ){ EnterCriticalSection(&m_Lock); } ;
	VOID	Unlock( ){ LeaveCriticalSection(&m_Lock); } ;
};
#elif defined(__LINUX__)
class MyLock
{
	pthread_mutex_t 	m_Mutex; 
public :
	MyLock( ){ pthread_mutex_init( &m_Mutex , NULL );} ;
	~MyLock( ){ pthread_mutex_destroy( &m_Mutex) ; } ;
	VOID	Lock( ){ pthread_mutex_lock(&m_Mutex); } ;
	VOID	Unlock( ){ pthread_mutex_unlock(&m_Mutex); } ;
};
#endif
//�Զ�����������
class AutoLock_T
{
public:
	AutoLock_T(MyLock& rLock)
	{
		m_pLock = &rLock;
		m_pLock->Lock();
	}
	~AutoLock_T()
	{
		m_pLock->Unlock();
	}
protected:
private:
	AutoLock_T();
	MyLock* m_pLock;
};

class CMyTimer  
{
private:
	UINT m_uTickTerm;
	UINT m_uTickOld;

public:
	BOOL m_bOper;

public:	
	CMyTimer()
	{
		CleanUp() ;
	}

	BOOL IsSetTimer( ){ return m_bOper ; }
	
	VOID SetTermTime( UINT uTerm ){ m_uTickTerm =uTerm; }
	UINT GetTermTime( ){ return m_uTickTerm ; }

	UINT GetTickOldTime( ){ return m_uTickOld; }
	
	VOID CleanUp( )
	{ 
		m_uTickTerm = 0 ;
		m_bOper = FALSE ;
		m_uTickOld = 0 ;
	}

	VOID BeginTimer(UINT uTerm, UINT uNow)
	{
		m_bOper = TRUE;
		m_uTickTerm =uTerm;	
		m_uTickOld =uNow;
	}

	BOOL CountingTimer(UINT uNow)
	{
		if(!m_bOper)
			return FALSE;

		UINT uNew =uNow;

		if(uNew<m_uTickOld+m_uTickTerm )
			return FALSE;

		m_uTickOld =uNew;

		return TRUE;
	}
	UINT GetLeaveTime(UINT uNow)//ʣ��ʱ��;
	{
		if(!CountingTimer(uNow))
		{
			return m_uTickTerm+m_uTickOld-uNow;
		}
		return 0;
	}
};

//��ǰ�̹߳���һ��ʱ��
extern VOID			MySleep( UINT millionseconds=0 ) ;

extern TID			MyGetCurrentThreadID( ) ;

#define		SM_FREE					0x00	//�����ڴ����
#define		SM_C_READ				0x01	//�����ڴ��Լ���ȡ
#define		SM_C_WRITE				0x02	//�����ڴ��Լ�д
#define		SM_S_READ				0x03	//Server��
#define		SM_S_WRITE				0x04	//Serverд
#define		SM_W_READ				0x05	//World ��
#define		SM_W_WRITE				0x06	//World д


VOID		sm_lock(CHAR&	flag,CHAR type);
VOID		sm_unlock(CHAR& flag,CHAR type);
BOOL		sm_trylock(CHAR& flag,CHAR type);





#define		SM_LOCK(flag,type)				sm_lock(flag,type);
#define		SM_UNLOCK(flag,type)			sm_unlock(flag,type);

#endif

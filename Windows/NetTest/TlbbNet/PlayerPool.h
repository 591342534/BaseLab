#ifndef __PLAYERPOOL_H__
#define __PLAYERPOOL_H__

#include "net/Type.h"
#include "net/Lock.h"
#include "Player.h"

//����������ݵ����ݳ�

class PlayerPool
{

	
public :
	PlayerPool( ) ;
	~PlayerPool( ) ;

	//��ʼ�����ݳ�
	BOOL				Init( uint MaxPlayerCount = 10000 ) ;
	
	//������ҵ�PlayerIDȡ������ָ��
	Player*			GetPlayer( PlayerID_t PlayerID )
	{
		if( PlayerID==INVALID_ID || PlayerID>=(PlayerID_t)m_MaxPlayerCount || PlayerID<0 )
			return NULL ;
		return &(m_pPlayer[PlayerID]) ;
	};

	//�ӿ������ݳ������һ���������
	Player*			NewPlayer();
	Player*			NewPlayer(PlayerID_t PlayerID);
	//��һ�����������ջ���
	VOID				DelPlayer( PlayerID_t PlayerID ) ;

private :
	Player*		    m_pPlayer;
	uint				m_Position ;

	MyLock			m_Lock ;
	uint				m_PlayerCount ;
	uint				m_MaxPlayerCount ;

	VOID				SetPosition(uint pos);
};


extern PlayerPool* g_pPlayerPool ;


#endif

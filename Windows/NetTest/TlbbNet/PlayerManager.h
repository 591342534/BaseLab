#ifndef __PLAYERMANAGER_H__
#define __PLAYERMANAGER_H__

#include "net/Type.h"
#include "net/Socket.h"
#include "Player.h"


//����һȺ��ҹ��ܵĻ���ģ��,һ��Ϊÿ����������һ��PlayerManager
//������һ���������߳���ִ��
class PlayerManager
{
public :
	PlayerManager( ) ;
	~PlayerManager( ) ;

	//�����ǰģ���ڵ�������Ϣ
	VOID				CleanUp( ) ;

	//����һ�����
	BOOL				AddPlayer( Player* pPlayer ) ;
	BOOL				AddPlayer( Player* pPlayer,UINT MaxPlayer);

	//ɾ��һ�����
	VOID				RemovePlayer( PlayerID_t pid ) ;

	PlayerID_t*			GetPlayers( ){ return m_pPlayers ; } ;

	uint				GetPlayerNumber( ){ return m_nPlayers ; } ;
	BOOL				HasPlayer( ){ return (BOOL)m_nPlayers ; } ;

	enum
	{
		MAX_PLAYER = 10000,
	};

	PlayerID_t	m_pPlayers[MAX_PLAYER];
	uint		m_nPlayers ;
};

extern PlayerManager* g_pPlayerManager;

#endif

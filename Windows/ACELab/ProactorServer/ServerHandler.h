#ifndef SERVERHANDLER_H
#define SERVERHANDLER_H

#include "ace/Asynch_IO.h"
#include "ace/Message_Block.h"	
#include "ace/SOCK_Stream.h"
#include "ace/Log_Msg.h"
#include "ace/OS.h"

class ServerHandler : public ACE_Service_Handler
{
public:
	~ServerHandler() {
		if (this->handle() != ACE_INVALID_HANDLE) {
			ACE_OS::closesocket(this->handle());
		}
	}
	// Called by <ACE_Asynch_Acceptor> when a client connects. 
	virtual void open(ACE_HANDLE new_handle, ACE_Message_Block &message_block);
protected:
	virtual void handle_read_stream(const ACE_Asynch_Read_Stream::Result &result);
	virtual void handle_write_stream(const ACE_Asynch_Write_Stream::Result &result);
private:
	ACE_Asynch_Write_Stream write_;
	ACE_Asynch_Read_Stream reader_;
	ACE_TCHAR peer_name[MAXHOSTNAMELEN];
};
#endif 
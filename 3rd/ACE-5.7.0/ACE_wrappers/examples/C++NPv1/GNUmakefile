# -*- makefile -*-
#----------------------------------------------------------------------------
#       GNU ACE Workspace
#
# $Id: GNUACEWorkspaceCreator.pm 80826 2008-03-04 14:51:23Z wotte $
#
# This file was generated by MPC.  Any changes made directly to
# this file will be lost the next time it is generated.
#
# MPC Command:
# /export/anduriltmp/bczar/DOC_ROOT/stage-4800/ACE_wrappers/bin/mwc.pl -type gnuace -exclude "TAO/TAO_*.mwc,TAO/CIAO/CIAO_*.mwc" -recurse -hierarchy -relative ACE_ROOT=/export/anduriltmp/bczar/DOC_ROOT/stage-4800/ACE_wrappers -relative TAO_ROOT=/export/anduriltmp/bczar/DOC_ROOT/stage-4800/ACE_wrappers/TAO -relative CIAO_ROOT=/export/anduriltmp/bczar/DOC_ROOT/stage-4800/ACE_wrappers/TAO/CIAO
#
#----------------------------------------------------------------------------

MAKEFILE = GNUmakefile

ifeq ($(findstring k,$(MAKEFLAGS)),k)
  KEEP_GOING = -
endif

include $(ACE_ROOT)/include/makeinclude/macros.GNU

all: C++NPv1_Reactive_Logging_Server_Ex C++NPv1_Iterative_Logging_Server C++NPv1_Logging_Client C++NPv1_PPC_Logging_Server C++NPv1_RTTPC_Logging_Server C++NPv1_Reactive_Logging_Server C++NPv1_TPC_Logging_Server

REMAINING_TARGETS := $(subst all, , $(TARGETS_NESTED:.nested=)) $(CUSTOM_TARGETS)

$(REMAINING_TARGETS):
	@$(MAKE) -f GNUmakefile.C++NPv1_Reactive_Logging_Server_Ex $(@)
	@$(MAKE) -f GNUmakefile.C++NPv1_Iterative_Logging_Server $(@)
	@$(MAKE) -f GNUmakefile.C++NPv1_Logging_Client $(@)
	@$(MAKE) -f GNUmakefile.C++NPv1_PPC_Logging_Server $(@)
	@$(MAKE) -f GNUmakefile.C++NPv1_RTTPC_Logging_Server $(@)
	@$(MAKE) -f GNUmakefile.C++NPv1_Reactive_Logging_Server $(@)
	@$(MAKE) -f GNUmakefile.C++NPv1_TPC_Logging_Server $(@)

.PHONY: C++NPv1_Reactive_Logging_Server_Ex
C++NPv1_Reactive_Logging_Server_Ex:
	@$(MAKE) -f GNUmakefile.C++NPv1_Reactive_Logging_Server_Ex all

.PHONY: C++NPv1_Iterative_Logging_Server
C++NPv1_Iterative_Logging_Server: C++NPv1_Reactive_Logging_Server_Ex
	@$(MAKE) -f GNUmakefile.C++NPv1_Iterative_Logging_Server all

.PHONY: C++NPv1_Logging_Client
C++NPv1_Logging_Client:
	@$(MAKE) -f GNUmakefile.C++NPv1_Logging_Client all

.PHONY: C++NPv1_PPC_Logging_Server
C++NPv1_PPC_Logging_Server: C++NPv1_Reactive_Logging_Server_Ex
	@$(MAKE) -f GNUmakefile.C++NPv1_PPC_Logging_Server all

.PHONY: C++NPv1_RTTPC_Logging_Server
C++NPv1_RTTPC_Logging_Server: C++NPv1_Reactive_Logging_Server_Ex
	@$(MAKE) -f GNUmakefile.C++NPv1_RTTPC_Logging_Server all

.PHONY: C++NPv1_Reactive_Logging_Server
C++NPv1_Reactive_Logging_Server: C++NPv1_Reactive_Logging_Server_Ex
	@$(MAKE) -f GNUmakefile.C++NPv1_Reactive_Logging_Server all

.PHONY: C++NPv1_TPC_Logging_Server
C++NPv1_TPC_Logging_Server: C++NPv1_Reactive_Logging_Server_Ex
	@$(MAKE) -f GNUmakefile.C++NPv1_TPC_Logging_Server all

project_name_list:
	@echo C++NPv1_Iterative_Logging_Server
	@echo C++NPv1_Logging_Client
	@echo C++NPv1_PPC_Logging_Server
	@echo C++NPv1_RTTPC_Logging_Server
	@echo C++NPv1_Reactive_Logging_Server
	@echo C++NPv1_Reactive_Logging_Server_Ex
	@echo C++NPv1_TPC_Logging_Server

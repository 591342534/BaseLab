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

all: Svr_Conc_Leader_Follower Svr_Conc_Leader_Follower_RT_CORBA Svr_Conc_Queue_Based_Workers Svr_Conc_Queue_Based_Workers_RTCorba

REMAINING_TARGETS := $(subst all, , $(TARGETS_NESTED:.nested=)) $(CUSTOM_TARGETS)

$(REMAINING_TARGETS):
	@cd Leader_Follower && $(MAKE) -f GNUmakefile.Svr_Conc_Leader_Follower $(@)
	@cd Leader_Follower && $(MAKE) -f GNUmakefile.Svr_Conc_Leader_Follower_RT_CORBA $(@)
	@cd Queue_Based_Workers && $(MAKE) -f GNUmakefile.Svr_Conc_Queue_Based_Workers $(@)
	@cd Queue_Based_Workers && $(MAKE) -f GNUmakefile.Svr_Conc_Queue_Based_Workers_RTCorba $(@)

.PHONY: Svr_Conc_Leader_Follower
Svr_Conc_Leader_Follower:
	@cd Leader_Follower && $(MAKE) -f GNUmakefile.Svr_Conc_Leader_Follower all

.PHONY: Svr_Conc_Leader_Follower_RT_CORBA
Svr_Conc_Leader_Follower_RT_CORBA:
	@cd Leader_Follower && $(MAKE) -f GNUmakefile.Svr_Conc_Leader_Follower_RT_CORBA all

.PHONY: Svr_Conc_Queue_Based_Workers
Svr_Conc_Queue_Based_Workers:
	@cd Queue_Based_Workers && $(MAKE) -f GNUmakefile.Svr_Conc_Queue_Based_Workers all

.PHONY: Svr_Conc_Queue_Based_Workers_RTCorba
Svr_Conc_Queue_Based_Workers_RTCorba:
	@cd Queue_Based_Workers && $(MAKE) -f GNUmakefile.Svr_Conc_Queue_Based_Workers_RTCorba all

project_name_list:
	@echo Svr_Conc_Leader_Follower
	@echo Svr_Conc_Leader_Follower_RT_CORBA
	@echo Svr_Conc_Queue_Based_Workers
	@echo Svr_Conc_Queue_Based_Workers_RTCorba

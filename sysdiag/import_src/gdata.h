#pragma once









#define PRINT_INFO	DbgPrint("------------------------------------------------------\n");	\
					DbgPrint("逆向火绒安全软件 ————————> sysydiag.sys\n");					\
					DbgPrint("项目地址:https://github.com/stonedreamforest/re_sysdiag\n");													\
					DbgPrint("网站:https://github.com/stonedreamforest\n");					\
					DbgPrint("作者:Tennn\n");												\
					DbgPrint("------------------------------------------------------\n");











//NTKERNELAPI VOID NTAPI SeDeleteAccessState(
extern NTKERNELAPI  PSHORT NtBuildNumber;





extern PINIT_LIST g_LT;

extern INIT_LIST	g_init_list_A;
extern INIT_LIST	g_init_list_B;
extern INIT_LIST	g_init_list_C;
extern INIT_LIST	g_init_list_D;


extern INIT_FUNTABLE	g_init_ftA;
extern INIT_FUNTABLE	g_init_ftB;
extern INIT_FUNTABLE	g_init_ftC;
extern INIT_FUNTABLE	g_init_ftD;




extern SYSDIAG g_sysdiag;
extern INIT_MEMOBJECT g_init_memob;


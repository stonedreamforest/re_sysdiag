#include "global.h"























PINIT_LIST g_LT = &g_init_list_D;


INIT_LIST	g_init_list_A = {
	0,
	&g_init_ftA,
	0,
	0
};
INIT_LIST	g_init_list_B = {
	&g_init_list_A,
	&g_init_ftB,
	0,
	0
};
INIT_LIST	g_init_list_C = {
	&g_init_list_B,
	&g_init_ftC,
	0,
	0
};

INIT_LIST	g_init_list_D = {
	&g_init_list_C,
	&g_init_ftD,
	0,
	0
};


INIT_FUNTABLE	g_init_ftA = {
	sub_14003C0D0,
	sub_14003C0A0,
	0,
	sub_14003C170
};
INIT_FUNTABLE	g_init_ftB = {
	sub_140038E30,
	sub_140038E00,
	0,
	sub_140038EC0
};
INIT_FUNTABLE	g_init_ftC = {
	sub_14003A930,
	sub_14003A900,
	0,
	sub_14003AA20
};
INIT_FUNTABLE	g_init_ftD = {
	sub_14000D710,
	0,
	0,
	sub_14000D8A0
};



SYSDIAG g_sysdiag = { 0 };
INIT_MEMOBJECT g_init_memob = { 0 };




int dword_14005AFA8[12];



INIT_KEVENT g_init_kevent[5];



extern int dword_14005AFA8[12];
extern NPAGED_LOOKASIDE_LIST g_np_lkaside[] = {0};
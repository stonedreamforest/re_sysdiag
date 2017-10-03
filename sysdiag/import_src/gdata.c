#include "global.h"














SYSDIAG g_sysdiag = { 0 };








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

















//OFF_14004A820 off_14004a820 = { 0 };
//BYTE_14005C880 byte_14005c880 = { 0 };
//OFF_14004A810 off_14004a810 = { 0 };
//QWORD_14004A6A8 qword_14004a6a8 = { 0 };
//OFF_14004A5A0 off_14004a5a0 = { 0 };
//OFF_14004A6C0 off_14004a6c0 = { 0 };
//OFF_14004A710 off_14004a710 = { 0 };
//OFF_14004A6D8 off_14004a6d8 = { 0 };
//OFF_140045410 off_140045410 = { 0 };
//OFF_14004A6F0 off_14004a6f0 = { 0 };
//
//
//
//
//
//OFF_14004A6A0 stru_14004A6A0 =
//{
//  (POFF_14004A6F0) &off_14004a6f0,
//  { 0, (POFF_14004A820) &off_14004a820, 0 },
//  { (PQWORD_14004A6A8) &qword_14004a6a8, &off_14004a5a0, 0 },
//  { (POFF_14004A6C0) &off_14004a6c0, (POFF_14004A710) &off_14004a710, 0 },
//  { (POFF_14004A6D8) &off_14004a6d8, &off_140045410, 0, 0 },
//  { sub_14003A930, sub_14003A900, 0, sub_14003AA20, "" },
//  { &byte_14005c880, 0 },
//  { sub_14003C0D0, sub_14003C0A0, 0, sub_14003C170 }
//};
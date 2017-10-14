





typedef struct NRL_FLAG {
	char flag_0;    //  0x00
	char flag_1;    //  0x01
	char flag_2;    //  0x02
	char flag_3;    //  0x03
	int  i_4;       //  0x04
}NRL_FLAG , *PNRL_FLAG;

typedef struct ERES_FLAG {
	char flag_0;    //  0x00
	char flag_1;    //  0x01
	char flag_2;    //  0x02
	char flag_3;    //  0x03
	int  i_4;       //  0x04
}ERES_FLAG , *PERES_FLAG;








typedef struct __declspec(align(8)) _SYSDIAG {
	PDRIVER_OBJECT *ppdriver_object_0;
	PDRIVER_OBJECT pdriver_object_8;
	RTL_OSVERSIONINFOEXW rtl_osversioninfoexw;
	char buf12c[28];
	void *field_148;
	char field_150[16];
	NRL_FLAG nrl_flag_160;
	NDIS_RW_LOCK ndis_rw_lock_168;
	void *v_578;
	void *v_580;
	void *v_588;
	NRL_FLAG nrl_flag_590;
	NDIS_RW_LOCK ndis_rw_lock_598;
	char buf998[16];
	ERES_FLAG eres_flag_9b8;
	ERESOURCE eresource_9c0;
	char bufa28[944];
	void *v_dd8;
	void *v_de0;
	NRL_FLAG nrl_flag_de8;
	NDIS_RW_LOCK ndis_rw_lock_df0;
	char buf11f0[8];
	void *v_1208;
	void *v_1210;
	NRL_FLAG nrl_flag_1218;
	NDIS_RW_LOCK ndis_rw_lock_1220;
	char buf1620[8];
	void *v_1638;
	void *v_1640;
	__int64 l_1648;
	NRL_FLAG nrl_flag_1650;
	NDIS_RW_LOCK ndis_rw_lock_1658;
	void *v_1a68;
	void *v_1a70;
	ERES_FLAG eres_flag_1a78;
	ERESOURCE eresource_1a80;
	char buf1ae8[936];
	void *v_1e90;
	void *v_1e98;
	void *v_1ea0;
	void *v_1ea8;
	void *v_1eb0;
	void *v_1eb8;
	NRL_FLAG nrl_flag_1ec0;
	NDIS_RW_LOCK ndis_rw_lock_1ec8;
	__int64 l_22d8;
	char buf22e0[32];
}SYSDIAG , *PSYSDIAG;





typedef struct _INIT_LIST INIT_LIST , *PINIT_LIST;
typedef struct _INIT_FUNTABLE INIT_FUNTABLE , *PINIT_FUNTABLE;


typedef NTSTATUS(__stdcall *psubA)(PINIT_FUNTABLE init_ft , PDRIVER_OBJECT pdriver_object , PUNICODE_STRING RegistryPath);
typedef void(__stdcall *psubB)();
typedef NTSTATUS(__stdcall *psubC)(void *a1 , void *a2 , long long a3 , int a4);
typedef char(__stdcall *psubD)(void   *a1 , long long a2);
typedef NTSTATUS(__stdcall *psubE)(void *a1 , PDRIVER_OBJECT pdriver_object , void *a3);
typedef struct _INIT_FUNTABLE {
	psubA	sub_0;						//	0x00
	psubB	sub_8;						//	0x08
	psubC	sub_10;						//	0x10
	psubD	sub_18;						//	0x18
	psubE	ArrSub[27];
}INIT_FUNTABLE , *PINIT_FUNTABLE;

typedef struct _INIT_LIST {
	PINIT_LIST		pnext_list;			//	0x00
	PINIT_FUNTABLE	pnext_ft;			//	0x08
	int				flag_10;			//	0x10
	int				flag_14;			//	0x14
}INIT_LIST , *PINIT_LIST;


typedef struct _INIT_MEMOBJECT {
	void*   v_0;            //  0x00
	KSPIN_LOCK SpinLock;    //  0x08
	USHORT  Length_a;       //  0x10
	USHORT  Length_b;       //  0x12
	int     i_14;           //  0x14
	void*   memptr;         //  0x18
	PDEVICE_OBJECT   ActMonDeviceObject;         //  0x20
	PDEVICE_OBJECT   DTrampoDeviceObject;        //  0x28
	int     i_30;           //  0x30
	int     i_34;           //  0x34
	void*   v_38;           //  0x38
}INIT_MEMOBJECT , *PINIT_MEMOBJECT;








typedef struct _INIT_KEVENT {
	int i_0;				//	0x00
	int i_4;				//	0x04
	long long l_8;			//	0x08
	long long l_10;			//	0x10
	long long l_18;			//	0x18
	int i_1c;				//	0x1c
	int i_20;				//	0x20
	KEVENT kevent;			//	0x28	size:0x18
	char buf[0x50 - 0x40];
}INIT_KEVENT , *PINIT_KEVENT;



typedef struct _STRC_140059950 {
	long long l_0;                      //  0x00
	long long l_8;                      //  0x08
	long long l_10;                     //  0x10
	long long l_18;                     //  0x18
	NDIS_RW_LOCK ndis_rw_lock_20;		//  0x20    size:0x410
	char buf430[0x48];
}STRC_140059950 , *PSTRC_140059950 ,
STRU_14005B290;




typedef struct _STRC_14005B708 {
	__int64 l_0;
	__int64 l_8;
	char field_10[16];
	__int64 l_20;
	char buf28[16];
	NPAGED_LOOKASIDE_LIST np_lks_lt_38;
	char buf118[192];
}STRC_14005B708 , *PSTRC_14005B708;



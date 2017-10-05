





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








typedef struct SYSDIAG {
	PDRIVER_OBJECT     *ppdriver_object_0;      //  0x00
	PDRIVER_OBJECT      pdriver_object_8;       //  0x08    
	RTL_OSVERSIONINFOEXW rtl_osversioninfoexw;  //  0x10    size:0x11c
	char buf12c[0x160 - 0x12c];
	NRL_FLAG nrl_flag_160;                      //  0X160  
	NDIS_RW_LOCK ndis_rw_lock_168;				//  0x168   size:0x410
	void* v_578;                                //  0x578
	void* v_580;                                //  0x580  
	void* v_588;                                //  0x588  
	NRL_FLAG nrl_flag_590;                      //  0x590  
	NDIS_RW_LOCK ndis_rw_lock_598;				//  0x598   size:0x410
	char buf998[0x9b8 - 0x9a8];
	ERES_FLAG eres_flag_9b8;                    //  0x9b8
	ERESOURCE eresource_9c0;					//  0x9c0   size:0x68
	char bufa28[0xdd8 - 0xa28];
	void* v_dd8;                                //  0xdd8
	void* v_de0;                                //  0xde0
	NRL_FLAG nrl_flag_de8;                      //  0xde8
	NDIS_RW_LOCK ndis_rw_lock_df0;				//  0xdf0   size:0x410
	char buf11f0[0x1208 - 0x1200];
	void* v_1208;                               //  0x1208
	void* v_1210;                               //  0x1210
	NRL_FLAG nrl_flag_1218;                     //  0x1218
	NDIS_RW_LOCK ndis_rw_lock_1220;				//  0x1220  size:0x410
	char buf1620[0x1638 - 0x1630];
	void* v_1638;                               //  0x1638
	void* v_1640;                               //  0x1640
	long long l_1648;                           //  0x1648
	NRL_FLAG nrl_flag_1650;                     //  0x1650
	NDIS_RW_LOCK ndis_rw_lock_1658;				//  0x1658  size:0x410    
	void* v_1a68;                               //  0x1a68
	void* v_1a70;                               //  0x1a70
	ERES_FLAG eres_flag_1a78;                   //  0x1a78
	ERESOURCE   eresource_1a80;					//  0x1a80  size:0x68
	char buf1ae8[0x1e90 - 0x1ae8];
	void* v_1e90;                               //  0x1e90
	void* v_1e98;                               //  0x1e98
	void* v_1ea0;                               //  0x1ea0
	void* v_1ea8;                               //  0x1ea8
	void* v_1eb0;                               //  0x1eb0
	void* v_1eb8;                               //  0x1eb8
	NRL_FLAG nrl_flag_1ec0;                     //  0x1ec0
	NDIS_RW_LOCK ndis_rw_lock_1ec8;				//  0x1ec8  size:0x410   
	long long l_22d8;                           //  0x22d8    
	char buf22e0[0x2300 - 0x22e0];
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
	PKSPIN_LOCK SpinLock;   //  0x08
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


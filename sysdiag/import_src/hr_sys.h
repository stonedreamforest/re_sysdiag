#pragma once





NTSTATUS sub_14003C0D0(PINIT_FUNTABLE init_ft , PDRIVER_OBJECT pdriver_object , PUNICODE_STRING RegistryPath);
NTSTATUS sub_14003C0A0();
char sub_14003C170(void   *a1 , long long a2);
NTSTATUS sub_140038E30(PINIT_FUNTABLE init_ft , PDRIVER_OBJECT pdriver_object , PUNICODE_STRING RegistryPath);
NTSTATUS sub_140038E00();
char sub_140038EC0(void   *a1 , long long a2);
NTSTATUS sub_14003A930(PINIT_FUNTABLE init_ft , PDRIVER_OBJECT pdriver_object , PUNICODE_STRING RegistryPath);
void sub_14003A900();
char sub_14003AA20(void   *a1 , long long a2);



NTSTATUS sub_14000E160(void *a1 , PDRIVER_OBJECT pdriver_object , void *a3);
NTSTATUS sub_14000E250(void *a1 , void *a2 , long long a3 , int a4);
//************************************************************************************************************
//	创建作者  :  Tennn
//  修改时间  :  2017/10/03 19:23
//	函数功能  :  申请内存	sub_14000AFD0 
//************************************************************************************************************
void *hr_AllocatePoolWithTag(POOL_TYPE PoolType , size_t NumberOfBytes , ULONG Tag);

//************************************************************************************************************
//	创建作者  :  Tennn
//  修改时间  :  2017/10/03 20:29
//	函数功能  :  设置交互式服务？	sub_14000E030
//************************************************************************************************************
NTSTATUS hr_SetNoInteractiveServices();

//************************************************************************************************************
//	创建作者  :  Tennn
//  修改时间  :  2017/10/03 23:15
//	函数功能  :  创建设备对象	sub_14000BBD0
//************************************************************************************************************
NTSTATUS hr_CreateDeviceSecure(PDRIVER_OBJECT pDriverObject , const WCHAR *u_DeviceName , const WCHAR *u_SymbolicLinkName , PDEVICE_OBJECT pdevice_object);
NTSTATUS sub_140021380();
void sub_140021960();
NTSTATUS sub_14001AF00();
NTSTATUS sub_140034090();
void sub_140021370();
void sub_14001AEF0();
NTSTATUS sub_140020D80(void *a1 , int a2);
NTSTATUS sub_140020E00(void *a1 , int a2);
//************************************************************************************************************
//	创建作者  :  Tennn
//  修改时间  :  2017/10/14 18:01
//	函数功能  :   此函数在xp以上版本不起作用 防火墙？  sub_140020CB0
//************************************************************************************************************
void hr_XPIoGetDeviceObjectPointer();
NTSTATUS sub_140021A60();
//************************************************************************************************************
//	创建作者  :  Tennn
//  修改时间  :  2017/10/14 15:03
//	函数功能  :  sub_140021CC0
//************************************************************************************************************
NTSTATUS sub_140021CC0();
NTSTATUS sub_14002AF30(PUSHORT length);
NTSTATUS sub_140023970() ;
NTSTATUS sub_14000A250() ;
NTSTATUS sub_140019F90() ;
NTSTATUS sub_140026610();
NTSTATUS sub_1400144F0(PDEVICE_OBJECT pdevice_object , PUSHORT length) ;
NTSTATUS sub_1400198C0();
NTSTATUS sub_140028290();
NTSTATUS sub_140025130();
NTSTATUS sub_140029210() ;
NTSTATUS sub_14000F0C0();
NTSTATUS sub_14000F410(void *a1 , int size , const wchar_t *a3 , int a4);


//************************************************************************************************************
//	创建作者  :	Tennn
//  修改时间  :  2017/10/27 21:39
//	函数功能  :	sub_14000AFB0
//************************************************************************************************************
void hr_ExFreePoolWithTag(void *mem , int tag);
NTSTATUS sub_140008FF0(STRU_14005B290 *context ,
					   void *a2 ,
					   void *a3 ,
					   int a4 ,
					   size_t a5 ,
					   size_t a6 ,
					   void *a8 ,
					   void *a7 ,
					   void *a9 ,
					   size_t a10 ,
					   size_t a11 ,
					   size_t a12 ,
					   size_t a13 ,
					   size_t a14 ,
					   size_t a15 ,
					   size_t a16);
//************************************************************************************************************
//	创建作者  :  Tennn
//  修改时间  :  2017/10/18 21:09
//	函数功能  :  创建一个线程 sub_140009B30
//************************************************************************************************************
NTSTATUS hr_CreateThread(STRU_14005B290 *loc_14005b290);
NTSTATUS sub_14000A290(void *a1 , void *a2 , void *a3);
//************************************************************************************************************
//	创建作者  :  Tennn
//  修改时间  :  2017/10/09 20:49
//	函数功能  :  初始化函数 sub_1400200B0
//************************************************************************************************************
NTSTATUS sub_1400200B0(PDEVICE_OBJECT pdevice_object , PUSHORT length , int flag);
NTSTATUS sub_140020350(int flag);
NTSTATUS sub_14000D710(PINIT_FUNTABLE init_ft , PDRIVER_OBJECT pdriver_object , PUNICODE_STRING RegistryPath);
char sub_14000D8A0(void *a1 , long long a2);

















//sub_14000ACA0
NTSTATUS hr_driver_dispatch(void *a1 , void *a2);

//sub_14000AE00
NTSTATUS hr_driver_unload(PDRIVER_OBJECT pdriver_object);

//sub_14000AD40
VOID hr_BootDriverReinitialization(_In_ struct _DRIVER_OBJECT *DriverObject , _In_opt_ PVOID Context , _In_ ULONG Count);

//sub_14000AD40
VOID hr_DriverReinitialization(_In_ struct _DRIVER_OBJECT *DriverObject , _In_opt_ PVOID Context , _In_ ULONG Count);


//sub_14000AE00
char hr_ExitCleaner(PDRIVER_OBJECT pdriver_object);
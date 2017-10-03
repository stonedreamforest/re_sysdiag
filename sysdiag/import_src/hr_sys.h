#pragma once





NTSTATUS sub_14003C0D0(PINIT_FUNTABLE init_ft , PDRIVER_OBJECT pdriver_object, PUNICODE_STRING RegistryPath);
NTSTATUS sub_14003C0A0();
char sub_14003C170(void   *a1 , long long a2);
NTSTATUS sub_140038E30(PINIT_FUNTABLE init_ft , PDRIVER_OBJECT pdriver_object, PUNICODE_STRING RegistryPath);
NTSTATUS sub_140038E00();
char sub_140038EC0(void   *a1 , long long a2);
NTSTATUS sub_14003A930(PINIT_FUNTABLE init_ft , PDRIVER_OBJECT pdriver_object, PUNICODE_STRING RegistryPath);
void sub_14003A900();
char sub_14003AA20(void   *a1 , long long a2);
NTSTATUS sub_14000D710(PINIT_FUNTABLE init_ft , PDRIVER_OBJECT pdriver_object, PUNICODE_STRING RegistryPath);
char sub_14000D8A0(void *a1 , long long a2);

















//sub_14000ACA0
NTSTATUS hr_driver_dispatch(void *a1 , void *a2);

//sub_14000AE00
NTSTATUS hr_driver_unload(PDRIVER_OBJECT pdriver_object);

//sub_14000AD40
VOID hr_BootDriverReinitialization(_In_ struct _DRIVER_OBJECT *DriverObject , _In_opt_ PVOID Context , _In_ ULONG Count);

VOID hr_DriverReinitialization(_In_ struct _DRIVER_OBJECT *DriverObject , _In_opt_ PVOID Context , _In_ ULONG Count);



char hr_ExitCleaner(PDRIVER_OBJECT pdriver_object);
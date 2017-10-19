#include "global.h"


NTSTATUS sub_14003C0D0(PINIT_FUNTABLE init_ft , PDRIVER_OBJECT pdriver_object , PUNICODE_STRING RegistryPath) {
	UNREFERENCED_PARAMETER(RegistryPath);

	return 0;
}

NTSTATUS sub_14003C0A0() {
	return 0;

}

char sub_14003C170(void *a1 , long long a2) {
	return 0;

}

NTSTATUS sub_140038E30(PINIT_FUNTABLE init_ft , PDRIVER_OBJECT pdriver_object , PUNICODE_STRING RegistryPath) {
	UNREFERENCED_PARAMETER(RegistryPath);

	return 0;

}

NTSTATUS sub_140038E00() {
	return 0;

}

char sub_140038EC0(void *a1 , long long a2) {
	return 0;

}

NTSTATUS sub_14003A930(PINIT_FUNTABLE init_ft , PDRIVER_OBJECT pdriver_object , PUNICODE_STRING RegistryPath) {
	UNREFERENCED_PARAMETER(RegistryPath);

	return 0;

}

void sub_14003A900() {

}

char sub_14003AA20(void *a1 , long long a2) {
	return 0;

}


NTSTATUS sub_14000E160(void *a1 , PDRIVER_OBJECT pdriver_object , void *a3) {
	return 0;
}

NTSTATUS sub_14000E250(void *a1 , void *a2 , long long a3 , int a4) {
	return 0;
}

void *hr_AllocatePoolWithTag(POOL_TYPE PoolType , size_t NumberOfBytes , ULONG Tag) {
	Tag = Tag ? Tag : 0x54646566;
	void *ptr = ExAllocatePoolWithTag(PoolType , NumberOfBytes , Tag);
	if (ptr) {
		memset(ptr , 0 , NumberOfBytes);
	}
	return ptr;
}

NTSTATUS hr_SetNoInteractiveServices() {
	ULONG Data = 0;
	HANDLE KeyHandle;
	UNICODE_STRING ValueName;
	UNICODE_STRING DestinationString;
	OBJECT_ATTRIBUTES ObjectAttributes;

	RtlInitUnicodeString(&DestinationString , L"\\Registry\\Machine\\SYSTEM\\CurrentControlSet\\Control\\Windows");
	RtlInitUnicodeString(&ValueName , L"NoInteractiveServices");
#if 0
	ObjectAttributes.Length = sizeof(OBJECT_ATTRIBUTES);	//	0x30
	ObjectAttributes.ObjectName = &DestinationString;
	ObjectAttributes.RootDirectory = 0i64;
	ObjectAttributes.Attributes = OBJ_CASE_INSENSITIVE | OBJ_KERNEL_HANDLE;	//	0x240
	ObjectAttributes.SecurityDescriptor = NULL;
#else
	InitializeObjectAttributes(&ObjectAttributes ,
							   &DestinationString ,
							   OBJ_CASE_INSENSITIVE | OBJ_KERNEL_HANDLE ,
							   NULL ,
							   NULL);
#endif
	if (ZwOpenKey(&KeyHandle , 0xF003F , &ObjectAttributes)) {
		return 0xFFFFFFF3;
	}
	NTSTATUS status = ZwSetValueKey(KeyHandle , &ValueName , 0 , REG_DWORD , &Data , sizeof(Data));
	ZwClose(KeyHandle);
	if (status < 0) {
		return 0xFFFFFFF2;
	}
	return 0;
}

NTSTATUS hr_CreateDeviceSecure(PDRIVER_OBJECT pDriverObject , const WCHAR *u_DeviceName , const WCHAR *u_SymbolicLinkName , PDEVICE_OBJECT pdevice_object) {
	UNICODE_STRING DestinationString;
	UNICODE_STRING DefaultSDDLString;
	UNICODE_STRING SymbolicLinkName;

	if (u_DeviceName) {
		RtlInitUnicodeString(&DestinationString , u_DeviceName);
	}
	RtlInitUnicodeString(&DefaultSDDLString , L"D:P(A;;GA;;;WD)");
	NTSTATUS status = WdmlibIoCreateDeviceSecure(pDriverObject ,
												 0 ,
												 &DestinationString ,
												 0x22u ,
												 0x100u ,
												 0 ,
												 &DefaultSDDLString ,
												 0 ,
												 &pdevice_object);
	if (status < 0) {
		return status;
	}
	if (u_SymbolicLinkName) {
		RtlInitUnicodeString(&SymbolicLinkName , u_SymbolicLinkName);
		status = IoCreateSymbolicLink(&SymbolicLinkName , &DestinationString);
		if (status < 0) {
			IoDeleteDevice(pdevice_object);
			return status;
		}

	}
	return 0;
}


NTSTATUS sub_140021380() {
	strc_14005b708.l_0 = 0;
	strc_14005b708.l_8 = 0;
	NTSTATUS status = hr_CreateThread(&g_ThreadContext);
	if (status < 0) {
		return status;
	}
	status = sub_14000A290(g_sysdiag.field_148 , &g_ThreadContext , L"\\HR::NetFlood");
	return status < 0 ? status : 0;
}
void sub_140021960() {

}
NTSTATUS sub_14001AF00() {
	return 0;
}
NTSTATUS sub_140034090() {
	return 0;
}
void sub_140021370() {

}
void sub_14001AEF0() {

}
NTSTATUS sub_140020D80(void *a1 , int a2) {
	return 0;
}
NTSTATUS sub_140020E00(void *a1 , int a2) {
	return 0;
}

void hr_XPIoGetDeviceObjectPointer() {
	UNICODE_STRING DestinationString;
	PFILE_OBJECT FileObject;
	PDEVICE_OBJECT DeviceObject;

	//windows 7 ртио╟Ф╠╬
	if ((USHORT)NtBuildNumber >= 0x1DB0) {
		return;
	}
	RtlInitUnicodeString(&DestinationString , L"\\Device\\HRFwDrv");
	if (IoGetDeviceObjectPointer(&DestinationString , 0x1F01FFu , &FileObject , &DeviceObject) < 0) {
		return;
	}
	ObfDereferenceObject(FileObject);
	if (!DeviceObject->DeviceExtension) {	// 0x40
		return;
	}
	typedef NTSTATUS(__stdcall *psub)(void *a1 , int a2);
	typedef NTSTATUS(__stdcall *pde_sub)(int zero , psub sub);
	typedef struct _CUS_DEVICEEXTENSION {
		long long l_0;	//	0x00
		int		i_8;	//	0x08
		pde_sub	sub_c;	//	0x0c
		pde_sub	sub_14;	//	0x14
	}CUS_DEVICEEXTENSION , *PCUS_DEVICEEXTENSION;
	PCUS_DEVICEEXTENSION DeviceExtension = (PCUS_DEVICEEXTENSION)DeviceObject->DeviceExtension;
	if (DeviceExtension->l_0 != 0x5652445746524821 || DeviceExtension->i_8 != 0) {
		return;
	}
	DeviceExtension->sub_c(0 , sub_140020D80);
	DeviceExtension->sub_14(0 , sub_140020E00);
	return;
}
NTSTATUS sub_140021A60() {
	hr_XPIoGetDeviceObjectPointer();
	strc_14005b708.l_20 = 0;
	return 0;
}
NTSTATUS sub_140021CC0() {
	ExInitializeNPagedLookasideList(&strc_14005b708.np_lks_lt_38 , 0i64 , 0i64 , 0 , 0x4E0ui64 , 0x546E6D69u , 0);
	if (sub_140021A60() < 0) {
		return 0x0C0000001;
	}
	if (sub_140021380() < 0) {
		sub_140021960();
		return 0x0C0000001;
	}
	if (sub_14001AF00() < 0) {
		sub_140021960();
		sub_140021370();
		return 0x0C0000001;
	}
	NTSTATUS status = sub_140034090();
	if (status >= 0) {
		return 0;
	}
	sub_140021960();
	sub_140021370();
	sub_14001AEF0();
	return status;
}
NTSTATUS sub_14002AF30(PUSHORT length) {
	return 0;
}
NTSTATUS sub_140023970() {
	return 0;
}
NTSTATUS sub_14000A250() {
	return 0;
}
NTSTATUS sub_140019F90() {
	return 0;
}
NTSTATUS sub_140026610() {
	return 0;
}
NTSTATUS sub_1400144F0(PDEVICE_OBJECT pdevice_object , PUSHORT length) {
	return 0;
}
NTSTATUS sub_1400198C0() {
	return 0;
}
NTSTATUS sub_140028290() {
	return 0;
}
NTSTATUS sub_140025130() {
	return 0;
}
NTSTATUS sub_140029210() {
	return 0;
}
NTSTATUS sub_14000F0C0() {
	return 0;
}
NTSTATUS sub_14000F410(void *a1 , int size , const wchar_t *a3 , int a4) {
	return 0;
}

VOID ThreadStart(_In_ PVOID StartContext) {

}

NTSTATUS hr_CreateThread(STRU_14005B290 *ThreadContext) {
	HANDLE ThreadHandle;
	OBJECT_ATTRIBUTES ObjectAttributes;

	memset(ThreadContext , 0 , sizeof(STRU_14005B290));
	ThreadContext->field_438 = 0;
	KeInitializeEvent(&ThreadContext->kevent_440 , SynchronizationEvent , 0);
	ThreadContext->field_468 = &ThreadContext->field_468;
	ThreadContext->field_470 = &ThreadContext->field_468;
	ThreadContext->field_10 &= 0xfd;
	ThreadContext->field_10 = (ThreadContext->field_10 & 0xFE) | (ExInitializeResourceLite(&ThreadContext->Resource_18) >= 0);
	if (!(ThreadContext->field_10 & 1)) {
		return 0x0FFFFFFF2;
	}
#if 0
	ObjectAttributes.Length = sizeof(OBJECT_ATTRIBUTES);	//	0x30
	ObjectAttributes.ObjectName = &DestinationString;
	ObjectAttributes.RootDirectory = 0i64;
	ObjectAttributes.Attributes = 0x200;
	ObjectAttributes.SecurityDescriptor = NULL;
#else
	InitializeObjectAttributes(&ObjectAttributes ,
							   NULL ,
							   0x200 ,
							   NULL ,
							   NULL);
#endif
	if (PsCreateSystemThread(&ThreadHandle , 0x1FFFFF , &ObjectAttributes , 0 , 0 , ThreadStart , ThreadContext) < 0) {
		return 0xFFFFFFF2;
	}
	if (ObReferenceObjectByHandle(ThreadHandle , 0x1FFFFFu , PsThreadType[0] , 0 , (PVOID *)&ThreadContext->object_458 , 0i64) < 0) {
		_InterlockedIncrement(&ThreadContext->field_460);
		KeSetEvent(&ThreadContext->kevent_440 , 0 , 0);
		return 0x0FFFFFFF2;
	}
	ZwClose(ThreadHandle);
	return 0;
}

NTSTATUS sub_14000A290(void *a1 , void *a2 , void *a3) {
	return 0;
}
NTSTATUS sub_1400200B0(PDEVICE_OBJECT pdevice_object , PUSHORT length , int flag) {
	NTSTATUS status;
	char buf[0x40];
	if (flag) {
		if (flag != 1) {
			status = sub_140021CC0();
			if (status < 0) {
				return status;
			}
			dword_14005AFA8[6] = 1;
		}
		goto loc_1400202A2;
	}
	for (int i = 0; i < 5; i++) {
		g_init_kevent[i].l_8 = 0;
		g_init_kevent[i].l_10 = 1;
		g_init_kevent[i].l_18 = 0;
		g_init_kevent[i].i_20 = 0;
		KeInitializeEvent(&g_init_kevent[i].kevent , SynchronizationEvent , FALSE);
	}
	ExInitializeNPagedLookasideList(&g_np_lkaside[0] , 0 , 0 , 0 , 0x40ui64 , 0x54697464u , 0);
	ExInitializeNPagedLookasideList(&g_np_lkaside[1] , 0 , 0 , 0 , 0x18ui64 , 0x5462706Cu , 0);
	ExInitializeNPagedLookasideList(&g_np_lkaside[2] , 0 , 0 , 0 , 0x78ui64 , 0x54706C6Cu , 0);
	sub_14002AF30(length);
	if (sub_140023970() < 0) {
		return 0x0C0000001;
	}
	dword_14005AFA8[0] = 1;
	if (sub_14000A250()) {
		return 0x0C0000001;
	}
	dword_14005AFA8[10] = 1;
	if (sub_140019F90() < 0) {
		return 0x0C0000001;
	}
	dword_14005AFA8[1] = 1;
	if (sub_140026610() >= 0) {
		dword_14005AFA8[2] = 1;
	}
	status = sub_1400144F0(pdevice_object , length);
	if (status < 0) {
		return status;
	}
	dword_14005AFA8[3] = 1;
	status = sub_1400198C0();
	if (status < 0) {
		return status;
	}
	dword_14005AFA8[7] = 1;
	status = sub_140028290();
	if (status < 0) {
		return status;
	}
	dword_14005AFA8[5] = 1;
	status = sub_140025130();
	if (status < 0) {
		return status;
	}
	dword_14005AFA8[4] = 1;
	status = sub_140029210();
	if (status < 0) {
		return status;
	}
	dword_14005AFA8[8] = 1;
	status = sub_14000F0C0();
	if (status < 0) {
		return status;
	}
	dword_14005AFA8[9] = 1;
loc_1400202A2:
	status = 0;
	for (int i = 0; i < 5; i++) {
		if (flag) {
			if (flag == 1 && i != 4) {
				continue;
			}
		}
		else {
			if (i == 4) {
				continue;
			}
		}

		sub_14000F410(buf , 0x40 , L"\\HR::ActMon_%d" , 0);
		if (hr_CreateThread(&strc_140059950[0]) < 0 || sub_14000A290(g_sysdiag.field_148 , &strc_140059950 , buf) < 0) {
			status = 0x0C0000001;
			break;
		}
	}
	return status;
}
NTSTATUS sub_140020350(int flag) {
	return 0;
}

NTSTATUS sub_14000D710(PINIT_FUNTABLE init_ft , PDRIVER_OBJECT pdriver_object , PUNICODE_STRING RegistryPath) {
	if ((USHORT)NtBuildNumber < 0xa28) {
		return 0xC00000BB;
	}
	void *ptr = hr_AllocatePoolWithTag(0 , RegistryPath->Length , 0);
	if (!ptr) {
		return 0x0C000009A;
	}
	memmove(ptr , RegistryPath->Buffer , RegistryPath->Length);
	g_init_memob.memptr = ptr;
	g_init_memob.Length_a = RegistryPath->Length;
	g_init_memob.Length_b = RegistryPath->Length;
	hr_SetNoInteractiveServices();
	NTSTATUS status = hr_CreateDeviceSecure(pdriver_object , L"\\Device\\HR::ActMon" , L"\\??\\HR::ActMon" , g_init_memob.ActMonDeviceObject);
	if (status < 0) {
		return status;
	}
	status = hr_CreateDeviceSecure(pdriver_object , L"\\Device\\HR::DTrampo" , L"\\??\\HR::DTrampo" , g_init_memob.ActMonDeviceObject);
	if (status < 0) {
		return status;
	}
	for (int i = 0; i < 27; i++) {
		init_ft->ArrSub[i] = sub_14000E160;
	}
	init_ft->sub_10 = sub_14000E250;
	if (sub_1400200B0(g_init_memob.ActMonDeviceObject , &g_init_memob.Length_a , 0) < 0) {
		return 0x0C0000001;
	}
	return sub_140020350(0);
}

char sub_14000D8A0(void *a1 , long long a2) {
	return 0;
}

NTSTATUS hr_driver_dispatch(void *a1 , void *a2) {
	return 0;
}

NTSTATUS hr_driver_unload(PDRIVER_OBJECT pdriver_object) {
	return 0;
}

VOID hr_BootDriverReinitialization(_In_ struct _DRIVER_OBJECT *DriverObject , _In_opt_ PVOID Context , _In_ ULONG Count) {

}


VOID hr_DriverReinitialization(_In_ struct _DRIVER_OBJECT *DriverObject , _In_opt_ PVOID Context , _In_ ULONG Count) {

}

char hr_ExitCleaner(PDRIVER_OBJECT pdriver_object) {
	return 0;
}

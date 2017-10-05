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

NTSTATUS sub_140021CC0() {
	return 0;
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
NTSTATUS sub_14000F410(void *a1,int a2,const wchar_t *a3,int a4) {
	return 0;
}
NTSTATUS sub_140009B30(void *a1) {
	return 0;
}
NTSTATUS sub_14000A290(void *a1 , void *a2 , void *a3) {
	return 0;
}
NTSTATUS sub_1400200B0(PDEVICE_OBJECT pdevice_object , PUSHORT length , int flag) {
	NTSTATUS status;
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

loc_1400202A2:
	return 0;
}
NTSTATUS sub_140020350(int flag) {
	return 0;
}

NTSTATUS sub_14000D710(PINIT_FUNTABLE init_ft , PDRIVER_OBJECT pdriver_object , PUNICODE_STRING RegistryPath) {
	if ((USHORT) NtBuildNumber < 0xa28) {
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

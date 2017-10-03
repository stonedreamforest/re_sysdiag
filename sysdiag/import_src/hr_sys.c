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


void *hr_AllocatePoolWithTag(POOL_TYPE PoolType , size_t NumberOfBytes , ULONG Tag) {
	Tag = Tag ? Tag : 0x54646566;
	void *ptr = ExAllocatePoolWithTag(PoolType , NumberOfBytes , Tag);
	if (ptr) {
		memset(ptr , 0 , NumberOfBytes);
	}
	return ptr;
}

NTSTATUS hr_SetNoInteractiveServices() {
	NTSTATUS status = 0;
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
	status = ZwSetValueKey(KeyHandle , &ValueName , 0 , REG_DWORD , &Data , sizeof(Data));
	ZwClose(KeyHandle);
	if (status < 0) {
		return 0xFFFFFFF2;
	}
	return status;
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
	return 0;

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

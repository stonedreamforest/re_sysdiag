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

NTSTATUS sub_14000D710(PINIT_FUNTABLE init_ft , PDRIVER_OBJECT pdriver_object , PUNICODE_STRING RegistryPath) {
	if ((USHORT) NtBuildNumber < 0xa28) {
		return 0xC00000BB;
	}
	void *ptr = hr_AllocatePoolWithTag(0 , RegistryPath->Length , 0);
	if (!ptr) {
		return 0x0C000009A;
	}
	memmove(ptr , RegistryPath->Buffer , RegistryPath->Length);

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

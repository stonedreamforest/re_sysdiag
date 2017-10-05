#include "global.h"















//************************************************************************************************************
//	创建作者  :  Tennn
//  修改时间  :  2017/10/03 19:23
//	函数功能  :  驱动入口
//************************************************************************************************************
NTSTATUS DriverEntry(_In_ PDRIVER_OBJECT  DriverObject , _In_ PUNICODE_STRING RegistryPath) {
	NTSTATUS status = 0;

#ifdef DBG
	__debugbreak();
	PRINT_INFO;
#else
	PRINT_INFO;
#endif // DBG
	

	//	不支持xp以下版本
	if ((USHORT) NtBuildNumber < 0xa28) {
		return 0xC00000BB;
	}

	g_sysdiag.v_580 = &g_sysdiag.v_580;
	g_sysdiag.v_588 = &g_sysdiag.v_580;
	g_sysdiag.v_dd8 = &g_sysdiag.v_dd8;
	g_sysdiag.v_de0 = &g_sysdiag.v_dd8;
	g_sysdiag.v_1208 = &g_sysdiag.v_1208;
	g_sysdiag.v_1210 = &g_sysdiag.v_1208;
	g_sysdiag.v_1638 = &g_sysdiag.v_1638;
	g_sysdiag.v_1640 = &g_sysdiag.v_1638;
	g_sysdiag.v_1a68 = &g_sysdiag.v_1a68;
	g_sysdiag.v_1a70 = &g_sysdiag.v_1a68;
	g_sysdiag.v_1e90 = &g_sysdiag.v_1e90;
	g_sysdiag.v_1e98 = &g_sysdiag.v_1e90;
	g_sysdiag.v_1ea0 = &g_sysdiag.v_1ea0;
	g_sysdiag.v_1ea8 = &g_sysdiag.v_1ea0;
	g_sysdiag.v_1eb0 = &g_sysdiag.v_1eb0;
	g_sysdiag.v_1eb8 = &g_sysdiag.v_1eb0;


	//获取当前正在运行的操作系统例程返回版本信息
	//初始化6个读写锁
	//初始化2个资源变量。
	g_sysdiag.rtl_osversioninfoexw.dwOSVersionInfoSize = sizeof(RTL_OSVERSIONINFOEXW);
	if (RtlGetVersion((PRTL_OSVERSIONINFOW) &g_sysdiag.rtl_osversioninfoexw) < 0)
		return 0xC0000001;
	NdisInitializeReadWriteLock(&g_sysdiag.ndis_rw_lock_168);
	g_sysdiag.nrl_flag_160.flag_0 |= 3u;
	if (!(g_sysdiag.nrl_flag_160.flag_0 & 1))
		return 0xC0000001;
	NdisInitializeReadWriteLock(&g_sysdiag.ndis_rw_lock_598);
	g_sysdiag.nrl_flag_590.flag_0 |= 3u;
	if (!(g_sysdiag.nrl_flag_590.flag_0 & 1))
		return 0xC0000001;
	g_sysdiag.eres_flag_9b8.flag_0 &= 0xFDu;
	g_sysdiag.eres_flag_9b8.flag_0 = g_sysdiag.eres_flag_9b8.flag_0 & 0xFE | (ExInitializeResourceLite(&g_sysdiag.eresource_9c0) >= 0);
	if (!(g_sysdiag.eres_flag_9b8.flag_0 & 1))
		return 0xC0000001;
	NdisInitializeReadWriteLock(&g_sysdiag.ndis_rw_lock_df0);
	g_sysdiag.nrl_flag_de8.flag_0 |= 3u;
	if (!(g_sysdiag.nrl_flag_de8.flag_0 & 1))
		return 0xC0000001;
	NdisInitializeReadWriteLock(&g_sysdiag.ndis_rw_lock_1220);
	g_sysdiag.nrl_flag_1218.flag_0 |= 3u;
	if (!(g_sysdiag.nrl_flag_1218.flag_0 & 1))
		return 0xC0000001;
	NdisInitializeReadWriteLock(&g_sysdiag.ndis_rw_lock_1658);
	g_sysdiag.nrl_flag_1650.flag_0 |= 3u;
	if (!(g_sysdiag.nrl_flag_1650.flag_0 & 1))
		return 0xC0000001;
	g_sysdiag.eres_flag_1a78.flag_0 &= 0xFDu;
	g_sysdiag.eres_flag_1a78.flag_0 = g_sysdiag.eres_flag_1a78.flag_0 & 0xFE | (ExInitializeResourceLite(&g_sysdiag.eresource_1a80) >= 0);
	if (!(g_sysdiag.eres_flag_1a78.flag_0 & 1))
		return 0xC0000001;
	NdisInitializeReadWriteLock(&g_sysdiag.ndis_rw_lock_1ec8);
	g_sysdiag.nrl_flag_1ec0.flag_0 |= 3u;
	if (!(g_sysdiag.nrl_flag_1ec0.flag_0 & 1))
		return 0xC0000001;

	g_sysdiag.pdriver_object_8 = DriverObject;
	g_sysdiag.ppdriver_object_0 = &DriverObject;


	PINIT_LIST list = g_LT;
	int IoRegister_flag = 0;
	int unload_flag = 1;
	while (list) {
		status = list->pnext_ft->sub_0(list->pnext_ft , DriverObject , RegistryPath);
		if (status < 0) {
			//退出清理
			hr_ExitCleaner(DriverObject);
			return unload_flag ? status : 0;
		}
		IoRegister_flag = list->pnext_ft->sub_10 ? 1 : IoRegister_flag;
		unload_flag = list->pnext_ft->sub_8 ? unload_flag : 0;
		list = list->pnext_list;
	}



	for (int i = 0; i < 28; i++) {
		DriverObject->MajorFunction[i] = hr_driver_dispatch;
	}
	if (unload_flag) {
		DriverObject->DriverUnload = hr_driver_unload;
	}
	if (IoRegister_flag) {
		IoRegisterBootDriverReinitialization(DriverObject , hr_BootDriverReinitialization , (PVOID) 0x424F4F54);
		IoRegisterDriverReinitialization(DriverObject , hr_DriverReinitialization , NULL);
	}
	g_sysdiag.ppdriver_object_0 = NULL;
	return status;
}
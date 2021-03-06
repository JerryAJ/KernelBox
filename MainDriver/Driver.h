#include <ntddk.h>

#include "Process.h"
#include "SSDT.h"

#define	DEVICE_NAME				L"\\Device\\AJ_Driver"
#define LINK_NAME				L"\\DosDevices\\AJ_Driver"
#define LINK_GLOBAL_NAME		L"\\DosDevices\\Global\\AJ_Driver"

#define IOCTL_TEST				CTL_CODE(FILE_DEVICE_UNKNOWN, 0x800, METHOD_BUFFERED, FILE_ANY_ACCESS) 

#define IOCTL_GetFuncAddr		CTL_CODE(FILE_DEVICE_UNKNOWN, 0x801, METHOD_BUFFERED, FILE_ANY_ACCESS)	// Out Long
#define IOCTL_GetKiSrvTableAddr	CTL_CODE(FILE_DEVICE_UNKNOWN, 0x802, METHOD_BUFFERED, FILE_ANY_ACCESS)	// 获取KiServiceTable地址
#define IOCTL_GetProcessNum		CTL_CODE(FILE_DEVICE_UNKNOWN, 0x803, METHOD_BUFFERED, FILE_ANY_ACCESS)	// 获取进程数目
#define IOCTL_GetProcessList	CTL_CODE(FILE_DEVICE_UNKNOWN, 0x804, METHOD_BUFFERED, FILE_ANY_ACCESS)	// 获取进程列表
#define IOCTL_GetProcessModules	CTL_CODE(FILE_DEVICE_UNKNOWN, 0x805, METHOD_BUFFERED, FILE_ANY_ACCESS)	// 获取进程模块
#define IOCTL_GetProcessThread	CTL_CODE(FILE_DEVICE_UNKNOWN, 0x806, METHOD_BUFFERED, FILE_ANY_ACCESS)	// 获取进程线程
#define IOCTL_SuspendProcess	CTL_CODE(FILE_DEVICE_UNKNOWN, 0x807, METHOD_BUFFERED, FILE_ANY_ACCESS)	// 暂停进程
#define IOCTL_ResumeProcess		CTL_CODE(FILE_DEVICE_UNKNOWN, 0x808, METHOD_BUFFERED, FILE_ANY_ACCESS)	// 恢复进程
#define IOCTL_TerminateProcess	CTL_CODE(FILE_DEVICE_UNKNOWN, 0x809, METHOD_BUFFERED, FILE_ANY_ACCESS)	// 终结进程
#define IOCTL_UninstallModule	CTL_CODE(FILE_DEVICE_UNKNOWN, 0x810, METHOD_BUFFERED, FILE_ANY_ACCESS)	// 卸载模块
#define IOCTL_TerminateThread	CTL_CODE(FILE_DEVICE_UNKNOWN, 0x811, METHOD_BUFFERED, FILE_ANY_ACCESS)	// 终结线程
#define IOCTL_SuspendThread		CTL_CODE(FILE_DEVICE_UNKNOWN, 0x812, METHOD_BUFFERED, FILE_ANY_ACCESS)	// 挂起线程
#define IOCTL_ResumeThread		CTL_CODE(FILE_DEVICE_UNKNOWN, 0x813, METHOD_BUFFERED, FILE_ANY_ACCESS)	// 恢复线程
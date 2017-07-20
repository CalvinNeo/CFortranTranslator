#include "../for90std/for90std.h"
#include "windows.h"
#define USE_FORARRAY

struct Cls {
	~Cls() {
		puts("end");
	}
};

void sub(int && c) {

}

DWORD GetHarddiskNum()
{
	char cVolume[256];                                         //  
	char cFileSysName[256];
	DWORD dwSerialNum;                                          //Ó²ÅÌÐòÁÐºÅ   
	DWORD dwFileNameLength;
	DWORD dwFileSysFlag;
	
	::GetVolumeInformation("C://", cVolume, 256, &dwSerialNum, &dwFileNameLength,
		&dwFileSysFlag, cFileSysName, 256);

	printf("%x\n", dwSerialNum);

	return dwSerialNum;
}
DWORD GetPhysicalDriveSerialNumber(UINT nDriveNumber, std::string & strSerialNumber)
{
	DWORD dwResult = NO_ERROR;

	// Format physical drive path (may be '\\.\PhysicalDrive0', '\\.\PhysicalDrive1' and so on).

	// call CreateFile to get a handle to physical drive
	HANDLE hDevice = ::CreateFile(TEXT("\\\\.\\PhysicalDrive0"), 0, FILE_SHARE_READ | FILE_SHARE_WRITE,
		NULL, OPEN_EXISTING, 0, NULL);

	if (INVALID_HANDLE_VALUE == hDevice)
		return ::GetLastError();

	// set the input STORAGE_PROPERTY_QUERY data structure
	STORAGE_PROPERTY_QUERY storagePropertyQuery;
	ZeroMemory(&storagePropertyQuery, sizeof(STORAGE_PROPERTY_QUERY));
	storagePropertyQuery.PropertyId = StorageDeviceProperty;
	storagePropertyQuery.QueryType = PropertyStandardQuery;

	// get the necessary output buffer size
	STORAGE_DESCRIPTOR_HEADER storageDescriptorHeader = { 0 };
	DWORD dwBytesReturned = 0;
	if (!::DeviceIoControl(hDevice, IOCTL_STORAGE_QUERY_PROPERTY,
		&storagePropertyQuery, sizeof(STORAGE_PROPERTY_QUERY),
		&storageDescriptorHeader, sizeof(STORAGE_DESCRIPTOR_HEADER),
		&dwBytesReturned, NULL))
	{
		dwResult = ::GetLastError();
		::CloseHandle(hDevice);
		return dwResult;
	}

	// allocate the necessary memory for the output buffer
	const DWORD dwOutBufferSize = storageDescriptorHeader.Size;
	BYTE* pOutBuffer = new BYTE[dwOutBufferSize];
	ZeroMemory(pOutBuffer, dwOutBufferSize);

	// get the storage device descriptor
	if (!::DeviceIoControl(hDevice, IOCTL_STORAGE_QUERY_PROPERTY,
		&storagePropertyQuery, sizeof(STORAGE_PROPERTY_QUERY),
		pOutBuffer, dwOutBufferSize,
		&dwBytesReturned, NULL))
	{
		dwResult = ::GetLastError();
		delete[]pOutBuffer;
		::CloseHandle(hDevice);
		return dwResult;
	}

	// Now, the output buffer points to a STORAGE_DEVICE_DESCRIPTOR structure
	// followed by additional info like vendor ID, product ID, serial number, and so on.
	STORAGE_DEVICE_DESCRIPTOR* pDeviceDescriptor = (STORAGE_DEVICE_DESCRIPTOR*)pOutBuffer;
	const DWORD dwSerialNumberOffset = pDeviceDescriptor->SerialNumberOffset;
	if (dwSerialNumberOffset != 0)
	{
		// finally, get the serial number
		const char * xchar = (const char *)pOutBuffer + dwSerialNumberOffset;
		strSerialNumber = std::string(xchar);
	}

	// perform cleanup and return
	delete[] pOutBuffer;
	::CloseHandle(hDevice);
	return dwResult;
}
int main() {
	//int a = 1;
	//reference_wrapper<int> w = make_reference_wrapper(a);
	//w.get() = 2;
	//reference_wrapper<int> w2 = std::reference_wrapper<int>(a);
	//w2.get() = 3;
	std::string sss;
	GetPhysicalDriveSerialNumber(0, sss);
	cout << sss << endl;
	GetHarddiskNum();
	int a = 0;
	forreadfree(stdin, make_iolambda({ 1 }, { 1 }, [&](const fsize_t * current) {
		return [&](fsize_t i) {
			std::tuple<int*> tt = make_tuple(&a);
			return IOStuff<int*>(tt);
		}(current[0]);
	}));

	//int a = 1;
	//tuple<int&> tu = std::tie(a);
	//tuple<int&> tu2 = tu;
	//std::get<0>(tu2) = 22;
	forprintfree(a);
	

	system("pause");
	return 0;
}
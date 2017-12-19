#include "XmlApi.h"
#if 1
#define PRINTF printf
#else
#define PRINTF
#endif

typedef struct ACSConfig {
	char DeviceSummary[PARAM_MAX_LENGTH] ;
	char ACSName[PARAM_MAX_LENGTH] ;
	char Description[PARAM_MAX_LENGTH] ;
	char SoftwareVersion[PARAM_MAX_LENGTH] ;
	char Copyright[PARAM_MAX_LENGTH] ;
	char Author[PARAM_MAX_LENGTH] ;
	char Contact[PARAM_MAX_LENGTH] ;
	unsigned int ServerPort;
	unsigned int ServerSSLPort ;
	char Username[PARAM_MAX_LENGTH] ;
	char Password[PARAM_MAX_LENGTH] ;
	unsigned char SSLEnable ;
	unsigned char AuthType ;
	char Realm[PARAM_MAX_LENGTH] ;
	char CACERT_PEM[PARAM_MAX_LENGTH] ;
	char SERVER_PEM[PARAM_MAX_LENGTH] ;
	char SERVER_PEM_Password[PARAM_MAX_LENGTH] ;
	char DH_PEM[PARAM_MAX_LENGTH] ;
    char CLIENT_PEM[PARAM_MAX_LENGTH] ;
	char CLIENT_PEM_Password[PARAM_MAX_LENGTH] ;
	unsigned int ManageableDeviceNotificationLimit ;
	unsigned int ManageableDeviceNumberOfEntries ;
}ACSConfig;

typedef struct CwmpConfig {
	char ACSName[PARAM_MAX_LENGTH] ;
	char Manufacturer[PARAM_MAX_LENGTH] ;
	char ManufacturerOUI[PARAM_MAX_LENGTH] ;
	char ModelName[PARAM_MAX_LENGTH] ;
	char Description[PARAM_MAX_LENGTH] ;
	char ProductClass[PARAM_MAX_LENGTH] ;
	char SerialNumber[PARAM_MAX_LENGTH] ;
	char HardwareVersion[PARAM_MAX_LENGTH] ;
	char SoftwareVersion[PARAM_MAX_LENGTH] ;
	char ModemFirmwareVersion[PARAM_MAX_LENGTH] ;
	char DeviceFirmwareVersion[PARAM_MAX_LENGTH] ;
	char FirmwareVersionDate[PARAM_MAX_LENGTH] ;
	char SpecVersion[PARAM_MAX_LENGTH] ;
	char ProvisioningCode[PARAM_MAX_LENGTH] ;
	
	char URL[PARAM_MAX_LENGTH] ;
    char Username[PARAM_MAX_LENGTH] ;
    char Password[PARAM_MAX_LENGTH] ;
    unsigned char PeriodicInformEnable ;
    unsigned int PeriodicInformInterval ;
    char PeriodicInformTime[PARAM_MAX_LENGTH] ;
    unsigned char RandomPeriodicInformEnable ;
    char ParameterKey[PARAM_MAX_LENGTH] ;
	unsigned int ConnectionRequestPort ;
    char ConnectionRequestURL[PARAM_MAX_LENGTH] ;
    char ConnectionRequestUsername[PARAM_MAX_LENGTH] ;
    char ConnectionRequestPassword[PARAM_MAX_LENGTH] ;
	unsigned char ACSContacted ;
    unsigned char SSLEnable ;
    unsigned char InitDatamodel ;
	unsigned char ItmsRemoteRebootCommandKey ;
    unsigned char ItmsRemoteReboot ;
    unsigned char AuthType ;
    unsigned char InitTreeValue ;
	char Realm[PARAM_MAX_LENGTH] ;
	char CACERT_PEM[PARAM_MAX_LENGTH] ;
	char SERVER_PEM[PARAM_MAX_LENGTH] ;
	char SERVER_PEM_Password[PARAM_MAX_LENGTH] ;
	char DH_PEM[PARAM_MAX_LENGTH] ;
	char CLIENT_PEM[PARAM_MAX_LENGTH] ;
	char CLIENT_PEM_Password[PARAM_MAX_LENGTH] ;
}CwmpConfig;

typedef struct CwmpUploadData {
	char CommandKey[PARAM_MAX_LENGTH] ;
	char FileType[PARAM_MAX_LENGTH] ;
	char URL[PARAM_MAX_LENGTH] ;
	char Username[PARAM_MAX_LENGTH] ;
	char Password[PARAM_MAX_LENGTH] ;
	int DelaySeconds ;
}CwmpUploadData ;

typedef struct CwmpDownloadData {
	char CommandKey[PARAM_MAX_LENGTH] ;
	char FileType[PARAM_MAX_LENGTH] ;
	char URL[PARAM_MAX_LENGTH] ;
	char Username[PARAM_MAX_LENGTH] ;
	char Password[PARAM_MAX_LENGTH] ;
	int FileSize ;
	char TargetFileName[PARAM_MAX_LENGTH] ;
	int DelaySeconds ;
	char SuccessURL[PARAM_MAX_LENGTH] ;
	char FailureURL[PARAM_MAX_LENGTH] ;
}CwmpDownloadData ;

typedef struct CwmpScheduleInformData {
	int DelaySeconds ;
	char CommandKey[PARAM_MAX_LENGTH] ;
}CwmpScheduleInformData ;

typedef struct CwmpTranferCompleteData {
	char CommandKey[PARAM_MAX_LENGTH] ;
	time_t StartTime ;
	time_t CompleteTime ;
	char FaultCode[PARAM_MAX_LENGTH] ;
	char FaultString[PARAM_MAX_LENGTH] ;
}CwmpTranferCompleteData ;

ACSConfig Acsconfig ;

CwmpConfig Cwmpconfig ;

CwmpUploadData * uploadData ;
CwmpDownloadData * downloadData ;
CwmpScheduleInformData * scheduleInformData ;
CwmpTranferCompleteData * tranferCompleteData ;

//eRPCName RpcName ;

char RpcName[PARAM_MAX_LENGTH] ;
char RpcNameRes[PARAM_MAX_LENGTH] ;
unsigned char ServerMode ;

unsigned char cwmp_NameListNum ;
unsigned char cwmp_ValueListNum ;
unsigned char cwmp_EventNum ;
char cwmp_EventCode[PARAM_MAX_LENGTH][PARAM_MAX_LENGTH] ;
char cwmp_NameList[PARAM_MAX_LENGTH][PARAM_MAX_LENGTH] ;
char cwmp_ValueList[PARAM_MAX_LENGTH][PARAM_MAX_LENGTH] ;

unsigned char cwmp_EventActionID ;







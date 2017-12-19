#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cwmpDebug.h"
#ifndef WHOLE_COMPILE
#include "Cwmp.nsmap"
#endif
#include "soapH.h"
#include "time.h"
#include <unistd.h>		/* defines _POSIX_THREADS if pthreads are available */
#if defined(_POSIX_THREADS) || defined(_SC_THREADS)
#include <pthread.h>
#endif
#if defined(_POSIX_SIGNAL)
#include <signal.h>		/* defines SIGPIPE */
#endif
#if defined(HTTP_GET)
#include "httpget.h"
#endif
//struct soap * soapClient ;
char Server[128] = {0} ;

#if defined (WITH_OPENSSL)
#if defined (DIGEST_AUTH)
#include "httpda.h" 	/* optionally enable HTTP Digest Authentication */
#endif
//#define CACERT_PEM "./ssl/CA/cacert.pem"
//#define CLIENT_PRM "./ssl/CA/client.pem"
#endif

int CRYPTO_thread_setup();
void CRYPTO_thread_cleanup();


#if defined(_POSIX_SIGNAL)
void sigpipe_handle(int);
#endif

int informParamNum = 8 ;	//default inform parameters number
char *informParameters[] = {		//define default inform parameters .
    "InternetGatewayDevice.DeviceInfo.SpecVersion",
    "InternetGatewayDevice.DeviceInfo.HardwareVersion",
    "InternetGatewayDevice.DeviceInfo.SoftwareVersion",
    "InternetGatewayDevice.DeviceInfo.ProvisioningCode",
    "InternetGatewayDevice.ManagementServer.ConnectionRequestURL",
    "InternetGatewayDevice.ManagementServer.ConnectionRequestUsername",
    "InternetGatewayDevice.ManagementServer.ConnectionRequestPassword",
    "InternetGatewayDevice.ManagementServer.ParameterKey",
#ifdef TR106_SUPPORT
    "InternetGatewayDevice.DeviceSummary",
#endif
    NULL
};

#ifdef WHOLE_COMPILE
#ifdef WITH_WEBSERVER
char WebBuffer[PARAM_MAX_LENGTH*PARAM_MAX_LENGTH] ;	//define for Web GUI display string 
unsigned char WebBufferTag ;	// string data exist
#endif
#endif
static int ConnectedStatus = 0 ;

int cwmp_EmptyPost(struct soap * soap , const char * Server) ;
int cwmp_Inform(struct soap * soap ,const char * Server , char ** DeviceEventInfo , char * CurrentTime , char ** ParameterNameList , char ** ParameterValueList , int * OtherOption);
int cwmp_GetRPCMethods(struct soap * soap , const char * Server , char *** RPCSupportList,int * size) ;
int cwmp_GetNamelist(struct soap * soap , const char * Server , char * Path, char *** NameList, int ** Writeable,int * size);
int cwmp_GetParameterValue(struct soap * soap , const char * Server, char ** NameList, char *** ValueList, int size) ;
int cwmp_SetParameterValue(struct soap * soap , const char * Server, char ** NameList, char ** ValueList, int size) ;
int cwmp_GetParameterAttributes(struct soap * soap,const char * Server, char ** NameList, int ** AttrList, int size) ;
int cwmp_SetParameterAttributes(struct soap * soap,const char * Server, char ** NameList ,int * AttrList, int size) ;
int cwmp_AddObject(struct soap * soap,const char * Server, char * objpath) ;
int cwmp_DelObject(struct soap * soap,const char * Server, char * objpath) ;
int cwmp_Reboot(struct soap * soap,const char * Server, char * CommandKey) ;
int cwmp_Download(struct soap * soap,const char * Server,char *CommandKey,char *FileType,char *URL,char *Username,char *Password,int FileSize,char *TargetFileName,int DelaySeconds,char *SuccessURL,char *FailureURL) ;
int cwmp_Upload(struct soap * soap,const char * Server, char *CommandKey,char *FileType,char *URL,char *Username,char *Password,int DelaySeconds) ;
int cwmp_FactoryReset(struct soap * soap,const char * Server) ;
int cwmp_ScheduleInform(struct soap * soap,const char * Server, int DelaySeconds , char * CommandKey) ;
int cwmp_TranferComplete(struct soap * soap,const char * Server, char * CommandKey , time_t StartTime , time_t CompleteTime , char * FaultCode , char * FaultString) ;
void CwmpClient_Init_Soap(struct soap * soapClient) ;
int CwmpClient_SendInform(struct soap * soap) ;


void Cwmp_Auth_Adapter(struct soap * soap , int AuthMode , char * Userid , char * Passwd , char * Realm)
{
	switch (AuthMode)
	{
		case 0 :
			break ;

		case 1 :
			if(Cwmpconfig.AuthType == 1 || Cwmpconfig.AuthType == 3)
			{
#if defined(BASIC_AUTH)
				cwmp_BasicAuth(soap,Userid,Passwd) ;
			
#endif
			}
			break ;
		case 2 :
			if(Cwmpconfig.SSLEnable)
			{
#if defined(WITH_OPENSSL)
				if(Cwmpconfig.AuthType == 2 || Cwmpconfig.AuthType == 3)
				{
#if defined(DIGEST_AUTH)
					cwmp_DigestAuth(soap,Userid,Passwd,Realm) ;
			
#endif
				}
#endif
			}
			break ;
	}
    return ;
}

int Cwmp_EmptyPost_Adapter(struct soap * soap)
{
	PRINTF("Start Send Empty Post to ACS Server\n") ;
#ifdef SUPPORT_EMPTYPOST
	return cwmp_EmptyPost(soap,Cwmpconfig.URL) ;
#else
	return 0 ;
#endif
}

#ifdef SERVER_CONNECT_RES

void __Cwmp_Auth_Adapter(struct soap * soap , int AuthMode)
{
    switch (AuthMode)
	{
		case 0 :
			break ;

		case 1 :
			if(Cwmpconfig.AuthType == 1 || Cwmpconfig.AuthType == 3)
			{
#if defined(BASIC_AUTH)
				cwmp_BasicAuth(soap,Cwmpconfig.Username,Cwmpconfig.Password) ;
			
#endif
			}
			break ;
		case 2 :
			if(Cwmpconfig.SSLEnable)
			{
#if defined(WITH_OPENSSL)
				if(Cwmpconfig.AuthType == 2 || Cwmpconfig.AuthType == 3)
				{
#if defined(DIGEST_AUTH)
					cwmp_DigestAuth(soap,Cwmpconfig.Username,Cwmpconfig.Password,Cwmpconfig.Realm) ;
#endif
				}
#endif
			}
			break ;
	}
    return ;
}

void ServerConnectHandle()
{
    struct soap soap ;
    int ret = 0 ;
    CwmpClient_Init_Soap(&soap) ;
    ret = cwmp_EmptyGet(&soap , Cwmpconfig.URL) ;
    if(ret == 0)
	{
		cwmp_EventNum = 0 ;
		memset(cwmp_EventCode,0x0,sizeof(cwmp_EventCode)) ;
		sprintf(cwmp_EventCode[cwmp_EventNum],"6 CONNECTION REQUEST") ;
		cwmp_EventNum ++ ;
		CwmpClient_SendInform(&soap) ;
#ifdef WITH_WEBSERVER
		WebBufferTag = 0 ;
    	memset(WebBuffer,0x0,sizeof(WebBuffer)) ;
    	WebBufferTag = 1 ;
#endif
	}
    soap_end(&soap);
    soap_done(&soap);
	CRYPTO_thread_cleanup();
    return ;
}
#endif

//int CwmpClient_Inform_Adapter(char * EventString)
int CwmpClient_Inform_Adapter(struct soap * soap , char ** DeviceEventInfo , char * CurrentTime , char ** ParameterNameList , char ** ParameterValueList , int * OtherOption)
{
	Cwmp_Auth_Adapter(soap,0,Cwmpconfig.Username,Cwmpconfig.Password,Cwmpconfig.Realm) ; // Try No Auth
    PRINTF("Send Inform to URL = [%s]\n",Cwmpconfig.URL);
	if(SOAP_OK == cwmp_Inform(soap,Cwmpconfig.URL,DeviceEventInfo , CurrentTime , ParameterNameList , ParameterValueList , OtherOption))
	{
        PRINTF("No Auth Success\n");
		return Cwmp_EmptyPost_Adapter(soap) ;
	} else
	{
		if(soap->error == 401) // HTTP authentication is required
		{
			Cwmp_Auth_Adapter(soap,1,Cwmpconfig.Username,Cwmpconfig.Password,Cwmpconfig.Realm) ; // Try Basic Auth
			if(SOAP_OK == cwmp_Inform(soap,Cwmpconfig.URL,DeviceEventInfo , CurrentTime , ParameterNameList , ParameterValueList , OtherOption))
			{
				return Cwmp_EmptyPost_Adapter(soap) ;
			} else
			{
				if(soap->error == 401) // HTTP authentication is required
				{
					Cwmp_Auth_Adapter(soap,2,Cwmpconfig.Username,Cwmpconfig.Password,Cwmpconfig.Realm) ; // Try Digset Auth
					if(SOAP_OK == cwmp_Inform(soap,Cwmpconfig.URL,DeviceEventInfo , CurrentTime , ParameterNameList , ParameterValueList , OtherOption))
					{	
						return Cwmp_EmptyPost_Adapter(soap) ;
					}
				}
			}
		}
	}
	return SOAP_OK ;
}
#ifdef CWMP_TEST
//int CwmpClient_GetRPCMethods_Adapter()
int CwmpClient_GetRPCMethods_Adapter(struct soap * soap , char *** RPCSupportList,int * size)
{
    return cwmp_GetRPCMethods(soap,Cwmpconfig.URL,RPCSupportList,size);
}

int CwmpClient_GetNamelist_Adapter(struct soap * soap , char * Path, char *** NameList, int ** Writeable,int * size)
{
    return cwmp_GetNamelist(soap,Cwmpconfig.URL,Path,NameList,Writeable,size);
}

int CwmpClient_GetParameterValue_Adapter(struct soap * soap , char ** NameList, char *** ValueList, int size)
{
    return cwmp_GetParameterValue(soap,Cwmpconfig.URL,NameList,ValueList,size);
}

int CwmpClient_SetParameterValue_Adapter(struct soap * soap , char ** NameList, char ** ValueList, int size)
{
    return cwmp_SetParameterValue(soap,Cwmpconfig.URL,NameList,ValueList,size);
}

int CwmpClient_GetParameterAttributes_Adapter(struct soap * soap , char ** NameList, int ** AttrList, int size)
{
    return cwmp_GetParameterAttributes(soap,Cwmpconfig.URL,NameList,AttrList,size);
}

int CwmpClient_SetParameterAttributes_Adapter(struct soap * soap , char ** NameList , int * AttrList, int size)
{
    return cwmp_SetParameterAttributes(soap,Cwmpconfig.URL,NameList,AttrList,size);
}

int CwmpClient_AddObject_Adapter(struct soap * soap , char * ObjPath)
{
    return cwmp_AddObject(soap,Cwmpconfig.URL,ObjPath);
}

int CwmpClient_DelObject_Adapter(struct soap * soap , char * ObjPath)
{
    return cwmp_DelObject(soap,Cwmpconfig.URL,ObjPath);
}
int CwmpClient_Reboot_Adapter(struct soap * soap , char * CommandKey)
{
    return cwmp_Reboot(soap,Cwmpconfig.URL,CommandKey);
}
int CwmpClient_Download_Adapter(struct soap * soap , char *CommandKey,char *FileType,char *URL,char *Username,char *Password,int FileSize,char *TargetFileName,int DelaySeconds,char *SuccessURL,char *FailureURL)
{
    return cwmp_Download(soap,Cwmpconfig.URL,CommandKey,FileType,URL,Username,Password,FileSize,TargetFileName,DelaySeconds,SuccessURL,FailureURL);
}
int CwmpClient_Upload_Adapter(struct soap * soap , char *CommandKey,char *FileType,char *URL,char *Username,char *Password,int DelaySeconds)
{
    return cwmp_Upload(soap,Cwmpconfig.URL,CommandKey,FileType,URL,Username,Password,DelaySeconds);
}

int CwmpClient_FactoryReset_Adapter(struct soap * soap)
{
    return cwmp_FactoryReset(soap,Cwmpconfig.URL);
}
int CwmpClient_ScheduleInform_Adapter(struct soap * soap , int DelaySeconds , char * CommandKey)
{
    return cwmp_ScheduleInform(soap,Cwmpconfig.URL,DelaySeconds,CommandKey);
}
int CwmpClient_TranferComplete_Adapter(struct soap * soap , char * CommandKey , time_t StartTime , time_t CompleteTime , char * FaultCode , char * FaultString)
{
    return cwmp_TranferComplete(soap,Cwmpconfig.URL,CommandKey,StartTime,CompleteTime,FaultCode,FaultString);
}
#endif

time_t getCurrentTime()
{ 
    time_t t; 
    t = time (&t);
    return t;
}

char * getTimeString()
{
	time_t t;
    t = time (&t);
	return ctime(&t) ;
}

void * Cwmp_Malloc(struct soap *soap , int size)
{
    void * p ;
    p = soap_malloc(soap,size) ;
    memset(p,0x0,size);
    return p ;
}

void * CwmpClient_Malloc(struct soap *soap,int size)
{
    return  Cwmp_Malloc(soap,size);
}

void * Cwmp_Strdup(struct soap *soap , char * string)
{
    return soap_strdup(soap , string) ;
}

void * CwmpClient_Strdup(struct soap *soap,char * string)
{
    return Cwmp_Strdup(soap,string) ;
}

/*
    "0 BOOTSTRAP",
    "1 BOOT",
    "2 PERIODIC",
    "3 SCHEDULED",
    "4 VALUE CHANGE",
    "5 KICKED",
    "6 CONNECTION REQUEST",
    "7 TRANSFER COMPLETE",
    "8 DIAGNOSTICS COMPLETE",
    "M Download",
    "M Reboot",
    "M ScheduleInform",
    "M SetParameterValues",
    "M AddObject",
    "M DeleteObject"
*/




int CwmpGetInformParamNum()
{
	return informParamNum ;
}
#ifdef CWMP_TEST

int CwmpGetEventNum()
{
	return 2 ;
}

int CwmpGetEventCode(int index , char * EventCode , char * CommandKey)
{
	memset(EventCode,0x0,PARAM_MAX_LENGTH) ;
	memset(CommandKey,0x0,PARAM_MAX_LENGTH) ;
	switch(index)
	{
		case 1 : sprintf(EventCode,"0 BOOTSTRAP") ;
				sprintf(CommandKey,"1") ;
				break ;
		case 2 : sprintf(EventCode,"4 VALUE CHANGE") ;
				sprintf(CommandKey,"0") ;
				break ;
		default : break ;
	}
	return 0 ;
}

int CwmpGetInformParamInfo(int index , char * Name , char * Value)
{
	memset(Name,0x0,PARAM_MAX_LENGTH) ;
	memset(Value,0x0,PARAM_MAX_LENGTH) ;
    sprintf(Name,"%s",informParameters[index-1]) ;
    return _GetConfigValue(informParameters[index-1] , Value) ;
}
int CwmpClient_Inform_Test_Adapter(struct soap * soap)
{
    int DeviceSize = 4 ;
    int EventSize = 0 ;
    char ** DeviceEventInfo ;

    int MaxEnvelopes = 1 ;
    int RetryCount = 1 ;
    char * CurrentTime ;

    int ParameterSize = 0 ;
    char ** ParameterNameList ;
    char ** ParameterValueList ;

    int * OtherOption ;
    int i = 0 ;

	char *pName = (char *) soap_malloc(soap,PARAM_MAX_LENGTH) ;
	char *pValue = (char *) soap_malloc(soap,PARAM_MAX_LENGTH) ;
    OtherOption = (int *)CwmpClient_Malloc(soap,4*sizeof(int));

	EventSize = CwmpGetEventNum() ;
	ParameterSize = CwmpGetInformParamNum() ;

    OtherOption[0] = EventSize ;
    OtherOption[1] = MaxEnvelopes ;
    OtherOption[2] = RetryCount ;
    OtherOption[3] = ParameterSize ;

    DeviceEventInfo = (char **)CwmpClient_Malloc(soap,(DeviceSize+EventSize*2)*sizeof(char *)) ;
	if(_GetConfigValue("InternetGatewayDevice.DeviceInfo.Manufacturer",pValue) == 0)
    	DeviceEventInfo[0] = (char *)CwmpClient_Strdup(soap,pValue) ; //Manufacturer
	if(_GetConfigValue("InternetGatewayDevice.DeviceInfo.ManufacturerOUI",pValue) == 0)
    	DeviceEventInfo[1] = (char *)CwmpClient_Strdup(soap,pValue) ; //OUI
	if(_GetConfigValue("InternetGatewayDevice.DeviceInfo.ProductClass",pValue) == 0)
    	DeviceEventInfo[2] = (char *)CwmpClient_Strdup(soap,pValue) ; //ProductClass
	if(_GetConfigValue("InternetGatewayDevice.DeviceInfo.SerialNumber",pValue) == 0)
    	DeviceEventInfo[3] = (char *)CwmpClient_Strdup(soap,pValue) ; //SerialNumber
	for(i = 0 ; i < EventSize ; i ++)
	{
		if(CwmpGetEventCode(i+1,pName,pValue) == 0)
		{
			DeviceEventInfo[4+i*2] = (char *)CwmpClient_Strdup(soap,pName) ; //EventCode
			DeviceEventInfo[4+i*2+1] = (char *)CwmpClient_Strdup(soap,pValue) ; //CommandKey
		}
		
	}

	CurrentTime = (char *)CwmpClient_Strdup(soap,getTimeString()) ;
	CurrentTime[strlen(CurrentTime)-1] = '\0' ;
	PRINTF("TIME:%s\n",CurrentTime) ;
    ParameterNameList = (char **)CwmpClient_Malloc(soap,ParameterSize*sizeof(char *)) ;
    ParameterValueList = (char **)CwmpClient_Malloc(soap,ParameterSize*sizeof(char *)) ;
	for(i = 1 ; i <= ParameterSize ; i ++)
	{
		if(CwmpGetInformParamInfo(i,pName,pValue) == 0)
		{
			ParameterNameList[i-1] = (char *)CwmpClient_Strdup(soap,pName) ;
			ParameterValueList[i-1] = (char *)CwmpClient_Strdup(soap,pValue) ;
		}
	}

    return CwmpClient_Inform_Adapter(soap,DeviceEventInfo , CurrentTime , ParameterNameList , ParameterValueList , OtherOption);
}

int CwmpClient_GetRPCMethods_Test_Adapter(struct soap * soap)
{
    char *** RPCSupportList ;
    int size = 0 ;
    int result = 0 ;
    int i = 0 ;
    RPCSupportList = (char ***)CwmpClient_Malloc(soap,sizeof(char **)) ;
    result = CwmpClient_GetRPCMethods_Adapter(soap,RPCSupportList,&size) ;

    PRINTF("RPC Support List [%d]: \n",size) ;
    for(i = 0 ; i < size ; i ++)
        PRINTF("------------------------[%s]\n",RPCSupportList[0][i]) ;
    
    return result ;
}

int CwmpClient_GetNamelist_Test_Adapter(struct soap * soap)
{
    char *** NameList ;
    int ** Writeable ;
    char * Path ;
    int size = 0 ;
    int result = 0 ;
    int i = 0 ;
    NameList = (char ***)CwmpClient_Malloc(soap,sizeof(char **)) ;
    Writeable = (int **)CwmpClient_Malloc(soap,sizeof(int *)) ;
    Path = (char *)CwmpClient_Strdup(soap,"InternetGatewayDevice.") ;
    result = CwmpClient_GetNamelist_Adapter(soap,Path,NameList,Writeable,&size);
    PRINTF("NameList Support Under Path [%s] [%d]: \n",Path,size) ;
    for(i = 0 ; i < size ; i ++)
        PRINTF("-----[%s]:[%d]\n",NameList[0][i],Writeable[0][i]) ;
    
    return result ;
}

int CwmpClient_GetParameterValue_Test_Adapter(struct soap * soap)
{
	char ** NameList ;
    char *** ValueList ;

    int size = 0 ;
    int result = 0 ;
    int i = 0 ;

	size = 3 ;
    NameList = (char **)CwmpClient_Malloc(soap,size*sizeof(char *)) ;
    ValueList = (char ***)CwmpClient_Malloc(soap,sizeof(char **)) ;
	NameList[0] = (char *)CwmpClient_Strdup(soap,"InternetGatewayDevice.DeviceSummary") ;
	NameList[1] = (char *)CwmpClient_Strdup(soap,"InternetGatewayDevice.LANDeviceNumberOfEntries") ;
	NameList[2] = (char *)CwmpClient_Strdup(soap,"InternetGatewayDevice.WANDeviceNumberOfEntries") ;

    result = CwmpClient_GetParameterValue_Adapter(soap,NameList,ValueList,size);
    PRINTF("GetParameterValue :\n") ;

    for(i = 0 ; i < size ; i ++)
        PRINTF("-----[%s]:[%s]\n",NameList[i],ValueList[0][i]) ;

    return result ;
}

int CwmpClient_SetParameterValue_Test_Adapter(struct soap * soap)
{
	char ** NameList ;
    char ** ValueList ;

    int size = 0 ;
    int result = 0 ;
    int i = 0 ;

	size = 3 ;
    NameList = (char **)CwmpClient_Malloc(soap,size*sizeof(char *)) ;
    ValueList = (char **)CwmpClient_Malloc(soap,size*sizeof(char *)) ;
	NameList[0] = (char *)CwmpClient_Strdup(soap,"InternetGatewayDevice.DeviceSummary") ;
	NameList[1] = (char *)CwmpClient_Strdup(soap,"InternetGatewayDevice.LANDeviceNumberOfEntries") ;
	NameList[2] = (char *)CwmpClient_Strdup(soap,"InternetGatewayDevice.WANDeviceNumberOfEntries") ;

	ValueList[0] = (char *)CwmpClient_Strdup(soap,"CIG") ;
	ValueList[1] = (char *)CwmpClient_Strdup(soap,"2") ;
	ValueList[2] = (char *)CwmpClient_Strdup(soap,"1") ;

    result = CwmpClient_SetParameterValue_Adapter(soap,NameList,ValueList,size);
    PRINTF("SetParameterValue :\n") ;

    for(i = 0 ; i < size ; i ++)
        PRINTF("-----[%s]:[%s]\n",NameList[i],ValueList[i]) ;

    return result ;
}

int CwmpClient_GetParameterAttributes_Test_Adapter(struct soap * soap)
{
	char ** NameList ;
    int ** AttrList ;

    int size = 0 ;
    int result = 0 ;
    int i = 0 ;

	size = 3 ;
    NameList = (char **)CwmpClient_Malloc(soap,size*sizeof(char *)) ;
    AttrList = (int **)CwmpClient_Malloc(soap,sizeof(int *)) ;
	NameList[0] = (char *)CwmpClient_Strdup(soap,"InternetGatewayDevice.DeviceSummary") ;
	NameList[1] = (char *)CwmpClient_Strdup(soap,"InternetGatewayDevice.LANDeviceNumberOfEntries") ;
	NameList[2] = (char *)CwmpClient_Strdup(soap,"InternetGatewayDevice.WANDeviceNumberOfEntries") ;

    result = CwmpClient_GetParameterAttributes_Adapter(soap,NameList,AttrList,size);
    PRINTF("GetParameterAttributes :\n") ;

    for(i = 0 ; i < size ; i ++)
        PRINTF("-----[%s]:[%d]\n",NameList[i],AttrList[0][i]) ;

    return result ;
}

int CwmpClient_SetParameterAttributes_Test_Adapter(struct soap * soap)
{
	char ** NameList ;
    int * AttrList ;

    int size = 0 ;
    int result = 0 ;
    int i = 0 ;

	size = 3 ;
    NameList = (char **)CwmpClient_Malloc(soap,size*sizeof(char *)) ;
    AttrList = (int *)CwmpClient_Malloc(soap,size*sizeof(int)) ;
	NameList[0] = (char *)CwmpClient_Strdup(soap,"InternetGatewayDevice.DeviceSummary") ;
	NameList[1] = (char *)CwmpClient_Strdup(soap,"InternetGatewayDevice.LANDeviceNumberOfEntries") ;
	NameList[2] = (char *)CwmpClient_Strdup(soap,"InternetGatewayDevice.WANDeviceNumberOfEntries") ;

	AttrList[0] = 2 ;
	AttrList[1] = 1 ;
	AttrList[2] = 0 ;

    result = CwmpClient_SetParameterAttributes_Adapter(soap,NameList,AttrList,size);
    PRINTF("SetParameterAttributes :\n") ;

    for(i = 0 ; i < size ; i ++)
        PRINTF("-----[%s]:[%d]\n",NameList[i],AttrList[i]) ;

    return result ;
}


int CwmpClient_AddObject_Test_Adapter(struct soap * soap)
{
	int Instance = 0 ;
	char * Path ;
	Path = (char *)CwmpClient_Strdup(soap,"InternetGatewayDevice.LANDevice.") ;
	Instance = CwmpClient_AddObject_Adapter(soap,Path) ;
	PRINTF("AddObject : [%s%d]\n",Path,Instance) ;
	if(Instance != 0)
		return 0 ;
	return 1 ;
}

int CwmpClient_DelObject_Test_Adapter(struct soap * soap)
{
	int result ;
	char * Path ;
	Path = (char *)CwmpClient_Strdup(soap,"InternetGatewayDevice.LANDevice.1.") ;
	result = CwmpClient_DelObject_Adapter(soap,Path) ;
	PRINTF("AddObject : [%s]\n",Path) ;
	return result ;
}

int CwmpClient_Reboot_Test_Adapter(struct soap * soap)
{
	char * commandkey ;
	commandkey = (char *)CwmpClient_Strdup(soap,"Reboot") ;
	return CwmpClient_Reboot_Adapter(soap,commandkey) ;
}

int CwmpClient_Download_Test_Adapter(struct soap * soap)
{
	char * CommandKey = (char *)CwmpClient_Strdup(soap,"0");
    char * FileType = (char *)CwmpClient_Strdup(soap,"ZIP");
    char * URL = (char *)CwmpClient_Strdup(soap,"http://127.0.0.1:8080/test");
    char * Username = (char *)CwmpClient_Strdup(soap,"root");
    char * Password = (char *)CwmpClient_Strdup(soap,"admin");
    int FileSize = 1024 ;
    char * TargetFileName = (char *)CwmpClient_Strdup(soap,"test2");
    int DelaySeconds = 5 ;
    char * SuccessURL = (char *)CwmpClient_Strdup(soap,"http://127.0.0.1:8080/succ");
    char * FailureURL = (char *)CwmpClient_Strdup(soap,"http://127.0.0.1:8080/fail");
	return CwmpClient_Download_Adapter(soap,CommandKey,FileType,URL,Username,Password,FileSize,TargetFileName,DelaySeconds,SuccessURL,FailureURL);
	
}

int CwmpClient_Upload_Test_Adapter(struct soap * soap)
{
	char * CommandKey = (char *)CwmpClient_Strdup(soap,"0");
    char * FileType = (char *)CwmpClient_Strdup(soap,"ZIP");
    char * URL = (char *)CwmpClient_Strdup(soap,"http://127.0.0.1:8080/test");
    char * Username = (char *)CwmpClient_Strdup(soap,"root");
    char * Password = (char *)CwmpClient_Strdup(soap,"admin");
    int DelaySeconds = 5 ;

	return CwmpClient_Upload_Adapter(soap,CommandKey,FileType,URL,Username,Password,DelaySeconds);
}

int CwmpClient_FactoryReset_Test_Adapter(struct soap * soap)
{	
	CwmpClient_FactoryReset_Adapter(soap) ;
}

int CwmpClient_ScheduleInform_Test_Adapter(struct soap * soap)
{
	int DelaySeconds = 5 ;
	char * CommandKey = (char *)CwmpClient_Strdup(soap,"ScheduleInform");
	return CwmpClient_ScheduleInform_Adapter(soap,DelaySeconds,CommandKey) ;
}

int CwmpClient_TranferComplete_Test_Adapter(struct soap * soap)
{
	char * CommandKey = (char *)CwmpClient_Strdup(soap,"TranferComplete"); 
	time_t StartTime = getCurrentTime() ;
	time_t CompleteTime  = getCurrentTime() ; 
	char * FaultCode = (char *)CwmpClient_Strdup(soap,"001"); 
	char * FaultString = (char *)CwmpClient_Strdup(soap,"TranferComplete Successful");
	return CwmpClient_TranferComplete_Adapter(soap,CommandKey,StartTime,CompleteTime,FaultCode,FaultString) ;
}

int CwmpClient_RPC_Test_Adapter(struct soap * soap)
{

    SOAP_SOCKET ret ;
    ret = CwmpClient_Inform_Test_Adapter(soap);
	//ret = CwmpClient_FactoryReset_Adapter(soap);
#if 0
    ret = CwmpClient_GetRPCMethods_Test_Adapter();
    ret = CwmpClient_GetNamelist_Test_Adapter();
	ret = CwmpClient_GetParameterValue_Test_Adapter() ;
	ret = CwmpClient_SetParameterValue_Test_Adapter() ;
	ret = CwmpClient_GetParameterAttributes_Test_Adapter() ;
	ret = CwmpClient_SetParameterAttributes_Test_Adapter() ;
	ret = CwmpClient_AddObject_Test_Adapter() ;
	ret = CwmpClient_DelObject_Test_Adapter() ;
	ret = CwmpClient_Reboot_Test_Adapter() ;
	ret = CwmpClient_Download_Test_Adapter() ;
	ret = CwmpClient_Upload_Test_Adapter() ;
	ret = CwmpClient_FactoryReset_Test_Adapter();
    ret = CwmpClient_ScheduleInform_Test_Adapter();
    ret = CwmpClient_TranferComplete_Test_Adapter();

	ret = Cwmp_EmptyPost_Adapter() ;
#endif
    return ret ;
}
#endif

void CwmpConfig_Init()
{
	char * value = (char *)malloc(PARAM_MAX_LENGTH); 

	if(_GetConfigValue("InternetGatewayDevice.DeviceInfo.ACSName" , value))
	{
		sprintf(value,"Cwmp-Client[Service]") ;
		PRINTF("ACSName Init Error : Not found , Default : [%s]\n",value) ;
	}
	sprintf(Cwmpconfig.ACSName,"%s",value) ;

	if(_GetConfigValue("InternetGatewayDevice.DeviceInfo.Manufacturer" , value))
	{
		sprintf(value,"Gsoap") ;
		PRINTF("DeviceSummary Init Error : Not found , Default : [%s]\n",value) ;
	}
	sprintf(Cwmpconfig.Manufacturer,"%s",value) ;
	
	if(_GetConfigValue("InternetGatewayDevice.DeviceInfo.ManufacturerOUI" , value))
	{
		sprintf(value,"001E40") ;
		PRINTF("ManufacturerOUI Init Error : Not found , Default : [%s]\n",value) ;
	}
	sprintf(Cwmpconfig.ManufacturerOUI,"%s",value) ;
	
	if(_GetConfigValue("InternetGatewayDevice.DeviceInfo.ModelName" , value))
	{
		sprintf(value,"Cwmp-Client") ;
		PRINTF("ModelName Init Error : Not found , Default : [%s]\n",value) ;
	}
	sprintf(Cwmpconfig.ModelName,"%s",value) ;

	if(_GetConfigValue("InternetGatewayDevice.DeviceInfo.Description" , value))
	{
		sprintf(value,"Gsoap Cwmp-Client") ;
		PRINTF("Description Init Error : Not found , Default : [%s]\n",value) ;
	}
	sprintf(Cwmpconfig.Description,"%s",value) ;
	
	if(_GetConfigValue("InternetGatewayDevice.DeviceInfo.ProductClass" , value))
	{
		sprintf(value,"TR69") ;
		PRINTF("ProductClass Init Error : Not found , Default : [%s]\n",value) ;
	}
	sprintf(Cwmpconfig.ProductClass,"%s",value) ;

	if(_GetConfigValue("InternetGatewayDevice.DeviceInfo.SerialNumber" , value))
	{
		sprintf(value,"5D102") ;
		PRINTF("SerialNumber Init Error : Not found , Default : [%s]\n",value) ;
	}
	sprintf(Cwmpconfig.SerialNumber,"%s",value) ;

	if(_GetConfigValue("InternetGatewayDevice.DeviceInfo.HardwareVersion" , value))
	{
		sprintf(value,"V1.0") ;
		PRINTF("HardwareVersion Init Error : Not found , Default : [%s]\n",value) ;
	}
	sprintf(Cwmpconfig.HardwareVersion,"%s",value) ;


	if(_GetConfigValue("InternetGatewayDevice.DeviceInfo.SoftwareVersion" , value))
	{
		sprintf(value,"V2013.10") ;
		PRINTF("SoftwareVersion Init Error : Not found , Default : [%s]\n",value) ;
	}
	sprintf(Cwmpconfig.SoftwareVersion,"%s",value) ;

	if(_GetConfigValue("InternetGatewayDevice.DeviceInfo.ModemFirmwareVersion" , value))
	{
		sprintf(value,"V85.11.01.02") ;
		PRINTF("ModemFirmwareVersion Init Error : Not found , Default : [%s]\n",value) ;
	}
	sprintf(Cwmpconfig.ModemFirmwareVersion,"%s",value) ;

	if(_GetConfigValue("InternetGatewayDevice.DeviceInfo.DeviceFirmwareVersion" , value))
	{
		sprintf(value,"547C16_540001") ;
		PRINTF("DeviceFirmwareVersion Init Error : Not found , Default : [%s]\n",value) ;
	}
	sprintf(Cwmpconfig.DeviceFirmwareVersion,"%s",value) ;

	if(_GetConfigValue("InternetGatewayDevice.DeviceInfo.FirmwareVersionDate" , value))
	{
		sprintf(value,"2013.10.12") ;
		PRINTF("FirmwareVersionDate Init Error : Not found , Default : [%s]\n",value) ;
	}
	sprintf(Cwmpconfig.FirmwareVersionDate,"%s",value) ;

	if(_GetConfigValue("InternetGatewayDevice.DeviceInfo.SpecVersion" , value))
	{
		sprintf(value,"1") ;
		PRINTF("SpecVersion Init Error : Not found , Default : [%s]\n",value) ;
	}
	sprintf(Cwmpconfig.SpecVersion,"%s",value) ;

	if(_GetConfigValue("InternetGatewayDevice.DeviceInfo.ProvisioningCode" , value))
	{
		sprintf(value,"12345") ;
		PRINTF("ProvisioningCode Init Error : Not found , Default : [%s]\n",value) ;
	}
	sprintf(Cwmpconfig.ProvisioningCode,"%s",value) ;

	if(_GetConfigValue("InternetGatewayDevice.ManagementServer.URL" , value))
	{
		sprintf(value,"http://127.0.0.1:30005") ;
		PRINTF("URL Init Error : Not found , Default : [%s]\n",value) ;
	}
	sprintf(Cwmpconfig.URL,"%s",value) ;

	if(_GetConfigValue("InternetGatewayDevice.ManagementServer.Username" , value))
	{
		sprintf(value,"root") ;
		PRINTF("Username Init Error : Not found , Default : [%s]\n",value) ;
	}
	sprintf(Cwmpconfig.Username,"%s",value) ;

	if(_GetConfigValue("InternetGatewayDevice.ManagementServer.Password" , value))
	{
		sprintf(value,"admin") ;
		PRINTF("Password Init Error : Not found , Default : [%s]\n",value) ;
	}
	sprintf(Cwmpconfig.Password,"%s",value) ;

	if(_GetConfigValue("InternetGatewayDevice.ManagementServer.PeriodicInformEnable" , value))
	{
		sprintf(value,"0") ;
		PRINTF("PeriodicInformEnable Init Error : Not found , Default : [%s]\n",value) ;
	}
	Cwmpconfig.PeriodicInformEnable = atoi(value) ;

	if(_GetConfigValue("InternetGatewayDevice.ManagementServer.PeriodicInformInterval" , value))
	{
		sprintf(value,"42300") ;
		PRINTF("PeriodicInformInterval Init Error : Not found , Default : [%s]\n",value) ;
	}
	Cwmpconfig.PeriodicInformInterval = atoi(value) ;

	if(_GetConfigValue("InternetGatewayDevice.ManagementServer.PeriodicInformTime" , value))
	{
		sprintf(value,"") ;
		PRINTF("PeriodicInformTime Init Error : Not found , Default : [%s]\n",value) ;
	}
	sprintf(Cwmpconfig.PeriodicInformTime,"%s",value) ;

	if(_GetConfigValue("InternetGatewayDevice.ManagementServer.RandomPeriodicInformEnable" , value))
	{
		sprintf(value,"0") ;
		PRINTF("RandomPeriodicInformEnable Init Error : Not found , Default : [%s]\n",value) ;
	}
	Cwmpconfig.RandomPeriodicInformEnable = atoi(value) ;

	if(_GetConfigValue("InternetGatewayDevice.ManagementServer.ParameterKey" , value))
	{
		sprintf(value,"") ;
		PRINTF("ParameterKey Init Error : Not found , Default : [%s]\n",value) ;
	}
	sprintf(Cwmpconfig.ParameterKey,"%s",value) ;
	
	if(_GetConfigValue("InternetGatewayDevice.ManagementServer.ConnectionRequestPort" , value))
	{
		sprintf(value,"30000") ;
		PRINTF("ConnectionRequestPort Init Error : Not found , Default : [%s]\n",value) ;
	}
	Cwmpconfig.ConnectionRequestPort = atoi(value) ;

	if(_GetConfigValue("InternetGatewayDevice.ManagementServer.ConnectionRequestURL" , value))
	{
		sprintf(value,"http://127.0.0.1:30000") ;
		PRINTF("ConnectionRequestURL Init Error : Not found , Default : [%s]\n",value) ;
	}
	sprintf(Cwmpconfig.ConnectionRequestURL,"%s",value) ;

	if(_GetConfigValue("InternetGatewayDevice.ManagementServer.ConnectionRequestUsername" , value))
	{
		sprintf(value,"root") ;
		PRINTF("ConnectionRequestUsername Init Error : Not found , Default : [%s]\n",value) ;
	}
	sprintf(Cwmpconfig.ConnectionRequestUsername,"%s",value) ;

	if(_GetConfigValue("InternetGatewayDevice.ManagementServer.ConnectionRequestPassword" , value))
	{
		sprintf(value,"admin") ;
		PRINTF("ConnectionRequestPassword Init Error : Not found , Default : [%s]\n",value) ;
	}
	sprintf(Cwmpconfig.ConnectionRequestPassword,"%s",value) ;

	if(_GetConfigValue("InternetGatewayDevice.ManagementServer.ACSContacted" , value))
	{
		sprintf(value,"0") ;
		PRINTF("ACSContacted Init Error : Not found , Default : [%s]\n",value) ;
	}
	Cwmpconfig.ACSContacted = atoi(value) ;

	if(_GetConfigValue("InternetGatewayDevice.ManagementServer.SSLEnable" , value))
	{
		sprintf(value,"0") ;
		PRINTF("SSLEnable Init Error : Not found , Default : [%s]\n",value) ;
	}
	Cwmpconfig.SSLEnable = atoi(value) ;

	if(_GetConfigValue("InternetGatewayDevice.ManagementServer.InitDatamodel" , value))
	{
		sprintf(value,"0") ;
		PRINTF("InitDatamodel Init Error : Not found , Default : [%s]\n",value) ;
	}
	Cwmpconfig.InitDatamodel = atoi(value) ;

	if(_GetConfigValue("InternetGatewayDevice.ManagementServer.ItmsRemoteRebootCommandKey" , value))
	{
		sprintf(value,"0") ;
		PRINTF("ItmsRemoteRebootCommandKey Init Error : Not found , Default : [%s]\n",value) ;
	}
	Cwmpconfig.ItmsRemoteRebootCommandKey = atoi(value) ;

	if(_GetConfigValue("InternetGatewayDevice.ManagementServer.ItmsRemoteReboot" , value))
	{
		sprintf(value,"0") ;
		PRINTF("ItmsRemoteReboot Init Error : Not found , Default : [%s]\n",value) ;
	}
	Cwmpconfig.ItmsRemoteReboot = atoi(value) ;

	if(_GetConfigValue("InternetGatewayDevice.ManagementServer.AuthType" , value))
	{
		sprintf(value,"2") ;
		PRINTF("AuthType Init Error : Not found , Default : [%s]\n",value) ;
	}
	Cwmpconfig.AuthType = atoi(value) ;

	if(_GetConfigValue("InternetGatewayDevice.ManagementServer.InitTreeValue" , value))
	{
		sprintf(value,"1") ;
		PRINTF("InitTreeValue Init Error : Not found , Default : [%s]\n",value) ;
	}
	Cwmpconfig.InitTreeValue = atoi(value) ;

	if(_GetConfigValue("InternetGatewayDevice.ManagementServer.Realm" , value))
	{
		sprintf(value,"test") ;
		PRINTF("Realm Init Error : Not found , Default : [%s]\n",value) ;
	}
	sprintf(Cwmpconfig.Realm,"%s",value) ;

	if(_GetConfigValue("InternetGatewayDevice.ManagementServer.CACERT_PEM" , value))
	{
		sprintf(value,"./ssl/CA/cacert.pem") ;
		PRINTF("CACERT_PEM Init Error : Not found , Default : [%s]\n",value) ;
	}
	sprintf(Cwmpconfig.CACERT_PEM,"%s",value) ;

	if(_GetConfigValue("InternetGatewayDevice.ManagementServer.SERVER_PEM" , value))
	{
		sprintf(value,"./ssl/CA/server.pem") ;
		PRINTF("SERVER_PEM Init Error : Not found , Default : [%s]\n",value) ;
	}
	sprintf(Cwmpconfig.SERVER_PEM,"%s",value) ;

	if(_GetConfigValue("InternetGatewayDevice.ManagementServer.SERVER_PEM_Password" , value))
	{
		sprintf(value,"kidiger") ;
		PRINTF("SERVER_PEM_Password Init Error : Not found , Default : [%s]\n",value) ;
	}
	sprintf(Cwmpconfig.SERVER_PEM_Password,"%s",value) ;
	
	if(_GetConfigValue("InternetGatewayDevice.ManagementServer.DH_PEM" , value))
	{
		sprintf(value,"./ssl/CA/dh512.pem") ;
		PRINTF("DH_PEM Init Error : Not found , Default : [%s]\n",value) ;
	}
	sprintf(Cwmpconfig.DH_PEM,"%s",value) ;

	if(_GetConfigValue("InternetGatewayDevice.ManagementServer.CLIENT_PEM" , value))
	{
		sprintf(value,"./ssl/CA/client.pem") ;
		PRINTF("SERVER_PEM Init Error : Not found , Default : [%s]\n",value) ;
	}
	sprintf(Cwmpconfig.CLIENT_PEM,"%s",value) ;

	if(_GetConfigValue("InternetGatewayDevice.ManagementServer.CLIENT_PEM_Password" , value))
	{
		sprintf(value,"kidiger") ;
		PRINTF("SERVER_PEM_Password Init Error : Not found , Default : [%s]\n",value) ;
	}
	sprintf(Cwmpconfig.CLIENT_PEM_Password,"%s",value) ;
	
    ServerMode = 0 ; //this parameter use for web display .

	free(value) ;

	return ;
}

void CwmpClient_Init_Soap(struct soap * soap)
{
	if(Cwmpconfig.SSLEnable)
	{
#if defined(WITH_OPENSSL)
		soap_ssl_init();
#endif
	}

  	if (CRYPTO_thread_setup())
  	{ 
		fprintf(stderr, "Cannot setup thread mutex for OpenSSL\n");
    	exit(1);
  	}

    soap_init(soap);
    soap_set_namespaces(soap, namespaces);
#if defined (HTTP_GET)
    soap_register_plugin(soap, http_get);
#endif

	if(Cwmpconfig.SSLEnable)
	{
#if defined (WITH_OPENSSL)
		if(Cwmpconfig.AuthType == 2)
		{
#if defined (DIGEST_AUTH)
			soap_register_plugin(soap, http_da);
#endif
		}
#if 1
		if (soap_ssl_client_context(soap,
			/* SOAP_SSL_NO_AUTHENTICATION, */ /* for encryption w/o authentication */
			/* SOAP_SSL_DEFAULT | SOAP_SSL_SKIP_HOST_CHECK, */	/* if we don't want the host name checks since these will change from machine to machine */
			SOAP_SSL_DEFAULT | SOAP_SSL_SKIP_HOST_CHECK | SOAP_SSL_REQUIRE_SERVER_AUTHENTICATION ,	/* use SOAP_SSL_DEFAULT in production code */
			Cwmpconfig.CLIENT_PEM, 		/* keyfile (cert+key): required only when client must authenticate to server (see SSL docs to create this file) */
			Cwmpconfig.CLIENT_PEM_Password, 		/* password to read the keyfile */
			Cwmpconfig.CACERT_PEM,	/* optional cacert file to store trusted certificates, use cacerts.pem for all public certificates issued by common CAs */
			NULL,		/* optional capath to directory with trusted certificates */
			NULL		/* if randfile!=NULL: use a file with random data to seed randomness */ 
	  	))
	  	{
			soap_print_fault(soap, stderr);
			exit(1);
	  	}
#endif
#endif
	}

    soap_omode(soap,SOAP_IO_KEEPALIVE|SOAP_XML_INDENT|SOAP_XML_IGNORENS);
    soap_imode(soap,SOAP_IO_KEEPALIVE|SOAP_XML_INDENT|SOAP_XML_IGNORENS);

    soap->recv_timeout = 11;
    soap->send_timeout = 0;
    soap->accept_timeout = 0;
    soap->connect_timeout = 0;
    soap->state = 1;
    soap->bind_flags = SO_REUSEADDR ;
    return ;
}

int IsACSConnected()
{
	return ConnectedStatus ;
}

void ACSConnected()
{
	ConnectedStatus = 1 ;
}

int CwmpEventNumGet()
{
    return cwmp_EventNum ;
}

int CwmpInformParamNumGet()
{
    return (cwmp_NameListNum + CwmpGetInformParamNum()) ;
}

int CwmpEventCodeGet(int index , char * EventCode , char * CommandKey)
{
	memset(EventCode,0x0,PARAM_MAX_LENGTH) ;
	memset(CommandKey,0x0,PARAM_MAX_LENGTH) ;
    if(index < cwmp_EventNum)
    {
        sprintf(EventCode,"%s",cwmp_EventCode[index]) ;
        sprintf(CommandKey,"1") ;
	}
	return 0 ;
}

int CwmpInformParamInfoGet(int index , char * Name , char * Value)
{
	memset(Name,0x0,PARAM_MAX_LENGTH) ;
	memset(Value,0x0,PARAM_MAX_LENGTH) ;
    if(index <= CwmpGetInformParamNum())
        sprintf(Name,"%s",informParameters[index-1]) ;
    else
        sprintf(Name,"%s",cwmp_NameList[index-CwmpGetInformParamNum()-1]) ;
    return _GetConfigValue(Name , Value) ;
}

    
int CwmpClient_SendInform(struct soap * soap)
{
    int DeviceSize = 4 ;
    int EventSize = 0 ;
    char ** DeviceEventInfo ;

    int MaxEnvelopes = 1 ;
    int RetryCount = 1 ;
    char * CurrentTime ;

    int ParameterSize = 0 ;
    char ** ParameterNameList ;
    char ** ParameterValueList ;

    int * OtherOption ;
    int i = 0 ;

	char *pName = (char *) soap_malloc(soap,PARAM_MAX_LENGTH) ;
	char *pValue = (char *) soap_malloc(soap,PARAM_MAX_LENGTH) ;
    OtherOption = (int *)CwmpClient_Malloc(soap,4*sizeof(int));

	EventSize = CwmpEventNumGet() ;
	ParameterSize = CwmpInformParamNumGet() ;

    OtherOption[0] = EventSize ;
    OtherOption[1] = MaxEnvelopes ;
    OtherOption[2] = RetryCount ;
    OtherOption[3] = ParameterSize ;

    DeviceEventInfo = (char **)CwmpClient_Malloc(soap,(DeviceSize+EventSize*2)*sizeof(char *)) ;
	if(_GetConfigValue("InternetGatewayDevice.DeviceInfo.Manufacturer",pValue) == 0)
    	DeviceEventInfo[0] = (char *)CwmpClient_Strdup(soap,pValue) ; //Manufacturer
	if(_GetConfigValue("InternetGatewayDevice.DeviceInfo.ManufacturerOUI",pValue) == 0)
    	DeviceEventInfo[1] = (char *)CwmpClient_Strdup(soap,pValue) ; //OUI
	if(_GetConfigValue("InternetGatewayDevice.DeviceInfo.ProductClass",pValue) == 0)
    	DeviceEventInfo[2] = (char *)CwmpClient_Strdup(soap,pValue) ; //ProductClass
	if(_GetConfigValue("InternetGatewayDevice.DeviceInfo.SerialNumber",pValue) == 0)
    	DeviceEventInfo[3] = (char *)CwmpClient_Strdup(soap,pValue) ; //SerialNumber
	for(i = 0 ; i < EventSize ; i ++)
	{
		if(CwmpEventCodeGet(i,pName,pValue) == 0)
		{
			DeviceEventInfo[4+i*2] = (char *)CwmpClient_Strdup(soap,pName) ; //EventCode
			DeviceEventInfo[4+i*2+1] = (char *)CwmpClient_Strdup(soap,pValue) ; //CommandKey
		}
	}

	CurrentTime = (char *)CwmpClient_Strdup(soap,getTimeString()) ;
	CurrentTime[strlen(CurrentTime)-1] = '\0' ;
	PRINTF("TIME:%s\n",CurrentTime) ;
    ParameterNameList = (char **)CwmpClient_Malloc(soap,ParameterSize*sizeof(char *)) ;
    ParameterValueList = (char **)CwmpClient_Malloc(soap,ParameterSize*sizeof(char *)) ;
	for(i = 1 ; i <= ParameterSize ; i ++)
	{
		if(CwmpInformParamInfoGet(i,pName,pValue) == 0)
		{
			ParameterNameList[i-1] = (char *)CwmpClient_Strdup(soap,pName) ;
			ParameterValueList[i-1] = (char *)CwmpClient_Strdup(soap,pValue) ;
		}
	}
    return CwmpClient_Inform_Adapter(soap,DeviceEventInfo , CurrentTime , ParameterNameList , ParameterValueList , OtherOption);
}

void ClientSendInform()
{
    int ret = 0 ;
    struct soap soap ;

	CwmpClient_Init_Soap(&soap) ;
    
    ret = CwmpClient_SendInform(&soap) ;
#ifdef WHOLE_COMPILE
#ifdef WITH_WEBSERVER
    WebBufferTag = 0 ;
    memset(WebBuffer,0x0,sizeof(WebBuffer)) ;
#endif
#endif
    if (ret != SOAP_OK) {
#ifdef WHOLE_COMPILE
#ifdef WITH_WEBSERVER
        sprintf(WebBuffer,"Send Inform Failed soap error, errcode=[%d]<br>",ret) ;
#endif
#endif
        printf("Send Inform Failed soap error, errcode=[%d]\n", ret);
    } else {
#ifdef WHOLE_COMPILE
#ifdef WITH_WEBSERVER
        sprintf(WebBuffer,"Send Inform OK.") ;
#endif
#endif
        printf("Send Inform OK.\n");
		ACSConnected() ;
    }
#ifdef WHOLE_COMPILE
#ifdef WITH_WEBSERVER
    WebBufferTag = 1 ;
#endif
#endif
    soap_end(&soap);
    soap_done(&soap);
#ifdef WITH_OPENSSL
	CRYPTO_thread_cleanup();
#endif
    return ;
}


#ifndef WHOLE_COMPILE

#ifdef CWMP_TEST
void CwmpClient_Distory_Adapter(struct soap * soap)
{
    soap_end(soap);
    soap_done(soap);
	CRYPTO_thread_cleanup();
}


void CwmpClient_Init_Adapter()
{
	int ret = 0 ;
    struct soap soap ;

	CwmpClient_Init_Soap(&soap) ;
    printf("\nStart Cwmp Client test Mode\n") ;

	ret = CwmpClient_RPC_Test_Adapter(&soap) ;

    if (ret != SOAP_OK) {
        printf("Send Inform Failed soap error, errcode=[%d]\n", ret);
    } else {
        printf("Send Inform OK.\n");
    }
    CwmpClient_Distory_Adapter(&soap) ;

    return ;
}
#endif


int main(int argc, char **argv)
{
    PRINTF("Start CwmpServerClient Function\n");
	char RootDir[256] ;
	char ConfigFile[256] ;
	char ConfigXML[256] ;
    SOAP_SOCKET ret ;
    if (argc < 2) {
        printf("usage: %s <config_root>\n", argv[0]);
        exit(1);
    }
	memset(RootDir,0x0,sizeof(RootDir)) ;
	memset(ConfigFile,0x0,sizeof(ConfigFile)) ;
	memset(ConfigXML,0x0,sizeof(ConfigXML)) ;
	strcpy(RootDir,argv[1]) ;
	sprintf(ConfigFile,"%s/DUTConfig.xml",RootDir) ;
	sprintf(ConfigXML,"%s/ConfigXml",RootDir) ;
	sprintf(xmlProPath,"%s",ConfigXML) ;
	if(LoadXML(ConfigFile))
	{
		PRINTF("Load XML failed \n");
		exit(0);
	}
    CwmpConfig_Init() ;	//Cwmp Client data init .
#ifndef CWMP_TEST
    ClientSendInform() ;	//Cwmp function Init . include Inform send out .
#else
	CwmpClient_Init_Adapter() ;	//Cwmp function Init . include Inform send out .
#endif
    return 0;
}

#ifdef WITH_OPENSSL

#if defined(WIN32)
# define MUTEX_TYPE		HANDLE
# define MUTEX_SETUP(x)		(x) = CreateMutex(NULL, FALSE, NULL)
# define MUTEX_CLEANUP(x)	CloseHandle(x)
# define MUTEX_LOCK(x)		WaitForSingleObject((x), INFINITE)
# define MUTEX_UNLOCK(x)	ReleaseMutex(x)
# define THREAD_ID		GetCurrentThreadId()
#elif defined(_POSIX_THREADS) || defined(_SC_THREADS)
# define MUTEX_TYPE		pthread_mutex_t
# define MUTEX_SETUP(x)		pthread_mutex_init(&(x), NULL)
# define MUTEX_CLEANUP(x)	pthread_mutex_destroy(&(x))
# define MUTEX_LOCK(x)		pthread_mutex_lock(&(x))
# define MUTEX_UNLOCK(x)	pthread_mutex_unlock(&(x))
# define THREAD_ID		pthread_self()
#else
# error "You must define mutex operations appropriate for your platform"
# error	"See OpenSSL /threads/th-lock.c on how to implement mutex on your platform"
#endif

struct CRYPTO_dynlock_value
{ MUTEX_TYPE mutex;
};

static MUTEX_TYPE *mutex_buf;

static struct CRYPTO_dynlock_value *dyn_create_function(const char *file, int line)
{ struct CRYPTO_dynlock_value *value;
  value = (struct CRYPTO_dynlock_value*)malloc(sizeof(struct CRYPTO_dynlock_value));
  if (value)
    MUTEX_SETUP(value->mutex);
  return value;
}

static void dyn_lock_function(int mode, struct CRYPTO_dynlock_value *l, const char *file, int line)
{ if (mode & CRYPTO_LOCK)
    MUTEX_LOCK(l->mutex);
  else
    MUTEX_UNLOCK(l->mutex);
}

static void dyn_destroy_function(struct CRYPTO_dynlock_value *l, const char *file, int line)
{ MUTEX_CLEANUP(l->mutex);
  free(l);
}

void locking_function(int mode, int n, const char *file, int line)
{ if (mode & CRYPTO_LOCK)
    MUTEX_LOCK(mutex_buf[n]);
  else
    MUTEX_UNLOCK(mutex_buf[n]);
}

unsigned long id_function()
{ return (unsigned long)THREAD_ID;
}

int CRYPTO_thread_setup()
{ int i;
  mutex_buf = (MUTEX_TYPE*)malloc(CRYPTO_num_locks() * sizeof(pthread_mutex_t));
  if (!mutex_buf)
    return SOAP_EOM;
  for (i = 0; i < CRYPTO_num_locks(); i++)
    MUTEX_SETUP(mutex_buf[i]);
  CRYPTO_set_id_callback(id_function);
  CRYPTO_set_locking_callback(locking_function);
  CRYPTO_set_dynlock_create_callback(dyn_create_function);
  CRYPTO_set_dynlock_lock_callback(dyn_lock_function);
  CRYPTO_set_dynlock_destroy_callback(dyn_destroy_function);
  return SOAP_OK;
}

void CRYPTO_thread_cleanup()
{ int i;
  if (!mutex_buf)
    return;
  CRYPTO_set_id_callback(NULL);
  CRYPTO_set_locking_callback(NULL);
  CRYPTO_set_dynlock_create_callback(NULL);
  CRYPTO_set_dynlock_lock_callback(NULL);
  CRYPTO_set_dynlock_destroy_callback(NULL);
  for (i = 0; i < CRYPTO_num_locks(); i++)
    MUTEX_CLEANUP(mutex_buf[i]);
  free(mutex_buf);
  mutex_buf = NULL;
}

#else

/* OpenSSL not used, e.g. GNUTLS is used */

int CRYPTO_thread_setup()
{ 
	return SOAP_OK;
}

void CRYPTO_thread_cleanup()
{ }

#endif

#if defined(_POSIX_SIGNAL)
void sigpipe_handle(int x) { }
#endif
#endif

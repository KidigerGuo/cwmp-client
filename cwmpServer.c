#include "cwmpDebug.h"
#include "stdsoap2.h"
#include "soapH.h"

#ifndef WHOLE_COMPILE
#ifdef WITH_WEBSERVER
char WebBuffer[PARAM_MAX_LENGTH*PARAM_MAX_LENGTH] ;	// Web String display
unsigned char WebBufferTag ;	// String data exist 
#endif
#endif

#ifdef SUPPORT_EMPTYPOST
#ifdef SUPPORT_EMPTYPOST_REQ

SOAP_FMAC5 int SOAP_FMAC6 __soap_call___cwmp__Inform(struct soap *soap, const char *soap_action, struct _cwmp__Inform *cwmp__Inform, struct _cwmp__InformResponse *cwmp__InformResponse)
{	
	int status = 200 ;
	struct __cwmp__Inform soap_tmp___cwmp__Inform;
	if (soap_action == NULL)
		soap_action = "";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp___cwmp__Inform.cwmp__Inform = cwmp__Inform;
	soap_serializeheader(soap);
	soap_serialize___cwmp__Inform(soap, &soap_tmp___cwmp__Inform);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___cwmp__Inform(soap, &soap_tmp___cwmp__Inform, "-cwmp:Inform", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_response(soap, status)//soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___cwmp__Inform(soap, &soap_tmp___cwmp__Inform, "-cwmp:Inform", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!cwmp__InformResponse)
		return soap_closesock(soap);
	soap_default__cwmp__InformResponse(soap, cwmp__InformResponse);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get__cwmp__InformResponse(soap, cwmp__InformResponse, "cwmp:InformResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __soap_call___cwmp__GetRPCMethods(struct soap *soap, const char *soap_action, struct _cwmp__GetRPCMethods *cwmp__GetRPCMethods, struct _cwmp__GetRPCMethodsResponse *cwmp__GetRPCMethodsResponse)
{	
	int status = 200 ;
	struct __cwmp__GetRPCMethods soap_tmp___cwmp__GetRPCMethods;
	if (soap_action == NULL)
		soap_action = "";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp___cwmp__GetRPCMethods.cwmp__GetRPCMethods = cwmp__GetRPCMethods;
	soap_serializeheader(soap);
	soap_serialize___cwmp__GetRPCMethods(soap, &soap_tmp___cwmp__GetRPCMethods);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___cwmp__GetRPCMethods(soap, &soap_tmp___cwmp__GetRPCMethods, "-cwmp:GetRPCMethods", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_response(soap, status)//soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___cwmp__GetRPCMethods(soap, &soap_tmp___cwmp__GetRPCMethods, "-cwmp:GetRPCMethods", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!cwmp__GetRPCMethodsResponse)
		return soap_closesock(soap);
	soap_default__cwmp__GetRPCMethodsResponse(soap, cwmp__GetRPCMethodsResponse);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get__cwmp__GetRPCMethodsResponse(soap, cwmp__GetRPCMethodsResponse, "cwmp:GetRPCMethodsResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __soap_call___cwmp__GetParameterValues(struct soap *soap, const char *soap_action, struct _cwmp__GetParameterValues *cwmp__GetParameterValues, struct _cwmp__GetParameterValuesResponse *cwmp__GetParameterValuesResponse)
{
	int status = 200 ;	
	struct __cwmp__GetParameterValues soap_tmp___cwmp__GetParameterValues;
	if (soap_action == NULL)
		soap_action = "";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp___cwmp__GetParameterValues.cwmp__GetParameterValues = cwmp__GetParameterValues;
	soap_serializeheader(soap);
	soap_serialize___cwmp__GetParameterValues(soap, &soap_tmp___cwmp__GetParameterValues);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___cwmp__GetParameterValues(soap, &soap_tmp___cwmp__GetParameterValues, "-cwmp:GetParameterValues", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_response(soap, status)//soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___cwmp__GetParameterValues(soap, &soap_tmp___cwmp__GetParameterValues, "-cwmp:GetParameterValues", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!cwmp__GetParameterValuesResponse)
		return soap_closesock(soap);
	soap_default__cwmp__GetParameterValuesResponse(soap, cwmp__GetParameterValuesResponse);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get__cwmp__GetParameterValuesResponse(soap, cwmp__GetParameterValuesResponse, "cwmp:GetParameterValuesResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __soap_call___cwmp__SetParameterValues(struct soap *soap, const char *soap_action, struct _cwmp__SetParameterValues *cwmp__SetParameterValues, struct _cwmp__SetParameterValuesResponse *cwmp__SetParameterValuesResponse)
{
	int status = 200 ;	
	struct __cwmp__SetParameterValues soap_tmp___cwmp__SetParameterValues;
	if (soap_action == NULL)
		soap_action = "";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp___cwmp__SetParameterValues.cwmp__SetParameterValues = cwmp__SetParameterValues;
	soap_serializeheader(soap);
	soap_serialize___cwmp__SetParameterValues(soap, &soap_tmp___cwmp__SetParameterValues);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___cwmp__SetParameterValues(soap, &soap_tmp___cwmp__SetParameterValues, "-cwmp:SetParameterValues", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_response(soap, status)//soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___cwmp__SetParameterValues(soap, &soap_tmp___cwmp__SetParameterValues, "-cwmp:SetParameterValues", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!cwmp__SetParameterValuesResponse)
		return soap_closesock(soap);
	soap_default__cwmp__SetParameterValuesResponse(soap, cwmp__SetParameterValuesResponse);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get__cwmp__SetParameterValuesResponse(soap, cwmp__SetParameterValuesResponse, "cwmp:SetParameterValuesResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __soap_call___cwmp__GetParameterNames(struct soap *soap, const char *soap_action, struct _cwmp__GetParameterNames *cwmp__GetParameterNames, struct _cwmp__GetParameterNamesResponse *cwmp__GetParameterNamesResponse)
{
	int status = 200 ;	
	struct __cwmp__GetParameterNames soap_tmp___cwmp__GetParameterNames;
	if (soap_action == NULL)
		soap_action = "";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp___cwmp__GetParameterNames.cwmp__GetParameterNames = cwmp__GetParameterNames;
	soap_serializeheader(soap);
	soap_serialize___cwmp__GetParameterNames(soap, &soap_tmp___cwmp__GetParameterNames);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___cwmp__GetParameterNames(soap, &soap_tmp___cwmp__GetParameterNames, "-cwmp:GetParameterNames", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_response(soap, status)//soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___cwmp__GetParameterNames(soap, &soap_tmp___cwmp__GetParameterNames, "-cwmp:GetParameterNames", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!cwmp__GetParameterNamesResponse)
		return soap_closesock(soap);
	soap_default__cwmp__GetParameterNamesResponse(soap, cwmp__GetParameterNamesResponse);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get__cwmp__GetParameterNamesResponse(soap, cwmp__GetParameterNamesResponse, "cwmp:GetParameterNamesResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __soap_call___cwmp__SetParameterAttributes(struct soap *soap, const char *soap_action, struct _cwmp__SetParameterAttributes *cwmp__SetParameterAttributes, struct _cwmp__SetParameterAttributesResponse *cwmp__SetParameterAttributesResponse)
{
	int status = 200 ;	
	struct __cwmp__SetParameterAttributes soap_tmp___cwmp__SetParameterAttributes;
	if (soap_action == NULL)
		soap_action = "";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp___cwmp__SetParameterAttributes.cwmp__SetParameterAttributes = cwmp__SetParameterAttributes;
	soap_serializeheader(soap);
	soap_serialize___cwmp__SetParameterAttributes(soap, &soap_tmp___cwmp__SetParameterAttributes);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___cwmp__SetParameterAttributes(soap, &soap_tmp___cwmp__SetParameterAttributes, "-cwmp:SetParameterAttributes", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_response(soap, status)//soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___cwmp__SetParameterAttributes(soap, &soap_tmp___cwmp__SetParameterAttributes, "-cwmp:SetParameterAttributes", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!cwmp__SetParameterAttributesResponse)
		return soap_closesock(soap);
	soap_default__cwmp__SetParameterAttributesResponse(soap, cwmp__SetParameterAttributesResponse);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get__cwmp__SetParameterAttributesResponse(soap, cwmp__SetParameterAttributesResponse, "cwmp:SetParameterAttributesResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __soap_call___cwmp__GetParameterAttributes(struct soap *soap, const char *soap_action, struct _cwmp__GetParameterAttributes *cwmp__GetParameterAttributes, struct _cwmp__GetParameterAttributesResponse *cwmp__GetParameterAttributesResponse)
{
	int status = 200 ;	
	struct __cwmp__GetParameterAttributes soap_tmp___cwmp__GetParameterAttributes;
	if (soap_action == NULL)
		soap_action = "";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp___cwmp__GetParameterAttributes.cwmp__GetParameterAttributes = cwmp__GetParameterAttributes;
	soap_serializeheader(soap);
	soap_serialize___cwmp__GetParameterAttributes(soap, &soap_tmp___cwmp__GetParameterAttributes);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___cwmp__GetParameterAttributes(soap, &soap_tmp___cwmp__GetParameterAttributes, "-cwmp:GetParameterAttributes", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_response(soap, status)//soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___cwmp__GetParameterAttributes(soap, &soap_tmp___cwmp__GetParameterAttributes, "-cwmp:GetParameterAttributes", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!cwmp__GetParameterAttributesResponse)
		return soap_closesock(soap);
	soap_default__cwmp__GetParameterAttributesResponse(soap, cwmp__GetParameterAttributesResponse);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get__cwmp__GetParameterAttributesResponse(soap, cwmp__GetParameterAttributesResponse, "cwmp:GetParameterAttributesResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __soap_call___cwmp__AddObject(struct soap *soap, const char *soap_action, struct _cwmp__AddObject *cwmp__AddObject, struct _cwmp__AddObjectResponse *cwmp__AddObjectResponse)
{	
	int status = 200 ;
	struct __cwmp__AddObject soap_tmp___cwmp__AddObject;
	if (soap_action == NULL)
		soap_action = "";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp___cwmp__AddObject.cwmp__AddObject = cwmp__AddObject;
	soap_serializeheader(soap);
	soap_serialize___cwmp__AddObject(soap, &soap_tmp___cwmp__AddObject);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___cwmp__AddObject(soap, &soap_tmp___cwmp__AddObject, "-cwmp:AddObject", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_response(soap, status)//soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___cwmp__AddObject(soap, &soap_tmp___cwmp__AddObject, "-cwmp:AddObject", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!cwmp__AddObjectResponse)
		return soap_closesock(soap);
	soap_default__cwmp__AddObjectResponse(soap, cwmp__AddObjectResponse);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get__cwmp__AddObjectResponse(soap, cwmp__AddObjectResponse, "cwmp:AddObjectResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __soap_call___cwmp__DeleteObject(struct soap *soap, const char *soap_action, struct _cwmp__DeleteObject *cwmp__DeleteObject, struct _cwmp__DeleteObjectResponse *cwmp__DeleteObjectResponse)
{
	int status = 200 ;	
	struct __cwmp__DeleteObject soap_tmp___cwmp__DeleteObject;
	if (soap_action == NULL)
		soap_action = "";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp___cwmp__DeleteObject.cwmp__DeleteObject = cwmp__DeleteObject;
	soap_serializeheader(soap);
	soap_serialize___cwmp__DeleteObject(soap, &soap_tmp___cwmp__DeleteObject);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___cwmp__DeleteObject(soap, &soap_tmp___cwmp__DeleteObject, "-cwmp:DeleteObject", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_response(soap, status)//soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___cwmp__DeleteObject(soap, &soap_tmp___cwmp__DeleteObject, "-cwmp:DeleteObject", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!cwmp__DeleteObjectResponse)
		return soap_closesock(soap);
	soap_default__cwmp__DeleteObjectResponse(soap, cwmp__DeleteObjectResponse);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get__cwmp__DeleteObjectResponse(soap, cwmp__DeleteObjectResponse, "cwmp:DeleteObjectResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __soap_call___cwmp__Reboot(struct soap *soap, const char *soap_action, struct _cwmp__Reboot *cwmp__Reboot, struct _cwmp__RebootResponse *cwmp__RebootResponse)
{	
	int status = 200 ;
	struct __cwmp__Reboot soap_tmp___cwmp__Reboot;
	if (soap_action == NULL)
		soap_action = "";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp___cwmp__Reboot.cwmp__Reboot = cwmp__Reboot;
	soap_serializeheader(soap);
	soap_serialize___cwmp__Reboot(soap, &soap_tmp___cwmp__Reboot);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___cwmp__Reboot(soap, &soap_tmp___cwmp__Reboot, "-cwmp:Reboot", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_response(soap, status)//soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___cwmp__Reboot(soap, &soap_tmp___cwmp__Reboot, "-cwmp:Reboot", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!cwmp__RebootResponse)
		return soap_closesock(soap);
	soap_default__cwmp__RebootResponse(soap, cwmp__RebootResponse);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get__cwmp__RebootResponse(soap, cwmp__RebootResponse, "cwmp:RebootResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __soap_call___cwmp__Download(struct soap *soap, const char *soap_action, struct _cwmp__Download *cwmp__Download, struct _cwmp__DownloadResponse *cwmp__DownloadResponse)
{	
	int status = 200 ;
	struct __cwmp__Download soap_tmp___cwmp__Download;
	if (soap_action == NULL)
		soap_action = "";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp___cwmp__Download.cwmp__Download = cwmp__Download;
	soap_serializeheader(soap);
	soap_serialize___cwmp__Download(soap, &soap_tmp___cwmp__Download);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___cwmp__Download(soap, &soap_tmp___cwmp__Download, "-cwmp:Download", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_response(soap, status)//soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___cwmp__Download(soap, &soap_tmp___cwmp__Download, "-cwmp:Download", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!cwmp__DownloadResponse)
		return soap_closesock(soap);
	soap_default__cwmp__DownloadResponse(soap, cwmp__DownloadResponse);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get__cwmp__DownloadResponse(soap, cwmp__DownloadResponse, "cwmp:DownloadResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __soap_call___cwmp__Upload(struct soap *soap, const char *soap_action, struct _cwmp__Upload *cwmp__Upload, struct _cwmp__UploadResponse *cwmp__UploadResponse)
{
	int status = 200 ;	
	struct __cwmp__Upload soap_tmp___cwmp__Upload;
	if (soap_action == NULL)
		soap_action = "";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp___cwmp__Upload.cwmp__Upload = cwmp__Upload;
	soap_serializeheader(soap);
	soap_serialize___cwmp__Upload(soap, &soap_tmp___cwmp__Upload);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___cwmp__Upload(soap, &soap_tmp___cwmp__Upload, "-cwmp:Upload", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_response(soap, status)//soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___cwmp__Upload(soap, &soap_tmp___cwmp__Upload, "-cwmp:Upload", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!cwmp__UploadResponse)
		return soap_closesock(soap);
	soap_default__cwmp__UploadResponse(soap, cwmp__UploadResponse);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get__cwmp__UploadResponse(soap, cwmp__UploadResponse, "cwmp:UploadResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}


SOAP_FMAC5 int SOAP_FMAC6 __soap_call___cwmp__FactoryReset(struct soap *soap, const char *soap_action, struct _cwmp__FactoryReset *cwmp__FactoryReset, struct _cwmp__FactoryResetResponse *cwmp__FactoryResetResponse)
{
	int status = 200 ;
	struct __cwmp__FactoryReset soap_tmp___cwmp__FactoryReset;
	if (soap_action == NULL)
		soap_action = "";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp___cwmp__FactoryReset.cwmp__FactoryReset = cwmp__FactoryReset;
	soap_serializeheader(soap);
	soap_serialize___cwmp__FactoryReset(soap, &soap_tmp___cwmp__FactoryReset);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___cwmp__FactoryReset(soap, &soap_tmp___cwmp__FactoryReset, "-cwmp:FactoryReset", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_response(soap, status)//soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___cwmp__FactoryReset(soap, &soap_tmp___cwmp__FactoryReset, "-cwmp:FactoryReset", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!cwmp__FactoryResetResponse)
		return soap_closesock(soap);
	soap_default__cwmp__FactoryResetResponse(soap, cwmp__FactoryResetResponse);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get__cwmp__FactoryResetResponse(soap, cwmp__FactoryResetResponse, "cwmp:FactoryResetResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __soap_call___cwmp__ScheduleInform(struct soap *soap, const char *soap_action, struct _cwmp__ScheduleInform *cwmp__ScheduleInform, struct _cwmp__ScheduleInformResponse *cwmp__ScheduleInformResponse)
{
	int status = 200 ;	
	struct __cwmp__ScheduleInform soap_tmp___cwmp__ScheduleInform;
	if (soap_action == NULL)
		soap_action = "";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp___cwmp__ScheduleInform.cwmp__ScheduleInform = cwmp__ScheduleInform;
	soap_serializeheader(soap);
	soap_serialize___cwmp__ScheduleInform(soap, &soap_tmp___cwmp__ScheduleInform);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___cwmp__ScheduleInform(soap, &soap_tmp___cwmp__ScheduleInform, "-cwmp:ScheduleInform", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_response(soap, status)//soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___cwmp__ScheduleInform(soap, &soap_tmp___cwmp__ScheduleInform, "-cwmp:ScheduleInform", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!cwmp__ScheduleInformResponse)
		return soap_closesock(soap);
	soap_default__cwmp__ScheduleInformResponse(soap, cwmp__ScheduleInformResponse);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get__cwmp__ScheduleInformResponse(soap, cwmp__ScheduleInformResponse, "cwmp:ScheduleInformResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __soap_call___cwmp__TranferComplete(struct soap *soap, const char *soap_action, struct _cwmp__TranferComplete *cwmp__TranferComplete, struct _cwmp__TranferCompleteResponse *cwmp__TranferCompleteResponse)
{
	int status = 200 ;	
	struct __cwmp__TranferComplete soap_tmp___cwmp__TranferComplete;
	if (soap_action == NULL)
		soap_action = "";
	soap_begin(soap);
	soap->encodingStyle = NULL;
	soap_tmp___cwmp__TranferComplete.cwmp__TranferComplete = cwmp__TranferComplete;
	soap_serializeheader(soap);
	soap_serialize___cwmp__TranferComplete(soap, &soap_tmp___cwmp__TranferComplete);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put___cwmp__TranferComplete(soap, &soap_tmp___cwmp__TranferComplete, "-cwmp:TranferComplete", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	}
	if (soap_end_count(soap))
		return soap->error;
	if (soap_response(soap, status)//soap_connect(soap, soap_url(soap, soap_endpoint, NULL), soap_action)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put___cwmp__TranferComplete(soap, &soap_tmp___cwmp__TranferComplete, "-cwmp:TranferComplete", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap_closesock(soap);
	if (!cwmp__TranferCompleteResponse)
		return soap_closesock(soap);
	soap_default__cwmp__TranferCompleteResponse(soap, cwmp__TranferCompleteResponse);
	if (soap_begin_recv(soap)
	 || soap_envelope_begin_in(soap)
	 || soap_recv_header(soap)
	 || soap_body_begin_in(soap))
		return soap_closesock(soap);
	soap_get__cwmp__TranferCompleteResponse(soap, cwmp__TranferCompleteResponse, "cwmp:TranferCompleteResponse", "");
	if (soap->error)
		return soap_recv_fault(soap, 0);
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap_closesock(soap);
	return soap_closesock(soap);
}

#ifdef CWMP_TEST
int __cwmp_Inform(struct soap * soap , char ** DeviceEventInfo , char * CurrentTime , char ** ParameterNameList , char ** ParameterValueList , int * OtherOption)
{
    //PRINTF("Entry %s\n",__FUNCTION__);

    int result = 0 ;
    int i = 0 ;
    struct _cwmp__Inform* Inform ;
    struct _cwmp__InformResponse InformResponse;

    Inform =  (struct _cwmp__Inform *) soap_malloc(soap,sizeof(struct _cwmp__Inform));

    Inform->DeviceId = (struct cwmp__DeviceIdStruct *)soap_malloc(soap,sizeof(struct cwmp__DeviceIdStruct)) ;
    Inform->DeviceId->Manufacturer = soap_strdup(soap, DeviceEventInfo[0]); 
    Inform->DeviceId->OUI = soap_strdup(soap, DeviceEventInfo[1]);
    Inform->DeviceId->ProductClass = soap_strdup(soap, DeviceEventInfo[2]);
    Inform->DeviceId->SerialNumber = soap_strdup(soap, DeviceEventInfo[3]);

    Inform->Event = (struct cwmpArrayOfEventStruct *)soap_malloc(soap,sizeof(struct cwmpArrayOfEventStruct)) ;
    Inform->Event->__size = OtherOption[0];
    Inform->Event->__ptrEventStruct = (struct cwmp__EventStruct**) soap_malloc(soap,Inform->Event->__size*sizeof(struct cwmp__EventStruct*));

    for(i = 0 ; i < Inform->Event->__size ; i ++)
    {
        Inform->Event->__ptrEventStruct[i] = (struct cwmp__EventStruct*) soap_malloc(soap,Inform->Event->__size*sizeof(struct cwmp__EventStruct));
        Inform->Event->__ptrEventStruct[i]->EventCode = soap_strdup(soap, DeviceEventInfo[i*2+4]) ;   //Event struct start from DeviceEventInfo[4]
        Inform->Event->__ptrEventStruct[i]->CommandKey = soap_strdup(soap, DeviceEventInfo[i*2+4+1]) ;
    }

    Inform->MaxEnvelopes = OtherOption[1];
    Inform->CurrentTime = soap_strdup(soap, CurrentTime) ; //date +%Y/%M/%d-%T
    Inform->RetryCount = OtherOption[2] ;

    Inform->ParameterList = (struct cwmpArrayOfParameterValueStruct *) soap_malloc(soap,sizeof(struct cwmpArrayOfParameterValueStruct));
    Inform->ParameterList->__size = OtherOption[3];
    Inform->ParameterList->__ptrParameterValueStruct = (struct cwmp__ParameterValueStruct **) soap_malloc(soap,Inform->ParameterList->__size*sizeof(struct cwmp__ParameterValueStruct *));
    for(i = 0 ; i < Inform->ParameterList->__size ; i ++)
    {
        Inform->ParameterList->__ptrParameterValueStruct[i] = (struct cwmp__ParameterValueStruct *) soap_malloc(soap,sizeof(struct cwmp__ParameterValueStruct));
        Inform->ParameterList->__ptrParameterValueStruct[i]->Name = soap_strdup(soap, ParameterNameList[i]) ; 
        Inform->ParameterList->__ptrParameterValueStruct[i]->Value = soap_strdup(soap, ParameterValueList[i]) ; 
    }

    result = __soap_call___cwmp__Inform(soap,"Inform",Inform,&InformResponse);
    PRINTF("############### Client RPC Inform ##############\n") ;
    PRINTF("[Inform Response] : [%d]\n",InformResponse.MaxEnvelopes);
    return result;
}
#endif

int __cwmp_GetRPCMethods(struct soap * soap , char *** RPCSupportList,int * size)
{
    //PRINTF("Entry %s\n",__FUNCTION__);

    int result = 0 ;
    int i = 0 ;
    struct _cwmp__GetRPCMethods* Inform ;
    struct _cwmp__GetRPCMethodsResponse InformResponse;
    char ** RPCList ;

    Inform =  (struct _cwmp__GetRPCMethods *) soap_malloc(soap,sizeof(struct _cwmp__GetRPCMethods));

    __soap_call___cwmp__GetRPCMethods(soap,"GetRPCMethods",Inform,&InformResponse);

    RPCSupportList[0] = (char **)soap_malloc(soap,InformResponse.MethodList->__sizestring*sizeof(char *)) ;
    PRINTF("############### Client RPC GetRPCMethods   ##############\n") ;
    for(i = 0 ; i < InformResponse.MethodList->__sizestring ; i ++)
    {
        RPCSupportList[0][i] = (char *)soap_strdup(soap,InformResponse.MethodList->string[i]) ;
        *size += 1 ;
	    //PRINTF("[%s]\n",InformResponse.MethodList->string[i]) ;
    }

    return result;
}

int __cwmp_GetNamelist(struct soap * soap , char * Path, char *** NameList , int ** Writeable,int * size)
{
    //PRINTF("Entry %s\n",__FUNCTION__);

    int result = 0 ;
    int i = 0 ;
    struct _cwmp__GetParameterNames * Inform ;
    struct _cwmp__GetParameterNamesResponse InformResponse;

    Inform =  (struct _cwmp__GetParameterNames *) soap_malloc(soap,sizeof(struct _cwmp__GetParameterNames));
    Inform->ParameterPath = (char *) soap_strdup(soap,Path);
    Inform->NextLevel = (char *) soap_strdup(soap,"0");

    __soap_call___cwmp__GetParameterNames(soap,"GetNameList",Inform,&InformResponse);
    NameList[0] = (char **)soap_malloc(soap,InformResponse.ParameterList->__size*sizeof(char *)) ;
	Writeable[0] = (int *)soap_malloc(soap,InformResponse.ParameterList->__size*sizeof(int)) ;
    PRINTF("############### Client RPC GetNameList ##############\n") ;
    *size = InformResponse.ParameterList->__size ;
    for(i = 0 ; i < InformResponse.ParameterList->__size ; i ++)
    {
        NameList[0][i] = (char *)soap_strdup(soap,InformResponse.ParameterList->__ptrParameterInfoStruct[i]->Name) ;
        Writeable[0][i] = InformResponse.ParameterList->__ptrParameterInfoStruct[i]->Writable ;
	    //PRINTF("[%s]:",InformResponse.ParameterList->__ptrParameterInfoStruct[i]->Name) ;
	    //PRINTF("[%d]\n",InformResponse.ParameterList->__ptrParameterInfoStruct[i]->Writable) ;
    }
    return result;
}


int __cwmp_GetParameterValue(struct soap * soap , char ** NameList, char *** ValueList, int size) 
{
    //PRINTF("Entry %s\n",__FUNCTION__);
    int result = 0 ;
    int i = 0 ;
    struct _cwmp__GetParameterValues * Inform ;
    struct _cwmp__GetParameterValuesResponse InformResponse;

    Inform =  (struct _cwmp__GetParameterValues *) soap_malloc(soap,sizeof(struct _cwmp__GetParameterValues));
    Inform->ParameterNames = (struct cwmpArrayOfstring*) soap_malloc(soap,sizeof(struct cwmpArrayOfstring));
    Inform->ParameterNames->__size = size ;
    Inform->ParameterNames->__ptrstring = (char **) soap_malloc(soap,(Inform->ParameterNames->__size)*sizeof(char *));

    for(i = 0 ; i < Inform->ParameterNames->__size ; i ++)
		Inform->ParameterNames->__ptrstring[i] = (char *)soap_strdup(soap,NameList[i]) ;

    __soap_call___cwmp__GetParameterValues(soap,"GetParameterValue",Inform,&InformResponse);
	
	ValueList[0] = (char **)soap_malloc(soap,Inform->ParameterNames->__size*sizeof(char *)) ;
	
    for(i = 0 ; i < Inform->ParameterNames->__size ; i ++)
    {	
		ValueList[0][i] = (char *)soap_strdup(soap,InformResponse.ParameterList->__ptrParameterValueStruct[i]->Value) ;
	    //PRINTF("[%s] : ",InformResponse.ParameterList->__ptrParameterValueStruct[i+1]->Name) ;
	    //PRINTF("[%s]\n",InformResponse.ParameterList->__ptrParameterValueStruct[i+1]->Value) ;
    }

    return result;
}

int __cwmp_SetParameterValue(struct soap * soap, char ** NameList, char ** ValueList, int size)
{
    //PRINTF("Entry %s\n",__FUNCTION__);
    int result = 0 ;
    int i = 0 ;
    struct _cwmp__SetParameterValues * Inform ;
    struct _cwmp__SetParameterValuesResponse InformResponse;

    Inform =  (struct _cwmp__SetParameterValues *) soap_malloc(soap,sizeof(struct _cwmp__SetParameterValues));
    Inform->ParameterList = (struct cwmpArrayOfParameterValueStruct*) soap_malloc(soap,sizeof(struct cwmpArrayOfParameterValueStruct));
    Inform->ParameterList->__size = size ;
    Inform->ParameterList->__ptrParameterValueStruct = (struct cwmp__ParameterValueStruct **)soap_malloc(soap,(Inform->ParameterList->__size)*sizeof(struct cwmp__ParameterValueStruct*)) ;
    for(i = 0 ; i < Inform->ParameterList->__size ; i ++)
        Inform->ParameterList->__ptrParameterValueStruct[i] = (struct cwmp__ParameterValueStruct *)soap_malloc(soap,sizeof(struct cwmp__ParameterValueStruct)) ;

	for(i = 0 ; i < Inform->ParameterList->__size ; i ++)
	{
		Inform->ParameterList->__ptrParameterValueStruct[i]->Name = (char *)soap_strdup(soap,NameList[i]) ;
		Inform->ParameterList->__ptrParameterValueStruct[i]->Value = (char *)soap_strdup(soap,ValueList[i]) ;
	}

    result = __soap_call___cwmp__SetParameterValues(soap,"SetParameterValue",Inform,&InformResponse);
    PRINTF("############### Client RPC SetParameterValue ##############\n") ;
    PRINTF("[SetParameterValue Response] : [%d]\n",InformResponse.Status);

    return result;
}

int __cwmp_GetParameterAttributes(struct soap * soap, char ** NameList, int ** AttrList, int size)
{
    int result = 0 ;
    int i = 0 ;
    struct _cwmp__GetParameterAttributes * Inform ;
    struct _cwmp__GetParameterAttributesResponse InformResponse;

    Inform =  (struct _cwmp__GetParameterAttributes *) soap_malloc(soap,sizeof(struct _cwmp__GetParameterAttributes));
    Inform->ParameterNames = (struct cwmpArrayOfstring*) soap_malloc(soap,sizeof(struct cwmpArrayOfstring));
    Inform->ParameterNames->__size = size ;
    Inform->ParameterNames->__ptrstring = (char **) soap_malloc(soap,(Inform->ParameterNames->__size)*sizeof(char *));

    for(i = 0 ; i < Inform->ParameterNames->__size ; i ++)
		Inform->ParameterNames->__ptrstring[i] = (char *)soap_strdup(soap,NameList[i]) ;

    __soap_call___cwmp__GetParameterAttributes(soap,"GetParameterAttributes",Inform,&InformResponse);
	AttrList[0] = (int *)soap_malloc(soap,InformResponse.ParameterList->__size*sizeof(int));
    PRINTF("############### Client RPC GetParameterAttributes ##############\n") ;
    for(i = 0 ; i < InformResponse.ParameterList->__size ; i ++)
    {
		AttrList[0][i] = InformResponse.ParameterList->__ptrParameterAttributeStruct[i]->Notification ;
	    //PRINTF("[%s] : ",InformResponse.ParameterList->__ptrParameterAttributeStruct[i]->Name) ;
	    //PRINTF("[%d]\n",InformResponse.ParameterList->__ptrParameterAttributeStruct[i]->Notification) ;
    }

    return result;
}

int __cwmp_SetParameterAttributes(struct soap * soap, char ** NameList, int * AttrList, int size)
{
    int result = 0 ;
    int i = 0 ;
    struct _cwmp__SetParameterAttributes * Inform ;
    struct _cwmp__SetParameterAttributesResponse InformResponse;

    Inform =  (struct _cwmp__SetParameterAttributes *) soap_malloc(soap,sizeof(struct _cwmp__SetParameterAttributes));
    Inform->ParameterList = (struct cwmpArrayOfSetParameterAttributesStruct*) soap_malloc(soap,sizeof(struct cwmpArrayOfSetParameterAttributesStruct));
    Inform->ParameterList->__size = size ;
    Inform->ParameterList->__ptrSetParameterAttributesStruct = (struct cwmp__SetParameterAttributesStruct **)soap_malloc(soap,(Inform->ParameterList->__size)*sizeof(struct cwmp__SetParameterAttributesStruct*)) ;
    for(i = 0 ; i < Inform->ParameterList->__size ; i ++)
        Inform->ParameterList->__ptrSetParameterAttributesStruct[i] = (struct cwmp__SetParameterAttributesStruct *)soap_malloc(soap,sizeof(struct cwmp__SetParameterAttributesStruct)) ;

	for(i = 0 ; i < Inform->ParameterList->__size ; i ++)
	{
		Inform->ParameterList->__ptrSetParameterAttributesStruct[i]->Name = (char *)soap_strdup(soap,NameList[i]) ;
		Inform->ParameterList->__ptrSetParameterAttributesStruct[i]->Notification = AttrList[i] ;
		Inform->ParameterList->__ptrSetParameterAttributesStruct[i]->AccessListChange = NULL ;
    	Inform->ParameterList->__ptrSetParameterAttributesStruct[i]->AccessList = NULL ;
	}

    __soap_call___cwmp__SetParameterAttributes(soap,"SetParameterAttributes",Inform,&InformResponse);
    PRINTF("############### Client RPC SetParameterAttributes ##############\n") ;
    return result;
}

int __cwmp_AddObject(struct soap * soap, char * objpath)
{
    struct _cwmp__AddObject * Inform ;
    struct _cwmp__AddObjectResponse InformResponse;

    Inform = (struct _cwmp__AddObject *)soap_malloc(soap,sizeof(struct _cwmp__AddObject)) ;        
    Inform->ObjectName = (char *)soap_strdup(soap,objpath) ;
    Inform->ParameterKey = (char *)soap_strdup(soap,"0");
    __soap_call___cwmp__AddObject(soap,"AddObject",Inform,&InformResponse);
    PRINTF("############### Client RPC AddObject ##############\n") ;
    PRINTF("[AddObject] [InstanceNumber] = [%d] , [Status] = [%d]\n",InformResponse.InstanceNumber,InformResponse.Status) ;
    return InformResponse.Status ;
}

int __cwmp_DelObject(struct soap * soap, char * objpath)
{
    struct _cwmp__DeleteObject * Inform ;
    struct _cwmp__DeleteObjectResponse InformResponse;

    Inform = (struct _cwmp__DeleteObject *)soap_malloc(soap,sizeof(struct _cwmp__DeleteObject)) ;        
    Inform->ObjectName = (char *)soap_strdup(soap,objpath) ;
    Inform->ParameterKey = (char *)soap_strdup(soap,"0");
    __soap_call___cwmp__DeleteObject(soap,"DelObject",Inform,&InformResponse);
    PRINTF("############### Client RPC DeleteObject ##############\n") ;
    PRINTF("[DeleteObject] [Status] = [%d]\n",InformResponse.Status) ;
    return InformResponse.Status ;
}

int __cwmp_Reboot(struct soap * soap, char * CommandKey)
{
    int result = 0 ;
    struct _cwmp__Reboot * Inform ;
    struct _cwmp__RebootResponse InformResponse;

    Inform = (struct _cwmp__Reboot *)soap_malloc(soap,sizeof(struct _cwmp__Reboot)) ;        
    Inform->CommandKey = (char *)soap_strdup(soap,CommandKey);
    __soap_call___cwmp__Reboot(soap,"Reboot",Inform,&InformResponse);
    PRINTF("############### Client RPC Reboot ##############\n") ;
    return result ;
}

int __cwmp_Download(struct soap * soap, char *CommandKey,char *FileType,char *URL,char *Username,char *Password,int FileSize,char *TargetFileName,int DelaySeconds,char *SuccessURL,char *FailureURL)
{
    int result = 0 ;
    struct _cwmp__Download * Inform ;
    struct _cwmp__DownloadResponse InformResponse;

    Inform = (struct _cwmp__Download *)soap_malloc(soap,sizeof(struct _cwmp__Download)) ;        
    Inform->CommandKey = (char *)soap_strdup(soap,CommandKey);
    Inform->FileType = (char *)soap_strdup(soap,FileType);
    Inform->URL = (char *)soap_strdup(soap,URL);
    Inform->Username = (char *)soap_strdup(soap,Username);
    Inform->Password = (char *)soap_strdup(soap,Password);
    Inform->FileSize = FileSize ;
    Inform->TargetFileName = (char *)soap_strdup(soap,TargetFileName);
    Inform->DelaySeconds = DelaySeconds ;
    Inform->SuccessURL = (char *)soap_strdup(soap,SuccessURL);
    Inform->FailureURL = (char *)soap_strdup(soap,FailureURL);
    __soap_call___cwmp__Download(soap,"Download",Inform,&InformResponse);
    PRINTF("############### Client RPC Download ##############\n") ;
    return result ;
}

int __cwmp_Upload(struct soap * soap, char *CommandKey, char *FileType,char *URL,char *Username,char *Password,int DelaySeconds)
{
    int result = 0 ;
    struct _cwmp__Upload * Inform ;
    struct _cwmp__UploadResponse InformResponse;

    Inform = (struct _cwmp__Upload *)soap_malloc(soap,sizeof(struct _cwmp__Upload)) ;        
    Inform->CommandKey = (char *)soap_strdup(soap,CommandKey);
    Inform->FileType = (char *)soap_strdup(soap,FileType);
    Inform->URL = (char *)soap_strdup(soap,URL);
    Inform->Username = (char *)soap_strdup(soap,Username);
    Inform->Password = (char *)soap_strdup(soap,Password);
    Inform->DelaySeconds = DelaySeconds ;

    __soap_call___cwmp__Upload(soap,"Upload",Inform,&InformResponse);
    PRINTF("############### Client RPC Upload ##############\n") ;
    return result ;
}

int __cwmp_FactoryReset(struct soap * soap)
{
	PRINTF("Entry %s\n",__FUNCTION__) ;
    int result = 0 ;
    struct _cwmp__FactoryReset * Inform ;
    struct _cwmp__FactoryResetResponse InformResponse;

    Inform = (struct _cwmp__FactoryReset *)soap_malloc(soap,sizeof(struct _cwmp__FactoryReset)) ;

    result = __soap_call___cwmp__FactoryReset(soap,"FactoryReset",Inform,&InformResponse);
    PRINTF("############### Server RPC FactoryReset ##############\n") ;
    return result ;
}

int __cwmp_ScheduleInform(struct soap * soap, int DelaySeconds , char * CommandKey)
{
    int result = 0 ;
    struct _cwmp__ScheduleInform * Inform ;
    struct _cwmp__ScheduleInformResponse InformResponse;

    Inform = (struct _cwmp__ScheduleInform *)soap_malloc(soap,sizeof(struct _cwmp__ScheduleInform)) ;
    Inform->DelaySeconds = DelaySeconds ;
    Inform->CommandKey = (char *)soap_strdup(soap,CommandKey) ;
    __soap_call___cwmp__ScheduleInform(soap,"ScheduleInform",Inform,&InformResponse);
    PRINTF("############### Client RPC FactoryReset ##############\n") ;
    return result ;
}
int __cwmp_TranferComplete(struct soap * soap, char * CommandKey , time_t StartTime , time_t CompleteTime , char * FaultCode , char * FaultString)
{
    int result = 0 ;
    struct _cwmp__TranferComplete * Inform ;
    struct _cwmp__TranferCompleteResponse InformResponse;

    Inform = (struct _cwmp__TranferComplete *)soap_malloc(soap,sizeof(struct _cwmp__TranferComplete)) ;
    Inform->CommandKey = (char *)soap_strdup(soap,CommandKey) ;
    Inform->StartTime = StartTime ;
    Inform->CompleteTime = CompleteTime ;
	Inform->FaultStruct = NULL ;
	if(FaultCode != NULL || FaultString != NULL)
	{
    	Inform->FaultStruct = (struct cwmp__FaultStruct*)soap_malloc(soap,sizeof(struct cwmp__FaultStruct)) ;
    	Inform->FaultStruct->FaultCode = (char *)soap_strdup(soap,FaultCode) ;
    	Inform->FaultStruct->FaultString = (char *)soap_strdup(soap,FaultString) ;
	}

    __soap_call___cwmp__TranferComplete(soap,"TranferComplete",Inform,&InformResponse);
    PRINTF("############### Client RPC FactoryReset ##############\n") ;
    return result ;
}

/*****************************************************************************************/
/*	Web_cwmp_##RPC## use to run RPC on server after connect to client					 */
/*****************************************************************************************/

int Web_cwmp_GetRPCMethods(struct soap *soap)
{
    char *** RPCSupportList ;
    int size = 0 ;
    int result = 0 ;
    int i = 0 ;
    RPCSupportList = (char ***)soap_malloc(soap,sizeof(char **)) ;
    result = __cwmp_GetRPCMethods(soap,RPCSupportList,&size) ;
    PRINTF("RPC Support List [%d]: \n",size) ;
#ifndef WHOLE_COMPILE
#ifdef WITH_WEBSERVER
    WebBufferTag = 0 ;
    memset(WebBuffer,0x0,sizeof(WebBuffer)) ;
#endif
#endif
    for(i = 0 ; i < size ; i ++)
    {
#ifndef WHOLE_COMPILE
#ifdef WITH_WEBSERVER
        strcat(WebBuffer,RPCSupportList[0][i]) ;
        strcat(WebBuffer,"<br>") ;
#endif
#endif
        PRINTF("==>[%s]\n",RPCSupportList[0][i]) ;
    }
#ifndef WHOLE_COMPILE
#ifdef WITH_WEBSERVER
    WebBufferTag = 1 ;
#endif
#endif
    return result ;
}

int Web_cwmp_GetParameterValues(struct soap * soap)
{
    char ** NameList ;
    char *** ValueList ;
    int size = cwmp_NameListNum ;
    int i = 0 ;
    int result = 0 ;
    NameList = (char **)soap_malloc(soap,size*sizeof(char *)) ;
    ValueList = (char ***)soap_malloc(soap,sizeof(char **)) ;
    for(i = 0 ; i < size ; i ++)
    {
        NameList[i] = (char *)soap_strdup(soap,cwmp_NameList[i]) ;
    }

    result = __cwmp_GetParameterValue(soap,NameList,ValueList,size) ;
    PRINTF("GetParameterValue :\n") ;
#ifndef WHOLE_COMPILE
#ifdef WITH_WEBSERVER
    WebBufferTag = 0 ;
    memset(WebBuffer,0x0,sizeof(WebBuffer)) ;
#endif
#endif
    for(i = 0 ; i < size ; i ++)
    {
#ifndef WHOLE_COMPILE
#ifdef WITH_WEBSERVER
        strcat(WebBuffer,NameList[i]) ;
        strcat(WebBuffer," = ") ;
        strcat(WebBuffer,ValueList[0][i]) ;
        strcat(WebBuffer,"<br>") ;
#endif
#endif
        PRINTF("==>[%s] : [%s]\n",NameList[i],ValueList[0][i]) ;
    }
#ifndef WHOLE_COMPILE
#ifdef WITH_WEBSERVER
    WebBufferTag = 1 ;
#endif
#endif
    return result ;
}

int Web_cwmp_SetParameterValues(struct soap * soap)
{
    char ** NameList ;
    char ** ValueList ;
    int size = cwmp_NameListNum ;
    int result = 0 ;
    int i = 0 ;

    NameList = (char **)soap_malloc(soap,size*sizeof(char *)) ;
    ValueList = (char **)soap_malloc(soap,size*sizeof(char *)) ;
    for(i = 0 ; i < size ; i ++)
    {
        NameList[i] = (char *)soap_strdup(soap,cwmp_NameList[i]) ;
    }
    for(i = 0 ; i < size ; i ++)
    {
        ValueList[i] = (char *)soap_strdup(soap,cwmp_ValueList[i]) ;
    }
    result = __cwmp_SetParameterValue(soap,NameList,ValueList,size);
    PRINTF("SetParameterValue :\n") ;
#ifndef WHOLE_COMPILE
#ifdef WITH_WEBSERVER
    WebBufferTag = 0 ;
    memset(WebBuffer,0x0,sizeof(WebBuffer)) ;
    if(result)
        sprintf(WebBuffer,"SetParameterValue Failed<br>") ;
    else
        sprintf(WebBuffer,"SetParameterValue Success<br>") ;
    WebBufferTag = 1 ;
#endif
#endif
    for(i = 0 ; i < size ; i ++)
        PRINTF("==>[%s] : [%s]\n",NameList[i],ValueList[i]) ;
    return result ;
}

int Web_cwmp_GetParameterNames(struct soap * soap)
{
    char *** PathList ;
    int ** Writeable ;
    char * Path ;
    int size = 0 ;
    int result = 0 ;
    int i = 0 ;
    char tmpPath[256] ;    
    
    PathList = (char ***)soap_malloc(soap,sizeof(char **)) ;
    Writeable = (int **)soap_malloc(soap,sizeof(int *)) ;
    Path = (char *)soap_strdup(soap,cwmp_NameList[0]) ;
    result = __cwmp_GetNamelist(soap,Path,PathList,Writeable,&size) ;//CwmpClient_GetNamelist_Adapter(soap,Path,NameList,Writeable,&size);
    PRINTF("NameList Support Under Path [%s] [%d]: \n",Path,size) ;
#ifndef WHOLE_COMPILE
#ifdef WITH_WEBSERVER
    WebBufferTag = 0 ;
    memset(WebBuffer,0x0,sizeof(WebBuffer)) ;
    strcat(WebBuffer,"<b>") ;
    strcat(WebBuffer,Path) ;
    strcat(WebBuffer,"</b> : <br>") ;
#endif
#endif
    for(i = 0 ; i < size ; i ++)
    {
#ifndef WHOLE_COMPILE
#ifdef WITH_WEBSERVER
        memset(tmpPath,0x0,sizeof(tmpPath)) ;
        sprintf(tmpPath,"==>[%s%s] : [%d]<br>",Path,PathList[0][i],Writeable[0][i]);
        strcat(WebBuffer,tmpPath) ;
#endif
#endif
        PRINTF("==>[%s%s] : [%d]\n",Path,PathList[0][i],Writeable[0][i]) ;
    }
#ifndef WHOLE_COMPILE
#ifdef WITH_WEBSERVER
    WebBufferTag = 1 ;
#endif
#endif
    return result ;
}

int Web_cwmp_AddObject(struct soap * soap)
{
    int result = 0 ;
    char ** NameList ;
    int i = 0 ;
    int size = cwmp_NameListNum ; //current we only support one Instance for Object Add.
    NameList = (char **)soap_malloc(soap,size*sizeof(char *)) ;
    for(i = 0 ; i < size ; i ++)
    {
        NameList[i] = (char *)soap_strdup(soap,cwmp_NameList[i]) ;
    }
    result = __cwmp_AddObject(soap,NameList[0]) ;//CwmpClient_AddObject_Adapter(soap,Path) ;
		
#ifndef WHOLE_COMPILE
#ifdef WITH_WEBSERVER
    WebBufferTag = 0 ;
    memset(WebBuffer,0x0,sizeof(WebBuffer)) ;
#endif
#endif
    if(result == 0)
    {
		PRINTF("AddObject : [%s] success \n",NameList[0]) ;
#ifndef WHOLE_COMPILE
#ifdef WITH_WEBSERVER
        sprintf(WebBuffer,"Add Object [%s] Success <br>",NameList[0]) ;
        WebBufferTag = 1 ;
#endif
#endif
		return 0 ;
    }
	PRINTF("AddObject : [%s] failed \n",NameList[0]) ;
#ifndef WHOLE_COMPILE
#ifdef WITH_WEBSERVER
    sprintf(WebBuffer,"Add Object [%s] Failed .<br>",NameList[0]) ;
    WebBufferTag = 1 ;
#endif
#endif
    return 1 ;
}

int Web_cwmp_DelObject(struct soap * soap)
{
    int result ;
    char ** NameList ;
    int size = cwmp_NameListNum ; //current we only support one Instance for Object Del.
    int i = 0 ;
    NameList = (char **)soap_malloc(soap,size*sizeof(char *)) ;
    for(i = 0 ; i < size ; i ++)
    {
        NameList[i] = (char *)soap_strdup(soap,cwmp_NameList[i]) ;
    }
    result = __cwmp_DelObject(soap,NameList[0]) ;
#ifndef WHOLE_COMPILE
#ifdef WITH_WEBSERVER
    WebBufferTag = 0 ;
    memset(WebBuffer,0x0,sizeof(WebBuffer)) ;
    if(result)
        sprintf(WebBuffer,"Delete Object [%s] Failed .<br>",NameList[0]) ;
    else
        sprintf(WebBuffer,"Delete Object [%s] Success .<br>",NameList[0]) ;
    WebBufferTag = 1 ;
#endif
#endif

    PRINTF("DelObject : [%s]\n",NameList[0]) ;
    return result ;
}

int Web_cwmp_Reboot(struct soap * soap)
{
	char rootPath[PARAM_MAX_LENGTH] = "InternetGatewayDevice.ManagementServer.ItmsRemoteRebootCommandKey" ;
    char *pValue = (char *)malloc(PARAM_MAX_LENGTH) ;
    _GetConfigValue(rootPath,pValue) ;
    __cwmp_Reboot(soap,pValue) ;
	
#ifndef WHOLE_COMPILE
#ifdef WITH_WEBSERVER
    WebBufferTag = 0 ;
    memset(WebBuffer,0x0,sizeof(WebBuffer)) ;
    sprintf(WebBuffer,"Remote Reboot Client with CommandKey [%s] .<br>",pValue) ;
    WebBufferTag = 1 ;
#endif
#endif
	
    PRINTF("Reboot : CommandKey [%s]\n",pValue) ;
	free(pValue) ;
    return 0 ;
}

int Web_cwmp_FactoryReset(struct soap * soap)
{
    __cwmp_FactoryReset(soap) ;
	
#ifndef WHOLE_COMPILE
#ifdef WITH_WEBSERVER
    WebBufferTag = 0 ;
    memset(WebBuffer,0x0,sizeof(WebBuffer)) ;
    sprintf(WebBuffer,"Remote FactoryReset Client .<br>") ;
    WebBufferTag = 1 ;
#endif
#endif
	
    PRINTF("FactoryReset \n") ;
    return 0 ;
}

int Web_cwmp_Download(struct soap * soap)
{

	if(!downloadData)
	{
		PRINTF("%s : Have not init download data , so skip this event \n",__FUNCTION__) ;
		return 0 ;
	}
	__cwmp_Download(soap, downloadData->CommandKey,
						  downloadData->FileType,
						  downloadData->URL,
						  downloadData->Username,
						  downloadData->Password,
						  downloadData->FileSize,
						  downloadData->TargetFileName,
						  downloadData->DelaySeconds,
						  downloadData->SuccessURL,
						  downloadData->FailureURL) ;

#ifndef WHOLE_COMPILE
#ifdef WITH_WEBSERVER
    WebBufferTag = 0 ;
    memset(WebBuffer,0x0,sizeof(WebBuffer)) ;
    sprintf(WebBuffer,"Remote Download .<br>") ;
    WebBufferTag = 1 ;
#endif
#endif
	
    PRINTF("Download \n") ;
    return 0 ;
}

int Web_cwmp_Upload(struct soap * soap)
{
	if(!uploadData)
	{
		PRINTF("%s : Have not init upload data , so skip this event \n",__FUNCTION__) ;
		return 0 ;
	}
	__cwmp_Upload(soap, uploadData->CommandKey, 
						uploadData->FileType,
						uploadData->URL,
						uploadData->Username,
						uploadData->Password,
						uploadData->DelaySeconds) ;
	
#ifndef WHOLE_COMPILE
#ifdef WITH_WEBSERVER
    WebBufferTag = 0 ;
    memset(WebBuffer,0x0,sizeof(WebBuffer)) ;
    sprintf(WebBuffer,"Remote Upload .<br>") ;
    WebBufferTag = 1 ;
#endif
#endif
	
    PRINTF("Upload \n") ;
    return 0 ;
}

int Web_cwmp_ScheduleInform(struct soap * soap)
{
	if(!scheduleInformData)
	{
		PRINTF("%s : Have not init schedule inform data , so skip this event \n",__FUNCTION__) ;
		return 0 ;
	}
	__cwmp_ScheduleInform(soap, scheduleInformData->DelaySeconds , scheduleInformData->CommandKey) ;

#ifndef WHOLE_COMPILE
#ifdef WITH_WEBSERVER
    WebBufferTag = 0 ;
    memset(WebBuffer,0x0,sizeof(WebBuffer)) ;
    sprintf(WebBuffer,"Remote ScheduleInform .<br>") ;
    WebBufferTag = 1 ;
#endif
#endif
	
    PRINTF("ScheduleInform \n") ;
    return 0 ;
}

/*****************************************************************************************/
/*	EventAction_cwmp_##RPC## use to run RPC on server while first client Inform			 */
/*****************************************************************************************/

int EventAction_cwmp_GetRPCMethods(struct soap *soap , int index)
{
    return Web_cwmp_GetRPCMethods(soap) ;
}

int EventAction_cwmp_GetParameterValues(struct soap *soap , int index)
{
    char ** NameList ;
    char *** ValueList ;
    int size = 0 ;
    int i = 0 ;
    int result = 0 ;
    
    char rootPath[PARAM_MAX_LENGTH] = "InternetGatewayDevice.ManagementServer.EventAction." ;
    char newPath[PARAM_MAX_LENGTH] ;
    char *pValue = (char *)malloc(PARAM_MAX_LENGTH) ;

    memset(newPath,0x0,sizeof(newPath)) ;
    memset(pValue,0x0,PARAM_MAX_LENGTH) ;
    snprintf(newPath,sizeof(newPath),"%s%d.EventResponse.%d.ParameterListNum",rootPath,cwmp_EventActionID,index) ;
    _GetConfigValue(newPath,pValue) ;
    size = atoi(pValue) ;
	NameList = (char **)soap_malloc(soap,size*sizeof(char *)) ;
    ValueList = (char ***)soap_malloc(soap,sizeof(char **)) ;
    for(i = 1 ; i <= size ; i ++)
    {
	    memset(newPath,0x0,sizeof(newPath)) ;
        memset(pValue,0x0,PARAM_MAX_LENGTH) ;
        snprintf(newPath,sizeof(newPath),"%s%d.EventResponse.%d.ParameterList.%d.ParameterName",rootPath,cwmp_EventActionID,index,i) ;
        _GetConfigValue(newPath,pValue) ;
        NameList[i-1] = (char *)soap_strdup(soap,pValue) ;
    }
    free(pValue) ;
    result = __cwmp_GetParameterValue(soap,NameList,ValueList,size) ;
    PRINTF("GetParameterValue :\n") ;
#if 0
#ifndef WHOLE_COMPILE
#ifdef WITH_WEBSERVER
    WebBufferTag = 0 ;
    memset(WebBuffer,0x0,sizeof(WebBuffer)) ;
#endif
#endif
#endif
    for(i = 0 ; i < size ; i ++)
    {
#if 0
#ifndef WHOLE_COMPILE
#ifdef WITH_WEBSERVER
        strcat(WebBuffer,NameList[i]) ;
        strcat(WebBuffer," = ") ;
        strcat(WebBuffer,ValueList[0][i]) ;
        strcat(WebBuffer,"<br>") ;
#endif
#endif
#endif
        PRINTF("==>[%s] : [%s]\n",NameList[i],ValueList[0][i]) ;
    }
#if 0
#ifndef WHOLE_COMPILE
#ifdef WITH_WEBSERVER
    WebBufferTag = 1 ;
#endif
#endif
#endif
    return result ;
}

int EventAction_cwmp_SetParameterValues(struct soap *soap , int index)
{
    char ** NameList ;
    char ** ValueList ;
    char rootPath[PARAM_MAX_LENGTH] = "InternetGatewayDevice.ManagementServer.EventAction." ;
    char newPath[PARAM_MAX_LENGTH] ;
    char *pValue = (char *)malloc(PARAM_MAX_LENGTH) ;
    int size = 0 ;
    int result = 0 ;
    int i = 0 ;
    

    memset(newPath,0x0,sizeof(newPath)) ;
    memset(pValue,0x0,PARAM_MAX_LENGTH) ;
    snprintf(newPath,sizeof(newPath),"%s%d.EventResponse.%d.ParameterListNum",rootPath,cwmp_EventActionID,index) ;
    _GetConfigValue(newPath,pValue) ;
    size = atoi(pValue) ;
	NameList = (char **)soap_malloc(soap,size*sizeof(char *)) ;
    ValueList = (char **)soap_malloc(soap,size*sizeof(char *)) ;
    for(i = 1 ; i <= size ; i ++)
    {
        memset(newPath,0x0,sizeof(newPath)) ;
        memset(pValue,0x0,PARAM_MAX_LENGTH) ;
        snprintf(newPath,sizeof(newPath),"%s%d.EventResponse.%d.ParameterList.%d.ParameterName",rootPath,cwmp_EventActionID,index,i) ;
        _GetConfigValue(newPath,pValue) ;
        NameList[i-1] = (char *)soap_strdup(soap,pValue) ;
	    memset(newPath,0x0,sizeof(newPath)) ;
        memset(pValue,0x0,PARAM_MAX_LENGTH) ;
        snprintf(newPath,sizeof(newPath),"%s%d.EventResponse.%d.ParameterList.%d.ParameterValue",rootPath,cwmp_EventActionID,index,i) ;
        _GetConfigValue(newPath,pValue) ;
        ValueList[i-1] = (char *)soap_strdup(soap,pValue) ;

    }
    free(pValue) ;
    result = __cwmp_SetParameterValue(soap,NameList,ValueList,size);
    PRINTF("SetParameterValue :\n") ;
#if 0
#ifndef WHOLE_COMPILE
#ifdef WITH_WEBSERVER
    WebBufferTag = 0 ;
    memset(WebBuffer,0x0,sizeof(WebBuffer)) ;
    if(result)
        sprintf(WebBuffer,"SetParameterValue Failed<br>") ;
    else
        sprintf(WebBuffer,"SetParameterValue Success<br>") ;
    WebBufferTag = 1 ;
#endif
#endif
#endif
    for(i = 0 ; i < size ; i ++)
        PRINTF("==>[%s] : [%s]\n",NameList[i],ValueList[i]) ;
    return result ;
}

int EventAction_cwmp_GetParameterNames(struct soap *soap , int index)
{
    char *** PathList ;
    int ** Writeable ;
    char * Path ;
    char ** NameList ;
    int size = 0 ;
    int psize = 0 ;
    int result = 0 ;
    int i = 0 ;
    int j = 0 ;
    char rootPath[PARAM_MAX_LENGTH] = "InternetGatewayDevice.ManagementServer.EventAction." ;
    char newPath[PARAM_MAX_LENGTH] ;
    char *pValue = (char *)malloc(PARAM_MAX_LENGTH) ;
    

    memset(newPath,0x0,sizeof(newPath)) ;
    memset(pValue,0x0,PARAM_MAX_LENGTH) ;
    snprintf(newPath,sizeof(newPath),"%s%d.EventResponse.%d.ParameterListNum",rootPath,cwmp_EventActionID,index) ;
    _GetConfigValue(newPath,pValue) ;
    size = atoi(pValue) ;
	NameList = (char **)soap_malloc(soap,size*sizeof(char *)) ;
    for(i = 1 ; i <= size ; i ++)
    {
        memset(newPath,0x0,sizeof(newPath)) ;
        memset(pValue,0x0,PARAM_MAX_LENGTH) ;
        snprintf(newPath,sizeof(newPath),"%s%d.EventResponse.%d.ParameterList.%d.ParameterName",rootPath,cwmp_EventActionID,index,i) ;
        _GetConfigValue(newPath,pValue) ;
        NameList[i-1] = (char *)soap_strdup(soap,pValue) ;

    }
    free(pValue) ;
    PathList = (char ***)soap_malloc(soap,sizeof(char **)) ;
    Writeable = (int **)soap_malloc(soap,sizeof(int *)) ;
#if 0
#ifndef WHOLE_COMPILE
#ifdef WITH_WEBSERVER
    memset(WebBuffer,0x0,sizeof(WebBuffer)) ;
#endif
#endif
#endif
    for(i = 1 ; i <= size ; i ++)
    {
        result = __cwmp_GetNamelist(soap,NameList[i-1],PathList,Writeable,&psize) ;//CwmpClient_GetNamelist_Adapter(soap,Path,NameList,Writeable,&size);
        PRINTF("NameList Support Under Path [%s] [%d]: \n",NameList[i-1],psize) ;
#if 0
#ifndef WHOLE_COMPILE
#ifdef WITH_WEBSERVER
        WebBufferTag = 0 ;
        strcat(WebBuffer,"<b>") ;
		strcat(WebBuffer,NameList[i-1]) ;
		strcat(WebBuffer,"</b> : <br>") ;
#endif
#endif
#endif
    	for(j = 0 ; j < psize ; j ++)
    	{
#if 0
#ifndef WHOLE_COMPILE
#ifdef WITH_WEBSERVER
            memset(newPath,0x0,sizeof(newPath)) ;
            snprintf(newPath,sizeof(newPath),"==>[%s%s] : [%d]<br>",NameList[i-1],PathList[0][j],Writeable[0][j]);
            strcat(WebBuffer,newPath) ;
#endif
#endif
#endif
            PRINTF("==>[%s%s] : [%d]\n",NameList[i-1],PathList[0][j],Writeable[0][j]) ;
        }
#if 0
#ifndef WHOLE_COMPILE
#ifdef WITH_WEBSERVER
        WebBufferTag = 1 ;
#endif
#endif
#endif
    }
    return result ;
}

int EventAction_cwmp_AddObject(struct soap *soap , int index)
{
    char ** NameList ;
    char ** ValueList ;
    char rootPath[PARAM_MAX_LENGTH] = "InternetGatewayDevice.ManagementServer.EventAction." ;
    char newPath[PARAM_MAX_LENGTH] ;
    char *pValue = (char *)malloc(PARAM_MAX_LENGTH) ;
    int size = 0 ;
    int result = 0 ;
    int i = 0 ;
    
    memset(newPath,0x0,sizeof(newPath)) ;
    memset(pValue,0x0,PARAM_MAX_LENGTH) ;
    snprintf(newPath,sizeof(newPath),"%s%d.EventResponse.%d.ParameterListNum",rootPath,cwmp_EventActionID,index) ;
    _GetConfigValue(newPath,pValue) ;
    size = atoi(pValue) ;
	NameList = (char **)soap_malloc(soap,size*sizeof(char *)) ;
    ValueList = (char **)soap_malloc(soap,size*sizeof(char *)) ;
	PRINTF("AddObject : Object Number [%s] : [%s]\n",newPath,pValue) ;
    for(i = 1 ; i <= size ; i ++)
    {
        memset(newPath,0x0,sizeof(newPath)) ;
        memset(pValue,0x0,PARAM_MAX_LENGTH) ;
        snprintf(newPath,sizeof(newPath),"%s%d.EventResponse.%d.ParameterList.%d.ParameterName",rootPath,cwmp_EventActionID,index,i) ;
        _GetConfigValue(newPath,pValue) ;
		PRINTF("AddObject : Object Number [%s] : [%s]\n",newPath,pValue) ;
        NameList[i-1] = (char *)soap_strdup(soap,pValue) ;
		if(__cwmp_AddObject(soap,NameList[i-1]) == 0)
			ValueList[i-1] = (char *)soap_strdup(soap,"Success") ;
		else
			ValueList[i-1] = (char *)soap_strdup(soap,"Failed") ;
    }
    free(pValue) ;

    PRINTF("AddObject :\n") ;
#if 0
#ifndef WHOLE_COMPILE
#ifdef WITH_WEBSERVER
    WebBufferTag = 0 ;
    memset(WebBuffer,0x0,sizeof(WebBuffer)) ;
	for(i = 0 ; i < size ; i ++)
        PRINTF("==>[%s] : [%s]\n",NameList[i],ValueList[i]) ;
    WebBufferTag = 1 ;
#endif
#endif
#endif
    for(i = 0 ; i < size ; i ++)
        PRINTF("==>[%s] : [%s]\n",NameList[i],ValueList[i]) ;
    return result ;
}

int EventAction_cwmp_DelObject(struct soap *soap , int index)
{
    char ** NameList ;
    char ** ValueList ;
    char rootPath[PARAM_MAX_LENGTH] = "InternetGatewayDevice.ManagementServer.EventAction." ;
    char newPath[PARAM_MAX_LENGTH] ;
    char *pValue = (char *)malloc(PARAM_MAX_LENGTH) ;
    int size = 0 ;
    int result = 0 ;
    int i = 0 ;
    

    memset(newPath,0x0,sizeof(newPath)) ;
    memset(pValue,0x0,PARAM_MAX_LENGTH) ;
    snprintf(newPath,sizeof(newPath),"%s%d.EventResponse.%d.ParameterListNum",rootPath,cwmp_EventActionID,index) ;
    _GetConfigValue(newPath,pValue) ;
    size = atoi(pValue) ;
	NameList = (char **)soap_malloc(soap,size*sizeof(char *)) ;
    ValueList = (char **)soap_malloc(soap,size*sizeof(char *)) ;
    for(i = 1 ; i <= size ; i ++)
    {
        memset(newPath,0x0,sizeof(newPath)) ;
        memset(pValue,0x0,PARAM_MAX_LENGTH) ;
        snprintf(newPath,sizeof(newPath),"%s%d.EventResponse.%d.ParameterList.%d.ParameterName",rootPath,cwmp_EventActionID,index,i) ;
        _GetConfigValue(newPath,pValue) ;
        NameList[i-1] = (char *)soap_strdup(soap,pValue) ;
		if(__cwmp_DelObject(soap,NameList[i-1]) == 0)
			ValueList[i-1] = (char *)soap_strdup(soap,"Success") ;
		else
			ValueList[i-1] = (char *)soap_strdup(soap,"Failed") ;
    }
    
    PRINTF("DelObject :\n") ;
#if 0
#ifndef WHOLE_COMPILE
#ifdef WITH_WEBSERVER
    WebBufferTag = 0 ;
    memset(WebBuffer,0x0,sizeof(WebBuffer)) ;
    if(result)
        sprintf(WebBuffer,"AddObject Failed<br>") ;
    else
        sprintf(WebBuffer,"AddObject Success<br>") ;
	for(i = 0 ; i < size ; i ++)
	{
		memset(pValue,0x0,PARAM_MAX_LENGTH) ;
		sprintf(pValue,"==>[%s] : [%s]<br>",NameList[i],ValueList[i]) ;
		strcat(WebBuffer,pValue) ;
	}
    WebBufferTag = 1 ;
#endif
#endif
#endif
    for(i = 0 ; i < size ; i ++)
        PRINTF("==>[%s] : [%s]\n",NameList[i],ValueList[i]) ;
	free(pValue) ;
    return result ;
}


int EventAction_cwmp_Reboot(struct soap *soap , int index)
{
    char rootPath[PARAM_MAX_LENGTH] = "InternetGatewayDevice.ManagementServer.ItmsRemoteRebootCommandKey" ;
    char *pValue = (char *)malloc(PARAM_MAX_LENGTH) ;

    _GetConfigValue(rootPath,pValue) ;
#if 0
#ifndef WHOLE_COMPILE
#ifdef WITH_WEBSERVER
    memset(WebBuffer,0x0,sizeof(WebBuffer)) ;
    WebBufferTag = 0 ;
    strcat(WebBuffer,"<b>") ;
	strcat(WebBuffer,"Client Rebooting ...") ;
	strcat(WebBuffer,"</b>") ;
    WebBufferTag = 1 ;
#endif
#endif
#endif
	__cwmp_Reboot(soap,pValue) ;
	free(pValue) ;
    return 0 ;
}

int EventAction_cwmp_FactoryReset(struct soap *soap , int index)
{
#if 0
#ifndef WHOLE_COMPILE
#ifdef WITH_WEBSERVER
    memset(WebBuffer,0x0,sizeof(WebBuffer)) ;
    WebBufferTag = 0 ;
    strcat(WebBuffer,"<b>") ;
	strcat(WebBuffer,"Client FactoryReset now ") ;
	strcat(WebBuffer,"</b>") ;
    WebBufferTag = 1 ;
#endif
#endif
#endif
	__cwmp_FactoryReset(soap) ;
    return 0 ;
}

int EventAction_cwmp_Download(struct soap * soap , int index)
{
	return Web_cwmp_Download(soap) ;
}

int EventAction_cwmp_Upload(struct soap * soap , int index)
{
	return Web_cwmp_Upload(soap) ;
}

int EventAction_cwmp_ScheduleInform(struct soap * soap , int index)
{
	return Web_cwmp_ScheduleInform(soap) ;
}


int __cwmp_soap_emptypost_rpc_handle(struct soap *soap , char * rpcname)
{
    int result = 0 ;
    if(strcmp(rpcname,"GetRPCMethods") == 0)
    {
        if(!Web_cwmp_GetRPCMethods(soap))
            result = 1 ;
    }else if(strcmp(rpcname,"GetParameterValues") == 0)
    {
        if(!Web_cwmp_GetParameterValues(soap))
            result = 1 ;
    }else if(strcmp(rpcname,"SetParameterValues") == 0)
    {
        if(!Web_cwmp_SetParameterValues(soap))
            result = 1 ;
    }else if(strcmp(rpcname,"GetParameterNames") == 0)
    {
        if(!Web_cwmp_GetParameterNames(soap))
            result = 1 ;
    }else if(strcmp(rpcname,"AddObject") == 0)
    {
        if(!Web_cwmp_AddObject(soap))
            result = 1 ;
    }else if(strcmp(rpcname,"DelObject") == 0)
    {
        if(!Web_cwmp_DelObject(soap))
            result = 1 ;
    }else if(strcmp(rpcname,"Reboot") == 0)
    {
        if(!Web_cwmp_Reboot(soap))
            result = 1 ;
    }else if(strcmp(rpcname,"FactoryReset") == 0)
    {
        if(!Web_cwmp_FactoryReset(soap))
            result = 1 ;
    }else if(strcmp(rpcname,"Download") == 0)
    {
        if(!Web_cwmp_Download(soap))
            result = 1 ;
    }else if(strcmp(rpcname,"Upload") == 0)
    {
        if(!Web_cwmp_Upload(soap))
            result = 1 ;
    }else if(strcmp(rpcname,"ScheduleInform") == 0)
    {
        if(!Web_cwmp_ScheduleInform(soap))
            result = 1 ;
    }else if(strlen(rpcname) < 1)
    {
            result = 0 ;
    }
    else
    {
		PRINTF("\n[Have not implement %s empty post handle , please add code in %s : %s]\n",rpcname,__FILE__,__FUNCTION__) ;
		result = 0 ;
    }
    return result ;
}

int EventAction_RPC_Handle(struct soap *soap , char * rpcname)
{

    char rootPath[PARAM_MAX_LENGTH] = "InternetGatewayDevice.ManagementServer.EventAction." ;
    char newPath[PARAM_MAX_LENGTH] ;
    char *pValue = (char *)malloc(PARAM_MAX_LENGTH) ;
    int ResNum = 0 ;
    int result = 0 ;
    int i = 0 ;
    memset(newPath,0x0,sizeof(newPath)) ;
    memset(pValue,0x0,PARAM_MAX_LENGTH) ;
    snprintf(newPath,sizeof(newPath),"%s%d.EventResponseNum",rootPath,cwmp_EventActionID) ;
    _GetConfigValue(newPath,pValue) ;
    ResNum = atoi(pValue) ;
    for(i = 1 ; i <= ResNum ; i ++)
    {
        memset(newPath,0x0,sizeof(newPath)) ;
        memset(pValue,0x0,PARAM_MAX_LENGTH) ;
        snprintf(newPath,sizeof(newPath),"%s%d.EventResponse.%d.EventString",rootPath,cwmp_EventActionID,i) ;
        _GetConfigValue(newPath,pValue) ;

        if(strcmp(pValue,"GetRPCMethods") == 0)
        {
            if(!EventAction_cwmp_GetRPCMethods(soap,i))
                result = 1 ;
        }else if(strcmp(pValue,"GetParameterValues") == 0)
        {
            if(!EventAction_cwmp_GetParameterValues(soap,i))
                result = 1 ;
        }else if(strcmp(pValue,"SetParameterValues") == 0)
        {
            if(!EventAction_cwmp_SetParameterValues(soap,i))
                result = 1 ;
        }else if(strcmp(pValue,"GetParameterNames") == 0)
        {
            if(!EventAction_cwmp_GetParameterNames(soap,i))
                result = 1 ;
        }else if(strcmp(pValue,"AddObject") == 0)
		{
			if(!EventAction_cwmp_AddObject(soap,i))
					result = 1 ;
		}else if(strcmp(pValue,"DeleteObject") == 0)
		{
			if(!EventAction_cwmp_DelObject(soap,i))
					result = 1 ;
		}else if(strcmp(pValue,"Reboot") == 0)
		{
			if(!EventAction_cwmp_Reboot(soap,i))
					result = 1 ;
		}else if(strcmp(pValue,"FactoryReset") == 0)
		{
			if(!EventAction_cwmp_FactoryReset(soap,i))
					result = 1 ;
		}else if(strcmp(pValue,"Download") == 0)
		{
			if(!EventAction_cwmp_Download(soap,i))
					result = 1 ;
		}else if(strcmp(pValue,"Upload") == 0)
		{
			if(!EventAction_cwmp_Upload(soap,i))
					result = 1 ;
		}else if(strcmp(pValue,"ScheduleInform") == 0)
		{
			if(!EventAction_cwmp_ScheduleInform(soap,i))
					result = 1 ;
		}else if(strlen(rpcname) < 1)
			{
			result = 0 ;
		}
		else
        {
	    PRINTF("\n[Have not implement %s Event Action , please add code in %s : %s]\n",rpcname,__FILE__,__FUNCTION__) ;
            result = 0 ;
        }
    }
    free(pValue) ;
    return result ;
}

int  __cwmp_soap_emptypost_handle(struct soap *soap)
{
    PRINTF("Entry %s : [%s] [%s]\n",__FUNCTION__,RpcNameRes,RpcName) ;
    //RpcName is from CGI to tigger RPC from Web GUI , RpcNameRes is from config which configure via Web GUI ,just use to response client inform . 
    EventAction_RPC_Handle(soap,RpcNameRes) ;
    //__cwmp_soap_emptypost_rpc_handle(soap,RpcNameRes) ;
    if(__cwmp_soap_emptypost_rpc_handle(soap,RpcName))
		soap_send_empty_response(soap,200) ;
    else
		soap_send_empty_response(soap,204) ;
    memset(RpcName,0x0,sizeof(RpcName)) ;
    memset(RpcNameRes,0x0,sizeof(RpcNameRes)) ;
    return 0 ;
}

#endif
#endif

int  __cwmp_Auth(struct soap * soap ,int dir)
{
#ifdef BASIC_AUTH
	if (Acsconfig.AuthType == 1 || Acsconfig.AuthType == 3)
	{
		if(soap->userid && soap->passwd) // Basic authentication
	  	{
			if (!strcmp(soap->userid, Acsconfig.Username) && !strcmp(soap->passwd, Acsconfig.Password))
			{
		  		return SOAP_OK;
			}
	  	}
	}
#endif
#if defined(WITH_OPENSSL)
#if defined(DIGEST_AUTH)
  	else if (Acsconfig.AuthType == 2 || Acsconfig.AuthType == 3)
	{
		if(soap->authrealm && soap->userid) // Digest authentication
	  	{
			if (!strcmp(soap->authrealm, Acsconfig.Realm) && !strcmp(soap->userid, Acsconfig.Username))
			{
                if(dir)
                {
		  		    if (!http_da_verify_post(soap, Acsconfig.Password)) // HTTP POST DA verification
		   	 		    return SOAP_OK;
                }
                else
                {
                    if (!http_da_verify_get(soap, Acsconfig.Password)) // HTTP POST DA verification
		   	 		    return SOAP_OK;
                }
			}
	  	}
	}
    if(Acsconfig.AuthType == 2 || Acsconfig.AuthType == 3)
    {
  	    soap->authrealm = Acsconfig.Realm; // realm to send to client
        return 401 ;
    }
#endif
#endif
#ifdef BASIC_AUTH
	if(Acsconfig.AuthType == 1)
    	return 401 ;
#endif
  	return SOAP_OK; // Not authorized, challenge with digest authentication
}

#if defined (HTTP_GET)

int cwmp_get_handler(struct soap *soap)
{

    if(__cwmp_Auth(soap,0) != SOAP_OK)//if (check_authentication(soap))
        return 401; /* HTTP not authorized */
    if (soap->path[1] == '\0' || soap->path[1] == '?')
    {
        soap->keep_alive = 0 ;
        return soap_send_empty_response(soap, 200);//return info(soap);
    }
    return 404; /* HTTP not found */
}
#endif

#ifdef WITH_COOKIES

void __cwmp_Cookies(struct soap * soap)
{
    int n;
    char *s, domain[32] ,buf[16];
    memset(domain,0x0,sizeof(buf)) ;
    sprintf(domain,"127.0.0.1") ; // this must be ipaddress .

    s = soap_cookie_value(soap, "sessionid", domain, "/");

    if (s)
        n = atoi(s)+1; // yes: increment int value as demo example session
    else
        n = 1; // no: return cookie with value 1 to client to start session
    memset(buf,0x0,sizeof(buf)) ;
    sprintf(buf, "%d", n);
    soap_set_cookie(soap, "sessionid", buf, domain, "/");
    soap_set_cookie_expire(soap, "sessionid", 5, domain, "/");

}
#endif

int find_InformDevice(struct _cwmp__Inform* Inform , char * path , char * param)
{
    PRINTF("Entry %s\n",__FUNCTION__) ;
	int i = 0 ;
	int ret = 0 ;
	char newpath[256] ;
	char * value = (char *)malloc(PARAM_MAX_LENGTH);
	for(i = 1 ; i <= Acsconfig.ManageableDeviceNumberOfEntries ; i ++)
	{
		sprintf(newpath,"%s.%d.%s",path,i,param) ;
		_GetConfigValue(newpath , value) ;
		if(strcmp(value,Inform->DeviceId->SerialNumber) == 0)
			ret = 1 ;
	}
	free(value) ;
	return ret ;
}


int add_InformDevice(struct _cwmp__Inform* Inform , char * path)
{
	int Instance = 0 ;
	int i = 0 ;
    PRINTF("Entry %s\n",__FUNCTION__) ;
	if(strcmp(Inform->Event->__ptrEventStruct[0]->EventCode,"0 BOOTSTRAP") != 0)
	{
		PRINTF("First Inform must be 0 BOOTSTRAP !!!\n") ;
		//return 1 ;
	}
	char * newpath = (char *)malloc(PARAM_MAX_LENGTH);
	Instance = AddInstanceXML(path) ;

	if(Instance == 0)
	{
		PRINTF("Add Inform Device Failed .\n") ;
		return 1 ;
	}
    PRINTF("Config the parameters \n") ;
	memset(newpath,0x0,PARAM_MAX_LENGTH) ;
	sprintf(newpath,"InternetGatewayDevice.ManagementServer.ManageableDevice.%d.Manufacturer",Instance) ;
	SetConfigValue(newpath , Inform->DeviceId->Manufacturer) ;

	memset(newpath,0x0,PARAM_MAX_LENGTH) ;
	sprintf(newpath,"InternetGatewayDevice.ManagementServer.ManageableDevice.%d.ManufacturerOUI",Instance) ;
	SetConfigValue(newpath , Inform->DeviceId->OUI) ;

	memset(newpath,0x0,PARAM_MAX_LENGTH) ;
	sprintf(newpath,"InternetGatewayDevice.ManagementServer.ManageableDevice.%d.ProductClass",Instance) ;
	SetConfigValue(newpath , Inform->DeviceId->ProductClass) ;

	memset(newpath,0x0,PARAM_MAX_LENGTH) ;
	sprintf(newpath,"InternetGatewayDevice.ManagementServer.ManageableDevice.%d.SerialNumber",Instance) ;
	SetConfigValue(newpath , Inform->DeviceId->SerialNumber) ;
	PRINTF("Start Set Attach Parameters [%d]\n",Inform->ParameterList->__size) ;
    for(i = 0 ; i < Inform->ParameterList->__size ; i ++)
    {
        PRINTF("Set [%s]=[%s]\n",Inform->ParameterList->__ptrParameterValueStruct[i]->Name,Inform->ParameterList->__ptrParameterValueStruct[i]->Value) ;
        if(strcmp(Inform->ParameterList->__ptrParameterValueStruct[i]->Name,"InternetGatewayDevice.DeviceInfo.SpecVersion") == 0)
        {
            memset(newpath,0x0,PARAM_MAX_LENGTH) ;
            sprintf(newpath,"InternetGatewayDevice.ManagementServer.ManageableDevice.%d.SpecVersion",Instance) ;
            SetConfigValue(newpath , Inform->ParameterList->__ptrParameterValueStruct[i]->Value) ;
        }
        if(strcmp(Inform->ParameterList->__ptrParameterValueStruct[i]->Name,"InternetGatewayDevice.DeviceInfo.HardwareVersion") == 0)
        {
            memset(newpath,0x0,PARAM_MAX_LENGTH) ;
            sprintf(newpath,"InternetGatewayDevice.ManagementServer.ManageableDevice.%d.HardwareVersion",Instance) ;
            SetConfigValue(newpath , Inform->ParameterList->__ptrParameterValueStruct[i]->Value) ;
        }
        if(strcmp(Inform->ParameterList->__ptrParameterValueStruct[i]->Name,"InternetGatewayDevice.DeviceInfo.SoftwareVersion") == 0)
        {
            memset(newpath,0x0,PARAM_MAX_LENGTH) ;
            sprintf(newpath,"InternetGatewayDevice.ManagementServer.ManageableDevice.%d.SoftwareVersion",Instance) ;
            SetConfigValue(newpath , Inform->ParameterList->__ptrParameterValueStruct[i]->Value) ;
        }
        if(strcmp(Inform->ParameterList->__ptrParameterValueStruct[i]->Name,"InternetGatewayDevice.DeviceInfo.ProvisioningCode") == 0)
        {
            memset(newpath,0x0,PARAM_MAX_LENGTH) ;
            sprintf(newpath,"InternetGatewayDevice.ManagementServer.ManageableDevice.%d.ProvisioningCode",Instance) ;
            SetConfigValue(newpath , Inform->ParameterList->__ptrParameterValueStruct[i]->Value) ;
        }
        if(strcmp(Inform->ParameterList->__ptrParameterValueStruct[i]->Name,"InternetGatewayDevice.ManagementServer.ConnectionRequestURL") == 0)
        {
            memset(newpath,0x0,PARAM_MAX_LENGTH) ;
            sprintf(newpath,"InternetGatewayDevice.ManagementServer.ManageableDevice.%d.ConnectionRequestURL",Instance) ;
            SetConfigValue(newpath , Inform->ParameterList->__ptrParameterValueStruct[i]->Value) ;
        }
        if(strcmp(Inform->ParameterList->__ptrParameterValueStruct[i]->Name,"InternetGatewayDevice.ManagementServer.ConnectionRequestUsername") == 0)
        {
            memset(newpath,0x0,PARAM_MAX_LENGTH) ;
            sprintf(newpath,"InternetGatewayDevice.ManagementServer.ManageableDevice.%d.ConnectionRequestUsername",Instance) ;
            SetConfigValue(newpath , Inform->ParameterList->__ptrParameterValueStruct[i]->Value) ;
        }
        if(strcmp(Inform->ParameterList->__ptrParameterValueStruct[i]->Name,"InternetGatewayDevice.ManagementServer.ConnectionRequestPassword") == 0)
        {
            memset(newpath,0x0,PARAM_MAX_LENGTH) ;
            sprintf(newpath,"InternetGatewayDevice.ManagementServer.ManageableDevice.%d.ConnectionRequestPassword",Instance) ;
            SetConfigValue(newpath , Inform->ParameterList->__ptrParameterValueStruct[i]->Value) ;
        }
        if(strcmp(Inform->ParameterList->__ptrParameterValueStruct[i]->Name,"InternetGatewayDevice.ManagementServer.ParameterKey") == 0)
        {
            memset(newpath,0x0,PARAM_MAX_LENGTH) ;
            sprintf(newpath,"InternetGatewayDevice.ManagementServer.ManageableDevice.%d.ParameterKey",Instance) ;
            SetConfigValue(newpath , Inform->ParameterList->__ptrParameterValueStruct[i]->Value) ;
        }
    }

	Acsconfig.ManageableDeviceNumberOfEntries ++ ;
    sprintf(newpath,"%d",Acsconfig.ManageableDeviceNumberOfEntries) ;
	SetConfigValue("InternetGatewayDevice.ManagementServer.ManageableDeviceNumberOfEntries" , newpath) ;
	free(newpath) ;
	return 0 ;
}

void InformEvent_Handle(struct _cwmp__Inform* Inform)
{
    char rootPath[PARAM_MAX_LENGTH] = "InternetGatewayDevice.ManagementServer.EventAction." ;
    char newPath[PARAM_MAX_LENGTH] ;
    int EventActionNumberOfEntries = 0 ;
    int i = 0 ;
    char *pValue = (char *)malloc(PARAM_MAX_LENGTH) ;
    _GetConfigValue("InternetGatewayDevice.ManagementServer.EventActionNumberOfEntries",pValue) ;
    EventActionNumberOfEntries = atoi(pValue) ;
    memset(RpcNameRes,0x0,sizeof(RpcNameRes)) ;
    cwmp_EventActionID = 0 ;
    for(i = 1 ; i <= EventActionNumberOfEntries ; i ++)
    {
        memset(newPath,0x0,sizeof(newPath)) ;
        snprintf(newPath,sizeof(newPath),"%s%d.EventCode",rootPath,i) ;
        _GetConfigValue(newPath,pValue) ;
        if(strcmp(Inform->Event->__ptrEventStruct[0]->EventCode,pValue) == 0)
        {
	    memset(newPath,0x0,sizeof(newPath)) ;
	    snprintf(newPath,sizeof(newPath),"%s%d.EventResponseNum",rootPath,i) ;
	    _GetConfigValue(newPath,pValue) ;
            memset(newPath,0x0,sizeof(newPath)) ;
            snprintf(newPath,sizeof(newPath),"%s%d.EventResponse.%s.EventString",rootPath,i,pValue) ;
            _GetConfigValue(newPath,pValue) ;
            snprintf(RpcNameRes,sizeof(RpcNameRes),"%s",pValue) ;
	    cwmp_EventActionID = i ;
        }
    }
    free(pValue) ;
    return ;
}
	
void Inform_Handle(struct _cwmp__Inform* Inform)
{
    PRINTF("Entry %s\n",__FUNCTION__) ;
	if(Acsconfig.ManageableDeviceNumberOfEntries >= Acsconfig.ManageableDeviceNotificationLimit)
		return ; // Inform device limited .
    InformEvent_Handle(Inform) ;
	if(Acsconfig.ManageableDeviceNumberOfEntries != 0)
		if(find_InformDevice(Inform,"InternetGatewayDevice.ManagementServer.ManageableDevice","SerialNumber"))
			return ; // already exist .
	
	add_InformDevice(Inform,"InternetGatewayDevice.ManagementServer.ManageableDevice.") ;
	return ;
}


/*******************************************************************************************************/
/*	Below "__cwmp__##RPC## function is use for cwmp client											   */
/*******************************************************************************************************/

int  __cwmp__Inform(
    struct soap *soap ,	  ///soap handle
    struct _cwmp__Inform*              cwmp__Inform,    ///< Input parameter
    struct _cwmp__InformResponse*      cwmp__InformResponse     ///< Output parameter
)
{

	if(__cwmp_Auth(soap,1) != SOAP_OK)
		return 401 ;
#ifdef WITH_COOKIES
    __cwmp_Cookies(soap) ;
#endif

    int i = 0 ;
    PRINTF("\n############### Server RPC SendInform ##############\n") ;

	if(cwmp__Inform)
	{
		Inform_Handle(cwmp__Inform) ;

		PRINTF("[Inform] [Manufacturer] = [%s] \n",cwmp__Inform->DeviceId->Manufacturer) ;
		PRINTF("[Inform] [OUI] = [%s] \n",cwmp__Inform->DeviceId->OUI) ;
		PRINTF("[Inform] [ProductClass] = [%s] \n",cwmp__Inform->DeviceId->ProductClass) ;
		PRINTF("[Inform] [SerialNumber] = [%s] \n",cwmp__Inform->DeviceId->SerialNumber) ;
		for(i = 0 ; i < cwmp__Inform->Event->__size ; i ++)
		{
		    PRINTF("[Inform] [EventCode(%d)] = [%s] \n",i,cwmp__Inform->Event->__ptrEventStruct[i]->EventCode) ;
		    PRINTF("[Inform] [CommandKey(%d)] = [%s] \n",i,cwmp__Inform->Event->__ptrEventStruct[i]->CommandKey) ;
		}
		PRINTF("[Inform] [MaxEnvelopes] = [%d] \n",cwmp__Inform->MaxEnvelopes) ;
		PRINTF("[Inform] [CurrentTime] = [%s] \n",cwmp__Inform->CurrentTime) ;
		PRINTF("[Inform] [RetryCount] = [%d] \n",cwmp__Inform->RetryCount) ;
		for(i = 0 ; i < cwmp__Inform->ParameterList->__size ; i ++)
		{
		    PRINTF("[Inform] [ParameterName(%d)] = [%s] \n",i,cwmp__Inform->ParameterList->__ptrParameterValueStruct[i]->Name) ;

		    PRINTF("[Inform] [ParameterValue(%d)] = [%s] \n",i,cwmp__Inform->ParameterList->__ptrParameterValueStruct[i]->Value) ;
		}
	}
	cwmp__InformResponse->MaxEnvelopes = 1;
	return 0 ;
}

int __cwmp__GetRPCMethods(
    struct soap *soap ,	  ///soap handle
    struct _cwmp__GetRPCMethods*       cwmp__GetRPCMethods,     ///< Input parameter
    struct _cwmp__GetRPCMethodsResponse* cwmp__GetRPCMethodsResponse    ///< Output parameter
)
{
	//PRINTF("Entry %s\n",__FUNCTION__);
    PRINTF("\n############### Server RPC GetRPCMethods ##############\n") ;
	cwmp__GetRPCMethodsResponse->MethodList = (struct cwmp__MethodList*)soap_malloc(soap,sizeof(struct cwmp__MethodList)) ;
	cwmp__GetRPCMethodsResponse->MethodList->__sizestring = 13 ;
	cwmp__GetRPCMethodsResponse->MethodList->string = (char **)soap_malloc(soap,cwmp__GetRPCMethodsResponse->MethodList->__sizestring*sizeof(char *));
	cwmp__GetRPCMethodsResponse->MethodList->string[0] = (char *)soap_strdup(soap,"GetRPCMethods") ;	
	cwmp__GetRPCMethodsResponse->MethodList->string[1] = (char *)soap_strdup(soap,"SetParameterValues") ;
	cwmp__GetRPCMethodsResponse->MethodList->string[2] = (char *)soap_strdup(soap,"GetParameterValues") ;
	cwmp__GetRPCMethodsResponse->MethodList->string[3] = (char *)soap_strdup(soap,"GetParameterNames") ;
	cwmp__GetRPCMethodsResponse->MethodList->string[4] = (char *)soap_strdup(soap,"SetParameterAttributes") ;
	cwmp__GetRPCMethodsResponse->MethodList->string[5] = (char *)soap_strdup(soap,"GetParameterAttributes") ;
	cwmp__GetRPCMethodsResponse->MethodList->string[6] = (char *)soap_strdup(soap,"AddObject") ;
	cwmp__GetRPCMethodsResponse->MethodList->string[7] = (char *)soap_strdup(soap,"DeleteObject") ;
	cwmp__GetRPCMethodsResponse->MethodList->string[8] = (char *)soap_strdup(soap,"Reboot") ;
	cwmp__GetRPCMethodsResponse->MethodList->string[9] = (char *)soap_strdup(soap,"Download") ;
	cwmp__GetRPCMethodsResponse->MethodList->string[10] = (char *)soap_strdup(soap,"ScheduleInform") ;
	cwmp__GetRPCMethodsResponse->MethodList->string[11] = (char *)soap_strdup(soap,"Upload") ;
	cwmp__GetRPCMethodsResponse->MethodList->string[12] = (char *)soap_strdup(soap,"FactoryReset") ;
	return 0 ;
}

int __cwmp__GetParameterValues(
    struct soap *soap ,	  ///soap handle
    struct _cwmp__GetParameterValues*  cwmp__GetParameterValues,        ///< Input parameter
    struct _cwmp__GetParameterValuesResponse* cwmp__GetParameterValuesResponse  ///< Output parameter
)
{
	//PRINTF("Entry %s\n",__FUNCTION__);
    int i = 0 ;
	char * value = (char *)soap_malloc (soap,PARAM_MAX_LENGTH) ;
    PRINTF("\n############### Server RPC GetParameterValues ##############\n") ;
    for(i = 0 ; i < cwmp__GetParameterValues->ParameterNames->__size ; i++)
        PRINTF("[GetParameterValues] [Path] = [%s]\n",cwmp__GetParameterValues->ParameterNames->__ptrstring[i]);
    cwmp__GetParameterValuesResponse->ParameterList = (struct cwmpArrayOfParameterValueStruct *)soap_malloc(soap,sizeof(struct cwmpArrayOfParameterValueStruct)) ;
    cwmp__GetParameterValuesResponse->ParameterList->__size = cwmp__GetParameterValues->ParameterNames->__size ;
    cwmp__GetParameterValuesResponse->ParameterList->__ptrParameterValueStruct = (struct cwmp__ParameterValueStruct **)soap_malloc(soap,(cwmp__GetParameterValuesResponse->ParameterList->__size)*sizeof(struct cwmp__ParameterValueStruct *)) ;

    for(i = 0 ; i < cwmp__GetParameterValuesResponse->ParameterList->__size ; i++)
	{
        cwmp__GetParameterValuesResponse->ParameterList->__ptrParameterValueStruct[i] = (struct cwmp__ParameterValueStruct *)soap_malloc (soap,sizeof(struct cwmp__ParameterValueStruct)) ;
		cwmp__GetParameterValuesResponse->ParameterList->__ptrParameterValueStruct[i]->Name = (char *) soap_strdup(soap,cwmp__GetParameterValues->ParameterNames->__ptrstring[i]);
		if(_GetConfigValue(cwmp__GetParameterValuesResponse->ParameterList->__ptrParameterValueStruct[i]->Name,value)) // if return error , we should add empty to return ;
			cwmp__GetParameterValuesResponse->ParameterList->__ptrParameterValueStruct[i]->Value = (char *) soap_strdup(soap,"") ;
		else
			cwmp__GetParameterValuesResponse->ParameterList->__ptrParameterValueStruct[i]->Value = (char *) soap_strdup(soap,value) ;
	}
    return 0 ;
}


int __cwmp__SetParameterValues(
    struct soap *soap ,	  ///soap handle
    struct _cwmp__SetParameterValues*  cwmp__SetParameterValues,        ///< Input parameter
    struct _cwmp__SetParameterValuesResponse* cwmp__SetParameterValuesResponse  ///< Output parameter
)
{
	//PRINTF("Entry %s\n",__FUNCTION__);
    int i = 0 ;
    PRINTF("\n############### Server RPC SetParameterValues ##############\n") ;
    for(i = 0 ; i < cwmp__SetParameterValues->ParameterList->__size ; i ++)
    {
		SetConfigValue(cwmp__SetParameterValues->ParameterList->__ptrParameterValueStruct[i]->Name , cwmp__SetParameterValues->ParameterList->__ptrParameterValueStruct[i]->Value) ;
        PRINTF("[%s] : ",cwmp__SetParameterValues->ParameterList->__ptrParameterValueStruct[i]->Name);
        PRINTF("[%s]\n",cwmp__SetParameterValues->ParameterList->__ptrParameterValueStruct[i]->Value);
    }

    cwmp__SetParameterValuesResponse->Status = 1 ;
	return 0 ;
}


int cwmp_GetNameList_Num(char * namelist , int index , char * ppath)
{
	memset(ppath,0x0,PARAM_MAX_LENGTH) ;
	return GetSubString(namelist,index,"&",ppath) ;
}

int cwmp_GetNameList(char * path, char * namelist)
{
	int number ;
	memset(namelist,0x0,NAMELIST_MAX_LENGTH) ;
	number = GetConfigNameList(path , namelist) ;
	return number ;
}

int __cwmp__GetParameterNames(
    struct soap *soap ,	  ///soap handle
    struct _cwmp__GetParameterNames*   cwmp__GetParameterNames, ///< Input parameter
    struct _cwmp__GetParameterNamesResponse* cwmp__GetParameterNamesResponse    ///< Output parameter
)
{
	//RINTF("Entry %s\n",__FUNCTION__);
	char * namelist = (char *) soap_malloc(soap,NAMELIST_MAX_LENGTH) ;
	char * pvalue = (char *) soap_malloc(soap,PARAM_MAX_LENGTH) ;
    char pName[PARAM_MAX_LENGTH] ;
    PRINTF("\n############### Server RPC GetParameterNames ##############\n") ;
	PRINTF("[GetParameterNames] [Path] = [%s] , [NextLevel] = [%s]\n",cwmp__GetParameterNames->ParameterPath , cwmp__GetParameterNames->NextLevel);
	struct cwmp__ParameterInfoStruct * parametername = NULL ;
	int i = 0 ;
	cwmp__GetParameterNamesResponse->ParameterList = (struct cwmpArrayOfParameterInfoStruct *) soap_malloc(soap,sizeof(struct cwmpArrayOfParameterInfoStruct)) ;
	
	cwmp__GetParameterNamesResponse->ParameterList->__size = cwmp_GetNameList(cwmp__GetParameterNames->ParameterPath,namelist) ;

	cwmp__GetParameterNamesResponse->ParameterList->__ptrParameterInfoStruct = (struct cwmp__ParameterInfoStruct **)soap_malloc(soap,(cwmp__GetParameterNamesResponse->ParameterList->__size)*sizeof(struct cwmp__ParameterInfoStruct*));

	for(i = 0 ; i < cwmp__GetParameterNamesResponse->ParameterList->__size ; i ++)
	{
		cwmp__GetParameterNamesResponse->ParameterList->__ptrParameterInfoStruct[i] = (struct cwmp__ParameterInfoStruct *)soap_malloc(soap,sizeof(struct cwmp__ParameterInfoStruct));
		if(cwmp_GetNameList_Num(namelist,i+1,pvalue))
			cwmp__GetParameterNamesResponse->ParameterList->__ptrParameterInfoStruct[i]->Name = (char *)soap_strdup(soap,"") ;
		else
			cwmp__GetParameterNamesResponse->ParameterList->__ptrParameterInfoStruct[i]->Name = (char *)soap_strdup(soap,pvalue) ;
		memset(pName,0x0,sizeof(pName)) ;
        sprintf(pName,"%s%s",cwmp__GetParameterNames->ParameterPath,cwmp__GetParameterNamesResponse->ParameterList->__ptrParameterInfoStruct[i]->Name) ;
        if(_GetConfigLevel(pName,pvalue))
			cwmp__GetParameterNamesResponse->ParameterList->__ptrParameterInfoStruct[i]->Writable = 0 ;
		else
			cwmp__GetParameterNamesResponse->ParameterList->__ptrParameterInfoStruct[i]->Writable = atoi(pvalue) ;

	}
	return 0 ;
}


int __cwmp__SetParameterAttributes(
    struct soap *soap ,	  ///soap handle
    struct _cwmp__SetParameterAttributes* cwmp__SetParameterAttributes, ///< Input parameter
    struct _cwmp__SetParameterAttributesResponse* cwmp__SetParameterAttributesResponse  ///< Output parameter
)
{
	//PRINTF("Entry %s\n",__FUNCTION__);
    int i = 0 ;
	char * pvalue = (char *) soap_malloc(soap,PARAM_MAX_LENGTH) ;
    PRINTF("\n############### Server RPC SetParameterAttributes ##############\n") ;
    for(i = 0 ; i < cwmp__SetParameterAttributes->ParameterList->__size ; i ++)
    {
		memset(pvalue,0x0,PARAM_MAX_LENGTH) ;
		sprintf(pvalue,"%d",cwmp__SetParameterAttributes->ParameterList->__ptrSetParameterAttributesStruct[i]->Notification) ;
		SetConfigAttr(cwmp__SetParameterAttributes->ParameterList->__ptrSetParameterAttributesStruct[i]->Name,pvalue,"1") ;
        PRINTF("[%s] : ",cwmp__SetParameterAttributes->ParameterList->__ptrSetParameterAttributesStruct[i]->Name);
        PRINTF("[%d]\n",cwmp__SetParameterAttributes->ParameterList->__ptrSetParameterAttributesStruct[i]->Notification);
    }   
	return 0 ;
}


int __cwmp__GetParameterAttributes(
    struct soap *soap ,	  ///soap handle
    struct _cwmp__GetParameterAttributes* cwmp__GetParameterAttributes, ///< Input parameter
    struct _cwmp__GetParameterAttributesResponse* cwmp__GetParameterAttributesResponse  ///< Output parameter
)
{
	//PRINTF("Entry %s\n",__FUNCTION__);
    int i = 0 ;
	char * pvalue = (char *) soap_malloc(soap,PARAM_MAX_LENGTH) ;
    PRINTF("\n############### Server RPC GetParameterAttributes ##############\n") ;
    for(i = 0 ; i < cwmp__GetParameterAttributes->ParameterNames->__size ; i++)
        PRINTF("[GetParameterAttributes] [Path] = [%s]\n",cwmp__GetParameterAttributes->ParameterNames->__ptrstring[i]);
    
	cwmp__GetParameterAttributesResponse->ParameterList = (struct cwmpArrayOfParameterAttributeStruct *)soap_malloc(soap,sizeof(struct cwmpArrayOfParameterAttributeStruct)) ;
    cwmp__GetParameterAttributesResponse->ParameterList->__size = cwmp__GetParameterAttributes->ParameterNames->__size ;
    cwmp__GetParameterAttributesResponse->ParameterList->__ptrParameterAttributeStruct = (struct cwmp__ParameterAttributeStruct **)soap_malloc(soap,(cwmp__GetParameterAttributesResponse->ParameterList->__size)*sizeof(struct cwmp__ParameterAttributeStruct *)) ;

    for(i = 0 ; i < cwmp__GetParameterAttributesResponse->ParameterList->__size ; i++)
	{
        cwmp__GetParameterAttributesResponse->ParameterList->__ptrParameterAttributeStruct[i] = (struct cwmp__ParameterAttributeStruct *)soap_malloc (soap,sizeof(struct cwmp__ParameterAttributeStruct)) ;
		cwmp__GetParameterAttributesResponse->ParameterList->__ptrParameterAttributeStruct[i]->Name = (char *) soap_strdup(soap,cwmp__GetParameterAttributes->ParameterNames->__ptrstring[i]);
		if(_GetConfigAttr(cwmp__GetParameterAttributesResponse->ParameterList->__ptrParameterAttributeStruct[i]->Name,pvalue))
			cwmp__GetParameterAttributesResponse->ParameterList->__ptrParameterAttributeStruct[i]->Notification = 0 ;
		else
			cwmp__GetParameterAttributesResponse->ParameterList->__ptrParameterAttributeStruct[i]->Notification = atoi(pvalue) ;
		cwmp__GetParameterAttributesResponse->ParameterList->__ptrParameterAttributeStruct[i]->AccessList = NULL ;
	}

    return 0 ;
}


int __cwmp__AddObject(
    struct soap *soap ,	  ///soap handle
    struct _cwmp__AddObject*           cwmp__AddObject, ///< Input parameter
    struct _cwmp__AddObjectResponse*   cwmp__AddObjectResponse  ///< Output parameter
)
{
	//PRINTF("Entry %s\n",__FUNCTION__);
    PRINTF("\n############### Server RPC AddObject ##############\n") ;
    PRINTF("[AddObject] [Path] = [%s] , [ParameterKey] = [%s]\n",cwmp__AddObject->ObjectName , cwmp__AddObject->ParameterKey) ;
    
    cwmp__AddObjectResponse->InstanceNumber = AddInstanceXML(cwmp__AddObject->ObjectName) ;
	if(cwmp__AddObjectResponse->InstanceNumber) // 0 : failed 
    	cwmp__AddObjectResponse->Status = 0 ;
	else
		cwmp__AddObjectResponse->Status = 1 ;

	return 0 ;
}


int __cwmp__DeleteObject(
    struct soap *soap ,	  ///soap handle
    struct _cwmp__DeleteObject*        cwmp__DeleteObject,      ///< Input parameter
    struct _cwmp__DeleteObjectResponse* cwmp__DeleteObjectResponse      ///< Output parameter
)
{
	//PRINTF("Entry %s\n",__FUNCTION__);
    PRINTF("\n############### Server RPC DeleteObject ##############\n") ;
    PRINTF("[DeleteObject] [Path] = [%s] , [ParameterKey] = [%s]\n",cwmp__DeleteObject->ObjectName , cwmp__DeleteObject->ParameterKey) ;
    if(DelInstanceXML(cwmp__DeleteObject->ObjectName)) // 0 : success , 1 : failed .
    	cwmp__DeleteObjectResponse->Status = 1 ;
	else
		cwmp__DeleteObjectResponse->Status = 0 ;
	return 0 ;
}


int __cwmp__Reboot(
    struct soap *soap ,	  ///soap handle
    struct _cwmp__Reboot*              cwmp__Reboot,    ///< Input parameter
    struct _cwmp__RebootResponse*      cwmp__RebootResponse     ///< Output parameter
)
{
	//PRINTF("Entry %s\n",__FUNCTION__);
    PRINTF("\n############### Server RPC Reboot ##############\n") ;
    PRINTF("[Reboot] [CommandKey] = [%s]\n",cwmp__Reboot->CommandKey) ;

	return 0 ;
}


int __cwmp__Download(
    struct soap *soap ,	  ///soap handle
    struct _cwmp__Download*            cwmp__Download,  ///< Input parameter
    struct _cwmp__DownloadResponse*    cwmp__DownloadResponse   ///< Output parameter
)
{
	//PRINTF("Entry %s\n",__FUNCTION__);
    PRINTF("\n############### Server RPC Download ##############\n") ;
    PRINTF("[Download] [CommandKey] = [%s]\n",cwmp__Download->CommandKey) ;
    PRINTF("[Download] [FileType] = [%s]\n",cwmp__Download->FileType) ;
    PRINTF("[Download] [URL] = [%s]\n",cwmp__Download->URL) ;
    PRINTF("[Download] [Username] = [%s]\n",cwmp__Download->Username) ;
    PRINTF("[Download] [Password] = [%s]\n",cwmp__Download->Password) ;
    PRINTF("[Download] [FileSize] = [%d]\n",cwmp__Download->FileSize) ;
    PRINTF("[Download] [TargetFileName] = [%s]\n",cwmp__Download->TargetFileName) ;
    PRINTF("[Download] [DelaySeconds] = [%d]\n",cwmp__Download->DelaySeconds) ;
    PRINTF("[Download] [SuccessURL] = [%s]\n",cwmp__Download->SuccessURL) ;
    PRINTF("[Download] [FailureURL] = [%s]\n",cwmp__Download->FailureURL) ;

	return 0 ;
}


int __cwmp__Upload(
    struct soap *soap ,	  ///soap handle
    struct _cwmp__Upload*              cwmp__Upload,    ///< Input parameter
    struct _cwmp__UploadResponse*      cwmp__UploadResponse     ///< Output parameter
)
{
	//PRINTF("Entry %s\n",__FUNCTION__);
    PRINTF("\n############### Server RPC Download ##############\n") ;
    PRINTF("[Download] [CommandKey] = [%s]\n",cwmp__Upload->CommandKey) ;
    PRINTF("[Download] [FileType] = [%s]\n",cwmp__Upload->FileType) ;
    PRINTF("[Download] [URL] = [%s]\n",cwmp__Upload->URL) ;
    PRINTF("[Download] [Username] = [%s]\n",cwmp__Upload->Username) ;
    PRINTF("[Download] [Password] = [%s]\n",cwmp__Upload->Password) ;
    PRINTF("[Download] [DelaySeconds] = [%d]\n",cwmp__Upload->DelaySeconds) ;

	return 0 ;
}


int __cwmp__FactoryReset(
    struct soap *soap ,	  ///soap handle
    struct _cwmp__FactoryReset*        cwmp__FactoryReset,      ///< Input parameter
    struct _cwmp__FactoryResetResponse* cwmp__FactoryResetResponse      ///< Output parameter
)
{
	//PRINTF("Entry %s\n",__FUNCTION__);
    PRINTF("\n############### Server RPC FactoryReset ##############\n") ;
	return 0 ;
}


int __cwmp__ScheduleInform(
    struct soap *soap ,	  ///soap handle
    struct _cwmp__ScheduleInform*      cwmp__ScheduleInform,    ///< Input parameter
    struct _cwmp__ScheduleInformResponse* cwmp__ScheduleInformResponse  ///< Output parameter
)
{
	//PRINTF("Entry %s\n",__FUNCTION__);
    PRINTF("\n############### Server RPC ScheduleInform ##############\n") ;
    PRINTF("[ScheduleInform] [DelaySeconds] = [%d]\n",cwmp__ScheduleInform->DelaySeconds) ;
    PRINTF("[ScheduleInform] [CommandKey] = [%s]\n",cwmp__ScheduleInform->CommandKey) ;
	return 0 ;
}


int __cwmp__TranferComplete(
    struct soap *soap ,	  ///soap handle
    struct _cwmp__TranferComplete*     cwmp__TranferComplete,   ///< Input parameter
    struct _cwmp__TranferCompleteResponse* cwmp__TranferCompleteResponse        ///< Output parameter
)
{
	//PRINTF("Entry %s\n",__FUNCTION__);
    PRINTF("\n############### Server RPC TranferComplete ##############\n") ;
    PRINTF("[TranferComplete] [CommandKey] = [%s]\n",cwmp__TranferComplete->CommandKey) ;
    PRINTF("[TranferComplete] [StartTime] = [%ld]\n",cwmp__TranferComplete->StartTime) ;
    PRINTF("[TranferComplete] [CompleteTime] = [%ld]\n",cwmp__TranferComplete->CompleteTime) ;
    PRINTF("[TranferComplete] [FaultCode] = [%s]\n",cwmp__TranferComplete->FaultStruct->FaultCode) ;
    PRINTF("[TranferComplete] [FaultString] = [%s]\n",cwmp__TranferComplete->FaultStruct->FaultString) ;
	return 0 ;
}


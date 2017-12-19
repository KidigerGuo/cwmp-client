#include "cwmpDebug.h"
#include "stdsoap2.h"
#include "soapH.h"
#include "soapStub.h"
//#include "Cwmp.nsmap"
#if defined (WITH_OPENSSL)
#if defined (DIGEST_AUTH)
#include "httpda.h" 	/* optionally enable HTTP Digest Authentication */
#endif
#endif

#ifdef SUPPORT_EMPTYPOST
#ifdef SUPPORT_EMPTYPOST_REQ

SOAP_FMAC5 int SOAP_FMAC6 __soap_serve___cwmp__Inform(struct soap *soap, const char *soap_endpoint)
{	struct __cwmp__Inform soap_tmp___cwmp__Inform;
	struct _cwmp__InformResponse cwmp__InformResponse;
	soap_default__cwmp__InformResponse(soap, &cwmp__InformResponse);
	soap_default___cwmp__Inform(soap, &soap_tmp___cwmp__Inform);
	if (!soap_get___cwmp__Inform(soap, &soap_tmp___cwmp__Inform, "-cwmp:Inform", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __cwmp__Inform(soap, soap_tmp___cwmp__Inform.cwmp__Inform, &cwmp__InformResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL;
	soap_serializeheader(soap);
	soap_serialize__cwmp__InformResponse(soap, &cwmp__InformResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put__cwmp__InformResponse(soap, &cwmp__InformResponse, "cwmp:InformResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_connect(soap, soap_url(soap, soap_endpoint, NULL), "InformResponse")//soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put__cwmp__InformResponse(soap, &cwmp__InformResponse, "cwmp:InformResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __soap_serve___cwmp__GetRPCMethods(struct soap *soap, const char *soap_endpoint)
{	struct __cwmp__GetRPCMethods soap_tmp___cwmp__GetRPCMethods;
	struct _cwmp__GetRPCMethodsResponse cwmp__GetRPCMethodsResponse;
	soap_default__cwmp__GetRPCMethodsResponse(soap, &cwmp__GetRPCMethodsResponse);
	soap_default___cwmp__GetRPCMethods(soap, &soap_tmp___cwmp__GetRPCMethods);
	if (!soap_get___cwmp__GetRPCMethods(soap, &soap_tmp___cwmp__GetRPCMethods, "-cwmp:GetRPCMethods", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __cwmp__GetRPCMethods(soap, soap_tmp___cwmp__GetRPCMethods.cwmp__GetRPCMethods, &cwmp__GetRPCMethodsResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL;
	soap_serializeheader(soap);
	soap_serialize__cwmp__GetRPCMethodsResponse(soap, &cwmp__GetRPCMethodsResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put__cwmp__GetRPCMethodsResponse(soap, &cwmp__GetRPCMethodsResponse, "cwmp:GetRPCMethodsResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_connect(soap, soap_url(soap, soap_endpoint, NULL), "GetRPCMethodsResponse")//soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put__cwmp__GetRPCMethodsResponse(soap, &cwmp__GetRPCMethodsResponse, "cwmp:GetRPCMethodsResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __soap_serve___cwmp__GetParameterValues(struct soap *soap, const char *soap_endpoint)
{	struct __cwmp__GetParameterValues soap_tmp___cwmp__GetParameterValues;
	struct _cwmp__GetParameterValuesResponse cwmp__GetParameterValuesResponse;
	soap_default__cwmp__GetParameterValuesResponse(soap, &cwmp__GetParameterValuesResponse);
	soap_default___cwmp__GetParameterValues(soap, &soap_tmp___cwmp__GetParameterValues);
	if (!soap_get___cwmp__GetParameterValues(soap, &soap_tmp___cwmp__GetParameterValues, "-cwmp:GetParameterValues", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __cwmp__GetParameterValues(soap, soap_tmp___cwmp__GetParameterValues.cwmp__GetParameterValues, &cwmp__GetParameterValuesResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL;
	soap_serializeheader(soap);
	soap_serialize__cwmp__GetParameterValuesResponse(soap, &cwmp__GetParameterValuesResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put__cwmp__GetParameterValuesResponse(soap, &cwmp__GetParameterValuesResponse, "cwmp:GetParameterValuesResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_connect(soap, soap_url(soap, soap_endpoint, NULL), "GetParameterValuesResponse")//soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put__cwmp__GetParameterValuesResponse(soap, &cwmp__GetParameterValuesResponse, "cwmp:GetParameterValuesResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __soap_serve___cwmp__SetParameterValues(struct soap *soap, const char *soap_endpoint)
{	struct __cwmp__SetParameterValues soap_tmp___cwmp__SetParameterValues;
	struct _cwmp__SetParameterValuesResponse cwmp__SetParameterValuesResponse;
	soap_default__cwmp__SetParameterValuesResponse(soap, &cwmp__SetParameterValuesResponse);
	soap_default___cwmp__SetParameterValues(soap, &soap_tmp___cwmp__SetParameterValues);
	if (!soap_get___cwmp__SetParameterValues(soap, &soap_tmp___cwmp__SetParameterValues, "-cwmp:SetParameterValues", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __cwmp__SetParameterValues(soap, soap_tmp___cwmp__SetParameterValues.cwmp__SetParameterValues, &cwmp__SetParameterValuesResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL;
	soap_serializeheader(soap);
	soap_serialize__cwmp__SetParameterValuesResponse(soap, &cwmp__SetParameterValuesResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put__cwmp__SetParameterValuesResponse(soap, &cwmp__SetParameterValuesResponse, "cwmp:SetParameterValuesResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_connect(soap, soap_url(soap, soap_endpoint, NULL), "SetParameterValuesResponse")//soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put__cwmp__SetParameterValuesResponse(soap, &cwmp__SetParameterValuesResponse, "cwmp:SetParameterValuesResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __soap_serve___cwmp__GetParameterNames(struct soap *soap, const char *soap_endpoint)
{	struct __cwmp__GetParameterNames soap_tmp___cwmp__GetParameterNames;
	struct _cwmp__GetParameterNamesResponse cwmp__GetParameterNamesResponse;
	soap_default__cwmp__GetParameterNamesResponse(soap, &cwmp__GetParameterNamesResponse);
	soap_default___cwmp__GetParameterNames(soap, &soap_tmp___cwmp__GetParameterNames);
	if (!soap_get___cwmp__GetParameterNames(soap, &soap_tmp___cwmp__GetParameterNames, "-cwmp:GetParameterNames", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __cwmp__GetParameterNames(soap, soap_tmp___cwmp__GetParameterNames.cwmp__GetParameterNames, &cwmp__GetParameterNamesResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL;
	soap_serializeheader(soap);
	soap_serialize__cwmp__GetParameterNamesResponse(soap, &cwmp__GetParameterNamesResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put__cwmp__GetParameterNamesResponse(soap, &cwmp__GetParameterNamesResponse, "cwmp:GetParameterNamesResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_connect(soap, soap_url(soap, soap_endpoint, NULL), "GetParameterNamesResponse")//soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put__cwmp__GetParameterNamesResponse(soap, &cwmp__GetParameterNamesResponse, "cwmp:GetParameterNamesResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __soap_serve___cwmp__SetParameterAttributes(struct soap *soap, const char *soap_endpoint)
{	struct __cwmp__SetParameterAttributes soap_tmp___cwmp__SetParameterAttributes;
	struct _cwmp__SetParameterAttributesResponse cwmp__SetParameterAttributesResponse;
	soap_default__cwmp__SetParameterAttributesResponse(soap, &cwmp__SetParameterAttributesResponse);
	soap_default___cwmp__SetParameterAttributes(soap, &soap_tmp___cwmp__SetParameterAttributes);
	if (!soap_get___cwmp__SetParameterAttributes(soap, &soap_tmp___cwmp__SetParameterAttributes, "-cwmp:SetParameterAttributes", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __cwmp__SetParameterAttributes(soap, soap_tmp___cwmp__SetParameterAttributes.cwmp__SetParameterAttributes, &cwmp__SetParameterAttributesResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL;
	soap_serializeheader(soap);
	soap_serialize__cwmp__SetParameterAttributesResponse(soap, &cwmp__SetParameterAttributesResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put__cwmp__SetParameterAttributesResponse(soap, &cwmp__SetParameterAttributesResponse, "cwmp:SetParameterAttributesResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_connect(soap, soap_url(soap, soap_endpoint, NULL), "SetParameterAttributesResponse")//soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put__cwmp__SetParameterAttributesResponse(soap, &cwmp__SetParameterAttributesResponse, "cwmp:SetParameterAttributesResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __soap_serve___cwmp__GetParameterAttributes(struct soap *soap, const char *soap_endpoint)
{	struct __cwmp__GetParameterAttributes soap_tmp___cwmp__GetParameterAttributes;
	struct _cwmp__GetParameterAttributesResponse cwmp__GetParameterAttributesResponse;
	soap_default__cwmp__GetParameterAttributesResponse(soap, &cwmp__GetParameterAttributesResponse);
	soap_default___cwmp__GetParameterAttributes(soap, &soap_tmp___cwmp__GetParameterAttributes);
	if (!soap_get___cwmp__GetParameterAttributes(soap, &soap_tmp___cwmp__GetParameterAttributes, "-cwmp:GetParameterAttributes", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __cwmp__GetParameterAttributes(soap, soap_tmp___cwmp__GetParameterAttributes.cwmp__GetParameterAttributes, &cwmp__GetParameterAttributesResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL;
	soap_serializeheader(soap);
	soap_serialize__cwmp__GetParameterAttributesResponse(soap, &cwmp__GetParameterAttributesResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put__cwmp__GetParameterAttributesResponse(soap, &cwmp__GetParameterAttributesResponse, "cwmp:GetParameterAttributesResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_connect(soap, soap_url(soap, soap_endpoint, NULL), "GetParameterAttributesResponse")//soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put__cwmp__GetParameterAttributesResponse(soap, &cwmp__GetParameterAttributesResponse, "cwmp:GetParameterAttributesResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __soap_serve___cwmp__AddObject(struct soap *soap, const char *soap_endpoint)
{	struct __cwmp__AddObject soap_tmp___cwmp__AddObject;
	struct _cwmp__AddObjectResponse cwmp__AddObjectResponse;
	soap_default__cwmp__AddObjectResponse(soap, &cwmp__AddObjectResponse);
	soap_default___cwmp__AddObject(soap, &soap_tmp___cwmp__AddObject);
	if (!soap_get___cwmp__AddObject(soap, &soap_tmp___cwmp__AddObject, "-cwmp:AddObject", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __cwmp__AddObject(soap, soap_tmp___cwmp__AddObject.cwmp__AddObject, &cwmp__AddObjectResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL;
	soap_serializeheader(soap);
	soap_serialize__cwmp__AddObjectResponse(soap, &cwmp__AddObjectResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put__cwmp__AddObjectResponse(soap, &cwmp__AddObjectResponse, "cwmp:AddObjectResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_connect(soap, soap_url(soap, soap_endpoint, NULL), "AddObjectResponse")//soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put__cwmp__AddObjectResponse(soap, &cwmp__AddObjectResponse, "cwmp:AddObjectResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __soap_serve___cwmp__DeleteObject(struct soap *soap, const char *soap_endpoint)
{	struct __cwmp__DeleteObject soap_tmp___cwmp__DeleteObject;
	struct _cwmp__DeleteObjectResponse cwmp__DeleteObjectResponse;
	soap_default__cwmp__DeleteObjectResponse(soap, &cwmp__DeleteObjectResponse);
	soap_default___cwmp__DeleteObject(soap, &soap_tmp___cwmp__DeleteObject);
	if (!soap_get___cwmp__DeleteObject(soap, &soap_tmp___cwmp__DeleteObject, "-cwmp:DeleteObject", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __cwmp__DeleteObject(soap, soap_tmp___cwmp__DeleteObject.cwmp__DeleteObject, &cwmp__DeleteObjectResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL;
	soap_serializeheader(soap);
	soap_serialize__cwmp__DeleteObjectResponse(soap, &cwmp__DeleteObjectResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put__cwmp__DeleteObjectResponse(soap, &cwmp__DeleteObjectResponse, "cwmp:DeleteObjectResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_connect(soap, soap_url(soap, soap_endpoint, NULL), "DeleteObjectResponse")//soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put__cwmp__DeleteObjectResponse(soap, &cwmp__DeleteObjectResponse, "cwmp:DeleteObjectResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __soap_serve___cwmp__Reboot(struct soap *soap, const char *soap_endpoint)
{	struct __cwmp__Reboot soap_tmp___cwmp__Reboot;
	struct _cwmp__RebootResponse cwmp__RebootResponse;
	soap_default__cwmp__RebootResponse(soap, &cwmp__RebootResponse);
	soap_default___cwmp__Reboot(soap, &soap_tmp___cwmp__Reboot);
	if (!soap_get___cwmp__Reboot(soap, &soap_tmp___cwmp__Reboot, "-cwmp:Reboot", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __cwmp__Reboot(soap, soap_tmp___cwmp__Reboot.cwmp__Reboot, &cwmp__RebootResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL;
	soap_serializeheader(soap);
	soap_serialize__cwmp__RebootResponse(soap, &cwmp__RebootResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put__cwmp__RebootResponse(soap, &cwmp__RebootResponse, "cwmp:RebootResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_connect(soap, soap_url(soap, soap_endpoint, NULL), "RebootResponse")//soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put__cwmp__RebootResponse(soap, &cwmp__RebootResponse, "cwmp:RebootResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __soap_serve___cwmp__Download(struct soap *soap, const char *soap_endpoint)
{	struct __cwmp__Download soap_tmp___cwmp__Download;
	struct _cwmp__DownloadResponse cwmp__DownloadResponse;
	soap_default__cwmp__DownloadResponse(soap, &cwmp__DownloadResponse);
	soap_default___cwmp__Download(soap, &soap_tmp___cwmp__Download);
	if (!soap_get___cwmp__Download(soap, &soap_tmp___cwmp__Download, "-cwmp:Download", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __cwmp__Download(soap, soap_tmp___cwmp__Download.cwmp__Download, &cwmp__DownloadResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL;
	soap_serializeheader(soap);
	soap_serialize__cwmp__DownloadResponse(soap, &cwmp__DownloadResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put__cwmp__DownloadResponse(soap, &cwmp__DownloadResponse, "cwmp:DownloadResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_connect(soap, soap_url(soap, soap_endpoint, NULL), "DownloadResponse")//soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put__cwmp__DownloadResponse(soap, &cwmp__DownloadResponse, "cwmp:DownloadResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __soap_serve___cwmp__Upload(struct soap *soap, const char *soap_endpoint)
{	struct __cwmp__Upload soap_tmp___cwmp__Upload;
	struct _cwmp__UploadResponse cwmp__UploadResponse;
	soap_default__cwmp__UploadResponse(soap, &cwmp__UploadResponse);
	soap_default___cwmp__Upload(soap, &soap_tmp___cwmp__Upload);
	if (!soap_get___cwmp__Upload(soap, &soap_tmp___cwmp__Upload, "-cwmp:Upload", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __cwmp__Upload(soap, soap_tmp___cwmp__Upload.cwmp__Upload, &cwmp__UploadResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL;
	soap_serializeheader(soap);
	soap_serialize__cwmp__UploadResponse(soap, &cwmp__UploadResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put__cwmp__UploadResponse(soap, &cwmp__UploadResponse, "cwmp:UploadResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_connect(soap, soap_url(soap, soap_endpoint, NULL), "UploadResponse")//soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put__cwmp__UploadResponse(soap, &cwmp__UploadResponse, "cwmp:UploadResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __soap_serve___cwmp__FactoryReset(struct soap *soap , const char *soap_endpoint)
{	struct __cwmp__FactoryReset soap_tmp___cwmp__FactoryReset;
	struct _cwmp__FactoryResetResponse cwmp__FactoryResetResponse;
	soap_default__cwmp__FactoryResetResponse(soap, &cwmp__FactoryResetResponse);
	soap_default___cwmp__FactoryReset(soap, &soap_tmp___cwmp__FactoryReset);
	if (!soap_get___cwmp__FactoryReset(soap, &soap_tmp___cwmp__FactoryReset, "-cwmp:FactoryReset", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __cwmp__FactoryReset(soap, soap_tmp___cwmp__FactoryReset.cwmp__FactoryReset, &cwmp__FactoryResetResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL;
	soap_serializeheader(soap);
	soap_serialize__cwmp__FactoryResetResponse(soap, &cwmp__FactoryResetResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put__cwmp__FactoryResetResponse(soap, &cwmp__FactoryResetResponse, "cwmp:FactoryResetResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_connect(soap, soap_url(soap, soap_endpoint, NULL), "FactoryResetResponse")//soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put__cwmp__FactoryResetResponse(soap, &cwmp__FactoryResetResponse, "cwmp:FactoryResetResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}


SOAP_FMAC5 int SOAP_FMAC6 __soap_serve___cwmp__ScheduleInform(struct soap *soap, const char *soap_endpoint)
{	struct __cwmp__ScheduleInform soap_tmp___cwmp__ScheduleInform;
	struct _cwmp__ScheduleInformResponse cwmp__ScheduleInformResponse;
	soap_default__cwmp__ScheduleInformResponse(soap, &cwmp__ScheduleInformResponse);
	soap_default___cwmp__ScheduleInform(soap, &soap_tmp___cwmp__ScheduleInform);
	if (!soap_get___cwmp__ScheduleInform(soap, &soap_tmp___cwmp__ScheduleInform, "-cwmp:ScheduleInform", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __cwmp__ScheduleInform(soap, soap_tmp___cwmp__ScheduleInform.cwmp__ScheduleInform, &cwmp__ScheduleInformResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL;
	soap_serializeheader(soap);
	soap_serialize__cwmp__ScheduleInformResponse(soap, &cwmp__ScheduleInformResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put__cwmp__ScheduleInformResponse(soap, &cwmp__ScheduleInformResponse, "cwmp:ScheduleInformResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_connect(soap, soap_url(soap, soap_endpoint, NULL), "ScheduleInformResponse")//soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put__cwmp__ScheduleInformResponse(soap, &cwmp__ScheduleInformResponse, "cwmp:ScheduleInformResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}

SOAP_FMAC5 int SOAP_FMAC6 __soap_serve___cwmp__TranferComplete(struct soap *soap, const char *soap_endpoint)
{	struct __cwmp__TranferComplete soap_tmp___cwmp__TranferComplete;
	struct _cwmp__TranferCompleteResponse cwmp__TranferCompleteResponse;
	soap_default__cwmp__TranferCompleteResponse(soap, &cwmp__TranferCompleteResponse);
	soap_default___cwmp__TranferComplete(soap, &soap_tmp___cwmp__TranferComplete);
	if (!soap_get___cwmp__TranferComplete(soap, &soap_tmp___cwmp__TranferComplete, "-cwmp:TranferComplete", NULL))
		return soap->error;
	if (soap_body_end_in(soap)
	 || soap_envelope_end_in(soap)
	 || soap_end_recv(soap))
		return soap->error;
	soap->error = __cwmp__TranferComplete(soap, soap_tmp___cwmp__TranferComplete.cwmp__TranferComplete, &cwmp__TranferCompleteResponse);
	if (soap->error)
		return soap->error;
	soap->encodingStyle = NULL;
	soap_serializeheader(soap);
	soap_serialize__cwmp__TranferCompleteResponse(soap, &cwmp__TranferCompleteResponse);
	if (soap_begin_count(soap))
		return soap->error;
	if (soap->mode & SOAP_IO_LENGTH)
	{	if (soap_envelope_begin_out(soap)
		 || soap_putheader(soap)
		 || soap_body_begin_out(soap)
		 || soap_put__cwmp__TranferCompleteResponse(soap, &cwmp__TranferCompleteResponse, "cwmp:TranferCompleteResponse", NULL)
		 || soap_body_end_out(soap)
		 || soap_envelope_end_out(soap))
			 return soap->error;
	};
	if (soap_end_count(soap)
	 || soap_connect(soap, soap_url(soap, soap_endpoint, NULL), "TranferCompleteResponse")//soap_response(soap, SOAP_OK)
	 || soap_envelope_begin_out(soap)
	 || soap_putheader(soap)
	 || soap_body_begin_out(soap)
	 || soap_put__cwmp__TranferCompleteResponse(soap, &cwmp__TranferCompleteResponse, "cwmp:TranferCompleteResponse", NULL)
	 || soap_body_end_out(soap)
	 || soap_envelope_end_out(soap)
	 || soap_end_send(soap))
		return soap->error;
	return soap_closesock(soap);
}


SOAP_FMAC5 int SOAP_FMAC6 __soap_serve_request(struct soap *soap , const char * Server)
{
	soap_peek_element(soap);
	if (!soap_match_tag(soap, soap->tag, "cwmp:Inform"))
		return __soap_serve___cwmp__Inform(soap,Server);
	if (!soap_match_tag(soap, soap->tag, "cwmp:GetRPCMethods"))
		return __soap_serve___cwmp__GetRPCMethods(soap,Server);
	if (!soap_match_tag(soap, soap->tag, "cwmp:GetParameterValues"))
		return __soap_serve___cwmp__GetParameterValues(soap,Server);
	if (!soap_match_tag(soap, soap->tag, "cwmp:SetParameterValues"))
		return __soap_serve___cwmp__SetParameterValues(soap,Server);
	if (!soap_match_tag(soap, soap->tag, "cwmp:GetParameterNames"))
		return __soap_serve___cwmp__GetParameterNames(soap,Server);
	if (!soap_match_tag(soap, soap->tag, "cwmp:SetParameterAttributes"))
		return __soap_serve___cwmp__SetParameterAttributes(soap,Server);
	if (!soap_match_tag(soap, soap->tag, "cwmp:GetParameterAttributes"))
		return __soap_serve___cwmp__GetParameterAttributes(soap,Server);
	if (!soap_match_tag(soap, soap->tag, "cwmp:AddObject"))
		return __soap_serve___cwmp__AddObject(soap,Server);
	if (!soap_match_tag(soap, soap->tag, "cwmp:DeleteObject"))
		return __soap_serve___cwmp__DeleteObject(soap,Server);
	if (!soap_match_tag(soap, soap->tag, "cwmp:Reboot"))
		return __soap_serve___cwmp__Reboot(soap,Server);
	if (!soap_match_tag(soap, soap->tag, "cwmp:Download"))
		return __soap_serve___cwmp__Download(soap,Server);
	if (!soap_match_tag(soap, soap->tag, "cwmp:Upload"))
		return __soap_serve___cwmp__Upload(soap,Server);
	if (!soap_match_tag(soap, soap->tag, "cwmp:FactoryReset"))
		return __soap_serve___cwmp__FactoryReset(soap,Server);
	if (!soap_match_tag(soap, soap->tag, "cwmp:ScheduleInform"))
		return __soap_serve___cwmp__ScheduleInform(soap,Server);
	if (!soap_match_tag(soap, soap->tag, "cwmp:TranferComplete"))
		return __soap_serve___cwmp__TranferComplete(soap,Server);
	return soap->error = SOAP_NO_METHOD;
}




#endif
#endif

#if defined (HTTP_GET)
#ifdef SERVER_CONNECT_RES

int cwmp_EmptyGet(struct soap * soap , const char * Server)
{	
	int AuthMode = 0 ;

    while(1)
    {
        soap_begin(soap);
        __Cwmp_Auth_Adapter(soap,AuthMode) ;
        if (soap_get_connect(soap, Server, "")
	     || soap_begin_recv(soap))
        {
            if(soap->error == 401)
            {
                PRINTF("ACS Server return 401 , need authentication \n") ;
                if (AuthMode < 2)
                    AuthMode ++ ;
                else
                {
                    soap_print_fault(soap, stderr);
				    soap_end(soap);
                    return 1 ;
                }
            }else if(soap->error == 204)
            {
                PRINTF("ACS server return 204 , this session is finished .\n") ;
	            soap_end(soap);
                return 0 ;
            }else if (soap->error == 200) // ACS return 200 but no content , so we think it's terminal .
	        {
			    PRINTF("ACS server return 200 , this session is finished .\n") ;
			    soap_end(soap);
                return 0 ;
		    }else
            {
                PRINTF("ACS server retrun %d , unknow code , session finished .\n",soap->error) ;
			    soap_print_fault(soap, stderr);
			    soap_end(soap);
                return 1 ;
            }
        }
    }
}

#endif
#endif

#ifdef BASIC_AUTH
void cwmp_BasicAuth(struct soap * soap , char * Userid , char * Passwd)
{
	PRINTF("Entry %s\n",__FUNCTION__) ;
	soap->userid = (char *)soap_strdup(soap,Userid) ;
	soap->passwd = (char *)soap_strdup(soap,Passwd) ;
	return ;
}
#endif
#if defined(WITH_OPENSSL)
#if defined(DIGEST_AUTH)
void cwmp_DigestAuth(struct soap * soap , char * Userid , char * Passwd , char * Realm)
{
	PRINTF("Entry %s\n",__FUNCTION__) ;
	struct http_da_info info;
	cwmp_BasicAuth(soap,Userid,Passwd) ;
	soap->authrealm = (char *)soap_strdup(soap,Realm) ;	
  	http_da_save(soap, &info, Realm, Userid, Passwd);
	return ;
}
#endif
#endif

#ifdef SUPPORT_EMPTYPOST
int cwmp_EmptyPost(struct soap * soap , const char * Server)
{	

	int result = 0 ;
	soap->length = 0;
    soap->count = 0;

    if(soap_connect(soap, Server, "")
     ||soap_end_send(soap))
	{
		soap_print_fault(soap,stderr);
		exit(1) ;
	}
	do
	{
		if (soap_begin_recv(soap)
	     || soap_envelope_begin_in(soap)
	     || soap_recv_header(soap)
	     || soap_body_begin_in(soap))
		{
			if (soap->error == 204) // terminal by ACS server .
			{
				PRINTF("ACS server return 204 , this session is finished .\n") ;
	            soap_end(soap);
			}
			else if (soap->error == 200) // ACS return 200 but no content , so we think it's terminal .
			{
				PRINTF("ACS server return 200 , this session is finished .\n") ;
				soap_end(soap);
			}
			else
			{
				PRINTF("ACS server retrun %d , unknow code , session finished .\n",soap->error) ;
				soap_print_fault(soap, stderr);
				soap_end(soap);
			}
			return SOAP_OK ;
		}
#ifdef SUPPORT_EMPTYPOST_REQ
	}while(__soap_serve_request(soap,Server) != SOAP_NO_METHOD) ;
#else
	}while(0) ;
#endif
	soap_end(soap);
	return SOAP_OK ;
}
#endif

int cwmp_Inform(struct soap * soap ,const char * Server , char ** DeviceEventInfo , char * CurrentTime , char ** ParameterNameList , char ** ParameterValueList , int * OtherOption)
{
    //PRINTF("Entry %s\n",__FUNCTION__);

    int result = 0 ;
    int i = 0 ;
    struct _cwmp__Inform* Inform ;
    struct _cwmp__InformResponse InformResponse;

    Inform =  (struct _cwmp__Inform *) soap_malloc(soap,sizeof(struct _cwmp__Inform));

#ifdef CWMP_MUSTUNDERSTAND_SUPPORT
	soap->header = (struct SOAP_ENV__Header*)soap_malloc(soap,sizeof(struct SOAP_ENV__Header)) ;
	bzero(soap->header,sizeof(struct SOAP_ENV__Header)) ;
	soap->header->cwmp__ID = (char *)soap_malloc(soap,128) ;
	memset(soap->header->cwmp__ID,0,128) ;
	soap->header->cwmp__ID = soap_strdup(soap,"0") ;	//by defaule configure as 0 
#endif

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

    result = soap_call___cwmp__Inform(soap,Server,"Inform",Inform,&InformResponse);
    PRINTF("############### Client RPC Inform ##############\n") ;
    PRINTF("[Inform Response] : [%d]\n",InformResponse.MaxEnvelopes);
    return result;
}


#ifdef CWMP_TEST
int cwmp_GetRPCMethods(struct soap * soap , const char * Server , char *** RPCSupportList,int * size)
{
    //PRINTF("Entry %s\n",__FUNCTION__);

    int result = 0 ;
    int i = 0 ;
    struct _cwmp__GetRPCMethods* Inform ;
    struct _cwmp__GetRPCMethodsResponse InformResponse;
    char ** RPCList ;

    Inform =  (struct _cwmp__GetRPCMethods *) soap_malloc(soap,sizeof(struct _cwmp__GetRPCMethods));

    soap_call___cwmp__GetRPCMethods(soap,Server,"GetRPCMethods",Inform,&InformResponse);

    RPCSupportList[0] = (char **)soap_malloc(soap,InformResponse.MethodList->__sizestring*sizeof(char *)) ;
    PRINTF("############### Client RPC GetRPCMethods   ##############\n") ;
    for(i = 0 ; i < InformResponse.MethodList->__sizestring ; i ++)
    {
        RPCSupportList[0][i] = (char *)soap_strdup(soap,InformResponse.MethodList->string[i]) ;
        *size += 1 ;
	    PRINTF("[%s]\n",InformResponse.MethodList->string[i]) ;

    }

    return result;
}

int cwmp_GetNamelist(struct soap * soap , const char * Server , char * Path, char *** NameList , int ** Writeable,int * size)
{
    //PRINTF("Entry %s\n",__FUNCTION__);

    int result = 0 ;
    int i = 0 ;
    struct _cwmp__GetParameterNames * Inform ;
    struct _cwmp__GetParameterNamesResponse InformResponse;

    Inform =  (struct _cwmp__GetParameterNames *) soap_malloc(soap,sizeof(struct _cwmp__GetParameterNames));
    Inform->ParameterPath = (char *) soap_strdup(soap,Path);
    Inform->NextLevel = (char *) soap_strdup(soap,"0");

    soap_call___cwmp__GetParameterNames(soap,Server,"GetNameList",Inform,&InformResponse);
    NameList[0] = (char **)soap_malloc(soap,InformResponse.ParameterList->__size*sizeof(char *)) ;
	Writeable[0] = (int *)soap_malloc(soap,InformResponse.ParameterList->__size*sizeof(int)) ;
    PRINTF("############### Client RPC GetNameList ##############\n") ;
    for(i = 0 ; i < InformResponse.ParameterList->__size ; i ++)
    {
        NameList[0][i] = (char *)soap_strdup(soap,InformResponse.ParameterList->__ptrParameterInfoStruct[i]->Name) ;
        Writeable[0][i] = InformResponse.ParameterList->__ptrParameterInfoStruct[i]->Writable ;
	    PRINTF("[%s]:",InformResponse.ParameterList->__ptrParameterInfoStruct[i]->Name) ;
	    PRINTF("[%d]\n",InformResponse.ParameterList->__ptrParameterInfoStruct[i]->Writable) ;
    }
    return result;
}


int cwmp_GetParameterValue(struct soap * soap , const char * Server, char ** NameList, char *** ValueList, int size) 
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

    soap_call___cwmp__GetParameterValues(soap,Server,"GetParameterValue",Inform,&InformResponse);
	
	ValueList[0] = (char **)soap_malloc(soap,Inform->ParameterNames->__size*sizeof(char *)) ;
	
    PRINTF("############### %s :Client RPC GetParameterValue ##############\n",__FUNCTION__) ;
    for(i = 0 ; i < Inform->ParameterNames->__size ; i ++)
    {	
		ValueList[0][i] = (char *)soap_strdup(soap,InformResponse.ParameterList->__ptrParameterValueStruct[i]->Value) ;
	    PRINTF("[%s] : ",InformResponse.ParameterList->__ptrParameterValueStruct[i]->Name) ;
	    PRINTF("[%s]\n",InformResponse.ParameterList->__ptrParameterValueStruct[i]->Value) ;
    }

    return result;
}

int cwmp_SetParameterValue(struct soap * soap,const char * Server, char ** NameList, char ** ValueList, int size)
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

    soap_call___cwmp__SetParameterValues(soap,Server,"SetParameterValue",Inform,&InformResponse);
    PRINTF("############### Client RPC SetParameterValue ##############\n") ;
    PRINTF("[SetParameterValue Response] : [%d]\n",InformResponse.Status);

    return result;
}

int cwmp_GetParameterAttributes(struct soap * soap,const char * Server, char ** NameList, int ** AttrList, int size)
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

    soap_call___cwmp__GetParameterAttributes(soap,Server,"GetParameterAttributes",Inform,&InformResponse);
	AttrList[0] = (int *)soap_malloc(soap,InformResponse.ParameterList->__size*sizeof(int));
    PRINTF("############### Client RPC GetParameterAttributes ##############\n") ;
    for(i = 0 ; i < InformResponse.ParameterList->__size ; i ++)
    {
		AttrList[0][i] = InformResponse.ParameterList->__ptrParameterAttributeStruct[i]->Notification ;
	    PRINTF("[%s] : ",InformResponse.ParameterList->__ptrParameterAttributeStruct[i]->Name) ;
	    PRINTF("[%d]\n",InformResponse.ParameterList->__ptrParameterAttributeStruct[i]->Notification) ;
    }

    return result;
}

int cwmp_SetParameterAttributes(struct soap * soap,const char * Server, char ** NameList, int * AttrList, int size)
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

    soap_call___cwmp__SetParameterAttributes(soap,Server,"SetParameterAttributes",Inform,&InformResponse);
    PRINTF("############### Client RPC SetParameterAttributes ##############\n") ;
    return result;
}

int cwmp_AddObject(struct soap * soap,const char * Server, char * objpath)
{
    int result = 0 ;
    struct _cwmp__AddObject * Inform ;
    struct _cwmp__AddObjectResponse InformResponse;

    Inform = (struct _cwmp__AddObject *)soap_malloc(soap,sizeof(struct _cwmp__AddObject)) ;        
    Inform->ObjectName = (char *)soap_strdup(soap,objpath) ;
    Inform->ParameterKey = (char *)soap_strdup(soap,"0");
    soap_call___cwmp__AddObject(soap,Server,"AddObject",Inform,&InformResponse);
    PRINTF("############### Client RPC AddObject ##############\n") ;
    PRINTF("[AddObject] [InstanceNumber] = [%d] , [Status] = [%d]\n",InformResponse.InstanceNumber,InformResponse.Status) ;
    return result ;
}

int cwmp_DelObject(struct soap * soap,const char * Server, char * objpath)
{
    int result = 0 ;
    struct _cwmp__DeleteObject * Inform ;
    struct _cwmp__DeleteObjectResponse InformResponse;

    Inform = (struct _cwmp__DeleteObject *)soap_malloc(soap,sizeof(struct _cwmp__DeleteObject)) ;        
    Inform->ObjectName = (char *)soap_strdup(soap,objpath) ;
    Inform->ParameterKey = (char *)soap_strdup(soap,"0");
    soap_call___cwmp__DeleteObject(soap,Server,"DelObject",Inform,&InformResponse);
    PRINTF("############### Client RPC DeleteObject ##############\n") ;
    PRINTF("[DeleteObject] [Status] = [%d]\n",InformResponse.Status) ;
    return result ;
}

int cwmp_Reboot(struct soap * soap,const char * Server , char * CommandKey)
{
    int result = 0 ;
    struct _cwmp__Reboot * Inform ;
    struct _cwmp__RebootResponse InformResponse;

    Inform = (struct _cwmp__Reboot *)soap_malloc(soap,sizeof(struct _cwmp__Reboot)) ;        
    Inform->CommandKey = (char *)soap_strdup(soap,CommandKey);
    soap_call___cwmp__Reboot(soap,Server,"Reboot",Inform,&InformResponse);
    PRINTF("############### Client RPC Reboot ##############\n") ;
    return result ;
}

int cwmp_Download(struct soap * soap,const char * Server,char *CommandKey,char *FileType,char *URL,char *Username,char *Password,int FileSize,char *TargetFileName,int DelaySeconds,char *SuccessURL,char *FailureURL)
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
    soap_call___cwmp__Download(soap,Server,"Download",Inform,&InformResponse);
    PRINTF("############### Client RPC Download ##############\n") ;
    return result ;
}

int cwmp_Upload(struct soap * soap,const char * Server , char *CommandKey,char *FileType,char *URL,char *Username,char *Password,int DelaySeconds)
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

    soap_call___cwmp__Upload(soap,Server,"Upload",Inform,&InformResponse);
    PRINTF("############### Client RPC Upload ##############\n") ;
    return result ;
}

int cwmp_FactoryReset(struct soap * soap,const char * Server)
{
    int result = 0 ;
    struct _cwmp__FactoryReset * Inform ;
    struct _cwmp__FactoryResetResponse InformResponse;

    Inform = (struct _cwmp__FactoryReset *)soap_malloc(soap,sizeof(struct _cwmp__FactoryReset)) ;        

    soap_call___cwmp__FactoryReset(soap,Server,"FactoryReset",Inform,&InformResponse);
    PRINTF("############### Client RPC FactoryReset ##############\n") ;
    return result ;
}

int cwmp_ScheduleInform(struct soap * soap,const char * Server , int DelaySeconds , char * CommandKey)
{
    int result = 0 ;
    struct _cwmp__ScheduleInform * Inform ;
    struct _cwmp__ScheduleInformResponse InformResponse;

    Inform = (struct _cwmp__ScheduleInform *)soap_malloc(soap,sizeof(struct _cwmp__ScheduleInform)) ;        
    Inform->DelaySeconds = DelaySeconds ;
    Inform->CommandKey = (char *)soap_strdup(soap,CommandKey) ;
    soap_call___cwmp__ScheduleInform(soap,Server,"ScheduleInform",Inform,&InformResponse);
    PRINTF("############### Client RPC FactoryReset ##############\n") ;
    return result ;
}
int cwmp_TranferComplete(struct soap * soap,const char * Server , char * CommandKey , time_t StartTime , time_t CompleteTime , char * FaultCode , char * FaultString)
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

    soap_call___cwmp__TranferComplete(soap,Server,"TranferComplete",Inform,&InformResponse);
    PRINTF("############### Client RPC FactoryReset ##############\n") ;
    return result ;
}
#endif


/*
 * XmlApi.h : a small test program for dare xml config parse
 *
 * See Copyright for the status of this software.
 *
 * DareGlobale:Kidiger.Guo
 * Date : 2010.03.14
 */


#ifndef _xml_api_h_
#define _xml_api_h_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "mxml.h"

#define DEBUG(x) printf(x)

//#define XML_ENCODING "ISO-8859-1"   //coding type

#define XML_PATH "/var/DareConfig.xml"
#define MultiInstance "MultiInstance"
#define SingleInstance "SingleInstance"
#define TR069NODE_LEN_MAX 256

typedef enum XMLConfig 
{
	XMLConfigValue,
	XMLConfigAttr,
	XMLConfigType,
	XMLConfigLevel,
}XMLConfig;

extern void SaveXML() ;
extern mxml_node_t * FindPathNodeXML(char * path) ;
extern int LoadXML(char * file) ;

extern int AddInstanceXML(char * path) ;

extern int DelInstanceXML(char * path) ;

extern int GetConfigNameList(char * path , char * namelist) ;

extern int SetConfigValue(char * path , char * value) ;

extern int GetConfigValue(char * path , char * value) ;
//extern int GetConfigValue(char * path , char * value, const size_t c_val_buf_size);

extern int AddConfigValue(
	const char *const c_path,
	const char *const c_name,
	const char *const c_type,
	const char *const c_level,
	const char *const c_attr,
	const char *const c_value,
	const char *const c_attrEnl
);

extern int SetConfigAttr(char * path , char * value , char * Enable) ;

extern int GetConfigAttr(char * path , char * value) ;

extern int SetConfigType(char * path , char * value) ;

extern int GetConfigType(char * path , char * value) ;

extern int SetConfigLevel(char * path , char * value) ;

extern int GetConfigLevel(char * path , char * value) ;

extern int RestoreConfigValue(char * path) ;

extern int RestoreConfigAttr(char * path) ;

extern int RestoreConfigType(char * path) ;

extern int RestoreConfigLevel(char * path) ;

#endif


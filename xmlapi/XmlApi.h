/*
 * XmlApi.h : a small test program for xml config parse
 *
 * See Copyright for the status of this software.
 *
 * Kidiger.Guo
 * Date : 2017.03.14
 */


#ifndef _XML_API_H_
#define _XML_API_H_

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include <mxml.h>

#ifndef PARAM_MAX_LENGTH
#define PARAM_MAX_LENGTH 256
#endif

#ifndef NAMELIST_MAX_LENGTH
#define NAMELIST_MAX_LENGTH 2048
#endif


#define MultiInstance "MultiInstance"
#define SingleInstance "SingleInstance"
#define TR069NODE_LEN_MAX 256

#define XML_TRUE	0
#define XML_FALSE	1
#define XML_NULL	NULL

static char xmlPath[PARAM_MAX_LENGTH] ;
char xmlProPath[PARAM_MAX_LENGTH] ;

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

extern int AddInstanceXMLName(char * path , char * name) ;

extern int DelInstanceXML(char * path) ;

extern int GetConfigNameList(char * path , char * namelist) ;

extern int SetConfigValue(char * path , char * value) ;

extern int GetConfigValue(char * path , char * value) ;

extern int _GetConfigValue(char * path , char * value) ;

extern int SetConfigAttr(char * path , char * value , char * Enable) ;

extern int GetConfigAttr(char * path , char * value) ;

extern int SetConfigType(char * path , char * value) ;

extern int GetConfigType(char * path , char * value) ;

extern int SetConfigLevel(char * path , char * value) ;

extern int GetConfigLevel(char * path , char * value) ;



#endif


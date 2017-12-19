/*
 * XmlApi.c : a small test program for dare xml config parse
 *
 * See Copyright for the status of this software.
 *
 * DareGlobale:Kidiger.Guo
 * Date : 2010.03.14
 */
#include "XmlApi.h"

enum {
	LoadSuccess,
	LoadFailed
}StatusXML; 

FILE * fp_root;
mxml_node_t * node_root;


//Load xml file to create DOM tree in RAM .
int LoadXML(char * file)
{
    if(node_root){
    	mxmlDelete(node_root);
		fclose(fp_root);
	}
	fp_root = fopen(file, "rw");
	if(!fp_root) return 1 ;
	node_root = mxmlLoadFile(NULL, fp_root, MXML_NO_CALLBACK);
    fclose(fp_root);
    sprintf(xmlPath,"%s",file) ;
    return 0 ;
}
//Save modification which in DOM tree into xml file
void SaveXML()
{
	FILE *fp ;
	fp = fopen(xmlPath, "w");
	if(!fp) return ;
	mxmlSaveFile(node_root, fp, MXML_NO_CALLBACK);
    fclose(fp);
    printf("Save modification to XML\n") ;
}

//Release DOM tree in RAM
void FreeXML()
{
	/*
    if(node_root)
	    mxmlRemove(node_root);
	if(fp_root)
		fclose(fp_root);
	*/
}

//Get root node form DOM tree 
mxml_node_t *  GetRootElementXML(){
  return mxmlFindElement(node_root, node_root, NULL, NULL, NULL, MXML_DESCEND_FIRST);
}

void SetNodeValueXML(mxml_node_t *  cur , char * value)
{	
	mxmlElementSetAttr(cur, "value", value);
}

void SetNodeLevelXML(mxml_node_t *  cur , char * value)
{
	mxmlElementSetAttr(cur, "level", value);
}

void SetNodeTypeXML(mxml_node_t *  cur , char * value)
{
	mxmlElementSetAttr(cur, "type", value);
}

void SetNodeAttrXML(mxml_node_t *  cur , char * value)
{
	mxmlElementSetAttr(cur, "attr", value);
}

void SetNodeAttrEnlXML(mxml_node_t *  cur , char * value)
{
	mxmlElementSetAttr(cur, "attrEnl", value);
}


void GetNodeInstanceXML(mxml_node_t *  cur , char * value)
{
	strcpy(value,mxmlElementGetAttr(cur, "Instance"));
}

void SetNodeInstanceXML(mxml_node_t *  cur , char * value)
{
	mxmlElementSetAttr(cur, "Instance", value);
}

void GetNodeLevelXML(mxml_node_t *  cur , char * value)
{
	strcpy(value,mxmlElementGetAttr(cur, "level"));
}

void GetNodeTypeXML(mxml_node_t *  cur , char * value)
{
    strcpy(value,mxmlElementGetAttr(cur, "type"));
}

void GetNodeValueXML(mxml_node_t *  cur , char * value)
{
	strcpy(value,mxmlElementGetAttr(cur, "value"));
}

int GetNodeAttrXML(mxml_node_t *  cur , char * value)
{
	strcpy(value,mxmlElementGetAttr(cur, "attr"));
}

int GetConfigNameXML(mxml_node_t *  cur , char * value)
{
	strcpy(value,mxmlElementGetAttr(cur, "config"));
}

int GetConfigAppXML(mxml_node_t *  cur , char * value)
{
    strcpy(value,mxmlElementGetAttr(cur, "app"));
}

mxml_node_t * find_nextbrother(mxml_node_t * node){
    mxml_node_t *brother = 0 ;
    if(node)
  	    brother = mxmlFindElement(node, node->parent, NULL, NULL, NULL, MXML_NO_DESCEND);
    return brother ;
}

mxml_node_t * find_firstchild(mxml_node_t * node){
	mxml_node_t *child ;
	if(!node)
        return NULL ;
    child = mxmlFindElement(node, node, NULL, NULL, NULL, MXML_DESCEND_FIRST);
    return child ;
}

int getNextNode(char *path, int idx)
{
	char fullpath[TR069NODE_LEN_MAX]="";
	sprintf(fullpath, "%s%d", path, idx);
	mxml_node_t * curr = NULL;
	curr = FindPathNodeXML(fullpath);
	if(curr==NULL)
		return XML_FALSE;
	return IsNodeCheck(curr) ;
}

//Get children node , children node is under node link , the point will link to the first node . 
mxml_node_t *  GetChildrenNodeXML(mxml_node_t *  cur)
{
	mxml_node_t *  children = NULL ;
	children = find_firstchild(cur) ;
	
	if(!children)
		return NULL;
	
	while (children && xmlIsBlankNode(children) == XML_TRUE)
	{	
		children = find_nextbrother(children) ;
  	    if(!children)
			return NULL;
    }
    return children ;
}

//Get brother node , brother node is in the same level .
mxml_node_t *  GetBrotherNodeXML(mxml_node_t *  cur)
{
	mxml_node_t * brother ;
	brother = find_nextbrother(cur) ;
	if(!brother)
		return NULL;
	if(brother->type != MXML_ELEMENT)
	{
		brother = find_nextbrother(brother) ;
		if(!brother)
			return NULL;
	}
	
	return brother ;
}

//find the node name in a tree level
mxml_node_t *  FindBrotherNameXML(mxml_node_t *  cur , char * name)
{
	mxml_node_t *  ptr = cur ;
	char data[256] ;
	char * str = data ;
	while(ptr)
	{	
		if(!strcmp(ptr->value.element.name, MultiInstance))
		{
			GetNodeInstanceXML(ptr,str) ;
			if(atoi(str) == atoi(name)){
				return ptr ;
			}
		}
		else
		{
			if(!strcmp(ptr->value.element.name, name))
				return ptr ;
		}
		ptr = GetBrotherNodeXML(ptr) ;
	}
	//printf("%s not found\n", name) ;
	return NULL ;
}

//find the real path node
mxml_node_t *  FindPathNodeXML(char * path)
{
	int i = 1 ;
	char data[256] ;
	mxml_node_t *  cur = NULL ;
	char * str = data ;
	cur = GetRootElementXML() ;
	memset(data,0x00,sizeof(data)) ;
	while(cur && (GetSubString(path, i, ".", str) == 0))
	{
		i ++ ;
		cur = FindBrotherNameXML(cur, str) ;
		if(!cur)
			return NULL ;
		memset(data,0x00,sizeof(data)) ;
		if((GetSubString(path, i, ".", str) == 0))
		{
			cur = GetChildrenNodeXML(cur) ;
			if(!cur)
				return NULL ;
		}
	}
	return cur ;
}

//find the real path node's parent
mxml_node_t *  FindPathNodeParentXML(char * path)
{
	char cpath[256] ;
	mxml_node_t *  cur = NULL ;
	mxml_node_t *  parent = NULL ;
	cur = GetRootElementXML() ;
	char * str = NULL ;
	strcpy(cpath,path) ;
	str = strtok(cpath,".") ;
	parent = cur ;
	while(cur && str)
	{
		cur = FindBrotherNameXML(cur,str) ;
		if(!cur)
			return NULL ;
		str = strtok(NULL,".") ;
		if(str)
		{
			parent = cur ;
			cur = GetChildrenNodeXML(cur) ;
			if(!cur)
				return NULL ;
		}
	}
	return parent ;
}

int IsNodeCheck(mxml_node_t *  cur)
{
	char data[256] ;
	char * str = data ;
	if(!strcmp(cur->value.element.name, MultiInstance) || 
	   !strcmp(cur->value.element.name, SingleInstance))
		return XML_TRUE ;
	GetNodeTypeXML(cur, str) ;
	if(!strcmp(str,MultiInstance) || !strcmp(str,SingleInstance))
		return XML_TRUE ;
	else
		return XML_FALSE ;
}

int SetConfigValue(char * path , char * value)
{
	mxml_node_t *  cur ;
	cur = FindPathNodeXML(path) ;
	if(!cur)
		return XML_FALSE ;
	if(IsNodeCheck(cur) == XML_TRUE)
		return XML_FALSE ;
	SetNodeValueXML(cur,value) ;
	return XML_TRUE ;
}



int GetConfigValue(char * path , char * value)
//int GetConfigValue(char * path , char * value, const size_t c_val_buf_size)
{
	mxml_node_t *  cur ;
	cur = FindPathNodeXML(path) ;
	if(!cur)
		return XML_FALSE ;
	if(IsNodeCheck(cur) == XML_TRUE)	
		return XML_FALSE ;
	GetNodeValueXML(cur,value) ;
	return XML_TRUE ;
}

int _GetConfigValue(char * path , char * value)
{
	memset(value,0x0,PARAM_MAX_LENGTH) ;
	return GetConfigValue(path,value) ;
}


int SetConfigAttr(char * path , char * value , char * Enable)
{
	mxml_node_t *  cur ;
	cur = FindPathNodeXML(path) ;
	if(!cur)
		return XML_FALSE ;
	if(IsNodeCheck(cur) == XML_TRUE)	
		return XML_FALSE ;
	SetNodeAttrXML(cur,value) ;
	SetNodeAttrEnlXML(cur,Enable) ;
	return XML_TRUE ;
}

int GetConfigAttr(char * path , char * value)
{
	mxml_node_t *  cur ;
	cur = FindPathNodeXML(path) ;
	if(!cur)
		return XML_FALSE ;
	if(IsNodeCheck(cur) == XML_TRUE)	
		return XML_FALSE ;
	GetNodeAttrXML(cur,value) ;
	return XML_TRUE ;
}

int _GetConfigAttr(char * path , char * value)
{
	memset(value,0x0,PARAM_MAX_LENGTH) ;
	return GetConfigAttr(path,value) ;
}

int GetConfigName(char * path , char * value)
{
    mxml_node_t *  cur ;
	cur = FindPathNodeXML(path) ;
	if(!cur)
		return XML_FALSE ;
	if(IsNodeCheck(cur) == XML_TRUE)	
		return XML_FALSE ;
	GetConfigNameXML(cur,value) ;
	return XML_TRUE ;
}

int _GetConfigName(char * path , char * value)
{
	memset(value,0x0,PARAM_MAX_LENGTH) ;
	return GetConfigName(path,value) ;
}

int GetConfigApp(char * path , char * value)
{
    mxml_node_t *  cur ;
	cur = FindPathNodeXML(path) ;
	if(!cur)
		return XML_FALSE ;
	if(IsNodeCheck(cur) == XML_TRUE)	
		return XML_FALSE ;
	GetConfigAppXML(cur,value) ;
	return XML_TRUE ;
}

int _GetConfigApp(char * path , char * value)
{
	memset(value,0x0,PARAM_MAX_LENGTH) ;
	return GetConfigApp(path,value) ;
}

int SetConfigType(char * path , char * value)
{
	mxml_node_t *  cur ;
	cur = FindPathNodeXML(path) ;
	if(!cur)
		return XML_FALSE ;
	if(IsNodeCheck(cur) == XML_TRUE)	
		return XML_FALSE ;
	SetNodeTypeXML(cur,value) ;
	return XML_TRUE ;
}

int GetConfigType(char * path , char * value)
{
	mxml_node_t *  cur ;
	cur = FindPathNodeXML(path) ;
	if(!cur)
		return XML_FALSE ;
	if(IsNodeCheck(cur) == XML_TRUE)	
		return XML_FALSE ;
	GetNodeTypeXML(cur,value) ;
	return XML_TRUE ;
}

int SetConfigLevel(char * path , char * value)
{
	mxml_node_t *  cur ;
	cur = FindPathNodeXML(path) ;
	if(!cur)
		return XML_FALSE ;
	SetNodeLevelXML(cur,value) ;
	return 0 ;
}

int GetConfigLevel(char * path , char * value)
{
	mxml_node_t *  cur ;
	cur = FindPathNodeXML(path) ;
	if(!cur)
		return XML_FALSE ;
	GetNodeLevelXML(cur,value) ;
	return 0 ;
}

int _GetConfigLevel(char * path , char * value)
{
	memset(value,0x0,PARAM_MAX_LENGTH) ;
	return GetConfigLevel(path,value) ;
}

//check instance num from tree level if already used, return XML_TRUE if used
int FindBrotherInstanceXML(mxml_node_t *  cur , int num)
{
	mxml_node_t *  ptr ;
	char data[256] ;
	char * str = data ;
	ptr = GetChildrenNodeXML(cur) ;
	while(ptr)
	{
		if(!strcmp(ptr->value.element.name, MultiInstance))
			GetNodeInstanceXML(ptr,str) ;
		if(num == atoi(str))
			return XML_TRUE ;
		ptr = GetBrotherNodeXML(ptr) ;
	}
	return XML_FALSE ;
}

//get no used instance num for datamodule , return the num
int GetNoUsedInstanceNumXML(mxml_node_t *  cur)
{
	int num = 1 ;
	while(num < 255)
	{
		if(FindBrotherInstanceXML(cur,num) == XML_FALSE)
			return num ;
		num ++ ;
	}
	return XML_TRUE ;
}

//create a new node form default xml file
mxml_node_t *  GetNodeFromFile(char * path)
{
	FILE * fp_tmp;
	mxml_node_t * cur ;
	mxml_node_t * children ;
	mxml_node_t * pdoc ;
	char modpath[128] ;
	cur = FindPathNodeXML(path) ;
	if(!cur)
		return NULL ;
	memset(modpath,0x00,sizeof(modpath)) ;
	sprintf(modpath,"%s/%s.xml", xmlProPath,cur->value.element.name) ;	
	fp_tmp = fopen(modpath, "r");
	if(!fp_tmp) return NULL ;
	pdoc = mxmlLoadFile(NULL, fp_tmp, MXML_NO_CALLBACK);
	children = mxmlFindElement(pdoc, pdoc, NULL, NULL, NULL, MXML_DESCEND);
	children = mxmlFindElement(children, pdoc, NULL, NULL, NULL, MXML_DESCEND_FIRST) ;
	fclose(fp_tmp);
	return children ;
}

//read default xml instance from file and add it to the tree
int AddInstanceXML(char * path)
{
	mxml_node_t *  cur ;
	mxml_node_t *  children ;
	mxml_node_t *  pdoc ;
	FILE * fp_tmp ;
	char num[8] ;
	char * pnum = num ;
	int Inum = 0 ;
	char modpath[128] ;
	printf("Add Node Path : %s\n",path) ;
	cur = FindPathNodeXML(path) ;
	if(!cur)
		return 0 ;
	memset(num,0x00,sizeof(num)) ;
	Inum = GetNoUsedInstanceNumXML(cur) ;
	sprintf(pnum,"%d",Inum) ;
	sprintf(modpath, "%s/%s.xml", xmlProPath,cur->value.element.name) ;	
    printf("Profile path = [%s].[%d]\n",modpath,Inum) ;
	fp_tmp = fopen(modpath, "r");
	if(!fp_tmp) return 0 ;
	pdoc = mxmlLoadFile(NULL, fp_tmp, MXML_NO_CALLBACK);
	children = mxmlFindElement(pdoc, pdoc, NULL, NULL, NULL, MXML_DESCEND);
	children = mxmlFindElement(children, pdoc, NULL, NULL, NULL, MXML_DESCEND_FIRST) ;
	mxmlAdd (cur, MXML_ADD_AFTER, MXML_ADD_TO_PARENT, children ) ;
	SetNodeInstanceXML(children,pnum) ;
	return Inum ;
}

int AddInstanceXMLName(char * path , char * name)
{
		mxml_node_t *  cur ;
	mxml_node_t *  children ;
	mxml_node_t *  pdoc ;
	FILE * fp_tmp ;
	char num[8] ;
	char * pnum = num ;
	int Inum = 0 ;
	char modpath[128] ;
	printf("Add Node Path : %s\n",path) ;
	cur = FindPathNodeXML(path) ;
	if(!cur)
		return 0 ;
	memset(num,0x00,sizeof(num)) ;
	Inum = GetNoUsedInstanceNumXML(cur) ;
	sprintf(pnum,"%d",Inum) ;
	sprintf(modpath, "%s/%s.xml", xmlProPath,name) ;
    printf("Profile path = [%s].[%d]\n",modpath,Inum) ;
	fp_tmp = fopen(modpath, "r");
	if(!fp_tmp) return 0 ;
	pdoc = mxmlLoadFile(NULL, fp_tmp, MXML_NO_CALLBACK);
	children = mxmlFindElement(pdoc, pdoc, NULL, NULL, NULL, MXML_DESCEND);
	children = mxmlFindElement(children, pdoc, NULL, NULL, NULL, MXML_DESCEND_FIRST) ;
	mxmlAdd (cur, MXML_ADD_AFTER, MXML_ADD_TO_PARENT, children ) ;
	SetNodeInstanceXML(children,pnum) ;
	return Inum ;
}

//unlink and free node
int DelInstanceXML(char * path)
{
	mxml_node_t *  cur ;
	mxml_node_t *  temp ;
	char num[8] ;
	char * str = num ;
	cur = FindPathNodeXML(path) ;
	if(!cur)
		return XML_FALSE ;
	mxmlDelete(cur);
	return XML_TRUE ;
}

int GetConfigNameList(char * path , char * namelist)
{
	mxml_node_t *  cur ;
	mxml_node_t *  children ;
	char num[8] ;
	char type[64] ;
	char * pnum = num ;
	char * stype = type ;
	int number = 0 ;
	char * str = path ;
	str += strlen(path) - 1 ; 
	if(*str != '.')
		return 0 ;
	cur = FindPathNodeXML(path) ;
	if(!cur)
		return 0 ;
	cur = GetChildrenNodeXML(cur) ;
	if(!cur)
		return 0 ;
	while(cur && strcmp(cur->value.element.name, "text") != 0)
	{
		number ++ ;
		children = GetChildrenNodeXML(cur) ;
		if(children)
		{
			if(!strcmp(cur->value.element.name, MultiInstance))
			{
				GetNodeInstanceXML(cur,pnum) ;
				strncat(namelist,pnum,strlen(pnum)) ;
			}
			else
			{
				strncat(namelist, cur->value.element.name, strlen(cur->value.element.name)) ;
			}
			strncat(namelist,".&",2) ;
		}
		else
		{
			strncat(namelist, cur->value.element.name, strlen(cur->value.element.name)) ;
			memset(type,0x00,sizeof(type)) ;
			GetNodeTypeXML(cur,stype) ;
			if(!strcmp(stype,MultiInstance))
			{
				strncat(namelist,".&",2) ;
			}
			else
			{
				strncat(namelist,"&",1) ;
			}
		}
		cur = GetBrotherNodeXML(cur) ;
	}
	printf("[Namelist] = [%s]\n",namelist);
	return number ;
}

#define IS_BLANK(c)							\
  (((c) == '\n') || ((c) == '\r') || ((c) == '\t') || ((c) == ' '))

int xmlIsBlankNode(mxml_node_t * node) {
    char *cur;
    if (!node) return XML_FALSE;
    if (node->type != MXML_TEXT) return XML_FALSE;
    cur = node->value.text.string;
    while (*cur != 0) {
	    if (!IS_BLANK(*cur)) return XML_FALSE;
		cur++;
    }
    return XML_TRUE;
}


int GetSubString(char * str , int num , char * sp , char * value)
{
	int i = 1 ;
	char * ptr = NULL ;
	char * pbuf = NULL ;
	char * pstr = NULL ;
	ptr = str ;
	while(i < num && ptr)
	{
		i ++ ;
		pbuf = strstr(ptr,sp) ;
		if(pbuf == NULL)
			return 1 ;
		ptr = pbuf + strlen(sp);
	}
	if(ptr == NULL || *ptr == '\0')
		return 1 ;
	pbuf = strstr(ptr,sp) ;
	if(!pbuf)
	{
		if(ptr)
		{
			sprintf(value,"%s",ptr) ;
			return 0 ;
		}
		else
			return 1 ;
	}
	pstr = ptr ;
	i = 0 ;
	while(*pstr != *pbuf)
	{
		pstr ++ ;
		i ++ ;
	}
	strncat(value,ptr,i) ;
	value[i] = '\0' ;
	//printf("value:%s\n", value);
	return 0 ;
}



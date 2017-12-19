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

  return 0 ;

}

void SaveXML()
{
	FILE *fp ;
	fp = fopen(XML_PATH, "w");
	if(!fp) return ;
	mxmlSaveFile(node_root, fp, MXML_NO_CALLBACK);
  fclose(fp);
}

void FreeXML()
{		
	/*
		if(node_root)
			mxmlRemove(node_root);
		if(fp_root)
			fclose(fp_root);
			*/
}

//get root node form doc 
mxml_node_t *  GetRootElementXML(){
  return mxmlFindElement(node_root, node_root, NULL, NULL, NULL, MXML_DESCEND_FIRST);
}

int SetNodeValueXML(mxml_node_t *  cur , char * value)
{	
	//printf("---%s:%d---\n", __FUNCTION__, __LINE__);	
	mxmlElementSetAttr(cur, "value", value);
}

int SetNodeLevelXML(mxml_node_t *  cur , char * value)
{
	//printf("---%s:%d---\n", __FUNCTION__, __LINE__);	
	mxmlElementSetAttr(cur, "level", value);
}

int SetNodeTypeXML(mxml_node_t *  cur , char * value)
{
	//printf("---%s:%d---\n", __FUNCTION__, __LINE__);	
	mxmlElementSetAttr(cur, "type", value);
}

int SetNodeAttrXML(mxml_node_t *  cur , char * value)
{
	//printf("---%s:%d---\n", __FUNCTION__, __LINE__);	
	mxmlElementSetAttr(cur, "attr", value);
}

int SetNodeAttrEnlXML(mxml_node_t *  cur , char * value)
{
	//printf("---%s:%d---\n", __FUNCTION__, __LINE__);	
	mxmlElementSetAttr(cur, "attrEnl", value);
}


int GetNodeInstanceXML(mxml_node_t *  cur , char * value)
{
	//printf("---%s:%d---\n", __FUNCTION__, __LINE__);	
	strcpy(value,mxmlElementGetAttr(cur, "Instance"));
	//printf("value:%s\n", value);
	return 0 ;
}

int SetNodeInstanceXML(mxml_node_t *  cur , char * value)
{
	//printf("---%s:%d---\n", __FUNCTION__, __LINE__);	
	mxmlElementSetAttr(cur, "Instance", value);
	return 0 ;
}

int GetNodeLevelXML(mxml_node_t *  cur , char * value)
{
	//printf("---%s:%d---\n", __FUNCTION__, __LINE__);	
	strcpy(value,mxmlElementGetAttr(cur, "level"));
	return 0 ;
}

int GetNodeTypeXML(mxml_node_t *  cur , char * value)
{
	//printf("---%s:%d---\n", __FUNCTION__, __LINE__);	
	if(cur==NULL)
	{
		return 1;
	}
	char * tmp = mxmlElementGetAttr(cur, "type");
	if(tmp==NULL)
	{
		return 1;
	}
	else
	{
		strcpy(value, tmp);
		return 0 ;
	}
}

int GetNodeValueXML(mxml_node_t *  cur , char * value)
{
	//printf("---%s:%d---\n", __FUNCTION__, __LINE__);	
	strcpy(value,mxmlElementGetAttr(cur, "value"));
	return 0 ;
}

int GetNodeAttrXML(mxml_node_t *  cur , char * value)
{
	//printf("---%s:%d---\n", __FUNCTION__, __LINE__);	
	strcpy(value,mxmlElementGetAttr(cur, "attr"));
	return 0 ;
}

mxml_node_t * find_nextbrother(mxml_node_t * node){
	//printf("---%s:%d---\n", __FUNCTION__, __LINE__);		
	mxml_node_t *brother = 0 ;
  if(node)
  	brother = mxmlFindElement(node, node->parent, NULL, NULL, NULL, MXML_NO_DESCEND);
  return brother ;
}

mxml_node_t * find_firstchild(mxml_node_t * node){
	//printf("---%s:%d---\n", __FUNCTION__, __LINE__);	
	mxml_node_t *child ;
	if(!node)  return 0 ;
  child = mxmlFindElement(node, node, NULL, NULL, NULL, MXML_DESCEND_FIRST);
  return child ;
}

int getNextNode(char *path, int idx)
{
	//printf("---%s:%d---\n", __FUNCTION__, __LINE__);	
	char fullpath[TR069NODE_LEN_MAX]="";
	sprintf(fullpath, "%s%d", path, idx);
	mxml_node_t * curr = NULL;
	curr = FindPathNodeXML(fullpath);
	if(curr==NULL)
		return 0;
	else
	{
		if(IsNodeCheck(curr) != 0)
			return 1;
		else
			return 0;
	}
}

//get children
mxml_node_t *  GetChildrenNodeXML(mxml_node_t *  cur)
{
	//printf("---%s:%d---\n", __FUNCTION__, __LINE__);	
	mxml_node_t *  children = NULL ;
	children = find_firstchild(cur) ;
	
	if(children==NULL)
		return NULL;
	
	while (children && xmlIsBlankNode(children))
	{	
		children = find_nextbrother(children) ;
  	if(children==NULL)
			return NULL;
	}
	if (children == NULL)
  {
		return NULL;
	}
	else
	{
		return children ;
	}
}

mxml_node_t *  GetBrotherNodeXML(mxml_node_t *  cur)
{
	//printf("---%s:%d---\n", __FUNCTION__, __LINE__);	
	mxml_node_t * brother ;
	brother = find_nextbrother(cur) ;
	if(!brother)
		return NULL;
	if(brother->type != MXML_ELEMENT)
	{
		brother = find_nextbrother(brother) ;
		if(brother == NULL)
			return NULL;
	}
	
	return brother ;
}

//find the node name in a tree level
mxml_node_t *  FindBrotherNameXML(mxml_node_t *  cur , char * name)
{
	//printf("---%s:%d---cur:%s name:%s\n", __FUNCTION__, __LINE__, cur->value.element.name, name);	
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
	printf("%s not found\n", name) ;
	return NULL ;
}

//find the real path node
mxml_node_t *  FindPathNodeXML(char * path)
{
	//printf("---%s:%d---path=%s\n", __FUNCTION__, __LINE__, path);	
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
		if(cur == NULL)
			return NULL ;
		memset(data,0x00,sizeof(data)) ;
		if((GetSubString(path, i, ".", str) == 0))
		{
			cur = GetChildrenNodeXML(cur) ;
			if(cur == NULL)
				return NULL ;
		}
	}
	//printf("path:%s, cur:%s\n", path, cur->value.element.name);
	return cur ;
}

//find the real path node's parent
mxml_node_t *  FindPathNodeParentXML(char * path)
{
	//printf("---%s:%d---\n", __FUNCTION__, __LINE__);	
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
		//printf("---%s:%d--- str:%s\n", __FUNCTION__, __LINE__, str);
		cur = FindBrotherNameXML(cur,str) ;
		if(cur == NULL)
			return NULL ;
		str = strtok(NULL,".") ;
		if(str)
		{
			parent = cur ;
			cur = GetChildrenNodeXML(cur) ;
			if(cur == NULL)
				return NULL ;
		}
	}
	return parent ;
}

int IsNodeCheck(mxml_node_t *  cur)
{
	//printf("---%s:%d---\n", __FUNCTION__, __LINE__);	
	char data[256] ;
	char * str = data ;
	if(strcmp(cur->value.element.name, MultiInstance) == 0 || 
				strcmp(cur->value.element.name, SingleInstance) == 0)
		return 1 ;
	GetNodeTypeXML(cur, str) ;
	if(strcmp(str,MultiInstance) == 0 || strcmp(str,SingleInstance) == 0)
		return 1 ;
	else
		return 0 ;
}

int SetConfigValue(char * path , char * value)
{
	//printf("---%s:%d---\n", __FUNCTION__, __LINE__);	
	mxml_node_t *  cur ;

	cur = FindPathNodeXML(path) ;
	if(cur == NULL)
		return 1 ;
	if(IsNodeCheck(cur) != 0)	
		return 1 ;
	
	SetNodeValueXML(cur,value) ;
	//SaveXML() ;
	return 0 ;
}

int GetConfigValue(char * path , char * value)
//int GetConfigValue(char * path , char * value, const size_t c_val_buf_size)
{
	//printf("---%s:%d---\n", __FUNCTION__, __LINE__);	
	mxml_node_t *  cur ;

	//if (gva_get_confg_value(path, value, c_val_buf_size)) return 0;
	//if (gva_get_confg_value(path, value)) return 0;

	cur = FindPathNodeXML(path) ;
	if(cur == NULL)
		return 1 ;
	if(IsNodeCheck(cur) != 0)	
		return 1 ;
	GetNodeValueXML(cur,value) ;

	//gva_get_confg_value(path, value, c_val_buf_size);
	gva_get_confg_value(path, value);
	return 0 ;
}


int AddConfigValue(
	const char *const c_path,
	const char *const c_name,

	const char *const c_type,
	const char *const c_level,
	const char *const c_attr,
	const char *const c_value,
	const char *const c_attrEnl
)
{
	//<DeviceSummary type="string" level="1" attr="0" value="DARE" attrEnl="0"/>

	int rc=1;
	mxml_node_t *cur;
	char full_path[256+1]="";

	if ((1==1)
		&&(NULL!=c_path)
		&&(NULL!=c_name)
		&&(NULL!=c_type)
		&&(NULL!=c_level)
		&&(NULL!=c_attr)
		&&(NULL!=c_value)
		&&(NULL!=c_attrEnl)
	)
	{
	  sprintf(full_path, "%s%s", c_path, c_name);

	  cur=FindPathNodeXML(full_path);
	  if (NULL==cur)
	  {
	    cur=FindPathNodeXML(c_path);
	    if (NULL!=cur)
	    {
	      cur=mxmlNewElement(cur, c_name);
	    }
	  }

	  if (NULL!=cur)
	  {
	    SetNodeTypeXML(cur, c_type);
	    SetNodeLevelXML(cur, c_level);
	    SetNodeAttrXML(cur, c_attr);
	    SetNodeValueXML(cur, c_value);
	    SetNodeAttrEnlXML(cur, c_attrEnl);
	    rc=0;
	  }
	}

	return rc;
}


int SetConfigAttr(char * path , char * value , char * Enable)
{
	//printf("---%s:%d---\n", __FUNCTION__, __LINE__);	
	mxml_node_t *  cur ;
	cur = FindPathNodeXML(path) ;
	if(cur == NULL)
		return 1 ;
	if(IsNodeCheck(cur) != 0)	
		return 1 ;
	SetNodeAttrXML(cur,value) ;
	SetNodeAttrEnlXML(cur,Enable) ;
	//SaveXML() ;
	return 0 ;
}

int GetConfigAttr(char * path , char * value)
{
	//printf("---%s:%d---\n", __FUNCTION__, __LINE__);	
	mxml_node_t *  cur ;
	cur = FindPathNodeXML(path) ;
	if(cur == NULL)
		return 1 ;
	if(IsNodeCheck(cur) != 0)	
		return 1 ;
	GetNodeAttrXML(cur,value) ;
	return 0 ;
}

int SetConfigType(char * path , char * value)
{
	//printf("---%s:%d---\n", __FUNCTION__, __LINE__);	
	mxml_node_t *  cur ;
	cur = FindPathNodeXML(path) ;
	if(cur == NULL)
		return 1 ;
	if(IsNodeCheck(cur) != 0)	
		return 1 ;
	SetNodeTypeXML(cur,value) ;
	//SaveXML() ;
	return 0 ;
}

int GetConfigType(char * path , char * value)
{
	//printf("---%s:%d---\n", __FUNCTION__, __LINE__);	
	mxml_node_t *  cur ;
	cur = FindPathNodeXML(path) ;
	if(cur == NULL)
		return 1 ;
	if(IsNodeCheck(cur) != 0)	
		return 1 ;
	GetNodeTypeXML(cur,value) ;
	return 0 ;
}

int SetConfigLevel(char * path , char * value)
{
	//printf("---%s:%d---\n", __FUNCTION__, __LINE__);	
	mxml_node_t *  cur ;
	cur = FindPathNodeXML(path) ;
	if(cur == NULL)
		return 1 ;
	SetNodeLevelXML(cur,value) ;
	//SaveXML() ;
	return 0 ;
}

int GetConfigLevel(char * path , char * value)
{
	//printf("---%s:%d---\n", __FUNCTION__, __LINE__);	
	mxml_node_t *  cur ;
	cur = FindPathNodeXML(path) ;
	if(cur == NULL)
		return 1 ;
	GetNodeLevelXML(cur,value) ;
	return 0 ;
}

//find no use instance num form tree level , return 0 if find
int FindBrotherInstanceXML(mxml_node_t *  cur , int num)
{
	//printf("---%s:%d---\n", __FUNCTION__, __LINE__);	
	mxml_node_t *  ptr ;
	char data[256] ;
	char * str = data ;
	ptr = GetChildrenNodeXML(cur) ;
	while(ptr)
	{
		if(!strcmp(ptr->value.element.name, MultiInstance))
			GetNodeInstanceXML(ptr,str) ;
		if(num == atoi(str))
			return 1 ;
		ptr = GetBrotherNodeXML(ptr) ;
	}
	return 0 ;
}

//get no used instanc num for datamodule , return the num
int GetNoUsedInstanceNumXML(mxml_node_t *  cur)
{
	//printf("---%s:%d---\n", __FUNCTION__, __LINE__);	
	int num = 1 ;
	while(num < 255)
	{
		if(FindBrotherInstanceXML(cur,num) == 0)
			return num ;
		num ++ ;
	}
	return 0 ;
}

//create a new node form default xml file
mxml_node_t *  GetNodeFromFile(char * path)
{
	//printf("---%s:%d---\n", __FUNCTION__, __LINE__);	
	FILE * fp_tmp;
	mxml_node_t * cur ;
	mxml_node_t * children ;
	mxml_node_t * pdoc ;
	char modpath[128] ;
	cur = FindPathNodeXML(path) ;
	if(cur == NULL)
		return NULL ;
	memset(modpath,0x00,sizeof(modpath)) ;
	sprintf(modpath,"/var/ConfigXml/%s.xml", cur->value.element.name) ;	
	fp_tmp = fopen(modpath, "r");
	if(!fp_tmp) return NULL ;
	pdoc = mxmlLoadFile(NULL, fp_tmp, MXML_NO_CALLBACK);
	children = mxmlFindElement(pdoc, pdoc, NULL, NULL, NULL, MXML_DESCEND);
	children = mxmlFindElement(children, pdoc, NULL, NULL, NULL, MXML_DESCEND_FIRST) ;
	fclose(fp_tmp);
	return children ;
}

int RestoreConfigValue(char * path)
{
	//printf("---%s:%d---\n", __FUNCTION__, __LINE__);	
	XMLConfig config = XMLConfigValue ;
	return RestoreInstanceXML(path,config) ;
}

int RestoreConfigAttr(char * path)
{
	//printf("---%s:%d---\n", __FUNCTION__, __LINE__);	
	XMLConfig config = XMLConfigAttr ;
	return RestoreInstanceXML(path, config) ;
}

int RestoreConfigType(char * path)
{
	//printf("---%s:%d---\n", __FUNCTION__, __LINE__);	
	XMLConfig config = XMLConfigType ;
	return RestoreInstanceXML(path,config) ;
}

int RestoreConfigLevel(char * path)
{
	//printf("---%s:%d---\n", __FUNCTION__, __LINE__);	
	XMLConfig config = XMLConfigLevel ;
	return RestoreInstanceXML(path,config) ;
}

//read default xml instance from file add restore the value to the tree
int RestoreInstanceXML(char * path , XMLConfig config)
{
	//printf("---%s:%d---\n", __FUNCTION__, __LINE__);	
	mxml_node_t *  cur ;
	mxml_node_t *  file ;
	char tmp[256] ;
	cur = FindPathNodeXML(path) ;
	if(cur == NULL)
		return 1 ;
	cur = GetChildrenNodeXML(cur) ;
	if(cur == NULL)
		return 1 ;
	file = GetNodeFromFile(path) ;
	if(file == NULL)
		return 1 ;
	file = GetChildrenNodeXML(file) ;
	if(file == NULL)
		return 1 ;

	while(cur != NULL && file != NULL)
	{
		if(IsNodeCheck(cur) == 0)
		{
			memset(tmp,0x00,sizeof(tmp)) ;
			switch(config)
			{
				case XMLConfigValue :	GetNodeValueXML(file,tmp) ;
															printf("---%s:%d---\n", __FUNCTION__, __LINE__);	
															SetNodeValueXML(cur,tmp) ;
															printf("---%s:%d---\n", __FUNCTION__, __LINE__);	
															break ;
				case XMLConfigAttr :	GetNodeAttrXML(file,tmp) ;
															SetNodeAttrXML(cur,tmp) ;
															break ;
				case XMLConfigType :	GetNodeTypeXML(file,tmp) ;
															SetNodeTypeXML(cur,tmp) ;
															break ;
				case XMLConfigLevel :	GetNodeLevelXML(file,tmp) ;
															SetNodeLevelXML(cur,tmp) ;
															break ;
			}
		}
		cur = GetBrotherNodeXML(cur) ;
		file = GetBrotherNodeXML(file) ;
	}
	return 0 ;
}


//read default xml instance from file and add it to the tree
int AddInstanceXML(char * path)
{
	//printf("---%s:%d---\n", __FUNCTION__, __LINE__);	
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
	if(cur == NULL)
		return 0 ;
	memset(num,0x00,sizeof(num)) ;
	Inum = GetNoUsedInstanceNumXML(cur) ;
	sprintf(pnum,"%d",Inum) ;
	//printf("cur->name = %s", cur->name) ;
	sprintf(modpath, "/DareGlobal/dare-etc/ConfigXml/%s.xml", cur->value.element.name) ;	
	fp_tmp = fopen(modpath, "r");
	if(!fp_tmp) return NULL ;
	pdoc = mxmlLoadFile(NULL, fp_tmp, MXML_NO_CALLBACK);
	children = mxmlFindElement(pdoc, pdoc, NULL, NULL, NULL, MXML_DESCEND);
	children = mxmlFindElement(children, pdoc, NULL, NULL, NULL, MXML_DESCEND_FIRST) ;
	mxmlAdd (cur, MXML_ADD_AFTER, MXML_ADD_TO_PARENT, children ) ;
	SetNodeInstanceXML(children,pnum) ;
	//SaveXML() ;
	//LoadXML(XML_PATH) ;
	return Inum ;
}

//unlink and free node
int DelInstanceXML(char * path)
{
	//printf("---%s:%d---\n", __FUNCTION__, __LINE__);	
	mxml_node_t *  cur ;
	mxml_node_t *  temp ;
	char num[8] ;
	char * str = num ;
	cur = FindPathNodeXML(path) ;
	if(cur == NULL)
		return 1 ;
	//mxmlRelease(cur); 
	mxmlDelete(cur);
	return 0 ;
}

int GetConfigNameList(char * path , char * namelist)
{
	//printf("---%s:%d---\n", __FUNCTION__, __LINE__);	
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
	if(cur == NULL)
		return 0 ;
	//printf("%s:%d  %s\n", cur->value.element.name);
	cur = GetChildrenNodeXML(cur) ;
	if(cur == NULL)
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
				//printf("GetConfigNameList : %s%s.\n",path,pnum) ;
			}
			else
			{
				strncat(namelist, cur->value.element.name, strlen(cur->value.element.name)) ;
				//printf("GetConfigNameList : %s%s.\n",path,cur->name) ;
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
				//printf("GetConfigNameList : %s%s.\n",path,cur->name) ;
				strncat(namelist,".&",2) ;
			}
			else
			{
				//printf("GetConfigNameList : %s%s\n",path,cur->name) ;
				strncat(namelist,"&",1) ;
			}
		}
		cur = GetBrotherNodeXML(cur) ;
	}
	//printf("---%s:%d---path:%s namelist:%s\n" , __FUNCTION__, __LINE__, path, namelist);
	//exit(0);
	return number ;
}

 #define IS_BLANK(c)							\
  (((c) == '\n') || ((c) == '\r') || ((c) == '\t') || ((c) == ' '))
 int xmlIsBlankNode(mxml_node_t * node) {
 		//printf("---%s:%d---\n", __FUNCTION__, __LINE__);	
    char *cur;
    if (node == NULL) return(0);
    if (node->type != MXML_TEXT) return(0);
    //if (node->value == NULL) return(0);
    cur = node->value.text.string;
    while (*cur != 0) {
			if (!IS_BLANK(*cur)) return(0);
			cur++;
    }
    return(1);
}

#if 0
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

int main(int argc, char **argv) {
	int ret = 0 ;
	mxml_node_t * doc ;
	mxml_node_t *  cur ;
	mxml_node_t *  children ;
	mxml_node_t *  parent ;
	char data[256] ;
	char * str = data ;
	char namelist[1024] ;
	char *nlptr = namelist ;
	if(argc < 2)
		DEBUG("Need a xml file path\n") ;
	if(argv[1])
		ret = LoadXML(argv[1]) ;
	else
		DEBUG("the xml file path is invaild\n") ;
	
	if(ret == 0)
	{
		DEBUG("Load XML Success\n") ;
		cur = GetRootElementXML() ;
		if(cur != NULL)
		{	
			printf("Root Element: %s\n", cur->value.element.name);
			DEBUG("Get Root Element Node Sucess \n") ;
			children = GetChildrenNodeXML(cur) ;
			printf("Child Element: %s\n", children->value.element.name);
			if(children != NULL)
				DEBUG("Get Children Element Node Sucess\n") ;
			else
				DEBUG("Get Children Element Node Failed\n") ;
			memset(data,0x00,sizeof(data)) ;
			GetNodeLevelXML(children,str) ;
			fprintf(stderr,"cur->level = %s\n",str);
			GetNodeTypeXML(children,str) ;
			fprintf(stderr,"cur->type = %s\n",str);
			GetNodeValueXML(children,str) ;
			fprintf(stderr,"cur->value = %s\n",str);
			GetNodeAttrXML(children,str) ;
			fprintf(stderr,"cur->attr = %s\n",str);
			//SetNodeValueXML(children , "test") ;
			//SetNodeLevelXML(children , "test2") ;
			//SetNodeTypeXML(children , "test3") ;
			//SetNodeAttrXML(children , "test4") ;
  	}
	}
	else
		DEBUG("Load XML Failed\n") ;
		
	GetConfigNameList("InternetGatewayDevice.WANDevice.", namelist);
	printf("namelist=%s\n", namelist);
	
	DelInstanceXML("InternetGatewayDevice.WANDevice.1.WANConnectionDevice.1.") ;
	SaveXML() ;
	
	//GetConfigValue(VALUE_GET,str) ;
	//SetConfigValue(VALUE_SET,"Hello World !") ;
	//fprintf(stderr,"%s = %s\n",VALUE_GET,str);
	//AddInstanceXML(ADD_INC) ;

	//SaveXML() ;
	//FreeXML() ;
	return 0 ;
}
#endif

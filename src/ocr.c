#include "windows.h"
#include "capi.h"
#include <stdio.h>
int main(int argc,char**argv)
{
	TessBaseAPI* api;
	int ret;
	char*text_out= NULL;
	if(argc < 2)
	{
		printf("usage %s <filename>",argv[0]);
		return -1;
	}
	api = TessBaseAPICreate();
	ret = TessBaseAPIInit3(api,"", "eng");
	if(ret < 0)
	{
		return NULL;
	}
	text_out = TessBaseAPIProcessPages(api,argv[1],NULL,10000);
	if(text_out)
		printf("%s \n",text_out);
	return 0;
}
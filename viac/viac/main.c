/******************************************
*Author:Away
*Date:2016-11-8
*Function:����ģ�鵥Ԫ����
*******************************************/
#include"viac.h"

int main(const int argc, char** argv)
{
	Init();
	outtype = OUTPUT_EXE;
	
	subsystem = IMAGE_SUBSYSTEM_WINDOWS_CUI;
	int opind = ProcessCommand(argc, argv);
	if (opind == 0)
	{
		return 0;
	}
	int i;
	char* ext = NULL;
	for (i = 0; i < srcfiles.count; ++i)
	{
		
		filename = srcfiles.data[i]; 
		
		ext = GetFileText(filename);
		
		if (!strcmp(ext, "viac") || !strcmp(ext,"VIAC"))
			Compile(filename);
		else if (!strcmp(ext, "c") || !strcmp(ext, "C"))
			Compile(filename);
		else if (!strcmp(ext, "obj"))
		{
			LoadObjFile(filename);
		}
		else
			printf("����ʧ�ܣ���֧�ֵ�����");
	}
	if (outtype == OUTPUT_OBJ)
	{
		if(outfile)
			WriteObj(outfile);
	}
	else
	{
		if (outfile);
			PeOutputFile(outfile);
	}
	Cleanup();
	
	printf("����ɹ�");
	return 1;
}
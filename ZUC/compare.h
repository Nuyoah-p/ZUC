#pragma once
#include<stdio.h>
#include<stdbool.h>
/// <summary>
/// 比较两个文件内容是否相同
/// </summary>
/// <param name="file1">文件1的路径</param>
/// <param name="file2">文件2的路径</param>
/// <returns>是否相同，1相同，0不相同</returns>
int Compare(const char* file1, const char* file2)
{
	FILE* f1, * f2;
	int size1, size2;
	unsigned char buffer1[1024], buffer2[1024];
	f1 = fopen(file1, "rb+");
	f2 = fopen(file2, "rb+");
	int isTheSame = false;
	if (!f1)
		goto end;
	if (!f2)
		goto end;
	while (1)
	{
		size1 = fread(buffer1, 1, 1024, f1);
		size2 = fread(buffer2, 1, 1024, f2);
		if (size1 != size2)
		{
			goto end;
		}
		if (size1 < 1)
			break;
		for (int i = 0; i < size1; i++)
		{
			if (buffer1[i] != buffer2[i])
			{
				goto end;
			}
		}
	}
	isTheSame = true;
end:
	if (f1)
		fclose(f1);
	if (f2)
		fclose(f2);
	return isTheSame;
}

unsigned char open_file(char* filename) {

	char file[MAX_PATH], * fileselect = NULL;
	OPENFILENAME open;
	ZeroMemory(&open, sizeof(OPENFILENAME));
	open.lStructSize = sizeof(OPENFILENAME);
	open.lpstrFile = file;
	open.lpstrFile[0] = '\0';
	open.nMaxFile = MAX_PATH;
	open.lpstrFilter = "文件(*.*)\0*.*\0";
	open.nFilterIndex = 1;
	open.lpstrFileTitle = NULL;
	open.nMaxFileTitle = 0;
	open.Flags = OFN_EXPLORER | OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST | OFN_NOCHANGEDIR;
	if (GetOpenFileName(&open)) {
		fileselect = open.lpstrFile;
		strcpy_s(filename, strlen(fileselect) + 1, fileselect);
		return 1;
	}
	else {
		return 0;
	}
}

int com_file()
{
	char file1[100];
	char file2[100];
	int choice = 0;

	choice = MessageBox(NULL, _T("选择第一个文件"), _T("提示"), MB_OKCANCEL | MB_ICONQUESTION | MB_SYSTEMMODAL);
	if (choice == 1) {
		open_file(file1);
	}
	else {
		return 0;
	}

	choice = MessageBox(NULL, _T("选择第二个文件"), _T("提示"), MB_OKCANCEL | MB_ICONQUESTION | MB_SYSTEMMODAL);
	if (choice == 1) {
		open_file(file2);
	}
	else {
		return 0;
	}

	if (Compare(file1, file2)) {
		MessageBox(NULL, _T("两个文件内容相同"), _T("提示"), MB_OK | MB_ICONINFORMATION | MB_SYSTEMMODAL);
	}
	else {
		MessageBox(NULL, _T("两个文件内容不同"), _T("提示"), MB_OK | MB_ICONINFORMATION | MB_SYSTEMMODAL);
	}

	return 0;
}
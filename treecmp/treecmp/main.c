#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <malloc.h>
#include <dirent.h>
#include <direct.h>

enum bool{ true, false };
/*
void traverse(const char* dir_name, char* arr1[], const char* start_dir_name, int i)
{
	DIR* dir1 = opendir(dir_name);
	_chdir(dir_name);
	if (!dir1) return;

	char full[_MAX_PATH];
	if(!_fullpath(full, start_dir_name, _MAX_PATH)) return;

	struct dirent* s_dir;

	while (s_dir = readdir(dir1))
	{
		if (s_dir->d_name[0] == '.') continue;

		arr1[i] = s_dir->d_name;
		i++;
		printf("%d", i);
		traverse(s_dir->d_name, arr1, start_dir_name, i);
	}

	if (_chdir(full)) return;
	closedir(dir1);

}

*/


enum bool treecmp(const char* directory1, const char* directory2)
{
	DIR* dir1 = opendir(directory1);
	DIR* dir2 = opendir(directory2);
	
	char* path1 = malloc(250);
	char* path2 = malloc(250);

	//char* arr1[50];
	//char* arr2[50];


	if (!dir1 || !dir2 || !path1 || !path2) return false;

	sprintf(path1, "%s\\", directory1);
	sprintf(path2, "%s\\", directory2);

	//sprintf(path1 + strlen(path1), "name");

	struct dirent *s_dir1, *s_dir2;
	
label2:
	while (s_dir1 = readdir(dir1))
	{
		if (s_dir1->d_name[0] == '.') continue;
		goto label1;
	}

label1:
	while (s_dir2 = readdir(dir2))
	{	
		if (s_dir2->d_name[0] == '.') continue;

		if (strcmp(s_dir1->d_name, s_dir2->d_name))
		{
			sprintf(path1 + strlen(path1), "%s\\", s_dir1->d_name);
			sprintf(path2 + strlen(path2), "%s\\", s_dir2->d_name);
			printf("%s\n", path1);
			printf("%s\n", path2);
			sprintf(path1, "%s\\", directory1);
			sprintf(path2, "%s\\", directory2);
		}
		goto label2;
	}
	
	/*
	int i = 0;
	_chdir(directory1);
	while (s_dir1 = readdir(dir1))
	{
		if (s_dir1->d_name[0] == '.') continue;

		arr1[i] = s_dir1->d_name;
		i++;
		traverse(s_dir1->d_name, arr1, directory1, i);
		/*
		if (!_chdir(s_dir1->d_name))
		{
			DIR* mydir = opendir(s_dir1->d_name);
			//traverse(DIR* dir1, arr1, directory1 or directory2, i);


		}
		

	}
	_chdir("..");
	*/




	closedir(dir1);
	closedir(dir2);
	free(path1);
	free(path2);

}

int main(int argc, char* argv[])
{
	if (argc != 3) return 1;

	

	treecmp(argv[1], argv[2]);

	return 0;
}
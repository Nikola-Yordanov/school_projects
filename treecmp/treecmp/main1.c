#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <io.h>
#include <direct.h>
#define PATH_SIZE 1000

int recur(char* current_path, char arr[70][100], int* index)
{
    struct _finddata64i32_t mystruct;
    auto handle = _findfirst("*.*", &mystruct);
    if (_findnext(handle, &mystruct)) return 0;

    while (_findnext(handle, &mystruct) == 0)
    {
        if (_chdir(mystruct.name) == 0)
        {
            char next_path[PATH_SIZE];
            strcpy(next_path, current_path);
            strcat(next_path, "\\");
            strcat(next_path, mystruct.name);
            strcpy(arr[*index], next_path);
            printf("%s %d\n", next_path, *index);
            (*index)++;
            recur(next_path, arr, index);
        }
        else
        {
            char file_path[PATH_SIZE];
            strcpy(file_path, current_path);
            strcat(file_path, "\\");
            strcat(file_path, mystruct.name);
            strcpy(arr[*index], file_path);
            printf("%s %d \n", file_path, *index);
            (*index)++;
        }
    }
    if (_chdir("..")) return 0;
    _findclose(handle);
    return 1;
}

void treecmp(char* dir1, char* dir2)
{
    char arr1[70][100], arr2[70][100];
    int index1 = 0, index2 = 0;
    if (_chdir(dir1)) return;
    recur("", arr1, &index1);

    printf("\n\n");
    if (_chdir(dir2)) return;
    recur("", arr2, &index2);

    printf("\n\n");
    int j;
    for (int i = 0; i < index1; i++)
    {
        for (j = 0; j < index2; j++)
        {
            if (strcmp(arr1[i], arr2[j]) == 0)
                break;
        }
        if (j == index2)
            printf("%s\n", arr1[i]);
    }

    printf("\n\n");
    for (int i = 0; i < index2; i++)
    {
        for (j = 0; j < index1; j++)
        {
            if (strcmp(arr2[i], arr1[j]) == 0)
                break;
        }
        if (j == index1)
            printf("%s\n", arr2[i]);
    }
}
int main(int argc, char* argv[])
{
    if (argc != 3) return 1;



    treecmp(argv[1], argv[2]);

    return 0;
}

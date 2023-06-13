#define _CRT_SECURE_NO_WARNINGS
#include<string.h>
#include <stdio.h>
#include <io.h>
#include <dirent.h>
#include <direct.h>

#define PATH_SIZE 200

void get_curr_dir(const char* full_path, char* curr_dir)
{
    while (*full_path != '\\' && *full_path)
    {
        *curr_dir = *full_path;
        curr_dir++, full_path++;
    }
    *curr_dir = 0;
}

void recursive_dir_make(const char* curr_path)
{
    char curr_dir[PATH_SIZE], * new_path;
    get_curr_dir(curr_path, curr_dir);
    new_path = curr_path + strlen(curr_dir) + 1;

    if (strstr(curr_dir, "."))
    {
        FILE* new = fopen(curr_dir, "w");
        if (new)
        {
            fclose(new);
            return;
        }
        fclose(new);
    }

    if (_chdir(curr_dir))
    {
        mkdir(curr_dir);
        _chdir(curr_dir);
    }

    recursive_dir_make(new_path);
    _chdir("..");
}

void copy_dir(const char* curr_path, const char* dstdir, int size)
{
    if (!_chdir(curr_path))
    {
        struct _finddata64i32_t mystruct;
        auto handle = _findfirst("*.*", &mystruct);
        if (_findnext(handle, &mystruct))
        {
            return;
        }

        while (!_findnext(handle, &mystruct))
        {
            const char new_path[PATH_SIZE];
            sprintf(new_path, "%s%s%s", curr_path, "\\", mystruct.name);
            copy_dir(new_path, dstdir, size);
        }
        _chdir("..");
        _findclose(handle);
    }
    else
    {
        _chdir(dstdir);
        recursive_dir_make(curr_path + size);
        _chdir(curr_path);
    }
}

int main(int argc, char** argv)
{
    if (argc != 3) return 0;
    copy_dir(argv[1], argv[2], strlen(argv[1]) + 1);
    return 0;
}

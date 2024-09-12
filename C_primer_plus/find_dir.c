#define _CRT_SECURE_NO_WARNINGS

#include <Windows.h>
#include <string.h>
#include <stdio.h>

int TotalFiles;
int TotalDirectories;

void SearchDirectory(LPCTSTR lpPath)
{
    TCHAR FindDir[MAX_PATH] = {0};
    TCHAR SubDir[MAX_PATH] = {0};

    WIN32_FIND_DATA FindFileData;
    BOOL bRet;

    wcscpy(FindDir, lpPath);
    wcscat(FindDir, L"\\*.*");

    HANDLE hFind = FindFirstFile(FindDir, &FindFileData);
    if (INVALID_HANDLE_VALUE == hFind)
    {
        // printf("null\n");
        return;
    }
    bRet = TRUE;
    while (bRet == TRUE)
    {
        if (wcscmp(FindFileData.cFileName, L".") != 0
            && wcscmp(FindFileData.cFileName, L"..") != 0)
        {
            if (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY)
            {
                TotalDirectories++;
                wcscpy(SubDir, lpPath);
                wcscat(SubDir, L"\\");
                wcscat(SubDir, FindFileData.cFileName);

                SearchDirectory(SubDir);
            } else
            {
                TotalFiles++;
            }
        }
        bRet = FindNextFile(hFind, &FindFileData);
    }

    FindClose(hFind);
}

void run_search_dir()
{
    LARGE_INTEGER Freq, Start, End;
    TCHAR Path[MAX_PATH];
    const char path[] = "C:\\code\\constellation";

    MultiByteToWideChar(CP_ACP, 0, path, strlen(path) + 1, Path, sizeof(Path));
    printf("org path is %s \n", path);
    printf("path is %s \n", Path);

    QueryPerformanceFrequency(&Freq);
    QueryPerformanceCounter(&Start);
    SearchDirectory(Path);
    QueryPerformanceCounter(&End);
    printf("Total Files [%d] Total Directories [%d]\n", TotalFiles, TotalDirectories);
    printf("Counter [%lld] Freq [%lld], Total [%lld] ms\n",
           End.QuadPart - Start.QuadPart,
           Freq.QuadPart, (End.QuadPart - Start.QuadPart) * 1000 / Freq.QuadPart);
}

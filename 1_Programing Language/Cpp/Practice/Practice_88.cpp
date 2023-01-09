// play music
#include <windows.h>
#include <mmsystem.h>
#include <tchar.h>
#pragma comment(lib, "winmm.lib")


int main() {

    mciSendString(TEXT("play [EMA]僕らの記憶を掠わないで.mp3"), NULL, 0, NULL);

    system("pause");

    return 0;
}
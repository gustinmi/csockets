// MessageBox : Windows application project sample

#include <windows.h>

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	MessageBox(NULL, "Hello, Windows!", "Hello!", MB_OK);
	return 0;
}

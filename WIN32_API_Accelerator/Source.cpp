#include <windows.h>
#include <TCHAR.H>
#include "resource.h"
LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
	WPARAM wParam, LPARAM lParam);
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance,
	LPSTR lpszCmdLine, int nCmdShow)
{
	HWND 	 hwnd;
	MSG 	 msg;
	WNDCLASS WndClass;
	WndClass.style = CS_HREDRAW | CS_VREDRAW;
	WndClass.lpfnWndProc = WndProc;
	WndClass.cbClsExtra = 0;
	WndClass.cbWndExtra = 0;
	WndClass.hInstance = hInstance;
	WndClass.hIcon = LoadIcon(NULL, IDI_APPLICATION);
	WndClass.hCursor = LoadCursor(NULL, IDC_ARROW);
	WndClass.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	WndClass.lpszMenuName = MAKEINTRESOURCE(IDR_MENU1);
	WndClass.lpszClassName = _T("Window Class Name");
	RegisterClass(&WndClass);
	hwnd = CreateWindow(_T("Window Class Name"),
		_T("Window Title Name"),
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		CW_USEDEFAULT,
		NULL,
		NULL,
		hInstance,
		NULL
		);
	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (int)msg.wParam;
}

LRESULT CALLBACK WndProc(HWND hwnd, UINT iMsg,
	WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT ps;
	static HMENU hMenu, hSubMenu;

	switch (iMsg)
	{
	case WM_CREATE:
		hMenu = GetMenu(hwnd);
		hSubMenu = GetSubMenu(hMenu, 1);
		
		return 0;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case ID_sub3://3�� ����޴� ������ �߻��Ѵٸ�
			hMenu = GetMenu(hwnd);	//��ü�޴�
			EnableMenuItem(hMenu, ID_sub1, MF_GRAYED);	//1�� ����޴� ��Ȱ��ȭ ��Ű��
			break;
		case ID_sub2://2�� ����޴� ������ �߻��Ѵٸ�
			hMenu = GetMenu(hwnd);	//��ü�޴�
			EnableMenuItem(hMenu, ID_sub1, MF_ENABLED);	//1�� ����޴� Ȱ��ȭ ��Ű��
			break;

		}
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	}
	return DefWindowProc(hwnd, iMsg, wParam, lParam);
}

#include <iostream>
#include <vector>
#include <Windows.h>
#include "proc.h"
#include "trainer.h"
#include <conio.h>
#include <thread>

void load(char& text);
void menu(char& text, Trainer* tn);

int main()
{
	// Get the console handle
	HWND console = GetConsoleWindow();

	// MoveWindow(window_handle, x, y, width, height, redraw_window);
	MoveWindow(console, (GetSystemMetrics(SM_CXSCREEN) / 2.0 - 380),
		(GetSystemMetrics(SM_CYSCREEN) / 2.0) - 200, 500, 200, TRUE);

	//bool run = true;
	Trainer* tn = new Trainer();
	char text;
	std::thread loadThr(load, std::ref(text));
	std::thread menuThr(menu, std::ref(text), std::ref(tn));

	loadThr.join();
	menuThr.join();

	return 0;
}

void load(char& text)
{
	do
	{
		Sleep(1000);
		text = (char)_getch();
	} while (text != '0');
}

void menu(char& text, Trainer* tn)
{
	//CONSOLE_SCREEN_BUFFER_INFO csbiInfo;
	system("color 70");
	do
	{
		switch (text)
		{
		case '1':
			text = '0';
			tn->setValue(tn->currAmmoAddr);
			text = 'A';
			break;

		case '2':
			text = '0';
			tn->setValue(tn->healthAddr);
			text = 'A';
			break;

		case '3':
			text = '0';
			tn->setValue(tn->rifleAddr);
			text = 'A';
			break;

		case '4':
			text = '0';
			tn->setValue(tn->pistolAddr);
			text = 'A';
			break;

		default:
			tn->scan();
			printf(": Traine Assault Cube :  PID: %d/%X Game: %s\n\n1-Set Current ammo { 0X%X: %d }\n2-Set Health       { 0X%X: %d }\n3-Set Ammo rifle   { 0X%X: %d }\n4-Set Ammo pistol  { 0X%X: %d }\n0-Exit\n>> ",
				tn->procId, tn->procId, (tn->procId == 0 ? "Off" : "On"), tn->currAmmoAddr, tn->currAmmoValue,
				tn->healthAddr, tn->healthValue, tn->rifleAddr, tn->rifleValue, tn->pistolAddr, tn->pistolValue);
			break;
		}
		Sleep(1000);
		system("cls");
	} while (text != '0');
}
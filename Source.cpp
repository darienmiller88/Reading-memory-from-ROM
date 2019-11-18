#include <iostream>
#include <Windows.h>
#include <thread>
using namespace std;

int main() { 
	HWND window = FindWindowA(nullptr, "Snes9X v1.57 for Windows");
	int newStat = 1, readTest = 0;

	if (window) {
		cout << "window was found!\n";
		
		DWORD valueID;
		GetWindowThreadProcessId(window, &valueID);
		HANDLE myHandle = OpenProcess(PROCESS_ALL_ACCESS, FALSE, valueID);
		
		if (valueID) {

			while (true) {
				if (GetAsyncKeyState(VK_SPACE)) {
					//WriteProcessMemory(myHandle, (LPVOID)0x0C258778, &newStat, sizeof(newStat), 0);
					newStat++;
					//cout << newStat << endl;
					ReadProcessMemory(myHandle, (PBYTE*)0x007E13F2, &readTest, sizeof(readTest), 0);
					cout << "Simons hearts: " << readTest << endl;
				}
				std::this_thread::sleep_for(50ms);
			}

			
			
		}
			
		else
			cout << "process cannot be opened!\n";
	}
	else
		cout << "window was not found!\n";

}
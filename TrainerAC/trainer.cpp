#include "trainer.h"
#include "proc.h"


void Trainer::scan()
{
	// Get PID
	this->moduleBase = GetModuleBaseAddress(this->procId, L"ac_client.exe");
	this->procId = GetProcId(L"ac_client.exe");

	this->hProcess = NULL;
	this->hProcess = OpenProcess(PROCESS_ALL_ACCESS, NULL, this->procId);

	// Player Object Address = POAddr
	this->pOAddr = this->moduleBase + 0x10F4F4;

	// Current Ammo
	this->currAmmoOffs = { 0x374, 0x14, 0x0 };
	this->currAmmoAddr = FindDMAAddy(this->hProcess, this->pOAddr, this->currAmmoOffs);
	ReadProcessMemory(this->hProcess, (BYTE*)this->currAmmoAddr, &this->currAmmoValue, sizeof(this->currAmmoValue), nullptr);

	// Health
	this->healthOffs = { 0xf8 };
	this->healthAddr = FindDMAAddy(this->hProcess, this->pOAddr, this->healthOffs);
	ReadProcessMemory(this->hProcess, (BYTE*)this->healthAddr, &this->healthValue, sizeof(this->healthValue), nullptr);

	// Rifle
	this->rifleOffs = { 0x150 };
	this->rifleAddr = FindDMAAddy(this->hProcess, this->pOAddr, this->rifleOffs);
	ReadProcessMemory(this->hProcess, (BYTE*)this->rifleAddr, &this->rifleValue, sizeof(this->rifleValue), nullptr);

	// pistol
	this->pistolOffs = { 0x13c };
	this->pistolAddr = FindDMAAddy(this->hProcess, this->pOAddr, this->pistolOffs);
	ReadProcessMemory(this->hProcess, (BYTE*)this->pistolAddr, &this->pistolValue, sizeof(this->pistolValue), nullptr);


}

void Trainer::setValue(uintptr_t& addr)
{
	printf("Enter the value: ");
	int value;
	std::cin >> value;
	WriteProcessMemory(this->hProcess, (BYTE*)addr, &value, sizeof(value), nullptr);
}
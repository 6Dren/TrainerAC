#pragma once

#include <iostream>
#include <vector>
#include <Windows.h>

class Trainer
{
public:
	// Variables
	HANDLE hProcess;
	DWORD procId;

	uintptr_t moduleBase;
	uintptr_t pOAddr; // POAddr = Player Object address

	// Current Ammo
	std::vector<unsigned int> currAmmoOffs; // CurrAmmoOffs = Current Ammo Offset
	uintptr_t currAmmoAddr; // CurrAmmoAddr = Current Ammo Address 
	int currAmmoValue; // CurrAmmoValue = Current Ammo Value

	// Health
	std::vector<unsigned int> healthOffs;
	uintptr_t healthAddr;
	int healthValue;

	// Rifle
	std::vector<unsigned int> rifleOffs;
	uintptr_t rifleAddr;
	int rifleValue;

	// Pistol
	std::vector<unsigned int> pistolOffs;
	uintptr_t pistolAddr;
	int pistolValue;


	// Functions
	void scan();

	void setValue(uintptr_t& addr);

};


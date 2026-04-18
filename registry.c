// registry.c
//
// part of checkerboard
//
// this file implements load/save settings from/to registry
// it distinguishes between 32- and 64-bit versions in the registry to enable these two versions
// to live in parallel on a 64-bit system

#include <windows.h>
#include <stdio.h>
#include "standardheader.h"
#include "CBstructs.h"
#include "CBconsts.h"
#include "registry.h"
#include "utility.h"
#include "CheckerBoard.h"


void savesettings(struct CBoptions *options)
	{
	// save settings in the registry 	
	HKEY hKey;
	unsigned long result;

#ifdef _WIN64
	// open registry key 
	RegCreateKeyEx(HKEY_CURRENT_USER,"Software\\Martin Fierz\\CheckerBoard64\\1.64",0,"CB_Key",0,KEY_WRITE,NULL,&hKey,&result);
#else
// open registry key 
	RegCreateKeyEx(HKEY_CURRENT_USER,"Software\\Martin Fierz\\CheckerBoard\\1.64",0,"CB_Key",0,KEY_WRITE,NULL,&hKey,&result);
#endif

	// save options struct
	RegSetValueEx(hKey,"options structure",0,REG_BINARY,(LPBYTE)options, sizeof(struct CBoptions));
	// close registry
	RegCloseKey(hKey);
}

void loadsettings(struct CBoptions *options, char CBdirectory[256])
	{
	// load settings from the registry 
	char lstr[256];
	HKEY hKey;
	unsigned long result;
	DWORD datatype, datasize;
	int defaultvalues = 0;

	// open registry key for checkerboard,
	//	if it doesnt exist, create it 
#ifdef _WIN64
	RegCreateKeyEx(HKEY_CURRENT_USER,"Software\\Martin Fierz\\CheckerBoard64\\1.64",0,"CB_Key",0,KEY_READ,NULL,&hKey,&result);
#else
	RegCreateKeyEx(HKEY_CURRENT_USER,"Software\\Martin Fierz\\CheckerBoard\\1.64",0,"CB_Key",0,KEY_READ,NULL,&hKey,&result);
#endif
	// get CB directory. if we find it in the registry we will overwrite it later.
	GetCurrentDirectory(255,CBdirectory);

	// if no info is in the registry, we set the values to default values 
	if(result == REG_CREATED_NEW_KEY)
		defaultvalues=1;
	
	else if(result == REG_OPENED_EXISTING_KEY)
		{
		// read values from keys 
		datasize = 255;
		result = RegQueryValueEx(hKey, "InstallPath",NULL,&datatype,(LPBYTE)CBdirectory,&datasize);
		
		// get CB options struct
		datasize = sizeof(struct CBoptions);
		result = RegQueryValueEx(hKey, "options structure",NULL,&datatype,(LPBYTE)options,&datasize);
		// if window size is too small, enlarge it
		options->window_height=max(options->window_height,480);
		options->window_width=max(options->window_width,400);
		if(options->window_x < 0 || options->window_x > 500)
			options->window_x = 1;
		if(options->window_y < 0 || options->window_y > 500)
			options->window_y = 1;
				
		if(result!=ERROR_SUCCESS)
			// could not read options - use defaults again.
			defaultvalues=1;
		}

	if(defaultvalues)
		// if we could not load settings from registry, use default settings.
		{	
		options->colors[0]=PALETTERGB(255,255,255);	
		options->colors[1]=PALETTERGB(255,255,255);	
		options->colors[2]=PALETTERGB(120,208,216);	
		options->colors[3]=PALETTERGB(0,128,192);	
		options->colors[4]=PALETTERGB(255,0,0);	
		sprintf(options->EGTBdirectory,"%s\\db",CBdirectory);
		options->exact=0;	
		options->highlight=0;
		options->invert=0;
		options->level=2;
		sprintf(options->matchdirectory,"%s\\games\\matches",CBdirectory);
		options->mirror=0;
		options->numbers=1;
		options->op_barred=0;
		options->op_crossboard=1;
		options->op_mailplay=0;
#ifdef _WIN64
		sprintf(options->primaryenginestring,"cakeM64.dll");
		sprintf(options->secondaryenginestring,"simplech64.dll");
#else
		sprintf(options->primaryenginestring,"cakeM32.dll");
		sprintf(options->secondaryenginestring,"simplech.dll");
#endif
		options->priority=0;
		options->sound=0;
		sprintf(options->userdirectory,"%s\\games",CBdirectory);
		options->userbook=0;
		options->window_x=0;
		options->addoffset = 0;
		options->language = ENGLISH;
		options->piecesetindex = 0;
		RegSetValueEx(hKey,"options structure",0,REG_BINARY,(LPBYTE)options, sizeof(struct CBoptions));
		}
	SetCurrentDirectory(CBdirectory);
	
	sprintf(lstr,"language is %i",options->language);
	CBlog(lstr);

	RegCloseKey(hKey);
	}

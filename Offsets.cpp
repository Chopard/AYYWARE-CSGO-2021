/*
Syn's AyyWare Framework 2015
*/

#include "Offsets.h"
#include "UTIL Functions.h"

#define strenc( s ) ( s )

void Offsets::Initialise()
{
	// Modules
	// 
	//2020.6 client_panorama is changed to client.dll
	//Modules::Client = Utilities::Memory::WaitOnModuleHandle("client_panorama.dll");
	//currently csgo not load client_panorama.dll
	Modules::Client = Utilities::Memory::WaitOnModuleHandle("client.dll");

	Modules::Engine = Utilities::Memory::WaitOnModuleHandle("engine.dll");
	Modules::VGUI2 = Utilities::Memory::WaitOnModuleHandle("vgui2.dll");
	Modules::VGUISurface = Utilities::Memory::WaitOnModuleHandle("vguimatsurface.dll");
	Modules::Material = Utilities::Memory::WaitOnModuleHandle("materialsystem.dll");
	Modules::VPhysics = Utilities::Memory::WaitOnModuleHandle("vphysics.dll");
	Modules::Stdlib = Utilities::Memory::WaitOnModuleHandle("vstdlib.dll");

	Utilities::Log("Client.dll Base %x",Modules::Client);
	Utilities::Log("Engine.dll Base %x", Modules::Engine);
	Utilities::Log("VGUI2.dll Base %x", Modules::VGUI2);
	Utilities::Log("VGUISurface.dll Base %x", Modules::VGUISurface);
	Utilities::Log("Material.dll Base %x", Modules::Material);
	Utilities::Log("VPhysics.dll Base %x", Modules::VPhysics);
	Utilities::Log("Stdlib.dll Base %x", Modules::Stdlib);

	//------------------------------------------------------------------------
	// VTables
#pragma region VTables
	VMT::CHL_GetAllClasses = 8;

	VMT::Engine_GetScreenSize = 5;
	VMT::Engine_GetPlayerInfo = 8;
	VMT::Engine_GetLocalPlayer = 12;
	VMT::Engine_Time = 14;
	VMT::Engine_GetViewAngles = 18;
	VMT::Engine_SetViewAngles = 19;
	VMT::Engine_GetMaxClients = 20;
	VMT::Engine_IsConnected = 27;
	VMT::Engine_IsInGame = 26;
	VMT::Engine_WorldToScreenMatrix = 37;
	VMT::Engine_ClientCmd_Unrestricted = 114;

	VMT::Panel_GetName = 36;
	VMT::Panel_PaintTraverse = 41;

	VMT::Surface_DrawSetColorA = 14;
	VMT::Surface_DrawSetColorB = 15;
	VMT::Surface_DrawFilledRect = 16;
	VMT::Surface_DrawOutlinedRect = 18;
	VMT::Surface_DrawLine = 19;
	VMT::Surface_DrawSetTextFont = 23;
	VMT::Surface_DrawSetTextColorA = 24;
	VMT::Surface_DrawSetTextColorB = 25;
	VMT::Surface_DrawSetTextPos = 26;
	VMT::Surface_DrawPrintText = 28;
	VMT::Surface_DrawSetTextureRGBA = 37;
	VMT::Surface_DrawSetTexture = 38;
	VMT::Surface_CreateNewTextureID = 43;
	VMT::Surface_FontCreate = 71;
	VMT::Surface_SetFontGlyphSet = 72;
	VMT::Surface_GetTextSize = 79;
	VMT::Surface_DrawOutlinedCircle = 103;
	VMT::Surface_SurfaceGetCursorPos = 66;
	VMT::Surface_DrawTexturedPolygon = 106;

	VMT::Material_GetName = 0;
	VMT::Material_SetMaterialVarFlag = 30;
	VMT::Material_GetMaterialVarFlag = 31;
	VMT::Material_AlphaModulate = 28;
	VMT::Material_ColorModulate = 29;
	VMT::Material_IncrementReferenceCount = 14;

	VMT::MaterialSystem_FindMaterial = 84;
	VMT::MaterialSystem_CreateMaterial = 83;

	VMT::ModelRender_ForcedMaterialOverride = 1;
	VMT::ModelRender_DrawModelExecute = 21;

	VMT::ModelInfo_GetModelName = 3;
	VMT::ModelInfo_GetStudiomodel = 32;

	VMT::RenderView_SetBlend = 4;
	VMT::RenderView_SetColorModulation = 6;

#pragma endregion Contains the VTable Indexs

	/*Functions::KeyValues_KeyValues = Utilities::Memory::FindPatternV2("client_panorama.dll", "55 8B EC 51 33 C0 C7 45");

	Functions::KeyValues_LoadFromBuffer = Utilities::Memory::FindPatternV2("client_panorama.dll", "55 8B EC 83 E4 F8 83 EC 34 53 8B 5D 0C 89 4C 24 04");

	Functions::dwCalcPlayerView = Utilities::Memory::FindPattern("client_panorama.dll", (PBYTE)"\x84\xC0\x75\x08\x57\x8B\xCE\xE8\x00\x00\x00\x00\x8B\x06", "xxxxxxxx????xx");

	Functions::dwGetPlayerCompRank = GameUtils::FindPattern1(strenc("client_panorama.dll"), strenc("55 8B EC 8B 0D ? ? ? ? 68 ? ? ? ? "));

	Functions::dwIsReady = GameUtils::FindPattern1(strenc("client_panorama.dll"), strenc("55 8B EC 83 E4 F8 83 EC 08 56 8B 35 ? ? ? ? 57 8B BE"));*/


	//not work yet
	Functions::KeyValues_KeyValues = Utilities::Memory::FindPatternV2("client.dll", "55 8B EC 51 33 C0 C7 45");

	Functions::KeyValues_LoadFromBuffer = Utilities::Memory::FindPatternV2("client.dll", "55 8B EC 83 E4 F8 83 EC 34 53 8B 5D 0C 89 4C 24 04");

	Functions::dwCalcPlayerView = Utilities::Memory::FindPattern("client.dll", (PBYTE)"\x84\xC0\x75\x08\x57\x8B\xCE\xE8\x00\x00\x00\x00\x8B\x06", "xxxxxxxx????xx");

	//not work,other refer of dwGetPlayerCompRank must be annotated
	//Functions::dwGetPlayerCompRank = GameUtils::FindPattern1(strenc("client.dll"), strenc("55 8B EC 8B 0D ? ? ? ? 68 ? ? ? ? "));

	//dwIsRead   seem no use?
	//Functions::dwIsReady = GameUtils::FindPattern1(strenc("client.dll"), strenc("55 8B EC 83 E4 F8 83 EC 08 56 8B 35 ? ? ? ? 57 8B BE"));


	Utilities::Log("Functions::KeyValues_KeyValues Base %x", Functions::KeyValues_KeyValues);
	Utilities::Log("Functions::KeyValues_LoadFromBuffer %x", Functions::KeyValues_LoadFromBuffer);
	Utilities::Log("Functions::dwCalcPlayerView %x", Functions::dwCalcPlayerView);
	//Utilities::Log("Functions::dwGetPlayerCompRank %x", Functions::dwGetPlayerCompRank);
	//Utilities::Log("Functions::dwIsReady %x", Functions::dwIsReady);

	Utilities::Log("[INFO]Offsets/Indexes Up to Date");
}

namespace Offsets
{
	// Addresses of loaded game modules
	namespace Modules
	{
		DWORD Client;
		DWORD Engine;
		DWORD VGUI2;
		DWORD VGUISurface;
		DWORD Material;
		DWORD VPhysics;
		DWORD Stdlib;
	};

	// Virtual Method Table Indexes
	namespace VMT
	{
		//CHL Client
		DWORD CHL_GetAllClasses;

		//Engine Client
		DWORD Engine_GetScreenSize;
		DWORD Engine_GetPlayerInfo;
		DWORD Engine_GetLocalPlayer;
		DWORD Engine_Time;
		DWORD Engine_GetViewAngles;
		DWORD Engine_SetViewAngles;
		DWORD Engine_GetMaxClients;
		DWORD Engine_IsConnected;
		DWORD Engine_IsInGame;
		DWORD Engine_WorldToScreenMatrix;
		DWORD Engine_GetNetChannelInfo;
		DWORD Engine_ClientCmd_Unrestricted;

		// Panels
		DWORD Panel_GetName;
		DWORD Panel_PaintTraverse;

		// Surface
		DWORD Surface_DrawSetColorA;
		DWORD Surface_DrawSetColorB;
		DWORD Surface_DrawFilledRect;
		DWORD Surface_DrawOutlinedRect;
		DWORD Surface_DrawLine;
		DWORD Surface_DrawSetTextFont;
		DWORD Surface_DrawSetTextColorA;
		DWORD Surface_DrawSetTextColorB;
		DWORD Surface_DrawSetTextPos;
		DWORD Surface_DrawPrintText;
		DWORD Surface_DrawSetTextureRGBA;
		DWORD Surface_DrawSetTexture;
		DWORD Surface_CreateNewTextureID;
		DWORD Surface_FontCreate;
		DWORD Surface_SetFontGlyphSet;
		DWORD Surface_GetTextSize;
		DWORD Surface_DrawOutlinedCircle;
		DWORD Surface_SurfaceGetCursorPos;
		DWORD Surface_DrawTexturedPolygon;

		DWORD Material_GetName;
		DWORD Material_SetMaterialVarFlag;
		DWORD Material_GetMaterialVarFlag;
		DWORD Material_AlphaModulate;
		DWORD Material_ColorModulate;
		DWORD Material_IncrementReferenceCount;

		DWORD MaterialSystem_FindMaterial;
		DWORD MaterialSystem_CreateMaterial;

		DWORD ModelRender_ForcedMaterialOverride;
		DWORD ModelRender_DrawModelExecute;

		DWORD ModelInfo_GetModelName;
		DWORD ModelInfo_GetStudiomodel;

		DWORD RenderView_SetBlend;
		DWORD RenderView_SetColorModulation;

		// Weapon entities
		DWORD Weapon_GetSpread;
	};

	// Addresses of engine functions to call
	namespace Functions
	{
		DWORD KeyValues_KeyValues;
		DWORD KeyValues_LoadFromBuffer;
		/*
	To get dwCalcPlayerView:
	1. String search for smoothstairs in client.dll
		58C1286F   68 6C18CF58      PUSH client.58CF186C                     ; ASCII "smoothstairs"
		58C12874   B9 9889EB58      MOV ECX,client.58EB8998
	2. Go to client.58EB8998
	3. Find references
	4. Go to reference with two below each other, this is C_BasePlayer::SmoothViewOnStairs(Vector &)
		586F29C7   8B15 9889EB58    MOV EDX,DWORD PTR DS:[58EB8998] < here
		586F29CD   8B42 34          MOV EAX,DWORD PTR DS:[EDX+34]
		586F29D0   B9 9889EB58      MOV ECX,client.58EB8998 < and here
	5. Find references to C_BasePlayer::SmoothViewOnStairs(Vector &)
	6. only reference is CalcPlayerView
	7. Sig starts after the call of InPrediction
	*/
		DWORD dwCalcPlayerView;

		DWORD dwGetPlayerCompRank;
		//DWORD dwIsReady;
	};

};
#pragma once

#ifdef BOMAPIDLL_EXPORTS

#if defined(__APPLE__)
#define CLO_PLUGIN_SPECIFIER
#else
#define CLO_PLUGIN_SPECIFIER __declspec(dllexport)
#endif

#else

#if defined(__APPLE__)
#define CLO_PLUGIN_SPECIFIER
#else
#define CLO_PLUGIN_SPECIFIER __declspec(dllimport)
#endif

#endif
#ifdef __cplusplus
extern "C"
{
#endif
	extern CLO_PLUGIN_SPECIFIER void DoFunction();
	extern CLO_PLUGIN_SPECIFIER const char* GetActionName();

	extern CLO_PLUGIN_SPECIFIER void showQt();
	extern CLO_PLUGIN_SPECIFIER void CreatePattern_Test(int p1, int p2, int p3,int pts);
	extern CLO_PLUGIN_SPECIFIER void Delete_Clothes(int idx);


#ifdef __cplusplus
}
#endif
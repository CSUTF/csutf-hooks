#include <Windows.h>
BOOL WINAPI DllMain (HINSTANCE hinstDll, DWORD Reason, LPVOID Reserved) {
switch (Reason) {
case DLL_PROCESS_ATTACH:

break;
case DLL_PROCESS_DETACH:

break;
 } 
Return 1;
}
//Beautiful empty, right?
//We can also work beautifully in the target process we create a thread now:

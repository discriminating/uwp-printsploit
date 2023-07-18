#include <windows.h>

#define rebase(x) (x - 0x400000 + (DWORD)GetModuleHandleA(0))

int main() {
	typedef int(__cdecl* print_t)(int, const char*, ...);
	print_t r_print = (print_t)rebase(0x0F568A0); // change print addy when rbx updates

	r_print(0, "0 Hello, world! Address: 0x%p", (void*)r_print);
	r_print(1, "1 Hello, world! Address: 0x%p", (void*)r_print);
	r_print(2, "2 Hello, world! Address: 0x%p", (void*)r_print);
	r_print(3, "3 Hello, world! Address: 0x%p", (void*)r_print);
	//r_print_2(0, "lol?");

	return 0;
}

DWORD WINAPI DllMain(HINSTANCE a, DWORD reason, LPVOID rsv) {
	if (reason == DLL_PROCESS_ATTACH) CreateThread(0, 0, (LPTHREAD_START_ROUTINE)main, 0, 0, 0);
	return 0;
}
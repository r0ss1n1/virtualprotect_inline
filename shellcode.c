#include <stdio.h>
#include <Windows.h>
#include <memoryapi.h>
#include <winbase.h>
/* I												#########     #	      #####	                     */
/*   love											    #       #	#	#	                     */
/*        you											    #	   #######	#		             */
/*            Tai										    #	  #	  #   #####	         	     */
/*															 			     */
/* Thanks to my big brother who inspired an intellectual self, when all I knew was street fights, arguments, Real McCoy rum, dutch ovens and pingers */

/* Mentored by my big brother Tai 2009-2020 */
/* Charles Truscott with love to Tai Truscott <3 <3 <3 */

/* Inline VirtualProtect Windows 10 Professional, Visual Studio 2019 Enterprise cl.exe	*/

/* github.com/r0ss1n1 */

/* OSCP Certified since 2015, DoD standard .mil hacker */
/* dtic.mil has interesting notes on the mathematics of warfare */


char shellcode[] = "\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC\xCC";
char oldprotect[] = "\xCC\xCC\xCC\xCC";
void * shellcode_address = &shellcode;
void * oldprotect_address = &oldprotect;
int main(void) {
	__asm {
		push offset shellcode
		push offset shellcode_address
		push offset shellcode_address
		push offset shellcode_address
		push offset shellcode_address
		push offset shellcode_address
		push offset shellcode_address
		push offset shellcode_address
		push offset shellcode_address
		push offset shellcode_address
		push offset shellcode_address
		push offset shellcode_address
		push offset shellcode_address
		push offset shellcode_address
		push offset shellcode_address
		push offset shellcode_address
		push offset shellcode_address
		push offset shellcode_address
		push offset shellcode_address
		push offset shellcode_address
		push offset shellcode_address
		push offset shellcode_address
		push offset shellcode_address
		push offset shellcode_address
		push offset shellcode_address  
		push esp
		pop esi
		sub esi, 0x00001000
		push esi
		xor esi, esi
		int 3
		push esp
		pop esi
		sub esi, 0x00001000
		push offset shellcode_address
		pop eax
		sub eax, 90
		push VirtualProtect
		push ebp
		push 0x00000040
		push 0x00000090
		push eax
		call VirtualProtect
		int 3
		add esp, 48
		pop esp
		sub esp, 90
		jmp esp


	}
	return 0;
}
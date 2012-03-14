#include "types.h"
#include "defs.h"
#include "param.h"
#include "spinlock.h"
#include "buf.h"
#include "x86.h"

//  print the current backtrace of the thread.
void
backtrace(void)
{
    // hw1: fill in your code here.
    //cprintf("not implemented yet\n");

    extern void main(void);
    uint ebp, eip, up_ebp, retaddr;
    uint arg0, arg1, arg2, arg3, arg4;
    ebp = read_ebp();
    eip = (uint)backtrace;
    while(eip)
    {
        up_ebp = *(uint *)ebp;
        retaddr = *(uint *)(ebp + 4);
        arg0 = *(uint *)(ebp + 8);
        arg1 = *(uint *)(ebp + 12);
        arg2 = *(uint *)(ebp + 16);
        arg3 = *(uint *)(ebp + 20);
        arg4 = *(uint *)(ebp + 24);
        cprintf("ebp %x eip %x args %x %x %x %x %x\n", 
           ebp, eip, arg0, arg1, arg2, arg3, arg4);
        ebp = up_ebp;
        eip = retaddr;
    }
}


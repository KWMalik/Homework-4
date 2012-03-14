#include "types.h"
#include "defs.h"
#include "param.h"
#include "spinlock.h"
#include "buf.h"

static void 
test_recursive(int n)
{
    if (n > 0)
        test_recursive(n - 1);
    else
        backtrace();
}

//  test for hw1
void
test_backtrace()
{
   cprintf("start testing backtrace\n");

   test_recursive(0);
   test_recursive(5);
}

//  test for hw1
void
test_oct(void)
{
    cprintf("start testing octal number print\n");
    cprintf("%o %o %o %o %o\n", 0, 1, 8, 23456, 65536);
}


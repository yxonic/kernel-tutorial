// main.c -- Defines the C-code kernel entry point, calls initialisation routines.
// Made for JamesM's tutorials

#include "monitor.h"

int main(struct multiboot *mboot_ptr)
{
    // Initialise the screen (by clearing it)
    monitor_clear();
    // Output test
    char *welcome_string = "Hello, world!\n";
    // Print strings
    monitor_write(welcome_string);
    // Print pointers
    monitor_write_hex((u32int) welcome_string);
    // Print chars
    monitor_put('\n');
    monitor_put('\t');
    monitor_put('#');
    monitor_put('\n');
    // Print decimals
    monitor_write_dec(142857);
    
    return 0xDEADDCBA;
}

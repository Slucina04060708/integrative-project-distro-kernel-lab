#include "print.h"

void kernel_main() {
    print_clear();
    print_set_color(PRINT_COLOR_BLUE, PRINT_COLOR_MAGENTA);
    print_str("Kernel is running..---\n"); 
    print_str("Group project by Camila P., Pamela Y., and Santiago\n");
    print_str("The Dynamite Group\n");
    while (1) {
    }
}

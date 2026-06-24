#include "print.h"

void kernel_main() {
    print clear();
    print_set_color(PRINT_COLOR_BLUE, PRINT_COLOR_MAGENTA);
    print_str("Kernel is running...\n");
}
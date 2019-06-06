#include "../constants.h"
#include "../header_interface_functions.h"

void boot_sound() {
    Beep (DO, 450);
    Beep (MI, 550);
    Sleep (20);
    Beep (RE, 400);
}

void closing_sound() {
    Beep (MI, 450);
    Beep (RE, 550);
    Sleep (20);
    Beep (DO, 400);
}

void error_sound() {
    Beep (RE, 300);
    Beep (DO, 300);
}

void success_sound() {
    Beep (LA, 400);
    Beep (SI, 200);
    Beep (SI, 200);
}

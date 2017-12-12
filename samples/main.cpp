#include "Nucleo.h"

Nucleo nucleo;

void
onClick(Event)
{
    nucleo.serial.printf("CLICK\r\n");
}

int
main()
{
    nucleo.init();
    nucleo.serial.printf(" *** NUCLEO BLINKY TEST ***\r\n");

    nucleo.messageBus.listen(DEVICE_ID_BUTTON_A, DEVICE_BUTTON_EVT_CLICK, onClick);

    while(1)
    {
        nucleo.io.led.setDigitalValue(1);
        nucleo.sleep(200);

        nucleo.io.led.setDigitalValue(0);
        nucleo.sleep(200);
    }
}

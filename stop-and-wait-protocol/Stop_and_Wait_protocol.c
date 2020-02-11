
typedef enum {frame arrival} event type;
#include "protocol.h"

void sender2(void)
{
    frame s;   
    packet buffer;
    event type_event;
    while (true) {
        from_network_layer(&buffer);
        s.info = buffer;
        to_physical_layer(&s);
        wait_for_event(&event);
    }
} 

void receiver2(void)
{
    frame r, s;
    event_type event;
    while (true) {
        wait_for_event(&event);
        from_physical_layer(&r);
        to_network_layer(&r.info);
        to_physical_layer(&s);
}
}

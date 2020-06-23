#define MAX SEQ 1
typedef enum {frame arrival, cksum err, timeout} event type;
#include "protocol.h"
void sender3(void)
{
	seq nr next frame to send;
	frame s;
	packet buffer;
	event type event;
	next frame to send = 0;
	from network layer(&buffer);
	while (true) {
		s.info = buffer;
		s.seq = next frame to send;
		to physical layer(&s);
		start timer(s.seq);
		wait for event(&event);
		if (event == frame arrival) {
			from physical layer(&s);
			if (s.ack == next frame to send) {
				stop timer(s.ack);
				from network layer(&buffer);
				inc(next frame to send);
			}
		}
	}
}
void receiver3(void)
{
	seq nr frame expected;
	frame r, s;
	event type event;
	frame expected = 0;
	while (true) {
		wait for event(&event);
		if (event == frame arrival) {
			from physical layer(&r);
			if (r.seq == frame expected) {
				to network layer(&r.info);
				inc(frame expected);
			}
			s.ack = 1 − frame expected;
			to physical layer(&s);
		}
	}
}

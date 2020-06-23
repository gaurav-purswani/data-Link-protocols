# Positive Acknowledgement with Retransmission
Protocols in which the sender waits for a positive acknowledgement before advancing to the next
data item are often called ARQ (Automatic Repeat reQuest) or PAR (Positive Acknowledgement with Retransmission).
This one also transmits data only in one direction.

After transmitting a frame and starting the timer, the sender waits for something exciting to happen. Only three 
possibilities exist: an acknowledgement frame arrives undamaged, a damaged acknowledgement frame staggers in, 
or the timer expires. If a valid acknowledgement comes in, the sender fetches the next packet from its network 
layer and puts it in the buffer, overwriting the previous packet. It also advances the sequence number. 
If a damaged frame arrives or the timer expires, neither the buffer nor the sequence number is changed so that a
duplicate can be sent. In all cases, the contents of the buffer (either the next packet or a duplicate) are 
then sent. When a valid frame arrives at the receiver, its sequence number is checked to see if it is a duplicate. 
If not, it is accepted, passed to the network layer, and an acknowledgement is generated. Duplicates and damaged 
frames are not passed to the network layer, but they do cause the last correctly received frame to be acknowledged 
to signal the sender to advance to the next frame or retransmit a damaged frame.

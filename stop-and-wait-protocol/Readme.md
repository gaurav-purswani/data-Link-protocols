# Simplex Stop and wait Protocol

This is Simplex Stop and wait protocol for error free channel. It provides flow control i.e sender takes a dummy frame as acknowledgement and then sends the next frame, which helps in situations where the sender is too fast and receiver is slow.

Even though the frames are being transmitted in both the directions, it's still a simplex channel.

## Working

### Sender Side
The sender data link layer fetches packet from network layer by using the from_network_layer and puts into the data part of the frame buffer and then sends using the to_physical_layer function to the receiver. The sender waits for a dummy frame as an acknowledgement and sends the next frame. The channel is assumed to be error free so there is no chance of a frame getting lost of destroying.

###Receiver Side
The receiver waits for an event to happen and in this case the only possibility is frame_arrival. The receiver will collect the frame from the channel using from_physical_layer and do transfer the packet data to the network layer using to_network_layer.After fetching packet from the frame and sending it to the network layer the receiver will send a dummy frame to the sender telling that it is ready to accept the next frame.

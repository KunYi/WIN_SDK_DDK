#	-SECTION_START-( 8.00 ) -SECTION_DESC-( "Send Multicast, Receive Directed & Broadcast & Multicast & Resend Broadcast" )
##
## TITLE: 1.3.1.16.8 Send Multicast, Receive Directed & Broadcast
## TITLE:            & Multicast & Resend Broadcast (1M/2C/1O)
##
## 1 Machine - 2 Cards - 1 Open Instance on each card.  These tests
## will have a trusted card send 10 MULTICAST packets to the card
## being tested.  The card being tested will have its packetfilter
## set to receive DIRECTED & BROADCAST & MULTICAST packets.  Each
## packet will contain a resend packet the test card will resend.
## Packets of size 80 bytes, 512 bytes, and MAX_FRAME_SIZE bytes
## will be sent.
##
## All SEND packets should be received by the test card.
##

# First dump any outstanding unexpected events to clear
# the event queue.  This "should" be empty here.

#	-SECTION_START-( 8.01 )
GetEvents                                       +
    OpenInstance=1
#	-SECTION_END-( 8.01 )

#	-SECTION_START-( 8.02 )
GetEvents                                       +
    OpenInstance=2
#	-SECTION_END-( 8.02 )

# And open and setup the cards.

#	-SECTION_START-( 8.03 )
Open                                            +
    OpenInstance=1                              +
    AdapterName=%TP_TRUSTED_CARD%
#	-SECTION_END-( 8.03 )

#	-SECTION_START-( 8.04 )
SetPacketFilter                                 +
    OpenInstance=1                              +
    PacketFilter=BROADCAST
#	-SECTION_END-( 8.04 )

#	-SECTION_START-( 8.05 )
Open                                            +
    OpenInstance=2                              +
    AdapterName=%TP_TEST_CARD%
#	-SECTION_END-( 8.05 )

#	-SECTION_START-( 8.06 )
SetPacketFilter                                 +
    OpenInstance=2                              +
    PacketFilter=DIRECTED|BROADCAST|MULTICAST
#	-SECTION_END-( 8.06 )

#	-SECTION_START-( 8.07 )
AddMulticastAddress                             +
    OpenInstance=2                               +
    MulticastAddress=%TP_MULTICAST_ADDRESS%
#	-SECTION_END-( 8.07 )

# Now set the trusted and test cards to receive packets.

#	-SECTION_START-( 8.08 )
Receive                                         +
    OpenInstance=1
#	-SECTION_END-( 8.08 )

#	-SECTION_START-( 8.09 )
Receive                                         +
    OpenInstance=2
#	-SECTION_END-( 8.09 )

########################################################

# Send 80 byte packets.

#	-SECTION_START-( 8.10 )
Send                                            +
    OpenInstance=1                              +
    DestinationAddress=%TP_MULTICAST_ADDRESS%   +
    PacketSize=80                               +
    Number=10                                   +
    ResendAddress=%TP_BROADCAST_ADDRESS%
#	-SECTION_END-( 8.10 )

#	-SECTION_START-( 8.11 )
WaitSend                                        +
    OpenInstance=1
#	-SECTION_END-( 8.11 )

########################################################

# Send 512 byte packets.

#	-SECTION_START-( 8.12 )
Send                                            +
    OpenInstance=1                              +
    DestinationAddress=%TP_MULTICAST_ADDRESS%   +
    PacketSize=512                              +
    Number=10                                   +
    ResendAddress=%TP_BROADCAST_ADDRESS%
#	-SECTION_END-( 8.12 )

#	-SECTION_START-( 8.13 )
WaitSend                                        +
    OpenInstance=1
#	-SECTION_END-( 8.13 )

########################################################

# Send "MAXIMUM FRAME SIZE" byte packets.

#	-SECTION_START-( 8.14 )
Send                                            +
    OpenInstance=1                              +
    DestinationAddress=%TP_MULTICAST_ADDRESS%   +
    PacketSize=%TP_MAX_FRAME_SIZE%              +
    Number=10                                   +
    ResendAddress=%TP_BROADCAST_ADDRESS%
#	-SECTION_END-( 8.14 )

#	-SECTION_START-( 8.15 )
WaitSend                                        +
    OpenInstance=1
#	-SECTION_END-( 8.15 )

########################################################

# Then stop the receives and dump the statistics.

#	-SECTION_START-( 8.16 )
StopReceive                                     +
    OpenInstance=1
#	-SECTION_END-( 8.16 )

#	-SECTION_START-( 8.17 )
StopReceive                                     +
    OpenInstance=2
#	-SECTION_END-( 8.17 )

########################################################

# Finally close the adapters, and again dump the Event
# Queue for any unexpected events.

#	-SECTION_START-( 8.18 )
Close                                           +
    OpenInstance=1
#	-SECTION_END-( 8.18 )

#	-SECTION_START-( 8.19 )
Close                                           +
    OpenInstance=2
#	-SECTION_END-( 8.19 )

#	-SECTION_START-( 8.20 )
GetEvents                                       +
    OpenInstance=1
#	-SECTION_END-( 8.20 )

#	-SECTION_START-( 8.21 )
GetEvents                                       +
    OpenInstance=2
#	-SECTION_END-( 8.21 )

#	-SECTION_END-( 8.00 )

#	-SECTION_START-( 1.00 ) -SECTION_DESC-( "Send Broadcast, Receive Directed & Broadcast" )
##
## TITLE: 1.3.1.7.1 Send Broadcast, Receive Directed & Broadcast (1M/2C/1O)
##
## 1 Machine - 2 Cards - 1 Open Instance on each card.  These tests
## will have a trusted card send 10 BROADCAST packets to the card
## being tested.  The card being tested will have its packetfilter
## set to receive DIRECTED and BROADCAST packets.  Packets of size
## 40 bytes, 512 bytes, and MAX_FRAME_SIZE bytes will be sent.
##
## All packets should be received by the test card.
##

# First dump any outstanding unexpected events to clear
# the event queue.  This "should" be empty here.

#	-SECTION_START-( 1.01 )
GetEvents                                       +
    OpenInstance=1
#	-SECTION_END-( 1.01 )

#	-SECTION_START-( 1.02 )
GetEvents                                       +
    OpenInstance=2
#	-SECTION_END-( 1.02 )

# And open and setup the cards.

#	-SECTION_START-( 1.03 )
Open                                            +
    OpenInstance=1                              +
    AdapterName=%TP_TRUSTED_CARD%
#	-SECTION_END-( 1.03 )

#	-SECTION_START-( 1.04 )
Open                                            +
    OpenInstance=2                              +
    AdapterName=%TP_TEST_CARD%
#	-SECTION_END-( 1.04 )

#	-SECTION_START-( 1.05 )
SetPacketFilter                                 +
    OpenInstance=2                              +
    PacketFilter=DIRECTED|BROADCAST
#	-SECTION_END-( 1.05 )

# Now set the test card to receive packets,

#	-SECTION_START-( 1.06 )
Receive                                         +
    OpenInstance=2
#	-SECTION_END-( 1.06 )

########################################################

# Send 40 byte packets.

#	-SECTION_START-( 1.07 )
Send                                            +
    OpenInstance=1                              +
    DestinationAddress=%TP_BROADCAST_ADDRESS%   +
    PacketSize=40                               +
    Number=10
#	-SECTION_END-( 1.07 )

#	-SECTION_START-( 1.08 )
WaitSend                                        +
    OpenInstance=1
#	-SECTION_END-( 1.08 )

########################################################

# Send 512 byte packets.

#	-SECTION_START-( 1.09 )
Send                                            +
    OpenInstance=1                              +
    DestinationAddress=%TP_BROADCAST_ADDRESS%   +
    PacketSize=512                              +
    Number=10
#	-SECTION_END-( 1.09 )

#	-SECTION_START-( 1.10 )
WaitSend                                        +
    OpenInstance=1
#	-SECTION_END-( 1.10 )

########################################################

# Send "MAXIMUM FRAME SIZE" byte packets.

#	-SECTION_START-( 1.11 )
Send                                            +
    OpenInstance=1                              +
    DestinationAddress=%TP_BROADCAST_ADDRESS%   +
    PacketSize=%TP_MAX_FRAME_SIZE%              +
    Number=10
#	-SECTION_END-( 1.11 )

#	-SECTION_START-( 1.12 )
WaitSend                                        +
    OpenInstance=1
#	-SECTION_END-( 1.12 )

########################################################

# Then stop the receive and dump the statistics.

#	-SECTION_START-( 1.13 )
StopReceive                                     +
    OpenInstance=2
#	-SECTION_END-( 1.13 )

########################################################

# Finally close the adapters, and again dump the Event
# Queue for any unexpected events.

#	-SECTION_START-( 1.14 )
Close                                           +
    OpenInstance=1
#	-SECTION_END-( 1.14 )

#	-SECTION_START-( 1.15 )
Close                                           +
    OpenInstance=2
#	-SECTION_END-( 1.15 )

#	-SECTION_START-( 1.16 )
GetEvents                                       +
    OpenInstance=1
#	-SECTION_END-( 1.16 )

#	-SECTION_START-( 1.17 )
GetEvents                                       +
    OpenInstance=2
#	-SECTION_END-( 1.17 )

#	-SECTION_END-( 1.00 )

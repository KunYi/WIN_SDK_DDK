#	-SECTION_START-( 4.00 ) -SECTION_DESC-( "Send Multicast, Receive Promiscuous & Resend Directed" ) -OPTIONALS-( PROMISCUOUS )
##
## TITLE: 1.3.1.12.4 Send Multicast, Receive Promiscuous & Resend
## TITLE:            Directed (1M/2C/1O)
##
## 1 Machine - 2 Cards - 1 Open Instance on each card.  These tests
## will have a trusted card send 10 MULTICAST packets to the card
## being tested.  The card being tested will have its packetfilter
## set to receive PROMISCUOUS packets.  Each packet will contain
## a resend packet the test card will resend.  Packets of size
## 80 bytes, 512 bytes, and MAX_FRAME_SIZE bytes will be sent.
##
## All packets should be received by the test card.
##

# First dump any outstanding unexpected events to clear
# the event queue.  This "should" be empty here.

#	-SECTION_START-( 4.01 )
GetEvents                                       +
    OpenInstance=1
#	-SECTION_END-( 4.01 )

#	-SECTION_START-( 4.02 )
GetEvents                                       +
    OpenInstance=2
#	-SECTION_END-( 4.02 )

# And open and setup the cards.

#	-SECTION_START-( 4.03 )
Open                                            +
    OpenInstance=1                              +
    AdapterName=%TP_TRUSTED_CARD%
#	-SECTION_END-( 4.03 )

#	-SECTION_START-( 4.04 )
SetPacketFilter                                 +
    OpenInstance=1                              +
    PacketFilter=DIRECTED
#	-SECTION_END-( 4.04 )

#	-SECTION_START-( 4.05 )
Open                                            +
    OpenInstance=2                              +
    AdapterName=%TP_TEST_CARD%
#	-SECTION_END-( 4.05 )

#	-SECTION_START-( 4.06 )
SetPacketFilter                                 +
    OpenInstance=2                              +
    PacketFilter=PROMISCUOUS
#	-SECTION_END-( 4.06 )

# Now set the trusted and test cards to receive packets.

#	-SECTION_START-( 4.07 )
Receive                                         +
    OpenInstance=1
#	-SECTION_END-( 4.07 )

#	-SECTION_START-( 4.08 )
Receive                                         +
    OpenInstance=2
#	-SECTION_END-( 4.08 )

########################################################

# Send 80 byte packets.

#	-SECTION_START-( 4.09 )
Send                                            +
    OpenInstance=1                              +
    DestinationAddress=%TP_MULTICAST_ADDRESS%   +
    PacketSize=80                               +
    Number=10                                   +
    ResendAddress=%TP_TRUSTED_CARD_ADDRESS%
#	-SECTION_END-( 4.09 )

#	-SECTION_START-( 4.10 )
WaitSend                                        +
    OpenInstance=1
#	-SECTION_END-( 4.10 )

########################################################

# Send 512 byte packets.

#	-SECTION_START-( 4.11 )
Send                                            +
    OpenInstance=1                              +
    DestinationAddress=%TP_MULTICAST_ADDRESS%   +
    PacketSize=512                              +
    Number=10                                   +
    ResendAddress=%TP_TRUSTED_CARD_ADDRESS%
#	-SECTION_END-( 4.11 )

#	-SECTION_START-( 4.12 )
WaitSend                                        +
    OpenInstance=1
#	-SECTION_END-( 4.12 )

########################################################

# Send "MAXIMUM FRAME SIZE" byte packets.

#	-SECTION_START-( 4.13 )
Send                                            +
    OpenInstance=1                              +
    DestinationAddress=%TP_MULTICAST_ADDRESS%   +
    PacketSize=%TP_MAX_FRAME_SIZE%              +
    Number=10                                   +
    ResendAddress=%TP_TRUSTED_CARD_ADDRESS%
#	-SECTION_END-( 4.13 )

#	-SECTION_START-( 4.14 )
WaitSend                                        +
    OpenInstance=1
#	-SECTION_END-( 4.14 )

########################################################

# Then stop the receives and dump the statistics.

#	-SECTION_START-( 4.15 )
StopReceive                                     +
    OpenInstance=1
#	-SECTION_END-( 4.15 )

#	-SECTION_START-( 4.16 )
StopReceive                                     +
    OpenInstance=2
#	-SECTION_END-( 4.16 )

########################################################

# Finally close the adapters, and again dump the Event
# Queue for any unexpected events.

#	-SECTION_START-( 4.17 )
Close                                           +
    OpenInstance=1
#	-SECTION_END-( 4.17 )

#	-SECTION_START-( 4.18 )
Close                                           +
    OpenInstance=2
#	-SECTION_END-( 4.18 )

#	-SECTION_START-( 4.19 )
GetEvents                                       +
    OpenInstance=1
#	-SECTION_END-( 4.19 )

#	-SECTION_START-( 4.20 )
GetEvents                                       +
    OpenInstance=2
#	-SECTION_END-( 4.20 )

#	-SECTION_END-( 4.00 )

#	-SECTION_START-( 11.00 ) -SECTION_DESC-( "Send Functional, Receive Functional & Mac Frame & Resend Broadcast" ) -OPTIONALS-( MACFRAME )
##
## TITLE: 1.3.1.17.11 Send Functional, Receive Functional & Mac Frame
## TITLE:             & Resend Broadcast (1M/2C/1O)
##
## 1 Machine - 2 Cards - 1 Open Instance on each card.  These tests
## will have a trusted card send 10 FUNCTIONAL packets to the card
## being tested.  The card being tested will have its packetfilter
## set to receive FUNCTIONAL & MACFRAME packets.  Each packet will
## contain a resend packet the test card will resend.  Packets of
## size 80 bytes, 512 bytes, and MAX_FRAME_SIZE bytes will be sent.
##
## All SEND packets should be received by the test card.
##

# First dump any outstanding unexpected events to clear
# the event queue.  This "should" be empty here.

#	-SECTION_START-( 11.01 )
GetEvents                                       +
    OpenInstance=1
#	-SECTION_END-( 11.01 )

#	-SECTION_START-( 11.02 )
GetEvents                                       +
    OpenInstance=2
#	-SECTION_END-( 11.02 )

# And open and setup the cards.

#	-SECTION_START-( 11.03 )
Open                                            +
    OpenInstance=1                              +
    AdapterName=%TP_TRUSTED_CARD%
#	-SECTION_END-( 11.03 )

#	-SECTION_START-( 11.04 )
SetPacketFilter                                 +
    OpenInstance=1                              +
    PacketFilter=BROADCAST
#	-SECTION_END-( 11.04 )

#	-SECTION_START-( 11.05 )
Open                                            +
    OpenInstance=2                              +
    AdapterName=%TP_TEST_CARD%
#	-SECTION_END-( 11.05 )

#	-SECTION_START-( 11.06 )
SetPacketFilter                                 +
    OpenInstance=2                              +
    PacketFilter=FUNCTIONAL|MACFRAME
#	-SECTION_END-( 11.06 )

#	-SECTION_START-( 11.07 )
SetFunctionalAddress                            +
    OpenInstance=2                              +
    FunctionalAddress=%TP_FUNCTIONAL_ADDRESS%
#	-SECTION_END-( 11.07 )

# Now set the trusted and test cards to receive packets.

#	-SECTION_START-( 11.08 )
Receive                                         +
    OpenInstance=1
#	-SECTION_END-( 11.08 )

#	-SECTION_START-( 11.09 )
Receive                                         +
    OpenInstance=2
#	-SECTION_END-( 11.09 )

########################################################

# Send 80 byte packets.

#	-SECTION_START-( 11.10 )
Send                                            +
    OpenInstance=1                              +
    DestinationAddress=C0-00-%TP_FUNCTIONAL_ADDRESS% +
    PacketSize=80                               +
    Number=10                                   +
    ResendAddress=%TP_BROADCAST_ADDRESS%
#	-SECTION_END-( 11.10 )

#	-SECTION_START-( 11.11 )
WaitSend                                        + OpenInstance=1
#	-SECTION_END-( 11.11 )

########################################################

# Send 512 byte packets.

#	-SECTION_START-( 11.12 )
Send                                            +
    OpenInstance=1                              +
    DestinationAddress=C0-00-%TP_FUNCTIONAL_ADDRESS% +
    PacketSize=512                              +
    Number=10                                   +
    ResendAddress=%TP_BROADCAST_ADDRESS%
#	-SECTION_END-( 11.12 )

#	-SECTION_START-( 11.13 )
WaitSend                                        + OpenInstance=1
#	-SECTION_END-( 11.13 )

########################################################

# Send "MAXIMUM FRAME SIZE" byte packets.

#	-SECTION_START-( 11.14 )
Send                                            +
    OpenInstance=1                              +
    DestinationAddress=C0-00-%TP_FUNCTIONAL_ADDRESS% +
    PacketSize=%TP_MAX_FRAME_SIZE%              +
    Number=10                                   +
    ResendAddress=%TP_BROADCAST_ADDRESS%
#	-SECTION_END-( 11.14 )

#	-SECTION_START-( 11.15 )
WaitSend                                        + OpenInstance=1
#	-SECTION_END-( 11.15 )

########################################################

# Then stop the receives and dump the statistics.

#	-SECTION_START-( 11.16 )
StopReceive                                     +
    OpenInstance=1
#	-SECTION_END-( 11.16 )

#	-SECTION_START-( 11.17 )
StopReceive                                     +
    OpenInstance=2
#	-SECTION_END-( 11.17 )

########################################################

# Finally close the adapters, and again dump the Event
# Queue for any unexpected events.

#	-SECTION_START-( 11.18 )
Close                                           +
    OpenInstance=1
#	-SECTION_END-( 11.18 )

#	-SECTION_START-( 11.19 )
Close                                           +
    OpenInstance=2
#	-SECTION_END-( 11.19 )

#	-SECTION_START-( 11.20 )
GetEvents                                       +
    OpenInstance=1
#	-SECTION_END-( 11.20 )

#	-SECTION_START-( 11.21 )
GetEvents                                       +
    OpenInstance=2
#	-SECTION_END-( 11.21 )

#	-SECTION_END-( 11.00 )

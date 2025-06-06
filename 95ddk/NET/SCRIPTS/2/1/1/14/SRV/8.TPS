#	-SECTION_START-( 4.00 ) -SECTION_DESC-( "Send Broadcast, Receive Broadcast & Functional & Resend Directed-server-side" )
##
## TITLE: 2.1.1.14.8 Send Broadcast, Receive Broadcast & Functional & Resend
## TITLE:            Directed (2M/1C/1O) server-side
##
## 2 Machine - 1 Card - 1 Open Instance on the card.  These tests
## will have the trusted card on one machine send 10 BROADCAST packets
## to the card being tested on another machine.  The test card will
## have its packetfilter set to receive BROADCAST & FUNCTIONAL packets.
## Each packet will contain a resend packet the test card will resend.
## Packets of size 80 bytes, 512 bytes, and MAX_FRAME_SIZE bytes will
## be sent.
##
## The server side of the test is run on the machine with the trusted
## card installed.
##
## All SEND packets should be received by the test card.
##

# First dump any outstanding unexpected events to clear
# the event queue.  This "should" be empty here.

#	-SECTION_START-( 4.01 )
GetEvents                                       +
    OpenInstance=1
#	-SECTION_END-( 4.01 )

# And open and setup the cards.

#	-SECTION_START-( 4.02 )
Open                                            +
    OpenInstance=1                              +
    AdapterName=%TP_TRUSTED_CARD%
#	-SECTION_END-( 4.02 )

#	-SECTION_START-( 4.03 )
SetPacketFilter                                 +
    OpenInstance=1                              +
    PacketFilter=DIRECTED
#	-SECTION_END-( 4.03 )

# Now set the trusted and test cards to receive packets.

#	-SECTION_START-( 4.04 )
Receive                                         +
    OpenInstance=1
#	-SECTION_END-( 4.04 )

########################################################

# Now wait for the server side to start the test

#	-SECTION_START-( 4.05 )
Pause                                           +
    OpenInstance=1                              +
    RemoteAddress=%TP_BROADCAST_ADDRESS%    +
    TestSignature=2111481
#	-SECTION_END-( 4.05 )

########################################################

# Then start the test,

# Send 80 byte packets.

#	-SECTION_START-( 4.06 )
Send                                            +
    OpenInstance=1                              +
    DestinationAddress=%TP_BROADCAST_ADDRESS%   +
    PacketSize=80                               +
    Number=10                                   +
    ResendAddress=%TP_TRUSTED_CARD_ADDRESS%
#	-SECTION_END-( 4.06 )

#	-SECTION_START-( 4.07 )
WaitSend                                        +
    OpenInstance=1
#	-SECTION_END-( 4.07 )

########################################################

# Send 512 byte packets.

#	-SECTION_START-( 4.08 )
Send                                            +
    OpenInstance=1                              +
    DestinationAddress=%TP_BROADCAST_ADDRESS%   +
    PacketSize=512                              +
    Number=10                                   +
    ResendAddress=%TP_TRUSTED_CARD_ADDRESS%
#	-SECTION_END-( 4.08 )

#	-SECTION_START-( 4.09 )
WaitSend                                        +
    OpenInstance=1
#	-SECTION_END-( 4.09 )

########################################################

# Send "MAXIMUM FRAME SIZE" byte packets.

#	-SECTION_START-( 4.10 )
Send                                            +
    OpenInstance=1                              +
    DestinationAddress=%TP_BROADCAST_ADDRESS%   +
    PacketSize=%TP_MAX_FRAME_SIZE%              +
    Number=10                                   +
    ResendAddress=%TP_TRUSTED_CARD_ADDRESS%
#	-SECTION_END-( 4.10 )

#	-SECTION_START-( 4.11 )
WaitSend                                        +
    OpenInstance=1
#	-SECTION_END-( 4.11 )

########################################################

# Now tell the server side to clean up.

#	-SECTION_START-( 4.12 )
Go                                              +
    OpenInstance=1                              +
    RemoteAddress=%TP_BROADCAST_ADDRESS%    +
    TestSignature=2111482
#	-SECTION_END-( 4.12 )

########################################################

# Then stop the receive and dump the statistics.

#	-SECTION_START-( 4.13 )
StopReceive                                     +
    OpenInstance=1
#	-SECTION_END-( 4.13 )

########################################################

# Finally close the adapters, and again dump the Event
# Queue for any unexpected events.

#	-SECTION_START-( 4.14 )
Close                                           +
    OpenInstance=1
#	-SECTION_END-( 4.14 )

#	-SECTION_START-( 4.15 )
GetEvents                                       +
    OpenInstance=1
#	-SECTION_END-( 4.15 )

#	-SECTION_END-( 4.00 )

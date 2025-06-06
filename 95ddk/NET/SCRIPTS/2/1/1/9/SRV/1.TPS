#	-SECTION_START-( 1.00 ) -SECTION_DESC-( "Send Directed, Receive Directed & Resend Directed-server-side" )
##
## TITLE: 2.1.1.9.1 Send Directed, Receive Directed & Resend
## TITLE:           Directed (2M/1C/1O) server-side
##
## 2 Machine - 1 Card - 1 Open Instance on the card.  These tests
## will have the trusted card on one machine send 10 DIRECTED packets
## to the card being tested on another machine.  The test card will
## have its packetfilter set to receive DIRECTED packets.  Each packet
## will contain a resend packet the test card will resend.  Packets
## of size 80 bytes, 512 bytes, and MAX_FRAME_SIZE bytes will be
## sent.
##
## The server side of the test is run on the machine with the trusted
## card installed.
##
## All SEND packets should be received by the test card.
##

# First dump any outstanding unexpected events to clear
# the event queue.  This "should" be empty here.

#	-SECTION_START-( 1.01 )
GetEvents                                       +
    OpenInstance=1
#	-SECTION_END-( 1.01 )

# And open and setup the cards.

#	-SECTION_START-( 1.02 )
Open                                            +
    OpenInstance=1                              +
    AdapterName=%TP_TRUSTED_CARD%
#	-SECTION_END-( 1.02 )

#	-SECTION_START-( 1.03 )
SetPacketFilter                                 +
    OpenInstance=1                              +
    PacketFilter=DIRECTED
#	-SECTION_END-( 1.03 )

# Now set the trusted and test cards to receive packets.

#	-SECTION_START-( 1.04 )
Receive                                         +
    OpenInstance=1
#	-SECTION_END-( 1.04 )

########################################################

# Now wait for the server side to start the test

#	-SECTION_START-( 1.05 )
Pause                                           +
    OpenInstance=1                              +
    RemoteAddress=%TP_REM_TEST_CARD_ADDRESS%    +
    TestSignature=211911
#	-SECTION_END-( 1.05 )

########################################################

# Then start the test,

# Send 80 byte packets.

#	-SECTION_START-( 1.06 )
Send                                            +
    OpenInstance=1                              +
    DestinationAddress=%TP_REM_TEST_CARD_ADDRESS% +
    PacketSize=80                               +
    Number=10                                   +
    ResendAddress=%TP_TRUSTED_CARD_ADDRESS%
#	-SECTION_END-( 1.06 )

#	-SECTION_START-( 1.07 )
WaitSend                                        +
    OpenInstance=1
#	-SECTION_END-( 1.07 )

########################################################

# Send 512 byte packets.

#	-SECTION_START-( 1.08 )
Send                                            +
    OpenInstance=1                              +
    DestinationAddress=%TP_REM_TEST_CARD_ADDRESS% +
    PacketSize=512                              +
    Number=10                                   +
    ResendAddress=%TP_TRUSTED_CARD_ADDRESS%
#	-SECTION_END-( 1.08 )

#	-SECTION_START-( 1.09 )
WaitSend                                        +
    OpenInstance=1
#	-SECTION_END-( 1.09 )

########################################################

# Send "MAXIMUM FRAME SIZE" byte packets.

#	-SECTION_START-( 1.10 )
Send                                            +
    OpenInstance=1                              +
    DestinationAddress=%TP_REM_TEST_CARD_ADDRESS% +
    PacketSize=%TP_MAX_FRAME_SIZE%              +
    Number=10                                   +
    ResendAddress=%TP_TRUSTED_CARD_ADDRESS%
#	-SECTION_END-( 1.10 )

#	-SECTION_START-( 1.11 )
WaitSend                                        +
    OpenInstance=1
#	-SECTION_END-( 1.11 )

########################################################

# Now tell the server side to clean up.

#	-SECTION_START-( 1.12 )
Go                                              +
    OpenInstance=1                              +
    RemoteAddress=%TP_REM_TEST_CARD_ADDRESS%    +
    TestSignature=211912
#	-SECTION_END-( 1.12 )

########################################################

# Then stop the receive and dump the statistics.

#	-SECTION_START-( 1.13 )
StopReceive                                     +
    OpenInstance=1
#	-SECTION_END-( 1.13 )

########################################################

# Finally close the adapters, and again dump the Event
# Queue for any unexpected events.

#	-SECTION_START-( 1.14 )
Close                                           +
    OpenInstance=1
#	-SECTION_END-( 1.14 )

#	-SECTION_START-( 1.15 )
GetEvents                                       +
    OpenInstance=1
#	-SECTION_END-( 1.15 )

#	-SECTION_END-( 1.00 )

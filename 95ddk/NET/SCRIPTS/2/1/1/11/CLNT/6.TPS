#	-SECTION_START-( 6.00 ) -SECTION_DESC-( "Send Multicast Receive Promiscuous & Resend Multicast-client-side" )
##
## TITLE: 2.1.1.11.6 Send Multicast Receive Promiscuous & Resend
## TITLE:            Multicast (2M/1C/1O) client-side
##
## 2 Machine - 1 Card - 1 Open Instance on the card.  These tests
## will have the trusted card on one machine send 10 MULTICAST packets
## to the card being tested on another machine.  The test card will
## have its packetfilter set to receive DIRECTED packets.  Each packet
## will contain a resend packet the test card will resend.  Packets
## of size 80 bytes, 512 bytes, and MAX_FRAME_SIZE bytes will be
## sent.
##
## The client side of the test is run on the machine with the test
## card installed.
##
## All SEND packets should be received by the test card.
##

Disable PROMISCUOUS

# First dump any outstanding unexpected events to clear
# the event queue.  This "should" be empty here.

#	-SECTION_START-( 6.01 )
GetEvents                                       +
    OpenInstance=1
#	-SECTION_END-( 6.01 )

# And open and setup the card.

#	-SECTION_START-( 6.02 )
Open                                            +
    OpenInstance=1                              +
    AdapterName=%TP_TEST_CARD%
#	-SECTION_END-( 6.02 )

#	-SECTION_START-( 6.03 )
SetPacketFilter                                 +
    OpenInstance=1                              +
    PacketFilter=PROMISCUOUS
#	-SECTION_END-( 6.03 )

########################################################

# Now set the test card to receive packets,

#	-SECTION_START-( 6.04 )
Receive                                         +
    OpenInstance=1
#	-SECTION_END-( 6.04 )

# tell the client side to start the test

#	-SECTION_START-( 6.05 )
Go                                              +
    OpenInstance=1                              +
    RemoteAddress=%TP_REM_TRUSTED_CARD_ADDRESS% +
    TestSignature=2111161
#	-SECTION_END-( 6.05 )

# and wait for the client side to finish

#	-SECTION_START-( 6.06 )
Pause                                           +
    OpenInstance=1                              +
    RemoteAddress=%TP_REM_TRUSTED_CARD_ADDRESS% +
    TestSignature=2111162
#	-SECTION_END-( 6.06 )

########################################################

# Then stop the receive and dump the statistics.

#	-SECTION_START-( 6.07 )
StopReceive                                     +
    OpenInstance=1
#	-SECTION_END-( 6.07 )

########################################################

# Finally close the adapter, and again dump the Event
# Queue for any unexpected events.

#	-SECTION_START-( 6.08 )
Close                                           +
    OpenInstance=1
#	-SECTION_END-( 6.08 )

#	-SECTION_START-( 6.09 )
GetEvents                                       +
    OpenInstance=1
#	-SECTION_END-( 6.09 )

Enable

#	-SECTION_END-( 6.00 )

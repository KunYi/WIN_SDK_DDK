#	-SECTION_START-( 8.00 ) -SECTION_DESC-( "Stress Tests" )
##
## TITLE: 2.1.2.3.8 Stress Tests (1M/2C/1O)
##
## 1 Machine - 2 Card - 1 Open Instance on the card.  These tests
## will open the test card once and the trusted card once and run
## run a Stress client/server on the test card and a Stress server
## on the trusted card.

# First dump any outstanding unexpected events to clear
# the event queue.  This "should" be empty here.

#	-SECTION_START-( 8.01 )
GetEvents                                       +
    OpenInstance=1
#	-SECTION_END-( 8.01 )

# Then open the card.

#	-SECTION_START-( 8.02 )
Open                                            +
    OpenInstance=1                              +
    AdapterName=%TP_TRUSTED_CARD%
#	-SECTION_END-( 8.02 )

########################################################

# Then start the Stress Server,

#	-SECTION_START-( 8.03 )
StressServer                                    +
     OpenInstance=1
#	-SECTION_END-( 8.03 )

# And tell the client we are ready to act as a Stress server.

#	-SECTION_START-( 8.04 )
Go                                              +
    OpenInstance=1                              +
    RemoteAddress=%TP_REM_TEST_CARD_ADDRESS%    +
    TestSignature=212381
#	-SECTION_END-( 8.04 )

########################################################

# Then wait for the stress test to end,

#	-SECTION_START-( 8.05 )
Pause                                           +
    OpenInstance=1                              +
    RemoteAddress=%TP_REM_TEST_CARD_ADDRESS%    +
    TestSignature=212382
#	-SECTION_END-( 8.05 )

# And stop the Stress Server

#	-SECTION_START-( 8.06 )
EndStress                                       +
    OpenInstance=1
#	-SECTION_END-( 8.06 )

########################################################

# Finally close the adapter, and again dump the Event
# Queue for any unexpected events.

#	-SECTION_START-( 8.07 )
GetEvents                                       +
    OpenInstance=1
#	-SECTION_END-( 8.07 )

#	-SECTION_START-( 8.08 )
Close                                           +
    OpenInstance=1
#	-SECTION_END-( 8.08 )

#	-SECTION_END-( 8.00 )

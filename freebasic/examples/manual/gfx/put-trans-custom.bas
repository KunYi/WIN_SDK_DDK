'' examples/manual/gfx/put-trans-custom.bas
''
'' Example extracted from the FreeBASIC Manual
'' from topic 'TRANS'
''
'' See Also: https://www.freebasic.net/wiki/wikka.php?wakka=KeyPgTransGfx
'' --------

Function trans32 ( ByVal source_pixel As ULong, ByVal destination_pixel As ULong, ByVal parameter As Any Ptr ) As ULong
	'' returns the source pixel
	'' unless it is &hff00ff (magenta), then return the destination pixel
	If (source_pixel And &hffffff) <> &hff00ff Then
		Return source_pixel
	Else
		Return destination_pixel
	End If
End Function

'' set up a screen: 320 * 200, 16 bits per pixel
ScreenRes 320, 200, 32

'' set up an image with the mask color as the background.
Dim img As Any Ptr = ImageCreate( 32, 32, RGB(255, 0, 255) )
Circle img, (16, 16), 15, RGB(255, 255, 0),     ,     , 1, f
Circle img, (10, 10), 3,  RGB(  0,   0, 0),     ,     , 2, f
Circle img, (23, 10), 3,  RGB(  0,   0, 0),     ,     , 2, f
Circle img, (16, 18), 10, RGB(  0,   0, 0), 3.14, 6.28

'' Put the image with PSET (gives the exact contents of the image buffer)
Draw String (110, 50 - 4), "Image put with PSET"
Put (60 - 16, 50 - 16), img, PSet

'' Put the image with TRANS
Draw String (110, 100 - 4), "Image put with TRANS"
Put (60 - 16, 100 - 16), img, Trans

'' Put the image with TRANS
Draw String (110, 150 - 4), "Image put with trans32"
Put (60 - 16, 150 - 16), img, Custom, @trans32

'' free the image memory
ImageDestroy img

'' wait for a keypress
Sleep

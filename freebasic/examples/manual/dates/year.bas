'' examples/manual/dates/year.bas
''
'' Example extracted from the FreeBASIC Manual
'' from topic 'YEAR'
''
'' See Also: https://www.freebasic.net/wiki/wikka.php?wakka=KeyPgYear
'' --------

#include "vbcompat.bi"

Dim a As Double = DateSerial (2005, 11, 28) + TimeSerial(7, 30, 50)

Print Format(a, "yyyy/mm/dd hh:mm:ss "); Year(a)

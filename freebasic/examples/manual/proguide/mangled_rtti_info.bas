'' examples/manual/proguide/mangled_rtti_info.bas
''
'' Example extracted from the FreeBASIC Manual
'' from topic 'OBJECT built-in and RTTI info'
''
'' See Also: https://www.freebasic.net/wiki/wikka.php?wakka=ProPgObjectRtti
'' --------

Namespace oop
	Type parent Extends Object
	End Type

	Type child Extends parent
	End Type

	Type grandchild Extends child
	End Type
End Namespace

Function mangledTypeNameFromRTTI (ByVal po As Object Ptr, ByVal baseIndex As Integer = 0) As String
	' Function to get any mangled-typename in the inheritance up hierarchy
	' of the type of an instance (address: 'po') compatible with the built-in 'Object'
	'
	' ('baseIndex =  0' to get the mangled-typename of the instance)
	' ('baseIndex = -1' to get the base mangled-typename of the instance, or "" if not existing)
	' ('baseIndex = -2' to get the base.base mangled-typename of the instance, or "" if not existing)
	' (.....)
	'
		Dim As String s
		Dim As ZString Ptr pz
		Dim As Any Ptr p = CPtr(Any Ptr Ptr Ptr, po)[0][-1]  ' Ptr to RTTI info
		For I As Integer = baseIndex To -1
			p = CPtr(Any Ptr Ptr, p)[2]                      ' Ptr to Base RTTI info of previous RTTI info
			If p = 0 Then Return s
		Next I
		pz = CPtr(Any Ptr Ptr, p)[1]                         ' Ptr to mangled-typename
		s = *pz
		Return s
End Function

Dim As Object Ptr p = New oop.grandchild

Print "Mangled typenames list, from RTTI info:"
Print "  " & mangledTypeNameFromRTTI(p, 0)
Print "  " & mangledTypeNameFromRTTI(p, -1)
Print "  " & mangledTypeNameFromRTTI(p, -2)
Print "  " & mangledTypeNameFromRTTI(p, -3)
Delete p

Sleep
		


This is an example how to handle exceptions with SEH. But remember.
YOU CAN'T HANDLE ALL EXCEPTIONS WITH SEH IN KERNEL MODE !

Use KmdManager to register/unregister and start/stop it.
Watch its debug output with the DbgView (www.sysinternals.com) or use SoftICE.

Tested under: Windows 2000, XP and Server 2003.

______________________
Four-F, four-f@mail.ru
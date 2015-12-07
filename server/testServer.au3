Server()

Func Server()
	TCPStartup()
	Local $ip = "127.0.0.1"
	Local $port = 65432
	Local $iListenSocket = TCPListen($ip, $port, 100)

	Local $socket = 0
	Local $str
	Do
		$socket = TCPAccept($iListenSocket)
		if (@error) Then
			msgbox(0, "error", "error")
			return False
		endif
	until $socket <> -1
	TCPCloseSocket($iListenSocket)
	Do
		$str = TCPRecv($socket, 4)
		if ($str <> "") then
			MsgBox(0, "Test", $str)
		EndIf
	until $str = "toto"
	TCPCloseSocket($socket)


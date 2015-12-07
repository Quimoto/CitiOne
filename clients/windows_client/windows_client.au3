#cs ----------------------------------------------------------------------------

 AutoIt Version: 3.3.14.2
 Author:         NoName

#ce ----------------------------------------------------------------------------

Connexion()

Func	Connexion()

	TCPStartup()

	Local	$ip = "127.0.0.1"
	Local	$port = 65432

	Local	$socket = TCPConnect($ip, $port)
	Local	$str

	if @error Then
		MsgBox(0, "error", "error")
	Else
		do
			$str = InputBox("Msg", "Write a msg")
			TCPSend($socket, $str)
		until $str = "toto"
	EndIf

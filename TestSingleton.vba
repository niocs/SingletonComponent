Sub TestSingleton

    Dim oServiceInst1
    Dim oServiceInst2
    Dim bad as Boolean
    On Error Goto ErrorHandler

    oServiceInst1 = inco.niocs.test.theBoolDataStore.get( GetDefaultContext() )
    If oServiceInst1.getBool() Then
    	bad = True
    End If
    oServiceInst1.setBool(True)
    If oServiceInst1.getBool() = False Then
    	bad = True
    End If
    
    oServiceInst2 = inco.niocs.test.theBoolDataStore.get( GetDefaultContext() )
    
    If oServiceInst2.getBool() = False Then
    	bad = True
    End If
    oServiceInst2.setBool(False)
    If oServiceInst1.getBool() = True Then
    	bad = True
    End If
    
    If bad Then
    	msgbox "Bug in singleton component !"
    Else
    	msgbox "singleton component works as expected."
    End If
    
    Exit Sub
    
    ErrorHandler:
    MsgBox "Error " & Err & ": " & Error$ & " (line : " & Erl & ")"
    'msgbox "singleton component not installed properly"

End Sub
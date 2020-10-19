Module Module1
    Sub swap(ByRef a As Integer, ByRef b As Integer)
        Dim tmp As Integer = a
        a = b : b = tmp
    End Sub

    Function maximum2(ByVal a As Integer, ByVal b As Integer) As Integer
        Dim helper As Integer
        If a < b Then
            helper = b
        Else
            helper = a
        End If
        Return helper
    End Function


    Function maximum(ByVal a As Integer, ByVal b As Integer) As Integer
        If a < b Then
            Return b
        End If
        Return a
    End Function

    Sub Main()
        Dim a As Integer = 5
        Dim b As Integer = 7
        Console.WriteLine("a = " + a.ToString + ", b = " + b.ToString + "  Bigger is: " + maximum2(a, b).ToString)
        Console.WriteLine("Swapping...")
        swap(a, b)
        Console.WriteLine("a = " + a.ToString + ", b = " + b.ToString + "  Bigger is still: " + maximum(a, b).ToString)
        Console.ReadLine()

    End Sub


End Module

Module Module1
    Sub hanoi(ByVal n As Integer, ByVal honnan As Char, ByVal hova As Char, ByVal segéd As Char)
        If n > 0 Then
            hanoi(n - 1, honnan, segéd, hova)
            Console.WriteLine(honnan.ToString() + "->" + hova.ToString())
            hanoi(n - 1, segéd, hova, honnan)
        End If
    End Sub
    Sub Main()
        Dim N As Integer = 3
        hanoi(N, "a", "b", "c")
    End Sub

End Module

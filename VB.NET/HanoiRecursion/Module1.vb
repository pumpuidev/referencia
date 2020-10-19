Module Module1
    Sub hanoi(ByVal n As Integer, ByVal source As Char, ByVal target As Char, ByVal helper As Char)
        If n > 0 Then
            hanoi(n - 1, source, helper, target)
            Console.WriteLine(source + " → " + target)
            hanoi(n - 1, helper, target, source)
        End If

    End Sub

    Sub Main()
        Console.WriteLine("Hanoi (Recursion)")
        Console.WriteLine("Enter number of rings")
        Dim n As Integer = Console.ReadLine
        hanoi(n, "a", "b", "c")
        Console.WriteLine("Hanoi completed. Press enter to exit.")
        Console.ReadLine()
    End Sub

End Module

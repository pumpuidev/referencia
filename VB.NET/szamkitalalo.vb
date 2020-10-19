Module Module1

    Sub Main()
        Dim vgen As Random = New Random()
        Dim db As Integer

        Console.WriteLine("Hogy hívnak")
        Dim név As String
        név = Console.ReadLine()
        Dim kitalálandó As Integer = vgen.Next(1, 100) '17
        Dim tipp As Integer = 0
        While tipp <> kitalálandó
            Console.WriteLine("Mi a tipped?")
            tipp = Convert.ToInt16(Console.ReadLine())
            db += 1
            If tipp < kitalálandó Then
                Console.WriteLine("Túl kicsi...")
            End If
            If tipp > kitalálandó Then
                Console.WriteLine("Túl nagy...")
            End If
        End While
        Console.WriteLine("Eltaláltad " + Convert.ToString(db) + "-ikra")
        Console.WriteLine(" Gratulálok " + név)
        Console.ReadKey()
        REM valami
        'valami
    End Sub

End Module

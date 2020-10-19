Module Module1

    Sub Main()
        Dim rng As Random = New Random()
        Dim min As Integer = 10
        Dim max As Integer = 100
        Dim n As Integer
        Console.WriteLine("I'm thinking of a number between " + min.ToString + " and " + max.ToString + "...")
        'Console.WriteLine(n)

        Dim guess As Integer
        Dim i As Integer
        For i = 1 To 3 Step 1 'Step 1 is optional
            Console.WriteLine("Game #" + i.ToString + "/3")
            guess = 0
            n = rng.Next(min, max)
            While n <> guess

                Console.Write("Guess: ")
                guess = Convert.ToInt32(Console.ReadLine())
                If guess < n Then
                    Console.WriteLine("Too small!")
                End If
                If guess > n Then
                    Console.WriteLine("Too big!")
                End If

            End While
            Console.WriteLine("Congratulations! You guessed right.")
        Next

        Console.WriteLine("Game over, press enter to exit")
        Console.ReadLine()
    End Sub

End Module

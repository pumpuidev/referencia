Module Module1

    Sub Main()
        Console.WriteLine("Hello World")

        'Console.WriteLine("What is your name?")
        'Dim name As String = "initial value is optional"
        'name = Console.ReadLine()
        'Console.WriteLine("Hi " + name)

        Dim number As Integer
        Console.WriteLine("Tell me a number")
        number = Convert.ToInt32(Console.ReadLine())
        Console.WriteLine(number)
        Console.Write(number.ToString + " + 1 = ")
        number += 1
        Console.WriteLine(number)

        Console.WriteLine("Enter to exit")
        Console.ReadLine()
    End Sub

End Module

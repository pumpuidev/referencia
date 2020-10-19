Imports System.IO

Public Class Form1
    Dim frogCount As Integer = 7
    Dim stones(frogCount) As PictureBox
    Dim frogs(frogCount) As PictureBox
    Dim path As String = Directory.GetCurrentDirectory() + "/../../pic/"
    Dim order(frogCount + 1) As Integer

    Function win() As Boolean
        Dim i As Integer = 1
        While i <= frogCount And order(i) = i
            i += 1
        End While
        Return i > frogCount
    End Function

    Private Sub mix()
        Dim i As Integer
        For i = 1 To frogCount
            order(i) = i
        Next
        Dim r As Random = New Random()
        Dim one, two, swap As Integer
        For i = 1 To 50
            one = r.Next(1, frogCount + 1)
            two = r.Next(1, frogCount + 1)
            swap = order(one)
            order(one) = order(two)
            order(two) = swap
        Next
        If win() Then
            mix()
        End If
    End Sub

    Private Sub Form1_Load(sender As System.Object, e As System.EventArgs) Handles MyBase.Load
        mix()
        Dim i As Integer
        For i = 1 To frogCount
            stones(i) = New PictureBox()
            stones(i).Image = Image.FromFile(path + "stone.png")
            stones(i).Width = 50
            stones(i).Height = 30
            stones(i).Top = 300
            stones(i).Left = i * 70 + 20
            stones(i).SizeMode = PictureBoxSizeMode.StretchImage
            stones(i).BackColor = Color.Transparent
            Me.Controls.Add(stones(i))

            frogs(i) = New PictureBox()
            frogs(i).Image = Image.FromFile(path + "frog" + order(i).ToString() + ".png")
            frogs(i).Width = 50
            frogs(i).Height = 80
            frogs(i).Top = 220
            frogs(i).Left = i * 70 + 20
            frogs(i).SizeMode = PictureBoxSizeMode.StretchImage
            frogs(i).BackColor = Color.Transparent
            frogs(i).Tag = order(i).ToString()
            AddHandler frogs(i).Click, AddressOf Frog_Click
            Me.Controls.Add(frogs(i))
        Next
    End Sub

    Private Sub Frog_Click(sender As PictureBox, e As System.EventArgs)
        'Dim cur As PictureBox = sender
        'MsgBox(cur.Tag)
        'Dim cur As Integer = Convert.ToInt32(sender.Tag)
        Dim swap As Integer
        Dim swap2 As Image
        Dim cur As Integer

        While order(cur) <> Convert.ToInt32(sender.Tag)
            cur += 1
        End While

        If cur < frogCount Then
            If frogs(cur + 1).Tag = frogCount Then
                swap = order(cur)
                order(cur) = order(cur + 1)
                order(cur + 1) = swap

                swap2 = frogs(cur).Image
                frogs(cur).Image = frogs(cur + 1).Image
                frogs(cur + 1).Image = swap2

                frogs(cur).Tag = frogCount
                frogs(cur + 1).Tag = order(cur + 1)

            End If
        End If
        If cur > 1 Then
            If frogs(cur - 1).Tag = frogCount Then
                swap = order(cur)
                order(cur) = order(cur - 1)
                order(cur - 1) = swap

                swap2 = frogs(cur).Image
                frogs(cur).Image = frogs(cur - 1).Image
                frogs(cur - 1).Image = swap2

                frogs(cur).Tag = frogCount
                frogs(cur - 1).Tag = order(cur - 1)

            End If
        End If

        If cur < frogCount - 1 Then
            If frogs(cur + 2).Tag = frogCount Then
                swap = order(cur)
                order(cur) = order(cur + 2)
                order(cur + 2) = swap

                swap2 = frogs(cur).Image
                frogs(cur).Image = frogs(cur + 2).Image
                frogs(cur + 2).Image = swap2

                frogs(cur).Tag = frogCount
                frogs(cur + 2).Tag = order(cur + 2)

            End If
        End If
        If cur > 2 Then
            If frogs(cur - 2).Tag = frogCount Then
                swap = order(cur)
                order(cur) = order(cur - 2)
                order(cur - 2) = swap

                swap2 = frogs(cur).Image
                frogs(cur).Image = frogs(cur - 2).Image
                frogs(cur - 2).Image = swap2

                frogs(cur).Tag = frogCount
                frogs(cur - 2).Tag = order(cur - 2)

            End If
        End If
        If win() Then
            MsgBox("Win!")
            Form1_Load(sender, e)
        End If
    End Sub

End Class

Imports System.IO

Public Class Form1
    Dim files() As String
    Dim pictures(6, 6) As PictureBox
    Dim pieces As Integer
    Dim result(6, 6) As Bitmap
    Dim pic As Bitmap
    Dim empty_x, empty_y As Integer


    Private Sub Form1_Load(sender As System.Object, e As System.EventArgs) Handles MyBase.Load
        files = Directory.GetFiles(Directory.GetCurrentDirectory() + "/../../pic/")
        pieces = 6
        pic = New Bitmap(files(0))
        cut()
    End Sub

    Public Sub cut()
        Dim x As Integer = pic.Width \ pieces
        Dim y As Integer = pic.Height \ pieces
        Dim a, b As Integer
        Dim color As Color

        Panel1.Controls.Clear()
        For i = 0 To pieces - 1
            For j = 0 To pieces - 1
                pictures(i, j) = New PictureBox()
                result(i, j) = New Bitmap(x, y)
                pictures(i, j).Width = x
                pictures(i, j).Height = y
                pictures(i, j).Left = i * x
                pictures(i, j).Top = j * y
                pictures(i, j).BorderStyle = BorderStyle.FixedSingle
                pictures(i, j).SizeMode = PictureBoxSizeMode.StretchImage
                pictures(i, j).Image = result(i, j)
                pictures(i, j).Tag = i.ToString + j.ToString
                AddHandler pictures(i, j).Click, AddressOf PictureBox_Click
                Panel1.Controls.Add(pictures(i, j))
            Next
        Next

        a = -1
        For i = 0 To pic.Width - 1
            If i Mod x = 0 Then
                a += 1
            End If
            b = -1
            For j = 0 To pic.Height - 1
                If j Mod y = 0 Then
                    b += 1
                End If
                color = pic.GetPixel(i, j)
                result(a, b).SetPixel(i Mod x, j Mod y, color)
            Next
        Next
        empty_x = pieces - 1
        empty_y = empty_x
        pictures(empty_x, empty_y).Image = New Bitmap(1, 1)
        mix()
    End Sub

    Private Sub swap(ByRef x As PictureBox, ByRef y As PictureBox)
        Dim a, b, tmp As Integer
        tmp = empty_x
        empty_x = empty_y
        empty_y = tmp

        a = x.Top
        b = x.Left
        x.Top = y.Top
        x.Left = y.Left
        y.Top = a
        y.Left = b
    End Sub

    Private Sub mix()
        Dim r As Random = New Random()
        'Dim one, two, three, four As Integer
        Dim neighbor_x, neighbor_y As Integer
        For i = 1 To 50
            neighbor_x = empty_x + r.Next(-1, 2)
            neighbor_y = empty_y + r.Next(-1, 2)
            'MsgBox(empty_x.ToString + " → " + neighbor_x.ToString + vbNewLine + empty_y.ToString + " → " + neighbor_y.ToString)
            If neighbor_x >= 0 And neighbor_x < pieces And _
                 neighbor_y >= 0 And neighbor_y < pieces Then
                swap(pictures(empty_x, empty_y), pictures(neighbor_x, neighbor_y))
            End If

            'one = r.Next(0, pieces)
            'two = r.Next(0, pieces)
            'three = r.Next(0, pieces)
            'four = r.Next(0, pieces)
            'swap(pictures(one, two), pictures(three, four))
        Next
        'If win() Then
        '    mix()
        'End If
    End Sub

    Private Sub win()

    End Sub

    Private Sub PictureBox_Click(sender As System.Object, e As System.EventArgs)

    End Sub

    Private Sub PictureButton_Click(sender As System.Object, e As System.EventArgs) Handles PictureButton.Click
        pic = New Bitmap(files(0))
        cut()
    End Sub


    Private Sub PiecesButton_Click(sender As System.Object, e As System.EventArgs) Handles PiecesButton.Click
        pieces = 6
        cut()
    End Sub

End Class

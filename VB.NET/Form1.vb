Imports System.IO

Public Class Form1
    Dim side_len As Integer = 32
    Dim count As Integer = 20
    Dim matrix(count, count) As PictureBox
    Dim path As String = Directory.GetCurrentDirectory() + "/../../Pictures/"
    Dim e, o, x As Image
    Dim player As Integer = 1

    Private Sub Form1_Load(sender As Object, eventArgs As System.EventArgs) Handles Me.Load
        e = Image.FromFile(path + "-.png")
        o = Image.FromFile(path + "o.png")
        x = Image.FromFile(path + "x.png")
        Panel1.Width = side_len * count + 4
        Panel1.Height = Panel1.Width
        Panel1.BorderStyle = BorderStyle.FixedSingle
        Panel1.BackColor = Color.Beige
        Dim i, j As Integer
        For i = 1 To count
            For j = 1 To count
                matrix(i, j) = New PictureBox()
                matrix(i, j).BorderStyle = BorderStyle.Fixed3D
                matrix(i, j).Width = side_len
                matrix(i, j).Height = side_len
                matrix(i, j).Top = (i - 1) * side_len + 1
                matrix(i, j).Left = (j - 1) * side_len + 1
                matrix(i, j).SizeMode = PictureBoxSizeMode.Zoom
                matrix(i, j).Image = e
                matrix(i, j).Tag = 0
                AddHandler matrix(i, j).Click, AddressOf PictureBox_Click

                Panel1.Controls.Add(matrix(i, j))
            Next
        Next
    End Sub

    Sub go(ByVal row As Integer, ByVal column As Integer,
           ByRef delta As Integer, ByRef delta2 As Integer,
           ByRef ret As Integer, ByRef ret2 As Integer)
        ret = column
        ret2 = row
        Try
            While (ret >= 1) And (ret <= count) And
                (ret2 >= 1) And (ret2 <= count) And
                matrix(row, column).Tag = matrix(ret2, ret).Tag
                ret += delta
                ret2 += delta2
            End While
        Catch
        End Try
        ret += -1 * delta
        ret2 += -1 * delta2
    End Sub


    Function win(ByRef row As Integer,
                 ByRef column As Integer) As Boolean
        Dim e, u As Integer
        Dim row_win, col_win, diag_win, diag2_win As Boolean
        go(row, column, -1, 0, e, row)
        go(row, column, 1, 0, u, row)
        row_win = u - e >= 4
        go(row, column, 0, -1, column, e)
        go(row, column, 0, 1, column, u)
        col_win = u - e >= 4
        go(row, column, 1, 1, e, u)
        go(row, column, -1, -1, e, u)
        diag_win = u - e >= 4
        go(row, column, 1, 1, row, column)
        go(row, column, -1, -1, row, column)
        diag2_win = u - e >= 4
        win = row_win Or col_win Or diag_win Or diag2_win
    End Function

    Private Sub PictureBox_Click(sender As PictureBox, e As System.EventArgs)
        If player = 1 Then
            sender.Image = o
        Else
            sender.Image = x
        End If
        sender.Tag = player
        player = 3 - player
        RemoveHandler sender.Click, AddressOf PictureBox_Click
        If win(1 + sender.Top / side_len, 1 + sender.Left / side_len) Then
            MsgBox("You win!")
        End If

    End Sub
End Class

Imports System.IO

Public Class Form1
    Dim mouse_down As Boolean = False
    Dim pictures(8, 8) As PictureBox
    Dim numbers(8) As PictureBox
    Dim box_size As Integer = 32
    Dim sudoku() As String = {"007005900",
                              "010004200",
                              "000900080",
                              "000602005",
                              "001070000",
                              "060000700",
                              "000030006",
                              "003400510",
                              "900080000"}
    Dim images(9) As Image
    Dim path As String = Directory.GetCurrentDirectory() + "/../../pic/"

    Dim status(8, 8) As Integer
    Dim which As Integer


    Private Sub Form1_Load(sender As System.Object, e As System.EventArgs) Handles MyBase.Load
        For i = 1 To 9
            images(i) = Image.FromFile(path + i.ToString + ".png")
        Next
        'Me.Controls.Clear()
        For i = 0 To 8
            numbers(i) = New PictureBox
            numbers(i).Width = box_size
            numbers(i).Height = box_size
            numbers(i).Left = i * box_size
            numbers(i).Top = 9 * box_size + 3
            numbers(i).BorderStyle = BorderStyle.FixedSingle
            numbers(i).SizeMode = PictureBoxSizeMode.StretchImage
            numbers(i).Cursor = Cursors.Hand
            numbers(i).Image = images(i + 1)
            numbers(i).BackColor = Color.Coral
            numbers(i).Tag = i.ToString
            AddHandler numbers(i).MouseDown, AddressOf numbers_MouseDown
            AddHandler numbers(i).MouseMove, AddressOf numbers_MouseMove
            Me.Controls.Add(numbers(i))

            For j = 0 To 8
                pictures(i, j) = New PictureBox()
                pictures(i, j).Width = box_size
                pictures(i, j).Height = box_size
                pictures(i, j).Left = i * box_size
                pictures(i, j).Top = j * box_size
                pictures(i, j).SizeMode = PictureBoxSizeMode.StretchImage
                'pictures(i, j).Cursor = Cursors.Hand
                status(i, j) = Convert.ToInt16(sudoku(i)(j)) - 48
                pictures(i, j).BorderStyle = BorderStyle.Fixed3D
                If sudoku(i)(j) <> "0" Then
                    pictures(i, j).Image = images(Val(sudoku(i)(j)))
                    pictures(i, j).BackColor = Color.Chartreuse
                Else
                    pictures(i, j).BackColor = Color.AliceBlue
                    pictures(i, j).AllowDrop = True
                    AddHandler pictures(i, j).DragDrop, AddressOf pic_DragDrop
                    AddHandler pictures(i, j).DragEnter, AddressOf pic_DragEnter
                End If
                pictures(i, j).Tag = i.ToString + " " + j.ToString
                Me.Controls.Add(pictures(i, j))
            Next
        Next
    End Sub

    Private Sub numbers_MouseDown(sender As System.Object, e As System.Windows.Forms.MouseEventArgs)
        mouse_down = True
    End Sub

    Private Sub numbers_MouseMove(sender As System.Object, e As System.Windows.Forms.MouseEventArgs)
        Dim s As PictureBox = sender
        If mouse_down = True Then
            s.DoDragDrop(s.Image, DragDropEffects.Copy)
            which = s.Tag
            mouse_down = False
        End If
    End Sub

    Private Sub pic_DragEnter(sender As System.Object, e As System.Windows.Forms.DragEventArgs)
        If e.Data.GetDataPresent(DataFormats.Bitmap) Then
            e.Effect = DragDropEffects.Copy
        End If
    End Sub

    Private Sub pic_DragDrop(sender As System.Object, e As System.Windows.Forms.DragEventArgs)
        Dim s As PictureBox = sender
        Dim x As Integer = Val(s.Tag(0))
        Dim y As Integer = Val(s.Tag(2))
        If check(x, y, which) Then
            s.Image = e.Data.GetData(DataFormats.Bitmap)
            status(x, y) = which
        End If
    End Sub

    Function check(x As Integer, y As Integer, w As Integer)
        Dim ret As Boolean = True
        For i = 0 To 8
            If status(i, y) = w Then
                ret = False
            End If
            If status(x, i) = w Then
                ret = False
            End If
        Next
        check = ret
    End Function

End Class

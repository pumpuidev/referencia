Imports System.IO

Public Class Terminator
    Dim board(6, 7) As PictureBox

    Dim WALL As Integer = 0
    Dim PATH As Integer = 1
    Dim CHEE As Integer = 2
    Dim MOUS As Integer = 3
    Dim GOAL As Integer = 4

    Dim table(,) As Integer = { _
        {WALL, WALL, WALL, GOAL, WALL, WALL, WALL, WALL}, _
        {WALL, WALL, WALL, PATH, WALL, WALL, WALL, WALL}, _
        {WALL, WALL, WALL, CHEE, PATH, CHEE, GOAL, WALL}, _
        {GOAL, PATH, PATH, CHEE, MOUS, WALL, WALL, WALL}, _
        {WALL, WALL, WALL, WALL, CHEE, WALL, WALL, WALL}, _
        {WALL, WALL, WALL, WALL, GOAL, WALL, WALL, WALL}, _
        {WALL, WALL, WALL, WALL, WALL, WALL, WALL, WALL}}

    Dim pic_path As String = Directory.GetCurrentDirectory() + "/../../pic/"

    Dim wallpic As Image = Image.FromFile(pic_path + "wall.jpg")
    Dim pathpic As Image = Image.FromFile(pic_path + "path.jpg")
    Dim cheesepic As Image = Image.FromFile(pic_path + "cheese.jpg")
    Dim mousepic As Image = Image.FromFile(pic_path + "mouse.jpg")
    Dim goalpic As Image = Image.FromFile(pic_path + "goal.jpg")

    Dim mouse As PictureBox
    Dim cheeses(3) As PictureBox
    Dim goals(3) As PictureBox
    Dim goal_locations(3) As Point

    Private Sub Terminator_KeyDown(sender As Object, e As KeyEventArgs) Handles Me.KeyDown
        Dim p As Point
        Select Case e.KeyCode
            Case Keys.Up, Keys.W : p = New Point(0, -1)
            Case Keys.Down, Keys.S : p = New Point(0, 1)
            Case Keys.Right, Keys.D : p = New Point(1, 0)
            Case Keys.Left, Keys.A : p = New Point(-1, 0)
        End Select
        moove(p)
    End Sub

    Private Sub Terminator_Load(sender As Object, e As EventArgs) Handles Me.Load
        mouse = New PictureBox
        For i = 0 To 3
            cheeses(i) = New PictureBox
            goals(i) = New PictureBox
            cheeses(i).Height = 30
            cheeses(i).Width = 30
            cheeses(i).SizeMode = PictureBoxSizeMode.StretchImage
        Next
        Dim cheese_count As Integer = 0
        Dim goal_count As Integer = 0
        For i = 0 To 6
            For j = 0 To 7
                board(i, j) = New PictureBox
                Select Case table(i, j)
                    Case 0 : board(i, j).Image = wallpic
                    Case 1 : board(i, j).Image = pathpic
                    Case 2 : board(i, j).Image = pathpic
                        cheeses(cheese_count).Image = cheesepic
                        cheeses(cheese_count).Left = i * 30
                        cheeses(cheese_count).Top = j * 30
                        Me.Controls.Add(cheeses(cheese_count))
                        cheese_count += 1
                    Case 3 : board(i, j).Image = pathpic
                        mouse.Left = i * 30
                        mouse.Top = j * 30
                    Case 4 : board(i, j).Image = goalpic
                        goal_locations(goal_count) = New Point(i, j)
                        goal_count += 1
                End Select
                board(i, j).Height = 30
                board(i, j).Width = 30
                board(i, j).Left = i * 30
                board(i, j).Top = j * 30
                board(i, j).SizeMode = PictureBoxSizeMode.StretchImage
                Me.Controls.Add(board(i, j))
            Next
        Next
        mouse.Image = mousepic
        mouse.Height = 30
        mouse.Width = 30
        mouse.SizeMode = PictureBoxSizeMode.StretchImage
        Me.Controls.Add(mouse)
        mouse.BringToFront()
    End Sub

    Private Sub moove(p As Point)
        Dim x As Integer = mouse.Left / 30
        Dim y As Integer = mouse.Top / 30
        x += p.X
        y += p.Y
        Try
            If (table(x, y) <> 0) Then
                mouse.Left += p.X * 30
                mouse.Top += p.Y * 30
            End If
        Catch ex As Exception

        End Try
    End Sub

End Class
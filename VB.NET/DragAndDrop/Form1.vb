Public Class Form1
    Dim mouse_down As Boolean = False

    Private Sub Form1_Load(sender As System.Object, e As System.EventArgs) Handles MyBase.Load
        PictureBox1.AllowDrop = True

    End Sub

    Private Sub PictureBox2_MouseDown(sender As System.Object, e As System.Windows.Forms.MouseEventArgs) Handles PictureBox2.MouseDown
        mouse_down = True
    End Sub

    Private Sub PictureBox2_MouseMove(sender As System.Object, e As System.Windows.Forms.MouseEventArgs) Handles PictureBox2.MouseMove
        If mouse_down = True Then
            PictureBox2.DoDragDrop(PictureBox2.Image, DragDropEffects.Copy)
            mouse_down = False
        End If
    End Sub

    Private Sub PictureBox1_DragEnter(sender As System.Object, e As System.Windows.Forms.DragEventArgs) Handles PictureBox1.DragEnter
        If e.Data.GetDataPresent(DataFormats.Bitmap) Then
            e.Effect = DragDropEffects.Copy
        End If
    End Sub

    Private Sub PictureBox1_DragDrop(sender As System.Object, e As System.Windows.Forms.DragEventArgs) Handles PictureBox1.DragDrop
        PictureBox1.Image = e.Data.GetData(DataFormats.Bitmap)
    End Sub
End Class

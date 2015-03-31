Public Class _Default
    Inherits System.Web.UI.Page

    Dim j As New Context

    Protected Sub Page_Load(ByVal sender As Object, ByVal e As System.EventArgs) Handles Me.Load
        If Not (IsPostBack Or IsCallback) Then
            RefreshGrid()
        End If
    End Sub

    Private Sub Create_Click(sender As Object, e As EventArgs) Handles Create.Click
        If Create.Text = "Update" Then
            Dim a = (From l In j.Albums Where l.Id = Create.CommandArgument).First
            With a
                .Title = Title.Text
                .PhotoUrl = EmptyAlbumUrl
            End With
            j.SubmitChanges()
            Create.Text = "Create Album"
        Else
            Dim a As New Album With {.Title = Title.Text, .PhotoUrl = EmptyAlbumUrl}
            j.Albums.InsertOnSubmit(a)
            j.SubmitChanges()
        End If
        Title.Text = ""
        RefreshGrid()
    End Sub

    Sub RefreshGrid()
        gv.DataSource = From l In j.Albums
        gv.DataBind()
    End Sub

    Protected Sub Edit_Click(sender As Object, e As EventArgs)
        Dim bt As Button = sender
        Create.CommandArgument = bt.CommandArgument
        Create.Text = "Update"
        Title.Text = bt.CommandName
    End Sub

    Protected Sub Delete_Click(sender As Object, e As EventArgs)
        Dim bt As Button = sender
        Dim a = (From l In j.Albums Where l.Id = bt.CommandArgument).First
        j.Albums.DeleteOnSubmit(a)
        j.SubmitChanges()
        RefreshGrid()
    End Sub
End Class
Public Class Photos
    Inherits System.Web.UI.Page

    Public Property Album As Album
    Dim j As New Context

    Protected Sub Page_Load(ByVal sender As Object, ByVal e As System.EventArgs) Handles Me.Load
        Dim aid = Request.QueryString("AlbumId")
        Dim k = From l In j.Albums Where l.Id = aid
        If k.Count > 0 Then
            Album = k.First
        Else
            Response.Redirect("~/")
        End If
        If Not (IsPostBack Or IsCallback) Then
            RefreshData()
        End If
    End Sub

    Sub RefreshData()
        gv.DataSource = From l In Album.Photos
        gv.DataBind()
    End Sub

    Protected Sub Edit_Click(sender As Object, e As EventArgs)
        Dim bt As Button = sender
        Upload.CommandArgument = bt.CommandArgument
        Upload.Text = "Update"
        Title.Text = bt.CommandName
        Photo.Visible = False
    End Sub

    Protected Sub Delete_Click(sender As Object, e As EventArgs)
        Dim bt As Button = sender
        Dim a = (From l In Album.Photos Where l.Id = bt.CommandArgument).First
        j.Photos.DeleteOnSubmit(a)
        j.SubmitChanges()
        RefreshData()
    End Sub

    Private Sub Upload_Click(sender As Object, e As EventArgs) Handles Upload.Click
        If Photo.Visible = False Then
            Dim a = (From l In Album.Photos Where l.Id = Upload.CommandArgument).First
            With a
                .Title = Title.Text
            End With
            j.SubmitChanges()
            Upload.Text = "Upload"
            Photo.Visible = True
        Else
            Dim filename = Guid.NewGuid.ToString
            filename = filename.Substring(0, filename.IndexOf("-") + 1) & Photo.PostedFile.FileName
            Dim path = Server.MapPath("~/Photos/" & filename)
            Photo.PostedFile.SaveAs(path)

            Dim a As New Photo With {.Title = Title.Text, .Url = EmptyAlbumUrl.Replace("empty-album.png", filename)}
            If Album.PhotoUrl = EmptyAlbumUrl Then Album.PhotoUrl = a.Url
            Album.Photos.Add(a)
            j.SubmitChanges()
        End If
        Title.Text = ""
        RefreshData()
    End Sub
End Class
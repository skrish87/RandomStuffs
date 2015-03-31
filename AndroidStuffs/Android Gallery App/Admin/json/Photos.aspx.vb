Public Class Photos1
    Inherits System.Web.UI.Page

    Protected Sub Page_Load(ByVal sender As Object, ByVal e As System.EventArgs) Handles Me.Load
        Dim aid = Request.QueryString("AlbumId")
        Dim j As New Context
        Dim Album = (From l In j.Albums Where l.Id = aid).First
        Dim json = "{""photos"":[[PHOTOS]]}"
        Dim a = ","
        For Each i In Album.Photos
            a = a & ",{""id"":""" & i.Id & """,""title"":""" & i.Title & """,""photourl"":""" & i.Url & """}"
        Next
        json = json.Replace("[PHOTOS]", a.Replace(",,", ""))
        Response.Clear()
        Response.ContentType = "application/json; charset=utf-8"
        Response.Write(json)
        Response.End()
    End Sub

End Class
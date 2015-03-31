Public Class Albums
    Inherits System.Web.UI.Page

    Protected Sub Page_Load(ByVal sender As Object, ByVal e As System.EventArgs) Handles Me.Load
        Dim j As New Context
        Dim json = "{""albums"":[[ALBUMS]]}"
        Dim a = ","
        For Each i In j.Albums
            a = a & ",{""id"":""" & i.Id & """,""title"":""" & i.Title & """,""photourl"":""" & i.PhotoUrl & """}"
        Next
        json = json.Replace("[ALBUMS]", a.Replace(",,", ""))
        Response.Clear()
        Response.ContentType = "application/json; charset=utf-8"
        Response.Write(json)
        Response.End()
    End Sub

End Class
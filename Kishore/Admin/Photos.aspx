<%@ Page Language="vb" AutoEventWireup="false" CodeBehind="Photos.aspx.vb" Inherits="Admin.Photos" %>

<!DOCTYPE html>

<html xmlns="http://www.w3.org/1999/xhtml">
<head lang="en" runat="server">
    <meta charset="utf-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1">
    <title>Bootstrap 101 Template</title>

    <!-- Bootstrap -->
    <link href="css/bootstrap.min.css" rel="stylesheet">
    <link href="css/jumbotron-narrow.css" rel="stylesheet" />
    <link href="css/custom.css" rel="stylesheet" />

    <!-- HTML5 shim and Respond.js for IE8 support of HTML5 elements and media queries -->
    <!-- WARNING: Respond.js doesn't work if you view the page via file:// -->
    <!--[if lt IE 9]>
      <script src="https://oss.maxcdn.com/html5shiv/3.7.2/html5shiv.min.js"></script>
      <script src="https://oss.maxcdn.com/respond/1.4.2/respond.min.js"></script>
    <![endif]-->
</head>
<body>
    <form id="form1" runat="server">
    <div class="container">
      <div class="header">
        <a href="/"><h3 class="text-muted">Gallery</h3></a>
      </div>

      <div id="content">
          <h3>Manage Photos of <% = Album.Title %></h3>
          <hr />
          <div class="form-inline">
              <asp:TextBox ID="Title" runat="server" CssClass="form-control" placeholder="Title" />
              <asp:FileUpload ID="Photo" runat="server" CssClass="form-control" />
              <asp:Button ID="Upload" runat="server" Text="Upload" CssClass="btn btn-primary" />
          </div>
          <br />
          <asp:GridView ID="gv" runat="server" CssClass="table table-bordered" GridLines="None" AutoGenerateColumns="false">
              <Columns>
                  <asp:BoundField DataField="Title" HeaderText="Title" />
                  <asp:ImageField DataImageUrlField="Url" DataImageUrlFormatString="{0}" HeaderText="Photo" ItemStyle-CssClass="photo" />
                  <asp:TemplateField ItemStyle-Width="130px">
                      <ItemTemplate>
                          <asp:Button ID="Edit" runat="server" Text="Edit" CommandArgument='<%# Eval("Id")%>' OnClick="Edit_Click" CommandName='<%# Eval("Title")%>' CssClass="btn btn-info btn-sm" />
                          <asp:Button ID="Delete" OnClientClick="return confirm('Do you really want to delete this?');" runat="server" Text="Delete" CommandArgument='<%# Eval("Id")%>' OnClick="Delete_Click" CssClass="btn btn-danger btn-sm" />
                      </ItemTemplate>
                  </asp:TemplateField>
              </Columns>
          </asp:GridView>
      </div>

      <footer class="footer">
        <p>&copy; Company 2014</p>
      </footer>

    </div> <!-- /container -->
    </form>
    <!-- jQuery (necessary for Bootstrap's JavaScript plugins) -->
    <script src="https://ajax.googleapis.com/ajax/libs/jquery/1.11.1/jquery.min.js"></script>
    <!-- Include all compiled plugins (below), or include individual files as needed -->
    <script src="js/bootstrap.min.js"></script>
</body>
</html>

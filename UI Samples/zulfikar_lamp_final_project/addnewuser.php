<!-- Controller for updating new users to the database --> 
<?php  
			if (isset($_POST['user']) && isset($_POST['pass']) && isset($_POST['cpass'])
					&& $_POST['user'] && $_POST['pass'] && $_POST['cpass']) {

				mysql_connect("localhost", "lamp", "1") or die(mysql_error());   
				mysql_select_db("lamp_final_project") or die(mysql_error());

				$uname = $_POST['user'];
				$pwd = $_POST['pass'];
				$cpwd = $_POST['cpass'];
				if ($uname && $pwd) {
					if (!get_magic_quotes_gpc()) {  
						$uname = addslashes($uname);
						$pwd = addslashes($pwd);
						$cpwd = addslashes($cpwd);
					}  

					$check = mysql_query("SELECT username FROM users WHERE username = '$uname'")   or die(mysql_error());  
					$check2 = mysql_num_rows($check);    //if the name exists it gives an error  
					if ($check2 != 0) {  
						echo "<script type='text/javascript'>", 
								"alert('Sorry, the username is already in use.');",
								"window.location.href = 'registernewuser.php';",
								"</script>";
					}
				}	
				
				$query = "INSERT INTO users(username, password)  VALUES('$uname', '$pwd')";  
				if(mysql_query($query)) { ?>
					<span style="text-align:center;"> You have signed up!! Please login to see new products</span><br/>
					<a href="login.php" style="text-decoration:none;text-align:center">Login</a>					
			<?php } else {				
					die('Error:'.mysql_error());
				}

				mysql_close();
			}
	?>
<!-- View for login page -->
<html>
	<head>
		<title>Login Page</title>
		<style>
			#signup {
				position: relative;
				top: -38px;
				right: -60px;
			}
		</style>
	</head>
	<body>	
	<h2>Welcome to Mini Craigslist</h2>
	

	<form method='post' onsubmit='return validateCredentials();' action='uservalidation.php' >
		<div id="existinguser">
			<div>Username : <input type="text" name='user' id="uname" /></div> <br/>
			<div>Password : <input type="password" name='pass' id="pword" /></div> <br/>
			<input type="submit" value="Login" onsubmit="validateCredentials();"/>					
			<div id="error"></div>
		</div>
	</form>	
			<input type="submit" value="Signup" id="signup" onclick="registerNewUser();"/>			
	
		<script type="text/javascript">	
			function validateCredentials() {
				if (document.getElementById('uname').value == '' || document.getElementById('pword').value == '') {
					alert("Please don't leave the fields empty");
					return false;
				} 
				return true;
			}		
			function registerNewUser() {
				window.location.href = 'registernewuser.php';
			} 
		</script>
	</body>
</html>
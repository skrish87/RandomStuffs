<!-- View for New user sign up page -->
<html>
<head>
	<h4>Please Sign up for more Products!! </h4>
</head>
<body>
	<form method='post' onsubmit='return validateEmail();' action='addnewuser.php'>
		<div id="newuser">
			<div>Username : <input type="text" name='user' id="uname" /> </div><br/>
			<div>Password : <input type="password" name='pass' id="pword" /> </div><br/>
			<div>Confirm Password : <input type="password" name='cpass' id="cpword" /> </div> </br>			
			<input type="submit" value="Signup"/>
		</div>
	</form>
	<script type="text/javascript">
		function validateEmail() {
			if (!/^\w+@[a-zA-Z_]+?\.[a-zA-Z]{2,3}$/.test(document.getElementById('uname').value)) {
				alert('Enter valid email ID');
				return false;
			} else if (document.getElementById('pword').value != document.getElementById('cpword').value) {
				alert('Your passwords did not match!!');
				return false;
			}
			return true;
		}
	</script>	
</body>
</html>

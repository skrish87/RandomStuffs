<!DOCTYPE html>
<!-- View for adding new post by users -->
<html>
<head>
<style type="text/css">
	.container {
		text-align:center;		
		clear:both;
		padding-top: 30px;
		margin-bottom:100px;
		width:500px;
	}
	a {
		text-decoration: none;
	}
	label {
		clear: left;		
		width: 180px;
		text-align: left;
		padding-bottom: 10px;
	}
	input, label {
		float:left;
		width:150px;
	}
	select, label {
		float:left;
	}
	textarea, label {
		float:left;
	}
	.submit {
		float:left;
		padding-left:30px;
		padding-right:10px;
	}
	select {
		width:200px;
	}
	#uid {
		font-style: italic;
		position:relative;
		left:-40px;
		float:right;
	}
</style>
</head>
<?php if (isset($_COOKIE['uid']) && $_COOKIE['uid']) { ?>
<body>

<a href="homepage.php">Home</a>
<a href="logout.php" style="position:relative;left:30px">Log out</a>
<span id="uid">Hi <?php echo $_COOKIE['uid'];?> </span>
<div class="container">
	<form action="addPost.php" onsubmit="return validateInputs();" enctype="multipart/form-data" method="post">
		<label>Category:</label>
		<select id='sub-category' name='subCategory'>
			<option value="0">Select</option>
  			<option value="Bike">Bike</option>
  			<option value="MotorBike">Motor Cycle</option>
  			<option value="Car">Car</option>
		</select>
		<br/>
		<label>Location:</label> 
		<select name='loc' id="location">
			<option value="0">Select</option>
  			<option value="SF">San Francisco</option>
  			<option value="SC">Santa Clara</option>
  			<option value="SE">Seattle</option>
  			<option value="SU">Sunnyvale</option>
		</select>		
		<br/>
		<label>Title:</label> <input id='titl' name="title" type="text" size="50"/><br/>
		<label>Price:</label> <input id='pr' name="price" type="text" size="5"/><br/>
		<label>Description:</label> <textarea id='descpn' name="desc" rows="5" cols="40" style="padding-bottom:10px;"> </textarea> <br/>
		<label>Email: </label> <input id='emailid' name="email" type="text" size="50"/><br/>
		<label>Confirm Email: </label> <input id='confirmemail' name="cemail" type="text" size="50"/><br/>
		<br/>
		<div class="agree"><label>I agree with terms and condtions </label>
			<input id='agreed' name='agreement' type="checkbox"/><br/>
		</div>
		<br/>
		<label>Optional fields:</label>
		<br/>
		<br/>

		<label>Image 1 (max 5 MB):</label><input type="text" readonly='readonly'/>
		<input type="file" name='file' id='file' accept="image/*"/> <br/>
		<br/>		
		</div>
		<div class="submit">
			<input id="submit-btn" type="submit" value="Submit"/>
		</div>
		<div class="Reset">
			<input type="reset" value="Reset" onclick="<?php $_SERVER['PHP_SELF']?>"/>
		</div>
	</form>
	<script type="text/javascript">
		//Validation done in the same page to avoid unnecessart transfer of data to backend controller
		function validateInputs() {
			if (document.getElementById('sub-category').value == '' || document.getElementById('location').value == ''
				|| document.getElementById('titl').value == '' || document.getElementById('pr').value == ''
				|| document.getElementById('descpn').value == '' || document.getElementById('emailid').value == '' 
				|| document.getElementById('confirmemail').value == '' ) {
				alert("Please fill in all the input fields");
				return false;
			} else if (document.getElementById('emailid').value != document.getElementById('confirmemail').value) {
				alert("Your emailid and confrim email are not matching!!");
				return false;
			} else if (document.getElementById('agreed').checked == false) {
				alert("Please agree to the terms and conditions");
				return false;
			} else if (document.getElementById('pr').value != '') {
				var priceVal = document.getElementById('pr').value;
				if (!/^([1-9][0-9]*|0)(\.[0-9]{2})?$/.test(priceVal)) {
					alert("Only digits are allowed for price");
					return false;
				}
			} else if (document.getElementById('titl').value != '') {
				var title = document.getElementById('titl').value;
				alert(title);
				if (!/^[a-zA-Z0-9 ]*$/.test(title)) {
					alert('Title can contain white spaces, digits and letters');
					return false;	
				}
				
			} 
			return true;
		}
	</script>
</body>
<?php } else {
	echo "<script type='text/javascript'>", 
				"window.location.href='login.php' ;",
			"</script>";
	}
?>
</html>


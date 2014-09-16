<!-- Controller for adding new products into the database -->
<html>
	<head>
		<style type="text/css">
			.error-div {
				color:red;
			}

			.error-container {
				text-align: center;
			}
		</style>
	</head>
</html>
<?php 

$error = "";

if($_SERVER["REQUEST_METHOD"] == "POST"){

	if (isset($_POST['title']) && isset($_POST['price']) && isset($_POST['desc']) && isset($_POST['agreement']) &&
		$_POST['title'] && $_POST['price'] && $_POST['desc'] && $_POST['agreement'] ) {

		$title = test_input($_POST['title']);
		$price = test_input($_POST['price']);
		$description = test_input($_POST['desc']);
		$agreement = test_input($_POST['agreement']);

	}
	
    if(empty($_POST["email"])) {
     	$emailError = "Email id is required";
    } else {    	
     	$email = test_input($_POST["email"]);
     	if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
       		$error .= "Invalid email id";
    	}
    }
	
	if ($error) { ?>
		<div class="error-container">
			<div class="error-div">* <?php  echo $error; ?></div>
			<a class="link-div" href="addnewpost.php">Add Post</a>
		</div>
		
	<? }

	//Setting category
	if (!isset($_POST["subCategory"])){ 
  		$subcatErr="Please select one of the subcategory";
 	} else {
 		$subCat = test_input($_POST["subCategory"]);
 		switch ($subCat) {
 			case "Bike":
 				$subCat = 1;
 				break;
 			case "MotorBike":
 				$subCat = 2;
 				break;
 			case "Car":
 				$subCat = 3;
 				break;
 			default:
 				$subCat = 0;
 				break;
 		}
	}


	if ($_FILES["file"]["error"] == 0) {
  		$image = mysql_real_escape_string($_FILES['file']['name']);
	}

	$region = 0; //Setting region depending on location
	if (!isset($_POST["loc"])){ 
  		$locError="Please select one of the locations";
 	} else {
 		$loc = test_input($_POST["loc"]);
 		switch ($loc) {
 			case "SU":
 				$loc = 1;
 				$region = 1;
 				break;
 			case "SF":
 				$loc = 2;
 				$region = 2;
 				break;
 			case "SC":
 				$loc = 3;
 				$region = 1;
 				break;
 			case "SE":
 				$loc = 4;
 				$region = 3;
 				break;
 			default:
 				$loc = 0;
 				$region = 0;
 				break;
 		}
	}

}

//function to remove the special characters and escape strings before inserting into the database
function test_input($data) {
  $data = trim($data);
  $data = stripslashes($data);
  $data = htmlspecialchars($data);
  $data = mysql_real_escape_string($data);
  return $data;
}

if (!$error) {
	mysql_connect("localhost", "lamp", "1") or die(mysql_error());   
	mysql_select_db("lamp_final_project") or die(mysql_error()); 


	$query = "INSERT INTO Posts(Posts_ID, Title, Price, Description, Email, Agreement, Image_1, SubCategory_ID, Location_ID, Region_ID) 
				VALUES ('', '$title', '$price', '$description', '$email', '$agreement', '$image', '$subCat', '$loc','$region')";  

	if(mysql_query($query)) {
		echo "<script type='text/javascript'>", 
				"window.location.href='homepage.php' ;",
			 "</script>";
	} else {
		die('Error:'.mysql_error());
	}
	mysql_close();
}
?>
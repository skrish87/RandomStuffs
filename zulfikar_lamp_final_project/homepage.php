
<!-- View & Controller for the main browse page -->
<html>
	<head>
		<title>Craigslist</title>
		<style type="text/css">
			h2 {
				text-align:center;
				position: relative;
				left:-60px;
			}
			td {
				width:100px;
				vertical-align: none;
			}
			a {
				text-decoration: none;
			}
			#container {
				padding-top: 50px;
			}
			#addpost {
				text-align: center;
				position: relative;
				left:-100px;
			}
			#logout {
				float:right;
				position: relative;
				left: -600px;
				top:-19px;
			}
			#sub-category-div {
				width:300px;
				float:left;
				position: relative;
				right:-50px;
			}
			#location-div {
				width:300px;
				float:right;
				position:relative;
				left:250px;
			}
			#region-div {
				width:300px;
				float:right;
				position:relative;
				left:-500px;
			}
			.tab {
				padding-top: 20px;				
				position: relative;
				top:50px;
				right: -40px;
				width: 900px;
			}
			.tab-header {
				width:100px;
			}
			.desc {
				width:300px;
			}
			.email {
				width:200px;
			}
			.pic {
				width:50px;
			}			
			#btn {
				position:relative;
				top:50px;
				right:-250px;
			}
			#uid {
				font-style: italic;
				position: relative;
				top:15px;

			}
		</style>
	</head>
	<?php if (isset($_COOKIE['uid']) && $_COOKIE['uid']) { ?>
	<body>
		<h2>Welcome to craigslist</h2>
		<span id="uid">Hi <?php echo $_COOKIE['uid']; ?> </span>
		<div id="addpost"><a href="addnewpost.php"> Add a New Post</a></div>	
		<div id="logout"><a href ="logout.php"> Log out</a></div> 
		<form action="<?php $_SERVER['PHP_SELF']?>" enctype="multipart/form-data" method="post">
		<div id="container">
		<div id="sub-category-div">
			<label>Browse by Category :</label>
			<select name='category' id='sub-category' >
				<option value="0">Select</option>
  				<option value="Bike">Bike</option>
  				<option value="MotorBike">Motor Cycle</option>
  				<option value="Car">Car</option>
			</select>
		</div>

		<div id="region-div">
			<label>Browse by Region:</label> 
			<select name='region' id="region-id">
				<option value="0">Select</option>
  				<option value="SB">South Bay</option>
  				<option value="NB">North Bay</option>
  				<option value="EB">East Bay</option>
			</select>		
		</div>	

		<div id="location-div">
			<label>Browse by Location:</label> 
			<select name='loc' id="location">
				<option value="0">Select</option>
  				<option value="SF">San Francisco</option>
  				<option value="SC">Santa Clara</option>
  				<option value="SE">Seattle</option>
  				<option value="SU">Sunnyvale</option>
			</select>		
		</div>

		<input id="btn" type="submit" value="Browse"></input>
		</div>
		</form>
		
		<table class="tab">
			<thead/>
			<tbody class="tab-body">
				<?php
						mysql_connect("localhost", "lamp", "1") or die(mysql_error());   
						mysql_select_db("lamp_final_project") or die(mysql_error()); 

						$location = $_POST['loc'];						
 						$category = $_POST["category"];
 						$region = $_POST['region'];

 						//Code to filter by category, location, Region
 						switch ($category) {
 							case "Bike":
 								$category = 1;
 								break;
 							case "MotorBike":
 								$category = 2;
 								break;
 							case "Car":
 								$category = 3;
 								break;
 							default:
 								$category = 0;
 								break;
 						}

 						switch ($region) {
 							case "SB":
 								$region = 1;
 								break;
 							case "NB":
 								$region = 2;
 								break;
 							case "EB":
 								$region = 3;
 								break;
 							default:
 								$region = 0;
 								break;
 						}
						
						switch ($location) {
 							case "SU":
 								$location = 1;
 								break;
 							case "SF":
 								$location = 2;
 								break;
 							case "SC":
 								$location = 3;
 								break;
 							case "SE":
 								$location = 4;
 								break;
 							default:
 								$location = 0;
 								break;
 						}

 						//query to display all the posts
 						if (!$location && !$region && !$category) { ?>
 							<tr class="tab-header">
								<td>Title</td>
								<td>Price in $</td>
								<td class='desc'>Desciption</td>
								<td class='email'>Email</td>
								<td class='pic'>Image</td>
								<td class='category'>Category</td>
								<td class='loc'>Location</td>
								<td class='region'>Region</td>
							<tr>

 						<?php
							$query = mysql_query("SELECT Title, Price, Description, Email, SubCategory_ID, Location_ID, Region_ID, 
												Image_1 FROM Posts")   or die(mysql_error()); 
							$numrows = mysql_num_rows($query);
							while ($row = mysql_fetch_array($query)) { 
								echo "<tr>";
									echo "<td>".$row['Title']."</td>";
									echo "<td>".$row['Price']."</td>";
									echo "<td class='desc'>".$row['Description']."</td>";
									echo "<td class='email'>".$row['Email']."</td>";
									echo "<td class='pic'><img src=".$row['Image_1']."></img></td>";
									echo "<td>".$row['SubCategory_ID']."</td>";
									echo "<td>".$row['Location_ID']."</td>";	
									echo "<td>".$row['Region_ID']."</td>";																
								echo "</tr>";
							}

 						}

 						//Filter category wise
 						if ($category) { ?>
 							<tr class="tab-header">
								<td>Title</td>
								<td>Price in $</td>
								<td class='desc'>Desciption</td>
								<td class='email'>Email</td>
								<td class='pic'>Image</td>								
								<td class='loc'>Location</td>
								<td class='region'>Region</td>
								<td class='category'>Category</td>
							<tr>
 						<?php
							$query = mysql_query("SELECT P.Title, P.Price, P.Description, P.Email, P.Image_1,  P.region_ID,
													P.Location_ID,  C.CategoryName FROM Posts AS P LEFT JOIN Category AS C 
													on P.SubCategory_ID = C.Category_ID 
													WHERE P.SubCategory_ID = '$category'")   or die(mysql_error()); 
							$numrows = mysql_num_rows($query);
							while ($row = mysql_fetch_array($query)) { 
								echo "<tr>";
									echo "<td>".$row['Title']."</td>";
									echo "<td>".$row['Price']."</td>";
									echo "<td class='desc'>".$row['Description']."</td>";
									echo "<td class='email'>".$row['Email']."</td>";
									echo "<td class='pic'><img src=".$row['Image_1']."></img></td>";									
									echo "<td>".$row['Region_ID']."</td>";	
									echo "<td>".$row['Location_ID']."</td>";
									echo "<td>".$row['CategoryName']."</td>";				
								echo "</tr>";
							}
						}

						//Filter Location wise
						if ($location) { ?>
							<tr class="tab-header">
								<td>Title</td>
								<td>Price in $</td>
								<td class='desc'>Desciption</td>
								<td class='email'>Email</td>
								<td class='pic'>Image</td>
								<td class='category'>Category</td>																								
								<td class='region'>Region</td>
								<td class='loc'>Location</td>
							<tr> 
							<?php

							$query = mysql_query("SELECT P.Title, P.Price, P.Description, P.Email, P.Image_1, P.SubCategory_ID, 
													P.Region_ID, L.LocationName FROM Posts AS P LEFT JOIN Location AS L 
													on P.Location_ID = L.Location_ID 
													WHERE P.Location_ID = '$location'") or die(mysql_error());
																				
							$numrows = mysql_num_rows($query);
							while ($row = mysql_fetch_array($query)) { 
								echo "<tr>";
									echo "<td>".$row['Title']."</td>";
									echo "<td>".$row['Price']."</td>";
									echo "<td class='desc'>".$row['Description']."</td>";
									echo "<td class='email'>".$row['Email']."</td>";
									echo "<td class='pic'><img src=".$row['Image_1']."></img></td>";
									echo "<td>".$row['SubCategory_ID']."</td>";
									echo "<td>".$row['Region_ID']."</td>";	
									echo "<td>".$row['LocationName']."</td>";										
								echo "</tr>";
							}

						} 
						
						//Filter region wise
						if ($region) { ?>
							<tr class="tab-header">
								<td>Title</td>
								<td>Price in $</td>
								<td class='desc'>Desciption</td>
								<td class='email'>Email</td>
								<td class='pic'>Image</td>
								<td class='category'>Category</td>
								<td class='loc'>Location</td>
								<td class='region'>Region</td>
							<tr>

						<?php 
							$query = mysql_query("SELECT P.Title, P.Price, P.Description, P.Email, P.Image_1, P.SubCategory_ID, 
													P.Location_ID, R.RegionName FROM Posts AS P LEFT JOIN Region AS R 
													on P.Region_ID = R.RegionID 
													WHERE P.Region_ID = '$region'") or die(mysql_error());
							$numrows = mysql_num_rows($query);
							while ($row = mysql_fetch_array($query)) { 
								echo "<tr>";
									echo "<td>".$row['Title']."</td>";
									echo "<td>".$row['Price']."</td>";
									echo "<td class='desc'>".$row['Description']."</td>";
									echo "<td class='email'>".$row['Email']."</td>";
									echo "<td class='pic'><img src=".$row['Image_1']."></img></td>";
									echo "<td>".$row['SubCategory_ID']."</td>";
									echo "<td>".$row['Location_ID']."</td>";	
									echo "<td>".$row['RegionName']."</td>";									
								echo "</tr>";
							}

						}
				?>
			</tbody>
		</table>
		<br/>		
	</body>	
	<?php } else {
	echo "<script type='text/javascript'>", 
				"window.location.href='login.php' ;",
			"</script>";
	}
	?>
</html>
